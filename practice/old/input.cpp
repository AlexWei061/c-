#include <iostream>
#include<String>
using namespace std;

class InputOutput {                                                                                       //class IO
public:
	int inum;                                                                                    //����integer num
	double dnum;                                                                                 //����doubel num
	bool is;                                                                                     //����bool ����
	char c;                                                                                      //�����ַ�����
	char str[1000];                                                                              //�����ַ�������
};

class Print : public InputOutput {                                                               //class Print�̳���IO
public:
	void print() {}
	template<typename T, typename ...Types>
	inline void print(const T arg, const Types& ...args) {
		cout << arg << " ";
		print(args...);
	}
};

class Input : public InputOutput {                                                                //class Input�̳���IO
public:
	int inputint(string str) {                                                                    //����һ������
		cout << str;
		inum = 0;                                                                                 //�洢�����
		bool is_negative = false;                                                                 //�Ƿ�Ϊ����
		char c;                                                                                   //��ǰ�ַ�
		c = cin.get();
		while ((c < '0' or c > '9') and c != '-') {                                               //���벻��Ҫ���ַ�
			c = cin.get();
		}
		if (c == '-') {                                                                           //�ж��Ƿ�Ϊ����
			is_negative = true;                                                                   //�洢
		}
		else {
			inum += c - '0';                                                                      //��Ϊ������0 num += Ҫ�������ֵĵ�һλ
		}
		c = cin.get();
		while (c >= '0' and c <= '9') {                                                           //����ʣ�µ�λ��
			inum = (inum * 10) + c - '0';                                                         //num = (num * 10) + c�����������
			c = cin.get();                                                                        //����c
		}
		if (is_negative == true) {                                                                //����Ǹ���
			inum *= -1;                                                                           //num *= -1
			return inum;
		}
		else {
			return inum;
		}
	}

	char inputchar(string str) {                                                                   //�����ַ�
		cout << str;
		c = cin.get();                                                                       
		return c;
	}

};

Input inputer;
Print printer;

int main()
{
	int n = 0;
	n = inputer.inputint("Please input an intger:");
	printer.print(n);
	return 0;
}
