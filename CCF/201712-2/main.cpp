#include <iostream>

using namespace std;

int check(int *, int n);



/*
    �������ʵ������٣�����ע������ѭ������Ŀ����ҪŪ���ѭ����ֹ���ź�-��ʣһ��С����
    ����������Խ���д�ɺ�����ÿɾ����һ��С����֮��ͼ��һ�顣
    ��������Ҫ���߼��������ԣ�������һ������˼·д��������ͨ��I/Oչʾ�м������DEBUG
    �мɿ�ֽ���룬������ǧ˿������˳��
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
//            cout << i % n << "����";
            //����ע��num / k����������
            if((num % 10 == k) || (num % k == 0)){
                child[i % n] = 0;
//                cout << "��̭";
                if(check(child, n)){   //��ʣһ���Ҵ�
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
