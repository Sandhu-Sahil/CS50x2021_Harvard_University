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
if (s > 0 and s < 9):
    for i in range(s):

        for j in range(s - 1 - i):
            print(" ", end="")

        for j in range(i + 1):
            print("#", end="")

        print("")
