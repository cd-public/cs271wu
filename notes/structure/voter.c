#include "voter.h"

struct voter_struct
{
	char *fname;
	char *lname;
	char *party;
	uint64_t ssn;
	uint64_t zip;
};

// a la __init__ && __new__
voter new_voter()
{
	char *default_value = "DEFAULT_FNAME";
	voter new = (voter)malloc(sizeof(struct voter_struct));
	new->fname = strdup(default_value);
	default_value = "DEFAULT_LNAME";
	new->lname = strdup(default_value);
	default_value = "DEFAULT_PARTY";
	new->party = strdup(default_value);
	new->ssn = 0;
	new->zip = 0;
	return new;
}

// no Python equivalent, because Python is a "garbage collected" language
void free_voter(voter v)
{
	free(v->fname);
	free(v->lname);
	free(v->party);
	free(v);
	return;
}

// a la __str__ 
void print_voter(voter v)
{
	printf("=== PRINTING VOTER STRUCT ===\n");
	printf("Memory Location: %lx\n", (uint64_t)v);
	printf("v->lname: \"%s\"\n", v->lname);
	printf("v->fname: \"%s\"\n", v->fname);
	printf("v->party: \"%s\"\n", v->party);
	printf("v->ssn:   %lu\n", v->ssn);
	printf("v->zip:   %lu\n", v->zip);
	return;
}
