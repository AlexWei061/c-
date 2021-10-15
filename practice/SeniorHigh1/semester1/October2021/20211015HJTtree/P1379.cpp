#include<bits/stdc++.h>
using namespace std;

const int px[4] = { 1, 0, -1, 0 };
const int py[4] = { 0, 1, 0, -1 };

int n = 8;
char s[20];
int x = 0; int y = 0;                               // 0 ������ 
string goal = "123804765";

int h(string current){                              // ����λ�ú�Ŀ��λ���м���λ���ǲ�ͬ�� (��������) 
	int ans = 0;
	for(int i = 0; i < 9; i++){
		if(goal[i] != current[i] and goal[i] != 0) ans++;
	}
	return ans;
}  

struct Tnode{  
    int f, step;                                    // ��ǰ����������ֵ���ߵĲ��� 
    string now;                                     // ��ǰ���� 
	bool operator < (const Tnode &x) const {  
        return step + f > x.step + x.f;             // �Ե�ǰ��������������������        
    }  
};

int ans = 0x7fffffff; 
priority_queue<Tnode> q;
map<string, int>  dis;
map<string, bool> way;

void bfs(char s[]){
	way[s] = 1; dis[s] = 0;
	q.push((Tnode){h(s), 0, s});                    // ������ 
	while(!q.empty()){
		Tnode t = q.top(); q.pop();
		string cur = t.now;
		if(cur == "123804765"){
			printf("%d\n", t.step);
			exit(0);
		}
		int tx = 0; int ty = 0;
		for(int i = 0; i < 9; i++){                                    //  ��ǰ���� 0 ��λ�� 
			if(cur[i] - '0' == 0){
				tx = i / 3 + 1; ty = i % 3 + 1; 
			}
		}
		int idx1 = (tx - 1) * 3 + ty - 1;                              // ��һά�����е�λ��
		for(int i = 0; i < 4; i++){                                    // ��չ 
			int nx = tx + px[i]; int ny = ty + py[i];
			if(nx < 1 or nx > 3 or ny < 1 or ny > 3) continue;
			int idx2 = (nx - 1) * 3 + ny - 1;                          // ��չ֮���λ�� 
			swap(cur[idx1], cur[idx2]);
			if(!way[cur] or (way[cur] and (t.step + 1) < dis[cur])){
				dis[cur] = t.step + 1;
				q.push((Tnode){h(cur), t.step + 1, cur});
				way[cur] = 1;
			} 
			swap(cur[idx1], cur[idx2]);
		} 
	} 
}

int main(){
	scanf("%s", s);
	for(int i = 0; i < 9; i++){
		if(s[i] - '0' == 0){
			x = i / 3 + 1; y = i % 3 + 1;           // 0 �ĳ�ʼ���� 
		}
	}
	if(h(s) == 0){                                  // ��ʼ״̬��Ŀ��״̬ ��ֱ�ӷ��� 
		printf("%d\n", 0);
		return 0; 
	}
	while(!q.empty()) q.pop();
	bfs(s);                                         // ��ʼ���� 
	return 0;
}
