//��������������⣺
//����������������X = <x1, x2, ....., xm>��Y = <y1, y2, ...., yn>, ϣ���ҳ�X��Y����󳤶ȵĹ��������У�����ʹ�ö�̬�滮�����
//����15.1��LCS�������ӽṹ��
//��X = <x1, x2, ....., xm>��Y = <y1, y2, ...., yn>Ϊ�������У�����Z = { z1, z2, ...., zk }ΪX��Y������һ��LCS
//��1�����xm = yn, ��ôzk = xm = yn, ����Zk - 1��Xm - 1��Yn - 1��һ��LCS
//��2�����xm != yn����ôZk �� = xm�̺�Z��Xm - 1��Y��һ��LCS
//��3�����xm != yn, ��ôZk �� = yn���̺�Z��X��Yn - 1��һ��LCS

//����c[i][j]Ϊ����Xi��Yi��һ��LCS���ȣ���������ݹ���ʽ
// ��i = 0 �� j = 0��ʱ�� c[i][j]=0��
//��i, j > 0 ��xi = yi��ʱ��  c[i][j] = c[i - 1][j - 1] + 1
//��i, j > 0 �� xi != yi   c[i][j]= max(c[i][j - 1], c[i - 1][j])
//��������ĵݹ�ʽ����д���Ե����ϵĶ�̬�滮����

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
				b[i][j] = 1;//������ʹ��1��ʾ��ͷָ�����ϣ�
			}
			else if (c[i - 1][j] >= c[i][j - 1])
			{
				c[i][j] = c[i - 1][j];
				b[i][j] = 2;//������ʹ��2��ʾ��ͷָ����
			}
			else
			{
				c[i][j] = c[i][j - 1];
				b[i][j] = 3;//������ʹ��3��ʾ��ͷָ����
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
