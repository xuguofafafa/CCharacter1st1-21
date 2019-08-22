#include <stdio.h>

#define TABLENGTH 8

int main(){
	int blockNum = 0;
	int tabNum = 0;
	int position ;
	char c;
	for(position = 1;(c = getchar()) != EOF;position ++ ){
		if(c == ' '){
            if(position % TABLENGTH != 0){
                blockNum ++;
            }else{
                blockNum = 0;
                tabNum ++;

            }
		}else{
			for( ;tabNum > 0;tabNum --){
                putchar('\t');
			}
			if(c == '\t'){
                blockNum = 0;
			}else{
			    for( ;blockNum > 0;blockNum --){
                    putchar(' ');
			    }
			}
			putchar(c);
			if(c == '\n'){
                position = 0;

			}else if(c == '\t'){
			    position = position + (TABLENGTH - (position - 1) % TABLENGTH) - 1;

			}
		}
	}
	return 0;
}
