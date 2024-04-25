n, m = input().split(' ')
n = int(n)
m = int(m)


powers = [0, 1]
limit = 1
while limit < 4000 and powers[limit]//limit <= m:
    limit += 1
    powers.append(limit**n)
pans = -1
qans = -1
for q in range(2, limit + 1):
    for p in range(1, q):
        if pans == -1 and m % ((powers[q] - powers[q-p]) // p) == 0:
            pans = p
            qans = q
if pans > -1:
    print(pans, qans)
else:
    print("impossible")
