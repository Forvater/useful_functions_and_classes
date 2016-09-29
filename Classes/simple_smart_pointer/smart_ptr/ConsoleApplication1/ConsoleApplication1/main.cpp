#include "simple_smart_pointer.h"

class A {
  public:
    A() : some_var(10) {}
    ~A() {}
    int get_some_var() { return some_var; }
    void set_some_var(int var) { some_var = var; }
  private:
    int some_var;
};

Smart<A> another_func() {
    Smart<A> sm = Smart<A>(new A);
    int res = sm->get_some_var();
    return sm;
}

int main() {
    {
        Smart<A> sma2 = another_func();
        Smart<A> sma3 = Smart<A>(new A);
        sma3 = sma2;
        int res2 = sma2->get_some_var();
    }
    return 0;
}
