#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

class guess {
private:
    int num;
    string username;
    string securityQuestion;  
    string securityAnswer;   

public:
    guess(int n);

    void choice();
    void login();
    void registerUser();
    void forgotPassword(); 
    int getnum();
    void guesstring(); //alphabet
    void riddle();
    void section1();   //easy riddles
    void section2();   //complex number
    void section3();   //complex riddles
};

guess::guess(int n) {
    // Constructor
    num = n;
}

int guess::getnum() {
    return num;
}

void guess::login() {
	system("Color F0");
    cout << "\n\t\t\t\t-------- Login --------" << endl;
    string enteredUsername, enteredPassword;
    int count=0;

    cout << "\t\t\t Enter your username: ";
    cin >> enteredUsername;

    cout << "\t\t\t Enter your password: ";
    cin >> enteredPassword;

    ifstream input("records.txt");
    string id, pass;
    while (input >> id >> pass) {
        if (id == enteredUsername && pass == enteredPassword) {
            count = 1;
        }
    }
    input.close();

    if (count == 1) {
        choice();
    } else {
        cout << "\t\t\t Invalid username or password." << endl;
        
        // Ask the user if they want to recover the password
        cout << "\t\t\t Do you want to recover your password? (yes/no): ";
        string recoverChoice;
        cin >> recoverChoice;

        if (recoverChoice == "yes") {
            forgotPassword();
        } else {
            cout << "\t\t\t Please register first!" << endl;
            registerUser();
        }
    }
}
void guess::registerUser() {
    system("cls");
    cout << "\n\t\t\t\t-------- Registration --------" << endl;
    cout << "\t\t\t Enter a username: ";
    cin >> username;

    cout << "\t\t\t Create a password: ";
    string password;
    cin >> password;

    cout << "\t\t\t Enter a security question: ";
    cin.ignore();  // Ignore newline character left in buffer
    getline(cin, securityQuestion);

    cout << "\t\t\t Enter the answer to the security question: ";
    getline(cin, securityAnswer);

    ofstream f1("records.txt", ios::app);
    f1 << username << ' ' << password << ' ' << securityQuestion << ' ' << securityAnswer << endl;
    system("cls");
    cout << "\t\t\t Registration successful! Welcome, " << username << "!" << endl;
    choice();
}
void guess::forgotPassword() {
	 int x;
    cout << "\n\t\t\t\t-------- Forgot Password --------" << endl;

    string enteredUsername, enteredAnswer;
    bool usernameFound = false;

    cout << "\t\t\t Enter your username: ";
    cin >> enteredUsername;

    ifstream input("records.txt");
    string id, pass;
    while (input >> id >> pass) {
        if (id == enteredUsername) {
            usernameFound = true;
            break;
        }
    }
    input.close();

    if (usernameFound) {
        // If the username is found, ask the security question
        cout << "\t\t\t Security Question: " << securityQuestion << endl;
        cout << "\t\t\t Enter your answer: ";
        cin >> enteredAnswer;

        // Check if the entered answer matches the stored answer
        if (enteredAnswer == securityAnswer) {
            // Allow the user to reset the password
            cout << "\t\t\t Answer is correct. You can reset your password." << endl;
            cout << "\t\t\t Enter a new password: ";
            string newPassword;
            cin >> newPassword;

            // Update the password in the file
            ofstream output("records.txt", ios::app);
            output << id << ' ' << newPassword << endl;
            output.close();

            cout << "\t\t\t Password reset successful!" << endl;
        } else { 
            cout << "\t\t\t Incorrect answer. Cannot reset password." << endl;
        }
    } else {
        cout << "\t\t\t Username not found. Please register first!" << endl;
        registerUser();
    }
}

void guess::choice() {
	system("cls");
	system("Color F0");
	cout << "\t\t\t\t Login successful! Lets Get Started   " << username << "!" << endl;
    cout << "\t\t\t\t Instruction: Enter Space for multiple inputs.  " << endl;
    string name;
    struct Node {
        string choiceType;
        Node* next;
    };

    Node* history;
   
    int y;
    cout << "\n\t\t\t\tWELCOME!"  << " CHOOSE ONE AND START GUESSING  \t\t\t\t" << endl;
    cout << "\t\t\tENTER 1 - Puzzles , 2 - Alphabet, 3 - Number :  ";
    cin >> y;
    Node* newNode = new Node;
    newNode->choiceType = (y == 1) ? "Riddle" : ((y == 2) ? "Alphabet" : "Number");
    newNode->next = history;
    history = newNode;

    switch (y) {
        case 1: {
            riddle();
            break;
        }
        case 2: {
            guesstring();
            break;
        }
        case 3: {
            section2();
            break;
        }
        default: {
            cout << "\t\t\t\t\tOOps Error! ";
            exit(3);
        }
    }
}

