#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxLen = 0;
        int left = 0;
        int right = 0;
        
        while(right < nums.size()) {
            // Get difference between max and min in current window
            int diff = nums[right] - nums[left];
            
            if(diff == 1) {
                // Found a valid harmonious subsequence
                maxLen = max(maxLen, right - left + 1);
                right++;
            }
            else if(diff < 1) {
                right++;
            }
            else {  // diff > 1
                left++;
            }
            
            // If pointers cross, reset right
            if(left > right) {
                right = left;
            }
        }
        
        return maxLen;
    }
};