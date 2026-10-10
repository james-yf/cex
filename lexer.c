#include "lexer.h"

Lexer lexer_init(const char *src) 
{
	return (Lexer){ .src = src, .cursor = src, .line = 1, .col = 1 };
}
