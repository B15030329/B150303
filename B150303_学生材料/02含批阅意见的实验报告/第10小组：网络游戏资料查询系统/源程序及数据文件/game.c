#include<stdio.h>
#include<stdlib.h>
#include"file.h"
#include"hero.h"

void printHead()                   /*打印英雄信息的表头*/
{
	printf("%2s%6s%6s%45s%8s%8s%8s%8s%8s%8s%8s\n","编号","名称","定位","技能","组合","克制","胜场","出场","杀敌","死亡","胜率");
}

void printBHead()                /*打印B表头*/
{
	printf("%4s%6s%8s\n","编号","名称","胜率");
}

void menu( )               /*顶层菜单函数*/
{
	printf("\t\t  **************欢迎使用时下最火热的守望先锋游戏资料查询系统**************\n");
	printf("\t\t\t\t\t***** 1.英雄总览     ******\n"); 
	printf("\t\t\t\t\t***** 2.英雄信息管理 ******\n");
	printf("\t\t\t\t\t***** 3.英雄信息查询 ******\n");
	printf("\t\t\t\t\t***** 4.赛季统计     ******\n");
	printf("\t\t\t\t\t***** 0.退出系统     ******\n");
}

void menuBase( )          /*2、基本信息管理菜单函数*/
{
	printf("\t\t##### 1.插入英雄记录 ######\n");
	printf("\t\t##### 2.删除英雄记录 ######\n");
	printf("\t\t##### 3.修改英雄记录 ######\n");
	printf("\t\t##### 0.返回上一级   ######\n");
}

void menuSearch( )       /*3、英雄信息查询菜单函数*/
{
	printf("\t\t&&&&& 1.按英雄编号查询 &&&&&&\n");
	printf("\t\t&&&&& 2.按英雄名称查询 &&&&&&\n");
	printf("\t\t&&&&& 0.返回上一级     &&&&&&\n");
}

void menuStatistics( )    /*4、赛季信息统计菜单函数*/
{
	printf("\t\t@@@@@ 1.统计英雄胜率排行 @@@@@@\n");
	printf("\t\t@@@@@ 0.返回上一级       @@@@@@\n");
}

int baseManage(Hero hero[],int n)           /*该函数完成基本信息管理*/
/*按学号进行插入删除修改，学号不能重复*/
{
	int choice,t,find[NUM];
	Hero h;
		do
	{
		menuBase( );          /*显示对应的二级菜单*/
		printf("choose one operation you want to do:\n");
		scanf("%d",&choice);         /*读入选项*/
			switch(choice)
		{
		case 1:readhero(&h,1);         /*读入一条待插入的英雄记录*/
			n=inserthero(hero,n,h);     /*调用函数插入英雄记录*/
			break;
		case 2:printf("Input the name deleted\n");
			scanf("%s",&h.name);       /*读入一个待删除的英雄名称*/
			n=deletehero(hero,n,h);     /*调用函数删除指定名称的英雄记录*/
			break;
		case 3:printf("Input the name modified\n");
			scanf("%s",&h.name);       /*读入一个待修改的英雄名称*/
			t=searchhero(hero,n,h,1,find);  /*调用函数查找指定名称的英雄记录*/
			if(t)
			{
				readhero(&h,1);
				hero[find[0]]=h;
			}
			else
				printf("this hero is not in,can not be modified.\n");      /*输出提示信息*/
		case 0:break;
		}
	}while(choice);
	return n;
}

void searchManage(Hero hero[],int n)              /*该函数完成根据条件查询功能*/
{
	int choice, i,findnum,f[NUM];
	Hero h;
	do
	{
		menuSearch();                              /*显示对应的二级菜单*/
		printf("Choose one operation you want to do:\n");
		scanf("%d",&choice);
		switch(choice)
		{
		case 1:printf("输入英雄编号查询：\n");          /*输入待查询英雄的编号*/
			scanf("%ld",&h.num);
			break;
		case 2:printf("输入英雄名称查询：\n");              /*输入待查询英雄的名称*/
			scanf("%s",h.name);
			break;
		case 0:break;
		}
		if (choice>=1&&choice<=2)
		{
			findnum=searchhero(hero,n,h,choice,f);      /*查找的符合条件元素的下标存于f数组中*/
			if (findnum)                                  /*如果查找成功*/
			{
				printHead();                                 /*打印表头*/
				for (i=0;i<findnum;i++)                       /*循环控制f数组的下标*/
					printhero(&hero[f[i]],1);                 /*每次输出一条记录*/         
			}
			else
				printf("英雄查询错误！\n");                 /*如果查找不到元素，则输出提示信息*/
		}
	}while (choice);
}

void statisticsManage(Hero hero[],int n)                  /*该函数完成赛季统计功能*/
{
	int choice;
	do
	{
		menuStatistics( );                                /*显示对应的二级菜单*/
		printf("请选择需要统计的赛季信息：\n");
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

int runMain(Hero hero[],int n,int choice)             /*主控模块，对应于一级菜单其下各功能选择执行*/
{
	system("cls");
    switch(choice)
	{
			case 1:printHead();                    /* 1. 显示基本信息*/
				sorthero(hero,n,1);
				printhero(hero,n);
				break;
			case 2:n=baseManage(hero,n);              /* 2. 基本信息管理*/
				break;
			case 3:searchManage(hero,n);                     /* 3. 根据条件查询*/
				break;
			case 4:statisticsManage(hero,n);              /* 4. 赛季信息统计*/
				break;
			case 0:	break;
	}
	return n;
}

int main()
{
	Hero hero[NUM];               /*定义实参一维数组存储英雄记录*/
	int choice,n;
	n=readFile(hero);             /*首先读取文件，记录条数返回赋值给n*/
	if(!n)                           /*如果原来的文件为空*/
	{
		n=createFile(hero);      /*则首先要建立文件，从键盘上读入一系列记录存于文件*/
	}
	do
	{
		menu();            /*显示主菜单*/
	printf("Please input your choice: ");
		scanf("%d",&choice);
		if (choice>=0&&choice<=4)
			n=runMain(hero,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/
		else
			printf("error input,please input your choice again!\n");
	} while (choice);
	sorthero(hero,n,1);           /*存入文件前按编号由小到大排序*/
	saveFile(hero,n);            /*将结果存入文件*/
	return 0;  
}