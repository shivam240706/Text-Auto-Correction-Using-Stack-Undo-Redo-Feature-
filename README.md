# Text-Auto-Correction-Using-Stack-Undo-Redo-Feature-
==============================

Project Description:
--------------------
This C++ project demonstrates a simple text auto-correction system with Undo and Redo functionality using stack data structures. The system allows users to append text, undo their last action, or redo an undone action — mimicking typical text editor behavior.

It showcases how the stack STL container can be effectively used to manage states of text during editing.

Features:
---------
- Add text input
- Undo the last text change
- Redo the previously undone change
- Automatically clears the redo stack when a new change is made
- Simple command-line interface

How It Works:
-------------
- Two stacks are used:
  - Undo Stack: Saves states of the text before a new change is made.
  - Redo Stack: Saves states that were undone, allowing them to be redone later.

- Whenever text is added:
  - The current text is pushed onto the undo stack.
  - The redo stack is cleared (as redo history becomes invalid).

- Undo:
  - The current state is pushed onto the redo stack.
  - The top of the undo stack becomes the current text.

- Redo:
  - The current state is pushed onto the undo stack.
  - The top of the redo stack becomes the current text.

Technologies Used:
------------------
- Language: C++
- Standard Library: stack, string, iostream

Example Usage:
--------------
Welcome to the Text Auto-Correction System!

Current Text: 
1. Add Text
2. Undo
3. Redo
4. Exit
Enter your choice: 1
Enter text to add: Hello
Text added. Current text: Hello

Enter your choice: 1
Enter text to add: World
Text added. Current text: HelloWorld

Enter your choice: 2
Undo performed. Current text: Hello

Enter your choice: 3
Redo performed. Current text: HelloWorld

File Structure:
---------------
project-folder/

|-- main.cpp            // Source code
|-- README.txt          // Project explanation and guide
|--Autocorrect.doc      // Project report
|--ss1,ss2,ss3   // Project output

How to Run:
-----------
1. Compile the code:
   g++ -o autocorrect main.cpp

2. Run the executable:
   ./autocorrect

Author:
-------
Developed by: SHIVAM SEMWAL  
Contact: shivamsemwal1999@gmail.com
