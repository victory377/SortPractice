#include <stdio.h>
#include <stdlib.h>

void buildMAX(int arr[],int n);
void heapify(int arr[],int n, int i);
void Swap(int arr[],int a,int b);

int main()
{
    int arr[]={4,10,3,5,1};
    buildMAX(arr,5);

    for(int i=4;i>0;--i){
        Swap(arr,i,0);
        buildMAX(arr,i);}
}
void buildMAX(int arr[],int n){
    int i = n/2;
    while(i>0) heapify(arr,n,--i);
}
void heapify(int arr[],int n, int i){

    int left=-1,right=-1,large=-1;
    if(2*i +1< n) //left
        left = 2*i+1;
    if(2*i +2<n) //right
        right = 2*i+2;
    //把 tree填滿
    if(left <0 && right<0) return;
    if(left <0) left=right;
    if(right <0) right=left;

    //比大小
    large = i;
    if(arr[left]>arr[large]) large = left;
    if(arr[right]>arr[large]) large = right;
    
    if(large != i){
        Swap(arr,large,i);
        heapify(arr,n,large);
    }
}
void Swap(int arr[],int a,int b){
    int tmp;
    tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}