class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> results;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, current, used, results);

        return results;
    }

private:
    void backtrack(const vector<int>& nums, vector<int>& current, vector<bool>& used, vector<vector<int>>& result)
    {
        if (current.size() == nums.size())
        {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) 
        {
            if (!used[i]) 
            {
                current.push_back(nums[i]);
                used[i] = true;
                
                backtrack(nums, current, used, result);
                
                current.pop_back();
                used[i] = false;
            }
        }
    }
};