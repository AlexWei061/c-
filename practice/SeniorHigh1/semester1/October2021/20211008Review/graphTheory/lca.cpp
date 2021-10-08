#include<bits/stdc++.h>
using namespace std;

#define SIZE 
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

int dep[MAXN] = { 0 };
int f[MAXN][35] = { 0 };

/* f[x][i] = f[f[x][i-1]][i-1], f[x][i] --> x �� 2^i ������ */ 
void prework(int u, int fa){
	dep[u] = dep[fa] + 1;
	for(int i = 0; i <= 30; i++){
		f[u][i + 1] = f[f[u][i]][i];
	}
	for(int e = first[u]; e; e = nxt[e]){
		int v = to[e];
		if(v != fa){
			f[v][0] = u;
			prework(v, u);
		}
	}
}

int queryLCA(int x, int y){
	if(dep[x] < dep[y]){
		swap(x, y);
	}
	for(int i = 30; i >= 0; i--){
		if(dep[f[x][i]] >= dep[y]){
			x = f[x][i];
		}
		if(x == y){
			return x;
		}
	}
	for(int i = 30; i >= 0; i--){
		if(f[x][i] != f[y][i]){
			x = f[x][i];
			y = f[y][i];
		}
	}
	return f[x][0];
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		int x = 0; int y = 0;
		scanf("%d%d", &x, &y);
		add(x, y);
	}
	
	prework(1, 0);
	
	printf("%d\n", queryLCA(4, 7));
	
	return 0;
}
