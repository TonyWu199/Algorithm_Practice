#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int input[40];   //����������ύΪ30�֣���ʹ���input[30]����С�ˣ����˰��������Ժ�������Ŀ�����һЩ��û��
    int a, i=0;;

    char c;
    //ע������Ļ��м��ɣ�ͨ��getchar()����ȡ���з�,����ʱ���ȡ���ǿո�
    while(cin >> a && ((c = getchar()) != '\n')){
        input[i++] = a;
    }

    int flag = 0; //������־��һ����Ծ�Ƿ�Ϊ2
    int last_score = 0; //��һ�μӵķ���
    int sum = 0;

    i = 0;
    while(input[i] != 0){
        if(input[i] == 1){
            sum += 1;
            last_score = 1;
        }else if(input[i] == 2){
            if(last_score <= 1){    //last_scoreΪ0��1��ʾ��һ�ε÷�Ϊ1�򱾾���Ϸ��һ����Ծ
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
