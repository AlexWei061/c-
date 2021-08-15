#include<bits/stdc++.h>
using namespace std;

/*
��������
����ʦ������μ�һ����ᣬ���ڳ��У�������ʦ��ǰ�����ĳ���Ϊ,�������кܶ���У���
Щ����֮��û��ֱ��������·����Щ����֮����ֱ��������·����Щ·����˫��ģ���ȻҲ�����ж�
����
���ڸ���ֱ�����ڳ��е�·���ȣ�����ʦ��֪���ӳ��е����У���̶��پ��롣

�����ʽ
����n��m����ʾ�����к���·;
�������У�ÿ�У� ��ʾ����������г���Ϊ��·��

�����ʽ
����������·��������ﲻ�ˣ������-1��
*/

#define INFI 65535

int N = 0;
int M = 0;
int gragh[][2001] = { 0 };
int     l[2001] =   { 0 };
bool is_s[2001] =   { false };

void initialize(int gragh[][2001], int l[]){
    for(int k = 2; k <= N; k++){
        if(gragh[1][k] != 0){
            l[k] = gragh[1][k];
        }
        else{
            l[k] = INFI;
        }
    }
}

void dijkstra(int gragh[][2001], int l[], bool is_s[]){
    initialize(gragh, l);
    for(int i = 1; i <= N; i++){
        int mmin = 0;
        int minn = 65535;
        if(is_s[i] == false){
            if(minn > l[i]){
                mmin = i;
            }
        }
        for(int j = 1; j <= N; j++){
            if(gragh[mmin][j] != 0 and gragh[mmin][j] + l[mmin] < l[j]){
                l[j] = gragh[mmin][j] + l[mmin];
            }
        }
    }
}

int main(){
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++){
		int a = 0;
		int b = 0;
		int c = 0;
		scanf("%d%d%d",&a, &b, &c);
		gragh[a][b] = c;
		gragh[b][a] = c;
	}
    dijkstra(gragh, l, is_s);
    if(l[N] == INFI){
    	printf("%d", -1);
	}else{
		printf("%d", l[N]);	
	}
    cout << endl;
    return 0;
}
