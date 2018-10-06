/* Modifications Bought in Code by AVG on 5 th OCtober 2018 20:27 pm
   Simpler than the previous. 
   Reduced Number of Loops
   Deleted unwanted codes
  */


#include<stdio.h>
#include<string.h>
struct sjf{
int a_time,b_time,f_time,t_time,s_time,w_time,t_e;
int name;
};
void main()
{

struct sjf p[3];
struct sjf temp;
p[0].a_time=0;

float avg_wting = 0;
float avg_tat = 0;
int n, count;
printf("\n Enter the Number Of Process:");
scanf("%d",&n);



p[0].w_time=0;


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
						//continue;
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
			}

	}


			


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






	p[i].f_time = p[i].b_time + p[i].s_time;
	
	p[i].t_time = p[i].f_time - p[i].a_time;

	p[i].w_time = p[i].t_time - p[i].b_time;

	avg_wting +=p[i].w_time; 
	avg_tat   +=p[i].t_time;


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



