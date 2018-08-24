
#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	<stdlib.h>
#include	<iostream>
#include	<signal.h>
#include	<conio.h>
#include	<stdlib.h>

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
//#define C_PLUS_PLUS_RES_AD_SAMPLE 1
//#define C_PLUS_PLUS_HASH_FUNCTION 1
//#define C_PLUS_PLUS_CHAR_CONVERTION_FUNCTION 1
//#define C_PLUS_PLUS_ARRAY_AND_POINTER_ARGUMENTS_FUNCTION 1
#define C_PLUS_PLUS_TEXT_FUNCTION 1


#if C_PLUS_PLUS_TEXT_FUNCTION
#if 0
int apricot[2][3][5] = {0};
void main()
{
	int i = 0, j = 0, k = 0;

	int (*p)[3][5] = apricot;		/* sizeof(apricot)= */
	int (*r)[5] = apricot[i];
	int (*t) = apricot[i][j];
	int u = apricot[i][j][k];

	printf("sizeof(apricot)=%d \n", sizeof(apricot));
	printf("sizeof(apricot[i])=%d \n", sizeof(apricot[i]));
	printf("sizeof(apricot[i][j])=%d \n", sizeof(apricot[i][j]));
	printf("sizeof(apricot[i][j][k])=%d \n", sizeof(apricot[i][j][k]));
}
#else
int apricot[2][3][5];
int(*r)[5] = apricot[0];
int* t = apricot[0][0];
char vegetable[][9] = {
	"beet",
	"barley",
	"basil",
	"broccli",
	"beans"
};
int row_1[] = { 1, 2, 2 };
int row_2[] = { 2, 3, 4, 4, 4 };
int row_3[] = { 2, 5, 2, 4 };
int *wights[] = {
	row_1,
	row_2,
	row_3
};
void main() {
	printf("r'address=%x \n",r);
	printf("t'address=%x \n", t);
	printf("apricot[0]'address=%x \n", apricot[0]);
	printf("apricot[0][0][0]'address=%x \n", &apricot[0][0][0]);
	printf("apricot[0][1][0]'address=%x \n", &apricot[0][1][0]);
	r++;
	t++;
	printf("r++'address=%x \n",r);
	printf("t++'address=%x \n",t);

	printf("vegetable string=%s \n", vegetable[0]);
	printf("wights[0][0]=%d \n", wights[0][0]);
}
#endif
#endif

#if C_PLUS_PLUS_ARRAY_AND_POINTER_ARGUMENTS_FUNCTION
char ga[] = "ga-text";

void fuction1(char ca[])
{
	printf("%p,%p,%p,", &ca, &(ca[0]), &(ca[1]));
	printf("%p \n", ++ca);
}
void fuction2(char *pa)
{
	printf("%p,%p,%p,", &pa, &(pa[0]), &(pa[1]));
	printf("%p \n", ++pa);
}
void main()
{
	//char str[] = "0123456789";
	//int   a = strlen(str); /*a=10;strlen �����ַ����ĳ���,��\0'Ϊ�ַ����������.*/
	//int   b=sizeof(str); /*b=20;sizeof ��������Ƿ��������str[20] ��ռ���ڴ�ռ�Ĵ�С,��������洢������Ӱ��*/
	
	printf("%p,%p,%p,%p \n", ga, &ga, &(ga[0]), &(ga[1]));
	//std::cout << ga << std::endl;
	fuction1(ga);
	fuction2(ga);

}
#endif

#if C_PLUS_PLUS_CHAR_CONVERTION_FUNCTION
#if PROGRAM1
extern int printf(const char*,...);
void main()
{
	void* f = (void*)printf;
	(*(int(*)(const char*,...))f)("I'm ok! \n");
}
#else
extern int printf(const char*,...);
typedef int(*p_function)(const char*,...);
void main()
{
	p_function f;
	f = &printf;
	(*f)("I'm ok! \n");
}
#endif
#endif

#if C_PLUS_PLUS_HASH_FUNCTION
	//#include <stdio.h>
	//#include <stdlib.h>
	//#include <string.h>
#define TABLE_SIZE (16)		// TABLE_SIZE��ֵΪ16����2���ݴΣ����򣬲���ͨ��data & (TABLE_SIZE-1)��������ֵ��data % TABLE_SIZE�ķ�ʽ��������ֵ��

typedef struct _node {
	int data;
	struct _node* next;
} NODE;

typedef struct _hash_table {
	NODE* value[TABLE_SIZE];
} HASH_TABLE;

typedef enum
{
	FALSE = 0,
	TRUE
}STATUS;

HASH_TABLE* create_hash_table()
{
	HASH_TABLE* pHashTb1 = (HASH_TABLE*)malloc(sizeof(HASH_TABLE));
	memset(pHashTb1, 0, sizeof(HASH_TABLE));
	return pHashTb1;
}

