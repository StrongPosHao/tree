/* stack */
#include "stack.h"

Status initStack(Stack *S){
	S->base=(ElemType *)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if(!S->base) exit(OVERFLOW);
	S->top=S->base;
	S->stacksize=STACK_INIT_SIZE;
	return OK;
}

Status isStackEmpty(Stack *S){
	if(S->base==S->top) return 1;
	else return 0;
}
Status push(Stack *S,BiTNode p){
	if(S->top-S->base==S->stacksize){
		S->base=(BiTree *)realloc(S->base,(S->stacksize+INCREMENT)*sizeof(BiTree));
		if(!S->base) 
			exit(OVERFLOW);
		S->top=S->base+S->stacksize;  
		S->stacksize+=INCREMENT;
	}
	*S->top++=p;
	return OK;
}
BiTNode getTop(Stack *S){
	if(isStackEmpty(S)) exit(ERROR);
	return *(S->top-1);
}
BiTNode pop(Stack *S){
	if(isStackEmpty(S)) 
		exit(ERROR);
	return *--S->top;
}
