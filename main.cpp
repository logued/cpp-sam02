// sam02.cpp								January 2023
// Sample code for Lecture 1
// Demonstrates:
// Standard Input and Output
// Data Types
// Loops and Branching


// Include some standard libraries in the program
#include<stdio.h>   // Standard Input Output
#include<iostream>  // Input Output Stream
#include<string>    // string library
#include<sstream>   // String Stream library

using namespace std;	// makes the "std" namespace available throughout this file
                        // so that we don't need to repeatedly use the "std::" qualifier

//  #define PI 3.14159;	// preprocessor will replace PI with 3.14159 throughout this file
// just before it is compiled. (This was the old way to create constants)

const double PI = 3.14159;	// PI is defined as a constant - so it cannot be changed (after initialisation)

// Function Prototypes (function declarations)
// The compiler must encounter the declaration of a function before
// the function is called, so the function signatures are often placed
// at the top of the program before main()
//
void demoStandardInputAndOutput();
void demoPrimitiveTypes();
void demoSizeofOperator();
void demoLoops();
void demoBranching();

int main()
{
    cout << "sam02 - Input/Output, Data Types, Loops, Branching" << endl << endl;;

    //TODO Comment or uncomment function calls as required
    // CTRL+Click on function name to jump to its body
    demoStandardInputAndOutput();
    //demoPrimitiveTypes();
    //demoSizeofOperator();
    //demoLoops();
    //demoBranching();
}

void demoStandardInputAndOutput()
{
    //  The Stream Insertion Operator "operator<<" inserts the characters of the string
    //  on its right into the output stream called "cout".(Meaning "Console OUTput").
    //  The output stream "cout" is directed at the console (screen),
    //  so that is where you see the output displayed.

    cout << "Enter your name:";

    string name;	// note lowercase "s" for string type (unlike Java)

    cin >> name;	//  the 'operator>>' is the stream extraction operator

    //	"cin" means (Console INput)
    //	The "stream extraction operator>>" is used to extract characters
    //	from a source "cin" into a destination - the string 'name'.
    //	The "cin" stream represents the keyboard.

    cout << "Welcome " << name << endl;  // '<<' stream insertion operators can be chained together

    int i;	// declare a variable i.  Note that it is NOT initialized (unlike in Java where it is set to 0)
    cout << "The uninitialized value in i is:" << i << endl;
    cout << "Please enter an integer value:";
    cin >> i;

    //	"cin" represents the input stream of characters from the keyboard.
    //	The extraction operator "operator>>" causes the system to wait for the user to
    //	type some digits on the keyboard (making up an integer value e.g. 243).
    //	When ENTER is typed, the "operator>>" extracts the characters from the input stream,
    //	converts them into an int type, and puts that integer value in variable "i".
    //	(It expects that you will type a valid integer value.)

    cout << "The value you entered - stored in i - is:" << i << endl;
    cout << "and its double (i*2) is:" << i * 2 << endl;

    //TODO
    // What if we enter an invalid integer value? Try it. e.g. xv34, or 34xv,
    // (ANS: it will mess up the input.)

    // Using getline() to read in a line of text at a time into a string variable
    // getline() will include whitespace characters

    string strLine; // a string variable to store the line of text
    cout << "Enter your full name (firstname  surname):";
    cin.ignore(); // flushes the input buffer (as previous cin leaves RETURN ('\n') in the input buffer)

    getline(cin, strLine);	// reads the full line of text entered
    cout << "Hello " << strLine << "\n";

    double price = 0;
    int quantity = 0;
    cout << "Enter price (with decimal places): ";
    getline(cin, strLine);			// read in the price as a string.
    // we could (and should) validate the inputted price here to check that it is a valid double value


    stringstream(strLine) >> price;	// convert string to a stringstream and extract/convert to a double
    /*
        Explanation:
        1. stringstream(strLine) creates a stringstream object from the 'strLine' string.
        2. The extraction operator>> determines that it needs to extract the data
           as type double (because 'price' is of type double).
        3. ">>" extracts the value from stringstream , assuming it is a double, and assigns it to price.
        (More detail on how this works at a later point)
    */

    cout << "Enter quantity: ";
    getline(cin, strLine);
    stringstream(strLine) >> quantity;
    cout << "Total price: " << price * quantity << endl;

    // Best Practice - always use getline() to read in values,
    // then, ideally validate, and convert to the required type.
    // (Conversion is done 'automatically' for us by stringstream)

    //TODO Exercise
    // Declare two variables, width and height, of type double.
    // Input the two values as strings (str1, str2) using getline().
    // Use stringstream to extract string values into the width and height.
    // Calculate and output the area. (width * height).

}

/************************* Demo Primitive Types **********************/

