#include<bits/stdc++.h>
using namespace std;

bool compare(const int &a, const int &b){
	return a > b;                                 //�������� 
}

int main(){
	int numlist[] = { 123, 45, 536, 43, 4, 67, 345, 3, 8, 10, 55, 3564 };
	int length = sizeof(numlist) / sizeof(int);
	
	for(int i = 0; i < length; i++){
		printf("%d ", numlist[i]);
	}
	printf("\n");
	
	sort(numlist, numlist+length);          //Ĭ������ 
	
	for(int i = 0; i < length; i++){
		printf("%d ", numlist[i]);
	}
	printf("\n");
	
	sort(numlist, numlist+length, compare); //���� 
	
	for(int i = 0; i < length; i++){
		printf("%d ", numlist[i]);
	}
	printf("\n");
	
	return 0;
}
