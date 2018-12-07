//Merge Sort
#include<stdio.h>
#include<conio.h>

void merge_sort(int a[], int beg, int end);
void merge(int a[], int beg, int mid, int end);

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

    merge_sort(a, 0, size-1);

    printf("\nAfter sorting, Array is ");
    for(i=0 ; i<size ; i++)
        printf("%d, ", a[i]);

    getch();
}

void merge_sort(int a[], int beg, int end)
{   int mid;
    if(beg<end)
    {   mid = (beg+end)/2;
        merge_sort(a,beg,mid);
        merge_sort(a,mid+1,end);
        merge(a,beg,mid,end);
    }
}

void merge(int a[], int beg, int mid, int end)
{   int i=beg, j=mid+1, index=beg, temp[20];
    while(i<=mid && j<=end)
    {   if(a[i]<a[j])
            temp[index++]=a[i++];
        else
            temp[index++]=a[j++];
    }
    if(i>mid)
        while(j<=end)
            temp[index++]=a[j++];
    else
        while(i<=mid)
            temp[index++]=a[i++];
    for(i=beg ; i<index ; i++)
        a[i]=temp[i];
}