#include<stdio.h>

int main()
{
	int i,j,n,sum[3];
	scanf("%d",&n);
	sum[0]=n%10;
	n=n/10;
//	printf("sum[0]=%d\n",sum[0]);
	while(n!=0) 
	{  //保存输入的数据的每一位上的数，sum[i]数组中i越大保存这高位上的数值 
		i++;
		sum[i]=n%10;
		n=n/10;
//		printf("sum[%d]=%d\n",i,sum[i]);
	}
	switch (i)
	{
		case 0:
		{ //说明输入的数为一个一位数 
			for(j=1;j<=sum[i];j++)
			{
				printf("%d",j);
			}
			break;
		}
		case 1:
		{ //说明输入的数为一个两位数 
			for(j=1;j<=sum[i];j++)
			{  //先打印十位上的数 
				printf("S");
			}
			for(j=1;j<=sum[i-1];j++)
			{  //打印个位上的数 
				printf("%d",j); 
			}
			break;
		}
		case 2:
		{ //说明输入的数为一个三位数 
			for(j=1;j<=sum[i];j++)
			{  //打印百位上的数 
				printf("B");
			}
			for(j=1;j<=sum[i-1];j++)
			{  //打印十位上的数 
				printf("S");
			}
			for(j=1;j<=sum[i-2];j++)
			{  //打印个位上的数 
				printf("%d",j);
			}
			break;
		}
	}
	return 0;
}
