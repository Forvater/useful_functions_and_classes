// Greatest Common Divisor, Binary Euclidean Algorithm
int gcd(int m, int n) {
  if(m == 0) return n;
  if(n == 0) return m;
  if(m == n) return m;
  if(m == 1) return 1;
  if(n == 1) return 1;
  if((IsEven(m) == true) && (IsEven(n) == true)) {
    return (2 * gcd((m/2),(n/2)));
  }
  if((IsEven(m) == true) && (IsEven(n) == false)) {
      return gcd((m/2),n);
  }
  if((IsEven(m) == false) && (IsEven(n) == true)) {
      return gcd(m,(n/2));
  }
  if((IsEven(m) == false) && (IsEven(n) == false)) {
    if(m > n) {
      return gcd(((m - n) / 2), n);
    } else if (m < n) {
      return gcd(((n - m) / 2), m);
    }
  }
}

bool IsEven(int a) {
  if((a % 2) == 0) return true;
  else return false;
}