//12.Stack
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct stack
{	int data;
	struct stack * next;
};

struct stack * top = NULL;
void create();
void peep();
void push();
void pop();
void display();

void main()
{   int option;

	do
	{   clrscr();
		printf(">>MAIN MENU<<");
		printf("\n1. Create Stack");
		printf("\n2. Peep");
		printf("\n3. Push");
		printf("\n4. Pop");
		printf("\n5. Display");
		printf("\n0. Exit");
		printf("\nEnter choice: ");	scanf("%d", &option);

		switch(option)
		{   case 0: exit(1); 	break;
			case 1: create(); 	break;
			case 2: peep();		break;
			case 3: push();		break;
			case 4: pop();		break;
			case 5: display();		break;
			default: printf("\nWrong Choice! Press any key to try again.");
					 getch();
		}

		printf("\nPress any key to go to main menu.");
		getch();

	}while(1);
}

void create()
{   struct stack * new_node;
	int num;
	if(top == NULL)
	{   printf("\nEnter data (-1 to stop): ");	scanf("%d", &num);
		while(num != -1)
		{	new_node = (struct stack *) malloc(sizeof(struct stack *));
			new_node->data = num;
			if(top == NULL)
			{	top = new_node;
				top->next = NULL;
			}
			else
			{	new_node->next = top;
				top = new_node;
			}
			printf("Enter data: ");	scanf("%d", &num);
		}
		printf("\nStack created!");
	}
	else
	{	printf("\nThe Stack is already created!");
	}
}

void peep()
{   if(top == NULL)
		printf("\nStack Underflow!");
	else
		printf("\n%d is top most element of Stack.", top->data);
}

void push()
{	struct stack * new_node;
	int num;
	printf("\nEnter data: ");	scanf("%d", &num);
	new_node = (struct stack *) malloc(sizeof(struct stack *));
	new_node->data = num;
	if(top == NULL)
	{   top = new_node;
		top->next = NULL;
	}
	else
	{	new_node->next = top;
		top = new_node;
	}
	printf("\n%d pushed!", num);
}

void pop()
{   struct stack * ptr;
	if(top == NULL)
		printf("\nStack Underflow!");
	else
	{   ptr = top;
		printf("\n%d popped!", top->data);
		top = top->next;
		free(ptr);
	}
}

void display()
{   struct stack * ptr;
	if(top == NULL)
		printf("\nStack Underflow!");
	else
	{   ptr = top;
		printf("\n\nStack: ");
		while(ptr != NULL)
		{	printf("\n%d", ptr->data);
			ptr = ptr->next;
		}
	}
}