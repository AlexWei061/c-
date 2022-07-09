#include<bits/stdc++.h>
using namespace std;
#define MAXN 10010

int n = 0; int m = 0;
int x[MAXN] = { 0 };
int w[MAXN][MAXN] = { 0 };
int c[MAXN][MAXN] = { 0 };
int f[MAXN] = { 0 };

int groupKnapsack(int n, int m){
	for(int i = 1; i<= n; i++){
		for(int j = m; j >= 0; j--){
			for(int k = 1; k <= x[i]; k++){
				if(j > w[i][k]){
					f[j] = max(f[j], f[j-w[i][k]] + c[i][k]);
				}
			}
		}
	}
	return f[m];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d\n", &x[i]);
		for(int j = 1; j <= x[i]; j++){
			scanf("%d%d", &w[i][j], &c[i][j]);
		}
	}

	printf("%d\n", groupKnapsack(n, m));

	return 0;
}

/*

���� n ����Ʒ���� i ���� Xi����Ʒ���� i ��ĵ� j ����Ʒ������ Wij ��һ����ֵ Cij ��
ͬʱ��һ���������������Ϊ M���ڲ�������������������£�ÿ�����ѡ��һ����
Ʒ���������η�����Ʒ������ʹ�÷��뱳������Ʒ�ļ�ֵ�����

4 12
2 5 2 3 6
3 1 3 2 5 5 3
4 5 1 2 7 6 8 3 6
6 9 6 10 3 2 10 7 12 11 11 4 20

38

*/

