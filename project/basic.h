#define OK 1
#define TRUE 1
#define INFEASIBLE -2
#define ERROR -1

typedef int Status;
typedef struct BiTNode{
	ElemType data;
	struct BiTNode *lchild,*rchild;
}BiTNode,*BiTree;

