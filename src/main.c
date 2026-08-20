#include <stdio.h>
#include <string.h>
#include "process_explorer.h"

void display_banner(void)
{
    printf("============================================\n");
    printf("       Linux Process Explorer v1.0\n");
    printf("============================================\n");
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
    char input[MAX_INPUT];

    display_banner();

    while (1)
    {
        printf("process-explorer> ");

        if (fgets(input, sizeof(input), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        input[strcspn(input, "\n")] = '\0';

        if (strcmp(input, "exit") == 0)
        {
            printf("Exiting Linux Process Explorer...\n");
            break;
        }
        else if (strcmp(input, "help") == 0)
        {
            display_help();
        }
        else if (strcmp(input, "list") == 0)
        {
            printf("\nProcess listing module will be implemented in the next phase.\n\n");
        }
        else if (strcmp(input, "info") == 0)
        {
            printf("\nLinux Process Explorer\n");
            printf("Version : 1.0\n");
            printf("Module  : REPL Foundation\n");
            printf("Status  : Week 1 Implementation\n\n");
        }
        else if (strlen(input) == 0)
        {
            continue;
        }
        else
        {
            printf("Unknown command: %s\n", input);
            printf("Type 'help' for available commands.\n\n");
        }
    }

    return 0;
}
