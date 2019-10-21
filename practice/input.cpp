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

class Print : public InputOutput {                                                                        //class Print�̳���IO
public:
	void print() {}
	template<typename T, typename ...Types>
	inline void print(const T arg, const Types& ...args) {
		cout << arg << " ";
		print(args...);
	}
};

class Input : public InputOutput {                                                                         //class Input�̳���IO
public:
	int inputint() {                                                                              //����һ������
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
			inum += c - '0';                                                                       //��Ϊ������0 num += Ҫ�������ֵĵ�һλ
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

	char inputchar() {                                                                             //�����ַ�
		c = cin.get();                                                                       
		return c;
	}
	char* inputstring() {
		int c = cin.get();
		int i = 0;
		while (c >= 33 and c <= 125) {
			str[i] = c;
			c = cin.get();
		}
		return str;
	}
};

Input inputer;
Print printer;

int main()
{
	char c;
	int num = 0;
	num = inputer.inputint();
	c = inputer.inputchar();
	printer.print(num,c);
	return 0;
}
