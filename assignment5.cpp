#include<iostream>
using namespace std;

int minimum(int *v,int *d, int n)
{

	int index;
	int min=9999;

	for(int i=0;i<n;i++)
	   {
	   	if(d[i]<min && v[i]==0)
	   	{
	   		min= d[i];
	   		index=i;

		   }


	   }
	   return index;

}



int main()
{
	int n_v,n_e,u,v,value;

	cout<<"enter the no of CITIES and no of PATHS between them";
	cin>>n_v>>n_e;

	int g[n_v][n_v];
	int parent[n_v];
	int visited[n_v];
	int distance[n_v];

	for(int i=0;i<n_v;i++)
	{
		distance[i]=9999;
		parent[i]=0;
		visited[i]=0;

	}

for(int i=0;i<n_v;i++)
	for(int j=0;j<n_v;j++)
	      g[i][j]=0;

	distance[0]=0;







	for(int i=0;i<n_e;i++)
	 {
	 	cout<<"enter the stating city- destination- charge by phone company ";
	 	cin>>u>>v>>value;

	g[u][v]=g[v][u]=value;
	 }

cout<<"the cost matrix is";
   for(int i=0;i<n_v;i++)
   {
   	cout<<endl;
   	for(int j=0;j<n_v;j++)
	{
	cout<<g[i][j]<<"\t";
	}
   }





for(int j=0;j<n_v-1;j++)
{
	int v= minimum(visited, distance,n_v);
	      visited[v]=1;

	      cout<<"the "<<j<<"loop run"<<endl;
	      cout<<"the minimum value is"<<v<<endl;


	for(int i=0;i<n_v;i++)
	{
		if(g[v][i]!=0 && (distance[i]>g[v][i]) && visited[i]==0)
		{
			distance[i]=g[v][i];
			parent[i]=v;

		}


	}

}
cout<<"***************************************0";
cout<<"\n\n\n\n";
cout<<"the path summary is";
for(int i=0;i<n_v;i++)
   {
   	cout<<" vertex1  "<<" vertex2 "<< " distance ";
   	cout<<i<<" --->"<<parent[i]<<" == "<<distance[i];
   	cout<<endl;
   }

int sum1=0;
for(int i=0;i<n_v;i++)
     sum1+=distance[i];

cout<<"total cost for all telephone line setup "<<sum1<<endl;

int p,sum;
cout<<"enter -1 to close";
do
{
	sum=0;
	cout<<"enter the destination";
cin>>p;

cout<<"required path"<<p;
sum=sum+distance[p];
	while(p!=0)
{
	p=parent[p];
	sum+=distance[p];
	cout<<"<--"<<p;

}
cout<<"total path length "<<sum<<endl;

}while(p!=-1);


	return 0;
}
