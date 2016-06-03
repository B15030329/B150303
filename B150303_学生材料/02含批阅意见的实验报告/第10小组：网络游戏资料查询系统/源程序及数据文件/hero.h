#ifndef _HERO      /*条件编译，防止重复包含的错误*/
#define _HERO
#include <string.h>
#define NUM 20     /*定义英雄数常量*/
struct Hero        /*英雄记录的数据域*/
{
	int num;
	char name [20];
	char skill [50];
	char character[20];
	char partner[20];
	char rival[20];
	int wins;
	int appearance;
	int rank;
	double rate;
	double kill;
	double death;
};
typedef struct Hero Hero;
#define sizehero sizeof(Hero)         /*一个英雄记录所需要的内存空间大小*/
int readhero( Hero hero[],int n);      /*读入英雄记录值，编号为0或读满规定条数记录时停止*/
void printhero( Hero *hero,int n);      /*输出所有英雄记录的值*/
int equal(Hero h1,Hero h2,int condition) ;    /*根据condition条件判断两个Hero类型数据相等否*/
int larger(Hero h1,Hero h2,int condition);    /*根据condition比较Hero类型数据大小*/
void sorthero(Hero hero[],int n,int condition);      /*选择法从小到大排序，按condition所规定的条件*/               
void calcuRank(Hero hero[],int n);                  /*根据胜率来计算英雄名次*/    
int searchhero(Hero hero[],int n,Hero h,int condition,int f[]) ; /*根据条件找数组中与h相等的各元素*/
int inserthero(Hero hero[],int n,Hero h);         /*向数组中插入一个元素按编号有序*/
int deletehero(Hero hero[],int n,Hero h);			/*从数组中删除一个指定编号的元素*/				
#endif