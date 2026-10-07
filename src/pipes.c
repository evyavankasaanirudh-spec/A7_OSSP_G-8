#include "../include/pipes.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_pipe(char **cmd1, char **cmd2)
{
    int pipefd[2];
    pid_t pid1;
    pid_t pid2;

    if (pipe(pipefd) == -1)
    {
        perror("pipe");
        return;
    }

    pid1 = fork();

    if (pid1 == -1)
    {
        perror("fork");
        close(pipefd[0]);
        close(pipefd[1]);
        return;
    }

    if (pid1 == 0)
    {
        /* First child: command writes to pipe */
        close(pipefd[0]);

        if (dup2(pipefd[1], STDOUT_FILENO) == -1)
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        close(pipefd[1]);

        execvp(cmd1[0], cmd1);

        perror("execvp");
        exit(EXIT_FAILURE);
    }

    pid2 = fork();

    if (pid2 == -1)
    {
        perror("fork");
        close(pipefd[0]);
        close(pipefd[1]);
        waitpid(pid1, NULL, 0);
        return;
    }

    if (pid2 == 0)
    {
        /* Second child: command reads from pipe */
        close(pipefd[1]);

        if (dup2(pipefd[0], STDIN_FILENO) == -1)
        {
            perror("dup2");
            exit(EXIT_FAILURE);
        }

        close(pipefd[0]);

        execvp(cmd2[0], cmd2);

        perror("execvp");
        exit(EXIT_FAILURE);
    }

    /* Parent closes both pipe ends */
    close(pipefd[0]);
    close(pipefd[1]);

    /* Wait for both children */
    waitpid(pid1, NULL, 0);
    waitpid(pid2, NULL, 0);
}
