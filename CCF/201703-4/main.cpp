#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

typedef struct Info{
    int d;    //目的地点
    int time; //修筑时间
}info;

const int INF = 2147483647;
const int maxn = 100010;

vector<info> M[maxn];   //邻接表存储矩阵
int visit[maxn], T[maxn];

int main()
{
    int n, m;
    cin >> n >> m;

    int a,b,c;
    info in;
    for(int i=0; i<m; i++){
        cin >> a >> b >> c;
        in.d = b;
        in.time = c;
        M[a].push_back(in);
        in.d = a;
        M[b].push_back(in);
    }


    fill(visit, visit+maxn, 0);
    fill(T, T+maxn, INF);
    for(int i=0; i<n; i++){
        int MIN = INF, u=0;
        T[1] = 0;
        for(int j=1; j<=n; j++){
            if(visit[j] == 0 && T[j] < MIN){
                MIN = T[j];
                u = j;
            }
        }

        visit[u] = 1;
        for(int v=0; v<M[u].size(); v++){
            if(visit[M[u][v].d] == 0){   //未被访问的点
                T[M[u][v].d] = min(max(M[u][v].time, T[u]), T[M[u][v].d]);
            }
        }

    }

    cout << T[n] << endl;
}
