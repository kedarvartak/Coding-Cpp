#include <vector>
using namespace std;

class Solution {
public:

    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        
        if (k == 0) return result;
        
        // Case 2
        vector<int> doubled;
        doubled.insert(doubled.end(), code.begin(), code.end());
        doubled.insert(doubled.end(), code.begin(), code.end());
        
        for (int i = 0; i < n; i++) {
            int sum = 0;
            if (k > 0) {
                // Case 1
                for (int j = 1; j <= k; j++) {
                    sum += doubled[i + j];
                }
            } else {
                // Case 3
                for (int j = 0; j < -k; j++) {
                    sum += doubled[i + n - 1 - j];
                }
            }
            result[i] = sum;
        }
        
        return result;
    }
};