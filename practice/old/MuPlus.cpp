#include<bits/stdc++.h>
using namespace std;

 int Plus(int a, int b) {
	int ans = 0;                                    //�� 
	int al[10001] = { 0 };                          //�������������aװ���� 
	int bl[10001] = { 0 };                          //�������������aװ���� 
	int cl[10001] = { 0 };                          //װ�𰸵����� 
	int j = 0; 
	int k = 0;
	for (int i = 1; i < a; i *= 10) {               //��a����al�� 
		al[j] = (a / i) % 10;
		//cout << al[j] << ' ';
		j++;
	}
	for (int i = 1; i < b; i *= 10) {               //��b����bl�� 
		bl[k] = (b / i) % 10;
		//cout << bl[k] << ' ';
		k++;
	}
	int h = 0;
	while(al[h] != 0 || bl[h] != 0){                //��������� 
		cl[h] = al[h] + bl[h];
		if (cl[h] >= 10) {                          //��ʮ��һ 
			cl[h] -= 10;
			cl[h + 1] += 1;
		}
		//cout << cl[h] << ' ';
		h++;
	 }
	int i = h;
	do {                                            //������ת������ 
		ans = ans * 10 + cl[i];
		i--;
	}while(cl[i] != 0);
	
	return ans;                                     //���ش� 
}

int a = 0;
int b = 0;

int main(){
	cin >> a >> b;
	int c = Plus(a,b);
	cout << c;
}
