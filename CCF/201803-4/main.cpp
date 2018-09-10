#include <iostream>
#include <algorithm>
#define len 3

using namespace std;

/*������ڿ�ʼ����ʱ������һ��������������������ô�ҵ���ѵ����ӷ�ʽ
Ȼ���ٸ������ӵķ�ʽ���з����ļ��㡣
��ʵ�����ķ�������һ���ܺõ����õ㣡�������������ڶ�̬�滮��˼������������
ÿ����д����֤�������(��)����ô���ܵó����Ľ����
*/

//�Ե�ǰ��ֵ�ʤ�߽����жϣ�����ʤ�߱�ţ����û��ʤ���򷵻�0
int Winner(int* M){
    for(int i=0; i<len; i++){
        //���н����ж�
        if(*(M + i*len + 0) == *(M + i*len + 1) && *(M + i*len + 1) == *(M + i*len + 2)){
            if(*(M + i*len + 0) != 0)
                return *(M + i*len + 0);
        }

        //���н����ж�
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

//0�ĸ���
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

//����ֽ������
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
       return 0;  //δ����
    }

}

int play(int* M, int player){
    //һ��ʼ���ж��Ƿ�ƽ�֣�dfs�ķ������������������࿴��
    //�����ʾϵͳΪ�ж����������Ǹ��������꣡��ʾƽ�֡�
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
                if(score){   //������
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
        //�������
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
