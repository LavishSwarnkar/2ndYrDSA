//Insertion & Selection Sort
#include<stdio.h>
#include<conio.h>

void insertion_sort(int a[], int size);
void selection_sort(int a[], int size);

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

	insertion_sort(a,size);

	printf("\nAfter sorting, Array is ");
	for(i=0 ; i<size ; i++)
		printf("%d, ", a[i]);

	getch();
}

void selection_sort(int a[], int size)
{   int temp, small, i, j;
	for(i=0 ; i<size ; i++)
	{	small = i;
		for(j=i+1 ; j<size ; j++)
			if(a[j] < a[small])
				small = j;
		temp = a[i];
		a[i] = a[small];
		a[small] = temp;
	}
}

void insertion_sort(int a[], int size)
{	int i, temp, j;
	for(i=1 ; i<size ; i++)
	{	temp = a[i];
		j = i-1;
		while(j>=0 && a[j]>temp)
			a[j+1] = a[j--];
		a[j+1] = temp;
	}
}