#include <stdio.h>

void
	swap(int *x, int *y)
{
	int	tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
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

void
	selection_sort(int *arr, int n)
{
	int	i;
	int	j;
	int	min;

	i = -1;
	while (++i < n - 1)
	{
		printf("Comparing %d against the elements after it...\n", arr[i]);
		min = i;
		j = i;
		while (++j < n)
		{
			printf("Is %d smaller than %d? ", arr[min], arr[j]);
			if (arr[min] > arr[j])
			{
				min = j;
				printf("No, the smallest element is now %d.\n", arr[min]);
			}
			else
				printf("Yes, %d is still the smallest.\n", arr[min]);
		}
		if (min != i)
		{
			printf("Swap %d with %d.\n", arr[min], arr[i]);
			swap(&arr[min], &arr[i]);
			printf("\nThe array now looks like this:\n");
			print_arr(arr, n);
			printf("\n");
		}
	}
}

int
	main(void)
{
	int	e;
	int	n;
	int	arr[100];
	int	i;

	printf("How many elements would you like to enter?\n");
	if (scanf("%d", &e) != 1)
	{
		fprintf(stderr, "Bad data entry. Exiting...\n");
		return (1);
	}
	n = (int)e;
	i = 1;
	while (i <= n)
	{
		printf("Enter an integer for the element %d of %d:\n", i, n);
		if (scanf("%d", &arr[i - 1]) != 1)
		{
			fprintf(stderr, "Bad data entry. Exiting...\n");
			return (1);
		}
		i++;
	}
	printf("The original array is:\n");
	print_arr(arr, n);
	printf("\n");
	printf("Starting selection sort...\n");
	printf("Assume the first element of the array is the smallest.\n");
	selection_sort(arr, n);
	printf("The sorted array looks like this:\n");
	print_arr(arr, n);
	return (0);
}
