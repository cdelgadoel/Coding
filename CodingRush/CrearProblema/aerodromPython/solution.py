n, m= map(int, input().split())
t = [0]*n
for i in range(n):
    t[i] = int(input())

ini = 1
fin = t[0] * m

while ini != fin:
    suma = 0
    mitad = (ini + fin) // 2
    i = 0
    while i < n and suma < m:
        suma += mitad // t[i]
        i += 1
    
    if suma >= m:
        fin = mitad
    else:
        ini = mitad + 1

print(ini)