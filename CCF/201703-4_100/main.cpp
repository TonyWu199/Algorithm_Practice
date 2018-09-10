/*
Prim算法最小生成树
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

typedef pair<int, int> P;//first是最短距离，second是顶点
#define maxv 100000+3
vector<P> G[maxv];//类似动态的二维数组，可以用push_back()动态增加
int d[maxv], visit[maxv];
#define INF 1<<29

struct cmp {
	bool operator()(P x,P y)
	{
		return x.first > y.first;
	}
};

int dijkstra(int s, int N)
{
	priority_queue<P, vector<P>, cmp> Q;
	fill(d, d + maxv + 1, INF);
	fill(visit, visit + maxv + 1, 0);
	d[s] = 0;
	Q.push(P(0, s));
	P temp, temp2; int ans = 0;
	while (!Q.empty())
	{
        temp = Q.top();//选出距离最小的点
		Q.pop();
		int v = temp.second;
		if(d[v] > ans)
            ans = d[v];
		if(v == N){
            return ans;
		}
        visit[v] = 1;
		for (int i = 0; i < G[v].size(); i++)
		{
            temp2 = G[v][i];//找到相邻的点
            if(visit[temp2.second] == 0){
                //cout << temp2.second << " ";
                if (d[temp2.second] >  temp2.first)
                    {
                         d[temp2.second] =  temp2.first;
                         Q.push(P(d[temp2.second], temp2.second));
                    }
            }
		}
	}
}

int main()
{
	int a,b,c,N,M;
	cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> a >> b >> c;
        G[a].push_back(P(c, b));
        G[b].push_back(P(c, a));
    }
    cout << dijkstra(1, N);
    return 0;
}
