#include<bits/stdc++.h>
using namespace std;

int n,q,l,r,x,a;
vector<int> pos[200005];

int main()
{
	freopen("query.in","r",stdin);
	freopen("query.out","w",stdout);  
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
	{
        scanf("%d",&a);
        pos[a].push_back(i);
    }
    scanf("%d",&q);
    while(q--)
	{
        scanf("%d%d%d",&l,&r,&x);
        int p1=lower_bound(pos[x].begin(),pos[x].end(),l)-pos[x].begin(); //������ֵΪx�������ж��ֲ��ұ�Ŵ��ڵ���l�ĵ�һ��λ�� 
        int p2=upper_bound(pos[x].begin(),pos[x].end(),r)-pos[x].begin(); //������ֵΪx�������ж��ֲ��ұ�Ŵ���r�ĵ�һ��λ�� 
        printf("%d\n",p2-p1); //���� 
    }
    return 0;
}
