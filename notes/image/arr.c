#include <stdio.h>

#define SIZE 16

int main()
{
	int arr[SIZE][SIZE][SIZE];
	int *ptr = (int *)arr;
	for ( int i = 0 ; i < SIZE * SIZE * SIZE ; i++ )
	{
		ptr[i] = i;
		
	}
	for ( int i = 0 ; i < SIZE ; i++ )
	{
		for ( int j = 0 ; j < SIZE ; j++ )
		{
			for ( int k = 0 ; k < SIZE ; k++ )
			{
				printf("arr[%x][%x][%x] = %x\n", i, j, k, arr[i][j][k]);
			}
		}
	}
	return 0;
}
