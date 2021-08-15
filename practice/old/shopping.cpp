#include<bits/stdc++.h>
using namespace std;

/*
��������
RainieҪȥ���Rainie��ÿһ����Ʒ��ÿ����Ʒֻ��һ�������в�ͬ�ĸ��˳̶ȣ����˳̶��ܹ���
�ӣ��������п���ʹ�������ֵ���Ʒ�Ứ�Ѹ����Ǯ�������ܹ�����Ǯֻ�У�Rainie�ͺ��������
������һ������Щ����������������ء�

�����ʽ
��һ������������������Ʒ�������ܹ���Ǯ��
�ڶ��������У�ÿ�а���������������Ʒ �ļ۸� ���Լ���Ʒ���˶� ��

�����ʽ
��������У�
��һ�а���һ����������Rainie����ܻ�õĸ��˶ȣ�
�ڶ��д�С�������ʹ��Rainie��������˶ȵ���Ʒ��ţ���Ʒ���Ϊ����ʱ��˳�򣩡�
*/

int M = 0;
int N = 0;
int p[1001] = { 0 };
int w[1001] = { 0 };
int v[1001][10001] = { 0 };

void kanspsack01(int v[][10001], int p[], int w[]){
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= M; j++){
            if(i == 0 or j == 0){
                v[i][j] = 0;
            }
            else if(w[i] <= j){
                v[i][j] = max(v[i - 1][j], v[i - 1][j - w[i]] + p[i]);
            }
            else{
                v[i][j] = v[i - 1][j];
            }
        }
    }
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 0; i < N; i++){
		scanf("%d%d", &w[i + 1], &p[i + 1]);
	}
    kanspsack01(v, p, w);
    int i = N;
    int j = M;
    int bp = v[N][M];
    cout << endl << v[N][M] << endl;
    //int temp[100] = { 0 }; 
    //int qwe = 0;
    priority_queue <int, vector<int>,greater<int> > temp;
	while(i > 0 and j >= 0){
        if(v[i][j] == v[i - 1][j]){
            i--;
        }
        else{
            //cout << i << " "; 
            temp.push(i);
            j -= w[i];
            i--;
        }
    }
    /*
    for(int i = 100; i >= 0; i--){
    	if(temp[i] != 0){
    		cout << temp[i] << " ";
		}
	}
	*/ 
	while(!temp.empty()){
		printf("%d%c", temp.top(), ' ');
		temp.pop();
	}
    return 0;
}
