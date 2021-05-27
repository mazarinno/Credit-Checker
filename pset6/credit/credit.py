from cs50 import get_int
import math

# Input
credit = get_int("Insert credit card number:\n")

# Length Checker
creditlength = 1 + math.log10(credit)

# Beginning number checker
creditstartchecker = credit
while creditstartchecker >= 10:
    creditstartchecker = int(creditstartchecker / 10)

# Second number checker, necessary for AMEX and MC
secondnumber = credit
counttwo = 0

# This is an int acting as a bool for final output
invalid = 0

# Checking for AMEX numbers
if int(creditlength) == 15 and creditstartchecker == 3:
    while secondnumber > 100:
        counttwo = int(counttwo + 1)
        digittwo = secondnumber % 10
        secondnumber = secondnumber / 10
    if int(secondnumber) == 34 or int(secondnumber) == 37:
        invalid = 0
    else:
        invalid = 1

# Checking for MC numbers
if int(creditlength) == 16 and creditstartchecker == 5:
    while secondnumber > 100:
        counttwo = int(counttwo + 1)
        digittwo = secondnumber % 10
        secondnumber = secondnumber / 10
    if int(secondnumber) < 51 or int(secondnumber) > 55:
        invalid = 1

# Checksum formulas
Sum = 0
sumtwo = 0
count = 0
while credit > 0:
    count = int(count + 1)
    digit = int(credit % 10)
    # Numbers which must be multiplied by 2
    if count % 2 == 0:
        if 2 * digit < 10:
            Sum = Sum + int(2 * digit)
        # Next line checks to see if product must be broken down, i.e. 12 into 1 and 2
        elif int(2 * digit) >= 10:
            result = 0
            result = int(2 * digit % 10) + int(2 * digit / 10)
            Sum = Sum + result
    # The other numbers which must only be added
    if count % 2 == 1:
        sumtwo = sumtwo + digit
    credit = credit / 10

# Adding the two together. Modulo for checksum is checked in final output
checksum = 0
checksum = Sum + sumtwo

# Final outputs
if checksum % 10 == 0 and int(creditlength) == 15 and int(secondnumber) == 34:
    print("AMEX\n")

if checksum % 10 == 0 and int(creditlength) == 15 and int(secondnumber) == 37:
    print("AMEX\n")

if checksum % 10 == 0 and int(creditlength) == 13 and creditstartchecker == 4:
    print("VISA\n")

if checksum % 10 == 0 and int(secondnumber) == 51 and int(creditlength) == 16:
    print("MASTERCARD\n")

if checksum % 10 == 0 and int(secondnumber) == 52 and int(creditlength) == 16:
    print("MASTERCARD\n")

if checksum % 10 == 0 and int(secondnumber) == 53 and int(creditlength) == 16:
    print("MASTERCARD\n")

if checksum % 10 == 0 and int(secondnumber) == 54 and int(creditlength) == 16:
    print("MASTERCARD\n")


if checksum % 10 == 0 and int(secondnumber) == 55 and int(creditlength) == 16:
    print("MASTERCARD\n")

if checksum % 10 == 0 and creditstartchecker == 4 and int(creditlength) == 16:
    print("VISA\n")

if checksum % 10 is not 0 or invalid == 1 or int(creditlength) == 10:
    print("INVALID\n")