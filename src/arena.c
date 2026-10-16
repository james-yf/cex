#include <stdbool.h>
#include <stdlib.h>
#include "arena.h"

#define ALIGN 8

bool arena_init(Arena *a, size_t capacity) 
{
	char *buf = malloc(capacity);	
	if (buf == NULL) return false;
	a->start = buf;
	a->capacity = capacity;
	a->used = 0;
	return true; 
}

void *arena_alloc(Arena *a, size_t size)
{
	a->used = (a->used + ALIGN - 1) & ~(size_t)(ALIGN - 1);
	if (a->used + size > a->capacity) return NULL; 
	void *p = a->start + a->used;
	a->used += size;
	return p; 
}

void arena_reset(Arena *a)
{
	a->used = 0;
}

void arena_free(Arena *a)
{
	free(a->start);
}
