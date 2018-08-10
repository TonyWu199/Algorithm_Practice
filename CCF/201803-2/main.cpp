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
        //���ȼ���Ƿ���������ײ�������ڱ�Ե�����������ı䷽��
        //������Ҫע�ⲻ����ȫ�������������ж���ײ������ᵼ���ظ�����
        //��ȷ�������ǽ��ڶ��μ�����������óɵ�һ�μ�����j
        for(int j=0;j<n;j++){
            //���ڱ�Ե
            if(ball[j].loc == 0 || ball[j].loc == L){
                ball[j].direction = -ball[j].direction;
            }
            //������ײ
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
