#ifndef H_STACK
#define H_STACK

#include <stdlib.h>
#include "basic.h"

Status initStack(Stack *S);
Status isStackEmpty(Stack *s);
Status push(Stack *S,BiTree p);
BiTree pop(Stack *S);
BiTree getTop(Stack *S);

#endif

