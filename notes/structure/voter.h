#include <stdio.h>
#include <stdint.h> // so we can use the uint64_t type
#include <stdlib.h>
#include <string.h>

typedef struct voter_struct *voter;

// a la __init__ && __new__
voter new_voter();

// no Python equivalent, because Python is a "garbage collected" language
void free_voter(voter v);

// a la __str__ 
void print_voter(voter v);
