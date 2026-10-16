#ifndef ARENA_H
#define ARENA_H

#include <stddef.h>
#include <stdbool.h>

typedef struct Arena {
	char *start;
	size_t capacity; 
	size_t used;
} Arena;

bool arena_init(Arena *a, size_t capacity);
void *arena_alloc(Arena *a, size_t size);
void arena_reset(Arena *a);
void arena_free(Arena *a);

#endif
