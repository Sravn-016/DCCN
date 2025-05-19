#include<stdio.h>
#define IN 99
#define N 100
int dijsktra(int cost[][N], int source, int target, int n);
int dijsktra(int cost[][N],int source,int target, int n)
{
int dist[N]={0},prev[N]={0},selected[N]={0},i,m,min,start,d,j=0;
char path[N] = {0};
for(i=1;i<=n;i++)
{
dist[i] = IN;
prev[i] = -1;
}
start = source;
selected[start]=1;
dist[start] = 0;
while(selected[target] ==0)
{
min = IN;
m = 0;
for(i=1;i<=n;i++)
{
d = dist[start]+cost[start][i];
if(d<dist[i]&&selected[i]==0)
{
dist[i] = d;
prev[i] = start;
 }
if(min>dist[i] && selected[i]==0)
{
min = dist[i];
m = i;


 }
}
start = m;
selected[start] = 1;
}
 start = target;
 j = 0;
while(start != -1)
{
path[j++] = start;
start = prev[start];
}
printf("shortest path\n");
for(i=0;i<j;i++)
{
if(i==j-1)
printf("%d", path[i]);
else
printf("%d->", path[i]);
 }
return dist[target];
}
void main()
{
int cost[N][N],i,j,w,ch,co;
int source,target,x,y;
int n=0;
printf("\tShortest Path Algorithm(DIJKSRTRA's ALGORITHM\n\n");
printf("\n\t Note: Give weight as 99 if no path exits. 99 = INFINITY \n \n");
printf("Enter No of Nodes:");
scanf("%d", &n);
printf("\n");
 for(i=1;i<=n;i++)
for(j=1;j<=n;j++)


cost[i][j] = IN;
printf("enter the weight of the path between nodes:\n");
for(x=1;x<=n;x++)
{
for(y=x+1;y<=n;y++)
{
printf("%d and %d: ",x,y);
scanf("%d",&w);
cost [x][y] = cost[y][x] = w;
}
printf("\n");
 }
printf("Enter the source:");
scanf("%d", &source);
printf("\nEnter the target:");
scanf("%d", &target);
co = dijsktra(cost,source,target, n);
printf("\nShortest Path(Cost): %d",co);
}