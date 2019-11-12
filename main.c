#include <stdio.h>
#include <stdlib.h>
#include "array.h"

int main (int argc, char *argv[])
{
	int i = 0;
//	int j = 0;

//	int ch = 0;
	int width = 0;
	int length = 0;
	int exitGame = 0;

	FILE *fp = fopen(argv[1], "r");

	if (fp == NULL)
	{
		printf("\nError, could not open file\n");
		exit (-1);
	}

	printf("\nSimple game of life\n");
	printf("\nPress any key to continue\n\n");
	getchar();

	fscanf (fp, "%d", &width);
	fscanf (fp, "%d", &length);

	if (width <= 0 || length <= 0)
	{
		printf("\nError, negative array size\n");
		exit (-1);
	}

	int *a = malloc (sizeof(int) * width * length);
	int *b = malloc (sizeof(int) * width * length);

//	printf ("%d %d", width, length);

/*	for (i = 0; i < length; i++)
	{
		printf ("\n");
		for (j = 0; j < width; j++)
		{
			fscanf (fp, "%d", &ch);
			printf (" %d", ch);
		}
	}*/

	for (i = 0; i < length * width; i++)
	{
		fscanf (fp, "%d", &a[i]);
		b[i] = a[i];
	}

//	printf ("%d %d\n", width, length);
//	printArray (width, length, b);

	while (exitGame != 115)
	{
		printf("\e[1;1H\e[2J");
		printArray (width, length, b);
		b = play (width, length, a, b);
		for (i = 0; i < length * width; i++)
		{
			a[i] = b[i];
		}
		printf("\nPress enter to continue, enter s to end the program \n");
		exitGame = getchar();
	}

	free (a);
	free (b);
	fclose (fp);

	return 0;
}
