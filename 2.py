s=input()
s1=s.split()
s2=s1[0]
res = 0
for char in s2:
    x = ord(char) - ord('A') + 1
    res = res * 26 + x
print (res)
