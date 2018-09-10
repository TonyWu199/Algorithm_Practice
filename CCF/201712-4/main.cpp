#include <iostream>
#include <algorithm>

using namespace std;

typedef struct info{
    int type;
    int len;
    long long cost;
}info;

//lineΪ��ǰ��·�ţ� type2_lenΪ0���ʾ��һ�β�ΪС��,ע������type1_len��ÿһ��ѭ���в����޸�
long long solve(info* road, int line, int type1_len, int road_num){
    if(line == road_num){
        if(type1_len != 0){
            return type1_len * type1_len;
        }else{
            return 0;
        }
    }

    long long Min = 1e18;
    for(int col=1; col<=road_num; col++){
        info cur = *(road + line*(road_num+1) + col);
        long long _type1_len = 0;;
        if(cur.len != 0){
            if(cur.type == 0){  //���
                long long type1_cost = 0;
                if(type1_len != 0){
                    type1_cost = type1_len * type1_len;
                    _type1_len = 0;
                }
                long long cost = solve(road, col, _type1_len, road_num);
                if(cost + cur.len + type1_cost < Min){
                    Min = cost + cur.len + type1_cost;
                }
            }else if(cur.type == 1){   //С��
                _type1_len = type1_len + cur.len;
                if(solve(road, col, _type1_len, road_num) < Min){
                    Min = solve(road, col, _type1_len, road_num);
                }
            }
        }
    }

    return Min;
}


int main()
{
    long long n, m;
    info road[1010][1010];   //��·����

    for(int i=0; i<=n; i++){
        for(int j=0; j<=n; j++){
            road[i][j].type = -1;   //i->j·�ڲ�ͨ
            road[i][j].len = 0;
            road[i][j].cost = 1e18;
        }
    }

    for(int i=0; i<m; i++){
        long long t,a,b,c;
        cin >> t >> a >> b >> c;
        road[a][b].type = t;
        road[a][b].len = c;
        //road[b][a].type = t;
        //road[b][a].len = c;
    }

    cout << solve((info *) road, 1, 0, n) << endl;
}
