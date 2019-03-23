#include <stdio.h>
#include "stack.h"

struct stack* create_stack(int max_size){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
    struct stack* s = (struct stack*) malloc(sizeof(struct stack));
    s->stack_nums = malloc(sizeof(double)*max_size);
    s->max_size = max_size;
    s->current_size = 0;
	return s;

    return NULL;
}

int destroy_stack(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
	if(s!=NULL)
	{
		if(s->stack_nums!= NULL)
			free(s->stack_nums);
		free(s);
		return 1;
	}
	
	return 0;
}

double peek(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
	if(s!=NULL)
	{
		if(s->stack_nums!=NULL)
		{
			if(s->current_size != 0)
				return s->stack_nums[s->current_size - 1];
		}
	}
	
	return -1;
}

double pop(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
	if(s!=NULL)
	{
		if(s->stack_nums!=NULL)
		{
			if(s->current_size != 0)
			{
				double p = s->stack_nums[s->current_size - 1];
				s->stack_nums[s->current_size - 1] = -1;
				s->current_size = s->current_size - 1;
				return p;
			}
		}
	}
	
	return -1;
}

int push(struct stack* s, double value){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
	if(s!=NULL)
	{
		if(s->stack_nums!=NULL)
		{
			if(s->current_size != s->max_size)
			{
				s->stack_nums[s->current_size] = value;
				s->current_size = s->current_size + 1;
				return 1;
			}
		}
	}
	
	return -1;
}

int clear(struct stack *s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
	if(s!=NULL)
	{
		if(s->stack_nums!=NULL)
		{
			for(int x=s->current_size-1; x>0; x--)
			{
				s->stack_nums[s->current_size-1] = -1;
				s->current_size = s->current_size - 1;
			}
		}
		if(s->current_size < 0)
		{
			s->current_size = 0;
			return 1;
		}
	}
	
	return 0;
}

int is_full(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
	if(s!=NULL)
	{
		if(s->stack_nums!=NULL)
		{
			if(s->current_size == s->max_size)
				return 1;
		}
	}
	
	return 0;
}

int is_empty(struct stack* s){

    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
	if(s!=NULL)
	{
		if(s->stack_nums!=NULL)
		{
			if(s->current_size == 0)
				return 1;
		}
	}

	return 0;
}

int has_atleast_two_nums(struct stack* s){
    
    /* TODO: insert your code here, referring
     * to the project pdf or stack.h for the 
     * function specification.
     */
	if(s!=NULL)
	{
		if(s->stack_nums!=NULL)
		{
			if(s->current_size >=2)
				return 1;
		}
	}

	return -1;
}

void print_stack(struct stack* s){
    int i = 0;
    printf("The contents of the stack are: ");
    
    if(is_empty(s)){
        printf("empty\n");
        return;
    }
   
    for (i = 0; i < s->current_size; i++){
        printf("%f ", s->stack_nums[i]);
    } 

    printf("\n");
}

