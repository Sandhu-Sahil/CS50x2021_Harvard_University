# To check weather a written paragraph is for which grade student

o = input("TEXT...: ")

a = o.count(" ") + 1  # Total words

b = o.count(".") + o.count("!") + o.count("?")  # Total number of sentences

s = b / a * 100  # average number of sentences per 100 words

#
c = 0
for i in range(len(o)):
    if o[i].isalnum():
        c += 1

#
l = c / a * 100

#
index = 0.0588 * l - 0.296 * s - 15.8

#
if index < 1:
    print("Before Grade 1")
elif index > 16:
    print("Grade 16+")
else:
    print(f"Grade {round(index)}")