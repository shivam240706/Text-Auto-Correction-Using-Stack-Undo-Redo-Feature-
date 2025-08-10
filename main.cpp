#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Undo operation
void undo(stack<string> &undoStack, stack<string> &redoStack, string &currentText) {
    if (undoStack.empty()) {
        cout << "Nothing to undo.\n";
        return;
    }
    redoStack.push(currentText); // Save the current text to the redo stack

    currentText = undoStack.top(); // Retrieve the last saved state from the undo stack

    undoStack.pop(); // Remove the restored state from the undo stack

    cout << "Undo performed. Current text: " << currentText << endl;
}

// Redo operation
void redo(stack<string> &undoStack, stack<string> &redoStack, string &currentText) {
    if (redoStack.empty()) {
        cout << "Nothing to redo.\n";
        return;
    }
    undoStack.push(currentText); // Save the current text to the undo stack

    currentText = redoStack.top(); // Retrieve the next saved state from the redo stack

    redoStack.pop(); // Remove the restored state from the redo stack

    cout << "Redo performed. Current text: " << currentText << endl;
}


int main() {
    stack<string> undoStack, redoStack; // Stacks to store undo and redo states

    string currentText = "";           // Holds the current text being edited

    string input;                      // Temporary variable to store user input

    int choice;                        // Variable to store the user's menu choice


    cout << "Welcome to the Text Auto-Correction System!\n";

    while (true) {
        // Display the current text and menu options
        cout << "\nCurrent Text: " << currentText << endl;
        cout << "1. Add Text\n";
        cout << "2. Undo\n";
        cout << "3. Redo\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); // Clear the newline character from the input

        switch (choice) {
            case 1: // Add new text to the current text
                cout << "Enter text to add: ";
                getline(cin, input);
                undoStack.push(currentText); // Save the current state before modifying

                currentText += input;       // Append the new text to the current text
                
                while (!redoStack.empty()) redoStack.pop(); // Clear the redo stack after a new change
                cout << "Text added. Current text: " << currentText << endl;
                break;

            case 2: // Undo the last change made to the text
                undo(undoStack, redoStack, currentText);
                break;

            case 3: // Redo the last undone change
                redo(undoStack, redoStack, currentText);
                break;

            case 4: // Exit the program
                cout << "Thank you for using the Text Auto-Correction System. Goodbye!\n";
                return 0;

            default: // Handle invalid menu choices
                cout << "Invalid choice. Please try again.\n";
        }
    }
}
