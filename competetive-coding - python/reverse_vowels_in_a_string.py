#Time : O(n)
#Space: O(n)

def reverseVowels(s):
    s = [c for c in s]
    vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'}

    i = 0
    j = len(s) - 1

    while i < j:
        while i < j and s[i] not in vowels:
            i += 1
        while i < j and s[j] not in vowels:
            j -= 1

        s[i], s[j] = s[j], s[i]
        i += 1
        j -= 1

    return ''.join(s)


print(reverseVowels("Hello"))
