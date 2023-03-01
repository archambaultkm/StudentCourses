#include <iostream>
#include "../inc/courses.h"

int main() {

    Student student1;
    string name;
    int numCourses;
    bool moreCourses;

    cout << "Enter the first student's name: " << endl;
    cin >> name;
    student1.setName(name);

    numCourses = 0;
    moreCourses = true;

    while(moreCourses) {

        numCourses ++;
        cout<< "Enter a name for course " << numCourses << " (or q to quit): " << endl;
        //add validation so they can't enter spaces
        cin >> name;

        if (name == "q" || name == "Q") {
            //quit the loop
            numCourses --;
            moreCourses = false;
        } else {
            //the addcourse method will also take care of incrementing the student's numcourses property
            student1.addCourse(name);
        }
    }

    cout << "Student 1: " << student1.getName() << endl;
    cout << "Number of courses: " << student1.getNumCourses() << endl;

    for (int i=0;i<student1.getNumCourses();i++) { //getNumCourses should directly correlate to size of array so it should be safe to call like this
        cout << "Course " << i+1 << ": " << student1.getCourseNames()[i] << endl;
    }

    return 0;
}
