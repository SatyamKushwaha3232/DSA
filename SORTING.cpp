#include<iostream>
using namespace std;

void selection_sort(int arr[],int n){
    int i,j,min;
    for(i=0;i<n-1;i++){
        min=i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[min])
            min=j;
        }
        swap(arr[i],arr[min]);
    }
}
void bubble_sort(int arr[],int n){
    int i,j;
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
}
void swap(int &a,int &b){
    int temp;
    temp=a;
    a=b;
    b=temp;


}

int main() {
    int i,n;
    
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
    }
    bubble_sort(arr,n);
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";

    }
return 0;

    
   
}