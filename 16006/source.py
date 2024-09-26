import sys
from fractions import Fraction

N = int(sys.stdin.readline())
result = Fraction(0,1)

for i in range(1, N+1):
    result = result + Fraction(1, i)
    
print(result.numerator)
print(result.denominator)
