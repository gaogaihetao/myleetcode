vector<string> generateParenthesis(int n) {
  vector<string> ss;
  string s;
  next(ss, s, n, n);
  return ss;
}

void next(vector<string>& ss, string str, int l, int r) {
  if(l==0 && r==0) {
    ss.push_back(str);
    return;
  }
  if(l!=0)
    next(ss, str+"(", l-1, r);
  if(r!=0 && r>l)
    next(ss, str+")", l, r-1);
}