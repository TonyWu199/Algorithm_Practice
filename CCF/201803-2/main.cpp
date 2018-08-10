#include <iostream>

using namespace std;

typedef struct BALL{
    int loc;
    int direction;
}BALL;

int main()
{
   int n,L,t;
   cin >> n >> L >> t;

   BALL ball[n];
   for(int i=0; i<n;i++){
        cin >> ball[i].loc;
        ball[i].direction = 1;
   }

   for(int i=1; i<=t; i++){
        //首先检查是否有正在碰撞或者正在边缘的球，如果有则改变方向
        //这里需要注意不能完全遍历两次球来判断相撞情况，会导致重复检索
        //正确的做法是将第二次检索的起点设置成第一次检索的j
        for(int j=0;j<n;j++){
            //球在边缘
            if(ball[j].loc == 0 || ball[j].loc == L){
                ball[j].direction = -ball[j].direction;
            }
            //两球相撞
            for(int k=j;k<n;k++){
                if(ball[k].loc == ball[j].loc && (k != j)){
                    ball[k].direction = -ball[k].direction;
                    ball[j].direction = -ball[j].direction;
                }
            }
        }

        for(int m=0; m<n; m++){
            ball[m].loc += ball[m].direction;
        }
//        for(int o=0; o<n; o++){
//            cout << ball[o].loc << " ";
//        }
//        cout << endl;
   }

   for(int o=0; o<n; o++){
        cout << ball[o].loc << " ";
   }
}
