#include <ctype.h>
#include "lexer.h"
#include "token.h"

static void lexer_advance(Lexer *l); 

Lexer lexer_init(const char *src) 
{
	return (Lexer){ .src = src, .cursor = src, .line = 1, .col = 1 };
}

Token lexer_get_next_token(Lexer *l)
{
	Token t;

	while (isspace((unsigned char)*l->cursor)) {
		lexer_advance(l);
	}

	const char start_c = *l->cursor;

	if (start_c == '\0') { 
		t.type = Eof; 
		t.lexeme_start = l->cursor;
		t.lexeme_len = 0; 
		return t; 
	}

	if (isdigit((unsigned char)start_c) || (start_c == '.')) {
		const char *num_str_start = l->cursor;
		while (isdigit((unsigned char)*l->cursor) || *l->cursor == '.') {
			lexer_advance(l);
		}

		t.lexeme_start = num_str_start;
		t.lexeme_len = l->cursor - t.lexeme_start;

		t.type = NUMBER;
		return t;
	} 
	
	switch (start_c) {
		case '+': t.type = PLUS;     break;
		case '-': t.type = MINUS;    break;
		case '*': t.type = TIMES;    break;
		case '/': t.type = DIVIDE;   break;
		case '%': t.type = MODULO;   break;
		case '^': t.type = EXPONENT; break;
		case '(': t.type = LPAREN;   break;
		case ')': t.type = RPAREN;   break;
		default:  t.type = INVALID;  break;
	}

	t.lexeme_start = l->cursor;
	t.lexeme_len = 1;
	lexer_advance(l);

	return t;
}

static void lexer_advance(Lexer *l) 
{
	if (*l->cursor == '\n') {
		l->line++;
		l->col = 1;
	} else {
		l->col++;
	}
	l->cursor++;
}

