#include<bits/stdc++.h>
using namespace std;

// We used set and not unordered_set , because unordered_set stores elements in random order , while in a set the keys are stored in sorted order (ascending order by default). As we require elements of the union to be in ascending order, using a set is preferable.

vector<int> mergeArrays(int arr1[] , int arr2[] , int n , int m){
    set<int> s;
    vector<int> v;

    for(int i = 0 ; i < n ; i++){
        s.insert(arr1[i]);
    }

    for(int j = 0 ; j < m ; j++){
        s.insert(arr2[j]);
    }

    for(set<int> :: iterator it = s.begin() ; it != s.end() ; it++){
        v.push_back(*it);
    }
    return v;
}
int main(){
    int n = 10, m = 7;
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[] = {2, 3, 4, 4, 5, 11, 12};

    vector<int> result = mergeArrays(arr1, arr2 , n , m);
    cout << "Merging of arr1 and arr2 is  " << endl;
    for(vector<int> :: iterator it = result.begin() ; it != result.end() ; it++){
        cout<<*it<<" ";
    }
    
    return 0;

}