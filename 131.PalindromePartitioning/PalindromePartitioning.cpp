vector<vector<string>> partition(string s) {
  vector<vector<string>> vvs;
  vector<string> vs;
  permutation(s, 0, vs, vvs);
  return vvs;
}

void permutation(string& s, int cur, vector<string> vs, vector<vector<string>>& vvs) {
  if(cur == s.size()) {
    vvs.push_back(vs);
    return;
  }
  for(int i =cur; i < s.size(); i++) {
    if(isPalindrome(s.substr(cur, i-cur+1))) {
      vector<string> tmp(vs);
      tmp.push_back(s.substr(cur, i-cur+1));
      permutation(s, i+1, tmp, vvs);
    }
  }
}

bool isPalindrome(string str) {
  for(int i = 0; i < str.size()/2; i++) {
    if(str[i] != str[str.size()-i-1]) {
      return false;
    }
  }
  return true;
}