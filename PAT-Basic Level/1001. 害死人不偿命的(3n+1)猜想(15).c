#include<stdio.h>

int main()
{
	int n,m,count=0;
	scanf("%d",&n);
	while(n!=1)
	{
		m=n%2;
		if(m!=0)
		{
			n=(3*n+1)/2;
		}
		else
		{
			n=n/2;
		}
		count++;
	}
	printf("%d",count);
	return 0;
}
