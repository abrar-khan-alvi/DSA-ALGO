#include<bits/stdc++.h>
#define ll long long int
#define ld long double
#define endl '\n'
#define faster  ios_base:: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int partition(int arr[],int low,int high){

    int pivot=arr[high];

    int i=low-1;

    for(int j=low;j<high;j++){
        if(arr[high]<=pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    
    return (i+1);
}

void quicksort(int arr[],int low,int high){
    if(low<high){

        int pi=partition(arr,low,high);

        quicksort(arr,low,pi-1);

        quicksort(arr,pi+1,high);

    }
}

int main()
{
faster;

int arr[]={11,12,36,96,98,6,36,4,5,1,2};

int high=sizeof(arr)/sizeof(arr[0]);

quicksort(arr,0,high-1);

for(int i=0;i<high;i++)
cout<<arr[i]<<" ";
return 0;
}