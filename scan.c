

#include<stdio.h>
int main()
{
 int i,j,sum=0,n;
 int d[20];
 int disk;   
 int temp,max;     
 int dloc;   
 
 printf("enter number of location\t");
 scanf("%d",&n);
 printf("enter position of head\t");
 scanf("%d",&disk);
 printf("enter elements of disk queue\n");
 for(i=0;i<n;i++)
 {
 scanf("%d",&d[i]);
 }
 d[n]=disk;
 n=n+1;
 for(i=0;i<n;i++)   
 {
  for(j=i;j<n;j++)
  {
    if(d[i]>d[j])
    {
    temp=d[i];
    d[i]=d[j];
    d[j]=temp;
    }
  }
 }
 max=d[n-1];
printf("max=%d,disk=%d",max,disk);
 for(i=0;i<n;i++)   
 {
 if(disk==d[i]) { dloc=i; break;  }
 }
 for(i=dloc;i>=0;i--)
 {
 printf("%d -->",d[i]);
/*
diff=abs(queue[j+1]-queue[j]);
seek+=diff;
printf("move is from %d to %d with seek %d\n",d[j],d[j+1],diff);
*/
 }
 printf("0 -->");
 for(i=dloc+1;i<n;i++)
 {
 printf("%d-->",d[i]);
 }
 sum=disk+max;
       printf("\nmovement of total cylinders %d\n",sum);

 return 0;
}
