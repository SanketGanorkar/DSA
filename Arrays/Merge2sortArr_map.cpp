#include <bits/stdc++.h>

using namespace std;


// In unordered_map the keys are stored in random order, while in the map the keys are stored in sorted order (ascending order by default). As we require elements of the union to be in ascending order, using a map is preferable.
vector<int> FindUnion(int arr1[], int arr2[], int n, int m) {
  map<int, int> freq;
  vector<int> Union;
  
  for(int i = 0; i < n; i++) {
    freq[arr1[i]]++;
  }

  for(int i = 0; i < m; i++) {
    freq[arr2[i]]++;
  }

  for(map<int, int>::iterator it = freq.begin(); it != freq.end(); ++it) {
    Union.push_back(it->first);
  }
  
  return Union;
}

int main() {
  int n = 10, m = 7;
  int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int arr2[] = {2, 3, 4, 4, 5, 11, 12};
  vector<int> Union = FindUnion(arr1, arr2, n, m);
  
  cout << "Union of arr1 and arr2 is " << endl;
  
  for(size_t i = 0; i < Union.size(); ++i) {
    cout << Union[i] << " ";
  }
  
  return 0;
}
