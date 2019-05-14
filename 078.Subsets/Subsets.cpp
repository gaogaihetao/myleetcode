vector<vector<int>> subsets(vector<int> &nums) {
  vector<vector<int>> ret;
  for(int i=0; i<nums.size(); i++) {
    int retSize=ret.size();
    for(int j=0; j<retSize; j++) {
      vector<int> tmp=ret[j];
      tmp.push_back(nums[i]);
      ret.push_back(tmp);
    }
    vector<int> tmp(1);
    tmp[0]=nums[i];
    ret.push_back(tmp);
  }
  vector<int> tmp;
  ret.push_back(tmp);
  return ret;
}