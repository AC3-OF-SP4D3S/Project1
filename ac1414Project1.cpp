/* Authors: ac1414
 *          ame0205 - Amanda English (amandaenglish3@my.unt.edu)
 *          etp0040
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

int main() {
    enum Shape {Square=1, Triangle=2, Pentagon=3, Sentence=4, Quit=5};
    int length;
    int lineNum;
    int i, l;
    int signInt;
    char signChar;
    Shape choice;
    int userChoice;
    bool continueOn = true;
    char next;
	o
    
    system("clear");
    cout << "Welcome to 'Create a Shape'!\n";
    cout << "Please enter an odd number: ";
    cin >> length;
    
    while ((length % 2) == 0){ // If number is even, the loop will continue asking for an odd number until one is entered.
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
        choice = static_cast<Shape>(userChoice); // changes "userChoice" to a Shape type variable and inputs into "choice"
        
        // seeded random number 33 to 64 inclusive
        srand(time(0));
        signInt = (rand() % 32) + 33;
        signChar = signInt;
        
        // Switch statement that evaluates case based on enumerated variable
        switch (choice){
            case Square: // Generate a Square
                for(int numLineSq = 0; numLineSq < length; numLineSq++){
                    system("clear");
                    for(int numRowSq = 0; numRowSq <= numLineSq; numRowSq++){ 
                        for(int numColSq = 0; numColSq <= numLineSq; numColSq++){
                            cout << signChar;
                        }
                        cout << endl;
                    }
                    sleep(1); // delay
                }
                do{
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
                for(int numLineTri = 1; numLineTri <= length; numLineTri++){
                    for(int numRowTri = 0; numRowTri < length-numLineTri; numRowTri++){
                        cout << " ";
                    }
                    for(int numColTri = 0; numColTri < ((2*numLineTri)-1); numColTri++){
                        cout << signChar;
                    }
                    cout << endl;
                    sleep(1); // delay
                }
                do{
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
                for(int numLinePenTri = 1; numLinePenTri <= length; numLinePenTri++){
                    for(int numRowPenTri = 0; numRowPenTri < length-numLinePenTri; numRowPenTri++){
                        cout << " ";
                    }
                    for(int numColPenTri = 0; numColPenTri < ((2*numLinePenTri)-1); numColPenTri++){
                        cout << signChar;
                    }
                    cout << endl;
                    sleep(1); // delay
                }
                for(int numLinePenSq = 1; numLinePenSq < length; numLinePenSq++){
                    for(int numColPenSq = 0; numColPenSq < ((length*2)-1) ; numColPenSq++){
                        cout << signChar;
                    }
                    cout << endl;
                    sleep(1); // delay
                }
                do{
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
                cout << "Enter a sentence:" << endl; // Prompt user input
		cin.ignore(); // allow for input to be read
		getline(cin,usr_sentence);
                system ("clear"); // clearing screen
                // main loop    
                lineNum = 0;
            	for (i = 0; i < usr_sentence.size(); i++) // for every element of users input
            	{                                         //this loop finds the minimum value in string 
			if (isdigit(usr_sentence.at(i))) 
                	{
                    		usr_sentence.erase(i,1);
                    		sleep(1);
                    		system("clear");
                    		i--;
                    		lineNum ++;
                    		for (l = 0; l < lineNum - 1; l++)
                    		{
                        		cout << endl;
                    		}

                    		cout << usr_sentence << endl;
			}
            	}

            
                do{
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
            case Quit: // Ask user to continue program. If not, end program
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
    
    cout << "Closing 'Create a Shape' . . . Goodbye!\n";
    
    return 0;
}
