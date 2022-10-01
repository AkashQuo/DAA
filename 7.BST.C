#include<stdio.h>
//#include<conio.h>
#include<malloc.h>
struct node
{
int info;
struct node *lchild;
struct node *rchild;
}*root;

	int dis_inorder(struct node *ptr)
	{
	if(root==NULL)
	{
	printf("tree is empty");
	return 0;
	}
	if(ptr!=NULL)
	{
	dis_inorder(ptr->lchild);
	printf("%d ",ptr->info);
	dis_inorder(ptr->rchild);
	}
	}
	
find(int item,struct node **par,struct node **loc)
		{
		struct node *ptr,*ptrsave;
		if(root==NULL) /*tree empty*/
		{
		*loc=NULL;
		*par=NULL;
		return 0;
		}
		printf("root is %d",root->info);
		if(item==root->info) /*item is a root*/
		{
		*loc=root;
		*par=NULL;
		return 0;
		}
		/*initialize ptr and ptrsave*/
		if(item<root->info)
		ptr=root->lchild;
		else
		ptr=root->rchild;
		ptrsave=root;
		while(ptr!=NULL)
		{
		if(item==ptr->info)
		{
		*loc=ptr;
		*par=ptrsave;
		return 0;
		}
		ptrsave=ptr;
		if(item<ptr->info)
		ptr=ptr->lchild;
		else
		ptr=ptr->rchild;
		}
		*loc=NULL;
		/*item not found*/
		*par=ptrsave;
		}
					int insert(int item)
					{
					struct node *temp,*parent,*location;
					find(item,&parent,&location);
					if(location!=NULL)
					{
					printf("Item already present");
					return 0;
					}
					temp=(struct node *)malloc(sizeof(struct node));
					temp->info=item;
					temp->lchild=NULL;
					temp->rchild=NULL;
					if(parent==NULL)
					root=temp;
					else if(item<parent->info)
					parent->lchild=temp;
					else
					parent->rchild=temp;
					}

int main()
{int i=1;
int choice,num;
//clrscr();
root=NULL;
	while(i)
	{
	printf("\n");
	printf("1.Insert\n");
	printf("2.Display\n");
	//printf("3.Display\n");
	printf("3.quit\n");
	printf("Enter your choice : ");
	scanf("%d",&choice);
	
				switch(choice)
				{
				case 1:
				printf("Enter the value to be inserted : ");
				scanf("%d",&num);
				insert(num);
				break;
				case 2:
				dis_inorder(root);
				break;
				//case 3:
				//display(root,1);
				//break;
				case 3:
				i=0;			
				break;
				default:
				printf("wrong choice\n");
				}
	}return 0;
}

		



/*display(struct node *ptr,int level)
{
int i;
if(ptr!=NULL)
{
display(ptr->rchild,level+1);
printf("\n");
for(i=0;i<level;i++)
printf(" ");
printf("%d",ptr->info);
display(ptr->lchild,level+1);
}
}           */
