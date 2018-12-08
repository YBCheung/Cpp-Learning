# Cpp-Learning
学习C++的笔记和例程  

*1.>>右移，若有符号，则左边补位取决于最高位（1或0）  
*2.换行符'\n' = '\12' = '\xa' = '\101' = <<endl  
3.cin>>，输入到空格之前  
4.cin>>字符串a[20]位数控制：  
法一： #include <iomanip>  
	cin>>setw(10)>>a;  
法二:  cin.width(10);    //是否全部限制还是只有一个？答：只有一个  
       cin>>a;  
5.cin>>读取一行：  
	char sentence[20];  
	cin.getline(sentence,20);  //若19？写x就读x-1个。若21，则数组拓展  
	cout<<"句子："<<sentence<<endl;  
6.cin>>读取字符：  
法一：	cin>>ch;//忽略空白；  
法二：	cin.get(ch);//直接读取；类似getchar();  
法三：	fflush(stdin);//清空缓存区  
  
7.cin>>忽略当前字符  
	int number;  
	char ch;  
	cin>>number;  
	(cin.ignore();)//相当于getchar()吞掉  
	cin.get(ch);  
	cout<<number<<endl<<ch<<endl;   
  
*8.函数调用全局变量，cout<<::a<<endl;  
	(一般局部和全局重复时用::a，C语言也可以用）  
*9.缺省值、默认值：  
	void caculate(int a = 10,int b = 20);声明中定义之后  
	void caculate()再调用，则自动补齐缺省值，C语言也可用  
10.内联函数：不可循环、switch、复杂if嵌套，节省时间。  
	inline int caculate(int a = 10,int b = 20);   
*11.函数重载：  
	int number(int a);  
	int number(double b);（变量类型）    
	int number(int c,int d);（变量个数）  
	可视作3个不同函数。  
12.函数声明：int number(int,int)；可以不说变量名称     
13.函数模板：template<class T>放在子函数前，用T替换子函数里的变量类型    
声明时脸上template一起。  
14.用#ifdef可判断是否有编译预处理#define   
15.cout<<a++，从左往右看，先输出后++；若cout<<(a++),照样如此。  
16.字符串输入：cin>>ch;或cin>>ch[i]  
	若要输入空格、tab、回车，则用cin.get(ch[i])  
17.C++中包含C的头文件，要加c，如cstring  
*18.strlen(),遇见\0就停下。sizeof()，是存储大小  
19.C++中string头文件：  
	string str,str3;   
	char str2[5];  
	str1 = "ABC";   
	str2[5] = "DEF";   
	str3 = str1+str2;   
	str3 += "GHI"   
20.C++读取string变量：string array;   
法一：	cin>>array;(不能有空格)    
法二：	getline(cin,array);  
法三：	char array[x];   
	  
   
读取数组型字符串变量：char array[10]   
	cin.getline(array,x+1);  
	int型只能用for循环。  
21.string初始化   
法一：	string str1("ABC");  
法二：	string str2(str1);   
法三：	string str3(str1,3);？？？   
法四：	string str4(str,1,2);//从str下标1开始，连续2个   
  
法一：	str1 = "ABC";  
法二： 	str2 = str1;  
法三：	str3 =   
  
计算：  str1 = "ABC";str2 = "DEF";   
	str1+str2 = ABCDEF;  
查找插入：  
	x = str1.find('A');   
	str1.insert(x,"123");//在x指针位置，即A前方插入。  
22.内联函数：避免调用函数产生的开销，直接贴上去  
	inline int count（int i）   
	{  
	  return i*i；  
	}；  
	x = count（i）；=x = i*i；不调用子函数直接替换，效率更高。  
23.动态指针的数组应用  
	char str[N],N只能是数值不能是变量，可以使str变为动态指针：  
法一：	char *str  
	str = new char[n];  
法二：	char *str = new char[n];//n为变量  
	int *p = new int;  
释放：	delete str  
	delete []str;  
	new char,返回值是*char，一个指针。  
  
	int *p = new int;  
	*p = 0;   
	cout<<"hello"<<p<<endl;   
	delete p;  
  
23.引用  
	int &b = a;//a改变，b也变；b改变，a也变。  
	void abc(int &a,int &b);  
	{  
		temp = a;  
		a = b;  
		b = temp;  
	}  
	abc(x,y)//交换x,y  
  
	void abc(const *p)//不希望p内容被改变。   
24.对象   
（1）private类型：  
	外部不能访问和修改，只能通过调用内部public函数修改访问。   
	用途：一旦private类型改变，不需要满程序找相关地方，只需要更改内部调用函数。   
（2）构造函数    
	class Complex   
	{  
	private：（参数缺省则默认为private）    
		real;imag   
	public:   
		Complex(int a,int b = 0)	  
	}   
	Complex::Complex(int a,int b)   
	{   
		real = a;imag = b;   
	}    
   
	使用：Complex a1(10);   
