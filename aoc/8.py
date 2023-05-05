import itertools
f = open('input.in', 'r').read().split("\n")
res = ["abcefg", "cf", "acdeg", "acdfg", "bcdf", "abdfg", "abdefg", "acf", "abcdefg", "abcdfg"]
# 6, 2, 5, 5, 4, 5, 6, 3, 7, 6

# cf
# acf
# bcdf
# abcdefg


# 0 1 2 3 4 7 8 9

# acf, len5 = 3

# ac, len5 = 2, dif char between 3 -> e

# acf, len6, has e = 0
# acf, len6, no e = 9

# len 5 = 5, len 6 = 6

#  

# abcefg
# acdeg
# acdfg
# abdfg

# 1, 7 tell us A
# common = F
# other in 1 = C
# 


# a, c, f
# 
ans = 0
alpha = ['a', 'b','c','d','e','f','g']
pos = list(itertools.permutations(['a', 'b','c','d','e','f','g']))
actual = {}
for l in f:
  #print(l)
  o, vv = l.split("|")
  o = ["".join(sorted(x)) for x in o.split(" ")[:-1]]
  vv = ["".join(sorted(x)) for x in vv.split(" ")[1:]]
  for it in pos:
    m = {}
    for i in range(7):
      m[it[i]] = alpha[i]
    mapped = []
    for x in o:
      x2 = ""
      for c in x:
        x2 += m[c]
      mapped.append("".join(sorted(x2)))
    can = True
    for v in res:
      if v not in mapped:
        can = False
    #print(mapped)
    if can:
      actual = m
      break
  place = 1000
  val = 0
  for x in vv:
    x2 = ""
    for c in x:
      x2 += m[c]
    x2 = "".join(sorted(x2))
    val += res.index(x2) * place
    place /= 10
  ans += val
    



  
    
print(ans)
