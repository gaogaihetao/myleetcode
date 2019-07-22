vector<int> plusOne(vector<int>& digits) {
  int i = digits.size() - 1;
  while(i>=0) {
    digits[i] += 1;
    if(digits[i] < 10)
      break;
    digits[i] = 0;
    i--;
  }
  if(i==-1)
    digits.insert(digits.begin(), 1);
  return digits;
}