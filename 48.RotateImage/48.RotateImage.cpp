void rotate(vector<vector<int>>& matrix) {
  vector<vector<int>> rotateMatrix = matrix;
  for(int i = 0; i < rotateMatrix.size(); i++) {
    for(int j = 0; j < rotateMatrix[i].size(); j++) {
      int iR = j;
      int jR = 0 - i + rotateMatrix.size() - 1;
      matrix[iR][jR] = rotateMatrix[i][j];
    }
  }
}

void rotate(vector<vector<int>>& matrix) {
  int n = matrix.size();
  for(int i = 0; i < n/2; i++) {
    for(int j = i; j <= n-2-i; j++) {
      int cur = matrix[i][j];
      int post = matrix[j][n-1-i];

      matrix[j][n-1-i] = cur;
      cur = post;
      post = matrix[n-1-i][n-1-j];

      matrix[n-1-i][n-1-j] = cur;
      cur = post;
      post = matrix[n-1-j][i];

      matrix[n-1-j][i] = cur;
      cur = post;

      matrix[i][j] = cur;
    }
  }
}