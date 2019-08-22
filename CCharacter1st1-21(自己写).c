#include <stdio.h>

#define TABLENGTH 8//����̨���Ʊ�������ԣ�ÿ8���ַ���һ���Ʊ����־λ������8���ַ���ʱ��ʹ���Ʊ����������

int main(){
	int blockNum = 0;//�ո�����
	int position = 1;//�ڿ���̨����ĵ�ǰ�ַ���λ��
	char c;
	while((c = getchar()) != EOF	){
		if(c == ' '){
			blockNum ++;//ÿ����һ���ո�ͼ���һ��
			if(blockNum == (TABLENGTH - ((position - 1) % TABLENGTH))){
                /*
                *���õ�ǰ��λ����ո������ж��Ƿ񵽴��־λ����������ֱ������Ʊ��������Ϊ�ַ�λ�ý���ǰ��
                */
				putchar('\t');
				position += blockNum;
				blockNum = 0;//�Ʊ���������һ�ֵĿո������������Ϊ0
			}
		}else if(c == '\n'){//���������ǻس�����ͨ���ж���ǰ���ܵĻ��ж��ٿո�û���룬����ո�������س�������
			while(blockNum > 0){
				putchar(' ');
				blockNum --;
			}
			putchar(c);
			position = 1;//�س����к�λ��������Ϊ1
		}else{//������������ͨ�ַ����жϵ�ǰ�����˶��ٻس������û�л��ܣ���λ��ǰ�ƣ�����ַ�����������ˣ�������ո�������ַ�
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
