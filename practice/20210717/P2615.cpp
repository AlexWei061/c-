#include<bits/stdc++.h>
using namespace std;

struct Coordinate{
	int x;
	int y;
};

int n                   =   0  ;
int magicSquare[40][40] = { 0 };

Coordinate coor[1600]; 

void work(){                             //Ԥ����coor 
	magicSquare[1][n/2+1] = 1;
	coor[1].x = n / 2 + 1;
	coor[1].y = 1;
}

/*
�� (K-1)��һ�е��������һ�У��� K�������һ�У� (K-1)�����е���һ�У�
�� (K-1)�����һ�е����ڵ�һ�У��� K���ڵ�һ�У� (K-1)�����е���һ�У�
�� (K-1)�ڵ�һ�����һ�У��� K���� (K-1)�����·���
�� (K-1)�Ȳ��ڵ�һ�У�Ҳ�������һ�У���� (K-1)�����Ϸ���δ�������� K���� (K-1)�����Ϸ������� K���� (K-1)�����·���
*/ 

void adjustSquare(){
	int k = 2;                          //1���ô��� 
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(coor[k-1].y == 1 and coor[k-1].x != n){
				magicSquare[n][coor[k-1].x+1] = k;
				coor[k].x = coor[k-1].x + 1;
				coor[k].y = n;
			}
			else if(coor[k-1].x == n and coor[k-1].y != 1){
				magicSquare[coor[k-1].y-1][1] = k;
				coor[k].x = 1;
				coor[k].y = coor[k-1].y - 1;
			}
			else if(coor[k-1].x == n and coor[k-1].y == 1){
				magicSquare[coor[k-1].y+1][coor[k-1].x] = k;
				coor[k].x = coor[k-1].x;
				coor[k].y = coor[k-1].y + 1;
			}
			else if(coor[k-1].x != n and coor[k-1].y != 1){
				if(magicSquare[coor[k-1].y-1][coor[k-1].x+1] == 0){
					magicSquare[coor[k-1].y-1][coor[k-1].x+1] = k;
					coor[k].x = coor[k-1].x + 1;
					coor[k].y = coor[k-1].y - 1;
				}
				else{
					magicSquare[coor[k-1].y+1][coor[k-1].x] = k;
					coor[k].x = coor[k-1].x;
					coor[k].y = coor[k-1].y + 1;
				}
			}
			k++;
		}
	}
}

int main(){
	scanf("%d", &n);
	work();
	adjustSquare();
	/*
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", mmap[i][j]);
		}
		printf("\n");
	}
	
	for(int i = 1; i <= n*n; i++){
		printf("%d's x = %d y = %d\n", i, coor[i].x, coor[i].y);
	}
	*/
	
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", magicSquare[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
