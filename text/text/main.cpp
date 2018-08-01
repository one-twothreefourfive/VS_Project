


#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	<stdlib.h>
#include	<iostream>


//#define C_PLUS_PLUS_CHAR_POINTER 1
//#define C_PLUS_PLUS_ALLOCATED_MB_AND_KB_TOTOL 1
//#define C_PLUS_PLUS_NUMBER_ORDER 1
//#define C_PLUS_PLUS_MEMORY_ALIGNMENT 1

void main()
{
	int *p = NULL;
	//*p = 17;	/*内存未对齐，总线错误！*/

#if 0
	if(p != NULL)
	{
		(void)printf("*p == %d \n", *p);
	}
	else
	{
		(void)printf("NULL \n");
	}
#else
	(void)printf("*p == %d \n", p?*p:NULL);
#endif
}

#if C_PLUS_PLUS_MEMORY_ALIGNMENT
union {
	char a[10];
	int i;
}u;

void main()
{
	int *p = (int *)&(u.a[1]);
	*p = 17;	/*内存未对齐，总线错误！*/

	printf("*p == %d \n", *p);
	printf("&(u.a[0]) == %d \n", &(u.a[0]));
	printf("&(u.a[1]) == %d \n", &(u.a[1]));
}
#endif

#if C_PLUS_PLUS_NUMBER_ORDER
#define FILTER_SIZE 10
unsigned long  ulaCAPTURE[2][FILTER_SIZE];
int main()
{
	unsigned char i, j, sm_unit;
	unsigned int temp1 =0,temp2=0;
	unsigned long mean=0,temp;

	sm_unit = 0;

	ulaCAPTURE[0][0] = 5;
	ulaCAPTURE[0][1] = 2;
	ulaCAPTURE[0][2] = 5;
	ulaCAPTURE[0][3] = 10;
	ulaCAPTURE[0][4] = 4;
	ulaCAPTURE[0][5] = 77;
	ulaCAPTURE[0][6] = 1345;
	ulaCAPTURE[0][7] = 13;
	ulaCAPTURE[0][8] = 323;
	ulaCAPTURE[0][9] = 32;

#if 0
	for (i = 0; i < FILTER_SIZE - 1; i++) {						// ‘错误’的冒泡排序求值						
		for (j = i; j < FILTER_SIZE - 1; j++) {
			if (ulaCAPTURE[sm_unit][j] > ulaCAPTURE[sm_unit][j + 1]) {
				temp = ulaCAPTURE[sm_unit][j];
				ulaCAPTURE[sm_unit][j] = ulaCAPTURE[sm_unit][j + 1];
				ulaCAPTURE[sm_unit][j + 1] = temp;
			}
		}
	}
#else
	for (i = 0; i < FILTER_SIZE - 1; i++) {						// ‘正确’的冒泡排序求值						
		for (j = 0; j < (FILTER_SIZE - 1 - i); j++) {
			if (ulaCAPTURE[sm_unit][j] > ulaCAPTURE[sm_unit][j + 1]) {
				temp = ulaCAPTURE[sm_unit][j];
				ulaCAPTURE[sm_unit][j] = ulaCAPTURE[sm_unit][j + 1];
				ulaCAPTURE[sm_unit][j + 1] = temp;
			}
		}
	}
#endif

	printf("buf0 == %d \n", ulaCAPTURE[0][0]);
	printf("buf1 == %d \n", ulaCAPTURE[0][1]);
	printf("buf2 == %d \n", ulaCAPTURE[0][2]);
	printf("buf3 == %d \n", ulaCAPTURE[0][3]);
	printf("buf4 == %d \n", ulaCAPTURE[0][4]);
	printf("buf5 == %d \n", ulaCAPTURE[0][5]);
	printf("buf6 == %d \n", ulaCAPTURE[0][6]);
	printf("buf7 == %d \n", ulaCAPTURE[0][7]);
	printf("buf8 == %d \n", ulaCAPTURE[0][8]);
	printf("buf9 == %d \n", ulaCAPTURE[0][9]);
}
#endif

