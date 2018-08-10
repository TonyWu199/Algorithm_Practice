#include <iostream>

using namespace std;

#define MOD 1000000007

int main()
{
    long long n;
    cin >> n;

    long long dp[1010][6];

    for(long long i=0; i<n; i++){
         dp[i+1][0] = 1;  //要想保持只能一直填2
         dp[i+1][1] = (dp[i][0] + dp[i][1]*2) % MOD;
         dp[i+1][2] = (dp[i][0] + dp[i][2]) % MOD;
         dp[i+1][3] = (dp[i][1] + dp[i][2] + dp[i][3]*2) % MOD;
         dp[i+1][4] = (dp[i][1] + dp[i][4]*2) % MOD;
         dp[i+1][5] = (dp[i][3] + dp[i][4] + dp[i][5]*2) % MOD;
    }

    cout << dp[n][5] << endl;


    return 0;
}
