class Solution {
public:
    int maxArea(vector<int>& height) {
        // Initialize two pointers, one at the start and one at the end
        int left = 0;
        int right = height.size() - 1;

        // Variable to store the maximum area
        int ans = 0;

        while(true) {
            // Break the loop if the pointers meet
            if(left == right) break;

            // Calculate the current area
            // Width is the distance between pointers
            // Height is the minimum of the two heights at the pointers
            int currentArea = min(height[left], height[right]) * (right - left);

            // Update the maximum area if the current area is larger
            if(ans < currentArea) {
                ans = currentArea;
            }
            
            // Move the pointer with the smaller height inward
            // This is because moving the taller line inward will never increase the area
            if(height[left] >= height[right]) {
                right--;
            } else {
                left++;
            }
        }

        // Return the maximum area found
        return ans;
    }
};