#include <iostream>

using namespace std;

int Seat[20][5];

int count_1(int line){
	int count = 0;
	for(int i=0; i<5; i++)
		if(Seat[line][i] == 1)
			count++;
	return count;
}

int main(){
	int n, m;
	cin >> n;
	
	for(int i=0; i<n; i++){
		cin >> m;
		int j;
		for(j=0; j<20; j++){
			int bought = count_1(j);
			if(bought + m > 5){
				continue;
			}else{
				for(int k=bought; k<bought + m; k++){
					Seat[j][k] = 1;
					cout << j*5 + k + 1 << " ";
				}
				break;
			}
		}
		
		//Ã»ÓÐÁ¬×ø 
		if(j == 20){
			for(int p=0; p<20; p++){
				for(int k=0; k<5; k++){
					if(Seat[p][k] == 0){
						Seat[p][k] = 1;
						cout << p*5 + k + 1 << " ";
						m--;
					}
					if(m == 0)
						break;
				}
				if(m==0)
					break;
			} 
		} 
		
		cout << endl;
	}	
}
