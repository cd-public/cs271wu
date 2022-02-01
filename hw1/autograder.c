// autograder.c

// tests plist.c functionality

#include "plist.h"

int main()
{
	plist l = pl_new();
	
	// Test new and print
	
	printf("\nInitial Test\n");
	printf("Make new and print plist should print:\n");
	printf("[]\n");
	printf("Does print:\n");
	pl_print(l);
	
	// Test free
	
	pl_free(l);
	printf("Free ran without error.\n");
	
	// Test append
	
	printf("\n0. Append (10 pts)\n");
	printf("Append 2 to [1] and 4 to [3], should print:\n");
	printf("[1, 2]\n");
	printf("[3, 4]\n");
	printf("Does print:\n");
	l = pl_new();
	pl_append(l,(void *)1);
	pl_append(l,(void *)2);
	plist l2 = pl_new();
	pl_append(l2,(void *)3);
	pl_append(l2,(void *)4);
	pl_print(l);
	pl_print(l2);
	
	// Test extend
	
	printf("\n1. Extend (10 pts)\n");
	printf("Extend [1, 2] with [3, 4], should print:\n");
	printf("[1, 2, 3, 4]\n");
	printf("Does print:\n");
	pl_extend(l,l2);
	pl_print(l);
	
	// Test insert
	
	printf("\n2. Insert (10 pts)\n");
	printf("Insert 5 into plist at position 2, should print:\n");
	printf("[1, 2, 5, 3, 4]\n");
	printf("Does print:\n");
	pl_insert(l,2,(void *)5);
	pl_print(l);
	
	// Test remove
	
	printf("\n3. Remove (10 pts)\n");
	printf("Remove 5 from plist, should print:\n");
	printf("[1, 2, 3, 4]\n");
	printf("Does print:\n");
	pl_remove(l,(void *)5);
	pl_print(l);
	
	// Test pop
	
	printf("\n4. Pop (10 pts)\n");
	printf("Pop 1th element from plist, should print:\n");
	printf("[1, 3, 4]\n");
	printf("Does print:\n");
	pl_pop(l,1);
	pl_print(l);
	
	// Test pop
	
	printf("\n5. Clear (10 pts)\n");
	printf("Clearing list, should print:\n");
	printf("[]\n");
	printf("Does print:\n");
	pl_clear(l);
	pl_print(l);
	
	// Test index
	
	printf("\n6. Index (10 pts)\n");
	printf("Index of 3 in [1,1,3,1,3] should be:\n");
	printf("2\n");
	printf("Is found to be:\n");
	pl_append(l,(void *)1);
	pl_append(l,(void *)1);
	pl_append(l,(void *)3);
	pl_append(l,(void *)1);
	pl_append(l,(void *)3);
	printf("%lu\n",pl_index(l, (void *)3));
	
	// Test count
	
	printf("\n7. Count (10 pts)\n");
	printf("Count of 1 in [1,1,3,1,3] should be:\n");
	printf("3\n");
	printf("Is found to be:\n");
	printf("%lu\n",pl_count(l, (void *)1));
	
	// Test reverse
	
	printf("\n8. Reverse (10 pts)\n");
	printf("Reversing [1,1,3,1,3] should be:\n");
	printf("[3, 1, 3, 1, 1]\n");
	printf("Is found to be:\n");
	pl_reverse(l);
	pl_print(l);
	
	// Test copy
	
	printf("\n9. Copy (10 pts)\n");
	printf("Copying [3,1,3,1,1] then clearing, copy should be:\n");
	printf("[3, 1, 3, 1, 1]\n");
	printf("Is found to be:\n");
	l2 = pl_copy(l);
	pl_clear(l);
	pl_print(l2);
		
	return 0;
}
