from collections import defaultdict
def solution():
    t = int(input())
    n = int(input())
    a = list(map(int, input().split()))
    m = int(input())
    b = list(map(int, input().split()))
    
    dic = defaultdict(int)
    answer = 0
    for i in range(n):
        for j in range(i, n):
            dic[sum(a[i:j+1])] += 1
    for i in range(m):
        for j in range(i, m):
            answer += dic[t - sum(b[i:j+1])]
    return answer
print(solution())