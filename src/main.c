#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

#define DIM      ( 8 )

#define EMPTY    ( (char)0 )
#define WHITE    ( (char)1 )
#define BLACK    ( (char)2 )

static char g_board[DIM * DIM];

int is_valid(int x, int y)
{
	return 0 <= x && x < DIM && 0 <= y && y < DIM;
}

char get(int x, int y)
{
	return g_board[DIM * y + x];
}

void set(int x, int y, char v)
{
	g_board[DIM * y + x] = v;
}

void init()
{
	memset(g_board, EMPTY, DIM * DIM);

	set(DIM / 2, DIM / 2, WHITE);
	set(DIM / 2 - 1, DIM / 2 - 1, WHITE);
	set(DIM / 2 - 1, DIM / 2, BLACK);
	set(DIM / 2, DIM / 2 - 1, BLACK);
}

void show_board(void)
{
	int ix, iy;

	for (iy = 0; iy < DIM; iy++)
	{
		for (ix = 0; ix < DIM; ix++)
		{
			char c = '.';
			switch (get(ix, iy))
			{
			case WHITE:
				c = 'O';
				break;
			case BLACK:
				c = 'X';
				break;
			}
			putchar(c);
		}
		putchar(10);
	}
}

int main(int argc, char *argv[])
{
	int ix, iy;
	int turn;

	init();

	turn = 0;
	for (;;)
	{
		show_board();
		do
		{
			printf(": ");
			scanf("%d %d", &ix, &iy);
		}
		while (!is_valid(ix, iy));

		set(ix, iy, turn ? WHITE : BLACK);

		turn = !turn;
	}
	return 0;
}
