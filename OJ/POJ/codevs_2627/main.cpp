/*
作者:BugenZhao
题目:p2627 村村通
*/

#include <iostream>
#include <algorithm>
#include <vector>
#define INF 0x7fffffff
using namespace std;

int                n,ans;
int          G[101][101];
int   vis[101],dist[101];
int                cur=1;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
		cin>>G[i][j];
	for(int i=2;i<=n;i++)
		dist[i]=G[1][i];
	vis[1]=1;
	for(int i=1;i<n;i++)
	{
		int minn=INF;
		for(int j=1;j<=n;j++)
			if((!vis[j])&&minn>dist[j])
			{
				minn=dist[j];
				cur=j;
			}
		ans+=minn,vis[cur]=1;
		for(int k=1;k<=n;k++)
			if((!vis[k]) && dist[k]>G[cur][k])
				dist[k]=G[cur][k];
	}
	cout<<ans;
	return 0;
}
