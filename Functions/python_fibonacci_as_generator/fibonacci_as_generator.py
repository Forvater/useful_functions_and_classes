def fib_gen(stop_value):
    prev_prev = 0
    prev = 1
    outp = 1
    while outp < stop_value :
        yield outp
        outp = prev_prev + prev
        prev_prev = prev
        prev = outp
        
print list(fib_gen(10))