class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Use a hash table to store each number and its index
        unordered_map<int, int> numMap;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            // Calculate the complement for the current number
            int complement = target - nums[i];

            // Check if the complement exists in the hash table
            if (numMap.count(complement)) {
                // Solution found, return the indices of the two numbers
                return {numMap[complement], i};
            }

            // Add the current number and its index to the hash table
            numMap[nums[i]] = i;
        }

        // If no solution is found, return an empty vector
        return {};
    }
};