// plist.c

// implements functions in plist.h

#include "plist.h"

struct plist_struct
{
	void *data;
	plist next;
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

void pl_insert(plist l, uint64_t i, void *x)
{
	return;
}

bool pl_remove(plist l, void *x)
{
	return FALSE;
}

void *pl_pop(plist l, uint64_t i)
{
	return NULL;
}

void pl_clear(plist l)
{
	return;
}

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
