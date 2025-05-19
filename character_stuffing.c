#include<stdio.h>
#include<string.h>
void main() 
{ 
int j,l,m,c,k; 
char a[50],b[50]; 
printf("Enter the string:"); 
scanf("%s",a); 
strcpy(b,"DLESTX"); 
m=strlen(a); 
for(j=0;j<m;j++) 
{ 
if(a[j]=='D'&& a[j+1]=='L' && a[j+2]=='E') 
{ 
//c=j+3; 
for(l=0;l<3;l++) 
{ 
for(k=m;k>j+3;k--) 
{ 
a[k]=a[k-1]; 
} 
m++; 
} 
a[j+3]='D'; 
a[j+4]='L'; 
a[j+5]='E'; 
j+=5; 
} 
} 
strcat(b,a); 
strcat(b,"DLEETX"); 
printf("\n%s",b); 
printf("\nReceiver side:"); 
m=strlen(a); 
for(j=0;j<m;j++) 
{ 
if(a[j]=='D'&& a[j+1]=='L'&& a[j+2]=='E') 
{ 
for(l=0;l<3;l++) 
{ 
for(k=j;k<m;k++) 
a[k]=a[k+1]; 
} 
j=j+2; 
} 
} 
printf("\n%s",a); 
}