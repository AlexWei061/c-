#include<bits/stdc++.h>
using namespace std;

int board[100] = { 0 };
int n = 0;

int a[100] = { 0 };                 //��a�б�ռ�õ����
int l[100] = { 0 };                 //����ĶԽ��߱�ռ�õ���� (ͬһ���Խ����Ϻ�������ĺ�Ϊ��ֵ: x+y = constant)
int r[100] = { 0 };                 //���ҵĶԽ��߱�ռ�õ���� (ͬһ���Խ����Ϻ�������Ĳ�Ϊ��ֵ: x-y = constant)

int ans = 0; 
 
void dfs(int x){              //��x�еĻʺ� 
	if(x > n){      //���лʺ��Ѿ����� 
		ans++;
		if(ans <= 3){              //����� 
			for(int i = 1; i <= n; i++){
				printf("%d ", board[i]);
			}
			puts("");
		}
		return;
	}
	
	for(int i = 1; i <= n; i++){                           //�ʺ��������y=i 
		int y = i;
		if(a[i] == 0 and l[x+y] == 0 and r[x-y+15] == 0){           //���������϶�û��ռ�� 
			board[x] = y;                                  //���ûʺ� 
			//����� 
			a[y] = 1;
			l[x+y] = 1;
			r[x-y+15] = 1;
			
			dfs(x + 1);        //�ݹ���һ��
			
			//ɾ���
			a[y] = 0;
			l[x+y] = 0;
			r[x-y+15] = 0;
		} 
	}
} 

int main(){
	scanf("%d", &n);
	dfs(1);
	printf("%d", ans);
	return 0;
} 
