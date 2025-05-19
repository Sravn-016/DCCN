#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void crc();
char a[50],b[50],c[50],newm[50];
int x,y,i=0,j,k,n,s,flag=0;
void main()
{
printf("Enter the data:\n");
scanf("%s",a);
n=strlen(a);
k=n;
printf("\nEnter your choice:\n1.CRC-12\n2.CRC-16\n3.CRC-CCIT\n");
scanf("%d",&x);
printf("\nAfter adding EDC code,the data is:");
switch(x)
{
case 1:strcpy(b,"1100000001111");
strcat(a,"000000000000");
k=k+12;s=13;
break;
case 2:strcpy(b,"11000000000000101");
strcat(a,"0000000000000000");
k=k+16;s=17;
break;
case 3:strcpy(b,"10001000000100001");
strcat(a,"0000000000000000");
k=k+16;s=17;
break;
default:printf("Wrong choice..!");
exit(0);
}
crc();


for(i=0;i<n;i++)
printf("%c",a[i]);
printf("\nEntermsg to be transmitted:");
scanf("%s",newm);
strcpy(a,newm);
crc();
printf("remainder is:");
for(i=0;i<n;i++)
printf("%c",c[i]);
printf("\n");
for(i=n-s;i<n;i++)
if(a[i]!='0')
{
flag=1;
break;
}
if(flag==1)
printf("the message contains an error");
else
printf("transmitted msg is corret");
}
void crc()
{
for(i=0;i<s;i++)
c[i]=a[i];
i=s;
while(i<k+1)
{
if(c[0]=='1')
for(j=0;j<s;j++)
{
if(c[j]==b[j])
c[j]='0';
else
c[j]='1';


}
if(c[0]=='0')
{
for(j=0;j<s;j++)
c[j]=c[j+1];
c[s-1]=a[i];
i++;
}
}
for(i=0;i<s-1;i++)
{
a[n]=c[i];
n++;
}
}