
#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	<stdlib.h>
#include	<iostream>
#include	<signal.h>
#include	<conio.h>

//#define C_PLUS_PLUS_JUMP
//#define C_PLUS_PLUS_QUOTE
//#define C_PLUS_PLUS_CHAR_POINTER 1
//#define C_PLUS_PLUS_ALLOCATED_MB_AND_KB_TOTOL 1
//#define C_PLUS_PLUS_NUMBER_ORDER 1
//#define C_PLUS_PLUS_MEMORY_ALIGNMENT 1
//#define C_PLUS_PLUS_MEMORY_ALIGNMENT2 1
//#define C_PLUS_PLUS_SECTION_ERROR_DEAL 1
//#define C_PLUS_PLUS_BIT_MAP_DISPLAY 1
//#define C_PLUS_PLUS_GETCHAR_GETCH_GETCHE_COMMAND 1
//#define C_PLUS_PLUS_UNIX_SINGLE_CHAR_INPUT 1
#define C_PLUS_PLUS_RES_AD_SAMPLE 1


#if C_PLUS_PLUS_RES_AD_SAMPLE
/*
 *部分数据的提前声明：
 *1.定义FUEL_IN口的电压为sensor_voltage;
 *2.FUEL_V口的电压为base_voltage;
 *3.FUEL口到负载接地之间的电压为voltage;
 *4.FUEL口到负载接地之间的电流为current;
 *5.FUEL口到负载接地之间的电阻为res;
 *6.单片机的基准电压 = 5V，AD精度为12位 = 4096；
 */
#define TEMP_GATHER_TIME_5MS 40
#define BIT12_ADC_VALUE 4096
#define FUEL_R_182  182
#define FUEL_R_100K 100
#define FUEL_R_10K  10
#define AD_EXPAND_MULTIPLE  10
typedef unsigned long dword;
typedef signed long dsword;

void main()
{
#if 0/* 方案一：整合算法后，计算得出外接电阻值(结果是扩大10倍的整形数据) */
	dword  temp;
	dword  fuel_voltage_ad_date;
	dword  fuel_res_ad_date;
	dsword temp1;

	fuel_voltage_ad_date = 4096;//4000;
	fuel_res_ad_date = 4090;//1000;

	temp1 = FUEL_R_100K*fuel_voltage_ad_date + (dword)FUEL_R_10K*BIT12_ADC_VALUE - (FUEL_R_100K+FUEL_R_10K)*fuel_res_ad_date;
	if(temp1 > 0) 
	{
		temp = ( (FUEL_R_100K+FUEL_R_10K)*fuel_res_ad_date - (dword)BIT12_ADC_VALUE*FUEL_R_10K ) * FUEL_R_182 * AD_EXPAND_MULTIPLE / temp1;

		//if(temp > 2000)    temp = 2000;
		//else if(temp < 20) temp = 20;

		printf("temp1 = %ld\n", temp1);
		printf("temp = %ld\n", temp);
		printf("ok\n");
	} 
	else 
	{
		printf("error\n");
	}
#else/* 方案二：单步计算，每一步详细的计算说明(结果是浮点型的实际值) */
	float  res;
	float  fuel_voltage_ad_date;
	float  fuel_res_ad_date;
	float current;

	float  sensor_voltage, voltage, base_voltage;

	fuel_voltage_ad_date = 4000;//4000.0;
	fuel_res_ad_date = 2000;//1000.0;

	sensor_voltage = (fuel_res_ad_date / BIT12_ADC_VALUE) * 5;
	base_voltage = (fuel_voltage_ad_date / BIT12_ADC_VALUE) * 5;
	printf("sensor_voltage = %f\n", sensor_voltage);
	printf("base_voltage = %f\n", base_voltage);

	/* 计算FUEL口到负载接地之间的电压值voltage */
	voltage = sensor_voltage - (5 - sensor_voltage)*FUEL_R_10K / FUEL_R_100K;
	printf("voltage = %f\n", voltage);

	/* 计算FUEL口到负载接地之间的电流值current */
	if (base_voltage > voltage)
	{
		current = ((5.0 - sensor_voltage) / (FUEL_R_100K * 1000) + (base_voltage - voltage) / FUEL_R_182);
	}
	else
	{
		current = ((5.0 - sensor_voltage) / (FUEL_R_100K * 1000) - (voltage - base_voltage) / FUEL_R_182);
	}
	printf("current = %f\n", current);

	/* 计算FUEL口到负载接地之间的电阻值res */
	if (current > 0)
	{
		res = voltage / current;
	}
	else
	{
		res = 2000;/* 默认res=2000欧姆 */
	}
	printf("res = %f\n", res);
#endif
} 
#endif

#if C_PLUS_PLUS_UNIX_SINGLE_CHAR_INPUT
void main()
{
	int c;
	system("stty raw");			/* 终端驱动处于一次一个字符模式,此命令不支持Windows */
	c = getchar();
	system("stty cooked");		/* 终端驱动处又回到一次一行模式,此命令不支持Windows */

}
#endif

