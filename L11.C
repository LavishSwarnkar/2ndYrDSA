//11.Linked List
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node
{	int data;
	struct node * next;
};

struct node * start = NULL;
struct node * create_LinkedList(struct node*);
struct node * insert_beg(struct node*);
struct node * insert_end(struct node*);
struct node * delete_beg(struct node*);
struct node * delete_end(struct node*);
struct node * insert_after(struct node*);
struct node * insert_before(struct node*);
struct node * delete_node(struct node*);
struct node * display(struct node*);

void main()
{   int option;

	do
	{   clrscr();
		printf(">>MAIN MENU<<");
		printf("\n1. Create Linked List");
		printf("\n2. Display Linked List");
		printf("\n3. Add a node at the beginning");
		printf("\n4. Add a node at the end");
		printf("\n5. Delete a node at the beginning");
		printf("\n6. Delete a node at the end");
		printf("\n7. Add a node after a node");
		printf("\n8. Add a node before a node");
		printf("\n9. Delete a node");
		printf("\n0. Exit");
		printf("\nEnter choice: ");	scanf("%d", &option);

		switch(option)
		{   case 0: exit(1); break;
			case 1: start = create_LinkedList(start);
					printf("\nCreated"); break;
			case 2: start = display(start);	break;
			case 3: start = insert_beg(start);	break;
			case 4: start = insert_end(start);	break;
			case 5: start = delete_beg(start);	break;
			case 6: start = delete_end(start);	break;
			case 7: start = insert_after(start);	break;
			case 8: start = insert_before(start);	break;
			case 9: start = delete_node(start);	break;
			default: printf("\nWrong Choice! Press any key to try again.");
					 getch();
		}

		printf("\nPress any key to go to main menu.");
		getch();

	}while(1);
}

struct node * create_LinkedList(struct node* start)
{	struct node * new_node;
	int num;
	printf("\n\n>>CREATE LINKED LIST<<\nEnter -1 to end");
	printf("\nEnter data: ");	scanf("%d", &num);

	while(num != -1)
	{	new_node = (struct node *) malloc(sizeof(struct node *));
		new_node->data = num;

		if(start == NULL)
		{	new_node->next = NULL;
			start = new_node;
		}
		else
		{   new_node->next = start;
			start = new_node;
		}
		printf("Enter data: ");	scanf("%d", &num);
	}
	return start;
}

struct node * display(struct node* start)
{	struct node * ptr;
	ptr = start;
	printf("\n\n>>DISPLAY LINKED LIST<<\n");
	while(ptr != NULL)
	{	printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}
	printf("NULL");
	return start;
}

struct node * insert_after(struct node* start)
{	struct node * new_node;
	struct node * preptr;
	struct node * ptr;
	int num, f=0;

	printf("\n\n>>INSERT AFTER A NODE OF LINKED LIST<<\n");
	printf("\nEnter node after which, new node is to be inserted: ");	scanf("%d", &num);

	if(start == NULL)
	{   printf("\nUnderflow!");
	}
	else
	{   ptr = start;
		while(ptr->next != NULL)
		{	preptr = ptr;
			ptr = ptr->next;
			if(preptr->data == num)
			{	printf("\nEnter data: ");	scanf("%d", &num);
				new_node = (struct node *) malloc(sizeof(struct node *));
				new_node->data = num;
				new_node->next = ptr;
				preptr->next = new_node;
				f=1; break;
			}
		}

		if(!f)
			printf("\nNode %d not found!", num);
		else
			printf("\nInserted!");
	}
	return start;
}

struct node * insert_before(struct node* start)
{	struct node * new_node;
	struct node * preptr;
	struct node * ptr;
	int num, f=0;

	printf("\n\n>>INSERT BEFORE A NODE OF LINKED LIST<<\n");
	printf("\nEnter node before which, new node is to be inserted: ");	scanf("%d", &num);

	if(start == NULL)
	{   printf("\nUnderflow!");
	}
	else
	{   ptr = start;
		preptr = start;
		if(start->data == num)
		{	printf("\nEnter data: ");	scanf("%d", &num);
			new_node = (struct node *) malloc(sizeof(struct node *));
			new_node->data = num;
			new_node->next = start;
			start = new_node;
			f=1;
		}
		else
		{	while(preptr->next != NULL)
			{   preptr = ptr;
				ptr = ptr->next;
				if(ptr->data == num)
				{	printf("\nEnter data: ");	scanf("%d", &num);
					new_node = (struct node *) malloc(sizeof(struct node *));
					new_node->data = num;
					new_node->next = ptr;
					preptr->next = new_node;
					f=1; break;
				}
			}
		}

		if(!f)
			printf("\nNode %d not found!", num);
		else
			printf("\nInserted!");
	}
	return start;
}

struct node * insert_beg(struct node* start)
{   struct node * new_node;
	int num;

	printf("\n\n>>INSERT AT BEGINNING OF LINKED LIST<<\n");
	printf("\nEnter data: ");	scanf("%d", &num);

	new_node = (struct node *) malloc(sizeof(struct node *));
	new_node->data = num;

	if(start == NULL)
	{	new_node->next = NULL;
		start = new_node;
	}
	else
	{   new_node->next = start;
		start = new_node;
	}
	printf("\nInserted!");

	return start;
}

struct node * insert_end(struct node* start)
{   struct node * new_node;
	struct node * ptr;
	int num;

	printf("\n\n>>INSERT AT END OF LINKED LIST<<\n");
	printf("\nEnter data: ");	scanf("%d", &num);

	new_node = (struct node *) malloc(sizeof(struct node *));
	new_node->data = num;
	new_node->next = NULL;

	if(start == NULL)
	{   printf("\nUnderflow!");
	}
	else
	{   ptr = start;
		while(ptr->next != NULL)
			ptr = ptr->next;

		ptr->next = new_node;
		printf("\nInserted!");
	}

	return start;
}

struct node * delete_beg(struct node* start)
{   struct node * ptr;
	int num;
	printf("\n\n>>DELETE AT BEGINING OF LINKED LIST<<\n");
	if(start == NULL)
	{   printf("\nUnderflow!");
	}
	else
	{   ptr = start;
		start = start->next;
		num = ptr->data;
		free(ptr);
		printf("\n%d Deleted!", num);
	}
	return start;
}

struct node * delete_end(struct node* start)
{   struct node * ptr;
	struct node * preptr;

	if(start == NULL)
		printf("\nUnderflow!");
	else if(start->next == NULL)
		printf("\nLinked contains only 1 element!");
	else
	{   ptr = start;
		while(ptr->next != NULL)
		{   preptr = ptr;
			ptr = ptr->next;
		}

		preptr->next = NULL;
		printf("\n%d Deleted!", ptr->data);
		free(ptr);
	}
	return start;
}

struct node * delete_node(struct node* start)
{	struct node * new_node;
	struct node * preptr;
	struct node * ptr;
	int num, f=0;

	printf("\n\n>>DELETE A NODE OF LINKED LIST<<\n");

	if(start == NULL)
		printf("\nUnderflow!");
	else
	{   printf("\nEnter node to be deleted: ");	scanf("%d", &num);
		ptr = start;
		preptr = start;
		while(ptr->next != NULL)
		{   preptr = ptr;
			ptr = ptr->next;
			if(ptr->data == num)
			{   preptr->next = ptr->next;
				f=1; break;
			}
		}

		if(!f)
			printf("\nNode %d not found!", num);
		else
			printf("\nNode %d deleted!", num);
	}
	return start;
}


