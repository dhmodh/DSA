#include<iostream>
using namespace std;

void merge_sort(int *a, int l, int m, int r)
{
	int i, j, k;
	int n1 = m -l +1;
	int n2 = r-m;
	int l1[n1], l2[n2];
	for(i=0; i<n1; i++)
		l1[i]=a[l+i];
	for(i=0; i<n2; i++)
		l2[i]=a[1+m+i];
	k=l;
	for(i=0, j=0; i<n1 && j<n2; k++)
	{
		if(l1[i]<=l2[j])
			a[k]=l1[i++];
		else
			a[k]=l2[j++];
	}
	while(i<n1)
		a[k++]=l1[i++];
	while(j<n2)
		a[k++]=l2[j++];
}

void rmerge_sort(int *a, int l, int r)
{
	if(l<r)
	{
		int m=(l+r)/2;
		rmerge_sort(a, l, m);
		rmerge_sort(a, m+1, r);
		merge_sort(a, l, m, r);
	}
}

int main()
{
	int arr[10];
	int n, i;
	cout<<"Enter no of elements : ";
	cin>>n;
	cout<<"\nEnter array \n";
	for(i=0; i<n; i++)
	{
		cout<<"Enter no : ";
		cin>>arr[i];
	}
	cout<<"\nEnter array : ";
	for(i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	rmerge_sort(arr, 0, n-1);
	cout<<"\nMerge sorted array : ";
	for(i=0; i<n; i++)
		cout<<arr[i]<<" ";
	cout<<endl;
	return 0;
} 
