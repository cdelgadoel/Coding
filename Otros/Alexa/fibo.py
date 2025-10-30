class Fibo:
    fibonacci = [0]*1000
    
    def fibo(self, n):
        if n<=1:
            return 1
        if this.fibonacci[n] == 0:
            this.fibonacci[n] = fibo(n-1) + fibo(n-2)
        return this.fibonacci[n]

print(Fibo.fibo(10001))