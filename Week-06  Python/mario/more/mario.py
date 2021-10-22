#
o = input("Height: ")

#
while (not o.isdigit()):
    o = input("Height: ")

#
s = int(o)

#
while (s < 1 or s > 8):
    s = int(input("Height: "))

#
for i in range(s):

    for j in range(s - 1 - i):
        print(" ", end="")

    for j in range(i + 1):
        print("#", end="")

    print("  ", end="")

    for j in range(i + 1):
        print("#", end="")

    print("")