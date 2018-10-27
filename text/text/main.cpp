
#include	<stdio.h>
#include	<string.h>
#include	<ctype.h>
#include	<stdlib.h>
#include	<signal.h>
#include	<conio.h>
#include	<stdlib.h>
#include	<iostream>
#include	<fstream>
#include	<typeinfo>
//#include <iostream>


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
//#define C_PLUS_PLUS_TEXT_FUNCTION 1
//#define C_PLUS_PLUS_POINTER_FUCTION_EXPEND 1
//#define C_PLUS_PLUS_POINTER_FUCTION_EXPEND2 1
//#define C_PLUS_PLUS_POINTER_FUCTION_EXPEND3 1
//#define C_PLUS_PLUS_POINTER_FUCTION_EXPEND4 1
//#define C_PLUS_PLUS_POINTER_FUCTION_EXPEND5 1
//#define C_PLUS_PLUS_CLASS_EXPEND0 1
//#define C_PLUS_PLUS_CLASS_EXPEND1 1
//#define C_PLUS_PLUS_CLASS_EXPEND2 1
//#define C_PLUS_PLUS_CLASS_EXPEND3 1
//#define C_PLUS_PLUS_CLASS_EXPEND4 1
//#define C_PLUS_PLUS_CLASS_EXPEND5 1
//#define C_PLUS_PLUS_CLASS_EXPEND6 1
//#define C_PLUS_PLUS_CLASS_EXPEND7 1
#define C_PLUS_PLUS_CLASS_EXPEND8 1


#if C_PLUS_PLUS_CLASS_EXPEND8
/**
 * 字符串转换为数字，并进行计算
 */
/* atoi example */
#include <stdio.h>      /* printf, fgets */
#include <stdlib.h>     /* atoi */

int main()
{
	int i;
	char buffer[256];
	printf("Enter a number: ");
	fgets(buffer, 256, stdin);
	i = atoi(buffer);
	printf("The value entered is %d. Its double is %d.\n", i, i * 2);
	return 0;
}
#endif

#if C_PLUS_PLUS_CLASS_EXPEND7
/**
 * C++文件流输入和输出
 * FILE_STREAM_WORK_STATE == 1：向文件内写入两行字符串
 * FILE_STREAM_WORK_STATE == 2：从文件内读出所有的字符串，并显示
 * FILE_STREAM_WORK_STATE == 3：读出文件的字节大小
 * FILE_STREAM_WORK_STATE == 4：首先读出文件的字符个数，动态分配buff'，再把内容读出并显示
 * FILE_STREAM_WORK_STATE == 5：一个文件的内容复制到另外一个文件内
 */
#define FILE_STREAM_WORK_STATE 5
using namespace std;

#if FILE_STREAM_WORK_STATE==1
int main() 
{
	ofstream out("d:\\out.txt");
	if (out.is_open()) 
	{
		out << "This is a line.\n";
		out << "This is another line.\n";
		out.close();
	}
	return 0;
}
#elif FILE_STREAM_WORK_STATE==2
int main() 
{
	char buffer[256];
	ifstream in("d:\\out.bin");
	if (!in.is_open())
	{ cout << "Error opening file"; exit (1); }
	while (!in.eof() )
	{
		in.getline (buffer,100);
		cout << buffer << endl;
	}
	return 0;
}
#elif FILE_STREAM_WORK_STATE==3
const char * filename = "d:\\out.txt";

