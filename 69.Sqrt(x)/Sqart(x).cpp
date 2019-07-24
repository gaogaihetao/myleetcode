int mySqrt(int x) {
  if(x == 0)
    return 0;
  long i = 1;
  long j = x;
  while((j - i) > 1) {
    long mid = (i + j)/2;
    long square = mid*mid;
    if(square < x)
      i = mid;
    else if(square > x)
      j = mid;
    else
      return mid;
  }
  return i;
}