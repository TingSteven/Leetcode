class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // Initialize pointers
        int slow = nums[0];
        int fast = nums[0];
        
        // Find the intersection point of the two pointers
        do {
            // Move slow pointer by one step
            slow = nums[slow];  
            // Move fast pointer by two steps
            fast = nums[nums[fast]];  
        } while (slow != fast);
        
        // Find the entrance to the cycle
        // Reset slow pointer to the start
        slow = nums[0];  
        while (slow != fast) {
            // Move slow pointer by one step
            slow = nums[slow];  
            // Move fast pointer by one step
            fast = nums[fast];  
        }
        // The meeting point is the duplicate number
        return slow;
    }
};