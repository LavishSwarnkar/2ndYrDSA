//All Sorting Algos
#include<stdio.h>
#include<conio.h>

void bubble_sort(int a[], int size);
void selection_sort(int a[], int size);
void insertion_sort(int a[], int size);
void merge_sort(int a[], int beg, int end);
void merge(int a[], int beg, int mid, int end);
int partition(int a[], int beg, int end);
void quick_sort(int a[], int beg, int end);
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

void bubble_sort(int a[], int size)
{    int temp, i, j;
	    for(i=1 ; i<size ; i++)
	    {	    for(j=0 ; j<=(size-i-1) ; j++)
		        {    if(a[j] > a[j+1])
			            {	   temp = a[j];
				               a[j] = a[j+1];
				               a[j+1] = temp;
			            }
		        }
	    }
}

void selection_sort(int a[], int size)
{   int temp, small, i, j;
    for(i=0 ; i<size ; i++)
    {    	small = i;
		        for(j=i+1 ; j<size ; j++)
			           if(a[j] < a[small])
				               small = j;
		        temp = a[i];
		        a[i] = a[small];
		        a[small] = temp;
    }
}

void insertion_sort(int a[], int size)
{    int i, temp, j;
	    for(i=1 ; i<size ; i++)
	    {    temp = a[i];
		        j = i-1;
		        while(j>=0 && a[j]>temp)
			           a[j+1] = a[j--];
		        a[j+1] = temp;
	    }
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

void quick_sort(int a[], int beg, int end)
{   int loc;
    if(beg<end)
    {   loc = partition(a, beg, end);
        quick_sort(a, beg, loc-1);
        quick_sort(a, loc+1, end);
    }
}

int partition(int a[], int beg, int end)
{   int loc, left, right, f=0, temp;
    loc=left=beg;
    right=end;
    while(!f)
    {   while(a[loc]<=a[right] && right!=loc)
            right--;
        if(right==loc)
            f=1;
        else if(a[loc]>a[right])
        {   temp = a[loc];
            a[loc] = a[right];
            a[right] = temp;
            loc = right;
        }
        if(!f)
        {    while(a[loc]>=a[left] && left!=loc)
                left++;
                if(left==loc)
                    f=1;
                else if(a[loc]<a[left])
                {   temp = a[loc];
                    a[loc] = a[left];
                    a[left] = temp;
                    loc = left;
                }
        }
    }
    return loc;
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