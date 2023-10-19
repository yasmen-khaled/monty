#ifndef MONTY_H
#define MONTY_H



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;


typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

typedef struct bus_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifi;
}  bus_t;
extern bus_t bus;

typedef void (*op_func)(stack_t **, unsigned int);
int execute(char *content, stack_t **stack, unsigned int line_no, FILE *file);
void push(stack_t **stack, unsigned int line_no);
void pall(stack_t **stack, unsigned int line_no);
void pint(stack_t **stack, unsigned int line_no);
void pop(stack_t **stack, unsigned int line_no);
void swap(stack_t **stack, unsigned int line_no);
void add(stack_t **stack, unsigned int line_no);
void nop(stack_t **stack, unsigned int line_no);
void _addnode(stack_t **stack, int n);
void memo(stack_t *stack);
void _queue(stack_t **stack, unsigned int line_no);
void _addqueue(stack_t **stack, int n);
void _starck(stack_t **stack, unsigned int line_no);




#endif
