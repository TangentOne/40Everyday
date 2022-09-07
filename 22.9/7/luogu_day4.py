# P1012 [NOIP1998 提高组] 拼数

def cmp(a, b):
    if a+b > b+a:
        return True
    else:
        return False

def quicksort(temp_list, cmp):
    list1 = []
    list2 = []
    len1 = len(temp_list)
    if len1 == 0:
        return []
    elif len1 == 1:
        return [temp_list[0]]
    elif len1 == 2:
        if cmp(temp_list[1], temp_list[0]):
            return [temp_list[1], temp_list[0]]
        else:
            return [temp_list[0], temp_list[1]]

    list1.append(temp_list[len1-1])
    for i in range(0, len1-1):
        if cmp(temp_list[i], temp_list[len1-1]):
            list1.append(temp_list[i])
        else:
            list2.append(temp_list[i])

    list3 = quicksort(list1, cmp)
    list4 = quicksort(list2, cmp)
    return list3 + list4

def luogu1012():
    n = int(input())
    listn = list(map(str, input().split()))
    
    liste = quicksort(listn, cmp)
    for i in liste:
        print(i, end="")
    print()

luogu1012()
