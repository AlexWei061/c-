#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
using namespace std;

int map[1000005][20];
int n;

void work()
{
    int i,j;
    for(j=1;1<<j<=n;j++)
    for(i=1;i+(1<<j)-1<=n;i++)//i+(1<<j)-1<=n��Ϊ�˱�֤������˵㲻��������n
    map[i][j]=min(map[i][j-1],map[i+(1<<j-1)][j-1]);//ʵ���Ƕ�̬�滮
}

int question(int z,int y)
{
    int x=int (log(y-z+1)/log(2));//ע��y-zҪ��һ��Ϊ���䳤��
    return min(map[z][x],map[y-(1<<x)+1][x]);//�ֱ������������˵�Ϊ����������������1<<x����
//��ֵ; 
}

int main()
{
    scanf("%d",&n);//������������
    int i,a,b,k;
    for(i=1;i<=n;i++)
    scanf("%d",&map[i][0]);//��������ӳ�ʼ��������i��ʼ������2��0�η��������е����ֵ����ע//��i��i�ĳ���Ϊһ����
    work();//Ԥ����
    scanf("%d",&k);//����ѯ�ʴ���k
    for(i=1;i<=k;i++)
        {
            scanf("%d%d",&a,&b);
            printf("%d\n",question(a,b));//������
        }
    return 0;
}
