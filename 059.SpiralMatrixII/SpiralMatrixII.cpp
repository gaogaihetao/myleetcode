/******************************************************************************
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n2 in spiral order.
 ******************************************************************************/
vector<vector<int>> generateMatrix(int n) {
  vector<vector<int>> ma(n,vector<int>(n));
  int pos=0;
  int ele=1;
  int len=n;
  while(len>0) {
    for(int i=pos; i<pos+len; i++)
    { ma[pos][i]=ele++; }
    if(ele>n*n)
    { break; }
    for(int i=pos+1; i<pos+len; i++)
    { ma[i][pos+len-1]=ele++; }
    if(ele>n*n)
    { break; }
    for(int i=pos+len-2; i>=pos; i--)
    { ma[pos+len-1][i]=ele++; }
    if(ele>n*n)
    { break; }
    for(int i=pos+len-2; i>pos; i--)
    { ma[i][pos]=ele++; }
    if(ele>n*n)
    { break; }
    pos++;
    len-=2;
  }
  return ma;
}