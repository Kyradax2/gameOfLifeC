#include "array.h"

void printArray (int w, int l, int *a)
{
	int i = 0;
	int j = 0;

	for (i = 0; i < l; i++)
	{
		printf("\n");
		for (j = 0; j < w; j++)
		{
			if (a[j + (w * i)] == 1)
			{
				printf("\033[0;31m");
				printf("%d", a[j + (w * i)]);
				printf("\033[0m");
			}
			else
			{
				printf("%d", a[j + (w * i)]);
			}
		}
	}

/*	for (i = 0; i < w * l; i++)
	{
		printf ("%d", a[i]);
	}*/
}

int* play (int w, int l, int *a, int *b)
{
	int i = 0;

//	int j = 0;
//	int k = 0;

	int livingCells = 0;

	for (i = 0; i < w * l; i++)
	{
/*		if (a[i] == 1) livingCells = -1;
	       	else livingCells = 0;*/

		livingCells = 0;

/*		for (j = i - 1; j <= i + 1; j++)
		{
			for (k = -1; k <= 1; k++)
			{
				if (((j + w * k) >= 0) && ((j + w * k) < w * l))
				{
					if (a[j + w * k] == 1)
						livingCells++;
				}
			}
		}*/

		if (!(i % w == 0))
		{
			if (a[i-1] == 1) livingCells++;
		}
		if (!(i % w == w - 1))
		{
			if (a[i+1] == 1) livingCells++;
		}
		if ((i - w) >= 0)
		{
			if (a[i-w] == 1) livingCells++;
		}
		if ((i + w) < w * l)
		{
			if (a[i+w] == 1) livingCells++;
		}
		if ((!(i % w == 0)) && ((i - w) >= 0))
		{
			if (a[i-1-w] == 1) livingCells++;
		}
		if ((!(i % w == 0)) && ((i + w) < w * l))
		{
			if (a[i-1+w] == 1) livingCells++;
		}
		if ((!(i % w == w - 1)) && ((i - w) >= 0))
		{
			if (a[i+1-w] == 1) livingCells++;
		}
		if ((!(i % w == w - 1)) && ((i + w) < w * l))
		{
			if (a[i+1+w] == 1) livingCells++;
		}

		if ((a[i] == 1) && (livingCells < 2)) b[i] = 0;
		else if ((a[i] == 1) && ((livingCells >= 2) && (livingCells <=3))) b[i] = 1;
		else if ((a[i] == 1) && (livingCells > 3)) b[i] = 0;
		else if ((a[i] == 0) && (livingCells == 3)) b[i] = 1;
		else b[i] = 0;
	}

	return b;
}
