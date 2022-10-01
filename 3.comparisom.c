#include<stdio.h>
#include<conio.h>
int min=32766 ,max=0,n,A[50],count=0;
int partion(int low,int high)
{	int i;
	for( i=low;i<=high;i++)
	{count++;
		if(min>=A[i])
		{
			min=A[i];
		}
		if(max<=A[i])
		{
			max=A[i];
		}
	}
}
	int main()
	{	int i;
		printf("\n Enter Size of Elements : ");
		scanf("%d",&n);
		printf("\n Enter Elements : ");
		for(i=0;i<n;i++)
		{scanf("%d",&A[i]);
			}	
		if(n<2)
		{count++;
			min=A[0];
			max=A[0];
		}
		else
		{
				partion(0,(n-1)/2);
				partion((n-1)/2,n-1);	
		}
	
		printf("\n Min=%d \t Max=%d \n",min,max);
		printf("\n Comparion=%d ",count);
	}
