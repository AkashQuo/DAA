// Program to implement Knapsack Problems

#include<iostream>
#include<conio.h>

using namespace std;
int n,w[20],v[30],maxw,tw=0;

	int large(int i,int j)
	{
	  if(v[i]<0)
	    return (j);
	  else if(v[j]<0)
	    return (i);
	  else if((v[i]*w[j])>(v[j]*w[i]))
	    return (i);
	 else return (j);    
	}

	void knapsack()
	{
	  int item=0;
	  int i=1;
	  while(i<n)
	  {
	    item=large(item,i);
	    i++;
	  }
	  if(w[item]<=maxw)
	  {
	    cout<<"\n\n Item number     : "<<(item+1);
	    cout<<"\n Selected Weight : "<<w[item];
	    cout<<"\n Worth           : "<<v[item];
	    tw+=v[item];
	    maxw-=w[item];
	    w[item]=-1;
	    v[item]=-1;
	  }
	  else
	  {
	    cout<<"\n\n Item number     : "<<(item+1);
	    cout<<"\n Selected Weight : "<<maxw;
	    int p;
	    p=((v[item]*maxw)/w[item]);
	    cout<<"\n Worth           : "<<p;
	    tw+=p;   
	    maxw=0;
	  }  
	}
			
			void get()
			{	
				cout<<"\n Enter the number of items : ";
				cin>>n;
				cout<<"\n Enter the following info : \n";
				
				for(int i=0;i<n;i++)
				{
					cout<<"\n Weight of item "<<i+1<<" : ";
					cin>>w[i];
				}
				cout<<"\n";
				for(int i=0;i<n;i++)
				{
					cout<<"\n Value of item "<<i+1<<" : ";
					cin>>v[i];
				}
				cout<<"\n Maximum weight to be selected : ";
				cin>>maxw;
			}

			
			int main()
			{
			  get();
			  cout<<"\n The selected items, their weights and worths are : ";
			   while(maxw!=0)
			    knapsack();
			    cout<<"\n\n The total worth of selected items is : "<<tw;
			
			    getch();
			    return 0;
			}

/*output

 Enter the number of items : 3

 Enter the following info :

 Weight of item 1 : 10

 Weight of item 2 : 20

 Weight of item 3 : 30

 Worth/Value of item 1 : 60

 Worth/Value of item 2 : 100

 Worth/Value of item 3 : 120

 Maximum weight to be selected : 50

 The selected items, their weights and worths are :

 Item number     : 1
 Selected Weight : 10
 Worth           : 60

 Item number     : 2
 Selected Weight : 20
 Worth           : 100

 Item number     : 3
 Selected Weight : 20
 Worth           : 80

 The total worth of selected items is : 240*/
