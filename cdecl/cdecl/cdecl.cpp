/*
* =====================================================================================
*
*       Filename:  cdecl.c
*
*    Description:
*
*        Version:  1.0
*        Created:  2012��02��28�� 21ʱ54��11��
*       Revision:  none
*       Compiler:  gcc
*
*         Author:  MaZheng (blog.csdn.net/mazheng1989), mazheng19891019@gmail.com
*        Company:  Dalian University Of Technology
*
* =====================================================================================
*/


#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	<stdlib.h>

#define	 MAXTOKENS 100			/*  */
#define	MAXTOKENLEN 64			/*  */

enum type_tag{ IDENTIFIER, QUALIFIER, TYPE };
struct token{
	char type;
	char string[MAXTOKENLEN];
};
int top = -1;
struct token stack[MAXTOKENS];

namespace tan{ 
	struct token this;
}


#define	pop stack[top--]			/*  */
#define	push(s) stack[++top]=s			/*  */

using tan::this;

#if 0
enum type_tag classify_string(void)/*�ƶϱ�ʶ��������*/
{
	char *s = this.string;
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
void gettoken(void)/*��ȡ��һ����ǵ� this*/
{
	char *p = this.string;
	/*�Թ��հ��ַ�*/
	while ((*p = getchar()) == ' ');

	if (isalnum(*p))
	{
		/*����ı�ʶ����A��Z��0-9��ͷ*/
		while (isalnum(*++p = getchar()));
		ungetc(*p, stdin);
		*p = '\0';
		this.type = classify_string();
		return;
	}
	if (*p == '*')
	{
		strcpy(this.string, "pointer to");
		this.type = '*';
		return;
	}
	this.string[1] = '\0';
	this.type = *p;
	return;
}
void read_to_first_identifier()
{
	gettoken();
	while (this.type != IDENTIFIER)
	{
		push(this);
		gettoken();
	}
	printf("%s is ", this.string);
	gettoken();
}
void deal_with_arrays()
{
	while (this.type == '[')
	{
		printf("array ");
		gettoken();/*���ֻ�']'*/
		if (isdigit(this.string[0]))
		{
			int temp;
			sscanf(this.string, "%d", &temp);
			printf("0..%d ", temp - 1);
			gettoken();/*��ȡ']'*/
		}
		gettoken();/*��ȡ']'֮�����һ�����*/
		printf("of ");
	}
}
void deal_with_function_args(){
	/*����������*/
	while (this.type != ')')
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
	switch (this.type)
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
#endif
int main()
{
	/*�����ѽ���ջ�У�ֱ��������ʶ��*/
	//read_to_first_identifier();
	//deal_with_declarator();
	printf("\n");
	return 0;
}