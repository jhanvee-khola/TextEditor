# TextEditor

Text Editor application build based on the Data Structure Stack and Object Oriented Programming in C++.
(Currently Incomplete🙈)

## Problem Statement
A text editor is a program that allows the user to open, view, and edit plain text files (files containing only text). 
Text editors deal with manipulating text and provide features to enhance the experience. As mentioned before, the major functionalities of text editors are: inserting, deleting, and viewing text. Additional features that are practically required to even compete with other text editors are:find and replace, copy/cut and paste, text formatting, sentence highlighting, and etc.

## Algorithm
### Two Stack Model
This approach is most likely only found in programming assignments rather than actual implementation, but it is good practice using stacks. The idea is to use two stacks to maintain the current cursor position. Left stack would contain the contents to the left of the cursor and the right stack would contain the contents to the right cursor. You would just push or pop the elements to get to where you need and either insert or delete text.

We used the cursor position as ‘divider’ and maintained two stacks to hold characters on either side. All characters to the left of the cursor are pushed on the ‘left’ stack All characters to its right are pushed on the ‘right’ stack.
Use 2 stacks to depict the text editor

