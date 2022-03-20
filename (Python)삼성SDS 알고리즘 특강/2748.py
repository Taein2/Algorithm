def solution():
    n = int(input())
    lst = [0,1,1,2]
    for i in range(3,n):
        lst.append(lst[i-1] + lst[i])
    return lst[n]
print(solution())