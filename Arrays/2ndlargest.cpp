#include<bits/stdc++.h>
using namespace std;
class Solution{
public:	
	// Function returns the second
	// largest elements
	int print2largest(int arr[], int n) {
	    int max = INT_MIN;
	    int secondMax = INT_MIN;
	    for(int i = 0 ; i < n ; i++){
	        if(arr[i] > max){
	            secondMax = max;
	            max = arr[i];
	        }
	        else if(arr[i] > secondMax && arr[i] != max){
                // here we are checking if the element is less than secondMax and also it should not be equal to max , otherwise it will be 1st element only.
	            secondMax = arr[i];
	        }
	    }
	    if(secondMax == INT_MIN){
	            // there is no max 2nd element , all the elements are same.
	            return -1;
	        }
	    return secondMax;
	}
};

int main(){
    int n;
    cin>>n;
    int arr[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    Solution obj;
    int ans = obj.print2largest(arr,n);
    cout<<ans<<"\n";
    return 0;
}