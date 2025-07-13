1.Overview:
This package provides a Trie data structure implementation that supports operations such as inserting strings, building a suffix trie, finding the longest common substring between two strings, and searching for patterns within a given text. The package is implemented in C++ and is ideal for various string manipulation and search tasks.
2.Installation:
To use this package, you need to have a C++ compiler installed on your system. Once you opened the code on the compiler you should face no problems with running the code
3.Usage:
you can run the executable to see the trie in action. The main.cpp file demonstrates the primary functionality of the Trie class.
3.1- Longest Common Substring:
	Two strings s1 and s2 are entered by the user.
for example :sequence 1 = "SBIGJKMMIXBAOSIUDABSKJ";
             sequence 2 = "ASHDVJASOCASBIGJKMMKHJASUDSJHG";
	The longestCommonSubstring function of the Trie class is called with s1 and s2 as 	arguments with the usage of insertsuffix function. 
	The function constructs a suffix trie from both strings and then finds the LCS using a 	recursive approach.
	The result is printed to the console.
3.2- Pattern Matching:
	DNA or Protein Sequence and a pattern string are entered by the user.
for example : Sequence = "TAGCTAC";
              Pattern = "AGC"; 
	The buildTree function is called to construct a trie from the main sequence and with insert function also.
	The patternsearch function is called with the pattern string as an argument.
	This function searches the trie for the pattern and returns true if found, false otherwise.
	The result is printed to the console.
4.Running a Demo:
The demo performs the following operations:

4.1- Builds a suffix trie for two strings and finds the longest common substring.
4.2- Builds a suffix trie for a given text and searches for a specified pattern.
The provided code includes a demo that showcases both functionalities. You can compile and run the main code to see the output.