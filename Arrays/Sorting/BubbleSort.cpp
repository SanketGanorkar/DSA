#include<bits/stdc++.h>
using namespace std;
int main(){
    int arr[] = {3,2,1,0,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    cout<<"Before Sorting"<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    
    cout<<endl;
    for(int i = 0 ; i < n-1 ; i++){ // no. of passes
        for(int j = 0 ; j < n-1-i ; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j] , arr[j+1]);
            }
        }
    }
    cout<<endl;
    cout<<"After Sorting"<<endl;
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
    return 0;    
}