//SJF Non premptive

#include<stdio.h>
#include<stdlib.h>

int i=0,n;

struct algorithm
{
	int at,bt,ct,tt,wt,id;
};

typedef struct algorithm algo;
algo p[10];

void swap(int *b,int *c)
{
    int tem;
    tem=*c;
    *c=*b;
    *b=tem;
}

void main()
{
    int flag=0;
    float avgtt=0,avgwt=0;
    printf("Enter No of process");
    scanf("%d",&n);
    printf("\nEnter ArrivalTime and BurstTime\n");

    for(i=0;i<n;i++)
    {
        p[i].id = i+1;
        printf("\n p %d ->", i+1);
        scanf("%d%d",&p[i].at,&p[i].bt);
    }

    int sum=0;
    
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n-i-1;j++)
        {
        	if(p[j].at > p[j+1].at)
            {
                swap(&p[j+1].id,&p[j].id);
                swap(&p[j+1].at,&p[j].at);
                swap(&p[j+1].bt,&p[j].bt);
            }

         }
     }
     
     int cmp=0;
     i=0;
     int y=p[0].at;
     
     for(int k=0;k<n;k++)
     {
        int min=p[k].bt;

        for(int j=k+1;j<n;j++)
        {
            if(min>p[j].bt && p[j].at<=y)
            {
                min=p[j].bt;
                swap(&p[k].id,&p[j].id);
                swap(&p[k].at,&p[j].at);
                swap(&p[k].bt,&p[j].bt);
            }
        }
        if(p[k].at>cmp)
           cmp=cmp+p[k].bt+(p[k].at-cmp);
        else
           cmp=cmp+p[k].bt;
           p[k].ct=cmp;
           y=cmp;
        }

    printf("\n ID\t AT\t BT\t CT\t TT\t WT");
    for(i=0;i<n;i++)
    {
        p[i].tt=p[i].ct - p[i].at;
        p[i].wt=p[i].tt - p[i].bt;
        avgtt+=p[i].tt;
        avgwt+=p[i].wt;
        printf("\n %d\t %d\t %d\t %d\t %d\t %d",p[i].id,p[i].at,p[i].bt,p[i].ct,p[i].tt,p[i].wt);
    }

    printf("\n avgtt=%f",(avgtt/n));
    printf("\n avgwt=%f",(avgwt/n));
    printf("\n");
    cmp=0;
    
    for(int i=0;i<n;i++)
    {
        if(p[i].at<=cmp)
        {
            printf("|P%d(%d)",p[i].id,p[i].bt);
            cmp+=p[i].bt;
        }
        else
        {
            printf("|XX(%d)",p[i].at-cmp);
            cmp=p[i].at;
            i--;
        }
    }
    
    printf("|\n0 ");
    cmp=0;
    
    for(int i=0;i<n;i++)
    {
        if(p[i].at<=cmp)
        {
            printf("%d ",p[i].ct);
            cmp += p[i].bt;
        }
        else
        {
            printf("%d ",p[i].at);
            cmp = p[i].at;
            i--;
        }
    }
}
