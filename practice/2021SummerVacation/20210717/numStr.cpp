#include<bits/stdc++.h>
using namespace std;

int s = 0;
char c;

int main() {		
	c = getchar();                                         //��׼��������е�д�� 
	while(c != 10){
		s = s + (c - '0');
		c = getchar();
	}
	cout << s << endl;
    return 0;
}

/*
#include<bits/stdc++.h>
using namespace std;

int s=0;
char c;

int main() 
{
	freopen("num.in","r",stdin);                           //�ļ���������е�д�� 
	freopen("num.out","w",stdout); 
	while(cin>>c)                                          //ֱ��EOF 
	{
		s=s+(c-'0');
	}
	cout<<s<<endl;
    return 0;
}
*/
