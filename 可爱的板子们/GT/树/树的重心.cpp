#include<bits/stdc++.h>
using namespace std;
 
#define INFI 1 << 20
#define MAXN 100100
#define MAXM 2 * MAXN
 
int n = 0; int m = 0;
 
int tot = 0;
int first[MAXN] = { 0 };
int   nxt[MAXM] = { 0 };
int    to[MAXM] = { 0 };
 
void add(int x, int y){
	nxt[++tot] = first[x];
	first[x] = tot; to[tot] = y;
} 
 
bool vis[MAXN] = { 0 };
int size[MAXN] = { 0 };
int ans = INFI; int pos = 0;
 
void dfs(int x){
	vis[x] = 1;                                   // x �����ʹ� 
	size[x] = 1;                                  // ���� x �Ĵ�С
	int max_part = 0;                             // ɾ�� x ��ɷֵ����������С
	for(int e = first[x]; e; e = nxt[e]){
		int y =to[e];
		if(vis[y]){
			continue;
		}
		dfs(y);
		size[x] += size[y];                       // ���ӽڵ��򸸽ڵ����
		max_part = max(max_part, size[y]); 
	} 
	max_part = max(n - size[x], max_part);        // n Ϊ�������Ľڵ�����
	if(max_part < ans){
		ans = max_part;                           // ans ��¼���Ķ�Ӧ�� max_part��ֵ 
		pos = x;                                  // pos ��¼���� 
	} 
}
 
int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	
	dfs(1);
	
	printf("pos = %d ans = %d\n", pos, ans);
	 
	return 0;
}
