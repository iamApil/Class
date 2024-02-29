#include <iostream>

using namespace std;

//Rectangle class to demonstrate the working of Constructor and Destructor in CPP
class Rectangle {
    public:
        float length, breadth;

    //Declaration of the default Constructor of the Rectangle Class
    public:
        Rectangle() {
            cout << "\n\n****** Inside the Constructor ******* \n\n";
            length = 2;
            breadth = 4;
        }

    //Declaration of the Destructor of the Rectangle Class
    public:
        ~Rectangle() {
            cout << "\n\n****** Inside the Destructor ******* \n\n";
        }
};

//Defining the main method to access the members of the class
int main() {

    cout << "\n\nWelcome to Studytonight :-)\n\n\n";
    cout << " =====  Program to demonstrate the concept of Constructor and Destructor in CPP  ===== \n\n";

    cout << "\nCalling the default Constructor of the Rectangle class to initialize the object.\n\n";

    //Declaring the Class object to access the class members
    Rectangle rect;

    cout << "\nThe Length of the Rectangle set by the Constructor is = " << rect.length << "\n\n";

    cout << "\nThe Breadth of the Rectangle set by the Constructor is = " << rect.breadth << "\n\n";

    return 0;
}	