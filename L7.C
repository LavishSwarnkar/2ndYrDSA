//Multiply 2 Matrix
#include<stdio.h>
#include<conio.h>
void main()
{   int a[2][2], b[2][2], c[2][2], i, j, k, sum;
	clrscr();

	printf("Input matrix A : \n");
	for(i = 0; i < 2 ; i++)
		for(j = 0; j < 2 ; j++)
		{   printf("Enter A[%d][%d]: ", i+1, j+1);
			scanf("%d", &a[i][j]);
		}

	printf("\nInput matrix B : \n");
	for(i = 0; i < 2 ; i++)
		for(j = 0; j < 2 ; j++)
		{   printf("Enter B[%d][%d]: ", i+1, j+1);
			scanf("%d", &b[i][j]);
		}

	for(i = 0; i < 2 ; i++)
		for(j = 0; j < 2 ; j++)
		{   sum = 0;
			for(k = 0; k < 2 ; k++)
				sum += a[i][k] * b[k][j];
			c[i][j] = sum;
		}

	printf("\nMatrix A : \n");
	for(i = 0; i < 2 ; i++)
	{   for(j = 0; j < 2 ; j++)
		   printf("%d ",a[i][j]);
		printf("\n");
	}

	printf("\nMatrix B : \n");
	for(i = 0; i < 2 ; i++)
	{   for(j = 0; j < 2 ; j++)
		   printf("%d ",b[i][j]);
		printf("\n");
	}

	printf("\nMatrix A*B : \n");
	for(i = 0; i < 2 ; i++)
	{   for(j = 0; j < 2 ; j++)
		   printf("%d ",c[i][j]);
		printf("\n");
	}

	getch();
}