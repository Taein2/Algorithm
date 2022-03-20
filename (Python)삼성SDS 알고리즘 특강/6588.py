def solution():
    lst = [True] * 1000001
    for i in range(2, 1001):
        if lst[i]:
            for j in range(i + i, 1000001, i):
                if lst[j]:
                    lst[j] = False
    while True:
        n = int(input())
        if n == 0:  break
        else:
            for i in range(3, len(lst)):
                if lst[i] and lst[n-i]:
                    print("{} = {} + {}".format(n, i, n-i))
                    break
solution()