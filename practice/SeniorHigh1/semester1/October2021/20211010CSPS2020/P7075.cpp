#include <cstdio>
using namespace std;
typedef long long ll;

//已经化归到4年的情况下求解
void solve2(int n, int &y, int &m, int &d, bool flag) {                                   //flag为标记是否考虑4年末的闰年
	//打表，快速计算第i天的日月
	static int todate[366][2] = {
	{0, 0}, {0, 1}, {0, 2}, {0, 3}, {0, 4}, {0, 5}, {0, 6}, {0, 7}, {0, 8}, {0, 9}, {0, 10}, {0, 11}, {0, 12}, {0, 13}, {0, 14}, {0, 15}, {0, 16}, {0, 17}, {0, 18}, {0, 19}, {0, 20}, {0, 21}, {0, 22}, {0, 23}, {0, 24}, {0, 25}, {0, 26}, {0, 27}, {0, 28}, {0, 29},{0, 30}, 
	{1, 0}, {1, 1}, {1, 2}, {1, 3}, {1, 4}, {1, 5}, {1, 6}, {1, 7}, {1, 8}, {1, 9}, {1, 10}, {1 ,11}, {1, 12}, {1, 13}, {1, 14}, {1, 15}, {1, 16}, {1, 17}, {1, 18}, {1, 19}, {1, 20}, {1, 21}, {1, 22}, {1, 23}, {1, 24}, {1, 25}, {1, 26}, {1, 27}, {1, 28}, 
	{2, 0}, {2, 1}, {2, 2}, {2, 3}, {2, 4}, {2, 5}, {2, 6}, {2, 7}, {2, 8}, {2, 9}, {2, 10}, {2, 11}, {2, 12}, {2, 13}, {2, 14}, {2, 15}, {2, 16}, {2, 17}, {2, 18}, {2, 19}, {2, 20}, {2, 21}, {2, 22}, {2, 23}, {2, 24}, {2, 25}, {2, 26}, {2, 27}, {2, 28}, {2, 29}, {2, 30}, 
	{3, 0}, {3, 1}, {3, 2}, {3, 3}, {3, 4}, {3, 5}, {3, 6}, {3, 7}, {3, 8}, {3, 9}, {3, 10}, {3, 11}, {3, 12}, {3, 13}, {3, 14}, {3, 15}, {3, 16}, {3, 17}, {3, 18}, {3, 19}, {3, 20}, {3, 21}, {3, 22}, {3, 23}, {3, 24}, {3, 25}, {3, 26}, {3, 27}, {3, 28}, {3, 29}, 
	{4, 0}, {4, 1}, {4, 2}, {4, 3}, {4, 4}, {4, 5}, {4, 6}, {4, 7}, {4, 8}, {4, 9}, {4, 10}, {4, 11}, {4, 12}, {4, 13}, {4, 14}, {4, 15}, {4, 16}, {4, 17}, {4, 18}, {4, 19}, {4, 20}, {4, 21}, {4, 22}, {4, 23}, {4, 24}, {4, 25}, {4, 26}, {4, 27}, {4, 28}, {4, 29}, {4, 30}, 
	{5, 0}, {5, 1}, {5, 2}, {5, 3}, {5, 4}, {5, 5}, {5, 6}, {5, 7}, {5, 8}, {5, 9}, {5, 10}, {5, 11}, {5, 12}, {5, 13}, {5, 14}, {5, 15}, {5, 16}, {5, 17}, {5, 18}, {5, 19}, {5, 20}, {5, 21}, {5, 22}, {5, 23}, {5, 24}, {5, 25}, {5, 26}, {5, 27}, {5, 28}, {5, 29}, 
	{6, 0}, {6, 1}, {6, 2}, {6, 3}, {6, 4}, {6, 5}, {6, 6}, {6, 7}, {6, 8}, {6, 9}, {6, 10}, {6, 11}, {6, 12}, {6, 13}, {6, 14}, {6, 15}, {6, 16}, {6, 17}, {6, 18}, {6, 19}, {6, 20}, {6, 21}, {6, 22}, {6, 23}, {6, 24}, {6, 25}, {6, 26}, {6, 27}, {6, 28}, {6, 29}, {6, 30}, 
	{7, 0}, {7, 1}, {7, 2}, {7, 3}, {7, 4}, {7, 5}, {7, 6}, {7, 7}, {7, 8}, {7, 9}, {7, 10}, {7, 11}, {7, 12}, {7, 13}, {7, 14}, {7, 15}, {7, 16}, {7, 17}, {7, 18}, {7, 19}, {7, 20}, {7, 21}, {7, 22}, {7, 23}, {7, 24}, {7, 25}, {7, 26}, {7, 27}, {7, 28}, {7, 29}, {7, 30}, 
	{8, 0}, {8, 1}, {8, 2}, {8, 3}, {8, 4}, {8, 5}, {8, 6}, {8, 7}, {8, 8}, {8, 9}, {8, 10}, {8, 11}, {8, 12}, {8, 13}, {8, 14}, {8, 15}, {8, 16}, {8, 17}, {8, 18}, {8, 19}, {8, 20}, {8, 21}, {8, 22}, {8, 23}, {8, 24}, {8, 25}, {8, 26}, {8, 27}, {8, 28}, {8, 29}, 
	{9, 0}, {9, 1}, {9, 2}, {9, 3}, {9, 4}, {9, 5}, {9, 6}, {9, 7}, {9, 8}, {9, 9}, {9, 10}, {9, 11}, {9, 12}, {9, 13}, {9, 14}, {9, 15}, {9, 16}, {9, 17}, {9, 18}, {9, 19}, {9, 20}, {9, 21}, {9, 22}, {9, 23}, {9, 24}, {9, 25}, {9, 26}, {9, 27}, {9, 28}, {9, 29}, {9, 30}, 
	{10, 0}, {10, 1}, {10, 2}, {10, 3}, {10, 4}, {10, 5}, {10, 6}, {10, 7}, {10, 8}, {10, 9}, {10, 10}, {10, 11}, {10, 12}, {10, 13}, {10, 14}, {10, 15}, {10, 16}, {10, 17}, {10, 18}, {10, 19}, {10, 20}, {10, 21}, {10, 22}, {10, 23}, {10, 24}, {10, 25}, {10, 26}, {10, 27}, {10, 28}, {10, 29}, 
	{11, 0}, {11, 1}, {11, 2}, {11, 3}, {11, 4}, {11, 5}, {11, 6}, {11, 7}, {11, 8}, {11, 9}, {11, 10}, {11, 11}, {11, 12}, {11, 13}, {11, 14}, {11, 15}, {11, 16}, {11, 17}, {11, 18}, {11, 19}, {11, 20}, {11, 21}, {11, 22}, {11, 23}, {11, 24}, {11, 25}, {11, 26}, {11, 27}, {11, 28}, {11, 29}, {11, 30}
	} ;
	if (n >= 1095 && flag) {                                                              //第4年是闰年
		y += 3; n -= 1095;                                                                //现在n是该年第几天
	} else {
		y += n / 365; n %= 365;
		if (n >= 59) n++;
	}
	m = todate[n][0] + 1, d = todate[n][1] + 1;
}
void solve(ll n, int &y, int &m, int &d) {
	if (n < 1721424 + 577737) {                                                           //1582年10月4日及之前
		//平移一下，把闰年放在第4个周期
		//因为前4713是闰年
		n += 1095;
		y = -4716 + n / 1461 * 4; n %= 1461;
		solve2(n, y, m, d, true);
		if (y >= 0) y++;                                                                  //公元0年不存在
	} else {                                                                              //公元后，改历法后
		n -= 1721424;
		//有每400年的闰年、100年的平年
		//前1582年当成无100年平年来做，多了12天，还要再加上
		n += 10 - 12;
		//约束到400年里
		y = 1 + n / 146097 * 400; n %= 146097;
		//然后讨论一下有多少闰年
		//下面约束到100年里 每100年有 36524天
		if (n >= 109572) {                                                                //最后一个100年，最后一年是闰年，满足每4年有闰年
			y += 300; n -= 109572;
			y += n / 1461 * 4; n %= 1461;
			solve2(n, y, m, d, true);
		} else {                                                                          //不是最后一个100年，末尾没有闰年
			y += n / 36524 * 100; n %= 36524;
			if (n >= 35064) {                                                             //在最后一个4年
				y += 96; n -= 35064;
				solve2(n,y,m,d,false);
			} else {
				y += n / 1461 * 4; n %= 1461;
				solve2(n, y, m, d, true);
			}	
		}
	}
}

int main() {
	int q = 0;
	scanf("%d", &q);
	while (q--) {
		ll n = 0;
		scanf("%lld", &n);
		int y, m, d;
		solve(n, y, m, d);
		if (y < 0) printf("%d %d %d BC\n", d, m, -y);
		else printf("%d %d %d\n", d, m, y);
	}
	return 0;
}