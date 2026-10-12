#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

typedef enum TokenType {
	PLUS,
	MINUS,
	TIMES,
	DIVIDE,
	MODULO,
	EXPONENT,
	LPAREN,
	RPAREN,
	NUMBER, 
	Eof,
	INVALID
} TokenType;

typedef struct Token {
	TokenType type;
	const char *lexeme_start;
	size_t lexeme_len;
} Token;

#endif
