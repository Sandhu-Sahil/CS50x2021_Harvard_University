# For calculating number of coins to be retuned to customer if we have to return some amount of money.

from sys import exit

o = input("Change owe: ")

while (not o.isdecimal()):
    if (o.isalnum()):
        o = input("Change owe: ")
    elif(o == ""):
        o = input("Change owe: ")
    else:
        break

s = float(o)

#
while (s < 0):
    s = int(input("Change owe: "))

i = 0

while s >= 0.25:
    s = s - 0.25
    i += 1

#print(f"Number of 0.25 coins: {i}")

#i = 0

while s >= 0.09:
    s = s - 0.1
    i += 1

#print(f"Number of 0.1 coins: {i}")

#i = 0

while s >= 0.049:
    s = s - 0.05
    i += 1

#print(f"Number of 0.05 coins: {i}")

#i = 0

while s >= 0.009:
    s = s - 0.01
    i += 1

print(f"{i}")

