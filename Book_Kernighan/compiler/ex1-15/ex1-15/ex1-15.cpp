// ex1-15.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
float trans(float fahr);

int main()
{
	float fahr;

	for (fahr = 0; fahr < 300; fahr = fahr + 20)
		printf("%6.1f %8.1f\n", fahr, trans(fahr));
    return 0;
}

float trans(float m)
{
	float i;
	i = (5.0 / 9.0)*(m - 32);
	return i;
}
