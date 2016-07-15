#include <iostream>
#include <string>

char stack[25];
int top = -1;

void push(char item)
{
	stack[++top] = item;
}

char pop()
{
	return stack[top--];
}

//returns precedence of operators
int precedence(char symbol)
{
	switch (symbol)
	{
	case '+':
	case '-':
		return 2;
		break;
	case '*':
	case '/':
		return 3;
		break;
	case '^':
		return 4;
		break;
	case '(':
	case ')':
	case '#':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}

//check whether the symbol is operator?
int isOperator(char symbol)
{
	switch (symbol)
	{
	case '+':
	case '-':
	case '*':
	case '/':
	case '^':
	case '(':
	case ')':
		return 1;
		break;
	default:
		return 0;
		break;
	}
}

//converts infix expression to postfix
