#include <stdio.h>
#include "ast.h"

void ast_print_node(const Node *n)
{
	if (!n) { 
		printf("<NULL NODE>"); 
		return; 
	}

	switch (n->type) {
		case NODE_NUMBER:
			printf("%g", n->number);	
			break;
		case NODE_UNARY:
			printf("(");
			printf("%c", n->unaryNode.op);
			printf(" ");
			ast_print_node(n->unaryNode.operand);
			printf(")");
			break;
		case NODE_BINARY:
			printf("(");
			printf("%c", n->binNode.op);
			printf(" ");
			ast_print_node(n->binNode.l);
			printf(" ");
			ast_print_node(n->binNode.r);
			printf(")");
			break;
		default:
			printf("<UNKNOWN NODE>");
			break;
	}
}
