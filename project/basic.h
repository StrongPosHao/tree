#ifndef H_BASIC
#define H_BASIC

#define OK 1
#define ERROR 1
#define TRUE 1
#define OVERFLOW -2
#define INCREMENT 10

typedef char ElemType;
typedef int Status;

/* tree implement*/
#define TREE_DEPTH 10
#define TREE_LEGTH 100

typedef struct BiTNode{
//	enum LTag={0,1};
//	enum RTag={0,1};
	struct BiTNode *lNode;
	struct BiTNode *rNode;
	ElemType data;
}BiTNode,*BiTree;

/* stack implement*/
#define STACK_INIT_SIZE 100
typedef struct {
	ElemType *base;
	ElemType *top;
	int stacksize;
}Stack;

#endif

