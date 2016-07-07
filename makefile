###############################################################
# Program:
#     Week 08, Binary Tree
#     Brother JonesL, CS235
# Author:
#     Tiffany Gohnert John Vehikite
# Summary:
#     Create a class similar to a Binary Tree.
# Time:
#     15+ hours
# Most difficult part:
#     The second portion of the assignment - Huffman Codes -
#     was extremely difficult.
###############################################################

##############################################################
# The main rule
##############################################################
a.out: week08.o huffman.o 
	g++ -o a.out week08.o huffman.o -g
	tar -cf week08.tar *.h *.cpp makefile

##############################################################
# The individual components
#      week08.o     : the driver program
#      huffman.o      : the logic for the huffman code program
##############################################################
week08.o: bnode.h huffman.h week08.cpp
	g++ -c week08.cpp -g

huffman.o: bnode.h huffman.h huffman.cpp
	g++ -c huffman.cpp -g

