//Subtract 2 array
#include<stdio.h>
#include<conio.h>
void main()
{   int a[20], b[20], c[20], size, i;
	clrscr();

	printf("Enter the no. of elements in each array: ");
	scanf("%d",&size);

	printf("Input array A : \n");
	for(i = 0; i < size ; i++)
	{   printf("A[%d] = ", i);
		scanf("%d", &a[i]);
	}

	printf("Input array B : \n");
	for(i = 0; i < size ; i++)
	{   printf("B[%d] = ", i);
		scanf("%d", &b[i]);

		c[i] = a[i] - b[i];
	}

	printf("Difference of A and B is :");

	for(i = 0; i < size ; i++)
		printf("%d, ", c[i]);

	getch();
}