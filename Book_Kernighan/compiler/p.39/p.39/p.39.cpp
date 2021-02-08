// p.39.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#define MAXLINE 1000 //맥시멈 라인 길이//


int getline(char line[], int maxline);
void copy(char to[], char from[]);

int main()
{
	int len;
	int max;
	char line[MAXLINE];
	char longest[MAXLINE];
	
	max = 0;
	while((len=getline(line,MAXLINE))>0)
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	if (max > 0)
		printf("%s", longest);
	return 0;
}

int getline(char s[], int lim) //라인 읽어오기 함수
{
	int c, i;

	for (i = 0; i < lim-1 && (c = getchar()) != EOF&&c != '\n'; ++i)
		s[i] = c;
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[]) //열 복사하기
{
	int i;

	i = 0;
	while ((to[i] = from[i]) != '\n')
		++i;
}