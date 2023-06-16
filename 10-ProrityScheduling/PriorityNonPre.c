//Priority NonPremptive

#include<stdio.h>
#include<stdlib.h>

int i =0;
int n;

struct algorithm{
	int at,bt,ct,tt,wt,id,pr;
};

typedef struct algorithm algo;
algo p[10];

void swap(int *b,int *c)
{
	int temp;
	temp = *c;
	*c = *b;
	*b = temp;
}

void main()
{
	//int i,j,k,q;
	//int rq[20],f = 0,r = -1;
	float avgtt = 0,avgwt = 0;
	//int ids[100],nos[100];
	printf("Enter no of process : ");
	scanf("%d",&n);
	//printf("Enter time Quantum : ");
	//scanf("%d",&q);
	printf("Enter\n ArrivalTime BurstTime and Priority\n");
	for(i = 0;i<n;i++)
	{
		p[i].id = i+1;
		printf("\np %d ->",i+1);
		scanf("\n%d%d%d",&p[i].at,&p[i].bt,&p[i].pr);
	}
	int sum = 0;
	for(int i = 0;i<n;i++)
	{
		for(int j = 0;j<n-i-1;j++)
		{
			if(p[j].at > p[j+1].at)
			{
				swap(&p[j+1].id,&p[j].id);
				swap(&p[j+1].at,&p[j].at);
				swap(&p[j+1].bt,&p[j].bt);
				swap(&p[j+1].pr,&p[j].pr);
			}
		}
	}
	int cmp = 0;
	int y = p[0].at;
	for(int k = 0;k<n;k++)
	{
		int min = p[k].pr;
		for(int j = k+1;j<n;j++)
		{
			if(min > p[j].pr && p[j].at <= y)
			{
				min = p[j].pr;
				swap(&p[k].id,&p[j].id);
				swap(&p[k].at,&p[j].at);
				swap(&p[k].bt,&p[j].bt);
				swap(&p[k].pr,&p[j].pr);
			}
		}
		if(p[k].at > cmp)
			cmp = cmp + p[k].bt + (p[k].at - cmp);
		else
			cmp = cmp + p[k].bt;
		p[k].ct = cmp;
		y = cmp;
	}
	printf("\nID\tAT\tBT\tPR\tCT\tTT\tWT");
	for(i = 0;i<n;i++)
	{
		p[i].tt = p[i].ct - p[i].at;
		p[i].wt = p[i].tt - p[i].bt;
		avgtt += p[i].tt;
		avgwt += p[i].wt;
		printf("\n%d\t%d\t%d\t%d\t%d\t%d\t%d",p[i].id,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tt,p[i].wt);
	}
	printf("\navgtt = %f",(avgtt/n));
	printf("\navgwt = %f\n\n",(avgwt/n));
	int cp = 0;
		
	for(int i = 0;i<n;i++)
	{
		if(p[i].at <= cp)
		{
			printf("|P%d(%d)",p[i].id,p[i].bt);
			cp += p[i].bt;
		}
		else
		{
				printf("|1XX(%d)",p[i].at-cp);
				cp = p[i].at;
				i--;
		}
	}
	printf("||no  ");
	cp = 0;
	for(int i = 0;i<n;i++)
	{
			if(p[i].at <= cp)
			{
				printf("%d ",p[i].ct);
				cp += p[i].bt;
			}else
			{
				printf("%d ",p[i].at);
				cp = p[i].at;
				i--;
				
		    }		
	}
}
