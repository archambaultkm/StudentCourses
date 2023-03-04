#include <iostream>
#include "../inc/courses.h"

int main() {

    while (true) {
        string input;
        int numCourses;
        bool stillAdding;

        //ask for the first student's input and courses, looping until the student is finished.
        cout << "\nPROGRAM START" << endl;
        cout << "\nEnter the first student's name: " << endl;
        getline(cin, input);

        Student student1;
        student1.setName(input);

        numCourses = 0;
        stillAdding = true;

        while(stillAdding) {

            numCourses ++; //just used to keep track of number for following prompt:
            cout<< "Enter a title for course " << numCourses << " (or q to quit): " << endl;

            cin.clear(); //get rid of potential error flags that would prevent cin from working
            cin >> ws; //absorb whitespace characters and clear prev. line from cin
            getline(cin, input);

            if (input == "q" || input == "Q") {
                //quit the loop
                stillAdding = false;
            } else {
                //the addcourse method will also take care of incrementing the student's numcourses property
                student1.addCourse(input);
            }
        }

        //Display the first student's input, number of courses in their list and their list of courses.
        cout << "\nStudent 1: " << student1.getName() << endl;
        student1.printStudentCourses();

        //Asl for the input of a second student
        cout << "\nEnter the second student's name: " << endl;
        getline(cin, input);

        Student student2 = student1; //copy the first student
        student2.setName(input);

        //and display this new student after copying the 1st student's course information and writing in the new input
        cout <<"\nStudent 2: " << student2.getName() << endl;
        student2.printStudentCourses();

        //Display the 1st student’s name, the number of courses in their list of courses after executing a function
        //that resets the number of courses to 0 and the courseList array to an empty list
        cout << "\nStudent 1 after reset: " << student1.getName() << endl;
        student1.resetCourses();
        student1.printStudentCourses();

        //Display the 2nd student’s name, number of courses in their list and their list of courses (to demonstrate
        //that a deep copy took place).
        cout << "\nStudent 2 to prove deep copy: " << student2.getName() << endl;
        student2.printStudentCourses();

        //Enter a third student and use the custom assignment operator i.e. 3rd student = 2nd student
        cout << endl;
        Student student3;
        student3 = student2;

        cout << "\nStudent 3: " << student2.getName() << endl;
        student3.printStudentCourses();

        cout << endl;
        //loop back to beginning
    }

    return 0;
}
