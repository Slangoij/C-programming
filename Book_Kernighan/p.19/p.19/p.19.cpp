// p.19.cpp : �ܼ� ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"

int main()
{
	float ceo;
	ceo = 0;
	
	for (ceo = 300; ceo >= 0; ceo = ceo - 20)
		printf("%5.1f %5.1f\n", ceo, ceo*(9.0 / 5.0) + 32);

}
