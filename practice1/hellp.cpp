#include <stdio.h>//<> represent the systerm variable,call from OS,"" from current
#include "max.h"

int main()
{
	int a1=33;
	int a2=21;
	int maxNum=max(a1,a2);
	printf("the max number is %d\n",maxNum);
	return 0;

}
