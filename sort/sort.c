// sort.c

// sort a million integers

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MIL 1000000
#define DEBUG 0

void print_arr(int *arr, int len)
{
	if (DEBUG) {
		int i ;
		fprintf(stderr,"{ ") ;
		for (i = 0 ; i < len - 1 ; i++ )
		{ 
			fprintf(stderr,"%u, ", arr[i]) ;	
		}
		fprintf(stderr,"%u }\n", arr[i]) ;
	}
	return ;
}

void csort(unsigned *list, unsigned *work, int frnt, int back )
{
	int midl = (frnt + back) / 2, i = frnt , j = frnt, k ;
	k = midl ;
	if (DEBUG) {fprintf(stderr,"frnt=%d, back=%d\n",frnt,back);}
	if ( frnt + 1 == back )
	{
		if ( work[frnt] > work[back] )
		{
			midl = list[frnt] ;
			work[frnt] = work[back] ;
			work[back] = work[frnt] ;
		}
		return ;
	}
	memcpy( work + frnt , list + frnt , sizeof(unsigned) * (back - frnt) ) ;
	csort( work , list , frnt , midl ) ;
	csort( work , list , midl , back ) ;
	while ( j < midl && k < back )
	{
		if (work[j] < work[k])
		{
			list[i++] = work[j++] ;
		} else {
			list[i++] = work[k++] ;
		}
	}
	while ( j < midl )
	{
		list[i++] = work[j++] ;
	}
	while ( k < back )
	{
		list[i++] = work[k++] ;
	}
	return ;
}

int main()
{
	int i = 0 ;
	size_t bsize = 16 ; 
	unsigned list[MIL], work[MIL];
	char *buf = (char *)malloc(bsize*sizeof(char)) ;
	FILE *fp ;
	
	fp = fopen("onem.txt", "r") ;
	for( i = 0; i < MIL ; i++ )
    	{
    		getline(&buf, &bsize, fp) ;
        	list[i] = atoi(buf) ;
        }
	fclose(fp);
	
	csort( list , work , 0 , MIL ) ;
	
	fp = fopen("incm.txt", "w") ;
	for( i = 0; i < MIL ; i++ )
    	{
    		fprintf(fp, "%u\n", list[i]) ;
        }
	fclose(fp) ;
	
	return 0 ;
}
