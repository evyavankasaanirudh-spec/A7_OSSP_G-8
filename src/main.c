#include "../include/pipes.h"
#include "../include/redirect.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/process_explorer.h"
#include "../include/input.h"
#include "../include/parser.h"
#include "../include/process.h"
#include "../include/builtin.h"

void display_banner(void)
{
    printf("============================================\n");
    printf("       Linux Process Explorer v3.0\n");
    printf("============================================\n");
    printf("Command parsing enabled.\n");
    printf("Type 'exit' to quit.\n\n");
}

int main(void)
{
    char *line;
    char **tokens;

    display_banner();

    while (1)
    {
        printf("process-explorer> ");

        line = read_line();

        if (strcmp(line, "exit") == 0)
        {
            free(line);
            break;
        }

        /* Week 7: Pipe support */
        if (strchr(line, '|') != NULL)
        {
            char *left;
            char *right;
            char **argv1;
            char **argv2;

            left = strtok(line, "|");
            right = strtok(NULL, "|");

            if (left == NULL || right == NULL)
            {
                printf("Invalid pipe command\n");
                free(line);
                continue;
            }

            argv1 = parse_line(left);
            argv2 = parse_line(right);

            if (argv1[0] != NULL && argv2[0] != NULL)
            {
                execute_pipe(argv1, argv2);
            }
            else
            {
                printf("Invalid pipe command\n");
            }

            free_tokens(argv1);
            free_tokens(argv2);
            free(line);
            continue;
        }
        /* Week 9: I/O redirection */
        if (strstr(line, ">") != NULL || strstr(line, "<") != NULL)
        {
            tokens = parse_line(line);

            if (tokens[0] != NULL)
            {
                execute_redirect(tokens);
            }

            free_tokens(tokens);
            free(line);
            continue;
        }

        /* Existing command handling */
        tokens = parse_line(line);

        if (tokens[0] != NULL)
        {
            if (execute_builtin(tokens) == 0)
            {
                execute(tokens);
            }
        }

        free_tokens(tokens);
        free(line);
    }

    return 0;
}
