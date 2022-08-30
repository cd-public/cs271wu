# include <stdio.h>
# include <stdlib.h>

// A simple program to sort an array of integers in C

/* YOUR WORK HERE */

// Input: An array of integers and its length
// Output: Zero in the case of no errors
// Side Effect: The input array is sorted from least to greatest
//              This creates the ret array
int *sort(int *arr, int len) 
{
	int i, not_done = 1;
	int *ret = (int *)malloc(10*sizeof(int));
	for (i = 0 ; i < len - 1 ; i++)
	{
		ret[i] = arr[i];
	}
	while (not_done)
	{
		not_done = 0;
		for (i = 0 ; i < len - 1 ; i++)
		{
			not_done += swap(ret, i);
		}
	}
	return ret;
}

/* END YOUR WORK */

/* FEEDBACK FUNCTIONS */

// The special main function
// Creates and maintains the "arr" array
int main()
{
	int loc[10] = {8,6,4,2,0,1,3,5,7,9};
	int *arr = loc;
	arr = sort(arr, 10);
	if (is_sorted(arr, 10))
	{
		printf("Good job!\n");
	} else {
		printf("Keep it up!: %d, %d, %d\n", arr[0], arr[1], arr[2]);
	}
	print_arr(loc, 10);
	print_arr(arr, 10);
	free(arr);
	return 0;
}
