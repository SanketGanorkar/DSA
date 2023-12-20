#include<bits/stdc++.h>
using namespace std;

int maxSubArray(int a[], int n){
    int maxsum = a[0];  // Initialize maxsum with the first element
    int curr_sum = a[0];  // Initialize curr_sum with the first element

    for(int i = 1 ; i < n ; i++){  // Start from the second element
        curr_sum = max(a[i], curr_sum + a[i]);  // Choose the maximum between the current element and the sum so far
        
        maxsum = max(maxsum, curr_sum);  // Update maxsum with the maximum of current maxsum and curr_sum
    }
    return maxsum;    
}

int main(){
    int b[3] = {-1,-2,-3};
    //sort(b,b+3);
    int result = maxSubArray(b,3);
    cout << result;
    // for(int i = 0 ; i < 3 ; i++){
    //     cout<<b[i]<<" ";
    // }
    return 0;
}
