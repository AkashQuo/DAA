// Program to implement Naive String Matching Algorithm
#include<iostream.h>
#include<conio.h>
using namespace std;
int length(char str[])
{
    int n=0;
    for(int i=0;str[i]!='\0';i++)
        n++;
    return(n);
}

void naive(char ptn[],char txt[])
{
    int n,m,temp=0,i,shift[30],k=0;
    n=length(ptn);
    m=length(txt);
    for(i=0;i<=m-n;i++)
    {
        for(int j=0;ptn[j]!='\0';j++)
            if(txt[i+j]!=ptn[j])
                temp=1;
        if(temp==0)
        {
            shift[k]=i;
            k++;
        }
        temp=0;
    }
    if(k==0)
        cout<<"\n The pattern doesn't occur in the text";
    else
    {
        cout<<"\n The pattern occurs at shift : ";
        for(i=0;i<k;i++)
            cout<<shift[i]<<' ';
    }
}

int main()
{
    char ptn[40],txt[80];
    cout<<"\n Enter the pattern to be matched : ";
    cin>>ptn;
    cout<<"\n Enter the text : ";
    cin>>txt;
    naive(ptn,txt);
 	return 0;
 }
