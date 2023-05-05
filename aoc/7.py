f = open('input.in', 'r')
x = list(map(int, f.read().split(',')))
x.sort()
print(len(x))
mid = len(x) // 2
#c = (x[mid] + x[mid - 1]) // 2
res = 1e20
for c in range(min(x), max(x) + 1):
  ans = 0
  for v in x:
    ans += abs(v - c) * (abs(v - c) + 1) / 2
  res = min(res, ans)
print(res)
