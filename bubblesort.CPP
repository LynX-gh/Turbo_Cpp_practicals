#include<iostream.h>
#include<conio.h>

void bubblesort (int arr[], int size)
{	int temp;
	for(int i=0, i<size, i++)
	{	for(int j=0, j<size-1, j++)
		{	if(arr[j]>arr[j+1])
			{	temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	cout<<"\n\nArray after iteration - "<<++ctr<<" - is : ";
	for(int k=0, k<size , k++)
	{	cout<<arr[k]<<" ";
	}
	}
int main(){
	clrscr();
	int arr[50],size;
	cout<<"Enter array size : ";
	cin>>size;
	for(int i=0;i<size;i++)
	{	cin>>arr[i];
	}
	Bubblesort(arr,size);
	cout<<"\n Sorted array is.....\n";
	for(i=0;i<size;i++)
		cout<<arr[i]<<" ";
	getch();
	return 0;
	}
