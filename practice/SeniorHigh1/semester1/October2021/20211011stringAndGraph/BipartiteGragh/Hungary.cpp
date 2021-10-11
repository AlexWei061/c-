#include<bits/stdc++.h>
using namespace std;

#define MAXN 10010

/* �������㷨 ����ͼ���ƥ�� */

int k = 0;                                  // �ܱ��� 
int n = 0; int m = 0;                       // nΪ X ���еĽڵ��� m Ϊ Y ���жȽڵ��� 

int edge[MAXN][MAXN] = { 0 };
int  used[MAXN] = { 0 };
int match[MAXN] = { 0 };

bool dfs(int x){
	for(int i = 1; i <= m; i++){
		if(edge[x][i] and !used[i]){              // ����б���û�б�ѡ��� 
			used[i] = 1;                          // ��Ǳ�ѡ��� 
			if(!match[i] or dfs(match[i])){       // ���û�б�ƥ��� ���� ƥ�����Ļ����ܹ�ƥ�䵽�� 
				match[i] = x;                     // ��Ǳ� x ƥ����
				return 1;                         // ƥ��ɹ� 
			}
		}
	}
	return 0;                                     // ƥ��ʧ�� 
}

int main(){
	scanf("%d", &k);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= k; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		edge[x][y] = 1;                     // x �� y ��һ���� x -> y
	}
	
	int sum = 0;                            // ���ƥ��
	for(int i = 1; i <= n; i++){
		memset(used, 0, sizeof(used));      // ÿһ����� used ����
		if(dfs(i)){
			sum++;
		} 
	} 
	
	printf("%d\n", sum);
	return 0;
}
