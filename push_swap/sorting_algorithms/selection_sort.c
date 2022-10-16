#include <stdio.h>

void
	swap(int *xp, int *yp)
{
	int	tmp;

	tmp = *xp;
	*xp = *yp;
	*yp = tmp;
}

void
	selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min;

	i = -1;
	while (++i < n - 1)
	{
		min = i;
		j = i;
		while (++j < n)
			if (arr[j] < arr[min])
				min = j;
		if (min != i)
			swap(&arr[min], &arr[i]);
	}
}

void
	print_arr(int *arr, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		printf("%d ", arr[i]);
	printf("\n");
}

int
	main(void)
{
	int	arr[5];
	int	n;

	arr[0] = 64;
	arr[1] = 25;
	arr[2] = 12;
	arr[3] = 22;
	arr[4] = 11;
	n = sizeof(arr) / sizeof(arr[0]);
	selection_sort(arr, n);
	printf("\n");
	print_arr(arr, n);
	return (0);
}
