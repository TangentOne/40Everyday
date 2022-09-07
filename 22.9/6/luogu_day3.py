# P1011 [NOIP1998 提高组] 车站

def luogu1011():
    a, n, m, x = map(int, input().split())

    up_peo = [[],[]]
    down_peo = [[],[]]
    now_peo = [a,0]
    pos = 0

    if n==x:
        print(0)
        return
    elif x==1 or x==2:
        print(a)
        return

    for i in range(22):
        up_peo[0].append(0)
        up_peo[1].append(0)
        down_peo[0].append(0)
        down_peo[1].append(0)

    up_peo[0][1] = a

    up_peo[1][2] = 1
    down_peo[1][2] = 1

    for i in range(3, n):
        up_peo[0][i] = up_peo[0][i-1] + up_peo[0][i-2]
        up_peo[1][i] = up_peo[1][i - 1] + up_peo[1][i - 2]
        down_peo[0][i] = up_peo[0][i-1]
        down_peo[1][i] = up_peo[1][i-1]
        now_peo[0] += (up_peo[0][i]-down_peo[0][i])
        now_peo[1] += (up_peo[1][i]-down_peo[1][i])

    b = int((m-now_peo[0])/now_peo[1])

    now_peo = [0,0]
    for i in range(1, x+1):
        now_peo[0] += (up_peo[0][i]-down_peo[0][i])
        now_peo[1] += (up_peo[1][i] - down_peo[1][i])

    print(int(now_peo[0] + now_peo[1]*b))

luogu1011()
