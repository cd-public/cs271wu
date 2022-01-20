// plist.c

// implements functions in plist.h

#include "plist.h"

struct plist_struct
{
	uint64_t len;
	uint64_t size;
	void **eles;
};

plist pl_new()
{
	return NULL;
}

void pl_free(plist l)
{
	return;
}

void pl_print(plist l)
{
	return;
}

void pl_append(plist l, void *x)
{
	return;
}

void pl_extend(plist l1, plist l2)
{
	return;
}

// 2: Insert
// inputs: a plist l, uint64_t list index i, and a pointer to an memory object of any type x
// outputs: nothing
// side effects: x is added to l with index i and all elements are preserved in l
// example:
// plist l = new_plist();
// uint64_t *val = 1;
// append(l, val);
// *val = 2;
// insert(l, 0, val);
// print_plist(l);
// - should pruint64_t "[2, 1]"
void pl_insert(plist l, uint64_t i, void *x)
{
	return;
}

// 3: Remove
// inputs: a plist l, and a pointer to an memory object of any type x
// outputs: TRUE if an instance of x is removed, FALSE otherwise
// side effects: the first instance of x is removed from l
// example:
// plist l = new_plist();
// uint64_t *val = 2;
// append(l, val);
// append(l, val);
// *val = 1;
// print_plist(l1);
// remove(l, 1, val);
// print_plist(l);
// - should return True
// - should pruint64_t "[2, 1, 2]" then "[1, 2]"
bool pl_remove(plist l, void *x)
{
	return FALSE;
}

// 4: Pop
// inputs: a plist l, and a uint64_t list index i
// outputs: The element at index i, or exit(1) if i is out of range
// side effects: remove the element at index i
// example:
// plist l = new_plist();
// uint64_t *val = 1;
// append(l, val);
// *val = 2;
// insert(l, 0, val);
// print_plist(l);
// printf("%d\n", pop(l, 1));
// print_plist(l);
// - should pruint64_t "[1, 2]" then "2" then "[1]"
void *pl_pop(plist l, uint64_t i)
{
	return NULL;
}

// 5: Clear
// inputs: a plist l
// outputs: nothing
// side effects: l contains no elements
// example:
// plist l = new_plist();
// uint64_t *val = 1;
// append(l, val);
// clear(l)
// - should pruint64_t "[]"
void pl_clear(plist l)
{
	return;
}

// 6: Index
// inputs: a plist l, and a pointer to an memory object of any type x
// outputs: a uint64_t i giving the index of x in l, or exit(1) if i is out of range
// side effects: none
// example:
// plist l = new_plist();
// uint64_t *val = 1;
// append(l, val);
// printf("%d\n", index(l, val)));
// - should pruint64_t "0"
uint64_t pl_index(plist l, void *x)
{
	return -1;
}

uint64_t pl_count(plist l, void *x)
{
	return 0;
}

void pl_reverse(plist l)
{
	return;
}

plist pl_copy(plist l)
{
	return NULL;
}
