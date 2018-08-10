#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int input[40];   //这道题首先提交为30分，错就错在input[30]定义小了，坑人啊，所以以后这种题目定义大一些总没错！
    int a, i=0;;

    char c;
    //注意这里的换行技巧，通过getchar()来读取换行符,其他时候读取的是空格
    while(cin >> a && ((c = getchar()) != '\n')){
        input[i++] = a;
    }

    int flag = 0; //用来标志上一次跳跃是否为2
    int last_score = 0; //上一次加的分数
    int sum = 0;

    i = 0;
    while(input[i] != 0){
        if(input[i] == 1){
            sum += 1;
            last_score = 1;
        }else if(input[i] == 2){
            if(last_score <= 1){    //last_score为0或1表示上一次得分为1或本局游戏第一次跳跃
                sum += 2;
                last_score = 2;
            }else{
                sum += last_score + 2;
                last_score = last_score + 2;
            }
        }
        i++;
    }

    cout << sum;
}
