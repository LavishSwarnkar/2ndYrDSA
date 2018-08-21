#include<stdio.h>
#include<conio.h>
void main()
{   int no, i, found = 0;
	clrscr();

	printf("Enter the no. ");
	scanf("%d",&no);

	for(i=no/2 ; i>=2 ; i--)
	{	if(no%i == 0)
		{   found = 1;
			break;
		}
	}

	if(found)
		printf("Entered no is not prime");
	else
		printf("Entered no is prime");

	getch();
}