void demoPrimitiveTypes()
{
    cout << "Primitive Data Types" << endl;

    char c = 'y';		// a char stores one ASCII character (always 1 byte in length in C++)
    cout << "The character in c is: " << c << endl;

    c = '\"';	// The "Escape" character \" represents a double quote
    // can we do without the backslash? Why not?

    cout << "The character in char c is: " << c << endl;

    int x = 234;		// 4-byte int, (is signed), so range is roughly -2 billion to +2 billion.
    x = -12345;			// negative integer value

    unsigned int y = 433322211u;  // positive values only; range 0->4 billion, u for unsigned value
    cout << "Value in unsigned int y = " << y << endl;;

    //TODO - try out the following
    // y = -2;	// ERROR - will NOT store what we expected - why?
    // cout << "y=-2  What does y store? y=" << y << endl;

    double d = 23.18;
    d = 1.06e-19;	    // 1.06 x 10^-19 diameter of a Hydrogen atom (very small number!)
    // i.e. move decimal point to left by 19 places = 0.000000000000000000106

    cout << "The diameter of a Hydrogen atom is d = " << d << endl;

    bool flag = true;	// true or false  (Java uses keyword 'boolean')

    cout << "The value in the flag variable flag = " << flag << endl;

    // issues of Range and Precision are relevant for floating point numbers.
}

/************************* Demo sizeof() operator *************************/

void demoSizeofOperator()
{
    cout << "The sizeof operator - sizeof(x)" << endl;

    int i = 18;
    cout << "sizeof int variable i = " << sizeof(i) << " bytes." << endl;
    cout << "sizeof type int = " << sizeof(int) << " bytes." << endl;
    printf("The value in i is : %d\n", i);  // %d is placeholder for an int (here, i)
    // printf() is a C style function.

    // An int (of size 4 bytes) can store over 4 billion different values,
    // ranging from approx: -2 billion to +2 billion (i.e. 2,147,483,647)

    i = INT_MAX;  // a constant representing the max int value (for a 4-byte int) <limits.h>

    // Variables can overflow and underflow. Can be a source of Error.
    cout << "Max int value in i = " << i << endl;
    cout << "adding one (i++) causes an overflow in this case " << endl;
    i++;
    cout << "after i++, OVERFLOW occurs, and i = " << i << endl;
    i++;
    cout << "increment i again, after i++; i = " << i << endl;

    long long int worldPopulation = LLONG_MAX;	// 19 digits !
    //TODO
    // display the size in bytes of a 'long long int'
    // Print out the value of the worldPopulation variable.

    // output the size of the 'double' data type
    cout << "sizeof(double) = " << sizeof(double) << " bytes." << endl;

    // We can use sizeof() operator to get size of compound objects - like arrays.
    // (Compound means, made up of other things) The array below is made of int values.

    // array of int values
    int arr[5] = { 1,2,3,4,5 };  // initializes a 'static' array of 5 int values

    cout << "The size of the array arr[] in bytes is: sizeof(arr) = "
         << sizeof(arr) << " i.e. 5 x 4bytes = 20" << endl;

    // we can calculate the number of elements in an array using this calculation:
    // (size of whole array in bytes) / (size of one element type in the array)

    cout << "Number of elements in this 'int' arr[] is: " << sizeof(arr) / sizeof(int) << endl;
}

/***************** Demo Loops ( for, while  ) ************************/

void demoLoops()
{
    // Demonstrating loop structures

    int n = 10;
    while (n > 0) {
        cout << n << ", ";
        --n;
    }
    cout << "liftoff!\n";

    for (int n = 10; n > 0; n--) {
        cout << n << ", ";
    }
    cout << "liftoff!\n";

    for (int n = 10; n > 0; n--) {
        cout << n << ", ";
        if (n == 3) {
            cout << "countdown aborted!";
            break;  // exit the innermost containing loop.
        }
    }
}

/***************** Demo Branching ( if, switch  ) ********************/

void demoBranching()
{
    int x = 3;
    if (x == 100) {
        cout << "x is 100" << endl;
    }
    else {
        cout << "x is not 100" << endl;
    }

    cout << "Enter a value for x (1 to 4):" << endl;
    cin >> x;
    switch (x) {
        case 1:
        case 2:         // fall through, if 1,2 or 3
        case 3:
            cout << "x is 1, 2 or 3" << endl;
            break;
        case 4:
            cout << "x is 4" << endl;
            break;
        default:
            cout << "x is not 1, 2 nor 3" << endl;
    }

    // Conditional Ternary Operator  (has an if-then-else effect
    int n = 15;
    int val = (n < 18) ? 22 : 33;  // if(n<18) then assign 22 to val, else assign 33 to val
    cout << "Val is : " << val << endl;

    string type = (n < 18) ? "Child" : "Adult";
    cout << type << endl;

}

