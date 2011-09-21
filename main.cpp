#include<math.h>
#include<iostream>
#include<stdio.h>
#define Max 50

void gmain();
void zmain();

void mean()
{
	int c=0;
	printf("请选择计算方式：\n");
	printf("1、更相减损术\n");
	printf("2、辗转相除法\n");
	printf("3、退出\n");
	printf("请选择:[ ]\b\b");
	scanf("%d",&c);
	switch(c)
	{
	case 1:gmain();
		break;
	case 2:zmain();
		break;
	case 3:return;
	default:printf("输入不合法！请重新选择！\n");system("cls");mean();
	}
}

long int ggcd(long int x,long int y)				//更相减损术
{
	if(x==0) return y;
	else if(y==0) return x;
	else
	if(x!=y)
	{
		if(x>y)
		{
			x=x-y;
			ggcd(x,y);
		}
		else
		{
			y=y-x;
			ggcd(x,y);
		}
	}
	else
		return x;
}

void gmain()
{
	long int a[Max];
	long int p[2];
	int j=0;
	printf("\n\n更相减损术\n");
	printf("\n说明：同时输入两个0即可返回！\n\n");
	scanf("%d%d",&a[0],&a[1]);
	for(int i=0;i<Max;)
	{
		a[i+1] = ggcd(a[i],a[i+1]);
		printf("%d\n",a[i+1]);
		i++;
		scanf("%d",&a[i+1]);
		if(a[i+1]==0)								//结束判断
		{
			p[j]=0;
			j++;
		}
		else j=0;
		if(p[0]==0&&p[1]==0)
		{
			system("cls");
			mean();
		}
	}
}

long int zgcd(long int a,long int b)
{
	long int r;
	while(b!=0)
	{
		r=a%b;
		a=b;
		b=r;
	}
    return a;
}

void zmain()
{
	long int z[Max];
	long int p[2];
	int j=0;
	printf("\n\n辗转相除法\n");
	printf("\n说明：同时输入两个0即可返回！\n\n");
	scanf("%d%d",&z[0],&z[1]);
	for(int i=0;i<Max;)
	{
		z[i+1] = zgcd(z[i],z[i+1]);
		printf("%d\n",z[i+1]);
		i++;
		scanf("%d",&z[i+1]);
		if(z[i+1]==0)								//结束判断
		{
			p[j]=0;
			j++;
		}
		else j=0;
		if(p[0]==0&&p[1]==0)
		{
			system("cls");
			mean();
		}
	}
}

int main()
{
	printf("求最大公约数！\n\n作者：张冠楠\n\n\n\n");
	mean();
}