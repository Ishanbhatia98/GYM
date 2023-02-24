s = input('Enter string: ')
s+='$'
n = len(s)
a = [(s[i], i) for i in range(n)]
a.sort(key=lambda x: x[0])
p = [a[i][1] for i in range(n)]
c = [0 for _ in range(n)]
c[p[0]] = 0
for i in range(1, n):
        c[p[i]] = c[p[i-1]] if (a[i][0]==a[i-1][0]) else 1+c[p[i-1]]
k = 0
while (k<n):
        for i in range(n):
                a[i] = ((c[i], c[(i+(1<<k))%n]), i)
        a.sort(key=lambda x:x[0][0]*10+x[0][1])
        p = [i[1] for i in a]
        c[p[0]] = 0
        for i in range(1, n):
                c[p[i]] = c[p[i-1]] if (a[i][0]==a[i-1][0]) else 1+c[p[i-1]]
        k = 1 << k
print(*p)