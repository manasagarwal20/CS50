from cs50 import get_float

inf = -1.0

while inf < 0:
    inf = get_float("Change owed: ")
inf = inf * 100
inp = round(inf)
count = 0
while inp >= 25:
    count = count + 1
    inp = inp - 25
while inp >= 10:
    count = count + 1
    inp = inp - 10
while inp >= 5:
    count = count + 1
    inp = inp - 5
while inp >= 1:
    count = count + 1
    inp = inp - 1
print(count)

