def gcd(x,y):
    mod = x % y
    while mod > 0:
        x = y
        y = mod
        mod = x % y
    return y
def solution():
    a, b = map(int, input().split())
    c, d = map(int, input().split())

    n = gcd((a*d) + (c*b), b * d)
    r1 = ((a*d) + (c*b)) //n
    r2 = b * d //n
    print(r1,r2)
solution()