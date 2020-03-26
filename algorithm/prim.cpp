#include<iostream>
#include<cstring>
using namespace std;

//������:��һ����k���ڵ��������ͨͼ�У�ȡ����v-1���ߣ����������еĽڵ㣬���õ���ͼ��Ϊԭͼ��һ��������  

//��С������:��һ��������ͨͼ�У�����Ȩ��С��һ��������

/*
��С������:Prim
 
	1.����ͳ�ʼ��(d[0] = 0; d[i] = INF) 
	2.���������� 
		(1) ѡһ��δ��ǵĵ�k,d[k]Ҫ��С
		(2)��k����Va
		(3)�޸�d[]
	3.�õ���С������T 
*/ 

/*
	Va[]:�Ѿ����������еĽڵ�
	Vb[]:��û�Ž�ȥ��
	 d[]:��ǰi �ڵ�ǰ�������еĵ������ߵı߳�����Сֵ
   vst[]:��i�Ƿ���Va�� 
*/ 

/*
�����ʽ
	����n���ڵ��m���� 
	��m������x��y�ı�Ȩ 
*/ 

#define INF 65535
int    vst[505];
int      d[505];
int g[505][505];
int n, m, ans = 0;     //ansΪ��Ȩ�� 

void read(){           //����ͼ 
	int x, y;          //����
	int    w;          //��ֵ
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			g[i][j] = INF;
		}
	}
	for(int i = 1; i <= m; i++){
		cin >> x >> y >> w;
		g[x][y] = g[y][x] = w;       //����ͼ 
	}
}

void prim(int v){          //�㷨��ʼ 
	int mmin = INF;        //��Сֵ
	int k;                 //��ǰ�ڵ�
	memset(vst, 0, sizeof(vst));   //��ʼ����ʱVaû���κ�Ԫ��
	//��ʼ��ʼ��d[]
	for(int i = 1; i <= n; i++){
		d[i] = INF; 
	} 
	d[1] = 0;
	//ans = 0;
	//ѡn����
	for(int i = 0; i <= n; i++){
		mmin = INF; 
		//ѡ��С�ı�Ȩ
		for(int j = 1; j < n; j++){
			if(vst[j] == 0 and d[j] < mmin){
				//С�ڵ�ǰ��С�Ҳ���Va��
				mmin = d[j];
				k = j;                //���µ�ǰ��С 
			} 
		}
		vst[k] = 1;                   //��ǵ�Va��
		ans += d[k];                  //��Ȩ�� ����
		//�޸�d[]
		for(int j = 1; j <= n; j++){
			if(vst[j] == 0 and d[j] > g[k][j]){
				//��ǰ��С���ڱ����Ȩ�Ҵ˽ڵ㲻��Va�� 
				d[j] = g[k][j];       //������С 
		    }
		}
	}
}

int main(){
	read();
	prim(1);
	cout << ans << endl;
	return 0;
}
