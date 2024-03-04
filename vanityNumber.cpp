/*
 Jacob St Lawrence
 This program prompts the user to provide the word or phrase they would like as their phone
 number. It then calculates the corresponding phone number digits and outputs it in
 xxx-xxxx format.
*/

//include statements
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

//declare variables and function prototype
int converterSwitch(char);
char letter;
int num[7];
bool done = false;


int main()  //start main
{
    //prompt user for input
    cout << "Please enter word or phrase to be converted to telephone number: " << endl;
    
    do  //create loop that will iterate for as many numbers as the user would like
    {
        int count = 0;  //initialize count for for loop
    
        while (count < 7)   //start loop that will iterate until 7 numbers are generated
        {
            cin.get(letter);    //get next character from user's input
            
            if (isalpha(letter))    //determine if the character is a letter
            {
                letter = tolower(letter);   //make sure letter is lower case
                
                if (converterSwitch(letter) != 0)   //call function to change it to a number
                {
                    //if good number is produced, assign it to next index in num array
                    num[count] = converterSwitch(letter);
                    count += 1; //move to next character
                }
                
                else
                    //if converter fails (produces a zero), disregard and move on
                    continue;
            }
            
            else if (isnumber(letter))  //determine if the character is already a number
            {
                num[count] = letter - '0';  //assign matching integer to next array index
                count += 1; //move to next character
            }
            
            else if (letter == '\n')    //catch if less than 7 characters were entered
            {
                //display error message to receive new input, restart loop from beginning
                cout << "Please enter at least seven characters: " << endl;
                count = 0;
                continue;
            }
            
            else
            {
                //if character is a space or special character, ignore it and move on
                cin.putback(letter);
                cin.ignore();
                continue;
            }
            
        }
        
        cout << "Your number will be: ";
        
        //create loop to output results
        for (int i = 0; i < 7; i++)
        {
            cout << num[i];
            //after third digit, output a '-'
            if (i == 2)
                cout << '-';
        }
    
        cout << endl;
        //after output, allow user to input for another number, or give option to exit
        cout << "Please enter another phrase to convert, or press ENTER to exit: " << endl;
        cin.ignore(100, '\n');  //advance to new line of input
        
        //check whether the input was a new line, and end loop if it is
        if (cin.peek() == '\n')
            done = true;
    }
    
    while (!done);
    
    return 0;
}

//define function for converting lowercase letters to numbers on telephone
int converterSwitch(char ch)
{
    int num;
    
    //create switch to match up letter with corresponding number
    switch (ch)
    {
        case 'a': case 'b': case 'c':
            num = 2;
            break;
            
        case 'd': case 'e': case 'f':
            num = 3;
            break;
            
        case 'g': case 'h': case 'i':
            num = 4;
            break;
            
        case 'j': case 'k': case 'l':
            num = 5;
            break;
            
        case 'm': case 'n': case 'o':
            num = 6;
            break;
            
        case 'p': case 'q': case 'r': case 's':
            num = 7;
            break;
            
        case 't': case 'u': case 'v':
            num = 8;
            break;
            
        case 'w': case 'x': case 'y': case 'z':
            num = 9;
            break;
            
        default:    //if it fails to produce a number, return a zero to indicate failure
            num = 0;
    }
    return num; //return value determined by function
}

