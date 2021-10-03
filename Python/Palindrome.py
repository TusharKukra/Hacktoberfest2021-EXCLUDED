def checkPalindrome(text):
    return text == text[::-1]

string = 'level'

if checkPalindrome(string):
    print(string + ' is palindrome')
else:
    print(string + ' is not palindrome')