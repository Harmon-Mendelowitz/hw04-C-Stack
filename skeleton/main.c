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
    FILE* output = fopen("output.txt", "w");

    s = create_stack(max_size);
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
		if(*current_num == '+')
		{
                	printf("+ ");
                
                	fprintf(output, "+ ");

                	/*if(!has_atleast_two_nums(s)){
                    	printf("Invalid equation, moving to next.\n");
                    	fprintf(stream2, " Invalid equation.\n");
                    	valid_result = 0;
                    	break;
                	}*/
                	first_num = pop(s);
                	second_num = pop(s);
			double sum = first_num+second_num;
                	push(s, sum);
        	}
		else if(*current_num == '-')
		{
                	printf("- ");
                	fprintf(output, "- ");
                
                	/*if(!has_atleast_two_nums(s)){
                    		printf("Invalid equation, moving to next.\n");
                    		fprintf(stream2, " Invalid equation.\n");
                    		valid_result = 0;
                    		break;
                	}*/
                	first_num = pop(s);
                	second_num = pop(s);
			double sub = second_num-first_num;
                	push(s, sub);
            	}
		else if(*current_num == '*')
		{
                	printf("* ");
                	fprintf(output, "* ");
                
                	/*if(!has_atleast_two_nums(s)){
                    		printf("Invalid equation, moving to next.\n");
                    		fprintf(stream2, " Invalid equation.\n");
                    		valid_result = 0;
                    		break;
                	}*/
                
                	first_num = pop(s);
                	second_num = pop(s);
			double mult = first_num*second_num;
                	push(s, mult);
            	}
		else if(*current_num == '/'){
                	printf("/ ");
                	fprintf(output, "/ ");
                
                	/*if(!has_atleast_two_nums(s)){
                    		printf("Invalid equation, moving to next.\n");
                    		fprintf(stream2, " Invalid equation.\n");
                    		valid_result = 0;
                    		break;
                	}*/
                
                	first_num = pop(s);
                	second_num = pop(s);
			double div = (double)second_num/(double)first_num;
                	push(s, div);
            	}
		else
		{
			//check if num
                	double input_num = atof(current_num);
                	printf("%.2f ", input_num);
                	fprintf(output, "%.2f ", input_num);
                	push(s,input_num);
            	}

            tmp = strdup(line);
            i++;
        }

	//???????????????????
	if(valid_result){
            printf("= %.2f\n",peek(s));
            fprintf(output, "= %.2f\n",pop(s));
            clear(s);
        }

        printf("\n");
        free(tmp);
    }
    
    fclose(stream); 
    fclose(output);

    destroy_stack(s);

    return 0;
}
