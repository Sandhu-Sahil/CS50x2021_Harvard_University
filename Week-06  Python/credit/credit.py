# To check wether the bank card is valid or not.
from sys import exit

o = input("Card Numnber: ")

#
if len(o) != 13 and len(o) != 15 and len(o) != 16:
    exit("INVALID")

#
o = list(o)

#
if len(o) == 16:
    for i in range(0, len(o), 2):
        (o[i]) = str(int(o[i]) * 2)
        if int(o[i]) > 9:
            p = list(map(int, o[i]))
            o[i] = str(sum(list(p)))

#
if len(o) == 13 or len(o) == 15:
    for i in range(1, len(o), 2):
        (o[i]) = str(int(o[i]) * 2)
        if int(o[i]) > 9:
            p = list(map(int, o[i]))
            o[i] = str(sum(list(p)))

#
s = sum(list(map(int, o))) % 10

#
if s == 0:
    if len(o) == 15:
        print("AMEX")
    else:
        if o[0] == '8':
            print("VISA")
        else:
            print("MASTERCARD")
else:
    print("INVALID")