#include "hero.h"
#include <stdio.h>

int readhero(Hero *hero,int n)    /*读入英雄记录值，编号为0或读满规定条数记录时停止*/
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("请输入英雄信息：\n");
		printf("num:  ");
		scanf("%d",&hero[i].num);
		if (hero[i].num==0) break;
		printf("name: ");
		scanf("%s",hero[i].name);
		printf("character: ");
        scanf("%s",hero[i].character); 
		printf("Input four skills of the hero:\n");
		scanf("%s",&hero[i].skill);
		printf("partner: ");
        scanf("%s",hero[i].partner);
        printf("rival: ");
        scanf("%s",hero[i].rival);
        printf("wins: ");
        scanf("%d",&hero[i].wins);
        printf("appearance: ");
        scanf("%d",&hero[i].appearance);
        printf("kills: ");
        scanf("%lf",&hero[i].kill);
        printf("death: ");
        scanf("%lf",&hero[i].death);
		printf("rate: ");
		scanf("%lf",&hero[i].rate);
		hero[i].rank=0;
	}
		return i;                           /*返回实际读入的记录条数*/
}

void printhero (Hero *hero,int n)                /*输出所有英雄记录的值*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%4ld",hero[i].num);
		printf("%6s",hero[i].name);
		printf("%6s",hero[i].character);
		printf("%45s",hero[i].skill);
		printf("%8s",hero[i].partner);
		printf("%8s",hero[i].rival);
		printf("%8d",hero[i].wins);
		printf("%8d",hero[i].appearance);
		printf("%8.1f",hero[i].kill);
		printf("%8.1f",hero[i].death);
		printf("%8.2f%%\n",hero[i].rate);
	}
}

void printBhero(Hero *hero,int n)             /*打印B表头*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%4ld",hero[i].num);
		printf("%6s",hero[i].name);
		printf("%8.2f%%\n",hero[i].rate);
	}
}


int equal(Hero h1,Hero h2,int condition)         /*如何判断两个Hero记录相等*/
{
	if (condition==1)                          /*如果参数condition的值为1，则比较编号*/
		return h1.num==h2.num;
	else if (condition==2)                           /*如果参数condition的值为2，则比较名称*/
	{
		if (strcmp(h1.name,h2.name)==0)
			return 1;
		else return 0;
	}
	else if (condition==3)
		return h1.rank==h2.rank;
	else if (condition==4)
		return h1.rate==h2.rate;
	else return 1;
}
 
int larger(Hero h1,Hero h2,int condition)                    /*根据condition条件比较两个Hero记录的大小*/
{
	if(condition==1)
		return h1.num>h2.num;
	if(condition==2)
		return h1.rate>h2.rate;
	else 
		return 1;
}

int searchhero(Hero hero[],int n,Hero h,int condition,int f[ ])/*在stu数组中依condition条件查找*/
/*与s相同的元素，由于不止一条记录符合条件，因此将这些元素的下标置于 f数组中*/
{
	int i,j=0,find=0;
	for(i=0;i<n;i++)
		if(equal(hero[i],h,condition))          /*待查找的元素*/
		{
			f[j++]=i;
			find++;
		}
		return find;
}

void sorthero(Hero hero[],int n,int condition)   /*选择法排序，按condition条件由小到大排序*/
{
	int i,j,minpos;
	Hero t;
	for (i=0;i<n-1;i++)
	{
		minpos=i;
		for (j=i+1;j<n;j++)
			if (larger(hero[minpos],hero[j],condition))
				minpos=j;
			if(i!=minpos)
			{
				t=hero[i];
				hero[i]=hero[minpos];
				hero[minpos]=t;
			}
	}
}


void calcuRank(Hero hero[],int n)       /*计算排名*/
{
	int i,j,temp;
	Hero t;
	for(i=0;i<n-1;i++)
	{
		for(j=i+1;j<n;j++)
		{
			temp=i;
			if(hero[temp].rate>hero[j].rate)
			{
				temp=j;
			}
			if(i!=temp)
			{
				t=hero[i];
				hero[i]=hero[temp];
				hero[temp]=t;
			}
		}
	}
}

int inserthero(Hero hero[],int n,Hero h)        /*向hero数组中依学号递增插入一个元素h*/
 {
	 int i;
	 sorthero(hero,n,1);           /*先按编号排序*/
	 for (i=0;i<n;i++)
	 {
		 if (equal(hero[i],h,1))             /*编号相同不允许插入，保证编号的唯一性*/
		 {
			 printf("this record exist,can not inset again!\n");
			 return n;
		 }
	 }
	 for (i=n-1;i>=0;i--)              /*按编号从小到大有序*/
	 {
		 if (!larger(hero[i],h,1))      /*如果h大于当前元素hero[i]，则退出循环*/
			 break;
		 hero[i+1]=hero[i];
	 }
		 hero[i+1]=h;             /*在下标i+1处插入元素h*/ 
		 n++;                      /*元素个数增加1*/
		 return n;                  /*返回现有元素个数*/
 }

 int deletehero(Hero hero[],int n,Hero h)              /*从数组中删除指定学号的一个元素*/
 {
	 int i,j;
	 for(i=0;i<n;i++)                                    /*寻找待删除的元素*/
		 if (equal(hero[i],h,1))  break;                         /*如果找到相等元素则退出循环*/
		 if(i==n)                                          /*如果找不到待删除的元素*/
		 {
			 printf("This record does not exist!\n");        /*给出提示信息然后返回*/
			 return n;
		 }
		 for (j=i;j<n-1;j++)
			 hero[j]=hero[j+1];
		 n--;                                            /*元素个数减少加1*/
		 return n;                                         /*返回现有个数*/
 } 
