"""实现一个希尔排序  使用list储存数据"""
list=[5,4,3,2,1]
def shell(list):
    step=len(list)//2
    while step:
        for i in range(step,len(list)):
            j = i
            while list[j]<list[j-step] and j-step>-1:
                list[j], list[j-step]=list[j-step],list[j]
                print(list)
                j-=step
        step//=2
    return list

shell(list)

