#ifndef AST_H
#define AST_H

typedef struct Node Node;

typedef enum NodeType {
	NODE_NUMBER,
	NODE_UNARY,
	NODE_BINARY
} NodeType;

typedef struct BinaryNode {
	char op;
	Node *l;
	Node *r;	
} BinaryOpNode; 

typedef struct UnaryNode {
	char op;
	Node *operand;
} UnaryNode;	

struct Node {
	NodeType type;
	union {
		BinaryOpNode binNode;
		UnaryNode unaryNode;	
		double number;
	};
};

void ast_print_node(const Node *n);

#endif
