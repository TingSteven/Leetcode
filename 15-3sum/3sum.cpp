class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        int n = nums.size();
        
        // Sort the array to handle duplicates and to use two-pointer technique
        sort(nums.begin(), nums.end());
        
        // Fix the first element and find the other two
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            // Two pointers for the remaining two elements
            int left = i + 1;
            int right = n - 1;
            
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (sum == 0) {
                    // Found a triplet with zero sum
                    result.push_back({nums[i], nums[left], nums[right]});
                    
                    // Skip duplicates for left and right pointers
                    while (left < right && nums[left] == nums[left+1]) left++;
                    while (left < right && nums[right] == nums[right-1]) right--;
                    
                    // Move both pointers inward
                    left++;
                    right--;
                } else if (sum < 0) {
                    // Sum is too small, increment left pointer
                    left++;
                } else {
                    // Sum is too large, decrement right pointer
                    right--;
                }
            }
        }
        
        return result;
    }
};