#include <stdio.h>
#include <string.h>
#define maxv 200

int main(){
	char s[maxv], t[maxv];
	scanf("%s", s);
	memcpy(t, s, strlen(s));
	
	for(int i=0; i<strlen(s); i++){
		if(s[i] == '#')
			continue;
		for(int j=i+1; j<strlen(s); j++){
			if(s[j] == s[i]){
				s[j] = '#';
			}
		}
	}
	
//	for(int i=0; i<strlen(s); i++){
//		if(s[i] != '#')
//			printf("%c", s[i]);
//	}
	
	for(int i=0; i<strlen(t); i++){
		if((t[i] >= '0' && t[i] <= '9') || (t[i] >= 'A' && t[i] <= 'F') || (t[i] >= 'a' && t[i] <= 'f')){
			printf("%x ",(t[i] & 0x08) >> 3);
			printf("%x ",(t[i] & 0x04) >> 1);
			printf("%x ",(t[i] & 0x02) << 1);
			printf("%x ",(t[i] & 0x01) << 3);
			printf("%x\n",(t[i] & 0xf0) | ((t[i] & 0x08) >> 3) | ((t[i] & 0x04) >> 1) | ((t[i] & 0x02) << 1) | ((t[i] & 0x01) << 3));
		}
	}
}
