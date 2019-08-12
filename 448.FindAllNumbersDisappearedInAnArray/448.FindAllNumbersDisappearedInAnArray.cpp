class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        /*
        vector<int> vec;
        if(nums.empty()) {
            return vec;
        }
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums[0]; i++) {
            vec.push_back(i);
        }
        for(int i = 0; i < nums.size() - 1; i++) {
            if((nums[i+1] - nums[i]) <= 1) {
                continue;
            }
            for(int dif = 1; dif < (nums[i+1] - nums[i]); dif++) {
                vec.push_back(nums[i] + dif);
            }
        }
        for(int num = nums[nums.size() - 1] + 1; num <= nums.size(); num++) {
            vec.push_back(num);
        }
        return vec;
        */
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;
            nums[index] = 0 - abs(nums[index]);
        }
        vector<int> vec;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0) {
                vec.push_back(i+1);
            }
        }
        return vec;
    }
};