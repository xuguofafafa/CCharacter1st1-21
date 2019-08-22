#include <stdio.h>

#define TABLENGTH 8

int main(){
	int blockNum = 0;
	int position = 1;
	char c;
	while((c = getchar()) != EOF	){
		if(c == ' '){
			blockNum ++;
			if(blockNum == (TABLENGTH - ((position - 1) % TABLENGTH))){
				putchar('\t');
				blockNum = 0;
				position += blockNum;
			}
				
		}else if(c == '\n'){
			putchar(c);
			position = 1;
		}else{
			if(blockNum != 0){
				while(blockNum > 0){
					putchar(' ');
				}
				position = position + blockNum +1;
				blockNum = 0;
			}else{
				position ++;
			}
			putchar(c);
		}
	}
	return 0;
}