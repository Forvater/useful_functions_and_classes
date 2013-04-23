// Computing number modulus
unsigned int Abs(int a) {
  if (a >= 0) {
    return a;
  } else {
    return (~a + 1);
  }
}
