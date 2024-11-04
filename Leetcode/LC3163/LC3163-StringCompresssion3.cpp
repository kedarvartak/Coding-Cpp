#include <string>
using namespace std;

class Solution {
public:
    string compressedString(string word) {
        /* Dry Run Example:
         * Input: "aaabbc"
         * 
         * Iteration 1:
         * curr = 'a', i = 0
         * count = 1, i = 1 (a)
         * count = 2, i = 2 (aa)
         * count = 3, i = 3 (aaa)
         * ans = "3a"
         * 
         * Iteration 2:
         * curr = 'b', i = 3
         * count = 1, i = 4 (b)
         * count = 2, i = 5 (bb)
         * ans = "3a2b"
         * 
         * Iteration 3:
         * curr = 'c', i = 5
         * count = 1, i = 6 (c)
         * ans = "3a2b1c"
         * 
         * Return: "3a2b1c"
         */

        // Result string to store compressed output
        string ans;
        int size = word.size();
        int i = 0;

        // Process each character in the string
        while(i < size) {
            // Get current character to check for repetition
            char curr = word[i];
            int count = 0;

            // Count consecutive occurrences of current character
            // Note: count is limited to 9 as per problem constraint
            while(i < size && word[i] == curr && count < 9) {
                count++;
                i++;
            }

            // Add the count followed by the character to result
            ans += to_string(count) + curr;
        }    
        return ans;
    }
};