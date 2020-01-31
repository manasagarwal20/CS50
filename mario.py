h = -1
while h > 8 or h <= 0:
    h = input("Height: ")
    if h.isalpha() or h == '':
        h=-1
    else:
        h = int(h)

for i in range(1, h + 1):

        print(' ' * (h - i) + "#" * i)