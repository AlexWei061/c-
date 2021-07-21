#include<bits/stdc++.h>
using namespace std;

const int px[5] = { 0, 0, 1,  0, -1 };
const int py[5] = { 0, 1, 0, -1,  0 };

int r = 0;
int c = 0;
int maze[100][100] = { 0 };

struct qNode{
	int x;
	int y;
	int depth;
}q[1010];

int head = 0;
int tail = 0;

void expand(int xx, int yy, int step){
	for(int i = 1; i <= 4; i++){
		int nx = xx + px[i];
		int ny = yy + py[i];
		if(maze[nx][ny] == 0 /*���Լ�����*/ and (nx >= 1 and nx <= r and ny >= 1 and ny <= c) /*��Խ��*/ ){
			q[tail].x = nx;                      //��չ���ڵ� 
			q[tail].y = ny;
			q[tail].depth = step + 1;
			tail++;
			maze[nx][ny] = 1;                   //����߹� 
		}
	}
}

int bfs(int xx, int yy){
	head = 1;                           //�����ÿ� 
	tail = 1; 
	/*������-----------*/
	q[tail].x = xx;
	q[tail].y = yy;
	q[tail].depth = 1;
	printf("q[tail].x = %d q[tail].y = %d q[tail].depth = %d\n", q[tail].x, q[tail].y, q[tail].depth);
	tail++;
	printf("%d\n", tail);
	/*------------------*/
	while(head != tail){                //���в�Ϊ�� 
		int i = q[head].x;              //������� 
		int j = q[head].y;
		int step = q[head].depth;
		printf("i = %d j = %d step = %d\n", i, j, step);
		head++;                         //ɾ������
		printf("%d\n", head);
		if(i == r and j == c){          //�����յ������ 
			return step;
		}
		else{                           //δ�����յ������չ 
			expand(i, j, step); 
		} 
	}
	return -1;                          //while��û��return˵���޷������յ� 
}

int main(){
	scanf("%d%d", &r, &c);
	for(int i = 1; i <= r; i++){
		for(int j = 1; j <= c; j++){
			scanf("%d", &maze[i][j]);
		}
	}
	
	printf("%d", bfs(1, 1));
	
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


