r, c = map(int,input().split())
m1 = []
for i in range(r):
    m1.append(list(map(int,input().split())))
for i in range(r):
    for j in range(c):
        if m1[i][j] == 1:
            m1[i][j] = -1
if m1[0][0] == -1:
    print(0%1000000007)
else:
    for i in range(r):
        if m1[i][0] == 0:
            m1[i][0] = 1
        else:
            break
    for j in range(1, c):
        if m1[0][j] == 0:
            m1[0][j] = 1
        else:
            break
    
    for i in range(1, r):
        for j in range(1, c):
            if m1[i][j] == -1:
                continue
            if m1[i-1][j] > 0:
                m1[i][j] = m1[i][j] + m1[i-1][j]
            if m1[i][j-1] > 0:
                m1[i][j] = m1[i][j] + m1[i][j-1]
    if m1[r-1][c-1] > 0:
        print(m1[r-1][c-1]%1000000007) 
    else:
        print(0%1000000007)           
