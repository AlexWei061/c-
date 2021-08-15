#include<bits/stdc++.h>
using namespace std;

#define INFI 63353

const int px[5] = { 0, 1, 0, -1,  0 };
const int py[5] = { 0, 0, 1,  0, -1 };
int way[25][25] = { 0 };

int n = 0;
int m = 0;
int maze[25][25] = { 0 };

int len = INFI;

void dfs(int step, int x, int y){
	int i, j;
	for(int k = 1; k <=4; k++){                 //4���������� 
		i = x + px[k];                          //���� 
		j = y + py[k];
		//�ж�
		if(((i >= 1 and i <= n) and ((j >= 1) and (j <= m)))/*��Խ��*/ and (maze[i][j] == 0) /*���ϰ�*/ and (way[i][j] == 0) /*û�߹�*/){
			//printf("i = %d j = %d\n", i, j);
			way[i][j] = 1;                     //����� 
			if((i == n) and (j == m)){         //���յ� 
				if(step < len){
					len = step;
					//printf("%d\n", step);
				}
			}
			else{                              //û���յ� 
				if(step < (len - 1)){          //��ʹstep<len 
					//printf("%d\n",step);
					dfs(step+1, i, j); 
				}
			}
			way[i][j] = 0;                     //ɾ��� 
		}
	}
}

int main(){
	//freopen("maze.in", "r", stdin);
	//freopen("maze.out", "w", stdout);
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			scanf("%d", &maze[i][j]);
		}
	}
	
	memset(way, 0, sizeof(way));
	way[1][1] = 1;
	//printf("%d\n", len);
	
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", maze[i][j]);
		}
		puts("");
	}
	puts("");
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			printf("%d ", way[i][j]);
		}
		puts("");
	}
	*/
	
	dfs(2, 1, 1);
	
	if(len == INFI){                           //lenû�б�����˵���Թ��޷��ߵ����� 
		printf("%d", -1);
	}
	else{
		printf("%d", len);
	}
	
	return 0;
}

/*

6 9
0 0 0 1 1 0 0 0 1
0 1 0 0 0 0 1 0 1
0 1 0 1 0 1 1 0 1
0 1 0 1 0 0 0 0 0
0 1 1 0 1 1 0 1 0
0 0 0 0 0 0 0 1 0

14

*/

