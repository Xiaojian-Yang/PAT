#include<stdio.h>
#include<stdlib.h>
#define MAX 100

void Sort_Max_Min(int *verify,int m);  //排序从大到小 

int main()
{
	int a,i,j,k=0,sum,n,m,q=0,verify[MAX]; //定义输入样例k，被验证数为key[MAX] 
	scanf("%d",&m);
	int keyN[m]; //声明存储关键数的数组 
	for(i=0;i<m;i++)
	{  //读入被验证数 
		scanf("%d",&verify[i]);
	}
	for(i=0;i<m;i++)
	{ //共有m个验证数，则要有m个循环 
		n=verify[i];
		while(n!=1)
		{  //计算m个验证数的猜想是否成立 
			k++; //计算m个验证数所计算的次数 
			if(n%2)
			{
				n=(3*n+1)/2;
			}
			else
			{
				n=n/2;
			}
		}
	}
	int *p=(int *)malloc(sizeof(int)*k);  //向系统同申请内存，存储每个验证数所计算的数
	j=0;
	for(i=0;i<m;i++)
	{ //共有m个验证数，则要有m个循环 
		n=verify[i];
		while(n!=1)
		{  //将每个验证数所计算的k个数，保存在数组p[j]中 
			p[j]=n; //保存验证数要计算所得数 
			if(n%2)
			{
				n=(3*n+1)/2;
			}
			else
			{
				n=n/2;
			}
			j++;
		}
	} 
	for(j=0;j<m;j++)  //判断m个验证数是否与k个计算数相等 
	{ //若待验证数与计算数想等
		sum=0;
		a=0;
		while(a<k) //共有k个计算的数 
		{
			if(verify[j]==p[a])
			{
				sum++;  //计算验证数verify[j]是否在计算中存在 
			}
			a++;
		}
		if(sum<=1) 
		{
			keyN[q]=verify[j];
			q++;
		}
	}
	free(p);
	Sort_Max_Min(keyN,q);
	return 0;
}
void Sort_Max_Min(int *verify,int m)
{
	int i,j,temp;
	for(i=0;i<m-1;i++)  //排序从大到小， 
	{
		for(j=i+1;j<m;j++)
		{
			if(verify[i]<verify[j])
			{
				temp=verify[i];
				verify[i]=verify[j];
				verify[j]=temp;
			}
		}
		printf("%d",verify[i]);
		printf(" ");
	}
	printf("%d",verify[m-1]); //打印最后一个数，且后边没有空格 
}
