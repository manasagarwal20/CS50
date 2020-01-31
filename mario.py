h = -1
while h>8 or h<0:
    h = int(input("Height: "))
for i in range(1, h + 1):
        print(' ' * (h - i) + "#" * i)