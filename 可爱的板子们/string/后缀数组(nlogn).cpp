// ��Ϊ FSYo ���еĴ�����ע���Ҿ�ֱ�ӷŹ�����
#include<bits/stdc++.h>
using namespace std;
#define MAXN 1000050

int n = 0; int m = 0;
char s[MAXN];                                          // ԭ��
int x[MAXN] = { 0 };                                   // ����ʱ��Ҫ��
int y[MAXN] = { 0 };
int tmp[MAXN] = { 0 };
int c[MAXN] = { 0 };                                   // ����ʱ��Ͱ
int SA[MAXN] = { 0 };

void Sort(){
	for(int i = 1; i <= m; i++) c[i] = 0;
	for(int i = 1; i <= n; i++) c[x[i]]++;
	for(int i = 2; i <= m; i++) c[i] += c[i - 1]; 
	/* c[i] ��ǰ׺�� , ��ʾ�Ե�һ�ؼ����ŵ��ڼ��� 
	������ 3��a , 2��b , ��ô��һ�ؼ���Ϊ b �ĵڶ��ؼ������ľ��ǵ� 5�� */ 
	for(int i = n; i >= 1; i--) SA[c[x[y[i]]]--] = y[i];
	// ���ŰѴ�b��Ͱ��һ�� ,  ��һ�ؼ���Ϊ b �ĵڶ��ؼ��ֵڶ���ľ��ǵ� 4�� 
}

void getSA(){
	//y[i] ��ʾ�ڶ��ؼ���Ϊ��i�����ڵĺ�׺λ�� 
	for(int i = 1; i <= n; i++) x[i] = s[i] , y[i] = i;
	Sort();
	for(int k = 1; k <= n; k <<= 1){
		int cnt = 0; // y �����±�
		for(int i = n - k + 1; i <= n; i++) y[++cnt] = i; // ���ұ�һ��ĵڶ��ؼ���Ϊ 0
		for(int i = 1; i <= n; i++) if(SA[i] > k) y[++cnt] = SA[i] - k;
		/*����Ϊ i ���� ���������Ƿ��ڵ�kλ�Ժ�
		������� (sa[i] > k) ��ô��������Ϊ���˵ĵڶ��ؼ��֣��Ͱ����ĵ�һ�ؼ��ֵ�λ����ӽ� y ������*/
		Sort(); swap(x, tmp); x[SA[1]] = 1; int num = 1;
		for(int i = 2; i <= n; i++){
			if(tmp[SA[i]] == tmp[SA[i - 1]] and tmp[SA[i] + k] == tmp[SA[i - 1] + k])
			// ��һ���ؼ��ֶ���ͬ 
				x[SA[i]] = num;
			else x[SA[i]] = ++num;
		} m = num; 
	}
}
int main(){
	scanf("%s",s + 1);
	n = strlen(s + 1); m = 127;
	getSA();
	for(int i = 1; i <= n; i++) printf("%d ", SA[i]);
	return 0;
} 

��������������������������������
��Ȩ����������ΪCSDN������lAWTYl����ԭ�����£���ѭCC 4.0 BY-SA��ȨЭ�飬ת���븽��ԭ�ĳ������Ӽ���������
ԭ�����ӣ�https://blog.csdn.net/ID246783/article/details/123446790
