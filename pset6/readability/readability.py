from cs50 import get_string
# input
text = get_string("Insert text here:\n")

placeholder = len(text)
letters = 0
words = 1
sentences = 0
# for loop for finding letters, words, and sentences
i = 0
while i < placeholder:
    # tried doing this by using restrictions based on the ASCII code. ended up finding isalpha after that didn't work
    if text[i].isalpha():
        letters = letters + 1
    
    # sentences based on number of exclamation points, periods, and question marks
    if ord(text[i]) == 33 or ord(text[i]) == 63 or ord(text[i]) == 46:
        sentences = sentences + 1
    
    # words based on amnt of spaces. the int words starts at 1 to account for the first word of every sentence, which doesn't follow a space
    if ord(text[i]) == 32:
        words = words + 1
    i = i + 1

# grading function
index = 0

index = index + (0.0588 * ((letters * 100) / words) - 0.296 * ((sentences * 100) / words) - 15.8)

index = round(index)

if (index > 16):
    print("Grade 16+\n")
if (index < 1):
    print("Before Grade 1\n")
if index > 1 and index < 17:
    print("Grade", index)