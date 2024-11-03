#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    // Function to check if there are duplicates within k distance in the array
    // arr: input array of integers
    // k: maximum allowed distance between duplicates
    // Returns: true if duplicates exist within k distance, false otherwise
    bool checkDuplicatesWithinK(vector<int>& arr, int k) {
        // Hash map to store each element and its most recent position
        unordered_map<int, int> map;
        
        // Iterate through each element in the array
        for(int i = 0; i < arr.size(); i++) {
            // Check if current element exists in map AND
            // the distance between current index and last seen index is <= k
            if (map.find(arr[i]) != map.end() && 
                i - map[arr[i]] <= k) {
                return true;    // Found duplicates within k distance
            }
            map[arr[i]] = i;   // Store/Update current element's position
        }
        return false;          // No duplicates found within k distance
    }
};

/*
Dry Run Example:
---------------
arr = [1, 2, 3, 1, 4]
k = 3

i = 0:
- arr[0] = 1
- map is empty, so add {1: 0}
- map = {1: 0}

i = 1:
- arr[1] = 2
- map doesn't have 2, add {2: 1}
- map = {1: 0, 2: 1}

i = 2:
- arr[2] = 3
- map doesn't have 3, add {3: 2}
- map = {1: 0, 2: 1, 3: 2}

i = 3:
- arr[3] = 1
- map has 1 at index 0
- check: 3 - 0 <= 3? (true)
- return true (found duplicates within k distance)

Result: true (1 appears at index 0 and 3, distance = 3 which is <= k)

Another Example:
arr = [1, 2, 3, 1, 4]
k = 2
Result would be false because distance between 1's is 3 which is > k
*/