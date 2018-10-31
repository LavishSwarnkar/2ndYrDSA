//13.Queue
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{	int data;
	struct node * next;
};

struct queue
{	struct node * front;
	struct node * rear;
};

struct queue q;
void create();
void enqueue();
void dequeue();
void display();

void main()
{   int option;

	do
	{   clrscr();
		printf(">>MAIN MENU<<");
		printf("\n1. Create Queue");
		printf("\n2. Insert");
		printf("\n3. Delete");
		printf("\n4. Display");
		printf("\n0. Exit");
		printf("\nEnter choice: ");	scanf("%d", &option);

		switch(option)
		{   case 0: exit(1); 	break;
			case 1: create(); 	break;
			case 2: enqueue();	break;
			case 3: dequeue();		break;
			case 4: display();		break;
			default: printf("\nWrong Choice! Press any key to try again.");
					 getch();
		}

		printf("\nPress any key to go to main menu.");
		getch();

	}while(1);
}

void create()
{   struct node * new_node;
	int num;
	printf("Enter data: ");	scanf("%d", &num);

	q.front = NULL;
	q.rear = NULL;

	while(num != -1)
	{	new_node = (struct node *) malloc(sizeof(struct node *));
		new_node->data = num;
		new_node->next = NULL;

		if(q.rear == NULL)
		{	q.rear = new_node;
			q.front = new_node;
		}
		else
		{	q.rear->next = new_node;
			q.rear = new_node;
		}

		printf("\nEnter data (-1 to stop): ");	scanf("%d", &num);
	}
	printf("\nQueue created!");

}

void enqueue()
{   struct node * new_node;
	int num;

	if(q.front == NULL)
	{	printf("\nQueue underflow or Queue has not been created!");
		return;
	}

	printf("Enter data: ");	scanf("%d", &num);
	new_node = (struct node *) malloc(sizeof(struct node *));
	new_node->data = num;
	new_node->next = NULL;
	q.rear->next = new_node;
	q.rear = new_node;

	printf("\n%d enqueued!", num);
}

void dequeue()
{   struct node * ptr;

	if(q.front == NULL)
	{	printf("\nQueue Underflow!");
		return;
	}

	ptr = q.front;
	q.front = q.front->next;
	printf("\n%d dequeued!", ptr->data);
	free(ptr);
}

void display()
{	struct node * ptr;
	if(q.front == NULL)
	{	printf("\nQueue Underflow!");
		return;
	}

	ptr = q.front;
	printf("\nFRONT-> ");
	while(ptr != NULL)
	{	printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("<- REAR");
}