#include "hero.h"
#include <stdio.h>

int readhero(Hero *hero,int n)    /*����Ӣ�ۼ�¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("������Ӣ����Ϣ��\n");
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
		return i;                           /*����ʵ�ʶ���ļ�¼����*/
}

void printhero (Hero *hero,int n)                /*�������Ӣ�ۼ�¼��ֵ*/
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

void printBhero(Hero *hero,int n)             /*��ӡB��ͷ*/
{
	int i;
	for (i=0;i<n;i++)
	{
		printf("%4ld",hero[i].num);
		printf("%6s",hero[i].name);
		printf("%8.2f%%\n",hero[i].rate);
	}
}


int equal(Hero h1,Hero h2,int condition)         /*����ж�����Hero��¼���*/
{
	if (condition==1)                          /*�������condition��ֵΪ1����Ƚϱ��*/
		return h1.num==h2.num;
	else if (condition==2)                           /*�������condition��ֵΪ2����Ƚ�����*/
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
 
int larger(Hero h1,Hero h2,int condition)                    /*����condition�����Ƚ�����Hero��¼�Ĵ�С*/
{
	if(condition==1)
		return h1.num>h2.num;
	if(condition==2)
		return h1.rate>h2.rate;
	else 
		return 1;
}

int searchhero(Hero hero[],int n,Hero h,int condition,int f[ ])/*��stu��������condition��������*/
/*��s��ͬ��Ԫ�أ����ڲ�ֹһ����¼������������˽���ЩԪ�ص��±����� f������*/
{
	int i,j=0,find=0;
	for(i=0;i<n;i++)
		if(equal(hero[i],h,condition))          /*�����ҵ�Ԫ��*/
		{
			f[j++]=i;
			find++;
		}
		return find;
}

void sorthero(Hero hero[],int n,int condition)   /*ѡ�����򣬰�condition������С��������*/
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


void calcuRank(Hero hero[],int n)       /*��������*/
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

int inserthero(Hero hero[],int n,Hero h)        /*��hero��������ѧ�ŵ�������һ��Ԫ��h*/
 {
	 int i;
	 sorthero(hero,n,1);           /*�Ȱ��������*/
	 for (i=0;i<n;i++)
	 {
		 if (equal(hero[i],h,1))             /*�����ͬ��������룬��֤��ŵ�Ψһ��*/
		 {
			 printf("this record exist,can not inset again!\n");
			 return n;
		 }
	 }
	 for (i=n-1;i>=0;i--)              /*����Ŵ�С��������*/
	 {
		 if (!larger(hero[i],h,1))      /*���h���ڵ�ǰԪ��hero[i]�����˳�ѭ��*/
			 break;
		 hero[i+1]=hero[i];
	 }
		 hero[i+1]=h;             /*���±�i+1������Ԫ��h*/ 
		 n++;                      /*Ԫ�ظ�������1*/
		 return n;                  /*��������Ԫ�ظ���*/
 }

 int deletehero(Hero hero[],int n,Hero h)              /*��������ɾ��ָ��ѧ�ŵ�һ��Ԫ��*/
 {
	 int i,j;
	 for(i=0;i<n;i++)                                    /*Ѱ�Ҵ�ɾ����Ԫ��*/
		 if (equal(hero[i],h,1))  break;                         /*����ҵ����Ԫ�����˳�ѭ��*/
		 if(i==n)                                          /*����Ҳ�����ɾ����Ԫ��*/
		 {
			 printf("This record does not exist!\n");        /*������ʾ��ϢȻ�󷵻�*/
			 return n;
		 }
		 for (j=i;j<n-1;j++)
			 hero[j]=hero[j+1];
		 n--;                                            /*Ԫ�ظ������ټ�1*/
		 return n;                                         /*�������и���*/
 } 
