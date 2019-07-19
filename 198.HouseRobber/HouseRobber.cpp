int rob(vector<int>& nums) {
  if(nums.empty())
    return 0;
  int k0 = 0;
  int k1 = nums[0];
  int k = k1;
  for(int i=1; i<nums.size(); i++) {
    k = max(k0+nums[i], k1);
    k0 = k1;
    k1 = k;
  }
  return k;
}