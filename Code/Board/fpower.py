# -*- coding: utf-8 -*-

def fpower(x,n=2):
    Sum = 1
    while n>=1 :
        if n%2 == 1 :
            Sum *= x
            n -= 1
        else :
            n /= 2
            x *= x
    return Sum

print(fpower(5))
print(fpower(2,10))
print(fpower(2,9))
print(fpower(3))