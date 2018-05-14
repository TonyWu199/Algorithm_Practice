//最长公共子序列问题：
//给定两个两个序列X = <x1, x2, ....., xm>和Y = <y1, y2, ...., yn>, 希望找出X和Y的最大长度的公共子序列，可以使用动态规划来解决
//定理15.1（LCS的最优子结构）
//设X = <x1, x2, ....., xm>和Y = <y1, y2, ...., yn>为两个序列，并设Z = { z1, z2, ...., zk }为X和Y的任意一个LCS
//（1）如果xm = yn, 那么zk = xm = yn, 而且Zk - 1是Xm - 1与Yn - 1的一个LCS
//（2）如果xm != yn，那么Zk ！ = xm蕴含Z是Xm - 1和Y的一个LCS
//（3）如果xm != yn, 那么Zk ！ = yn，蕴含Z是X和Yn - 1的一个LCS

//定义c[i][j]为序列Xi与Yi的一个LCS长度，则有下面递归表达式
// 当i = 0 或 j = 0的时候 c[i][j]=0；
//若i, j > 0 且xi = yi的时候  c[i][j] = c[i - 1][j - 1] + 1
//若i, j > 0 且 xi != yi   c[i][j]= max(c[i][j - 1], c[i - 1][j])
//根据上面的递归式可以写出自底向上的动态规划代码

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

pair<vector<vector<int>>,vector<vector<int>>>
LCS_Length(string x, string y)
{
	int m = x.size();
	int n = y.size();
	vector<vector<int>> c(m+1, vector<int>(n+1, 0));
	vector<vector<int>> b(m+1, vector<int>(n+1, 0));

	for (int i = 1; i <= m; ++i)
	{
		c[i][0] = 0;
	}
	for (int j = 1; j <= n; ++j)
	{
		c[0][j] = 0;
	}

	for (int i = 1; i <= m; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (x[i - 1] == y[j - 1])
			{
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i][j] = 1;//这里我使用1表示箭头指向左上，
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;//这里我使用2表示箭头指向上
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;//这里我使用3表示箭头指向左
			}
		}
	}

	return make_pair(c, b);
}

void print_LCS(vector<vector<int>>b, string x, int i, int j)
{
	if (i == 0 || j == 0)
		return;
	if (b[i][j] == 1)
	{
		print_LCS(b, x, i - 1, j - 1);
		cout << x[i - 1]<<" ";
	}
	else if (b[i][j] == 2)
		print_LCS(b, x, i - 1, j);
	else
		print_LCS(b, x, i, j - 1);
}

int main()
{
	string x = "ABCBDAB";
	string y = "BDCABA";
	int i = x.size();
	int j = y.size();

	vector<vector<int>> c = LCS_Length(x, y).first;
	vector<vector<int>> b = LCS_Length(x, y).second;

	cout << "the LCS is: " << c[x.size()][y.size()] << endl;
	print_LCS(b, x, i, j);

	return 0;
}
