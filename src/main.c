#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/process_explorer.h"
#include "../include/input.h"
#include "../include/parser.h"

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
    int i;

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

        tokens = parse_line(line);

        printf("\nParsed Tokens\n");
        printf("--------------------------------------------\n");

        for (i = 0; tokens[i] != NULL; i++)
        {
            printf("argv[%d] = %s\n", i, tokens[i]);
        }

        printf("--------------------------------------------\n\n");

        free_tokens(tokens);
        free(line);
    }

    printf("Goodbye!\n");

    return 0;
}
