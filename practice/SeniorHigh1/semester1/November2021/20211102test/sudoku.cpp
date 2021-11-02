#include<bits/stdc++.h>
using namespace std;
#define in read()

inline int read(){
	int x = 0; char c = getchar();
	while(c < '0' or c > '9') c = getchar();
	while('0' <= c and c <= '9'){
		x = x * 10 + c - '0';
		c = getchar();
	}
	return x;
}

int t = 0;
int mmap[15][15][110] = { 0 };

struct Tpos{
	int x, y;
};
Tpos findNine(int x, int y){                                                    // �鵽ÿ���Ź����� 
	if((1 <= x and x <= 3) and (1 <= y and y <= 3)) return (Tpos){1, 1};
	if((1 <= x and x <= 3) and (4 <= y and y <= 6)) return (Tpos){1, 4};
	if((1 <= x and x <= 3) and (7 <= y and y <= 9)) return (Tpos){1, 7};
	
	if((4 <= x and x <= 6) and (1 <= y and y <= 3)) return (Tpos){4, 1};
	if((4 <= x and x <= 6) and (4 <= y and y <= 6)) return (Tpos){4, 4};
	if((4 <= x and x <= 6) and (7 <= y and y <= 9)) return (Tpos){4, 7};
	
	if((7 <= x and x <= 9) and (1 <= y and y <= 3)) return (Tpos){7, 1};
	if((7 <= x and x <= 9) and (4 <= y and y <= 6)) return (Tpos){7, 4};
	if((7 <= x and x <= 9) and (7 <= y and y <= 9)) return (Tpos){7, 7}; 
}

void Insert(int t, int x, int y, int k){
	if(mmap[x][y][t]){                                                  // �Ѿ������� 
		mmap[x][y][t+1] = mmap[x][y][t];
		printf("Error!\n");
	}
	else{                                                               // ��û�� 
		bool is = false;                                                // ��¼ʱ�Ƿ��ͻ 
		for(int i = 1; i <= 9; i++){                                    // �ж��г�ͻ 
			if(i != y)
				if(mmap[x][i][t] == k){
					is = true;
					mmap[x][y][t+1] = mmap[x][y][t];
					printf("Error:row!\n");
				}
		}
		for(int i = 1; i <= 9; i++){                                    // �ж��г�ͻ 
			if(is) break;
			if(i != x)
				if(mmap[i][y][t] == k){
					is = true;
					mmap[x][t][t+1] = mmap[x][y][t];
					printf("Error:column!\n");	
				}
		}
		Tpos p = findNine(x, y); int a = p.x, b = p.y;
		for(int i = a; i <= a + 2; i++){                                // �жϾŹ����ͻ 
			if(is) break;
			for(int j = b; j <= b + 2; j++)
				if(!(i == x and j == y))
					if(mmap[i][j][t] == k){
						is = true;
						mmap[x][y][t+1] = mmap[x][y][t];
						printf("Error:square!\n");	
					}
		}
		if(!is) { mmap[x][y][t+1] = k; printf("OK!\n"); }               // û�г�ͻ 
	}
	for(int i = 1; i <= 9; i++)
		for(int j = 1; j <= 9; j++)
			if(!(i == x and j == y))
				mmap[i][j][t+1] = mmap[i][j][t];
}

void Delete(int t, int x, int y){
	if(!mmap[x][y][t]){                                                 // û�� 
		mmap[x][y][t+1] = mmap[x][y][t];
		printf("Error!\n");
	}
	else{                                                               // ���� ɾ�� 
		mmap[x][y][t+1] = 0;
		printf("OK!\n");
	}
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++)
			if(!(i == x and j == y))
				mmap[i][j][t+1] = mmap[i][j][t];
	}
}

