#include <stdio.h>
#include <string.h>

struct employee
{
	char name[10];
	int year;
	int pay;
};

void main()
{
	struct employee Lee;
	struct employee *Sptr = &Lee;
	strcpy_s(Sptr->name, 8, "�̼���");
	Sptr->year = 2005;
	Sptr->pay = 2009;

	printf("\n �̸� : %s", Sptr->name);
	printf("\n �Ի� : %d", Sptr->year);
	printf("\n ���� : %d", Sptr->pay);
}