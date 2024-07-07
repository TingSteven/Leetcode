class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Map to store sorted string as key and its index in 'ans' as value
        unordered_map<string, int> word_dic;
        // Copy of input strings for sorting
        vector<string> copy_strs;
        // Vector to store groups of anagrams
        vector<vector<string>> ans;
        // Create a copy of input strings
        copy_strs = strs;

        for(int i = 0; i < strs.size(); i++){
            // Sort the copied string
            sort(copy_strs[i].begin(), copy_strs[i].end());

            // Check if we've seen this sorted string before
            if (word_dic.find(copy_strs[i]) == word_dic.end()){
                // If not, add a new group to 'ans' and store its index in 'word_dic'
                word_dic[copy_strs[i]] = ans.size();
                ans.push_back({strs[i]});
            }
            else{
                // If we've seen it, add the original string to the existing group
                ans[word_dic[copy_strs[i]]].push_back(strs[i]);
            }
        }
        return ans;
    }
};