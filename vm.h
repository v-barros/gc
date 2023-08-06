/*
 * vm.h
 *
 *  Created on: 2023-08-06
 *      Author: @v-barros
 */
#ifndef VM_H_
#define VM_H_

struct object{
	unsigned char marked;
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

int pop(VM *vm);

int push(VM *vm, int value);

int isEmpty(VM *vm);

void printMem(VM *vm);

int peek(VM *vm);

void markAll(VM* vm);

#endif /*VM_H_*/