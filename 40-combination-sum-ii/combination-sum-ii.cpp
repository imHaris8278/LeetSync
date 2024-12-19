class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        vector<vector<int>> result;
    
        vector<int> current;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, result, current, 0);
    
        return result;
    }

    void backtrack(vector<int>& candidates, int target, vector<vector<int>>& result, vector<int>& current, int index) 
    {
        if (target == 0)
        {
            result.push_back(current);
            return;
        }

        for (int i = index; i < candidates.size() && target >= candidates[i]; i++)
        {
            if (i == index || candidates[i] != candidates[i - 1])
            {
                current.push_back(candidates[i]);
                backtrack(candidates, target - candidates[i], result, current, i+1);
                current.pop_back();
            }
        }
    }
};