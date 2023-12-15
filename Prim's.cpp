#include <iostream>
using namespace std;

#define I 20382
int cost[][8]=
{
    {I,I,I,I,24,I,I,I},
    {I,I,I,I,11,I,I,I},
    {I,I,I,12,I,I,I,I},
    {I,I,I,I,I,I,1,I},
    {I,I,I,I,I,I,I,I},
    {I,I,I,I,I,66,I,I},
    {I,I,92,I,I,I,I,I},
    {I,I,I,9,I,I,I,I},
    };

int near[8] = {I,I,I,I,I,I,I,I};
 int t[2][7];

main()
{
 int min =I,n=7,k,u,v;
 for(int i=1;i<=n;i++)
 {
    for(int j=i;j<=n;j++)
    {
        if(cost[i][j]<=min)
        {
            min = cost[i][j];
            u=i;
            v=j;
        }
    }
 }
 t[0][0]=u,t[0][1]=v;
 near[u]=near[v]=0;
 for(int i=1;i<=n;i++)
 {
   if(near[i]!=0)
    {
   if(cost[i][u]<cost[i][v])
   {
    near[i]=u;
   }
   else
   {
    near[i]=v;
   }
    }
 }
 for(int i=1;i<=n-1;i++)
 {
    min=I;
    for(int j=1;j<=n;j++)
    {
        if(near[j]!=0 && cost[j][near[j]]<min)
        {
            k= j;
            min=cost[j][near[j]];
        }
    }
 t[0][i]=k;
 t[1][i]=near[k];
 near[k]=0;
 }
 for(int i=1;i<=n;i++)
 {
    if(near[i]!=0 && cost[i][k]<cost[i][near[i]])
    {
        near[i]=k;
    }
 }

 
 for(int i=1;i<=n;i++)
 {
    cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl;
 }
}
