#include<math.h>
#include<iostream>
#include<stdio.h>
#define Max 50

void gmain();
void zmain();

void mean()
{
	int c=0;
	printf("��ѡ����㷽ʽ��\n");
	printf("1�����������\n");
	printf("2��շת�����\n");
	printf("3���˳�\n");
	printf("��ѡ��:[ ]\b\b");
	scanf("%d",&c);
	switch(c)
	{
	case 1:gmain();
		break;
	case 2:zmain();
		break;
	case 3:return;
	default:printf("���벻�Ϸ���������ѡ��\n");system("cls");mean();
	}
}

long int ggcd(long int x,long int y)				//���������
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
	printf("\n\n���������\n");
	printf("\n˵����ͬʱ��������0���ɷ��أ�\n\n");
	scanf("%d%d",&a[0],&a[1]);
	for(int i=0;i<Max;)
	{
		a[i+1] = ggcd(a[i],a[i+1]);
		printf("%d\n",a[i+1]);
		i++;
		scanf("%d",&a[i+1]);
		if(a[i+1]==0)								//�����ж�
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
	printf("\n\nշת�����\n");
	printf("\n˵����ͬʱ��������0���ɷ��أ�\n\n");
	scanf("%d%d",&z[0],&z[1]);
	for(int i=0;i<Max;)
	{
		z[i+1] = zgcd(z[i],z[i+1]);
		printf("%d\n",z[i+1]);
		i++;
		scanf("%d",&z[i+1]);
		if(z[i+1]==0)								//�����ж�
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
	printf("�����Լ����\n\n���ߣ��Ź��\n\n\n\n");
	mean();
}