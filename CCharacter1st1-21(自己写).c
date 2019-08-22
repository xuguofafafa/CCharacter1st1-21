#include <stdio.h>

#define TABLENGTH 8//控制台中制表符的特性，每8个字符有一个制表符标志位，不满8个字符的时候，使用制表符可以填满

int main(){
	int blockNum = 0;//空格数量
	int position = 1;//在控制台输出的当前字符的位置
	char c;
	while((c = getchar()) != EOF	){
		if(c == ' '){
			blockNum ++;//每输入一个空格就计数一个
			if(blockNum == (TABLENGTH - ((position - 1) % TABLENGTH))){
                /*
                *利用当前的位置与空格数量判断是否到达标志位，如果到达就直接输出制表符，并将为字符位置进行前移
                */
				putchar('\t');
				position += blockNum;
				blockNum = 0;//制表符输出后，这一轮的空格计数结束，置为0
			}
		}else if(c == '\n'){//如果输入的是回车键，通过判定当前积攒的还有多少空格没输入，输完空格再输出回车键换行
			while(blockNum > 0){
				putchar(' ');
				blockNum --;
			}
			putchar(c);
			position = 1;//回车换行后将位置重新置为1
		}else{//如果输入的是普通字符，判断当前积攒了多少回车，如果没有积攒，就位置前移，输出字符，如果积攒了，先输出空格再输出字符
			position ++;
			if(blockNum != 0){
                position = position + blockNum;
				while(blockNum > 0){
					putchar(' ');
					blockNum --;
				}

				blockNum = 0;
			}

			putchar(c);


		}
	}
	return 0;
}
