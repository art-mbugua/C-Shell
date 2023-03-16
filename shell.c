#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 256

int main(int argc, char **argv)
{
    char buffer[BUFFER_SIZE];

    while (1)
    {
        printf("$ ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        int pid = fork();

        if (pid == 0)
        {
            // Child process
            char **args = malloc(BUFFER_SIZE * sizeof(char *));
            char *token = strtok(buffer, " ");
            int i = 0;

            while (token != NULL)
            {
                args[i] = token;
                token = strtok(NULL, " ");
                i++;
            }

            args[i] = NULL;
            execvp(args[0], args);
            free(args);
        }
        else
        {
            // Parent process
            (NULL);
        }
    }

    return 0;
}