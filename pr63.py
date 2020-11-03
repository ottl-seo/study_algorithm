# -*- coding: cp949 -*-

def power(a,n):
    for k in range(0,100):
        if(a**k>n):
            return (k-1)

while(True):
    a=int(input("a= "))
    if(a==1):   break
    n=int(input("n= "))

    k=power(a,n)
    print("k="+str(k)+"\n")

print("Program finished")
