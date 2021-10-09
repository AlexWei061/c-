#include<bits/stdc++.h> 
#define ll long long 
using namespace std; 
 
const int MAXN = int(3e5 + 21);                              //3*N 
int getNum[MAXN];                                            //��ɢ�����飬֮������3*N�Ŀռ䣬����ΪҪ��N�仨���ŵ���ʼʱ�䡢��ѯʱ�� 
int li[MAXN / 3], ri[MAXN / 3], c[MAXN];                     //��������ʼʱ�䡢����ʱ�䡢��״���� 
 
int lowbit(int x){      
    return x & -x; 
} 
 
void add(int x, int num, int len){                           //�������   
    for(int i=x;i<=len;i+=lowbit(i)) { 
        c[i] += num; 
    } 
} 
 
ll query(int x){                                             //�����ѯ   
    ll ans = 0; 
    for(int i = x; i > 0; i -=l owbit(i)){ 
        ans += c[i]; 
    } 
    return ans; 
} 
 
int bSerach(int num, int len){                               //������getNum���ҳ����ڵ���num���������������±�+1������״�����±��1��ʼ��   
    return lower_bound(getNum, getNum + len, num) - getNum + 1; 
}

int main() { 
    int t, n, m, cnt = 0; 
    cin >> t; 
    while(t--){ 
        memset(c, 0, sizeof(c)); 
        memset(getNum, 0, sizeof(getNum));    
        scanf("%d%d", &n, &m);         
        int cnt1 = 0;         
        for(int i = 0; i < n; ++i) { 
            scanf("%d%d", &li[i], &ri[i]); 
            getNum[cnt1++] = li[i];                          //�������ŷ�Χ���ֵ����ݴ�������  
            getNum[cnt1++] = ri[i]; 
        } 
        int ques[MAXN / 3];                                  //�洢��ѯʱ�� 
        for(int i = 0; i < m; ++i){ 
            scanf("%d", &ques[i]);  
            getNum[cnt1++] = ques[i];                        //����ѯ���ֵ����ݴ�������  
        }         
        sort(getNum, getNum + cnt1);                         //�����г��ֵ������� 
 
        int cnt2 = 1; 
        for(int i = 1; i < cnt1; ++i){ 
            if(getNum[i] != getNum[i - 1])                   // getNum[0]��getNum[cnt2-1]�����ȥ�غ����  
                getNum[cnt2++] = getNum[i]; 
        }   
 
        for(int i = 0; i < n; ++i){                          //��״����������� 
            add(bSerach(li[i], cnt2), 1, cnt2);              //λ��bSerach(li[i],cnt2)��λ��cnt2������1 
            add(bSerach(ri[i], cnt2) + 1, -1, cnt2);         //λ��bSerach(lr[i]+1,cnt2)��λ��cnt2������-1 
        }  
        printf("Case #%d:\n", ++cnt); 
        for(int i = 0; i < m; ++i){ 
            cout << query(bSerach(ques[i],cnt2)) << endl;    //��״���鵥���ѯ  
        }                                                    //bSerach(ques[i],cnt2)�ǲ���ques[i]����ɢ�������е�λ�� 
    } 
    return 0; 
}