#if C_PLUS_PLUS_ALLOCATED_MB_AND_KB_TOTOL
int main()
{
#if KB_DEFINE
	int KB=0;
	while(malloc(1 << 10)) ++KB;
	printf("Allocated %d KB totol\n", KB);
#else
	int MB = 0;
	while (malloc(1 << 20)) ++MB;
	printf("Allocated %d MB totol\n", MB);
#endif
	return 0;
}
#endif

#if C_PLUS_PLUS_CHAR_POINTER
#if 1
//using namespace std;
int main()
{
	char x[10] = "tanzheng";
	char *x_pter = x;

	int y[8] = { 2, 4, 6, 8, 10, 12, 14, 16 };
	int *y_pter = y;

	char *str1 = "abcdefdf";
	char *str2 = "abcdefdf";
	char *str3 = "abcdefdfg";

	std::cout << "Value of x variable: ";
	std::cout << x << std::endl;

	std::cout << "Value of &x[0] variable: ";
	std::cout << &x[0] << std::endl;

	std::cout << "Value of (void *)x variable: ";
	std::cout << (void *)x << std::endl;

	std::cout << "Value of &x variable: ";
	std::cout << &x << std::endl;

	std::cout << "Value of (void *)&x[0] variable: ";
	std::cout << (void *)&x[0] << std::endl;

	std::cout << "Value of x_pter variable: ";
	std::cout << x_pter << std::endl;

	std::cout << "Value of (void *)x_pter variable: ";
	std::cout << (void *)x_pter << std::endl;

	std::cout << "Value of &x_pter variable: ";
	std::cout << &x_pter << std::endl;

	std::cout << "Value of y variable: ";
	std::cout << y << std::endl;

	std::cout << "Value of &y variable: ";
	std::cout << &y << std::endl;

	std::cout << "Value of &y[0] variable: ";
	std::cout << &y[0] << std::endl;

	std::cout << "Value of y_pter variable: ";
	std::cout << y_pter << std::endl;

	std::cout << "Value of &y_pter variable: ";
	std::cout << &y_pter << std::endl;

	if ((void *)str1 == (void *)str2)
	{
		std::cout << "(void *)str1 == (void *)str2" << std::endl;
	}
	else
	{
		std::cout << "(void *)str1 != (void *)str2" << std::endl;
	}
	std::cout << "Value of (void *)str1 variable: ";
	std::cout << (void *)str1 << std::endl;
	std::cout << "Value of (void *)str2 variable: ";
	std::cout << (void *)str2 << std::endl;
	std::cout << "Value of (void *)str3 variable: ";
	std::cout << (void *)str3 << std::endl;

	return 0;
}

#else

using namespace std;

int main()
{
	int  var = 20;   // 实际变量的声明
	int  *ip;        // 指针变量的声明

	ip = &var;       // 在指针变量中存储 var 的地址

	cout << "Value of var variable: ";
	cout << var << endl;

	// 输出在指针变量中存储的地址
	cout << "Address stored in ip variable: ";
	cout << ip << endl;

	// 访问指针中地址的值
	cout << "Value of *ip variable: ";
	cout << *ip << endl;

	return 0;
}

#endif
#endif

#if C_PLUS_PLUS_QUOTE

// 引用参数实现交换
void swap(int &d, int &f){
    int temp;
    temp = d;
    d = f;
    f = temp;
}

// Using main to test
void main(){
    void swap(int&, int&);

	int a = 1, b = 2;
	int &m = a, &n = b;
    swap(a,b);
	printf("%d %d\n", a, b);
	printf("%d %d\n", m, n);
}
#endif

#if C_PLUS_PLUS_JUMP

void test8000(void)
{
	int a=1, b=2;
	printf("%d %d\n", a, b);
	printf("%d %d\n", 2, 4);
}

int main()
{
	void (*function)(void);
	function = (void(*)(void))(0x8000);
	function = test8000;
	function();
}
#endif