class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        // Product of all non-zero elements
        int sum = 1;  
        // Index of the first zero found (-1 if no zero)
        int zero_add = -1;  
        vector<int> ans;
        
        // Calculate product of all non-zero elements and track zeros
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] == 0){
                if(zero_add == -1)
                    // Record index of first zero
                    zero_add = i;
                else
                    // More than one zero found
                    zero_add = -2;  
                continue;
            }
            sum *= nums[i];
        }

        // Calculate the result based on number of zeros found
        switch(zero_add)
        {
            // No zeros in the array
            case -1:  
                for(int i = 0; i < nums.size(); i++){
                    ans.push_back(sum / nums[i]);
                }
                break;
            // More than one zero in the array
            case -2:  
                for(int i = 0; i < nums.size(); i++){
                    ans.push_back(0);
                }
                break;
            // Exactly one zero in the array
            default:  
                for(int i = 0; i < nums.size(); i++){
                    if(nums[i] == 0){
                        ans.push_back(sum);
                    }
                    else{
                        ans.push_back(0);
                    }
                }
        }

        return ans;
    }
};