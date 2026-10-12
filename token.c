#include <stdio.h>
#include "token.h"

void print_token(Token t) 
{
	printf("TYPE: <%s> | VALUE: <%.*s>\n", token_type_to_string(t.type), (int)t.lexeme_len, t.lexeme_start); 
}

const char *token_type_to_string(TokenType tt) 
{
	switch (tt) {
		#define AS_SWITCH(token_type) case token_type: return #token_type; 
		TOKEN_TYPE(AS_SWITCH)
		#undef AS_SWITCH
		default: return "UNKNOWN";
	}	
}
