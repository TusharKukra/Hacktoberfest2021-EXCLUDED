def p(l,s,e):
    pv=l[s]
    c=0
    for i in range(s,e+1):
        if l[i]<pv:
            c+=1
    l[s+c],l[s]=l[s],l[s+c]
    index=s+c
    i=s
    j=e
    while i<j:
        if l[i]<pv:
            i+=1
        elif l[j]>=pv:
            j-=1
        else:
            l[i],l[j]=l[j],l[i]
            i+=1
            j-=1
    return index
def qs(l,s,e):
    if s>=e:
        return
    i=p(l,s,e)
    qs(l,s,i-1)
    qs(l,i+1,e)
    return l
l=[int(x) for x in input().split(' ')]
print(qs(l,0,len(l)-1))