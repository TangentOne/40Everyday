# P1004 [NOIP2000 提高组] 方格取数
import numpy as np

def luogu1004():
    dp = np.zeros([11, 11, 11, 11])
    # print(dp.shape)
    map1 = np.zeros([11,11])

    n = int(input())
    while True:
        x,y,v = map(int,input().split())
        if x==0 and y==0 and v==0:
            break
        else:
            map1[x][y] = v

    for n1 in range(2*n+1):
        if n1==0 or n1==1:
            continue
        for i1 in range(n+1):
            if i1==0:
                continue
            elif n1-i1>n:
                continue
            elif n1-i1<1:
                break
            for i2 in range(n+1):
                if i2==0:
                    continue
                elif n1-i2>n:
                    continue
                elif n1-i2<1:
                    break
                add_num=0
                if i1==i2:
                    add_num = map1[i1][n1-i1]
                else:
                    add_num = map1[i1][n1-i1] + map1[i2][n1-i2]
                dp[i1][n1-i1][i2][n1-i2] = max(max(dp[i1-1][n1-i1][i2-1][n1-i2], dp[i1-1][n1-i1][i2][n1-i2-1]),max(dp[i1][n1-i1-1][i2-1][n1-i2], dp[i1][n1-i1-1][i2][n1-i2-1]))+add_num

    print(int(dp[n][n][n][n]))

luogu1004()
