# Runtime approximately a + b.
## Very slow for 20 digit numbers. (IT MAY TAKES YEARS !!)

def gcd_naive(a, b):
    current_gcd = 1
    for d in range(2, min(a, b) + 1):
        if a % d == 0 and b % d == 0:
            if d > current_gcd:
                current_gcd = d

    return current_gcd


a = int(input())
b = int(input())

print(gcd_naive(a,b))
