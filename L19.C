//Heap Sort
#include<stdio.h>
#include<conio.h>

void heap_sort(int a[], int size);
void heapify(int a[], int size, int i);

void main()
{   int i, a[10], size;
    clrscr();
    
    printf("Enter size of array: ");
    scanf("%d", &size);

    printf(">>INPUT<<\n");
    for(i=0 ; i<size ; i++)
	   {	   printf("Enter A[%d]: ", i+1);
		      scanf("%d", &a[i]);
    }

    printf("\nBefore sorting, Array is ");
    for(i=0 ; i<size ; i++)
        printf("%d, ", a[i]);

    heap_sort(a, size);

    printf("\nAfter sorting, Array is ");
    for(i=0 ; i<size ; i++)
        printf("%d, ", a[i]);

    getch();
}

void heap_sort(int a[], int size)
{   int i, temp;
    for(i=size/2-1 ; i>=0 ; i--)
        heapify(a, size, i);
    for(i=size-1 ; i>=0 ; i--)
    {   temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        
        heapify(a, i, 0);
    }
}

void heapify(int a[], int size, int i)
{   int largest = i, l, r, temp;
    l = i*2 + 1;
    r = i*2 + 2;
    if(l<size && a[l]>a[largest])
        largest = l;
    if(r<size && a[r]>a[largest])
        largest = r;
    if(largest != i)
    {   temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        
        heapify(a, size, largest);
    }
}
