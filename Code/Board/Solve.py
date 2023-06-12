# -*- coding: utf-8 -*-
import math

def Solve(a,b,c) :
    if not isinstance(a,(int,float)):
        raise TypeError("Need Number As Value")
    if not isinstance(b, (int, float)):
        raise TypeError("Need Number As Value")
    if not isinstance(c,(int,float)):
        raise TypeError("Need Number As Value")
    delta = b*b-4*a*c
    if(delta < 0):
        return
    elif (delta == 0):
        x1 = x2 = (-b)/(2*a)
        return x1,x2
    else:
        delta = math.sqrt(delta)
        x1 = (-b+delta)/(2*a)
        x2 = (-b-delta)/(2*a)
        return x1,x2

if Solve(2, 3, 1) != (-0.5, -1.0):
    print('测试失败')
elif Solve(1, 3, -4) != (1.0, -4.0):
    print('测试失败')
else:
    print('Code.py测试成功')