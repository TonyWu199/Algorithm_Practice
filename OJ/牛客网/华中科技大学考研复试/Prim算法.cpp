#include <stdio.h>
#include <algorithm>
using namespace std; 

typedef struct{
	int cost;
	char v1, v2;
}edge;

char temp[100];
int flag = 0;

void cmp(edge x, edge y){
	return x.cost < y.cost;
}

int main(){
	int i, j, n, m;
	Edge edges[100], t;
	
	cout >> m >> n;
	for(i=0; i<n; i++){
		cin >> edges[i].v1 >> edges[i].v2 >> edges[i].cost;
	}
	
	//按照cost对边进行排序
	sort(edges, edges + n, cmp); 
} 
