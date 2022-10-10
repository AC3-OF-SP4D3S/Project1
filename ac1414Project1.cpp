/* Authors: ac1414  - Abhijeet Chahande (abhijeetchahande@my.unt.edu)
 *          ame0205 - Amanda English (amandaenglish3@my.unt.edu)
 *          etp0040 - Eric Parker (ericparker3@my.unt.edu)
 * Date: 2022-10-09
 * Instructor: Dr. Pradhumna Shrestha
 * Description: Recieves input from user for the size of the shape ("length"). The program enters a do-while loop once "length"
 *              is entered. The user is then asked what shape they would like to create. The user's options are enumerated
 *              variables ("Square", "Triangle", "Pentagon", "Sentence", and "Quit") of the data type "Shape". The shape is
 *              created and user is asked if they want to continue. If yes, the do-while loop will continue. If no, the do-while
 *              loop will terminate and the program will exit, displaying an exit message.
 */

#include <iostream>
#include <unistd.h>
#include <cctype>
#include <string>

using namespace std;

int main(){
    enum Shape {Square=1, Triangle=2, Pentagon=3, Sentence=4, Quit=5};
    int length; // Length of shape
    int numLineSq, numRowSq, numColSq;       // Line, row, and column variables for Square
    int numLineTri, numRowTri, numColTri;    // Line, row, and column variables for Triangle
    int numLinePenA, numRowPenA, numColPenA; // Line, row, and column variables for Pentagon (top)
    int numLinePenB, numColPenB;             // Line and column variables for Pentagon (bot)
    int numLineSen, numRowSen, numColSen;    // Line, row, and column variables for Sentence
    int signInt; // Integer value for symbol
    char signChar; // Character value for symbol
    Shape choice;
    int userChoice;
    string usr_sentence;
    bool continueOn = true;
    char next;
    
    // Asks user for a length
    system("clear");
    cout << "Welcome to 'Create a Shape'!\n";
    cout << "Please enter an odd number: ";
    cin >> length;
    
    // If number is even, the loop will continue asking for an odd number until one is entered.
    while ((length % 2) == 0){
        system("clear");
        cout << "That is not an odd number.\n";
        cout << "Please enter an odd number: ";
        cin >> length;
    }
    
    system("clear");
    
    do{
        /* Function: Do-while loop
         * Parameters: Looop will exit when boolean variable "continueOn" is false.
         * Return: A shape with size of "length", or removes all digits from a sentence
         * Description: This function either generates a shape (square, triangle, or pentagon) based on length, or if a sentence
         *              is entered, all the digits within the sentence are progressively removed until a sentence without digits
         *              is displayed. If "Ouit" is choosen, then the program will exit.
         */
        cout << "What shape would you like to create with a length of " << length << "?\n";
        cout << "\n";
        cout << "(1) Square\n";
        cout << "(2) Triangle\n";
        cout << "(3) Pentagon\n";
        cout << "(4) Sentence\n";
        cout << "(5) Quit\n";
        cout << "\n";
        cout << "Choose an option: ";
        cin >> userChoice;
        choice = static_cast<Shape>(userChoice); // Changes "userChoice" to a Shape type variable and inputs into "choice"
        
        // Seeded random number 33 to 64 inclusive
        srand(time(0));
        signInt = (rand() % 32) + 33;
        signChar = static_cast<char>(signInt);
        
        // Switch statement that evaluates case based on enumerated variable
        switch (choice){
            case Square: // Generate a Square
                for(numLineSq = 0; numLineSq < length; numLineSq++){ // For each line, the screen clears
                    system("clear");
                    for(numRowSq = 0; numRowSq <= numLineSq; numRowSq++){ // For each line, there is a row of the same width
                        for(numColSq = 0; numColSq <= numLineSq; numColSq++){ // For each row, there is a symbol in each column
                            cout << signChar;
                        }
                        cout << endl;
                    }
                    sleep(1);
                }
                do{ // After printing a square, does the user want to continue?
                    cout << "\nWould you like to continue? (Y/N): ";
                    cin >> next;
                    next = toupper(next);
                    if(next == 'Y'){
                        continueOn = true;
                    }
                    else if(next == 'N'){
                        continueOn = false;
                    }
                    system("clear");
                }while(next!='Y'&&next!='N');
                break;
            case Triangle: // Generate a Triangle
                system("clear");
                for(numLineTri = 1; numLineTri <= length; numLineTri++){ // Repeats until number of lines equals length
                    for(numRowTri = 0; numRowTri < length-numLineTri; numRowTri++){ // There is "length"-1 spaces
                        cout << " ";
                    }
                    for(numColTri = 0; numColTri < ((2*numLineTri)-1); numColTri++){ // There is an odd number of symbols
                        cout << signChar;
                    }
                    cout << endl;
                    sleep(1);
                }
                do{ // After printing a triangle, does the user want to continue?
                    cout << "\nWould you like to continue? (Y/N): ";
                    cin >> next;
                    next = toupper(next);
                    if(next == 'Y'){
                        continueOn = true;
                    }
                    else if(next == 'N'){
                        continueOn = false;
                    }
                    system("clear");
                }while(next!='Y'&&next!='N');
                break;
            case Pentagon: // Generate a Pentagon
                system("clear");
                for(numLinePenA = 1; numLinePenA <= length; numLinePenA++){ // Top half of pentagon is same as triangle
                    for(numRowPenA = 0; numRowPenA < length-numLinePenA; numRowPenA++){
                        cout << " ";
                    }
                    for(numColPenA = 0; numColPenA < ((2*numLinePenA)-1); numColPenA++){
                        cout << signChar;
                    }
                    cout << endl;
                    sleep(1);
                }
                for(numLinePenB = 1; numLinePenB < length; numLinePenB++){ // Bottom half of pentagon is same as square
                    for(numColPenB = 0; numColPenB < ((length*2)-1) ; numColPenB++){
                        cout << signChar;
                    }
                    cout << endl;
                    sleep(1);
                }
                do{ // After printing a pentagon, does the user want to continue?
                    cout << "\nWould you like to continue? (Y/N): ";
                    cin >> next;
                    next = toupper(next);
                    if(next == 'Y'){
                        continueOn = true;
                    }
                    else if(next == 'N'){
                        continueOn = false;
                    }
                    system("clear");
                }while(next!='Y'&&next!='N');
                break;
            case Sentence: // Sentence for animation
                system ("clear");
                cout << "Enter a sentence: "; // Prompt user input
                cin.ignore(); // Allow for input to be read
                getline(cin,usr_sentence);
                system ("clear");
                numLineSen = 0;
                cout << usr_sentence << endl;
                for (numColSen = 0; numColSen < usr_sentence.size(); numColSen++){ // For every element of users input
                    if (isdigit(usr_sentence.at(numColSen))){ // This loop finds each digit in the string deletes it
                        usr_sentence.erase(numColSen,1);
                        sleep(1);
                        system("clear");
                        numColSen--;
                        numLineSen++;
                        for (numRowSen = 1; numRowSen <= (numLineSen); numRowSen++){
                            cout << endl;
                        }
                        cout << usr_sentence << endl;
                    }
                }
                do{ // After removing all digits from a string, does the user want to continue?
                    cout << "\nWould you like to continue? (Y/N): ";
                    cin >> next;
                    next = toupper(next);
                    if(next == 'Y'){
                        continueOn = true;
                    }
                    else if(next == 'N'){
                        continueOn = false;
                    }
                    system("clear");
                }while(next!='Y'&&next!='N');
                break;
            case Quit: // Does the user want to continue? If not, program ends
                do{
                    system("clear");
                    cout << "Are you sure you would like to quit the program? (Y/N): ";
                    cin >> next;
                    next = toupper(next);
                    if(next == 'Y'){
                        continueOn = false;
                        system("clear");
                    }
                    else if(next == 'N'){
                        continueOn = true;
                        system("clear");
                    }
                }while(next!='Y'&&next!='N');
                break;
            default: // Error message
                cout << "\nInvalid input. Please enter a valid input.\n\n";
                continueOn = true;
                break;
        }
    }while(continueOn == true);
    
    for (int i = 0; i <=4; i++){ // Goodbye message
        if(i==0){
            cout << "Closing 'Create a Shape'";
        }
        else if (i==1||i==2||i==3){
            cout << " .";
        }
        else if (i==4){
            cout << " Goodbye!\n";
        }
        cout.flush();
        sleep(1);
    }

    return 0;
}
