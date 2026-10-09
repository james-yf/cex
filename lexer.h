#ifndef LEXER_H
#define LEXER_H

typedef enum TokenType {
	PLUS,
	MINUS,
	TIMES,
	DIVIDE,
	MODULO,
	EXPONENT,
	LPAREN,
	RPAREN,
	NUMBER 
} TokenType;

typedef struct Token {
	TokenType type;
	union {
		double val;
	};
} Token;

typedef struct Lexer {
	const char *src;
	const char *cursor;
	size_t line;
	size_t col;
} Lexer;

Lexer lexer_init(const char *src);
void lexer_free(Lexer *l);

#endif
