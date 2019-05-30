int numTrees(int n) {
  vector<int> vec(n+1,0);
  vec[0]=1;
  for(int i=1; i<=n; i++) {
    for(int j=0; j<i; j++)
      vec[i]+=vec[j]*vec[i-j-1];
  }
  return vec[n];
}