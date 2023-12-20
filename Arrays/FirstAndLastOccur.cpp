#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result;

        if (nums.empty()) {
            result.push_back(-1);
            result.push_back(-1);
            return result;
        }

        if (nums.size() == 1) {
            if (nums[0] == target) {
                result.push_back(0);
                result.push_back(0);
            } else {
                result.push_back(-1);
                result.push_back(-1);
            }
            return result;
        }

        // Search for the first occurrence from the left
        for (size_t i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                result.push_back(static_cast<int>(i));
                break;
            }
        }

        // Search for the last occurrence from the right
        for (size_t i = nums.size() - 1; i >= 0; --i) {
            if (nums[i] == target) {
                result.push_back(static_cast<int>(i));
                break;
            }
        }

        if (result.empty()) {
            result.push_back(-1);
            result.push_back(-1);
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Test case: [1, 3], target = 1
    vector<int> nums = {};
    int target = 1;

    vector<int> result = solution.searchRange(nums, target);

    // Output the result
    cout << "Result: [";
    for (int i = 0; i < result.size(); ++i) {
        cout << result[i];
        if (i < result.size() - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;

    return 0;
}