void Query(int t, int x, int y){
	map<int, int> s;                                                    // ��¼ÿ�������ֵĴ��� 
	if(mmap[x][y][t]) printf("Error!\n");                               // ���� 
	else{                                                               // û�� 
		for(int i = 1; i <= 9; i++){                                    // ��¼���ϵ��� 
			s[mmap[x][i][t]]++;
		}
		for(int i = 1; i <= 9; i++){                                    // ��¼���ϵ��� 
			s[mmap[i][y][t]]++;
		}
		Tpos p = findNine(x, y); int a = p.x; int b = p.y;
		for(int i = a; i <= a + 2; i++){                                // ��¼�Ź�������� 
			for(int j = b; j <= b + 2; j++)
				s[mmap[i][j][t]]++;
		}
		int cnt = 0;                                                    // ��¼ǰ����ִ���Ϊ 0 ����Ҳ���ǿ�������������� 
		for(int i = 1; i <= 9; i++) if(!s[i]) cnt++;
		printf("%d\n", cnt);
		for(int i = 1; i <= 9; i++) if(!s[i]) printf("%d\n", i);        // ������������ 
	}
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++)
			mmap[i][j][t+1] = mmap[i][j][t];
	}
}

bool isCogTu(int t, int x, int y, int k){                               // �ж��Ƿ��ͻ 
	bool is = false;
	for(int i = 1; i <= 9; i++){                                        // ���ϳ�ͻ 
		if(i != k)
			if(mmap[x][i][t+1] == k) is = true;
	}
	for(int i = 1; i <= 9; i++){                                        // ���ϳ�ͻ 
		if(is) break;
		if(i != k)
			if(mmap[i][y][t+1] == k) is = true;	
	}
	Tpos p = findNine(x, y); int a = p.x, b = p.y;
	for(int i = a; i <= a + 2; i++){                                    // �Ź����ͻ 
		if(is) break;
		for(int j = b; j <= b + 2; j++)
			if(!(i == x and j == y))
				if(mmap[i][j][t+1] == k) is = true;
	}
	return is;
}

void Merge(int t, int a, int b){
	a++; b++; int cnta = 0; int cntb = 0;
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			if(mmap[i][j][a]){                                          // a ������ 
				if(!isCogTu(t, i, j, mmap[i][j][a])){                   // a ����ͻ
					mmap[i][j][t+1] = mmap[i][j][a]; cnta++;
				}
				else{                                                   // a ��ͻ 
					if(mmap[i][j][b]){                                  // b ���� 
						if(!isCogTu(t, i, j, mmap[i][j][b])){           // b ����ͻ 
							mmap[i][j][t+1] = mmap[i][j][b]; cntb++;
						}
						else                                            // b ��ͻ 
							mmap[i][j][t+1] = 0;
					}
					else                                                // b ���� 
						mmap[i][j][t+1] = 0;	
				} 
			}
			else{                                                       // a ������ 
				if(mmap[i][j][b]){                                      // b ���� 
					if(!isCogTu(t, i, j, mmap[i][j][b])){               // b ����ͻ 
						mmap[i][j][t+1] = mmap[i][j][b]; cntb++;
					}
					else                                                // b ��ͻ 
						mmap[i][j][t+1] = 0;
				}
				else                                                    // b ���� 
					mmap[i][j][t+1] = 0;
			}
		}
	}
	printf("%d %d\n", cnta, cntb);
}

void Print(int t){
	for(int i = 1; i <= 9; i++){
		printf("+-");
	} printf("+\n");
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			if(j == 1) printf("|");
			printf("%d|", mmap[i][j][t]);
		} puts("");
		for(int j = 1; j <= 9; j++){
			printf("+-");
		} printf("+\n"); 
	}
	
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++)
			mmap[i][j][t+1] = mmap[i][j][t]; 
	}
} 

int main(){
	for(int i = 1; i <= 9; i++){
		for(int j = 1; j <= 9; j++){
			mmap[i][j][1] = in;
		}
	}
	t = in;
	for(int i = 1; i <= t; i++){
		char op[10]; scanf("%s", op);
		if(op[0] == 'I'){
			int x = in, y = in, k = in;
			Insert(i, x, y, k);
		}	
		else if(op[0] == 'D'){
			int x = in, y = in;
			Delete(i, x, y);
		}
		else if(op[0] == 'Q'){
			int x = in, y = in;
			Query(i, x, y);
		}
		else if(op[0] == 'M'){
			int a = in, b = in;
			Merge(i, a, b);
		}
		else if(op[0] == 'P'){
			Print(i);
		}
	}
	return 0;
}
