vector<int> grayCode(int n) {
  vector<int> ret(1,0);
  for(int i=1; i<=n; i++) {
    int tmp=pow(2,i-1);
    for(int j=ret.size()-1; j>=0; j--)
      ret.push_back(tmp+ret[j]);
  }
  return ret;
}