int main () {
	long l,m;
	ifstream in(filename, ios::in|ios::binary);
	l = in.tellg();
	in.seekg (0, ios::end);
	m = in.tellg();
	in.close();
	cout << "size of " << filename;
	cout << " is " << (m-l) << " bytes.\n";
	return 0;
}
#elif FILE_STREAM_WORK_STATE==4
const char *filename = "d:\out.bin";
int main() {
	//std::ifstream is(filename, std::ifstream::binary);
	ifstream is(filename, ios::in | ios::binary | ios::ate);
	if (is) {
		// get length of file:
		is.seekg(0, is.end);
		int length = is.tellg();
		is.seekg(0, is.beg);

		// allocate memory:
		char * buffer = new char[length];

		// read data as a block:
		is.read(buffer, length); 

		is.close();

		// print content:
		std::cout.write(buffer, length);

		delete[] buffer;
	}

	return 0;
}
#elif FILE_STREAM_WORK_STATE==5
int main () {
	std::ifstream infile("d:\\test.txt", std::ifstream::binary);
	std::ofstream outfile("d:\\new.txt", std::ofstream::binary);

	// get size of file
	infile.seekg (0,infile.end);
	long size = infile.tellg();
	infile.seekg (0);

	// allocate memory for file content
	char* buffer = new char[size];

	// read content of infile
	infile.read (buffer,size);

	// write to outfile
	outfile.write (buffer,size);

	// release dynamically-allocated memory
	delete[] buffer;

	outfile.close();
	infile.close();
	return 0;
}
#endif

#endif

#if C_PLUS_PLUS_CLASS_EXPEND6
/**
 * 矩阵乘法朴素算法
 */
#define MAXN  50
typedef struct mat{
	int n, m;
	double data[MAXN][MAXN];
} s_matrix;

int mul(mat& c, const mat& a, const mat& b){
	int i, j, k;
	if (a.m != b.n)
		return 0;
	c.n = a.n;
	c.m = b.m;
	for (i = 0; i < c.n; i++)
	for (j = 0; j < c.m; j++)
	for (c.data[i][j] = k = 0; k < a.m; k++)
		c.data[i][j] += a.data[i][k] * b.data[k][j];
	return 1;
}
void main()
{
	mat a_mat;
	mat b_mat;
	mat c_mat;

	char x,y;
	int a;
	//ch = _getch();                        //不能写成getch(ch);
	//std::cout << ch << std::endl;
	//_getch();

	memset(&a_mat, 0, sizeof(mat));
	memset(&b_mat, 0, sizeof(mat));
	memset(&c_mat, 0, sizeof(mat));
	
	printf("请输入矩阵A：\n");
#if 0
	for (y = 0; y < MAXN; y++)
	{
		for (x = 0; x < MAXN; x++)
		{
			//std::cin >> a;
			a = _getch();
			//if ((a == '\n') || (a == 'q'))
			if (a == '\n')
			{
				break;
			}
			a_mat.data[y][x] = a;
			std::cout << a_mat.data[y][x] << ",";
		}

		printf("\n");
		if (a == '\n') {
			break;
		}
	}
#else
	using namespace std;

	float data[1500][2] = { 0 };//定义一个1500*2的矩阵，用于存放数据
	ifstream infile;//定义读取文件流，相对于程序来说是in
	infile.open("d:\data.txt");//打开文件
	for (int i = 0; i < 1500; i++)//定义行循环
	{
		for (int j = 0; j < 2; j++)//定义列循环
		{
			infile >> data[i][j];//读取一个值（空格、制表符、换行隔开）就写入到矩阵中，行列不断循环进行
		}
	}
	infile.close();
#endif
	printf("请输入矩阵B：\n");
	for (int i = 0; i < 20; i++)
	{
		std::cout << a_mat.data[0][i] << std::endl;
	}
	 
	//int len = 0;
	//cin >> len;
	//int *nums = new int[len];
	//for (int i = 0; i < len; ++i)
	//{
		//std::cin >> nums[i];
	//}
	//for (auto i = 0; i < len; ++i)
		//cout << nums[i] << endl;
	//std::cin >> 

}
#endif

#if C_PLUS_PLUS_CLASS_EXPEND5
/**
 给定一个数N，要求列出所有不大于N的素数？
 1.普通算法(判断一个数是否是素数？只需判断该数平方根以内的数据能否被整除，如果不能被整除就是素数。)
 2.素数筛法算法(原理：就是当i是质(素)数的时候，i的所有的倍数必然是合数。如果i已经被判断不是质数了，
                数的倍数筛掉。那么再找到i后面的质数来把这个质)
 */
