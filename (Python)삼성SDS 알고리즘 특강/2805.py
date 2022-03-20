def solution():
    n, m = map(int, input().split())
    tree = list(map(int, input().split()))
    start, end = 1, max(tree)
    while start <= end:
        mid = (start + end) // 2

        total = 0
        for height in tree:
            if height >= mid:
                total += height - mid # 남게 되는 트리

        # 트리 이분 탐색
        if total >= m:
            start = mid + 1
        else:
            end = mid - 1

    return end

print(solution())