#if C_PLUS_PLUS_GETCHAR_GETCH_GETCHE_COMMAND
void main() 
{ 
#if 1
	char c, ch; 
	c = _getch();		/*从键盘上读入一个字符不回显送给字符变量c*/
	putchar(c);			/*输出该字符*/ 
	ch = _getche();		/*从键盘上带回显的读入一个字符送给字符变量ch*/
	putchar(ch); 
	c = getchar();		/*从键盘读入字符直到回车结束*/
	putchar(c);			/*显示输入的第一个字符*/ 

#else
	char c;
	int ch;
	std::cin >> c; 
	std::cout << "*\n";

	while (1){
		if (_kbhit()){//如果有按键按下，则_kbhit()函数返回真
			ch = _getch();//使用_getch()函数获取按下的键值
			std::cout << ch;
			if (ch == 27){ break; }//当按下ESC时循环，ESC键的键值时27.
		}
	}
	system("pause");

#endif
} 
#endif

#if C_PLUS_PLUS_BIT_MAP_DISPLAY
#define X )*2+1
#define _ )*2
#define s ((((((((((((((((0			/* 用于创建16位宽的图形 */
/* 使用上面的宏定义，程序就可以描述出对应的图形，程序的自描述能力大大加强 */
static unsigned short stopwatch[] =
{
#if 1
	s _ _ _ _ _ X X X X X _ _ _ X X _,
	s _ _ _ _ _ X X X X X _ _ _ X X _,
	s _ _ X X X _ _ _ _ _ X X X _ X X,
	s _ X X _ _ _ _ _ _ _ _ _ X X _ _,
	s _ X X _ _ _ _ _ _ _ _ _ X X _ _,
	s X X _ _ _ _ _ _ _ _ _ _ _ X X _,
	s X X _ _ _ _ _ _ _ _ _ _ _ X X _,
	s X X _ X X X X X _ _ _ _ _ X X _,
	s X X _ _ _ _ _ X _ _ _ _ _ X X _,
	s X X _ _ _ _ _ X _ _ _ _ _ X X _,
	s _ X X _ _ _ _ X _ _ _ _ X X _ _,
	s _ X X _ _ _ _ X _ _ _ _ X X _ _,
	s _ _ X X X _ _ _ _ _ X X X _ _ _,
	s _ _ _ X X X X X X X X X _ _ _ _,
	s _ _ _ _ _ X X X X X _ _ _ _ _ _,
	s _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
#else
	s _ _ _ _ _ X X X X X _ _ _ X X _,
	s _ _ _ _ _ X X X X X _ _ _ X X _,
	s _ _ X X X _ _ X _ _ X X X _ X X,
	s _ X X _ _ _ _ X _ _ _ _ X X _ _,
	s _ X X _ _ _ _ X _ _ _ _ X X _ _,
	s X X _ _ _ _ _ X _ _ _ _ _ X X _,
	s X X _ _ _ _ _ X _ _ _ _ _ X X _,
	s X X X X X X X X X X X X X X X _,
	s X X _ _ _ _ _ X _ _ _ _ _ X X _,
	s X X _ _ _ _ _ X _ _ _ _ _ X X _,
	s _ X X _ _ _ _ X _ _ _ _ X X _ _,
	s _ X X _ _ _ _ X _ _ _ _ X X _ _,
	s _ _ X X X _ _ _ _ _ X X X _ _ _,
	s _ _ _ X X X X X X X X X _ _ _ _,
	s _ _ _ _ _ X X X X X _ _ _ _ _ _,
	s _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _
#endif
};

#define ushort_bit_length 16
void main()
{
	int buf_length;
	buf_length = sizeof(stopwatch)/2;
	printf("buf_length = %d\n", buf_length);
	printf("\n");

	for (int i = 0; i < buf_length; i++)
	{
		for (int j = 0; j < ushort_bit_length; j++)
		{
			if (j == 0)
			{
				printf("s");
			}
			else
			{
				if ((stopwatch[i] << j) & 0x8000)
				{
					printf("X");
				}
				else
				{
					printf("_");
				}
			}
		}
		printf("\n");
	}
	printf("\n");

	#ifdef X
		#undef X
	#endif

	#ifdef _
		#undef _
	#endif

	#ifdef s
		#undef s
	#endif

	#ifdef X
		printf("#ifdef X able\n");
	#else
		printf("#undef X able\n");
	#endif

	#ifdef _
		printf("#ifdef _ able\n");
	#else
		printf("#undef _ able\n");
	#endif

	#ifdef s
		printf("#ifdef s able\n");
	#else
		printf("#undef s able\n");
	#endif
}
#endif

#if C_PLUS_PLUS_SECTION_ERROR_DEAL
void handler(int s)
{
	//if (s == SIGBUS) printf(" now got a bus error signal\n");
	if(s == SIGSEGV) printf(" now got a segmentation violation signal\n");
	if(s == SIGILL) printf(" now got a illegal instrution signal\n");
	exit(1);
}
void main()
{
	int *p = NULL;

	//signal(SIGBUS,handler);
	signal(SIGSEGV,handler);
	signal(SIGILL,handler);
	*p = 0;					/* 非法内存访问，会产生SIGSEGV信号，打印对应的提示信息 */
}
#endif

#if C_PLUS_PLUS_MEMORY_ALIGNMENT2
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
#endif

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