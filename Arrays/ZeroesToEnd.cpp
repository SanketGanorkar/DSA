#include<bits/stdc++.h>
using namespace std;

void pushZerosToEnd(int nums[] , int n){
    int j = -1;
    for(int i = 0 ; i < n ; i++){
        if(nums[i] == 0){
            j = i;
            break;
        }
    }
    
    if(j == -1) return ;

    for(int i = j+1 ; i < n ; i++){
        if(nums[i] != 0){
            swap(nums[i], nums[j]);
            j++;
        }
    }
}

void printArray(int nums[] , int n){
    for(int i = 0 ; i < n ; i++){
        cout<<nums[i]<<" ";
    }
}
int main(){
    int arr[5] = {3, 5, 0, 0, 4};
    cout<<"Original array : ";
    printArray(arr,5);

    cout<<endl;
    pushZerosToEnd(arr,5);

    cout<<"Zeroes at the end of the array : ";
    printArray(arr,5);
    return 0;
}