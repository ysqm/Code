# -*- coding: utf-8 -*-

def Mergesort(x):
    if not isinstance(x,list):
        raise TypeError("Need a list")
    R,L = len(x),0
    mid = (R+L)//2
    if R-L!=1:
        tmpl = list(Mergesort(x[L:mid]))
        tmpr = list(Mergesort(x[mid:R]))
        lc,rc,cu = 0,0,0
        while cu != R :
            if lc == mid :
                x[cu] = tmpr[rc]
                rc += 1
            elif rc == R-mid :
                x[cu] = tmpl[lc]
                lc += 1
            elif tmpl[lc] < tmpr[rc] :
                x[cu] = tmpl[lc]
                lc += 1
            else :
                x[cu] = tmpr[rc]
                rc += 1
            cu += 1
    return x

def main():
    a = [9,8,7,6,5,4,3,2,1,0]
    a = Mergesort(a)
    print(a)
    pass

if __name__ == "__main__":
    main()