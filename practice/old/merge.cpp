#include<bits/stdc++.h>
using namespace std;

/*
��������
Rainieӵ�кܶ����С���飬�����������Щ����С������кϳɣ������µĳ���С���飬���պϳ�Ϊ
һֻ����С���飬��ÿֻ����С���鶼�в�ͬ������ֵ��ͬʱ�ϳ�Ҳ����������صĹ��򣬾��������
�£�
1��ÿ��ֻ�ܽ�����ֵ�ŵ�һ��С���������ֵ���е�����һ��С������кϳɣ�
2��������ֵ��һ��С����Ϊa������ֵ������һ��С����Ϊb,�ϳɺ��С��������ֵΪc=a/2+b��
3��(ȡ�������������Ľ��Ϊ)
4�����ϳɺ��µĳ������¼���
Rainie�������������һ�����պϳɺ�ĳ�������ֵ�Ƕ��١�

�����ʽ
��һ�а���һ������ ����ʾ�ܹ��ж���ֻС���飻
�ڶ��а�������������ʾС���������ֵ��

�����ʽ
���ֻ��һ�У�����һ�������������ϳɵ�С��������ֵ
*/

long long NumOfBao = 0;
long long PowOfEachBao[100001] = { 0 };
//�������
priority_queue <long long, vector<long long>,greater<long long> > gq;
//�������
priority_queue <long long, vector<long long>,less<long long> > lq;

int main(){
    /*����*/
    scanf("%lld", &NumOfBao);
    for(long long i = 0; i < NumOfBao; i++){
        scanf("%lld", &PowOfEachBao[i]);
        gq.push(PowOfEachBao[i]);
        lq.push(PowOfEachBao[i]);
    }
    /**/
    long long j = 0;
    while(1){                                            //for(long long i = 0; i < NumOfBao - 1; i++)
        long long temp = (lq.top() / 2) + gq.top();
        if(j == NumOfBao - 2){
        	printf("%lld", temp);
        	break;
		}
        gq.pop();
        lq.pop();
        gq.push(temp);
        lq.push(temp);
        j++;
    }
    return 0;
}
