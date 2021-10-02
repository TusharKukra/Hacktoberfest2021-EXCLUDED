import re

occurances = int(input())
main = []
flag = False
for i in range(occurances):
    main.append(str(input()))
dec = -1
ref = main[0]

# Searching for the longest common prefix in each word provided
while(len(ref) > 0):
    cc = 0
    for i in main:
        if re.match(ref, i): cc += 1
    if cc == occurances:
        print("The longest common prefix is : ")
        print(ref)
        flag = True
        break
    else:
        ref = ref[:-1]
if flag != True:
    print("No common prefix exists")