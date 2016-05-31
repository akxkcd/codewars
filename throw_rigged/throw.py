import random
def throw_rigged():
    i = random.randint(1,100)
    if (i<=22):
        return 6
    else:
        return random.randint(1,5)

print throw_rigged()
