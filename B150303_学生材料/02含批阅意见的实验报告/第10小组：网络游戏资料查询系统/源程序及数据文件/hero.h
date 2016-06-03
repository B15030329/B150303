#ifndef _HERO      /*�������룬��ֹ�ظ������Ĵ���*/
#define _HERO
#include <string.h>
#define NUM 20     /*����Ӣ��������*/
struct Hero        /*Ӣ�ۼ�¼��������*/
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
#define sizehero sizeof(Hero)         /*һ��Ӣ�ۼ�¼����Ҫ���ڴ�ռ��С*/
int readhero( Hero hero[],int n);      /*����Ӣ�ۼ�¼ֵ�����Ϊ0������涨������¼ʱֹͣ*/
void printhero( Hero *hero,int n);      /*�������Ӣ�ۼ�¼��ֵ*/
int equal(Hero h1,Hero h2,int condition) ;    /*����condition�����ж�����Hero����������ȷ�*/
int larger(Hero h1,Hero h2,int condition);    /*����condition�Ƚ�Hero�������ݴ�С*/
void sorthero(Hero hero[],int n,int condition);      /*ѡ�񷨴�С�������򣬰�condition���涨������*/               
void calcuRank(Hero hero[],int n);                  /*����ʤ��������Ӣ������*/    
int searchhero(Hero hero[],int n,Hero h,int condition,int f[]) ; /*������������������h��ȵĸ�Ԫ��*/
int inserthero(Hero hero[],int n,Hero h);         /*�������в���һ��Ԫ�ذ��������*/
int deletehero(Hero hero[],int n,Hero h);			/*��������ɾ��һ��ָ����ŵ�Ԫ��*/				
#endif