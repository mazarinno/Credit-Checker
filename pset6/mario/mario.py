from cs50 import get_int
height = get_int("Height:")
while height <= 0 or height > 8:
    height = get_int("Height:")
if height == 1:
    print("#  #")
elif height == 2:
    print(" #  #")
    print("##  ##")
elif height == 3:
    print("  #  #")
    print(" ##  ##")
    print("###  ###")
elif height == 4:
    print("   #  #")
    print("  ##  ##")
    print(" ###  ###")
    print("####  ####")
elif height == 5:
    print("    #  #")
    print("   ##  ##")
    print("  ###  ###")
    print(" ####  ####")
    print("#####  #####")
elif height == 6:
    print("     #  #")
    print("    ##  ##")
    print("   ###  ###")
    print("  ####  ####")
    print(" #####  #####")
    print("######  ######")
elif height == 7:
    print("      #  #")
    print("     ##  ##")
    print("    ###  ###")
    print("   ####  ####")
    print("  #####  #####")
    print(" ######  ######")
    print("#######  #######")
elif height == 8:
    print("       #  #")
    print("      ##  ##")
    print("     ###  ###")
    print("    ####  ####")
    print("   #####  #####")
    print("  ######  ######")
    print(" #######  #######")
    print("########  ########")