#if 0
	#define N 100001
	void main()
	{
		int num = 0,i,j;
		int buf[N + 1];
		for (i = 2; i<N; i++) {
			for (j = 2; j <= sqrt(i); j++) {
				if (i%j == 0) {
					break;
				}
			}
			if (j>sqrt(i)) {
				buf[num++] = i;
			}
		}

		printf("数据%d以内的所有素数：\n", N);
		for (i = 0; i<num; i++) {
			printf("%d,", buf[i]);
		}
	}
#else
	#define N 100001
	#define true 1
	#define false 0
	void main()
	{
		int i,j;
		int buf[N+1];
		for(i=2;i<N;i++) {
			if(i%2) {
				buf[i] = true;
			}
			else {
				buf[i] = false;
			}
		}

		for (i = 3; i <= sqrt(N); i++) {
			if(buf[i] == true) {
				for (j = i + i; j<N; j += i) {
					buf[j] = false;
				}
			}
		}

		printf("数据%d以内的所有素数：\n",N);
		for(i=0;i<N;i++) {
			if(buf[i]==true) {
				printf("%d,",i);
			}
		}
		printf("\n");
	}
	/*
	第 1 步过后2 4 ... 28 30这15个单元被标成false,其余为true。
    第 2 步开始：
		i=3;  由于prime[3]=true, 把prime[6], [9], [12], [15], [18], [21], [24], [27], [30]标为false.

		i=4;  由于prime[4]=false,不在继续筛法步骤。

		i=5;  由于prime[5]=true, 把prime[10],[15],[20],[25],[30]标为false.

		i=6>sqrt(30)算法结束。
    第 3 步把prime[]值为true的下标输出来：
		for(i=2; i<=30; i++)
			if(prime[i]) printf("%d ",i);
    结果是 2 3 5 7 11 13 17 19 23 29
	*/
#endif

#endif

#if C_PLUS_PLUS_CLASS_EXPEND4
/*
 八皇后的问题（在8×8格的国际象棋上摆放八个皇后，使其不能互相攻击，即任意两个皇后都不能处于同一行、同一列或同一斜线上）
 提问：列出所有满足八皇后条件的排列组合，并累计总个数，如何求解？
 */
#define true 1
#define false 0
#define MAX_NUM 8
static int chessBoard[MAX_NUM][MAX_NUM] = {0};
typedef unsigned char boolean;
 
class Queen8 {
	public:
		boolean settleQueen(int y);
		boolean check(int x, int y);
		void printChessBoard(void);
		Queen8(int i);
		~Queen8();
	private:
		int conut;
};

Queen8::Queen8(int i)
{
	conut = i;
}

Queen8::~Queen8()
{
	printf("Class queen8 over\n");
}

boolean Queen8::check(int x, int y)
{
	for (int i = 0; i < y; i++) {
		if (chessBoard[x][i] == 1) {
			return false;
		}
		if (x - 1 - i >= 0 && chessBoard[x - 1 - i][y - 1 - i] == 1) {
			return false;
		}
		if (x + 1 + i < MAX_NUM && chessBoard[x+1+i][y - 1 - i] == 1) {
			return false;
		}
	}
	return true;
}

boolean Queen8::settleQueen(int y)
{
	int i=0;

	if (y == 0 && i == (MAX_NUM-1)) {
		return true;
	}

	if (y == MAX_NUM) {
		conut++;
		Queen8::printChessBoard();
		printf("八皇后摆放成功次数=%d \n", conut);
		printf("\n");

		return false;
	}

	for (i = 0; i < MAX_NUM; i++) {
		for (int x = 0; x < MAX_NUM; x++) {
			chessBoard[x][y] = 0;
		}
		
		if (Queen8::check(i, y)) {
			chessBoard[i][y] = 1;
			if (Queen8::settleQueen(y + 1)) {
				return true;
			}
		}
	}
	return false;
	
}

void Queen8::printChessBoard(void)
{
	for (int j = 0; j < MAX_NUM; j++) {
		for (int i = 0; i < MAX_NUM; i++) {
			printf("%d ", chessBoard[i][j]);
		}
		printf("\n");
	}
	//printf("\n");
}

