#include <stdio.h>
#include <math.h>

int bit2int(int b){
	int flag = 0, sum = 0;
	do{
		sum += b%10 * pow(2, flag++);
		b /= 10;
	}while(b != 0);
	
	return sum; 
}

void int2bit(int i){
	if(i == 1){
		printf("1");
		return;
	}
	
	int2bit(i/2);
	printf("%d", i%2);
	return;
}

int main(){
	int a, b, res;
	char c;
	
	while(scanf("%d %d %c", &a, &b, &c) != EOF){
		a = bit2int(a);
		b = bit2int(b);
		if(c == '+'){
			res = a + b;
			int2bit(res);
			putchar('\n');
		}else if(c == '-'){
			res = a - b;
			int2bit(res);
			putchar('\n');
		}else if(c == '*'){
			res = a * b;
			int2bit(res);
			putchar('\n');
		}else if(c == '/'){
			res = a / b;
			int2bit(res);
			putchar('\n');
		}
	}
} 
