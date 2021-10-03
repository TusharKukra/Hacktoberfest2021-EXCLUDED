a = int(input())
n=list();
t=list();
h=list();
cuti=0;
j=0;
k=0;
for i in range(a):
    n.append(input().split())
    b=n[0]
    u=b[0]
    v=b[1]
    while(j<len(v) and k<len(u)):
        if(u[k]==v[j]):
            j=j+1
            k=k+1
            t.append(j)
        else:
            j=j+1;
    if(k==len(u)):
        h=t.copy()
        h.sort()
        if(h==t):
            print("true")
        else:
            print("false")
    else:
        print("false")
               
        
    n=[]
    t=[]
    j=0
    k=0
