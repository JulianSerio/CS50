import cs50

while True:
    height = cs50.get_int('Height: ')
    if height > 0 and height < 9:
        break
    else:
        print("Error!")

for row in range(height):
    for space in range(height - row - 1, 0, -1):
        print(" ", end="")
    for hash in range(row + 1):
        print("#", end="")
    print("\n", end="")