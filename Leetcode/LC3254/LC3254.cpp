#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> ans;
        
        
        for (int i = 0; i <= size - k; i++) {
            
            bool isValid = true;
            int maxNum = nums[i];
            
            
            for (int j = i; j < i + k - 1; j++) {
                if (nums[j + 1] != nums[j] + 1) {
                    isValid = false;
                    break;
                }
                maxNum = max(maxNum, nums[j + 1]);
            }
            
            
            ans.push_back(isValid ? maxNum : -1);
        }
        
        return ans;
    }
};