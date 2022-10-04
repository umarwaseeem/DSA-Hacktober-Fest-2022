def fib(n):
    if(n <= 2): return 1
    return fib(n-1) + fib(n-2)

for i in range(10):
    print(fib(i+1))