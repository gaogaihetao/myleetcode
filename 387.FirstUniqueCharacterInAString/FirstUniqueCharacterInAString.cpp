int firstUniqChar(string s) {
  /*
  set<char> repeatChar;
  for(int i = 0; i < s.size(); i++) {
      auto it = repeatChar.find(s[i]);
      if(it != repeatChar.end())
          continue;
      repeatChar.insert(s[i]);
      size_t pos = s.find(s[i], i+1);
      if(pos == string::npos)
          return i;
  }
  return -1;
  */
  /*
  map<char, pair<int, int> > repeatMap;
  for(int i = 0; i < s.size(); i++) {
      auto it = repeatMap.find(s[i]);
      if(it == repeatMap.end()) {
          repeatMap[s[i]] = make_pair(1, i);
      } else {
          it->second.first += 1;
      }
  }
  int minPos = s.size();
  for(auto it : repeatMap) {
      if(it.second.first > 1)
          continue;
      if(it.second.second < minPos)
          minPos = it.second.second;
  }
  if(minPos < s.size())
      return minPos;
  else
      return -1;
  */
  vector<int> vec(26, 0);
  for(auto c : s)
    vec[c-'a'] += 1;
  for(int i = 0; i < s.size(); i++) {
    if(vec[s[i] - 'a'] == 1)
      return i;
  }
  return -1;
}