vector<int> productExceptSelf(vector<int> &nums) {
  vector<int> retVec(nums.size());
  retVec[0]=1;
  for(int i=0; i<nums.size()-1; i++) {
    retVec[i+1]=retVec[i]*nums[i];
  }
  int product=1;
  for(int i=nums.size()-1; i>0; i--) {
    product*=nums[i];
    retVec[i-1]*=product;
  }
  return retVec;
}