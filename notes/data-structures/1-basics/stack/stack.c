#include <stdio.h>
#include <stdlib.h>

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define DEFAULT "\x1b[0m"

#if defined(_WIN32)
	void clearScreen() system("cls");
#elif defined(__linux__)
	void clearScreen() system("clear");
#endif

typedef struct node {
	int data;
	struct node* next;
} node_t;

typedef struct stack{
	node_t* head;
} stack_t; 

node_t* createNode(int data){ 
        node_t* node = (node_t*) malloc(sizeof(node_t));
        
        if(node == NULL){
                clearScreen(0;
                printf("err: Failed creating node;\n"); 
                exit(EXIT_FAILURE);
        }       
        node->data = data;
        node->next = NULL;
        
        return node;
}

stack_t* createStack(){
	stack_t stack = (stack_t*) malloc(sizeof(stack_t));
	
	if(stack == NULL) {
		clearScreen();
		printf("err: Failed creating stack;\n");
		exit(EXIT_FAILURE);
	}

	stack->head = NULL;
	return stack;
}

void push(stack_t* stack int data){
	node_t* newNode = createNode(data);
	
	newNode->next = stack->head;
	stack->head = newNode;

	return 1;
}

int pop(node_t* stack){
	node_t* removed_node = stack->next;
	int data = stack->data;
	stack->next = removed_node->next;
	free(removed_node);
	return data;
}

void printNode(int data){
	printf("|%d| ",data);

}

void printStack(node_t* stack){
	system("clear");
	node_t* current = stack;
	while(current != NULL){
		printNode(current->data);
		current = current->next;
	}
	printf(RED);
	printNode(stack->data);
	printf(DEFAULT);
}

void menu(){
	printf("1)Add a new item to the stack.\n");
	printf("2)Remove an item from the stack.\n");
	printf("3)Print the stack.\n");
	printf("4)Exit.\n");

}


int main (int argc, char* argv[]){
	// stack
	node_t* stack;
	unsigned int option;
	int newData;

	createStack(&stack);

	while(option <= 4){
		menu();
		scanf("%d",&option);

		switch(option){
			case 1: 
				printf("Give a value to the new item: ");
				scanf("%d",&newData);
				push(stack, newData);
				break;
			case 2:
				pop(stack);
				break;
			case 3:
				printStack(stack);
				break;
			case 4:
				system("clear");
				printf("Thanks for using the program.\n");
				free(stack);
				return 0;	
			default:
				break;

				
		}
	}
	free(stack);
	return 0;
}
