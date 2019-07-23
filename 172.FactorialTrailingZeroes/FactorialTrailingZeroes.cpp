int trailingZeroes(int n) {
  // 0! = 1
  if(n == 0)
    return 0;

  // zeros = n/5 + n/5^2 + ... + n/5^p
  // note: 5^(p-1) < n And 5^p > n
  int count = 0;
  long i = 5;
  while(n / i > 0) {
    count += n/i;
    i *= 5;
  }
  return count;
}