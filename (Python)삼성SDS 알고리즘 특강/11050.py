def solution():
    n, k = map(int, input().split())
    answer = 1
    for i in range(n-k+1, n+1):
        answer *= i
    for j in range(1, k+1):
        answer = answer // j
    print(answer)

solution()