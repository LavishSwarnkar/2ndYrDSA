//Bubble Sort
#include<stdio.h>
#include<conio.h>
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

	printf("\nBefore sorting, Array is ");
	for(i=0 ; i<size ; i++)
		printf("%d, ", a[i]);

	for(i=1 ; i<size ; i++)
	{	for(j=0 ; j<(size-i) ; j++)
		{	if(a[j] > a[j+1])
			{	temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}
		}
	}

	printf("\nAfter sorting, Array is ");
	for(i=0 ; i<size ; i++)
		printf("%d, ", a[i]);

	getch();
}