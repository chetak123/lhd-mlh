#include <stdio.h>
void merge(int a[],int,int,int);
void merge_brek(int a[],int,int);
#define SI 100
void main()
{
	int a[]={2,1,5,3,9,6,7,4},b,c,d;
	merge_brek(a,0,7);
	for (c=0;c<=7;c++)
	{
		printf("%d",a[c]);
	}
}
void merge(int a[],int beg,int mid,int end)
{	
	int temp[SI];
	int i=beg,j=mid+1,index=beg;
	while (i<=mid && j<=end)
	{
		if (a[i]<a[j])
		{
			temp[index]=a[i];
			i++;
		}
		else{
			temp[index]=a[j];
			j++;
		}
		index++;
	}
	if (i>mid)
	{
		while (j<=end)
		{
			temp[index]=a[j];
			index++;
			j++;
		}
	}
	else{
		while (i<=mid)
		{
			temp[index]=a[i];
			index++;
			i++;
		}
	}
	int k=0;
	while (k<index){
		a[k]=temp[k];
	//	printf("%d",a[k]);
		k++;
	}
}

void merge_brek(int a[],int beg,int end)
{
	if (beg<end)
	{
		int mid=(beg+end)/2;
		merge_brek(a,beg,mid);
		merge_brek(a,mid+1,end);
		merge(a,beg,mid,end);
	}
}

