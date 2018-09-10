#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int maxn = 1010;
vector<int> Z[maxn], rZ[maxn], S[maxn];  //构建正向和逆向邻接表
int visit[maxn];
int N,M;

//a标志起始点，b标志每次递归的起始点
void dfs(int a, int b, vector<int> s[maxn]){
    for(int i=0; i<s[b].size(); i++){
        if(visit[s[b][i]] == 0){
            visit[s[b][i]] = 1;
            dfs(a, s[b][i], s);
        }
    }
    S[a].push_back(b);
}

int main()
{
    cin >> N >> M;

    int a, b;
    for(int i=0; i<M; i++){
        cin >> a >> b;
        Z[a-1].push_back(b-1);
        rZ[b-1].push_back(a-1);
    }

    for(int i=0; i<N; i++){
        memset(visit, 0, sizeof(visit));
        dfs(i, i, Z);
        memset(visit, 0, sizeof(visit));
        dfs(i, i, rZ);
    }


    int cnt = 0;
    for(int i=0; i<N; i++){
        memset(visit, 0, sizeof(visit));
        for(int j=0; j<S[i].size(); j++){
            visit[S[i][j]] = 1;
        }

        //注意这里的逻辑
        bool flag = false;
        for(int j=0; j<N; j++){
            if(visit[j] == 0){
                flag = 1;
            }
        }

        if(flag == false)
            cnt++;
    }

    cout << cnt;
}
