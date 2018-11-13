//Tower of Hanoi
#include<stdio.h>
#include<conio.h>
void move(int N, char SRC, char DEST, char SPARE);
void main()
{   int N;
	clrscr();

	printf("Enter the no. of rings to be moved: ");
	scanf("%d",&N);

	move(N, 'A', 'C', 'B');

	getch();
}
void move(int N, char SRC, char DEST, char SPARE)
{	if(N == 1)
		printf("\nMove from %c to %c", SRC, DEST);
	else
	{	move(N-1, SRC, SPARE, DEST);
		move(1, SRC, DEST, SPARE);
		move(N-1, SPARE, DEST, SRC);
	}
}