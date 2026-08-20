#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/process_explorer.h"
#include "../include/input.h"

void display_banner(void)
{
    printf("============================================\n");
    printf("       Linux Process Explorer v2.0\n");
    printf("============================================\n");
    printf("Dynamic input enabled.\n");
    printf("Type 'help' to see available commands.\n\n");
}

void display_help(void)
{
    printf("\nAvailable Commands:\n");
    printf("--------------------------------------------\n");
    printf("help    - Display available commands\n");
    printf("list    - List running processes (coming soon)\n");
    printf("info    - Display system/process information\n");
    printf("exit    - Exit Linux Process Explorer\n");
    printf("--------------------------------------------\n\n");
}

int main(void)
{
    char *line;

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

        if (strcmp(line, "help") == 0)
        {
            display_help();
        }
        else if (strcmp(line, "list") == 0)
        {
            printf("\nProcess listing module will be implemented in a later phase.\n\n");
        }
        else if (strcmp(line, "info") == 0)
        {
            printf("\nLinux Process Explorer\n");
            printf("Version : 2.0\n");
            printf("Module  : Dynamic Input\n");
            printf("Status  : Week 2 Implementation\n\n");
        }
        else if (strlen(line) != 0)
        {
            printf("You entered: %s\n\n", line);
        }

        free(line);
    }

    printf("Goodbye!\n");

    return 0;
}
