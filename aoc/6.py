f = open("input.in")
x = map(int, f.read().split(","))
res = [0] * 9
ans = 0
for v in x:
  res[v] += 1
for i in range(256):
  n = [0] * 9
  for j in range(1, 9):
    n[j - 1] = res[j]
  n[6] += res[0]
  n[8] += res[0]
  res = n
print(sum(res))