def solution():
    num = int(input())
    lst = [True] * 4000001
    prime_lst = []

    for i in range(2, num+1):
        if lst[i]:
            prime_lst.append(i)
            for j in range(i + i, num+1, i):
                if lst[j]:
                    lst[j] = False
    answer = 0
    start = 0
    end = 0
    while end <= len(prime_lst):
        tmp = sum(prime_lst[start:end])
        if tmp == num:
            answer += 1
            end += 1
        elif tmp < num:
            end += 1
        else:
            start += 1
    return answer        
print(solution())