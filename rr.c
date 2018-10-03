#include<stdio.h>

struct roundrobin
{
	int arrival_time;
	int burst_time;
	int wait_time;
	int turnaround_time;
	int start_time;
	int finish_time;
	int id;
	int rem_time;
}p[20],temp,q[20];

int main()
{
    int i=0,j=0,remain=0,n,tt=0,tw=0,s=0,flag=0,t;
    float avw=0,avt=0;
    printf("Enter the number of processes: ");
	scanf("%d",&n);
	printf("Enter the time quantum: ");
	scanf("%d",&s);
	for(i=0;i<n;++i)
	{
		printf("Process %d: \n-----\n",i+1);
		printf("Arrival Time: ");
		scanf("%d",&p[i].arrival_time);
		printf("Burst Time: ");
		scanf("%d",&p[i].burst_time);
		p[i].id=i+1;
		p[i].rem_time=p[i].burst_time;
	}
	remain=n;
	q[0].finish_time=s;
	q[0].start_time=p[0].arrival_time;
	for(i=0,t=0;remain!=0;)
    {
        if(j!=0)
        {
            q[j].start_time=q[j-1].finish_time;
        }
        if(p[i].rem_time<=s && p[i].rem_time>0)
        {
            t+=p[i].rem_time;
            q[j].finish_time=q[j].start_time+p[i].rem_time;
            q[j].id=p[i].id;
            j++;
            p[i].rem_time=0;
            flag=1;

        }
        else if(p[i].rem_time>0)
        {
            p[i].rem_time-=s;
            q[j].finish_time=q[j].start_time+s;
            q[j].id=p[i].id;
            j++;
            t+=s;
        }
        if(p[i].rem_time==0 && flag==1)
        {
            remain--;
            p[i].wait_time=t-p[i].arrival_time-p[i].burst_time;
            p[i].turnaround_time= t-p[i].arrival_time;
            tw+=p[i].wait_time;
            tt+=p[i].turnaround_time;
            flag=0;
        }
        if(i==(n-1))
            i=0;
        else if(p[i].arrival_time<=t)
            i++;
        else
            i=0;
    }
    avw=(tw*1.0)/n;
	avt=(tt*1.0)/n;
    printf("\nProcess Arrival_Time Burst_Time Wait_Time Turnaround_Time ");
	for(i=0;i<n;++i)
	{
		printf("\n P%d \t\t %d \t %d \t %d \t\t%d ",p[i].id,p[i].arrival_time,p[i].burst_time,p[i].wait_time,p[i].turnaround_time);
	}
    printf("\n\nGantt Chart: \n");
	for(i=0;i<j;++i)
	{
		printf("--------");
	}
	printf("\n");
	for(i=0;i<j;++i)
	{
		printf("|   P%d  ",q[i].id);
	}
	printf("|\n");
	for(i=0;i<j;++i)
	{
		printf("--------");
	}
	printf("\n");
	printf("%d",q[0].arrival_time);
	for(i=0;i<j;++i)
	{
		printf("\t%d",q[i].finish_time);
	}
	printf("\n");
    printf("\n\nAverage Waiting Time: %f ms",avw);
	printf("\nAverage Turnaround Time: %f ms",avt);

    printf("\n");
    return 0;
}
