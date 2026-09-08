class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int first_index;
        int last_index;
        int i;
        for(i = 0; i < nums.size(); i++) {
            first_index = i;
            auto it = find(nums.begin() + i + 1, nums.end(), target - nums[first_index]);
            if(it != nums.end()) {
                last_index = distance(nums.begin(), it);
            } else {
                continue;
            }
            if(last_index >= nums.size()) {
                continue;
            } else {
                break;
            }
        }
        vector<int> ret_vec = {first_index, last_index};
        return ret_vec;
    }
};