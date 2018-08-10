#include <iostream>

using namespace std;

int check(int *, int n);



/*
    这道题其实代码很少，但是注意这种循环的题目，需要弄清楚循环终止的信号-还剩一个小朋友
    方便起见可以将其写成函数，每删除掉一个小朋友之后就检测一遍。
    这种题主要是逻辑的连续性，可以先一口气将思路写出来，再通过I/O展示中间过程来DEBUG
    切忌空纸白想，这样会千丝万缕理不顺。
*/
int main()
{
    int n,k;
    cin >> n >> k;

    int child[n];
    for(int i=0; i<n; i++){
        child[i] = 1;
    }

    int i=0;
    int num=1;

    while(i>=0){
        if(child[i % n] == 1){
//            cout << i % n << "报数";
            //这里注意num / k会四舍五入
            if((num % 10 == k) || (num % k == 0)){
                child[i % n] = 0;
//                cout << "淘汰";
                if(check(child, n)){   //还剩一个幸存
                   break;
                }
            }
//            cout << endl;
            num++;
        }else{
            ;
        }
        i++;
    }

    for(int i=0; i<n; i++){
        if(child[i] == 1){
            cout << i+1;
        }
    }


}


int check(int * child, int n){
    int num=0;
    for(int i=0; i<n; i++){
       if(child[i] == 1){
            num++;
       }
    }

    if(num == 1)
        return 1;
    else
        return 0;
}
