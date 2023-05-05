import sys
sys.setrecursionlimit(10001)


f = open("input.in", "r").read().split("\n")
v = []
for l in f:
  v.append(list(map(int, l)))

dirs = [(-1, 0), (0, -1), (0, 1), (1,0)]
res = 0
lows = []
for i in range(len(v)):
  for j in range(len(v[i])):
    low = True
    for d in dirs:
      if i + d[0] < 0 or i + d[0] >= len(v):
        continue
      if j + d[1] <0 or j + d[1] >= len(v[i]):
        continue
      if v[i + d[0]][j + d[1]] <= v[i][j]:
        low = False
    if low:
      lows.append((i, j))
lens = []
vis = set()
for low in lows:
  def dfs(low):
    if low in vis:
      return 0
    i = low[0]
    j = low[1]
    vis.add(low)
    cnt = 0
    if v[i][j] != 9:
      cnt = 1 
    for d in dirs:
      if i + d[0] < 0 or i + d[0] >= len(v):
        continue
      if j + d[1] <0 or j + d[1] >= len(v[i]):
        continue
      if v[i + d[0]][j + d[1]] >= v[i][j]:
        cnt += dfs((i + d[0], j + d[1]))
    return cnt
  lens.append(dfs(low))
lens.sort()
lens = lens[::-1]
res = lens[0] * lens[1] * lens[2]
    
print(res)

      
