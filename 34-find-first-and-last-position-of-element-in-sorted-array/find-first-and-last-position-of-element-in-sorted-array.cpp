class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result = {-1, -1};
        int n = nums.size();
        if (n == 0)
        {
            return result;
        }
        int left = 0, right = n - 1;
        while(left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target)
            {
                int i = mid, j = mid;
                while (i >= 0 && nums[i] == target)
                {
                    i--;
                }
                while (j < n && nums[j] == target)
                {
                    j++;
                }
                result[0] = i + 1;
                result[1] = j - 1;
                return result;
            }
            else if (nums[mid] < target)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }
        return result;
    }
};