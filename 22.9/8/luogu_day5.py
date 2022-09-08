# P1013 [NOIP1998 提高组] 进制位

import numpy as np

def luogu1013():
    n = int(input())
    table1 = []
    for i in range(n):
        table1.append(list(map(str, input().split())))

    # 简单检查方程有效性
    num_2 = [] #大于10的数字
    for i in range(1,n):
        for j in range(1, i+1):
            if table1[i][j]!=table1[j][i]:
                print("ERROR!")
                return
            if len(table1[i][j])>1:
                num_2.append(table1[i][j])

    if len(num_2)==0:
        print("ERROR!")
        return
    for i in range(len(num_2)-1):
        if num_2[i][0] != num_2[i+1][0] or len(num_2[i])>2 or len(num_2[i+1])>2:
            print("ERROR!")
            return

    id_letter1 = list(-np.ones(20))
    id_letter2 = list(-np.ones(20))
    for i in range(1, n):
        if num_2[0][0]==table1[0][i][0]:
            id_letter1[1] = i
            id_letter2[i] = 1
            break

    for i in range(1,n):
        if table1[i][i] == table1[0][i]:
            id_letter1[0] = i
            id_letter2[i] = 0

    h = n
    if id_letter1[0]>=0:
        h-=1
    pos0 = id_letter1[1]
    for i in range(2, h):
        for j in range(1, n):
            if table1[id_letter1[1]][pos0] == table1[0][j]:
                pos0 = j
                id_letter1[i] = j
                id_letter2[j] = i
                break

    id_letter3 = list(-np.ones(100))
    for i in range(1,n):
        id_letter3[ord(table1[0][i][0])-ord('a')] = id_letter2[i]

    for i in range(1,n):
        for j in range(1,n):
            if id_letter2[i]+id_letter2[j]!=h*(len(table1[i][j])-1)+id_letter3[ord(table1[i][j][-1])-ord('a')]:
                print("ERROR!")
                return

    for i in range(1,n):
        print(table1[0][i][0], end="=")
        print(id_letter2[i], end=" ")
    print()
    print(h)


luogu1013()
