#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000
double count=0,val,diff=0;

	void randoms()
	{
	int i,b;
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
	// double b;
	  FILE *fp;
	  fp=fopen("data.txt","r");
	  for (b=0;b<MAX;b++)
	  {
	     fscanf(fp,"%d",&i);
	     A[b]=i;
	  }
	  fclose(fp);
	}

void merge(int Arr[], int start, int mid, int end) 
{

	int temp[end - start + 1];
	int i = start, j = mid+1, k = 0;
	while(i <= mid && j <= end) {
		if(Arr[i] <= Arr[j]) {
			count++;
			temp[k] = Arr[i];
			k += 1; i += 1;
		}
		else {
			count++;
			temp[k] = Arr[j];
			k += 1; j += 1;
		}
	}
	while(i <= mid) {count++;
		temp[k] = Arr[i];
		k += 1; i += 1;
	}
	while(j <= end) {count++;
		temp[k] = Arr[j];
		k += 1; j += 1;
	}
	for(i = start; i <= end; i += 1) {count++;
		Arr[i] = temp[i - start];
	}
}
void mergeSort(int Arr[], int start, int end) {
		
	  	val=clock();
	if(start < end) {
		count++;
		int mid = (start + end) / 2;
		mergeSort(Arr, start, mid);
		mergeSort(Arr, mid+1, end);
		merge(Arr, start, mid, end);
	}
	
}
void Sho(int A[])
{		
		diff=clock()-val;
	  for(int b=0;b<MAX;b++)
		printf("%d\t",A[b]);
	  //printf("\nTime taken= %lf",diff/(double)CLOCKS_PER_SEC);
	  printf("\n Comparisons= %lf",count);
}
int main()
{
  int A[MAX];
  int b;
  randoms();
  getdata(A);
  mergeSort(A,0,MAX);
	Sho(A);
  getch();
  return 0;
}
