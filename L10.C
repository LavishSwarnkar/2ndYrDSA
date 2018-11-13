//Sum and average of array elements
#include<stdio.h>
#include<conio.h>

int sum(int a[], int size);
float avg(int a[], int size);

void main()
{   int i, j, a[10], size, temp;
	clrscr();

	printf("Enter size of array: ");
	scanf("%d", &size);

	printf(">>INPUT<<\n");
	for(i=0 ; i<size ; i++)
	{	printf("Enter A[%d]: ", i+1);
		scanf("%d", &a[i]);
	}

	printf("\nSum of elements = %d\nAvg of elements = %f", sum(a,size), avg(a,size));

	getch();
}

int sum(int a[], int size)
{   int i, sum=0;
	for(i=0 ; i<size ; i++)
		sum+=a[i];
	return sum;
}

float avg(int a[], int size)
{	return  (float)sum(a, size)/size;
}

