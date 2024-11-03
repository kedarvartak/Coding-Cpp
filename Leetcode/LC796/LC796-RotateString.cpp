#include <string>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        /* Example Dry Run:
           s = "abcde"
           goal = "cdeab"
           
           Step 1: Length check
           s.length() = 5
           goal.length() = 5
           5 == 5 ✓ - continue
           
           Step 2: Create temp string
           temp = s + s
           temp = "abcde" + "abcde"
           temp = "abcdeabcde"
           
           Step 3: Find goal in temp
           Look for "cdeab" in "abcdeabcde"
                    ^^^^^
                    Found at position 2
           
           Step 4: Return true since goal was found
        */
        
        // Step 1: If lengths are different, rotation is impossible
        // Example: s = "abcde" (len=5), goal = "cde" (len=3) -> false
        if (s.length() != goal.length()) 
            return false;
            
        // Step 2: Concatenate s with itself
        // This creates a string containing all possible rotations
        // Example: s = "abcde" -> temp = "abcdeabcde"
        string temp = s + s;
        
        // Step 3: Check if goal is a substring of temp
        // string::npos is returned if substring is not found
        // Example: find("cdeab") will return 2, which != string::npos
        return temp.find(goal) != string::npos;
        
        /* Additional Example:
           s = "abcde"
           goal = "abced"
           
           1. Length check: 5 == 5 ✓
           2. temp = "abcdeabcde"
           3. "abced" not found in temp
           4. Return false
        */
    }
};