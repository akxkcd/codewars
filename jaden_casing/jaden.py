def toJadenCase(string):
    # ...
    lst = [word[0].upper() + word[1:] for word in string.split(' ')  ]
    return ' '.join(lst)

val = toJadenCase("this should work")
print toJadenCase("this should work")
