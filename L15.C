//Binary Search
#include<stdio.h>
#include<conio.h>
void binarySearch(int a[], int BEG, int END, int x);
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

	binarySearch(a, 0, size-1, x);

	getch();
}
void binarySearch(int a[], int BEG, int END, int x)
{	int MID;
	if(BEG < END)
	{	MID = (BEG + END)/2;
		if(a[MID] == x)
			printf("\n%d found at index %d", x, MID);
		else if(a[MID] > x)
			binarySearch(a, BEG, MID-1, x);
		else
			binarySearch(a, MID+1, END, x);
	}
	else
		printf("\n%d not found!", x);
}