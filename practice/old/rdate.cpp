#include<bits/stdc++.h>
using namespace std;

int i,j,n,m,a,b,c,sum,ans;
int month_day[13] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
    scanf("%d%d",&n,&m);
    for (i = 1; i <= 12; i++)                                                             //ö���º��� 
        for (j = 1; j <= month_day[i]; j++)
        {
            c = (j % 10) * 1000 + (j / 10) * 100 +(i % 10) * 10 + (i / 10);               //���ǰ��λ��
            sum = c * 10000 + i * 100 + j;                                                //����������� 
            if (sum < n || sum > m) continue;
            ans++;                                                                        //ͳ�� 
        }
    printf("%d",ans);
    return 0;
}
