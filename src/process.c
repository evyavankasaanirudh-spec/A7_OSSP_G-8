#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "../include/process.h"

int execute(char **tokens)
{
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0)
    {
        /*
         * Child process:
         * Execute the command entered by the user.
         */
        execvp(tokens[0], tokens);

        /*
         * This line runs only if execvp() fails.
         */
        perror("LinuxProcessExplorer");
        _exit(EXIT_FAILURE);
    }
    else if (pid < 0)
    {
        /*
         * fork() failed.
         */
        perror("fork");
        return -1;
    }
    else
    {
        /*
         * Parent process:
         * Wait for the child process to finish.
         */
        if (waitpid(pid, &status, 0) == -1)
        {
            perror("waitpid");
            return -1;
        }
    }

    return 1;
}
