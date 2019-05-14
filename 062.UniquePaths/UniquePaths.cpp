int uniquePaths(int m, int n) {
  vector<vector<int>> vecVec(m,vector<int>(n));
  for(int i=0; i<m; i++) {
    for(int j=0; j<n; j++) {
      if(i==0||j==0)
        vecVec[i][j]=1;
      else
        vecVec[i][j]=vecVec[i-1][j]+vecVec[i][j-1];
    }
  }
  return vecVec[m-1][n-1];
}