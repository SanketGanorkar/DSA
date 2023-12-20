#include<bits/stdc++.h>
using namespace std;

void rotateArray(int arr[], int n, int size){
    vector<int> temp(size);
    for(int i = 0; i < size; i++){
        temp[(i + n) % size] = arr[i];
    }
    for(int i = 0; i < size; i++){
        arr[i] = temp[i];
    }
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int size = sizeof(arr)/sizeof(arr[0]);
    int n = 2; // number of places to shift
    rotateArray(arr, n, size);
    for(int i = 0; i < size; i++){
        cout << arr[i] << " ";
    }
    return 0;
}
