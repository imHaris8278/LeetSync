class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;

        sort(candidates.begin(), candidates.end());
        function<void(int, int)> backtrack = [&](int target, int start) {
        
            if (target < 0)
            {
                return;
            }
            else if (target == 0)
            {
                res.push_back(path);
                return;
            }
            else
            {
                for (int i = start; i < candidates.size(); i++)
                {
                    if (i > start && candidates[i] == candidates[i - 1])
                    {
                        continue;
                    }
                    
                    path.push_back(candidates[i]);
                    backtrack(target - candidates[i], i);
                    path.pop_back();
                }
            }
        };
        
        backtrack(target, 0);
        return res;
    }
};