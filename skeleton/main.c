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
//creates stack and necessary variables
    int max_size = 10;
    double first_num = 0, second_num = 0;
    struct stack *s;
    const char *current_num;

//opens input/output files
    FILE* input = fopen("input.txt", "r");
    FILE* output = fopen("output.txt", "w");

    s = create_stack(max_size);
    char line[1024];

    while (fgets(line, 1024, input))
    {
        int valid_result = 1;
        char* tmp = strdup(line);
        unsigned int i = 1;

//reads from file and stores current char/num in current_num
        while(getfield(tmp, i) != NULL){
            tmp = strdup(line);
            current_num = getfield(tmp,i);

		//check - sign
		if(*current_num == '-')
		{
			//prints - sign
                	printf("- ");
                	fprintf(output, "- ");
                
		//checks if there are not enough nums to perform operation
                	if(!has_atleast_two_nums(s)){
                    		printf("Invalid equation, moving to next.\n");
                    		valid_result = 0;
                    		break;
                	}
			//pushes the new number after operation is performed
                	first_num = pop(s);
                	second_num = pop(s);
			double sub = second_num-first_num;
                	push(s, sub);
            	}
		//check + sign
		else if(*current_num == '+')
		{
			//prints + sign
                	printf("+ ");
                
                	fprintf(output, "+ ");

		//checks if there are not enough nums to perform operation
                	if(!has_atleast_two_nums(s)){
                    	printf("Invalid equation, moving to next.\n");
                    	valid_result = 0;
                    	break;
                	}

			//pushes the new number after operation is performed
                	first_num = pop(s);
                	second_num = pop(s);
			double sum = first_num+second_num;
                	push(s, sum);
        	}
		//check * sign
		else if(*current_num == '*')
		{
			//prints * sign
                	printf("* ");
                	fprintf(output, "* ");
                
		//checks if there are not enough nums to perform operation
                	if(!has_atleast_two_nums(s)){
                    		printf("Invalid equation, moving to next.\n");
                    		valid_result = 0;
                    		break;
                	}
                
			//pushes the new number after operation is performed
                	first_num = pop(s);
                	second_num = pop(s);
			double mult = first_num*second_num;
                	push(s, mult);
            	}
		//check / sign
		else if(*current_num == '/'){
			//prints * sign
                	printf("/ ");
                	fprintf(output, "/ ");
                
		//checks if there are not enough nums to perform operation
                	if(!has_atleast_two_nums(s)){
                    		printf("Invalid equation, moving to next.\n");
                    		valid_result = 0;
                    		break;
                	}
                
			//pushes the new number after operation is performed
                	first_num = pop(s);
                	second_num = pop(s);
			double div = (double)second_num/(double)first_num;
                	push(s, div);
            	}
		//check number
		else
		{
                	double input_num = atof(current_num);
                	printf("%.3f ", input_num);
                	fprintf(output, "%.3f ", input_num);
                	push(s,input_num);
            	}

            tmp = strdup(line);
            i++;
        }

//prints the new value pushed to the stack
	if(valid_result){
            printf("= %.3f\n",peek(s));
            fprintf(output, "= %.3f\n",pop(s));
            clear(s);
        }

        printf("\n");
        free(tmp);
    }
    
//closes files and frees memory
    fclose(input); 
    fclose(output);

    destroy_stack(s);

    return 0;
}