void main()
{
	Queen8 queen8(0);		// Queen8是整个类的名字

	queen8.settleQueen(0);
}
#endif

#if C_PLUS_PLUS_CLASS_EXPEND3
/*
  读取一个字符串，并输出它里面字符的所有字符？
  现列出两种方法：
	1.二进制形算法  
	2.递归算法
 */
#if 1
void GetPowerSet2(char nArray[], int nLength)
{
	int mark = 0;
	int i = 0;
	int nStart = 0;
	int nEnd = (1 << nLength) -1;
	bool bNullSet = false;

	for (mark = nStart; mark <= nEnd; mark++)
	{
		bNullSet = true;
		for (i = 0; i < nLength; i++)
		{
			if (((1<<i)&mark) != 0) //该位有元素输出
			{
				bNullSet = false;
				printf("%c\t", nArray[i]);
			}
		}
		if (bNullSet) //空集合
		{
			printf("@\t");
		}
		printf("\n");
	}
}
void main()
{
	char str[50] = { 0 };
	char *s=NULL;
	int age, len;
	std::cin >> str >> age;
	std::cout << str << "的年龄：" << age << std::endl;
	printf("%s,%d \n", str, age);
	len = strlen(str);
	s = new char[len+1];
	//s = (char *)malloc(sizeof(char)* len);
	memset(s, 0, len+1);
	GetPowerSet2(str,len);
}
#else
void string_renew_position(char *str, char *s, char len, int m, int n)
{
	int i;
	for (i = n; i < len; i++)
	{
		if (i > n) {
			m--;
		}
		s[m] = str[i];
		s[++m] = '\0';
		printf("%s \n", s);
		if (i < len-1)
			string_renew_position(str, s, len, m, i+1);
	}
}
void main()
{
	char str[50] = { 0 };
	char *s;
	int age,len;
	std::cin >> str >> age;
	std::cout << str<< "的年龄：" << age << std::endl;
	printf("%s,%d \n", str, age);
	len = strlen(str);
	s = new char[len+1];
	string_renew_position(str,s,len, 0, 0);
}
#endif
#endif

#if C_PLUS_PLUS_CLASS_EXPEND2
//小结：1、有virtual才可能发生多态现象
// 2、不发生多态（无virtual）调用就按原类型调用
using namespace std;

class Base
{
public:
	virtual void f(float x)
	{
		cout << "Base::f(float)" << x << endl;
	}
	void g(float x)
	{
		cout << "Base::g(float)" << x << endl;
	}
	void h(float x)
	{
		cout << "Base::h(float)" << x << endl;
	}
};
class Derived : public Base
{
public:
	virtual void f(float x)
	{
		cout << "Derived::f(float)" << x << endl;   //多态、覆盖
	}
	void g(int x)
	{
		cout << "Derived::g(int)" << x << endl;     //隐藏
	}
	void h(float x)
	{
		cout << "Derived::h(float)" << x << endl;   //隐藏
	}
};
int main(void)
{
	Derived d;
	Base *pb = &d;
	Derived *pd = &d;

	// Good : behavior depends solely on type of the object
	pb->f(3.14f);   // Derived::f(float) 3.14
	pd->f(3.14f);   // Derived::f(float) 3.14

	// Bad : behavior depends on type of the pointer
	pb->g(3.14f);   // Base::g(float)  3.14
	pd->g(3.14f);   // Derived::g(int) 3 

	// Bad : behavior depends on type of the pointer
	pb->h(3.14f);   // Base::h(float) 3.14
	pd->h(3.14f);   // Derived::h(float) 3.14
	return 0;
}
#endif

#if C_PLUS_PLUS_CLASS_EXPEND1
class Fruit {
public:
	virtual void peel() { printf("peelling a base class fruit\n"); }
	//void peel() { printf("peelling a base class fruit\n"); }
	void slice();
	void juice();
protected:
	int fruit_test_val;
private:
	int weight,calories_per_oz;
}; 
class Apple : public Fruit {
public:
	void peel() { 
		fruit_test_val = 2;
		//weight = 3;		// program error
		printf("peelling an apple\n"); 
	}
	void make_candy_apple(float weight);
protected:
	int apple_test_val;
};

