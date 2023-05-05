f = open("input.in", "r").read().split("\n");

m = {}
for l in f:
  a, _, b = l.split(" ")
  x1, y1 = a.split(",")
  x2, y2 = b.split(",")
  x1, y1, x2, y2 = int(x1), int(y1), int(x2), int(y2)
  if (x1 == x2):
    if y2 < y1:
      y2, y1 = y1, y2
    for y in range(y1, y2 + 1):
      if (x1, y) in m:
        m[(x1, y)] += 1
      else:
        m[(x1, y)] = 1
  elif (y1 == y2):
    if x2 < x1:
      x2, x1 = x1, x2
    for x in range(x1, x2 + 1):
      if (x, y1) in m:
        m[(x, y1)] += 1
      else:
        m[(x, y1)] = 1
  else:
    xd = (x2 - x1) // abs(x2 - x1)
    yd = (y2 - y1) // abs(y2 - y1)
    for i in range(abs(x2 - x1) + 1):
      x, y = x1 + i *xd, y1 + i * yd
      print (x1, y1, x2, y2, x, y)

      if (x, y) in m:
        m[(x, y)] += 1
      else:
        m[(x, y)] = 1
  res = 0
for x in m:
  if (m[x] >= 2):
    res += 1
print(len(m))
print(res)
    