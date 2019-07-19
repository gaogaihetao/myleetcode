bool isPalindrome(string s) {
  if(s.empty())
    return true;
  int i = 0;
  int j = s.size() - 1;

  while(i<j) {
    //cout << "begin s[" << i << "]=" << s[i] << " s[" << j << "]=" << s[j] << endl;
    char a;
    while(i<j) {
      if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= '0' && s[i] <= '9')) {
        a = s[i];
        break;
      }
      if(s[i] >= 'A' && s[i] <= 'Z') {
        a = s[i] + 'a' - 'A';
        break;
      }
      i++;
    }
    char b;
    while(i<j) {
      if((s[j] >= 'a' && s[j] <= 'z') || (s[j] >= '0' && s[j] <= '9')) {
        b = s[j];
        break;
      }
      if(s[j] >= 'A' && s[j] <= 'Z') {
        b = s[j] + 'a' - 'A';
        break;
      }
      j--;
    }
    if(i == j)
      break;
    //cout << "compare s[" << i << "]=" << s[i] << " s[" << j << "]=" << s[j] << endl;
    //cout << "compare a="<<a<<" b="<<b<<endl;
    if(a == b) {
      i++;
      j--;
    } else
      return false;
  }
  return true;
}