#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"hero.h"

void printHead()                   /*��ӡӢ����Ϣ�ı�ͷ*/
{
	printf("%2s%6s%6s%45s%8s%8s%8s%8s%8s%8s%8s\n","���","����","��λ","����","���","����","ʤ��","����","ɱ��","����","ʤ��");
}

void printBHead()                /*��ӡB��ͷ*/
{
	printf("%4s%6s%8s\n","���","����","ʤ��");
}

void menu( )               /*����˵�����*/
{
	printf("\t\t  **************��ӭʹ��ʱ������ȵ������ȷ���Ϸ���ϲ�ѯϵͳ**************\n");
	printf("\t\t\t\t\t***** 1.Ӣ������     ******\n"); 
	printf("\t\t\t\t\t***** 2.Ӣ����Ϣ���� ******\n");
	printf("\t\t\t\t\t***** 3.Ӣ����Ϣ��ѯ ******\n");
	printf("\t\t\t\t\t***** 4.����ͳ��     ******\n");
	printf("\t\t\t\t\t***** 0.�˳�ϵͳ     ******\n");
}

void menuBase( )          /*2��������Ϣ����˵�����*/
{
	printf("\t\t##### 1.����Ӣ�ۼ�¼ ######\n");
	printf("\t\t##### 2.ɾ��Ӣ�ۼ�¼ ######\n");
	printf("\t\t##### 3.�޸�Ӣ�ۼ�¼ ######\n");
	printf("\t\t##### 0.������һ��   ######\n");
}

void menuSearch( )       /*3��Ӣ����Ϣ��ѯ�˵�����*/
{
	printf("\t\t&&&&& 1.��Ӣ�۱�Ų�ѯ &&&&&&\n");
	printf("\t\t&&&&& 2.��Ӣ�����Ʋ�ѯ &&&&&&\n");
	printf("\t\t&&&&& 0.������һ��     &&&&&&\n");
}

void menuStatistics( )    /*4��������Ϣͳ�Ʋ˵�����*/
{
	printf("\t\t@@@@@ 1.ͳ��Ӣ��ʤ������ @@@@@@\n");
	printf("\t\t@@@@@ 0.������һ��       @@@@@@\n");
}

int baseManage(Hero hero[],int n)           /*�ú�����ɻ�����Ϣ����*/
/*��ѧ�Ž��в���ɾ���޸ģ�ѧ�Ų����ظ�*/
{
	int choice,t,find[NUM];
	Hero h;
		do
	{
		menuBase( );          /*��ʾ��Ӧ�Ķ����˵�*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);         /*����ѡ��*/
			switch(choice)
		{
		case 1:readhero(&h,1);         /*����һ���������Ӣ�ۼ�¼*/
			n=inserthero(hero,n,h);     /*���ú�������Ӣ�ۼ�¼*/
			break;
		case 2:printf("Input the name deleted\n");
			scanf("%s",&h.name);       /*����һ����ɾ����Ӣ������*/
			n=deletehero(hero,n,h);     /*���ú���ɾ��ָ�����Ƶ�Ӣ�ۼ�¼*/
			break;
		case 3:printf("Input the name modified\n");
			scanf("%s",&h.name);       /*����һ�����޸ĵ�Ӣ������*/
			t=searchhero(hero,n,h,1,find);  /*���ú�������ָ�����Ƶ�Ӣ�ۼ�¼*/
			if(t)
			{
				readhero(&h,1);
				hero[find[0]]=h;
			}
			else
				printf("this hero is not in,can not be modified.\n");      /*�����ʾ��Ϣ*/
		case 0:break;
		}
	}while(choice);
	return n;
}

void searchManage(Hero hero[],int n)              /*�ú�����ɸ���������ѯ����*/
{
	int choice, i,findnum,f[NUM];
	Hero h;
	do
	{
		menuSearch();                              /*��ʾ��Ӧ�Ķ����˵�*/
		printf("Choose one operation you want to do:\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("����Ӣ�۱�Ų�ѯ��\n");          /*�������ѯӢ�۵ı��*/
			scanf("%ld",&h.num);
			break;
		case 2:printf("����Ӣ�����Ʋ�ѯ��\n");              /*�������ѯӢ�۵�����*/
			scanf("%s",h.name);
			break;
		case 0:break;
		}
		if (choice>=1&&choice<=2)
		{
			findnum=searchhero(hero,n,h,choice,f);      /*���ҵķ�������Ԫ�ص��±����f������*/
			if (findnum)                                  /*������ҳɹ�*/
			{
				printHead();                                 /*��ӡ��ͷ*/
				for (i=0;i<findnum;i++)                       /*ѭ������f������±�*/
					printhero(&hero[f[i]],1);                 /*ÿ�����һ����¼*/         
			}
			else
				printf("Ӣ�۲�ѯ����\n");                 /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/
		}
	}while (choice);
}

void statisticsManage(Hero hero[],int n)                  /*�ú����������ͳ�ƹ���*/
{
	int choice;
	do
	{
		menuStatistics( );                                /*��ʾ��Ӧ�Ķ����˵�*/
		printf("��ѡ����Ҫͳ�Ƶ�������Ϣ��\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printBHead();
			printBhero(hero,n);
			break;
		case 0:break;
		}
	}while(choice);
}

int runMain(Hero hero[],int n,int choice)             /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/
{
	system("cls");
    switch(choice)
	{
			case 1:printHead();                    /* 1. ��ʾ������Ϣ*/
				sorthero(hero,n,1);
				printhero(hero,n);
				break;
			case 2:n=baseManage(hero,n);              /* 2. ������Ϣ����*/
				break;
			case 3:searchManage(hero,n);                     /* 3. ����������ѯ*/
				break;
			case 4:statisticsManage(hero,n);              /* 4. ������Ϣͳ��*/
				break;
			case 0:	break;
	}
	return n;
}

int main()
{
	Hero hero[NUM];               /*����ʵ��һά����洢Ӣ�ۼ�¼*/
	int choice,n;
	n=readFile(hero);             /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/
	if(!n)                           /*���ԭ�����ļ�Ϊ��*/
	{
		n=createFile(hero);      /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/
	}
	do
	{
		menu();            /*��ʾ���˵�*/
	printf("Please input your choice: ");
		scanf("%d",&choice);
		if (choice>=0&&choice<=4)
			n=runMain(hero,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/
		else
			printf("error input,please input your choice again!\n");
	} while (choice);
	sorthero(hero,n,1);           /*�����ļ�ǰ�������С��������*/
	saveFile(hero,n);            /*����������ļ�*/
	return 0;  
}