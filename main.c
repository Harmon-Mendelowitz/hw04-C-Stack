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
    FILE* stream2 = fopen("output.txt", "w");

    char line[1024];
    s = create_stack(max_size);

    while (fgets(line, 1024, stream))
    {
        int valid_result = 1;
        char* tmp = strdup(line);
        unsigned int i = 1;

        while(getfield(tmp, i) != NULL){
            tmp = strdup(line);
            current_num = getfield(tmp,i);

            if(*current_num == '+'){
                printf("+ ");
                
                fprintf(stream2, "+ ");

                if(!has_atleast_two_nums(s)){
                    printf("Invalid equation, moving to next.\n");
                    fprintf(stream2, " Invalid equation.\n");
                    valid_result = 0;
                    break;
                }
                first_num = pop(s);
                second_num = pop(s);
                push(s, first_num+second_num);
            }else if(*current_num == '-'){
                printf("- ");
                fprintf(stream2, "- ");
                
                if(!has_atleast_two_nums(s)){
                    printf("Invalid equation, moving to next.\n");
                    fprintf(stream2, " Invalid equation.\n");
                    valid_result = 0;
                    break;
                }
                
                first_num = pop(s);
                second_num = pop(s);
                push(s, second_num-first_num);

            }else if(*current_num == '*'){
                printf("* ");
                fprintf(stream2, "* ");
                
                if(!has_atleast_two_nums(s)){
                    printf("Invalid equation, moving to next.\n");
                    fprintf(stream2, " Invalid equation.\n");
                    valid_result = 0;
                    break;
                }
                
                first_num = pop(s);
                second_num = pop(s);
                push(s, first_num*second_num);

            }else if(*current_num == '/'){
                printf("/ ");
                fprintf(stream2, "/ ");
                
                if(!has_atleast_two_nums(s)){
                    printf("Invalid equation, moving to next.\n");
                    fprintf(stream2, " Invalid equation.\n");
                    valid_result = 0;
                    break;
                }
                
                first_num = pop(s);
                second_num = pop(s);
                push(s, second_num/(double)first_num);

            }else{
                double input_num = atof(current_num);
                printf("%.2f ", input_num);
                fprintf(stream2, "%.2f ", input_num);
                push(s,input_num);
            }



            

            /* TODO insert code here to first check if tmp is an operation, then
            *  put into stack if not
            *  int m = *getfield(tmp, i);
            *  printf("tmp is %i\n", m);
            */
            
            tmp = strdup(line);
            i++;
        }

        if(valid_result){
            printf("= %.2f\n",peek(s));
            fprintf(stream2, "= %.2f\n",pop(s));
            clear(s);
        }
        printf("\n");
        free(tmp);
    }
    
    fclose(stream); 
    fclose(stream2); 
    destroy_stack(s);

    return 0;
}