class Apple_pai : public Apple {
	public:
		void peel() {
			fruit_test_val = 3;
			apple_test_val = 4;
			printf("peelling an apple pai\n");
		}
		void apple_pai_else() {
			;
		}
};

void Apple::make_candy_apple(float weight) {
	printf("Candy apple'weight=%f\n", weight);
}

Fruit banana;
Fruit *p;
Apple *pa;
Apple_pai apple_pai_val;
void main()  
{
	p = new Apple_pai;
	pa = new Apple;
	banana.peel();
	p->peel();
	p->Fruit::peel();
	pa->peel();
	pa->Fruit::peel();
	//p->weight = 2;
	//pa->weight = 2;
	//p->low = 2;
	//pa->high = 2;
	pa->make_candy_apple((float)2.2);
	apple_pai_val.peel();
	p->
}

#endif

#if C_PLUS_PLUS_CLASS_EXPEND0
class Fruit {
public:
	void peel();
private:
	int weight, calories_per_oz;
};
void Fruit::peel() {
	printf("this per=%p \n", this);
	this->weight--;
	weight++;
	printf("this->weight per=%p \n", &(this->weight));
	printf("weight per=%p \n", &(weight));
	printf("this->weight data=%d \n", this->weight);
	printf("weight data=%d \n", weight);
	printf("calories_per_oz per=%p \n", &(this->calories_per_oz));
}
Fruit apple;
void main(){
	printf("address of apple=%x \n",&apple);
	apple.peel();
}
#endif

#if C_PLUS_PLUS_POINTER_FUCTION_EXPEND5
int current_element = 0;
int total_element = 128;
char *dynamic = (char*)malloc(total_element);
void add_element(char c) {
	char *dynamic_now;
	if (current_element == (total_element - 1)) {
		total_element *= 2;
		dynamic_now = (char*)realloc(dynamic, total_element);
		if (dynamic_now == NULL) {
			// error('Coundn't expend the table');
			//total_element /= 2;
			printf("Coundn't expend the table");
			return;
		}
		else {
			dynamic = dynamic_now;
		}
	}
	printf("dynamic=%p \n", dynamic);
	current_element++;
	dynamic[current_element] = c;
}
void main()
{
	for (int i = 0; i < 3 * 128; i++){
		add_element(i);
		printf("dynamic[%d]=%d \n",i,dynamic[i]);
	}

}
#endif

#if C_PLUS_PLUS_POINTER_FUCTION_EXPEND4
char *fgets(char *str, int n, FILE *stream);
void main()
{
	int size;
	char *dynamic;
	char input[10];
	printf("Please enter size of array：");
	size = atoi(fgets(input, 7, stdin));
	dynamic = (char*)malloc(size);

	dynamic[0] = 'a';
	dynamic[size-1] = 'z';

	printf("dynamic[0]=%d \n", dynamic[0]);
	printf("dynamic[size-1]=%d \n", dynamic[size - 1]);
	printf("size=%d \n", size);
	/*
	解释1：fgets函数，从标准流stdin读取一行（一般指键盘输入到缓冲区里的东西），当读取 (7-1) 个字符或者读取到换行符时，并把它存储在input所指向的字符串内
	解释2：atoi函数是把字符串转换成整型数的一个函数,直到遇上数字或正负符号才开始做转换，而在遇到非数字或字符串结束符('\0')才结束转换，并将结果返回（atoi函数只能转换带数字的字符串）。
	*/
}
#endif

#if C_PLUS_PLUS_POINTER_FUCTION_EXPEND3
#if 0
	int(*paf())[20];		/* paf是一个函数，它返回一个指向包括20个int元素的数组的指针 */

	int(*paf())[20] {
		int(*pear)[20];
		//pear = (int(*)[20])calloc(20, sizeof(int));
		pear = (int(*)[20])calloc(20, sizeof(int));
		if (!pear);//longjmp(error, 1);
		
		printf("pear'address=%p \n", pear);
		return pear;
	}
	void main()
	{
		int(*result)[20];		/* 声明一个指向20个int元素的数组的指针 */

		result = paf();
		(*result)[3] = 12;
		printf("result'address=%p \n", result);
		printf("result[0][3]=%d \n", result[0][3]);
		free(result);
		result=NULL;							/*  free(起始地址的指针) 对内存进行释放 */
		printf("result'address=%p \n", result);
	}
