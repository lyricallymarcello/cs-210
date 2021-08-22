# snhu-cs-210 - Corner Grocer Project

This program takes a list of items purchased from a grocery store and and allows the user to make selections by reading from the file that contains the list. The user is able to count the frequency that items appear on the list, search for a particular items on the list and find that item's frequency and display a histogram made of the counted list.

# What did you do particularly well?
For this project, designing the menu and handling user input were done well. When working with input my goal is to try and break my code and then fix errors that stem to catch all cases that I may come across. Storing the contents of the file into a manageable dictionary served as the foundation for each function I created in Python. These two processes needed to be absolute correct in order for the program to function at all.

# Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
I could enhance this code by creating a function to read the file. In the python code I do this process 3 times. As code is the same in each of the three functions, I could have placed it in its own function to allow for more reusability. This would allow for increased readability and less lines to code to acheive the same result.

# Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
The most challenging piece of the code to write for this project would be reading from the file and writing the sorted contents to a new list. My intial attempts were attempting to output the keys and values of the python dictionary to the file the same way that they are printed. This caused my newly created file to be blank. I utilized the https://www.w3schools.com/ python guide for dictionaries and file handling to help solve this dilema. To manipulate the output to the file I had to cast the keys and values of the dictionary as strings in the output statement. As I had not working with python for some time prior to this project I needed to review some of the basics and some of my previous python code. 

# What skills from this project will be particularly transferable to other projects or course work?
The skills that will be particularly transferable would be integrating C++ and Python together. I had not had a chance, prior to this project, to working with multiple programming languages simultaneously. However, once set up, the process and workflow of using C++ and Python in Visual Studio Code felt very natural. 

# How did you make this program maintainable, readable, and adaptable?
This entire program is organized in simple functions. In order keep to code readable I decided this would be best. If I decide to expand the functionality of this program the foundations are solid and will allow for scalabilty for things like separating fruits from vegtables or working multiple input files or bigger list.

