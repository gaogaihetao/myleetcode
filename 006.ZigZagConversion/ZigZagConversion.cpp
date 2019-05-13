string convert(string s, int numRows) {
  vector<string> vecStr;
  int n=numRows+numRows-2;
  if(numRows==1)
    n=1;
  for(int i=0; i<s.size(); i+=n) {
    if(i+n>s.size())
      vecStr.push_back(s.substr(i));
    else
      vecStr.push_back(s.substr(i,n));
  }
  string retStr;
  for(int i=0; i<numRows; i++) {
    for(int j=0; j<vecStr.size(); j++) {
      if(i>vecStr[j].size()-1)
        continue;
      retStr.push_back(vecStr[j][i]);
      if(i==0||i==numRows-1)
        continue;
      if((numRows+numRows-2-i)>(vecStr[j].size()-1))
        continue;
      retStr.push_back(vecStr[j][numRows+numRows-2-i]);
    }
  }
  return retStr;
}