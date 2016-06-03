#include<stdio.h>
#include<stdlib.h>
#include"hero.h"
int createFile(Hero hero[])       /*������ʼ�������ļ�*/
{
	FILE *fp;
	int n;
	if((fp=fopen("d:\\hero.dat", "wb")) == NULL)  /*ָ�����ļ�������д�뷽ʽ��*/
	{
		printf("can not open file !\n");     /*����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                              /*Ȼ���˳�*/
	}
	printf("������Ӣ����Ϣ��\n");
	n=readhero(hero,NUM);                /*����hero.h�еĺ���������*/
	fwrite(hero,sizehero,n,fp);           /*���ղŶ�������м�¼һ����д���ļ�*/
	fclose(fp);                              /*�ر��ļ�*/
	return n;
}

int readFile(Hero hero[] )              /*���ļ��е����ݶ������ڽṹ������hero��*/
{
	FILE *fp;
	int i=0;
	if((fp=fopen("d:\\hero.dat", "rb")) == NULL)  /*�Զ��ķ�ʽ��ָ���ļ�*/
	{
		printf("û���ҵ��ļ������ȴ���:\n");   /*�����ʧ�������ʾ��Ϣ*/
		return 0;          /*Ȼ�󷵻�0*/
	}
	fread(&hero[i],sizehero,1,fp);            /*������һ����¼*/
	while(!feof(fp))                       /*�ļ�δ����ʱѭ��*/
	{ 
		i++;
		fread(&hero[i],sizehero,1,fp);        /*�ٶ�����һ����¼*/
	}
	fclose(fp);                               /*�ر��ļ�*/
	return i;                                   /*���ؼ�¼����*/
} 

void saveFile(Hero hero[],int n)                     /*���ṹ�����������д���ļ�*/
{
	FILE *fp;
	if((fp=fopen("d:\\hero.dat","wb"))==NULL)      /*��д�ķ�ʽ��ָ���ļ�*/
	{
		printf("���ܴ��ļ���\n");                /*�����ʧ�ܣ������ʾ��Ϣ*/
		exit(0);                                    /*Ȼ���˳�*/
	}
	fwrite(hero,sizehero,n,fp);
	fclose(fp);                                 /*�ر��ļ�*/
}
