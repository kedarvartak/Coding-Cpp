class Solution {
public:
    bool isLengthEven(struct Node **head) {
        // Base case: empty list has even length (0)
        if (*head == NULL)
            return true;
            
        struct Node* current = *head;
        
        /* Dry Run Example for list: 1->2->3->4->NULL
         *
         * Initial state:
         * List:     1 -> 2 -> 3 -> 4 -> NULL
         * current:  ^
         *
         * After first jump (current = current->next->next):
         * List:     1 -> 2 -> 3 -> 4 -> NULL
         * current:          ^
         *
         * After second jump:
         * List:     1 -> 2 -> 3 -> 4 -> NULL
         * current:                      ^(NULL)
         *
         * Since current == NULL, length is even (4)
         */
        
        /* Dry Run Example for list: 1->2->3->NULL
         * Initial:  current at 1
         * Jump 1:   current at 3
         * Result:   current not NULL, so length is odd (3)
         */
        
        while (current != NULL && current->next != NULL) {
            current = current->next->next;
        }
        
        // If current is NULL, length is even
        // If current is not NULL, length is odd
        return (current == NULL);
    }
};