/*
第一次自己用dijkstra和priority优化实现图问题的求解，很爽！
AC
*/

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct NODE{
    int v;
    int dis;

    NODE (int V, int DIS=0){
        v = V;
        dis = DIS;
    }
}node;

struct cmp {
    bool operator() (NODE n1, NODE n2){
        return n1.dis > n2.dis;
    }
};

const int maxv = 10010;
const int inf = 9999999;
vector<node> G[maxv];
int d[maxv], cost[maxv], visit[maxv];
priority_queue <node, vector<node>, cmp> pq;
int n, m;

void dijkstra(int s){
    fill(d, d+maxv, inf);
    fill(cost, cost+maxv, inf);
    fill(visit, visit+maxv, 0);
    d[1] = 0;
    cost[1] = 0;

    pq.push(node(1, 0));

    node tmp(0,0);
    while(!pq.empty()){
        tmp = pq.top();
        pq.pop();
        int u =tmp.v;
        //cout << "current point" << u << ":";
        if(visit[u] == 1)
            continue;
        visit[u] = 1;

        for(int k=0; k<G[u].size(); k++){
            int v = G[u][k].v;
            int dis = G[u][k].dis;
            //cout << v << "-" << dis << " ";
            if(visit[v] == 1)
                continue;
            if(d[u] + dis < d[v]){
                d[v] = d[u] + dis;
                cost[v] = dis;
                pq.push(node(v, d[v]));
            }

            if(d[u] + dis == d[v]){
                cost[v] = min(cost[v], dis);
            }
        }
//        cout << endl;
//        for(int i=1; i<=n; i++){
//            cout << cost[i] << " ";
//        }
//        cout << endl;
    }
}

int main(){
    cin >> n >> m;

    int a, b, c;
    for(int i=0; i<m; i++){
        node p(0,0);
        cin >> a >> b >> c;
        p.v = b;
        p.dis = c;
        G[a].push_back(p);
        p.v = a;
        G[b].push_back(p);
    }

    dijkstra(1);

    long long sum = 0;
    for(int i=1; i<=n; i++){
        sum += cost[i];
    }
    cout << sum << endl;
}
