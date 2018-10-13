/*
* =====================================================================================
*
*       Filename:  cdecl.c
*
*    Description:  Expert C example program
*
*        Version:  1.0
*        Created:  
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  
*        Company:  
*
* =====================================================================================
*/
#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	<stdlib.h>

#define C_PLUS_PLUS_FSM_CDECL_PROGRAM 0

#if C_PLUS_PLUS_FSM_CDECL_PROGRAM
void main()
{
	;
}
#else
#pragma warning (disable:4996)				/* ����4996�еı�����󣬻ᱨstrcpyΪ����ȫ���� */

#define	 MAXTOKENS 100			/*  */
#define	MAXTOKENLEN 64			/*  */

enum type_tag{ IDENTIFIER, QUALIFIER, TYPE };
struct token{
	char type;
	char string[MAXTOKENLEN];
};
int top = -1;
struct token stack[MAXTOKENS];
struct token thisis;				/* this����ⶨ���ͻ���ʸ���thisis */ 

#define	pop stack[top--]			/*  */
#define	push(s) stack[++top]=s			/*  */

enum type_tag classify_string(void)/*�ƶϱ�ʶ��������*/
{
	char *s = thisis.string;
	if (!strcmp(s, "const"))
	{
		strcpy(s, "read-only");
		return QUALIFIER;
	}
	if (!strcmp(s, "volatile")) return QUALIFIER;
	if (!strcmp(s, "void")) return TYPE;
	if (!strcmp(s, "char")) return TYPE;
	if (!strcmp(s, "signed")) return TYPE;
	if (!strcmp(s, "unsigned")) return TYPE;
	if (!strcmp(s, "short")) return TYPE;
	if (!strcmp(s, "int")) return TYPE;
	if (!strcmp(s, "long")) return TYPE;
	if (!strcmp(s, "float")) return TYPE;
	if (!strcmp(s, "double")) return TYPE;
	if (!strcmp(s, "struct")) return TYPE;
	if (!strcmp(s, "union")) return TYPE;
	if (!strcmp(s, "enum")) return TYPE;
	return IDENTIFIER;
}
void gettoken(void)/*��ȡ��һ����ǵ� thisis*/
{
	char *p = thisis.string;
	/*�Թ��հ��ַ�*/
	while ((*p = getchar()) == ' ');

	if (isalnum(*p))
	{
		/*����ı�ʶ����A��Z��0-9��ͷ*/
		while (isalnum(*++p = getchar()));
		ungetc(*p, stdin);
		*p = '\0';
		thisis.type = classify_string();
		return;
	}
	if (*p == '*')
	{
		strcpy(thisis.string, "pointer to");
		thisis.type = '*';
		return;
	}
	thisis.string[1] = '\0';
	thisis.type = *p;
	return;
}
void read_to_first_identifier()
{
	gettoken();
	while (thisis.type != IDENTIFIER)
	{
		push(thisis);
		gettoken();
	}
	printf("%s is ", thisis.string);
	gettoken();
}
void deal_with_arrays()
{
	while (thisis.type == '[')
	{
		printf("array ");
		gettoken();/*���ֻ�']'*/
		if (isdigit(thisis.string[0]))
		{
			int temp;
			sscanf(thisis.string, "%d", &temp);
			printf("0..%d ", temp - 1);
			gettoken();/*��ȡ']'*/
		}
		gettoken();/*��ȡ']'֮�����һ�����*/
		printf("of ");
	}
}
void deal_with_function_args(){
	/*����������*/
	while (thisis.type != ')')
	{
		gettoken();
	}
	gettoken();
	printf("function returning ");
}
void deal_with_pointers(){
	while (stack[top].type == '*')
	{
		printf("%s ", pop.string);
	}
}
void deal_with_declarator()
{
	/*�����ʶ��֮����ܴ��ڵ�����/����*/
	switch (thisis.type)
	{
	case '[':
		deal_with_arrays();
		break;
	case '(':
		deal_with_function_args();
		break;
	}
	deal_with_pointers();
	/*�����ڶ��뵽��ʶ��֮ǰѹ�뵽��ջ�ķ���*/
	while (top >= 0)
	{
		if (stack[top].type == '('){
			pop;
			gettoken();/*��ȡ')'֮��ķ���*/
			deal_with_declarator();
		}
		else
		{
			printf("%s ", pop.string);
		}
	}
}

int main()
{
	/*�����ѽ���ջ�У�ֱ��������ʶ��*/
	read_to_first_identifier();
	deal_with_declarator();
	printf("\n");
	return 0;
}
#endif