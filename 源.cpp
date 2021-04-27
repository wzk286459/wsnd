#include<math.h>
#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
float pi = 3.14;
class jisuan
{
public:
	int factor();                   //����һ�����Ӳ�������ֵ
	int term();                     //����һ�������ֵ  ��*�� ��/��
	int expression();               //����һ�����ʽ��������ֵ
};
int jisuan::expression() {
	int result = term();               //���һ���ֵ
	bool more = true;                  //������������ֵ
	while (more) {
		char op = cin.peek();          //cin.peek()����ֵΪchar���ַ���ָ��ָ��ĵ�ǰ�ַ�������ȡ��ɾ��
		if (op == '+' || op == '-') {
			cin.get();               //��������ȡ��һ���ַ�
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
int jisuan::term() {                 //��һ�����ֵ
	int result = factor();             //���һ�����ӵ�ֵ
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
		while (isdigit(c)) {              //isdigit�ж��ַ����Ƿ�Ϊ����
			result = 10 * result + c - '0';     //-'0'�ַ���תΪ����
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
	cout << "��������" << endl;
	cout << "1.��ƽ��" << endl;
	cout << "2.�󿪷�" << endl;
	cout << "3.�����Ǻ���" << endl;
	cout << "4.ת��Ϊ������" << endl;
	cout << "5.����" << endl;
}
void sanjiaohanshucaidan()
{
	cout << "1.sin" << endl;
	cout << "2.cos" << endl;
	cout << "3.tan" << endl;
}
void cd()
{
	cout << "1.��������" << endl;
	cout << "2.����" << endl;
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
	cout << "��ӭʹ�ÿ�ѧ������" << endl;
	cout << "������(�������㣩��" << endl;
	cout << js.expression() << endl;
	caidan();
	cin >> x;
	if (x == 1)
	{
		cout << "�����룺" << endl;
		cin >> t;
		p.pingfang(t);
		cout << endl;
	}
	else if (x == 2)
	{
		cout << "�����룺" << endl;
		cin >> t;
		p.kaifang(t);
	}
	else if (x == 3)
	{
		sanjiaohanshucaidan();
		cin >> a;
		if (a == 1)
		{
			cout << "�����룺" << endl;
			cin >> t;
			sjhs.s(t);
		}
		else if (a == 2)
		{
			cout << "�����룺" << endl;
			cin >> t;
			sjhs.c(t);
		}
		else if (a == 3)
		{
			cout << "�����룺" << endl;
			cin >> t;
			sjhs.t(t);
		}
		else
			cout << "����������";
	}
	else if (x == 4)
	{
		cout << "�����룺" << endl;
		cin >> t;
		e.show(t);
	}
	else if (x == 5)
	{
		cout << "�����룺" << endl;
		cin >> t;
		return 0;
	}
	else
	{
		cout << "����������";
	}
	return 0;
}