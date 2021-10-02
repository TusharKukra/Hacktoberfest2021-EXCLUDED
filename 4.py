T=int(input())
for i in range(T):
    base=int(input())
    n=int(input())
    if(base==2):
        x=bin(n)
    elif(base==8):
        x=oct(n)
    else:
        y=hex(n)
        x=y[:len(y)-1]+y[len(y)-1].capitalize()
    l=len(x)
    print(x[2:])
    
    