void guess::section2() { // For guessing number
	system("cls");
     system("Color 70");
    int x;
    string c, u;
    cout << "\t\t\t\t\t Guess between 1-60  " << endl;
    int w, z, k, s;
    while (u != "no") {
        cout << "\t\t\t\t Enter Three Numbers that gives sum of that Number : ";
        cin >> w >> z >> k;
        s = w + z + k;
        if (s == 45) {
            system("Color A0");
            cout << "\t\t\t\t WOOHO ! You Won! ";
            system("PAUSE");
            cout << " \n\t\t\t\t LETS GO FOR ANOTHER GUESS ! " << endl;
            choice();
        } else {
            system("Color 7C");
            cout << "\t\t\t\t Try Again. " << endl;
            cout << "\t\t\t\t Enter - Yes To Continue This Number Else - NO  : ";
            cin >> u; 
        }
    } 
    system("Color 70");
    cout << "\n\n\t\t\t\t Enter y - To Solve Another Puzzle Or n - To EXIT.. : ";
    cin >> c;
  
    if ((c == "y") || (c == "Y")) {
        choice();
    } else if ((c == "n") || (c == "N")) {
        exit(3);
    } else {
        exit(3);
    }
}

void guess::riddle() { 
	system("cls");
 // puzzles
    system("Color 70");
    string r, h, c;
    int l;
    cout << "\t\t\t Enter 1 - For Easy Puzzles  2 - Complex Puzzles : ";
    cin >> l;
    switch (l) {
        case 1: {
            cout << "\t\t\t Instruction: Must give an answer either in all large or all small letters. " << endl;
            cout << "\t\t\t What goes up but never comes down? ";
            cin >> r;
            if ((r == "AGE") || (r == "age")) {
            	system("Color A0");
                cout << "\t\t\t CONGRATS ! YOU GOT IT. " << endl;
                cout << "\t\t\t Enter YES - To Guess Another Puzzle Or NO - EXIT : ";
                cin >> h;
                if ((h == "yes") || (h == "YES")) {
                    section1();
                } else if ((h == "no") || (h == "NO")) {
                        exit(3);
                    } else {
                        exit(3);
                    }
                }
             else {
             	system("Color 70");
                cout << "\t\t\t Try once more!  " << endl;
                cout << "\t\t\t What goes up but never comes down? " ;
                cin >> r;
                if ((r == "AGE") || (r == "age")) {
                	system("Color A0");
                    cout << "\t\t\t Correct! " << endl;
                    cout << "\t\t\t Lets go for another! " << endl;
                    section1();
                } else {
                	system("Color 7C");
                    cout << "\t\t\t Wrong! The answer is Age. Lets Try Another one!  " << endl;
                    system("PAUSE");
                    section1();
                }
            }
        }
        case 2: {
        	system("Color 70");
            cout << "\t\t\t Instruction: Must give an answer either in all large or all small letters. " << endl;
            cout << "\t\t\t I have keys but open no locks, I have space but no room, You can enter,\n\t\t\t but you can't go outside. What am I? ";
            cin >> r;
            if ((r == "KEYBOARD") || (r == "keyboard")) {
            	system("Color A0");
                cout << " \t\t\t CONGRATS! YOU GOT IT " << endl;
                cout << "\t\t\t Enter YES - To Go For Another Puzzle or NO - EXIT  : ";
                cin >> h;
                if ((h == "yes") || (h == "YES")) {
                    section1();
                } else if ((h == "no") || (h == "NO")) {
                        exit(3);
                    } else {
                        exit(3);
                    }
                }
             else {
             	system("Color 70");
                cout << "\t\t\t Try once more!  " << endl;
                cout << "\t\t\t I have keys but open no locks, I have space but no room, You can enter,\n\t\t\t but you can't go outside. What am I?";
                cin >> r;
                if ((r == "KEYBOARD") || (r == "keyboard")) {
                	system("Color A0");
                    cout << "\t\t\t Correct! ";
                    cout << "\t\t\t Lets go for another! " << endl;
                    section1();
                } else {
                	system("Color 7C");
                    cout << "\t\t\t OOps Wrong! The answer is Keyboard. Lets Try Another one!  " << endl;
                    section1();
                }
            }
        
        default: {
            system("Color 70");
            cout << "\t\t\t OOPs Error! " << endl;
            exit(3);
        } 
    }
 } }
