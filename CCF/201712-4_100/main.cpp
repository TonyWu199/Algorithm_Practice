#include <iostream>
using namespace std;

const long long INF = 1e18;
const int maxn = 1010;

typedef struct Info{
    int type;
    long long len;
}info;

long long SD(long long s){
    return s*s;
}

info M[maxn][maxn];          //�洢����
long long dis[maxn];        //���1�������ڵ�ľ�����
int used[maxn] = {0};       //�ڵ���ʾ���
long long small_len[maxn] = {0};    //�ۻ�С·����

int main()
{
    long long n,m;
    cin >> n >> m;

    //��ʼ���ٽӾ���
    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            M[i][j].len = INF;
            M[i][j].type = -1;
        }
    }

    long long t, a, b, c;
    for(int i=0; i<m; i++){
        cin >> t >> a >> b >> c;
        M[a][b].len = c;
        M[a][b].type = t;
        M[b][a].len = c;
        M[b][a].type = t;
    }

    //��ʼ��dis����
    fill(dis, dis+maxn, INF);
    dis[1] = 0;

    //Dijkstra
    for(int i=1; i<=n; i++){
        long long MIN = INF, u=-1;
        for(int j=1; j<=n; j++){
            if(used[j] == 0 && dis[j] < MIN){
                u = j;
                MIN = dis[j];
            }
        }

        if(u == -1)
            break;

        used[u] = 1;

        for(int k=1; k<=n; k++){
            if(M[u][k].len != INF && used[k] == 0){    //������u�����ĵ�
                if(M[u][k].type == 0){         //��·
                    if(dis[u] + M[u][k].len < dis[k]){
                        dis[k] = dis[u] + M[u][k].len;
                        small_len[k] = 0;
                    }
                }else if(M[u][k].type == 1){   //С·
                    if(dis[u] - SD(small_len[u]) + SD(small_len[u] + M[u][k].len) < dis[k]){
                        dis[k] = dis[u] - SD(small_len[u]) + SD(small_len[u] + M[u][k].len);
                        small_len[k] = small_len[u] + M[u][k].len;
                    }
                }
            }
        }
    }

    cout << dis[n] << endl;
}
