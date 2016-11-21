#ifndef H_STACK
#define H_STACK

#include <stdlib.h>
#include <stdio.h>
#include "basic.h"

Status initStack(Stack *S);
Status isStackEmpty(Stack *S);
Status push(Stack *S,ElemType p);
ElemType pop(Stack *S);
ElemType getTop(Stack *S);
Status printStack(Stack *S);
#ifdef DEBUG

#endif
#endif

