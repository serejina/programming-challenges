//
// Created by masha on 11/5/20.
//

#ifndef CPP_PRACTICE_CLASSES_H
#define CPP_PRACTICE_CLASSES_H

#endif //CPP_PRACTICE_CLASSES_H

#include <iostream>

/*
 * Structs
 * Input Format
 *  Input will consist of four lines.
 *  The first line will contain an integer, representing age.
 *  The second line will contain a string, consisting of lower-case Latin characters ('a'-'z'), representing the first_name of a student.
 *  The third line will contain another string, consisting of lower-case Latin characters ('a'-'z'), representing the last_name of a student.
 *  The fourth line will contain an integer, representing the standard of student.
 *
 * Note: The number of characters in first_name and last_name will not exceed 50.
 *
 * Output Format
 *  Output will be of a single line, consisting of age, first_name, last_name and standard, each separated by one white space.
 */
struct Student_struct {
    // age (int), first_name (string), last_name (string) and standard (int).
    int age;
    std::string first_name;
    std::string last_name;
    int standard;
};

int call_struct() {
    Student_struct st;

    std::cin >> st.age >> st.first_name >> st.last_name >> st.standard;
    std::cout << st.age << " " << st.first_name << " " << st.last_name << " " << st.standard;

    return 0;
}


/*
 * Class
 * You have to create a class, named Student, representing the student's details, as mentioned above,
 * and store the data of a student. Create setter and getter functions for each element;
 * that is, the class should at least have following functions:
 *  get_age, set_age
 *  get_first_name, set_first_name
 *  get_last_name, set_last_name
 *  get_standard, set_standard
 * Also, you have to create another method to_string() which returns the string consisting of the above elements,
 * separated by a comma(,). You can refer to stringstream for this.
 *
 * Input Format
 *  Input will consist of four lines.
 *  The first line will contain an integer, representing the age.
 *  The second line will contain a string, consisting of lower-case Latin characters ('a'-'z'), representing the first_name of a student.
 *  The third line will contain another string, consisting of lower-case Latin characters ('a'-'z'), representing the last_name of a student.
 *  The fourth line will contain an integer, representing the standard of student.
 *
 * Note: The number of characters in first_name and last_name will not exceed 50.
 *
 * Output Format
 *  The code provided by HackerRank will use your class members to set and then get the elements of the Student class.
 */
class Student {
    // ge (int), first_name (string), last_name (string) and standard
private:
    std::string first_name;
    std::string last_name;
    int age;
    int standard;

public:
    /*
    get_age, set_age
    get_first_name, set_first_name
    get_last_name, set_last_name
    get_standard, set_standard
    */
    std::string get_first_name() { return first_name; }

    std::string get_last_name() { return last_name; }

    int get_age() { return age; }

    int get_standard() { return standard; }

    void set_first_name(const std::string first_name) {
        this->first_name = first_name;
    }

    void set_last_name(const std::string last_name) {
        this->last_name = last_name;
    }

    void set_age(const int age) {
        this->age = age;
    }

    void set_standard(const int standard) {
        this->standard = standard;
    }

    std::string to_string() {
        std::string output = std::to_string(age) + "," + first_name + "," + last_name + "," + std::to_string(standard);

        return output;
    }
};

int call_student_class() {
    int age, standard;
    std::string first_name, last_name;

    std::cin >> age >> first_name >> last_name >> standard;

    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);

    std::cout << st.get_age() << "\n";
    std::cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    std::cout << st.get_standard() << "\n";
    std::cout << "\n";
    std::cout << st.to_string();

    return 0;
}

/*
 * Classes and Objects
 * Create a class named Student with the following specifications:
 * An instance variable named scores to hold a student's 5 exam scores.
 * A void input() function that reads 5 integers and saves them to scores.
 * An int calculateTotalScore() function that returns the sum of the student's scores.
 *
 * Input Format
 *  Most of the input is handled for you by the locked code in the editor.
 *  In the void Student::input() function, you must read 5 scores from stdin and save them to your scores instance variable.
 *
 *  Sample Input
 *  The first line contains n, the number of students in Kristen's 5 class.
 *  The n subsequent lines contain each student's 5 exam grades for this semester.
 */
class StudentObj {
private:
    static const int numberOfExams = 5;

public:
    int scores[numberOfExams];

public:
    void input() {
        for (int i = 0; i < numberOfExams; i++) {
            int ex;
            std::cin >> ex;
            scores[i] = ex;
        }
    }

    int calculateTotalScore() {
        int res = 0;
        for (int i = 0; i < numberOfExams; i++) {
            res += scores[i];
        }
        return res;
    }
};

int call_StudentObj() {
    int n; // number of students
    std::cin >> n;
    StudentObj *s = new StudentObj[n]; // an array of n students

    for (int i = 0; i < n; i++) {
        s[i].input();
    }

    // calculate kristen's score
    int kristen_score = s[0].calculateTotalScore();

    // determine how many students scored higher than kristen
    int count = 0;
    for (int i = 1; i < n; i++) {
        int total = s[i].calculateTotalScore();
        if (total > kristen_score) {
            count++;
        }
    }

    // print result
    std::cout << count;

    return 0;
}


/*
 * Box It
 * Implement the class Box
 * l,b,h are integers representing the dimensions of the box
 *
 * The class should have the following functions:
 * Constructors:
 * Box();
 * Box(int,int,int);
 * Box(Box);
 *
 * int getLength(); // Return box's length
 * int getBreadth (); // Return box's breadth
 * int getHeight ();  //Return box's height
 * long long CalculateVolume(); // Return the volume of the box
 *
 * Overload operator < as specified
 * bool operator<(Box& b)
 *
 * Overload operator << as specified
 * ostream& operator<<(ostream& out, Box& B)
 */
class Box {
private:
    int length;
    int breadth;
    int height;

public:
    Box() : length(0), breadth(0), height(0) {};

    Box(int length, int breadth, int height) : length(length), breadth(breadth), height(height) {};

    Box(Box &other) {
        length = other.length;
        breadth = other.breadth;
        height = other.height;
    }

    int getLength() { return length; };

    int getBreadth() { return breadth; };

    int getHeight() { return height; };

    long long CalculateVolume() {
        return (long long) length * height * breadth;
    }

    bool operator<(const Box &B) {
        if (this->length < B.length) { return true; }

        if (this->breadth < B.breadth && this->length == B.length) { return true; }

        if (this->height < B.height && this->breadth == B.breadth && this->length == B.length) { return true; }
        return false;
    }

    friend std::ostream &operator<<(std::ostream &out, const Box &B) {
        out << B.length << " " << B.breadth << " " << B.height;
        return out;
    }
};

void check2() {
    int n;
    std::cin >> n;
    Box temp;
    for (int i = 0; i < n; i++) {
        int type;
        std::cin >> type;
        if (type == 1) {
            std::cout << temp << std::endl;
        }
        if (type == 2) {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box NewBox(l, b, h);
            temp = NewBox;
            std::cout << temp << std::endl;
        }
        if (type == 3) {
            int l, b, h;
            std::cin >> l >> b >> h;
            Box NewBox(l, b, h);
            if (NewBox < temp) {
                std::cout << "Lesser\n";
            } else {
                std::cout << "Greater\n";
            }
        }
        if (type == 4) {
            std::cout << temp.CalculateVolume() << std::endl;
        }
        if (type == 5) {
            Box NewBox(temp);
            std::cout << NewBox << std::endl;
        }
    }
}