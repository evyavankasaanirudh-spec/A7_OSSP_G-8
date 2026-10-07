#include "../include/redirect.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void execute_redirect(char **args)
{
    pid_t pid;
    int i;

    pid = fork();

    if (pid == -1)
    {
        perror("fork");
        return;
    }

    if (pid == 0)
    {
        for (i = 0; args[i] != NULL; i++)
        {
            if (strcmp(args[i], ">") == 0)
            {
                int fd;

                fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

                if (fd == -1)
                {
                    perror("open");
                    exit(EXIT_FAILURE);
                }

                dup2(fd, STDOUT_FILENO);
                close(fd);

                args[i] = NULL;
                break;
            }
            else if (strcmp(args[i], ">>") == 0)
            {
                int fd;

                fd = open(args[i + 1], O_WRONLY | O_CREAT | O_APPEND, 0644);

                if (fd == -1)
                {
                    perror("open");
                    exit(EXIT_FAILURE);
                }

                dup2(fd, STDOUT_FILENO);
                close(fd);

                args[i] = NULL;
                break;
            }
            else if (strcmp(args[i], "<") == 0)
            {
                int fd;

                fd = open(args[i + 1], O_RDONLY);

                if (fd == -1)
                {
                    perror("open");
                    exit(EXIT_FAILURE);
                }

                dup2(fd, STDIN_FILENO);
                close(fd);

                args[i] = NULL;
                break;
            }
            else if (strcmp(args[i], "2>") == 0)
            {
                int fd;

                fd = open(args[i + 1], O_WRONLY | O_CREAT | O_TRUNC, 0644);

                if (fd == -1)
                {
                    perror("open");
                    exit(EXIT_FAILURE);
                }

                dup2(fd, STDERR_FILENO);
                close(fd);

                args[i] = NULL;
                break;
            }
        }

        execvp(args[0], args);
        perror("execvp");
        exit(EXIT_FAILURE);
    }

    waitpid(pid, NULL, 0);
}
