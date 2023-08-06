/*
 * vm.h
 *
 *  Created on: 2023-08-06
 *      Author: @v-barros
 */

struct object{
	int value;
	struct object * next;
	struct object * previous;
};
typedef struct object object;

struct VM{
	int size;
	object * head;
	object * tail;
};
typedef struct VM VM;

VM * newStack();

void * pop(VM *);

int push(VM *, void *);

int isEmpty(VM *);

void printMem(VM *);

void * peek(VM *);

