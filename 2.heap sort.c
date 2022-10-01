#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
double count=0,val,diff=0;

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

void heapify(int arr[], int n, int i) 
{ 	int temp=0;
    int largest = i; 
    int l = 2*i + 1; 
    int r = 2*i + 2; 
    count++;
    if (l < n && arr[l] > arr[largest]) 
        largest = l; count++;

    if (r < n && arr[r] > arr[largest]) 
        largest = r; count++;

    if (largest != i) 
    { 
        temp=arr[i];
		arr[i]=arr[largest];
		arr[largest]=temp;  
        heapify(arr, n, largest); 
        count++;
    } 
} 


 
void heapSort(int b[], int n) 
{ 
	int temp=0,i;
    for (i=((n/2)-1);i>=0;i--) 
       {heapify(b, n, i);
	   } 

    for (i=n-1; i>=0; i--) 
    { count++;
        temp=b[0];
		b[0]=b[i];
		b[i]=temp;
        heapify(b, i, 0); 
    } 
    	  for(i=0;i<MAX;i++)
		{
		printf("%d\t",b[i]);}
	  //printf("\nTime taken= %lf",diff/(double)CLOCKS_PER_SEC);
	  printf("\n Comparisons= %lf",count);
} 
int main()
{
  int A[MAX];
  int b;
  randoms();
  getdata(A);
	heapSort(A, MAX); 
  getch();
  return 0;
}
