#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans = 0;      
        long long curr = 0;    
        unordered_set<int> s;  
        queue<int> q;          
        
        for(int i = 0; i < nums.size(); i++) {
            
            q.push(nums[i]);
            curr += nums[i];
            
            // Remove duplicates from window
            while(s.find(nums[i]) != s.end()) {
                curr -= q.front();
                s.erase(q.front());
                q.pop();
            }
            
            
            s.insert(nums[i]);
            
           
            while(q.size() > k) {
                curr -= q.front();
                s.erase(q.front());
                q.pop();
            }
            
           
            if(q.size() == k) ans = max(ans, curr);
        }
        return ans;
    }
};