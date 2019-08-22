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
				position += blockNum;
				blockNum = 0;
			}
				
		}else if(c == '\n'){
			while(blockNum > 0){
				putchar(' ');
				blockNum --;
			}
			putchar(c);
			position = 1;
		}else{
			position ++;
			if(blockNum != 0){
				while(blockNum > 0){
					putchar(' ');
					blockNum --;
				}
				position += blockNum;
				blockNum = 0;
			}
			putchar(c);
		}
	}
	return 0;
}