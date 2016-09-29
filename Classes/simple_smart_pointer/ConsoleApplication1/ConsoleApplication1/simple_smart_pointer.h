#ifndef SIMPLE_SMART_POINTER_H
#define SIMPLE_SMART_POINTER_H

class RefCount {
  public:
    RefCount() : counter(0) {}
    ~RefCount() {}
    void inc_count() { counter++; }
    void dec_count() { counter--; }
    int get_count() { return counter; }
  private:
    int counter;
};

template <class T>
class Smart {
  public:
    Smart() {}
    Smart(T* ptr);
    Smart(const Smart& other);
    ~Smart();
    T* operator->();
    Smart& operator=(const Smart& other);
  private:
    T* internal_ptr;
    RefCount* reference_count_ptr;
};

template <class T>
Smart<T>::Smart(T* ptr) : internal_ptr(ptr) {
    reference_count_ptr = new RefCount();
    reference_count_ptr->inc_count();
}

template <class T>
Smart<T>::Smart(const Smart<T>& other) {
    internal_ptr = other.internal_ptr;
    reference_count_ptr = other.reference_count_ptr;
    reference_count_ptr->inc_count();
}

template <class T>
Smart<T>::~Smart() {
    reference_count_ptr->dec_count();
    if (reference_count_ptr->get_count() == 0) {
        delete internal_ptr;
        delete reference_count_ptr;
    }
}

template <class T>
T* Smart<T>::operator->() {
    return internal_ptr;
}

template <class T>
Smart<T>& Smart<T>::operator=(const Smart<T>& other) {
    if (this != &other) {
        reference_count_ptr->dec_count();
        if (reference_count_ptr->get_count() == 0) {
            delete internal_ptr;
            delete reference_count_ptr;
        }
        internal_ptr = other.internal_ptr;
        reference_count_ptr = other.reference_count_ptr;
        reference_count_ptr->inc_count();
    }
    return *this;
}

#endif  // SIMPLE_SMART_POINTER_H
