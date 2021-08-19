#include<bits/stdc++.h>
using namespace std;

int n = 0;
int x = 0;

int findNumFrequent(int n, int x){
    int tot = 0;
    for(int i = 1; i <= n; i++){
        //printf("i = %d\n", i);
        int a = i;
        while(a != 0){
            //printf("    a = %d\n", a);
            int temp = a % 10;
            //printf("    temp = %d\n", temp);
            a = (a - temp) / 10;
            if(x == temp){
                tot++;
            }
        }
    }
    return tot;
}

int main(){
    scanf("%d%d", &n, &x);
    printf("%d\n", findNumFrequent(n, x));
    return 0;
}

/*

试计算在区间 1 到 n 的所有整数中，数字 x (0 ≤ x ≤ 9) 共出现了多少次？例如，在 1 到 11 中，即在 1,2,3,4,5,6,7,8,9,10,11 中，数字 1 出现了 4 次。

11 1

4

*/