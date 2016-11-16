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
Status push(Stack *S,BiTree p){
	if(S->top-S->base==S->stacksize){
		S->base=(BiTree *)realloc(S->base,(STACK_INIT_SIZE+INCREMENT)*sizeof(BiTree));
		if(!S->base) 
			exit(OVERFLOW);
		S->top=S->base+S->stacksize;  
		S->stacksize+=INCREMENT;
	}
	*S->top++=p;
	return OK;
}
BiTree getTop(Stack *S){
	BiTree e;
	if(isStackEmpty(S)) exit(ERROR);
		e=*--S->top;
		S->top++;
	return e;
}
BiTree pop(Stack *S){
	if(isStackEmpty(S)) 
		exit(ERROR);
	return *--S->top;
}
