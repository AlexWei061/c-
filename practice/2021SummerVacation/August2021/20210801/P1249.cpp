#include<bits/stdc++.h>
using namespace std;

#define MANN 10001

/*
˼· :
ln(a) + ln(b) = ln(a*b)
max(n1*n2*n3*...*ni) --> max(ln(n1*n2*n3*...*ni)) --> max(ln(n1)+ln(n2)+...+ln(ni))
�������Խ�������ת����һ��������СΪ n��n �����壬����ni��СΪ i������ni��ֵΪln(i)�ı�������
        { = max{ f[i-1][j], f[i-1][j-w[i]] + v[i] }  (w[i] <= j)
f[i][j]{
        { = f[i-1][j]   (w[i] > j)
*/

int n = 0;

double f[MANN][MANN] = { 0 };
struct Obj{
    double value;
    int weight;
}obj[MANN];

double maxf(double a, double b){
    return a > b ? a : b;
}

void prework(){
    for(int i = 1; i <= n; i++){
        obj[i].weight = i;
        obj[i].value = log(i) / log(2);   
    }
}

void knaspsack(){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(obj[i].weight <= j){
                f[i][j] = maxf(f[i-1][j], f[i-1][j-obj[i].weight] + obj[i].value);
            }
            else{
                f[i][j] = f[i-1][j];
            }
        }
    }
}

int main(){
    scanf("%d", &n);

    prework();
    knaspsack();

    int o[MANN] = { 0 };
    int k = 0;
    int i = n;
    int j = n;
    while(i > 0 and j > 0){
        if(f[i][j] == f[i-1][j]){
            i--;
        }
        else{
            o[++k] = i;
            j -= obj[i].weight;
            i--;
        }
    }

    unsigned long long ans = 1;
    for(int i = k; i > 0; i--){
        printf("%d ", o[i]);
        ans *= o[i];
        //printf("o[%4d] = %4d  ans = %llu\n", i, o[i], ans);
    }

    printf("\n%llu\n", ans);
    
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            printf("%lf ", f[i][j]);
        }
        printf("\n");
    }
    
    
    return 0;
}

/*
[��Ŀ����]
һ��������һ����Է�Ϊ����������ͬ����Ȼ���ĺͣ��� 3=1+2 3=1+2��4=1+3 4=1+3��5��1+4=2+3 5��1+4=2+3��6=1+5��2+4 6=1+5��2+4��
������������ǽ�ָ���������� n �ֽ�����ɸ�������ͬ����Ȼ���ĺͣ���ʹ��Щ��Ȼ���ĳ˻����
[�����ʽ]
һ�������� n (3 <= n <= 10000)
[�����ʽ]
��һ���Ƿֽⷽ�������ڵ���֮����һ���ո�ֿ������Ұ���С�����˳��
�ڶ��������ĳ˻�
[�����������]
10
2 3 5
30
*/
