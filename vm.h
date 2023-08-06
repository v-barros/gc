/*
 * vm.h
 *
 *  Created on: 2023-08-06
 *      Author: @v-barros
 */
#ifndef VM_H_
#define VM_H_

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

VM * newVM();

int pop(VM *);

int push(VM *, int);

int isEmpty(VM *);

void printMem(VM *);

int peek(VM *);

#endif /*VM_H_*/