void guess::section1() { // for easy riddles
	system("cls");
 system("Color 70");
string s,x;
cout << "\t\t\t Instruction: You have only two attempts for this " << endl;
while(x!="no") {
 system("Color 70");
cout << " \t\t\t It belongs to you, but other people use it more than you do. What is it? " ;
cin>>s;
if ((s=="name")|| (s== "NAME") ) {
system("Color A0");
cout << "\t\t\t Congrats! Lets Try another One! . " << endl;
section3();
}
else {
system("Color 7C");
cout << "\t\t\t OOps! Try again. " << endl;
cout << "\t\t\t If you want to keep guesing this Enter - Yes Or NO - to Stop : " ;
cin>>x;
}
}
cout << "\t\t\t Lets Try anything else!. " << endl;
system("PAUSE");
choice();
}
void guess::guesstring() { // for guessing alphabet
	system("cls");
    string u;
    string g, c;
    while (u != "no") {
        system("Color B0");

        cout << "\t\t\t Guess an alphabet  : ";
        cin >> g;
        if ((g == "e") || (g == "E") || (g == "o") || (g == "O") || (g == "y") || (g == "Y") || (g == "u") || (g == "U")) {
            system("Color A0");
            cout << "\t\t\t Congrats Genius! You Guessed it right. " << endl;
            cout << "\n\n\t\t\t Enter yes - Continue or no - exit : ";
            cin >> u;
        } else {
            system("Color BC ");
            cout << "\t\t\t OOPs! You didn't guessed! " << endl;
            cout << "\t\t\t Enter Yes - Continue, NO - To Stop : ";
            cin >> u;
        }
    }
    system("Color 70");
    cout << "\n\t\t\t Enter Y - Continue, N - EXIT : ";
    cin >> c;
    if ((c == "y") || (c == "Y")) {
        choice();
    } else if ((c == "n") || (c == "N")) {
        exit(3);
    } else {
        exit(3);
    }
}

void guess::section3() { //easy puzzles
		system("cls");
		system("Color 70");
     string s;
    cout << "\t\t\t Instruction: You have only two attempts for this " << endl;
    cout << "\t\t\t What has one head, one foot, and four legs? : ";
    cin >> s;
    system("Color 70");
    if ((s == "bed") || (s == "BED")) {
    	system("Color A0");
        cout << "\t\t\t WOOHO ! You Got It ! " << endl;
        cout << "\t\t\t Enter yes - Continue, No - Exit ";
        cin >> s;
        if ((s == "yes") || (s == "YES")) {
            choice();
        } else {
        	exit(3);
		}
    } else {
    	system("Color 70");
            cout << "\t\t\t Oops Try again. " << endl;
            cout << "\t\t\t What has one head, one foot, and four legs? " ;
            cin >> s;
            if ((s == "bed") || (s == "BED")) {
            	system("Color A0");
                cout << "\t\t\t Correct Congrats! " << endl;
                cout << "\t\t\t Lets try anything else. " << endl;
               
                choice();
            } else {
            	system("Color 7C");
                cout << "\t\t\t Wrong! The answer is bed. Try anything else! " << endl;
                system("PAUSE");
                choice();
            }
        }
}

int main() {
    int s;
    system("Color F0");
    cout << "\t\t\t\tWELCOME! To Fun-Wheel Guessing Game " << endl;

   
    guess g(0);

    
    int choice;
    cout << "\t\t\t Choose an option: 1 - Login, 2 - Register: ";
    cin >> choice;

    if (choice == 1) {
        g.login();
    } else if (choice == 2) {
        g.registerUser();
    } else {
        cout << "\t\t\t Invalid choice. Exiting..." << endl;
        exit(3);
    }

}
