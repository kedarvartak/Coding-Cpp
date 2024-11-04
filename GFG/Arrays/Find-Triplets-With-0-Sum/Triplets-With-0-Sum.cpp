#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> findTriplets(vector<int>& arr) {
        vector<vector<int>> result;  // Store all valid triplets
        int n = arr.size();
        if (n < 3) return result;    // Need at least 3 elements
        
        // Store each element with its original index
        // This helps us maintain the original positions after sorting
        vector<pair<int, int>> nums;  // pair<value, original_index>
        for(int i = 0; i < n; i++) {
            nums.push_back({arr[i], i});
        }
        
        // Sort pairs based on values (first element of pair)
        // This allows us to use two-pointer technique
        sort(nums.begin(), nums.end());
        
        // Fix first element and use two pointers for remaining elements
        for (int i = 0; i < n-2; i++) {
            // Skip duplicates for first element to avoid duplicate triplets
            if (i > 0 && nums[i].first == nums[i-1].first) continue;
            
            // Two pointers: left points to element after i
            // right points to last element
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                // Calculate sum of current triplet
                int sum = nums[i].first + nums[left].first + nums[right].first;
                
                if (sum == 0) {
                    // Found a valid triplet
                    // Create vector with original indices
                    vector<int> indices = {nums[i].second, nums[left].second, nums[right].second};
                    // Sort indices to maintain i < j < k condition
                    sort(indices.begin(), indices.end());
                    result.push_back(indices);
                    
                    // Skip duplicates for second element
                    while (left < right && nums[left].first == nums[left+1].first) left++;
                    // Skip duplicates for third element
                    while (left < right && nums[right].first == nums[right-1].first) right--;
                    
                    // Move both pointers inward
                    left++;
                    right--;
                }
                else if (sum < 0) {
                    // Sum is too small, need larger elements
                    // Move left pointer to get larger value
                    left++;
                }
                else {
                    // Sum is too large, need smaller elements
                    // Move right pointer to get smaller value
                    right--;
                }
            }
        }
        
        return result;
    }
};