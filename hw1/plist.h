// plist.h

// declares functions in plist.c

// This prevents double-inclusions
#ifndef PLIST
#define PLIST

// Some useful librarys

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

// Implement booleans

#define TRUE 1
#define FALSE 0
typedef uint64_t bool;

// Notes:

// List elements are of type void *
// List indices are of type uint64_t
// Success/failure returns are of type bool
// None returns are of type void

typedef struct plist_struct *plist;

// *: New (a la Python __init__)
// inputs: none
// outputs: a new plist containing no values
// side effects: none
plist pl_new();

// *: Free (no Python equivalent)
// inputs: a plist l
// outputs: nothing
// side effects: frees all memory associated with l
void pl_free(plist l);

// *: Print (a la Python __str__)
// inputs: a plist l
// outputs: nothing
// side effects: the elements of l are printed as in python
// example:  
// pl_print(pl_new());
// - should print "[]"
// Note: Prints void *'s as uint64_t's. (use %lu)
void pl_print(plist l);

// 0: Append
// inputs: a plist l, a pointer to an memory object of any type x
// outputs: nothing
// side effects: x is added to the end of l
// example:
// plist l = pl_new();
// uint64_t *val = 1;
// pl_append(l, val);
// pl_print(l);
// - should print "[1]"
void pl_append(plist l, void *x);

// 1: Extend
// inputs: two plists, l1 and l2
// outputs: nothing
// side effects: all elements of l2 are appended to l1
// example:
// plist l1 = pl_new();
// uint64_t *val = 1;
// pl_append(l1, val);
// plist l2 = pl_new();
// *val = 2;
// pl_append(l2, val);
// pl_print(l1);
// - should print "[1, 2]"
void pl_extend(plist l1, plist l2);

// 2: Insert
// inputs: a plist l, uint64_t list index i, and a pointer to an memory object of any type x
// outputs: nothing
// side effects: x is added to l with index i and all elements are preserved in l
// example:
// plist l = pl_new();
// uint64_t *val = 1;
// pl_append(l, val);
// *val = 2;
// pl_insert(l, 0, val);
// pl_print(l);
// - should print "[2, 1]"
void pl_insert(plist l, uint64_t i, void *x);

// 3: Remove
// inputs: a plist l, and a pointer to an memory object of any type x
// outputs: TRUE if an instance of x is removed, FALSE otherwise
// side effects: the first instance of x is removed from l
// example:
// plist l = pl_new();
// uint64_t *val = 2;
// pl_append(l, val);
// pl_append(l, val);
// *val = 1;
// pl_print(l1);
// pl_remove(l, 1, val);
// pl_print(l);
// - should return True
// - should print "[2, 1, 2]" then "[1, 2]"
bool pl_remove(plist l, void *x);

// 4: Pop
// inputs: a plist l, and a uint64_t list index i
// outputs: The element at index i, or exit(1) if i is out of range
// side effects: remove the element at index i
// example:
// plist l = pl_new();
// uint64_t *val = 1;
// pl_append(l, val);
// *val = 2;
// pl_insert(l, 0, val);
// pl_print(l);
// printf("%d\n", pop(l, 1));
// pl_print(l);
// - should print "[1, 2]" then "2" then "[1]"
void *pl_pop(plist l, uint64_t i);

// 5: Clear
// inputs: a plist l
// outputs: nothing
// side effects: l contains no elements
// example:
// plist l = pl_new();
// uint64_t *val = 1;
// pl_append(l, val);
// clear(l)
// - should print "[]"
void pl_clear(plist l);

// 6: Index
// inputs: a plist l, and a pointer to an memory object of any type x
// outputs: a uint64_t i giving the index of x in l, or exit(1) if i is out of range
// side effects: none
// example:
// plist l = pl_new();
// uint64_t *val = 1;
// pl_append(l, val);
// printf("%d\n", index(l, val)));
// - should print "0"
uint64_t pl_index(plist l, void *x);

// 7: Count
// inputs: a plist l, and a pointer to an memory object of any type x
// outputs: The number of times x occurs in l
// side effects: none
// example:
// plist l = pl_new();
// uint64_t *val = 1;
// pl_append(l, val);
// pl_append(l, val);
// pl_count(l, val);
// - should return 2
uint64_t pl_count(plist l, void *x);

// ~: Sort
// Extra credit for an O(n*log(n)) sort
// 10 points if it works on the x_sort input but I can break it
// 20 points if I can't break it and it is documented.
// 05 points for an O(n^2) implementation that isn't Bubble Sort
// void sort(plist l)

// 8: Reverse
// inputs: a plist l
// outputs: nothing
// side effects: the elements of l are reversed
// example:
// plist l = pl_new();
// uint64_t *val = 1;
// pl_append(l, val);
// *val = 2;
// pl_append(l, val);
// pl_print(l);
// pl_reverse(l)
// pl_print(l);
// - should print "[1, 2]" then "[2, 1]"
void pl_reverse(plist l);

// 9: Copy
// inputs: a plist l
// outputs: a plist r containing all the elements of l
// side effects: none
// example:
// plist l = pl_new();
// uint64_t *val = 1;
// pl_append(l, val);
// plist r = copy(l);
// pl_append(l, val);
// pl_print(l);
// pl_print(r);
// - should print "[1, 1]" then "[1]"
plist pl_copy(plist l);

#endif
