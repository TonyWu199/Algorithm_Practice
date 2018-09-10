#include <stdio.h>
#include <string.h>

int main(){
    char input[101];
    
    while(1){
        scanf("%s",input);
        for(int i=0; i<strlen(input); i++){
        	int bit[7];
            bit[0] = input[i] & 0x01;
            bit[1] = (input[i] & 0x02) >> 1;
            bit[2] = (input[i] & 0x04) >> 2;
            bit[3] = (input[i] & 0x08) >> 3;
            bit[4] = (input[i] & 0x10) >> 4;
            bit[5] = (input[i] & 0x20) >> 5;
            bit[6] = (input[i] & 0x40) >> 6;
            
            int num = 0;
            for(int i=0; i<7; i++){
            	if(bit[i] == 1)
            		num++;
			}
			
			if(num % 2 == 0){
				printf("1");
			}else{
				printf("0");
			}
			
			for(int i=6; i>=0; i--){
            	printf("%d", bit[i]);
			}
			
			printf("\n");
        }
    }
}
