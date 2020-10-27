Welcome to my family tree program!
Name:Craig Scarboro

-----DESCRIPTION-----
This program takes a .txt file with input commands of the format 

Insert n Parent n Marriage n
Family n Husband n Wife n Child n Child n ...
Check
Relate n n

where n is an integer from 0-99 and 0 indicates the absense of an individual.
The insert command inserts an individual with a parent and marriage family.
The family command inserts a family with a husband, wife, and up to 10 children.
Check makes sure that the data is consistent from individual to family.
Relate is supposed to find the shortest path between two unique individuals. Currently the function is incomplete,
but once complete would utilize a queue to implement Breadth First Search (BFS). 

-----TO RUN THE PROGRAM-----
Type "make" to compile the program. Then type ./project4 in order to start it up. 

Typing "make clean" will clean up the object files generated during coimpilation.

-----USING THE PROGRAM-----
The program will ask for a text file (including the .txt extension) receive data from this file and insert
into the graph data structure. With every data insert the program will output what has been inserted.