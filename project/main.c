#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

int main() {
	BiTree T;
	createBiTree(T);
	inOrderTraverse(T);
	return 0;
}
