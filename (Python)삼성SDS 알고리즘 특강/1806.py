

def solution():
    n, s = map(int, input().split())
    nums = list(map(int, input().split()))
    left, right = 0, 1
    answer = 100001

    # 0 ~ n 합 구하기
    num_lst = [0] * (n+1)
    for i in range(1, n + 1):
        num_lst[i] = num_lst[i-1] + nums[i-1]
    
    while left != n:
        if num_lst[right] - num_lst[left] >= s:
            if right - left < answer:
                answer = right - left
            left += 1
        else:
            if right != n:
                right += 1
            else:
                left += 1
    return 0 if answer == 100001 else answer

print(solution())