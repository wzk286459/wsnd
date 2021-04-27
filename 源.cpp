#include<math.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
float pi = 3.14;
class jisuan
{
public:
	int factor();                   //读入一个因子并返回其值
	int term();                     //读入一项并返回其值  ’*‘ ’/‘
	int expression();               //读入一个表达式并返回其值
};
int jisuan::expression() {
	int result = term();               //求第一项的值
	bool more = true;                  //布尔变量返回值
	while (more) {
		char op = cin.peek();          //cin.peek()返回值为char型字符（指针指向的当前字符），读取不删除
		if (op == '+' || op == '-') {
			cin.get();               //从输入中取走一个字符
			int value = term();
			if (op == '+')
				result += value;
			else
				result -= value;
		}
		else
			more = false;
	}
	return result;
}
int jisuan::term() {                 //求一个项的值
	int result = factor();             //求第一个因子的值
	while (true) {
		char op = cin.peek();
		if (op == '*' || op == '/') {
			cin.get();
			int value = factor();
			if (op == '*')
				result *= value;
			else
				result /= value;
		}
		else
			break;
	}
	return result;
}
int jisuan::factor() {
	int result = 0;
	char c = cin.peek();
	if (c == '(') {
		cin.get();
		result = expression();
		cin.get();
	}
	else {
		while (isdigit(c)) {              //isdigit判断字符型是否为数字
			result = 10 * result + c - '0';     //-'0'字符型转为数字
			cin.get();
			c = cin.peek();
		}
	}
	return result;
}
class pk
{
public:
	void pingfang(int p);
	void kaifang(int p);
};
void pk::pingfang(int p)
{
	cout << p * p;
}
void pk::kaifang(int p)
{
	cout << sqrt(p);
}
class sanjiaohanshu
{
public:
	void s(int p);
	void c(int p);
	void t(int p);
};
void sanjiaohanshu::s(int p)
{
	cout << sin(pi * p / 180);
}
void sanjiaohanshu::c(int p)
{
	cout << cos(pi * p / 180);
}
void sanjiaohanshu::t(int p)
{
	cout << tan(pi * p / 180);
}
class erjinzhi
{
public:
	void show(int p);
};
void erjinzhi::show(int p)
{
	int i, j = 0, k;
	int a[100];
	for (i = 0; p > 1; i++)
	{
		a[i] = p % 2;
		p = p / 2;
	}
	j = i;
	for (k = j; k > 0; k--)
	{
		cout << a[k];
	}
}
void caidan()
{
	cout << "继续运算" << endl;
	cout << "1.求平方" << endl;
	cout << "2.求开方" << endl;
	cout << "3.求三角函数" << endl;
	cout << "4.转化为二进制" << endl;
	cout << "5.结束" << endl;
}
void sanjiaohanshucaidan()
{
	cout << "1.sin" << endl;
	cout << "2.cos" << endl;
	cout << "3.tan" << endl;
}
void cd()
{
	cout << "1.继续运算" << endl;
	cout << "2.结束" << endl;
}
void c()
{

}
int main() {
	void caidan();
	void sjhscaidan();
	void cd();
	jisuan js;
	pk p;
	sanjiaohanshu sjhs;
	erjinzhi e;
	int x, a, t, q;
	cout << "欢迎使用科学计算器" << endl;
	cout << "请输入(四则运算）：" << endl;
	cout << js.expression() << endl;
	caidan();
	cin >> x;
	if (x == 1)
	{
		cout << "请输入：" << endl;
		cin >> t;
		p.pingfang(t);
		cout << endl;
	}
	else if (x == 2)
	{
		cout << "请输入：" << endl;
		cin >> t;
		p.kaifang(t);
	}
	else if (x == 3)
	{
		sanjiaohanshucaidan();
		cin >> a;
		if (a == 1)
		{
			cout << "请输入：" << endl;
			cin >> t;
			sjhs.s(t);
		}
		else if (a == 2)
		{
			cout << "请输入：" << endl;
			cin >> t;
			sjhs.c(t);
		}
		else if (a == 3)
		{
			cout << "请输入：" << endl;
			cin >> t;
			sjhs.t(t);
		}
		else
			cout << "请重新输入";
	}
	else if (x == 4)
	{
		cout << "请输入：" << endl;
		cin >> t;
		e.show(t);
	}
	else if (x == 5)
	{
		cout << "请输入：" << endl;
		cin >> t;
		return 0;
	}
	else
	{
		cout << "请重新输入";
	}
	return 0;
}