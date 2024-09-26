import sys
sys.setrecursionlimit(10**6)

def fact(k):
    if k < 2:
        return 1
    else:
        return k * fact(k - 1)


if __name__ == "__main__":
    n = int(input())
    print(fact(n))
