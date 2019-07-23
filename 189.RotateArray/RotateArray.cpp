void rotate(vector<int>& nums, int k) {
  k = k % nums.size();
  vector<int> tmp(nums.begin()+nums.size()-k, nums.end());
  tmp.insert(tmp.end(), nums.begin(), nums.begin()+nums.size()-k);
  nums = tmp;
}