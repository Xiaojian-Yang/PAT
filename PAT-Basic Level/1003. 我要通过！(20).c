#include<stdio.h>
#include<string.h>

int main()
{
	int n,i,j,m;
	char pat[100];
	scanf("%d",&n);
	getchar();//读走回车键 
	while(n--)
	{
		int sumP=0,sumA=0,sumT=0;   //记录字符串中P、A、T的数量 
		gets(pat);
		m=strlen(pat);
//		p=strchr(pat,'P');
//		t=strchr(pat,'T');
//		printf("the string lenth=%d\n",m);
		for(i=0;i<m;i++)
		{//统计字符串中字符P、A、T的个数 
//			if((pat[i]!='P')&&(pat[i]!='A')&&(pat[i]!='T'))
//			{  //判断字符串中是否存在其他的字符 
//				printf("NO\n");
//				break;
//			} 
			if(pat[i]=='P')
			{
				sumP=sumP+1;
			}
			else if(pat[i]=='A')
			{
				sumA=sumA+1;
			}
			else if(pat[i]=='T')
			{
				sumT=sumT+1;
			}
		}
//		printf("%5d%5d%5d\n",sumP,sumA,sumT);
		if((m>=3)&&(m==sumP+sumA+sumT)&&(sumP==1)&&(sumT==1)) 
		//保证字符串中的字符有且仅有P、A、T 组成，且字符P和T有且只有一个 
		//且字符T在字符P的之后 
		{
//			printf("N------Y---10\n");
			for(i=0;i<m;i++)
			{
//				printf("N------Y---10----i=%d\n",i);
				if(pat[i]=='P') 
				{//先寻找字符P的位置i
					if(pat[i+1]=='A')  
					{ //保证字符P位置后紧跟着字符A
//						printf("N------Y---20\n");
						for(j=i+2;j<m;j++)
						{//寻找字符为T的位置，并保证字符T在字符P之后 如果T不在P之后，则为NO 
//							printf("N------Y---20----j=%d\n",j);
							if(pat[j]=='T')
							{//T后A的数量=P前A的数量+（PT之间A的数量-1）*P前A的数量
								if((m-1-j)==(i+(j-1-i-1)*i))
								{
//									printf("N------Y---30\n");
									printf("YES\n");
									break;
								}
								else
								{//如果这个等式不相等，则为NO 
									printf("NO\n");
									break;
								}
							}
							else if((j==m)&&(pat[j]!='T'))
							{//判断字符T在字符P之后 
								printf("NO\n");
								break;
							} 
						}
					}
					else
					{//字符P后不是紧跟着字符A，则是错误的 
						printf("NO\n");
						break;
					} 
				}
			} 
		}
		else
		{
			printf("NO\n");
		}
	}
	return 0;
} 
