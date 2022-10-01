from tabnanny import check


def check_arrangement(d, k, prev, curr):
    if k<=0:
        return True
    if curr>=n:
        return False
    if a[curr]-a[prev]>=d:
        return check_arrangement(d, k-1, curr, curr+1)
    return check_arrangement(d, k, prev, curr+1)

def bs(l, r, k):
    if l>r:
        return l
    m = l+(r-l)//2
    if check_arrangement(m, k, 0, 1):
        '''
        if not check_arrangement(m+1, k, 0, 1):
            return m
        '''
        return bs(m+1, r, k)
    return bs(l, m-1, k)


for _ in range(int(input())):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()
    print(bs(0, a[n-1]-a[0], k))