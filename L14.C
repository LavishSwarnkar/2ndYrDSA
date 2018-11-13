//Linear Search
#include<stdio.h>
#include<conio.h>
void linearSearch(int a[], int size, int x);
void main()
{   int a[20], size, x, i;
	clrscr();

	printf("Enter the no. of elements in array: ");
	scanf("%d",&size);

	printf("Input array: \n");
	for(i = 0; i < size ; i++)
	{   printf("A[%d] = ", i);
		scanf("%d", &a[i]);
	}

	printf("\nEnter element to be searched: ");
	scanf("%d",&x);

	linearSearch(a,size,x);

	getch();
}
void linearSearch(int a[], int size, int x)
{	int i;
	for(i=0 ; i<size ; i++)
		if(a[i] == x)
		{	printf("\n%d found at index %d", x, i);
			return;
		}
	printf("\n%d not found!", x);
}