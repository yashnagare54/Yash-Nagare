#include<iostream>
using namespace std;
string A[]={"PUNE","MUMBAI","CHENNAI","KOLKATA","BANGLORE"};
int i,j,k,m[10][10],cost[20][20];
typedef struct Prims
	{
		int cost;
		
	}G;

void createM(int m[][10],int n)
	{       
		cout<<"\nCREATING ADJACENCY MATRIX\n";
		for(i=0;i<n;i++)
			{
			for(j=i+1;j<n;j++)
				{
					if(i!=j)
						{
					cout<<"\nEnter Price Between "<<A[i]<<" & "<<A[j]<<" OR Enter -1 For no connection\n" ;
							cin>>m[i][j]; 
							m[j][i]=m[i][j];
						}
				}	
			}
	
	}

void printM(int m[][10],int n)
	{	
		cout<<"\nPRINTING IN MATRIX\n";
		for(i=0;i<n;i++)
			{	
			for(j=0;j<n;j++)
				{	if(i==j)
					m[i][j]=-1;	
					cout<<m[i][j]<<"\t";
				}
					cout<<endl;
			}
	}

void prims(int m[][10],int n)
	{
		int min,row,col,visit[20],path[20],z,mincost=0;
		for(i=1;i<n;i++)
		visit[i]=0;

		visit[0]=1;
		z=0; 
		path[z++]=1;
		cout<<"\nInitial Cost Is "<<mincost;

		for(k=0;k<n-1;k++)
		      	{
			min=999;
			for(i=0;i<n;i++)
			  {
			   for(j=0;j<n;j++)
			       {
				if(visit[i]==1 && visit[j]==0)
				   {
				    if(m[i][j]!=-1 && min>m[i][j])
					{
					min=m[i][j];
					row=i;
					col=j;

					}
				    }
				}
			    }
			cout<<" \nMin"<<min;
			mincost=mincost+min;
			visit[col]=1;
			path[z++]=col;

			cost[row][col]=-1;
			cost[col][row]=-1;
		       }
		     cout<<"\nTotal Min Cost "<<mincost;
		     cout<<"\nSelected  (Shortest) Path to Connect all Offices is:\n";
			int x;	
			for(i=0;i<n;i++)
				{ 	
					x=path[i];
					if(i==0)
					{ x=x-1; }
				 cout<<A[x]<<"==>";
				}
}
	

int main()
	{
	int choice,n;
	cout<<"\nEnter How many offices in Different Cities\n";
	cin>>n;
	do
	{
		cout<<"\n1.Enter Phone company charges for Different Cities.";
		cout<<"\n2.Print in Matrix Form";
		cout<<"\n3.Use Prims Algorithm ";
		cout<<"\nEnter Your Choice";
		cin>>choice;
		switch(choice)
			{
			case 1:createM(m,n);
				break;
			case 2: printM(m,n);
				break;
			case 3:prims(m,n);
				break;
			}
		cout<<"\nDo you  want to continue 1 for YES and  0 for NO:";
		cin>>choice;
	}while(choice==1);
	}
