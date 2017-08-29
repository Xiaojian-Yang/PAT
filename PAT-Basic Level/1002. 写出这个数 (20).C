#include<stdio.h>

void Print(int sum,int n);

int main()
{
	char n;
	int i,p,sum=0;
	printf("请输入一个自然数n:");
	n=getchar();     //将输入的数字按照字符的形式一个一个的读入，直到读到回车键\n为止 
	while(n!='\n')
	{
		sum=sum+n-'0';    //将 字符型的数字，强制转换为整型，按照它对应的ASCII值计算 
		n=getchar();
	}
//	printf("%d\n",sum);
	p=sum/10;
	for(i=1;p!='\0';i++)  //计算sum的位数 
	{
//		printf("%d\n",p);
		p=p/10;
	}
//	printf("%d",i);
	Print(sum,i);
	return 0;
}

void Print(int sum,int n)
{
	int m[n],i=0;
	char *number[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
	m[i]=sum%10;
	sum=sum/10;
	while(sum!=0)
	{
		i++;
		m[i]=sum%10;
		sum=sum/10;
	}
	for(;i>0;i--)
	{
		printf("%s",number[m[i]]);
		printf(" ");
	}
	printf("%s",number[m[0]]);
}
