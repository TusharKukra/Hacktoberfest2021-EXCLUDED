#!/bin/python3

import math
import os
import random
import re
import sys

# Complete the repeatedString function below.
def repeatedString(s, n):
    q=s.count("a")
    w=n%len(s)
    e=n//len(s)
    c=0
    for i in range(w):
        if (s[i]=="a"):
            c+=1
    return(q*e+c)
            
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    n = int(input())

    result = repeatedString(s, n)

    fptr.write(str(result) + '\n')

    fptr.close()
