vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
  vector<int> vec;
  multiset<int> mySet(nums2.begin(), nums2.end());
  for(int i=0; i<nums1.size(); i++) {
    multiset<int>::iterator it = mySet.find(nums1[i]);
    if(it != mySet.end()) {
      vec.push_back(*it);
      mySet.erase(it);
    }
  }
  return vec;
}