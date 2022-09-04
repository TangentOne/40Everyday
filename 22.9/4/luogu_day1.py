# 洛谷 普及 P1007 独木桥
def luogu1007():
    L = int(input())
    N = int(input())
    N_nums = []
    if N>0:
        N_nums = list(map(int, input().split()))

    # 最长时间与最短时间
    l_time = 0
    m_time = 0

    if N>0:
        for i in N_nums:
            max(i, L+1-i)
            l_time = max(l_time, max(i, L+1-i))
            m_time = max(m_time, min(i, L+1-i))

    print(m_time, end=" ")
    print(l_time)

# P1008 [NOIP1998 普及组] 三连击
def digui(rest_list, listed):
    temp_list = listed[:]
    rest_n = len(rest_list)
    if rest_n==1:
        temp_list.append(rest_list[0])
        n1 = temp_list[0]*100+temp_list[1]*10+temp_list[2]
        n2 = temp_list[3]*100+temp_list[4]*10+temp_list[5]
        n3 = temp_list[6]*100+temp_list[7]*10+temp_list[8]
        # print("n1, n2, n3:", n1, n2, n3)
        if 2*n1==n2 and 3*n1==n3:
            print(n1, end=" ")
            print(n2, end=" ")
            print(n3)
        return

    for i in range(rest_n):
        temp_list = listed[:]
        temp_list.append(rest_list[i])
        list1 = []
        for j in range(rest_n):
            if j != i:
                list1.append(rest_list[j])
        digui(list1, temp_list)

    return

def luogu1008():
    digui([1,2,3,4,5,6,7,8,9], [])
    return

# luogu1007()
luogu1008()
