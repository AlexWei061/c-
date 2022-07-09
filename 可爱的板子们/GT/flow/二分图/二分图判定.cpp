#include<bits/stdc++.h>
using namespace std;
 
#define MAXN 100100
#define MAXM 2 * MAXN
 
int n = 0; int m = 0;
 
int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
 
void add(int x, int y){                             // �ڽӱ� ûʲô��˵�� 
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
}
 
int color[MAXN] = { 0 };
 
bool dfs(int x, int c){                             // ���԰ѽڵ� x Ⱦ�� c �������Ƿ�Ⱦɫ�ɹ� 
	color[x] = c;                                   // Ⱦɫ
	for(int e = first[x]; e; e = nxt[e]){
		int y = to[e];
		if(color[y] == c){
			return false;                           // ����ȥ�ĵ���������ɫ��ͬ Ⱦɫʧ�� 
		}
		if(color[y] == 0 and !dfs(y, -c)){
			return false;                           // ������ڵĽڵ�û�б�Ⱦɫ ���Ǹ���Ⱦ�Ϻ��Լ��෴����ɫȴʧ���� ��Ⱦɫʧ�� 
		}
	} 
	return true;                                    // Ⱦɫ�ɹ�  
}
 
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		add(x, y);
		add(y, x);
	}
	
	for(int i = 1; i <= n; i++){
		if(color[i] == 0){                          // ���û��Ⱦɫ      
			if(!dfs(i, 1)){
				printf("NO\n");                     // Ⱦɫ���ɹ� ˵�����Ƕ���ͼ 
				return 0;
			} 
		}
	}
	printf("YES\n");                                // ���е㶼Ⱦɫ�ɹ� ˵���Ƕ���ͼ 
	return 0;
}
