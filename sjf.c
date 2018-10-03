#include<stdio.h>
#include<string.h>
struct fcfs{
int a_time,b_time,f_time,t_time,s_time,w_time,priority;
int name;
};
void main()
{

struct fcfs p[3];
struct fcfs temp;
p[0].a_time=0;

float avg_wting = 0;
float avg_tat = 0;
int n;
printf("\n Enter the Number Of Process:");
scanf("%d",&n);

//strcpy(p[0].name , "p1"); 
//p[0].s_time=0;

p[0].w_time=0;

/*for(int i=0;i<n;i++)
{
strcpy(p[i].name ,Pi);
} */
//p[1].a_time=0;

//strcpy(p[1].name , "p2"); 

//p[2].a_time=0;

//strcpy(p[2].name , "p3"); 

//printf("Process Id   Arrival Time  Burst Time \t TurnAround Time  \tWait Time  \tFinish Time");
//printf("\n\n");

//printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d" , p[0].name,  p[0].a_time, p[0].b_time, p[0].t_time , p[0].w_time , 
//p[0].f_time);

//printf("\n");
for(int i=0;i<n;i++)
{
	printf("\n Enter the Arrival-Time And Burst-Time   For the process %d :" , i+1);
	scanf("%d%d",&p[i].a_time,&p[i].b_time);
	p[i].name = i+1;
}







for(int i=0;i<n;i++) {

		for(int j = 0;j<n-1;j++)
			{
				if(p[j].a_time > p[j+1].a_time ) 
					{
						temp = p[j];
						p[j] = p[j+1];
						p[j+1] =temp;
					}
				else if(p[j].a_time == p[j+1].a_time)
					{
						continue;
					}
			}

	}


			


				if(p[0].a_time == p[1].a_time)
					{
						for(int i=0;i<n;i++) {
								for(int j = 0;j<n-1;j++) {
					
												
												if(p[j].b_time > p[j+1].b_time ) 
													{
														temp = p[j];
														p[j] = p[j+1];
														p[j+1] =temp;
													}
											}
									}


 					}



				else 
			                {



							for(int i=1;i<n;i++) {
								for(int j = 1;j<n-1;j++) {
					
												
												if(p[j].b_time > p[j+1].b_time ) 
													{
														temp = p[j];
														p[j] = p[j+1];
														p[j+1] =temp;
													}
											}
									}
					}


	



p[0].f_time=p[0].b_time+p[0].a_time;
p[0].t_time=p[0].f_time-p[0].a_time;
p[0].s_time= p[0].a_time;

p[0].w_time=0;


for(int i =1;i<n;i++)
{
	
   if(p[i].a_time>(p[i-1].b_time+p[i-1].s_time))
		{	
			p[i].s_time=p[i].a_time;
		}
		else
		{	
			p[i].s_time=p[i-1].b_time+p[i-1].s_time;
		}





	//p[i].s_time = p[i - 1].f_time;

	p[i].f_time = p[i].b_time + p[i].s_time;
	
	p[i].t_time = p[i].f_time - p[i].a_time;

	p[i].w_time = p[i].t_time - p[i].b_time;

	avg_wting +=p[i].w_time; 
	avg_tat   +=p[i].t_time;

//printf("%s\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d" , p[i].name,  p[i].a_time, p[i].b_time, p[i].t_time , p[i].w_time , 
//p[i].f_time);

//printf("\n");

}









printf("\n");


printf("\t\t");



for(int i = 0;i<n;i++)

{
	printf("-------");

}

printf("\n");

printf("\t\t|");
for(int i=0;i<n;i++){
	
	printf(" P%d |\t",p[i].name);
} 


printf("\n");


printf("\t\t");



for(int i = 0;i<n;i++)

{
	printf("-------");

}

printf("\n");


printf("\n\t\t");
//printf("Gange_Chart\t");

printf("0\t");
for(int i=0;i<n;i++){
	printf("%d\t",p[i].f_time);

}
printf("\n\n");
/*

printf("S_time\t");

for(int i=0;i<n;i++){
	printf("%d\t",p[i].s_time);

}
printf("\n\n");

printf("F_time\t");
for(int i=0;i<n;i++){
	printf("%d\t",p[i].f_time);

}

printf("\n");
printf("\nW_time\t");
for(int i=0;i<n;i++){
	printf("%d\t",p[i].w_time);

}

printf("\n");
printf("t_time\t");

for(int i=0;i<n;i++){
	printf("%d\t",p[i].t_time);

}
*/


printf("\n\n");
printf("Burst-time\t");

for(int i=0;i<n;i++){
	printf("%d\t",p[i].b_time);

}
printf("\n\n");

printf("Arival-time\t");

for(int i=0;i<n;i++){
	printf("%d\t",p[i].a_time);

}
printf("\n\n");
printf("Start-time\t");


for(int i=0;i<n;i++){
	printf("%d\t",p[i].s_time);

}
printf("\n\n");
printf("Finish-time\t");


for(int i=0;i<n;i++){
	printf("%d\t",p[i].f_time);

}
printf("\n\n");
printf("Waiting-time\t");


for(int i=0;i<n;i++){
	printf("%d\t",p[i].w_time);

}
printf("\n");
printf("\n\n");
printf("Turn_Arond-time\t");


for(int i=0;i<n;i++){
	printf("%d\t",p[i].t_time);

}

printf("\n\n");
printf("Average Waiting Time: %f",(float)avg_wting/n);
printf("\n");
printf("\n\n");
printf("Average Turn_Arnd Time: %f",(float)avg_tat/n);
printf("\n");
printf("\t\t");
printf("------------------------------------");
printf("\n");

}