#else
	struct a_tag {
		int array[20];
	}x,y;
	struct a_tag my_function() {
		y.array[0] = 10;
		y.array[1] = 13;
		return y;
	}
	void main()
	{
		x = my_function();
		x.array[0] = 12;
		printf("x.array[0]=%d \n", x.array[0]);
		printf("x.array[1]=%d \n", x.array[1]);
		printf("y.array[0]=%d \n", y.array[0]);
		printf("y.array[1]=%d \n", y.array[1]);
	}
#endif
#endif

#if C_PLUS_PLUS_POINTER_FUCTION_EXPEND2
void my_function_1(int fruit[2][3][5])
{
	printf("function_1'fruit=%p \n", fruit);
}
void my_function_2(int fruit[][3][5])
{
	printf("function_2'fruit=%p \n", fruit);
}
void my_function_3(int (*fruit)[3][5])
{
	printf("function_3'fruit=%p \n", fruit);
}
void main()
{
	int apricot[2][3][5];
	int(*p)[3][5] = apricot;
	int(*q)[2][3][5] = &apricot;

	my_function_1(apricot);
	my_function_2(apricot);
	my_function_3(apricot);

	my_function_1(p);
	my_function_2(p);
	my_function_3(p);

	my_function_1(*q);
	my_function_2(*q);
	my_function_3(*q);
}
#endif

#if C_PLUS_PLUS_POINTER_FUCTION_EXPEND
void main()
{
	char* pea[4];
	char* p=NULL;
	char row_size=4, column_size=6;
	
	if (p == NULL) {
		p = (char*)malloc(row_size*column_size*sizeof(char));
		memset(p, 0, row_size*column_size*sizeof(char));
	}
	else {
		return;
	}
	for (int i = 0; i<row_size; i++) {
		pea[i] = p + (i*column_size*sizeof(char));
		printf("pea[%d]=%p \n", i, pea[i]);
	}
	printf("p=%p \n", p);
	printf("pea=%p \n", pea);
	printf("&pea[0]=%p \n", &pea[0]);
	printf("*pea=%p \n", *pea);

	free(p);
	p = NULL;
	for (int i = 0; i<row_size; i++) {
		pea[i] = NULL;
	}
	printf("p=%p \n", p);
	printf("&pea[0][0]=%p \n", &pea[0][0]);
	printf("&pea[0][5]=%p \n", &pea[0][5]);
	printf("&pea[1][0]=%p \n", &pea[1][0]);
	printf("&pea[1][5]=%p \n", &pea[1][5]);
	printf("&pea[2][0]=%p \n", &pea[2][0]);
	printf("&pea[2][5]=%p \n", &pea[2][5]);
	printf("&pea[3][0]=%p \n", &pea[3][0]);
	printf("&pea[3][5]=%p \n", &pea[3][5]);
}
#endif

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
	//int   a = strlen(str); /*a=10;strlen 计算字符串的长度,以\0'为字符串结束标记.*/
	//int   b=sizeof(str); /*b=20;sizeof 计算的则是分配的数组str[20] 所占的内存空间的大小,不受里面存储的内容影响*/
	
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
#define TABLE_SIZE (16)		// TABLE_SIZE赋值为16或者2的幂次；否则，不能通过data & (TABLE_SIZE-1)计算索引值（data % TABLE_SIZE的方式计算索引值）

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
	int hash_code, test_data;
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

		/*输入一个类型为int的数据，查找此数据是否保存在hash表中*/
		std::cin >> test_data;
		p_node = find_data_in_hash(p_hash_table, test_data);
		if (p_node != NULL)
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

	fuel_voltage_ad_date = 999;//4000.0;	4.88
	fuel_res_ad_date = 317;//2000.0;		1.55

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