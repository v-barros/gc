/*
 * vm.h
 *
 *  Created on: 2023-08-06
 *      Author: @v-barros
 */
#include <stdlib.h>
#include <stdio.h>
#include "vm.h"

 void mark(object*obj){
    obj->marked=1;
 }

object * newObject(int n){
	object * newobj = (object*) malloc(sizeof(object));

	if(newobj!=NULL){
		newobj->value=n;
        newobj->marked=0;
		newobj->next=NULL;
		newobj->previous=NULL;
	}
	return newobj;
}

void markAll(VM* vm)
{
    object * aux=vm->head;
     while(aux!=NULL){
        mark(aux);
		aux = aux->next;
     }
}

VM * newVM(){
    VM * p = (VM *) malloc (sizeof(VM));

	if(p!=NULL){
		p->size=0;
		p->head=NULL;
		p->tail=NULL;
	}

	return p;
}

int pop(VM * VM){
	if(isEmpty(VM))
		return 0;

	object * tailobj = VM->head;
	int n = VM->head->value;

	if(VM->head->next!=NULL){
		VM->head->next->previous=NULL;
		VM->head = VM->head->next;
	}else{//only 1 element
		VM->head=NULL;
		VM->tail=NULL;
	}

	VM->size--;
	free(tailobj);
	return n;
}

int push(VM * VM, int valueToPush){
	object * newtailobj = newObject(valueToPush);
	if(newtailobj==NULL){
		return 0;
	}

	if(isEmpty(VM)){
		VM->head=newtailobj;
		VM->tail=newtailobj;
	}else{
		VM->head->previous=newtailobj;
		newtailobj->next=VM->head;
		VM->head=newtailobj;
	}
	VM->size++;
	return 1;

}

int isEmpty(VM * VM){
	return VM->head==NULL;
}

void printMem(VM * VM){
	if(isEmpty(VM)){
		printf("\nList is empty!\n");
		return;
	}
	int i = 0;
	object * tailobj = VM->tail;
	
	printf("\nList:\nSize:[%d] Head:[%d]\n",VM->size,(VM->head->value));

	while(tailobj!=NULL){
		printf("%03d ",tailobj->value);
		if(i%10==9)
			printf("\n");
		tailobj = tailobj->previous;
		i++;
	}
		printf("\n");
}

int peek(VM * VM){
	if(isEmpty(VM))
				return 0;
	return VM->head->value;
}
