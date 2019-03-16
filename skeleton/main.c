#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

const char* getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, " ");
            tok && *tok;
            tok = strtok(NULL, " \n"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

int main()
{
    int max_size = 10;
    double first_num = 0, second_num = 0;
    struct stack *s;
    const char *current_num;

    FILE* stream = fopen("input.txt", "r");

    char line[1024];

    while (fgets(line, 1024, stream))
    {
        int valid_result = 1;
        char* tmp = strdup(line);
        unsigned int i = 1;

        while(getfield(tmp, i) != NULL){
            tmp = strdup(line);
            current_num = getfield(tmp,i);

            /* TODO: current_num now holds the value at column i 
             * in the row that is currently being observed.
             * Your job is to insert code here to parse it and 
             * determine what to do next (if it's a number then 
             * push it onto the stack, for instance).
             */

            tmp = strdup(line);
            i++;
        }

        printf("\n");
        free(tmp);
    }
    
    fclose(stream); 

    return 0;
}
