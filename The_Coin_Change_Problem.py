#The Coin Change Problem
#https://www.hackerrank.com/challenges/coin-change/problem

i = [int(k) for k in input().split()]
n = i[0]
m = i[1]

a = [int(k) for k in input().split()]

prev = [0]*(n+1)
prev[0] = 1
cur = [0]*(n+1)

for i in range(m):
    for j in range(n+1):
        if j>= a[i]:
            cur[j] = prev[j] + cur[j-a[i]]
        else:
            cur[j] = prev[j]
    prev = cur

print(cur[-1])