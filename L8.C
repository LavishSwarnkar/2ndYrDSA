//Bubble Sort
#include<stdio.h>
#include<conio.h>

void bubble_sort(int a[], int size);

void main()
{   int i, a[10], size;
	clrscr();

	printf("Enter size of array: ");
	scanf("%d", &size);

	printf(">>INPUT<<\n");
	for(i=0 ; i<size ; i++)
	{	printf("Enter A[%d]: ", i+1);
		scanf("%d", &a[i]);
	}

	printf("\nBefore sorting, Array is ");
	for(i=0 ; i<size ; i++)
		printf("%d, ", a[i]);

	bubble_sort(a,size);

	printf("\nAfter sorting, Array is ");
	for(i=0 ; i<size ; i++)
		printf("%d, ", a[i]);

	getch();
}

void bubble_sort(int a[], int size)
{   int temp, i, j;
	for(i=1 ; i<size ; i++)
	{	for(j=0 ; j<=(size-i-1) ; j++)
		{	if(a[j] > a[j+1])
			{	temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}
}