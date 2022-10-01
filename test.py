import itertools
def flag_upper_diagonal(r, c):
    if r<0 or c>=on:
        return 
    flag[r][c]= True
    flag_upper_diagonal(r-1,c+1)

def flag_lower_diagonal(r, c):
    if r>=on or c>=on:
        return 
    flag[r][c]= True
    flag_upper_diagonal(r+1,c+1)


#check?
def find_next():
    return next(((r, c) for r, c in itertools.product(range(on), range(on)) if not flag[r][c]), (-1, -1))


def check(n):
    if n<0:
        return True
    coors = find_next()
    if coors==(-1, -1):
        return False
    for c in range(on-n, on):
        if flag[coors[0]][c]:
            return False
        flag[coors[0]][c] = True
    for r in range(on-n, n):
        if flag[r][coors[1]]:
            return False
        flag[r][coors[1]]=True
    flag_upper_diagonal(coors[0], coors[1])
    flag_lower_diagonal(coors[0], coors[1])



for _ in range(int(input())):
    on = int(input('Enter size of chess board:'))
    flag = [[False for _ in range(on)] for _ in range(on)]
    flag[0][0] = True
    for r, c in itertools.product(range(on), range(on)):
        if r==0 or c==0 or r==c:
            flag[r][c] = True
    if check(on-1):
        print('YES')
    else:
        print('NO')
