编写分析程序，分析C语言的声明。编写一个这样的分析程序，很有助于帮助我们理解c语言的声明。
例如：
	输入： int *((*p)(int))(int)
	输出：p is pointer to function returning function returning pointer to int
