	#include<stdio.h>
	#include<conio.h>
	#include<stdlib.h>
	#define MAX 1000
	int main()
	{
		int i,b;
		FILE *fp;
		fp=fopen("data.txt","w");
		for (b=0;b<MAX;b++)
		{
		   i=rand()%32000;
		   fprintf(fp, "%d\t",i);
		}
		fclose(fp);
		return 0;
	}
