#include "main.h"

/**
 * **alloc_grid - function to allocate memory to grid
 * @width: int type
 * @height: int type
 * Return: grid of 0s
 */
int **alloc_grid(int width, int height)
{
	int **grd;
	int i;
	int j;

	if (width == 0 || height == 0)
		return (NULL);
	grd = malloc(sizeof(int *) * height);

	if (grd == NULL)
		return (NULL);
	for (i = 0; i < height; i++)
	{
		grd[i] = malloc(sizeof(int) * width);

		if (grd[i] == NULL)
		{
			free(grd);
			for (j = 0; j <= height; j++)
				free(grd[j]);
			return (NULL);
		}
		for (j = 0; j < width; j++)
			grd[i][j] = 0;
	}
	return (grd);
}
