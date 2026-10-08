#include <stdlib.h>
#include "lexer.h"

Lexer lexer_init(const char *src) 
{
	return (Lexer){ .src = src, .cursor = src, .line = 1, .col = 1 };
}

void lexer_free(Lexer *l) {
	if (!l) return;
	free((void *)l->src);
}