NODE* find_data_in_hash(HASH_TABLE* pHashTbl, int data)
{
	int i=0;
	NODE* pNode;
	if (NULL == pHashTbl)
		return NULL;

	//if (NULL == (pNode = pHashTbl->value[data % TABLE_SIZE]))
	if (NULL == (pNode = pHashTbl->value[data & (TABLE_SIZE - 1)]))
		return NULL;

	while (pNode){
		if (data == pNode->data)
			return pNode;
		pNode = pNode->next;
		i++;
	}
	return NULL;
}

STATUS insert_data_into_hash(HASH_TABLE* pHashTbl, int data)
{
	NODE* pNode;
	if (NULL == pHashTbl)
		return FALSE;

	//if (NULL == pHashTbl->value[data % TABLE_SIZE]){
	if (NULL == pHashTbl->value[data & (TABLE_SIZE - 1)]){
		pNode = (NODE*)malloc(sizeof(NODE));
		memset(pNode, 0, sizeof(NODE));
		pNode->data = data;
		//pHashTbl->value[data % TABLE_SIZE] = pNode;
		pHashTbl->value[data & (TABLE_SIZE - 1)] = pNode;
		return TRUE;
	}

	if (NULL != find_data_in_hash(pHashTbl, data))
		return FALSE;

	//pNode = pHashTbl->value[data % TABLE_SIZE];
	pNode = pHashTbl->value[data & (TABLE_SIZE - 1)];
	while (NULL != pNode->next)
		pNode = pNode->next;

	pNode->next = (NODE*)malloc(sizeof(NODE));
	memset(pNode->next, 0, sizeof(NODE));
	pNode->next->data = data;
	return TRUE;
}

STATUS delete_data_from_hash(HASH_TABLE* pHashTbl, unsigned long int data)
{
	NODE* pHead;
	NODE* pNode;
	//if (NULL == pHashTbl || NULL == pHashTbl->value[data % TABLE_SIZE])
	if (NULL == pHashTbl || NULL == pHashTbl->value[data & (TABLE_SIZE - 1)])
		return FALSE;

	if (NULL == (pNode = find_data_in_hash(pHashTbl, data)))
		return FALSE;

	//if (pNode == pHashTbl->value[data % TABLE_SIZE]){
	if (pNode == pHashTbl->value[data & (TABLE_SIZE - 1)]){
		//pHashTbl->value[data % TABLE_SIZE] = pNode->next;
		pHashTbl->value[data & (TABLE_SIZE - 1)] = pNode->next;
		goto final;
	}

	//pHead = pHashTbl->value[data % TABLE_SIZE];
	pHead = pHashTbl->value[data & (TABLE_SIZE - 1)];
	while (pNode != pHead->next)
		pHead = pHead->next;
	pHead->next = pNode->next;

	final:
	free(pNode);
	return TRUE;
}

/* the classic Times33 hash function */
static int hash_33(char* key)
{
	int hash = 0;
	while (*key) {
		hash = (hash << 5) + hash + *key++;
		//hash = hash * 33 + *key++;
	}
	return hash;
}

void main()
{
	NODE* p_node = NULL;
	HASH_TABLE* p_hash_table = NULL; 
	STATUS e_status;
	int hash_code;
	char input[] = "book";
	char input2[] = "tanzheng";

	p_hash_table = create_hash_table();
	if (p_hash_table != NULL)
	{	
		printf("create hash_table ok,address=%p \n", p_hash_table);
		hash_code = hash_33(input);
		e_status = insert_data_into_hash(p_hash_table, hash_code);
		e_status = insert_data_into_hash(p_hash_table, hash_code);
		e_status = insert_data_into_hash(p_hash_table, 16139);
		e_status = insert_data_into_hash(p_hash_table, 7723);
		e_status = insert_data_into_hash(p_hash_table, 7724);
		e_status = insert_data_into_hash(p_hash_table, 7725);
		e_status = delete_data_from_hash(p_hash_table, 16139);
		e_status = delete_data_from_hash(p_hash_table, 7724);
		if (e_status == TRUE)
		{
			printf("SUCCESS \n");
		}
		else
		{
			printf("FAILURE \n");
		}
	}
}
#endif

