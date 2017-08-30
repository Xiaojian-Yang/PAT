#include<stdio.h>
#define NAME 15
#define ID  15


struct stu
{//定义学生的的类型 
	char name[NAME];
	char stuID[ID];
	int score;
};
typedef struct stu STU;


void StuMin(STU *student,int m); //搜索最小值 
void StuMax(STU *student,int m); //搜素最大值 

int main() 
{
	int i,j,n;
	scanf("%d",&n);   //输入学生人数
	STU student[n];
	for(i=0;i<n;i++)
	{
		scanf("%s",student[i].name); //student[i].name直接是地址 
		scanf("%s",student[i].stuID); //student[i].stuID直接是地址
		scanf("%d",&student[i].score); //student[i].score不是是地址
	}
	StuMax(student,n);
	StuMin(student,n);
	return 0;
}

void StuMax(STU *student,int m)
{
	int i,j=0,max=student[j].score;
	for(i=1;i<m-1;i++)  //一共有m-1个数比较 
	{
		if(max<student[i].score) //判断一个数与其后一个数的大小
		{
			max=student[i].score;
			j=i; //记录下这个大数的位置 
		}
	}
	printf("%s %s\n",student[j].name,student[j].stuID); 
}

void StuMin(STU *student,int m)
{
	int i,j=0,min=student[j].score;
	for(i=1;i<m;i++)  //一共有m-1个数比较
	{
		if(min>student[i].score) //判断一个数与其后一个数的大小
		{
			min=student[i].score;
			j=i;
		}
	}
	printf("%s %s\n",student[j].name,student[j].stuID);
}
