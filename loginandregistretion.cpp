#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter a new username: ";
    cin >> username;

    // Check if user already exists
    ifstream checkFile("users/" + username + ".txt");
    if (checkFile) {
        cout << "Username already exists. Try a different one.\n";
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    // Save username and password in a file
    ofstream file("users/" + username + ".txt");
    file << username << endl;
    file << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Function to log in an existing user
void loginUser() {
    string username, password, storedUsername, storedPassword;

    cout << "Enter your username: ";
    cin >> username;

    // Open the user's file
    ifstream file("users/" + username + ".txt");
    if (!file) {
        cout << "User not found. Please register first.\n";
        return;
    }

    // Read stored credentials
    getline(file, storedUsername);
    getline(file, storedPassword);
    file.close();

    cout << "Enter your password: ";
    cin >> password;

    // Check password
    if (password == storedPassword) {
        cout << "Login successful! Welcome, " << username << ".\n";
    } else {
        cout << "Incorrect password. Try again.\n";
    }
}

// Main menu
int main() {
    int choice;

    // Create directory for storing user files (for Linux/macOS use mkdir, for Windows use system("mkdir users"))
    system("mkdir users >nul 2>nul");  // Works on Windows

    while (true) {
        cout << "\n=== Login & Registration System ===\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
            registerUser();
        else if (choice == 2)
            loginUser();
        else if (choice == 3) {
            cout << "Exiting program. Goodbye!\n";
            break;
        } else
            cout << "Invalid choice. Please try again.\n";
    }

    return 0;
}
