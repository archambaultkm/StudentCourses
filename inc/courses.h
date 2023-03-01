//
// Created by Kaitlyn Archambault on 2023-02-27.
//

#ifndef UNTITLED1_COURSES_H
#define UNTITLED1_COURSES_H

#include <string>
#include <utility>
using namespace std;

class Student {

    private:
        string name;
        int numCourses;
        string* courseNames;

    public:
        //default constructor
        Student()  {
            name = "";
            numCourses = 0;
            courseNames = new string[0];
        };

        //constructor with arguments
        Student(string name, int numCourses)
            :name(std::move(name)), numCourses(numCourses) //initialization list
            {
                courseNames = new string[numCourses+1];
            } //empty body

        // Copy Constructor
        Student(const Student& source)= default;

        //Move constructor
        Student(Student&& source) noexcept //won't be allowed to throw exceptions, shouldn't be able to do anything that would cause that anyway
            :name(std::move(source.name)), numCourses(source.numCourses), courseNames(source.courseNames)
            {}


        ~Student() { delete []courseNames; }; //default destructor

        string getName() const{return this->name;}
        void setName(string name) {this->name = name;}

        int getNumCourses() const{return this->numCourses;}
        //don't need a setter, addCourses increments as values are added

        string* getCourseNames() {return this->courseNames;}

        //function to allow adding a course to the course list as many times as needed
        void addCourse(string courseName) {

            int old_size = *(&courseNames + 1) - courseNames; //the size of the array won't match the number of courses, since most of the time there should be empty room.
            this->numCourses += 1;

            if (numCourses >= old_size) {

                int new_size = old_size + 1; //only increasing by 1 each time prevents making space for a bunch of unused indeces

                auto* newArr = new string[new_size];
                std::copy(courseNames, courseNames + std::min(old_size, new_size), newArr);
                delete[] courseNames;
                courseNames = newArr;
            }

            //since we added one to the numCourses counter already, this should reflect the next uninitialized index of the array
            courseNames[numCourses - 1] = courseName;

        } // end addcourse

}; //end student class


#endif //UNTITLED1_COURSES_H
