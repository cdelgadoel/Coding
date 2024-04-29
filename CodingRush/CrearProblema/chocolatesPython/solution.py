def se_puede(dieta, paga, n):
    total_chocolates = 0
    respuesta = True
    i = 0
    while i < n and respuesta:
        total_chocolates += paga[i]
        total_chocolates -= dieta
        if total_chocolates < 0:
            respuesta = False
        i += 1
    return respuesta

def max_chocolates(paga, n):
    ini = 0
    fin = max(paga)  # Ajustamos para buscar el máximo valor posible en toda la lista

    while ini != fin:
        mitad = (ini + fin + 1) // 2

        if se_puede(mitad, paga, n):
            ini = mitad
        else:
            fin = mitad - 1

    return ini


n = int(input())
paga = []
for i in range(n):
    paga.append(int(input()))

print(max_chocolates(paga, n))