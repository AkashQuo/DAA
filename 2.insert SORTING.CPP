#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 1000

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

void inser_sort(int A[])
{
	  int key,i,j,b;
	  double count=0,val,diff=0;
	  val=clock();
	for(i=0;i<MAX;i++)
	{
	    key=A[i];
	    j=i-1;
	    count++;
	    while(A[j]>=key&&j>=0)
	    {
	      A[j+1]=A[j];
	      j--;
	      count++;
	    }
	    A[j+1]=key;
	}
	  diff=clock()-val;
	  for(b=0;b<MAX;b++)
		printf("%d\t",A[b]);
	  printf("\nTime taken= %lf",diff/(double)CLOCKS_PER_SEC);
	  printf("\n Comparisons= %lf",count);
}

int main()
{
  int A[MAX];
  int b;
  randoms();
  getdata(A);
  inser_sort(A);
  getch();
  return 0;
}
