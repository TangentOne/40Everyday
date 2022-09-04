def quick(a,b,list):
    if b<=a+1:
        return
    temp_pos=a
    for i in range(a+1,b):
        if list[i]<list[temp_pos]:
            list[i],list[temp_pos],list[temp_pos+1]=list[temp_pos+1],list[i],list[temp_pos]
            temp_pos+=1
    if temp_pos!=a and temp_pos!=b-1:
        quick(a,temp_pos,list)
        quick(temp_pos+1,b,list)
    elif temp_pos==a:
        quick(temp_pos + 1, b, list)
    elif temp_pos==b-1:
        quick(a,b-1,list)


list=[5,4,23,334,1,232,3434,9,4,4,4]
quick(0,len(list),list)
print(list)
