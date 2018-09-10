#include <iostream>
#include <algorithm>
#define len 3

using namespace std;

/*这道题在开始做的时候陷入一个误区。。。总想着怎么找到最佳的填子方式
然后再根据填子的方式进行分数的计算。
其实这道题的分数就是一个很好的利用点！可以利用类似于动态规划的思想来解决这道题
每次填写都保证分数最高(低)，那么就能得出最后的结果！
*/

//对当前棋局的胜者进行判断，返回胜者编号，如果没有胜者则返回0
int Winner(int* M){
    for(int i=0; i<len; i++){
        //对行进行判断
        if(*(M + i*len + 0) == *(M + i*len + 1) && *(M + i*len + 1) == *(M + i*len + 2)){
            if(*(M + i*len + 0) != 0)
                return *(M + i*len + 0);
        }

        //对列进行判断
        if(*(M + 0*len + i) == *(M + 1*len + i) && *(M + 1*len + i) == *(M + 2*len + i)){
            if(*(M + 0*len + i) != 0)
                return *(M + 0*len + i);
        }
    }

    if(*(M + 0*len + 0) == *(M + 1*len + 1) && *(M + 1*len + 1) == *(M + 2*len + 2))
        if(*(M + 1*len + 1) != 0)
            return *(M + 1*len + 1);

    if(*(M + 0*len + 2) == *(M + 1*len + 1) && *(M + 1*len + 1) == *(M + 2*len + 0))
        if(*(M + 1*len + 1) != 0)
            return *(M + 1*len + 1);

    return 0;
}

//0的个数
int zero(int* M){
    int sum = 0;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(*(M + i*len + j) == 0)
                sum++;
        }
    }

    return sum;
}

//对棋局进行算分
int get_score(int* M){
    int sum = 0;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(*(M + i*len + j) == 0)
                sum++;
        }
    }

    if(Winner((int*) M) == 1){
        return sum + 1;
    }else if(Winner((int*) M) == 2){
        return -1 * (sum + 1);
    }else{
       return 0;  //未结束
    }

}

int play(int* M, int player){
    //一开始就判断是否平局，dfs的返回条件，这种条件多看！
    //这里表示系统为判定结束，但是格子已填完！表示平局。
    if(zero((int*) M) == 0)
        return 0;

//    printf("------\n");
//    for(int i=0; i<len; i++){
//        printf("%d %d %d\n", *(M + i*len + 0), *(M + i*len + 1), *(M + i*len + 2));
//    }
    int Max = -10, Min = 10;
    for(int i=0; i<len; i++){
        for(int j=0; j<len; j++){
            if(*(M + i*len + j) == 0){
                *(M + i*len + j) = player;
                int score = get_score((int *) M);
                if(score){   //当结束
                    *(M + i*len + j) = 0;
                    return score>0?max(Max, score):min(Min,score);
                }

                if(player == 1)
                    Max = max(Max, play((int*) M, 2));
                else
                    Min = min(Min, play((int*) M, 1));
                *(M + i*len + j) = 0;
            }
        }
    }

    return player==1?Max:Min;
}

int main()
{
    int n, M[len][len];
    scanf("%d", &n);

    while(n--){
        //输入矩阵
        for(int i=0; i<len; i++){
            scanf("%d %d %d", &M[i][0], &M[i][1], &M[i][2]);
        }

        if(Winner((int*) M) == 1 || Winner((int*) M) == 2){
            cout << get_score((int*) M) << endl;
        }else{
            cout << play((int*) M, 1) << endl;
        }
    }

}
