#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, M = 10001, tmp;
    cin >> n;
    int num[n];

    for(int i=0;i <n; i++){
        cin >> num[i];
    }

    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            tmp = abs(num[i] - num[j]);
            if(tmp < M)
                M = tmp;
        }
    }

    cout << M;
}
