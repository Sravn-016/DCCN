#include<stdio.h>
#include<string.h>
int main()
{
int n,m,x,i,j=0,t,k;
char a[100],b[150];
printf("enter the data for stuffing");
scanf("%s",a);
n=strlen(a);
for(i=0;i<n;i++){
if(a[i]=='1')
j++;
else
j=0;

if(j==5){
for(k=n;k>i;k--){
a[k+1]=a[k];
}
a[i+1]='0';
}
}
printf("a is %s\n",a);
strcpy(b,"01111110");
printf("b is %s\n",b);

strcat(b,a);
printf("b is %s\n",b);
strcat(b,"01111110");

printf("After bit stuffing:%s",b);
n=strlen(b);

for(i=8;i<n-8;i++){
if (b[i]=='1' && b[i+1]=='1' && b[i+2]=='1' && b[i+3]=='1' && b[i+4]=='1'){
n=n-1;
for(j=i+5;j<n;j++)
b[j]=b[j+1];
i=i+5;
}
}
printf("After Destuffing:\n");
for(i=8;i<n-8;i++)
printf("%c",b[i]);
}