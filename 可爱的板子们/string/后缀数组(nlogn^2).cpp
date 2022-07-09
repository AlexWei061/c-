#include<bits/stdc++.h>
using namespace std;
#define mod 233
#define ull unsigned long long
#define MAXN 1001000

int n = 0;
ull base[MAXN] = { 0 };                                                   // base[i] = mod ^ i
ull Hash[MAXN] = { 0 };                                                   // ��ϣֵ 
char str[MAXN];
int SA[MAXN] = { 0 };

inline ull get(int l, int r){                                             // O(1) ���Ӵ���ϣ 
	return Hash[r] - Hash[l - 1] * base[r - l + 1];
}

bool comp(int x, int y){                                                  // ��д�ȽϺ��� 
    int l = -1, r = min(n - x, n - y);                                    // ��������׺�ĳ���֮�ڶ��� 
    while(l < r){                                                         // ���� 
        int mid = (l + r + 1) >> 1;
        if(get(x, x + mid) == get(y, y + mid)) l = mid;                   // ǰ�벿����ͬ 
        else r = mid - 1;                                                 // ��ͬ 
    }
    if(l > min(n - x, n - y)) return x > y;                               // ��˵㳬�����Ҷ˵� ˵���̵��ǳ��ĵ��Ӵ� ��ô�����ַ������������� 
    else return str[x + l + 1] < str[y + l + 1];                          // û���� �Ͱ��յ�һ����ͬ�ĵط��Ĵ�С�Ƚ� 
}

int main(){
    scanf("%s", str + 1);
    n = strlen(str + 1);
    base[0] = 1;
    for(int i=1;i<=n;i++){
        base[i] = base[i - 1] * mod;
        Hash[i] = Hash[i - 1] * mod + str[i];
        SA[i] = i;
    }
    stable_sort(SA + 1, SA + n + 1, comp);
    for(int i = 1; i <= n; i++) printf("%d ", SA[i]);
    return 0;
}
