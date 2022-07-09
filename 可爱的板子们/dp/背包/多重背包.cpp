#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010

int n = 0; int m = 0;
int   w[MAXN] = { 0 };
int   c[MAXN] = { 0 };
int   x[MAXN] = { 0 };
int   f[MAXN] = { 0 };
int num[MAXN] = { 0 };

int multiKnapsack(int n, int m){
	for(int i = 1; i <= n; i++){
		memset(num, 0, sizeof(num));
		for(int j = w[i]; j <= m; j++){
			if(f[j] < f[j-w[i]] + c[i] and num[j-w[i]] < x[i]){
				f[j] = f[j-w[i]] + c[i];
				num[j] = num[j-w[i]] + 1;
			}
		}
	}
	return f[m];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &w[i], &c[i], &x[i]);
	}

	printf("%d\n", multiKnapsack(n, m));

	return 0;
}

/*

���� n ����Ʒ��ÿ����Ʒ��һ������ Wi��һ����ֵ Ci����ÿ����Ʒ�����������Դ���
1 ���������Ƶģ��� i ����Ʒ�� Xi����

ͬʱ��һ���������������Ϊ M������ڲ�������������������£���η�����Ʒ��
����ʹ�÷��뱳������Ʒ�ļ�ֵ�����

4 12
2 5 2
3 3 3
4 5 1
7 9 6

19

*/
