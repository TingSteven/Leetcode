class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int min_tmp, max_tmp;
        
        // Sort intervals based on start time
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for(int i = 0; i < intervals.size(); i++){
            // Initialize min and max with the current interval
            min_tmp = intervals[i][0];
            max_tmp = intervals[i][1];
            
            // Look for overlapping intervals
            for(int j = i+1; j < intervals.size(); j++){
                // If there's an overlap
                if(max_tmp >= intervals[j][0]){
                    // Extend the current interval if necessary
                    max_tmp = max(max_tmp, intervals[j][1]);
                    i = j;  // Skip the merged interval in the outer loop
                }
                else{
                    // No more overlaps, break the inner loop
                    break;
                }
            }
            
            // Add the merged interval to the result
            ans.push_back({min_tmp, max_tmp});
        }
        
        return ans;
    }
};