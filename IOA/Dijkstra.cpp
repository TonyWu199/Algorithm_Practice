#include <stdio.h>
#define inf 999999

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	int map[n+1][n+1], used[n+1], dis[n+1];

	for(int i=0; i<=n; i++)
		for(int j=0; j<=n; j++)
			if(i == j)
				map[i][j] = 0;
			else
				map[i][j] = inf;	
			

	int a, b, len;
	for(int i=0; i<m; i++){
		scanf("%d %d %d", &a, &b, &len);
		map[a][b] = len;
	}	
	
	for(int i=1; i<=n; i++){
		dis[i] = map[1][i];
		used[i] = 0;
	}
	
	used[1] = 1; //��ʾ�ڵ�1�ѱ�����
	
	//������Ҫn-1�ε����������Ǵ���ĳ���� 
	for(int i=1; i<n; i++){
		int min = inf; //ѡ����i����Ľڵ� 
		int u;
		for(int j=1; j<=n; j++){
			if(used[j] == 0 && dis[j] < min){
				min = dis[j];
				u = j;	
			}
		} 
		
		used[u] = 1;
		for(int v=1; v<=n; v++){   //����u���ȵ����е� 
			if(map[u][v] != inf){  
				if(dis[v] > map[u][v] + min){
					dis[v] = map[u][v] + min;
				} 
			}
		}
		
		printf("%d:", u);
		for(int i=1; i<=n; i++){
			printf("%d ", dis[i]);
		}
		putchar('\n');
	} 	 

    return 0;
}
