# include <stdio.h>

// A simple program to sort an array of integers in C

/* YOUR WORK HERE */

// Input: An array of integers and its length
// Output: Zero in the case of no errors
// Side Effect: The input array is sorted from least to greatest
int sort(int *arr, int len) 
{
	return 0;
}

// Input: An array, and a location i
// Output: Zero in the case no swap, one in the case of swap
// Side Effect: The elements i and i+1 of the array are swapped if 
//              the ith element is greater than the i+1th element
int swap(int *arr, int i)
{
	int temp;
	if (arr[i] > arr[i+1])
	{
		temp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = temp;
		return 1;
	}
	return 0;
}

/* END YOUR WORK */

/* FEEDBACK FUNCTIONS */

// Input: An array of integers and its length
// Output: 1 if the array is sorted least to greatest, 0 otherwise
// Side Effect: None
int is_sorted(int *arr, int len)
{
	int i = 0;
	while (i < (len - 2))
	{
		if (arr[i] > arr[i+1])
		{
			return 0;
		}
		i++;
	}
	return 1;
}

// The special main function
int main()
{
	int arr[10] = {8,6,4,2,0,1,3,5,7,9};
	sort(arr, 10);
	if (is_sorted(arr, 10))
	{
		printf("Good job!\n");
	} else {
		printf("Keep it up!: %d, %d, %d\n", arr[0], arr[1], arr[2]);
	}
	return 0;
}
