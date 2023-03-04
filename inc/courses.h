//
// Created by Kaitlyn Archambault on 2023-02-27.
//

#ifndef UNTITLED1_COURSES_H
#define UNTITLED1_COURSES_H

#include <string>
using namespace std;

class Student {

    private:
    string name;
    int numCourses;
    string* courseNames;

    public:
    //default constructor
    Student()  {
        cout << "Default constructor fired" << endl;
        name = "";
        numCourses = 0;
        courseNames = new string[0];
    };

    // Copy Constructor
    Student(const Student& source) {
        cout << "Copy constructor fired" << endl;

        name = source.name;
        numCourses = source.numCourses;
        courseNames = new string[numCourses];
        std::copy(source.courseNames, source.courseNames + numCourses, courseNames);
    };

    // Assignment operator
    Student& operator= (const Student& source) {
        cout << "Custom assignment operator fired" << endl;

        name = source.name;
        numCourses = source.numCourses;
        courseNames = new string[numCourses];
        std::copy(source.courseNames, source.courseNames + numCourses, courseNames);

        return *this;
    }

    //default destructor
    ~Student() {
        cout << "Destructor fired" << endl;

        if (courseNames) {
            cout << "Deleting array" << endl;
            delete [] courseNames;
            courseNames = {};
        }
    };

    string getName() const{return this->name;}
    void setName(string name) {this->name = name;}

    //function to allow adding a course to the course list as many times as needed
    void addCourse(string courseName) {

        this->numCourses += 1;
        int old_size = *(&courseNames + 1) - courseNames; //find out what memory the old array was occupying

        if (numCourses >= old_size) {

            int new_size = old_size + 1; //only increasing by 1 each time prevents making space for a bunch of unused indeces

            string* newArr = new string[new_size];
            std::copy(courseNames, courseNames + old_size, newArr);
            delete []courseNames;
            courseNames = newArr;
            delete []newArr; //free memory from placeholder array
        }

        //since we added one to the numCourses counter already, this should reflect the next uninitialized index of the array
        courseNames[numCourses - 1] = std::move(courseName); //move prevents unneccesary copies

    } // end addcourse

    void printStudentCourses() {
        cout << "Number of courses: " << numCourses << endl;

        for (int i=0;i<numCourses;i++) { //numCourses will directly correlate to initialized indexes of the array
            cout << "Course " << i+1 << ": " << courseNames[i] << endl;
        }
    }

    void resetCourses() {
        numCourses = 0;
        delete []courseNames;
        courseNames = new string[0];

        cout << "Courses reset" << endl;
    }
}; //end student class

#endif //UNTITLED1_COURSES_H