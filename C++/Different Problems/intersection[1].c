#include<stdio.h>


void main()
{
int i,k=0,x[10],y[10],c[25],j,n,n1,d[25],f=0;

printf("\n how many elements in SET 1:\n");
scanf("%d",&n);
printf("\n please enter the elements\n" );
for(i=0;i<n;i++)
{

scanf("%d",&x[i]);
}
printf("\n how many elements in set 2:\n");
scanf("%d",&n1);
printf("\n please enter elements");
for(i=0;i<n1;i++)
{

scanf("%d",&y[i]);
}

/*for(i=0;i<k;i++)
printf("%d  ",c[i]);*/


for(j=0;j<n;j++)
{
for(i=0;i<n1;i++)
{
if(y[i]==x[j])
break;
}
if(i!=n1)
{
d[f]=y[i];
f++;
}
}
printf("\n the intersection set is\n");
for(i=0;i<f;i++)
printf("%d  ",d[i]);



}
