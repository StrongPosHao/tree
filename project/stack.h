#ifndef H_STACK
#define H_STACK

#include <stdlib.h>
#include "basic.h"

Status initStack(Stack *S);
Status isStackEmpty(Stack *s);
Status push(Stack *S,BiTNode p);
BiTNode pop(Stack *S);
BiTNode getTop(Stack *S);

#endif

