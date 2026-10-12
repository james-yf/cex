#ifndef TOKEN_H
#define TOKEN_H

#include <stddef.h>

#define TOKEN_TYPE(X) \
    X(PLUS)                \
    X(MINUS)               \
    X(TIMES)               \
    X(DIVIDE)              \
    X(MODULO)              \
    X(EXPONENT)            \
    X(LPAREN)              \
    X(RPAREN)              \
    X(NUMBER)              \
    X(Eof)                 \
    X(INVALID)
	
typedef enum TokenType {
	#define AS_ENUM(token_type) token_type,  
	TOKEN_TYPE(AS_ENUM)	
	#undef AS_ENUM	
} TokenType;

typedef struct Token {
	TokenType type;
	const char *lexeme_start;
	size_t lexeme_len;
} Token;

#endif
