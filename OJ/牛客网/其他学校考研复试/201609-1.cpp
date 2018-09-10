#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> s;
    for(int i=0; i<n; i++){
        int m;
        cin >> m;
        s.push_back(m);        
    }
    
    int Max = 0;
    for(int i=0; i<s.size()-1; i++){
        if(abs(s[i+1] - s[i]) > Max)
        	Max = abs(s[i+1] - s[i]);
    }
    
    cout << Max << endl;
}

