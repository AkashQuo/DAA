#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
double count=0;
void randoms()
{
	int i,b;
	//double b;
	FILE *fp;
	fp=fopen("data.txt","w");
	for (b=0;b<MAX;b++)
	{
	   i=rand()%32000;
	   fprintf(fp, "%d\n",i);
	}
	fclose(fp);
}

void getdata(int A[])
{
	  int i,b;
		//  double b;
	  FILE *fp;
	  fp=fopen("data.txt","r");
	  for (b=0;b<MAX;b++)
	  {
	     fscanf(fp,"%d",&i);
	     A[b]=i;
	  }
	  fclose(fp);
}
	void swap(int *p, int *q)
	{
	int *temp;
	temp=p;
	p=q;
	q=temp;
	}

int partition (int arr[], int low, int high) 
{ 
    int pivot = arr[high];     
    int i = (low - 1); 
  	int j;
    for ( j=low;j<=high-1;j++) 
    { count++;

        if (arr[j] <= pivot) 
        { 

            i++;   
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 
  
void quickSort(int arr[], int low, int high) 
{ 	
    if (low < high) 
    { count++;

        int pi = partition(arr, low, high); 
		
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
	    	//diff=clock()-val;
		  	
} 



int main()
{
  int A[MAX];
  int b;
  randoms();
  getdata(A);
  quickSort(A,0,(MAX-1));
 			 for( b=0;b<MAX;b++)
			{	printf("%d\t",A[b]);}
		  	//printf("\nTime taken= %lf",diff/(double)CLOCKS_PER_SEC);
		  	printf("\n Comparisons= %lf",count);
  getch();
  return 0;
}

