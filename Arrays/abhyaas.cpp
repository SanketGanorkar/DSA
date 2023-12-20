#include<bits/stdc++.h>
using namespace std;

vector<int> mergeArrays(int arr1[], int arr2[], int n, int m){
    int i = 0 ;
    int j = 0 ;

    vector<int> v;
    while(i < n && j < m){
        if(arr1[i] < arr2[j]){
            if(v.empty() || v.back() != arr1[i]){
                v.push_back(arr1[i]);
            }
            i++;
        }
        else if(arr1[i] > arr2[j]) {
            if (v.empty() || v.back() != arr2[j]) {
                v.push_back(arr2[j]);
            }
            j++;
        }
        else { 
            // Elements are equal
            if (v.empty() || v.back() != arr1[i]) {
                v.push_back(arr1[i]);
            }
            i++;
            j++;
        }
    }

    while(i < n){
        if (v.empty() || v.back() != arr1[i]) {
            v.push_back(arr1[i]);
        }
        i++;
    }

    while(j < m){
        if (v.empty() || v.back() != arr2[j]) {
            v.push_back(arr2[j]);
        }
        j++;
    }
    return v;
}
int main(){
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};

    vector<int> v = mergeArrays(arr1, arr2, n, m);

    for(auto &val : v){
        cout<<val<<" ";
    }
    return 0;
}