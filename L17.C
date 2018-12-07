//Quick Sort
#include<stdio.h>
#include<conio.h>

int partition(int a[], int beg, int end);
void quick_sort(int a[], int beg, int end);

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

    quick_sort(a, 0, size-1);

    printf("\nAfter sorting, Array is ");
    for(i=0 ; i<size ; i++)
        printf("%d, ", a[i]);

    getch();
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