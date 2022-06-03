import csv
import sys


def main():

    if len(sys.argv) != 3:
        sys.exit("Usage: python dna.py STRcounts DNASequence")

check = True
STRlist = []
Humanlist = []
# copy person list
with open(sys.argv[1], "r") as STR:
    readSTR = csv.reader(STR)
    for row in readSTR:
        if check:
            STRlist.append(row)
            check = False
        else:
            Humanlist.append(row)
Slist = STRlist[0]
Slist.remove("name")
# print(Humanlist)
# print(Slist)
seq = []
# copy sequence
with open(sys.argv[2], "r") as text:
    readtext = csv.reader(text)
    for i in readtext:
        seq = i
text = seq[0]
# print(text)
# create dictionary for STR

STRdict = {}
"""
for STR in Slist:
    STRdict[STR] = 0"""
for STR in Slist:
    idx = 0
    max_ = 0
    while idx < len(text):
        num_repeats = 0
        while STR == text[idx:idx+len(STR)]:
            num_repeats += 1
            idx += len(STR)
        if num_repeats > max_:
            max_ = num_repeats

        idx += 1
    STRdict[STR] = max_
    #print(STR, max_)

    """for letter in range(len(text)):
        if STR == text[letter:letter+len(STR)]:
            STRdict[STR] += 1"""
check = False
for human in range(len(Humanlist)):
    for STR in range(len(Slist)):
        if str(STRdict[Slist[STR]]) == str(Humanlist[human][STR+1]):
            check = True
        else:
            check = False
            break
    if check:
        print(Humanlist[human][0])
        break
if not check:
    print("no match")


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
