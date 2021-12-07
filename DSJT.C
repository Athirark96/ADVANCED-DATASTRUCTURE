#include<stdio.h>
int i;
struct disjset
{
   int parent[10];
   int rank[10];
   int n;
}
   dis;
void makeset()
{
   for(i=0;i<dis.n;i++)
   {
      dis.parent[i]=i;
      dis.rank[i]=0;
   }
}
void displayset()
{
   printf("\n Parameter Array\n");
   for(i=0;i<dis.n;i++)
   {
      printf("%d",dis.parent[i]);
   }
      printf("\n Rank Array\n");
      for(i=0;i<dis.n;i++)
      {
	 printf("%d",dis.rank[i]);
      }
	 printf("\n");
}
int find(int x)
{
   if(dis.parent[x]!=x)
   {
      dis.parent[x]=find(dis.parent[x]);
   }
      return dis.parent[x];
}
void Union(int x,int y)
{
   int xset=find(x);
   int yset=find(y);
   if(xset==yset)
   return;
   if(dis.rank[xset]<dis.rank[yset])
   {
      dis.parent[xset]=yset;
      dis.rank[xset]=-1;
   }
   else
   {
     dis.parent[yset]=xset;
     dis.rank[xset]=dis.rank[xset]+1;
     dis.rank[yset]=-1;
   }
}
int main()
{
   int n,x,y,ch,wish;
   clrscr();
   printf("How many elements?");
   scanf("%d",&dis.n);
   makeset();
   do
   {
      printf("\n_menu_\n");
      printf("1. union \n 2. find 3. display \n");
      printf("Enter choice \n");
      scanf("%d",&ch);
      switch(ch)
      {
	 case 1: printf("Enter elements to perform union");
		 scanf("%d %d",&x,&y);
		 Union(x,y);
		 break;
	 case 2: printf("Enter elements to check it connected components");
		 scanf("%d %d",&x,&y);
		 if(find(x)==find(y))
		 printf("Connected components \n");
		 else
		 printf("Not connected components \n");
		 break;
	case 3:  displayset();
		 break;
      }
   printf(" \n Do you wish to continue?(1/0) \n");
   scanf("%d",&wish);
   }
   while(wish==1);
   return 0;
}