import re
import string


def ItemFrequency():
    # Open and Read From File
    f = open("P3_Input_File.txt", "r")
    # Create New Dictionary to Store Each Word of the File
    file_dict = dict()
    # For Loop to Iterate Through Each Line of the File
    for line in f:
        # Ends Each Word at the Newline Char
        line = line.split()
        # For Loop to Count the Number of Times a Word Repeats to Store in Dictionary
        for word in line:
            if word in file_dict:
                file_dict[word] = file_dict[word] + 1
            else:
                file_dict[word] = 1
    # Closes the File
    f.close()
    # For Loop to Print List Followed by Newline
    for key in file_dict.keys():
        print(key, file_dict[key])
    print()
   

def SpecificItemFrequency(searchWord):
    # Open and Read From File
    f = open("P3_Input_File.txt", "r")
    # Create New Dictionary to Store Each Word of the File
    file_dict = dict()
    # For Loop to Iterate Through Each Line of the File
    for line in f:
        # Ends Each Word at the Newline Char
        line = line.split()
        # For Loop to Count the Number of Times a Word Repeats to Store in Dictionary
        for word in line:
            if word in file_dict:
                file_dict[word] = file_dict[word] + 1
            else:
                file_dict[word] = 1
    # Closes the File
    f.close()

    # If Statement to Search for Word in Dictionary
    if searchWord in file_dict.keys():
        # If Word if Found Print the Word and Frequency
        print(searchWord, file_dict[searchWord])
    else:
        # If Word is not Found then Error is Printed
        print("That word was not found.")
    print()

    return 0

def CreateHistogramFile():
    # Open and Read From File
    f = open("P3_Input_File.txt", "r")
    # Create New Dictionary to Store Each Word of the File
    file_dict = dict()
    # For Loop to Iterate Through Each Line of the File
    for line in f:
        # Ends Each Word at the Newline Char
        line = line.split()
        # For Loop to Count the Number of Times a Word Repeats to Store in Dictionary
        for word in line:
            if word in file_dict:
                file_dict[word] = file_dict[word] + 1
            else:
                file_dict[word] = 1
    # Closes the File
    f.close()

    # Create New File to Write to
    with open("frequency.dat", "w") as f:
        for k, v in file_dict.items():
            f.write(str(k) + " " + str(v) + "\n")
