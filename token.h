#ifndef TOKEN_H
#define TOKEN_H

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
	double val;
} Token;

#endif
