#ifndef LEXER_H
#define LEXER_H

#include <stddef.h>
#include "token.h"

typedef struct Lexer {
	const char *src;
	const char *cursor;
	size_t line;
	size_t col;
} Lexer;

Lexer lexer_init(const char *src);

#endif