#if C_PLUS_PLUS_RES_AD_SAMPLE
/*
 *�������ݵ���ǰ������
 *1.����FUEL_IN�ڵĵ�ѹΪsensor_voltage;
 *2.FUEL_V�ڵĵ�ѹΪbase_voltage;
 *3.FUEL�ڵ����ؽӵ�֮��ĵ�ѹΪvoltage;
 *4.FUEL�ڵ����ؽӵ�֮��ĵ���Ϊcurrent;
 *5.FUEL�ڵ����ؽӵ�֮��ĵ���Ϊres;
 *6.��Ƭ���Ļ�׼��ѹ = 5V��AD����Ϊ12λ = 4096��
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
#if 0/* ����һ�������㷨�󣬼���ó���ӵ���ֵ(���������10������������) */
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
#else/* ���������������㣬ÿһ����ϸ�ļ���˵��(����Ǹ����͵�ʵ��ֵ) */
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

	/* ����FUEL�ڵ����ؽӵ�֮��ĵ�ѹֵvoltage */
	voltage = sensor_voltage - (5 - sensor_voltage)*FUEL_R_10K / FUEL_R_100K;
	printf("voltage = %f\n", voltage);

	/* ����FUEL�ڵ����ؽӵ�֮��ĵ���ֵcurrent */
	if (base_voltage > voltage)
	{
		current = ((5.0 - sensor_voltage) / (FUEL_R_100K * 1000) + (base_voltage - voltage) / FUEL_R_182);
	}
	else
	{
		current = ((5.0 - sensor_voltage) / (FUEL_R_100K * 1000) - (voltage - base_voltage) / FUEL_R_182);
	}
	printf("current = %f\n", current);

	/* ����FUEL�ڵ����ؽӵ�֮��ĵ���ֵres */
	if (current > 0)
	{
		res = voltage / current;
	}
	else
	{
		res = 2000;/* Ĭ��res=2000ŷķ */
	}
	printf("res = %f\n", res);
#endif
} 
#endif

#if C_PLUS_PLUS_UNIX_SINGLE_CHAR_INPUT
void main()
{
	int c;
	system("stty raw");			/* �ն���������һ��һ���ַ�ģʽ,�����֧��Windows */
	c = getchar();
	system("stty cooked");		/* �ն��������ֻص�һ��һ��ģʽ,�����֧��Windows */

}
#endif

#if C_PLUS_PLUS_GETCHAR_GETCH_GETCHE_COMMAND
void main() 
{ 
#if 1
	char c, ch; 
	c = _getch();		/*�Ӽ����϶���һ���ַ��������͸��ַ�����c*/
	putchar(c);			/*������ַ�*/ 
	ch = _getche();		/*�Ӽ����ϴ����ԵĶ���һ���ַ��͸��ַ�����ch*/
	putchar(ch); 
	c = getchar();		/*�Ӽ��̶����ַ�ֱ���س�����*/
	putchar(c);			/*��ʾ����ĵ�һ���ַ�*/ 

#else
	char c;
	int ch;
	std::cin >> c; 
	std::cout << "*\n";

	while (1){
		if (_kbhit()){//����а������£���_kbhit()����������
			ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
			std::cout << ch;
			if (ch == 27){ break; }//������ESCʱѭ����ESC���ļ�ֵʱ27.
		}
	}
	system("pause");

#endif
} 
#endif

#if C_PLUS_PLUS_BIT_MAP_DISPLAY
#define X )*2+1
#define _ )*2
#define s ((((((((((((((((0			/* ���ڴ���16λ���ͼ�� */
/* ʹ������ĺ궨�壬����Ϳ�����������Ӧ��ͼ�Σ��������������������ǿ */
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
	*p = 0;					/* �Ƿ��ڴ���ʣ������SIGSEGV�źţ���ӡ��Ӧ����ʾ��Ϣ */
}
#endif

#if C_PLUS_PLUS_MEMORY_ALIGNMENT2
void main()
{
	int *p = NULL;
	//*p = 17;	/*�ڴ�δ���룬���ߴ���*/

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
	*p = 17;	/*�ڴ�δ���룬���ߴ���*/

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
	for (i = 0; i < FILTER_SIZE - 1; i++) {						// �����󡯵�ð��������ֵ						
		for (j = i; j < FILTER_SIZE - 1; j++) {
			if (ulaCAPTURE[sm_unit][j] > ulaCAPTURE[sm_unit][j + 1]) {
				temp = ulaCAPTURE[sm_unit][j];
				ulaCAPTURE[sm_unit][j] = ulaCAPTURE[sm_unit][j + 1];
				ulaCAPTURE[sm_unit][j + 1] = temp;
			}
		}
	}
#else
	for (i = 0; i < FILTER_SIZE - 1; i++) {						// ����ȷ����ð��������ֵ						
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
	int  var = 20;   // ʵ�ʱ���������
	int  *ip;        // ָ�����������

	ip = &var;       // ��ָ������д洢 var �ĵ�ַ

	cout << "Value of var variable: ";
	cout << var << endl;

	// �����ָ������д洢�ĵ�ַ
	cout << "Address stored in ip variable: ";
	cout << ip << endl;

	// ����ָ���е�ַ��ֵ
	cout << "Value of *ip variable: ";
	cout << *ip << endl;

	return 0;
}

#endif
#endif

#if C_PLUS_PLUS_QUOTE

// ���ò���ʵ�ֽ���
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