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

Status push(Stack *S,ElemType p){
	if(S->top-S->base==S->stacksize){
		S->base=(ElemType *)realloc(S->base,(S->stacksize+INCREMENT)*sizeof(ElemType));
		if(!S->base) 
			exit(OVERFLOW);
		S->top=S->base+S->stacksize;  
		S->stacksize+=INCREMENT;
	}
	*S->top++=p;
	return OK;
}

ElemType getTop(Stack *S){
	if(isStackEmpty(S)) exit(ERROR);
	return *(S->top-1);
}

ElemType pop(Stack *S){
	if(isStackEmpty(S)) 
		exit(ERROR);
	return *--S->top;
}

#ifdef DEBUG
Status printStack(Stack *S){
	if(S->base==S->top)
		return ERROR;
	ElemType *p;
	for(p=S->top-1;p>=S->base;p--)
		printf("%p\n",*p);
	printf("\n");
	return OK;
} 
#endif
