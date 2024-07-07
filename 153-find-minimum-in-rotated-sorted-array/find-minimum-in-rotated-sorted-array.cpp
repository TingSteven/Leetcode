class Solution {
public:
    int findMin(vector<int>& nums) {
        // Handle edge cases
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return min(nums[0], nums[1]);

        int left = 0, right = nums.size() - 1;

        // Check if the array is not rotated
        if (nums[left] < nums[right]) return nums[left];

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // Check if mid is the rotation point
            if (mid < nums.size() - 1 && nums[mid] > nums[mid + 1])
                return nums[mid + 1];
            if (mid > 0 && nums[mid - 1] > nums[mid])
                return nums[mid];

            // Decide which half to search
            if (nums[mid] > nums[left])
                left = mid + 1;
            else
                right = mid - 1;
        }

        // If no rotation found, return first element
        return nums[0];
    }
};