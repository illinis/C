#include <stdio.h>
#include <stdlib.h>

#define RED     "\x1b[31m"
#define GREEN 	"\x1b[32m"
#define YELLOW  "\x1b[33m"
#define DEFAULT "\x1b[0m"
#define MAX_SIZE 100

// stack struct
typedef struct stack{
	int arr[MAX_SIZE];
	int top;
} stack_t;

// stack functions
int push(stack_t* stack, int value){
	system("clear");
	if(stack->top >= MAX_SIZE-1) return 0;
	stack->top++;
	stack->arr[stack->top] = value;
	printf("Added item to stack.\n");
	return 1;
}

int pop(stack_t* stack){
        system("clear");
	if(stack->top < 0) return 0;
	stack->top--;
	stack->arr[stack->top] = 0;
	printf(GREEN "Removed item from stack.\n" DEFAULT);
	return 1;
}

// display functions
void printItem(int data){ 
        printf("|%d| ",data);    
}


int printStack(stack_t stack){
	system("clear");
	int current = stack.top;
	if(current < 0) return 0;
	
	// outputs the color based on the size of the array
	if(current == 0){
		printf(YELLOW);
        	printItem(stack.arr[current]);
		printf(DEFAULT);
		return 1;
	}
	else{
		printf(GREEN);
        	printItem(stack.arr[current]);
		printf(DEFAULT);
		current--;
	}
	printf(YELLOW);
        while(current > 0){
                printItem(stack.arr[current]);
		current--;
        }

        printf(RED);
        printItem(stack.arr[current]);
        printf(DEFAULT);
	printf("\n");
	
	return 1;
}

void menu(){
        printf("1)Add a new item to the stack.\n");
        printf("2)Remove an item from the stack.\n");
        printf("3)Print the stack.\n");
        printf("4)Exit.\n");
}

int main(int argc, char* argv[]){
	stack_t stack;
	stack.top = -1;

	int option, value;

	do{
		menu();
		scanf("%d",&option);
		switch(option){
			case 1:
				printf("Type the value you want to add to the stack: ");
				scanf("%d",&value);
				if(!push(&stack, value)) printf(RED "Stack is already full!\n" DEFAULT);
				
				break;
			case 2:
				if(!pop(&stack)) printf(RED "Stack is already empty!\n" DEFAULT);
				break;
			case 3:
				if(!printStack(stack)) printf(YELLOW "Stack is empty!\n" DEFAULT);
				break;
			case 4:
				system("clear");
				printf("Thanks for using the application.\n");
				return 0;
				break;
			default:
				system("clear");
				printf("Invalid input.\n");
				break;
		}
	} while(option != 4);
	return 0;
}
