#include<bits/stdc++.h>
using namespace std;
#define MAXN 101 

int k = 0;                // 0 ʱ�̵�������¥�� 
int n = 0;                // ��˵���������� 
int p = 0;                // ����������� 

struct TElevator{
	int nfloor;
	bool ndire;
	int npopu;
	int maxpopu;
}elevator;

struct TRequest{
	int t;               // t ʱ�� 
	int s;               // �� s ���� 
	int d;               // ��Ҫ�� d 
}req[MAXN];

struct TRequests{
	queue<TRequest> q;
}floor[MAXN];                     // floor[i].q.front() �� i ��ĵ�һ������ 

bool upOrDown(){
	
}

int main(){
	freopen("elevator.in", "r", stdin);
	freopen("elevator.out", "w", stdout);
	scanf("%d%d%d", &k, &n, &p);
	elevator.maxpopu = p;
	for(int i = 1; i <= n; i++){
		scanf("%d%d%d", &req[i].t, &req[i].s, &req[i].d);
		floor[req[i].s].push(req[i]);
	}
	for(int i = 1; i <= 10; i++){
		printf("Floor %d : \n", i);
		while(!floor[i].q.empty()){
			TRequest node = floor[i].q.front();
			floor[i].q.pop();
			printf("  t = %d s = %d t = %d\n", node.t, node.s, node.d);
		}
		puts("");
	}
	return 0;
}
