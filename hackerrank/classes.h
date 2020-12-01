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

/* Inherited Code
 * You inherited a piece of code that performs username validation for your company's website.
 * The existing function works reasonably well, but it throws an exception when the username is too short.
 * Upon review, you realize that nobody ever defined the exception.
 * The inherited code is provided for you in the locked section of your editor.
 * Complete the code so that, when an exception is thrown, it prints Too short: n (where n is the length of the given username).
 *
 * Input Format
 *  The first line contains an integer, t, the number of test cases.
 *  Each of the t subsequent lines describes a test case as a single username string, u.
 *
 * Output Format
 *  You are not responsible for directly printing anything to stdout. If your code is correct,
 *  the locked stub code in your editor will print either Valid (if the username is valid), Invalid (if the username is invalid),
 *  or Too short: n (where n is the length of the too-short username) on a new line for each test case.
 */
class BadLengthException : public std::exception {
private:
    int length;
    std::string error;

public:
    BadLengthException(int length) {
        this->length = length;
        this->error = std::to_string(length);
    };

    virtual ~BadLengthException() throw() {};

    virtual const char *what() {
        return error.c_str();
    }
};

bool checkUsername(std::string username) {
    bool isValid = true;
    int n = username.length();
    if (n < 5) {
        throw BadLengthException(n);
    }
    for (int i = 0; i < n - 1; i++) {
        if (username[i] == 'w' && username[i + 1] == 'w') {
            isValid = false;
        }
    }
    return isValid;
}

void call_inherited_code() {
    int T;
    std::cin >> T;
    while (T--) {
        std::string username;
        std::cin >> username;
        try {
            bool isValid = checkUsername(username);
            if (isValid) {
                std::cout << "Valid" << '\n';
            } else {
                std::cout << "Invalid" << '\n';
            }
        } catch (BadLengthException e) {
            std::cout << "Too short: " << e.what() << '\n';
        }
    }
}

/*
 * Exceptional Server
 * In this challenge, you are required to handle error messages while working with small computational server that performs complex calculations.
 * It has a function that takes 2 large numbers as its input and returns a numeric result. Unfortunately,
 * there are various exceptions that may occur during execution.
 * Complete the code in your editor so that it prints appropriate error messages, should anything go wrong.
 * The expected behavior is defined as follows:
 * - If the compute function runs fine with the given arguments, then print the result of the function call.
 * - If it fails to allocate the memory that it needs, print Not enough memory.
 * - If any other standard C++ exception occurs, print Exception: S where  is the exception's error message.
 * - If any non-standard exception occurs, print Other Exception.
 *
 * Input Format
 *  The first line contains an integer, T, the number of test cases.
 *  Each of the T subsequent lines describes a test case as 2 space-separated integers, A and B, respectively.
 *
 * Output Format
 *  For each test case, print a single line containing whichever message described in the Problem Statement above is appropriate.
 *  After all messages have been printed, the locked stub code in your editor prints the server load.
 */
#include <vector>
#include <cmath>

class Server {
private:
    static int load;
public:
    static int compute(long long A, long long B) {
        load += 1;
        if (A < 0) {
            throw std::invalid_argument("A is negative");
        }
        std::vector<int> v(A, 0);
        int real = -1, cmplx = sqrt(-1);
        if (B == 0) throw 0;
        real = (A / B) * real;
        int ans = v.at(B);
        return real + A - B * ans;
    }

    static int getLoad() {
        return load;
    }
};

int Server::load = 0;

int call_exceptional_server() {
    int T;
    std::cin >> T;
    while (T--) {
        long long A, B;
        std::cin >> A >> B;
        try {
            int res = Server::compute(A, B);
            std::cout << res << std::endl;
        }
        catch (const std::bad_alloc &e) {
            std::cout << "Not enough memory" << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        catch (...) {
            std::cout << "Other Exception" << std::endl;
        }

    }
    std::cout << Server::getLoad() << std::endl;
    return 0;
}

/*
 * Virtual Functions
 * This problem is to get you familiar with virtual functions. Create three classes Person, Professor and Student.
 * The class Person should have data members name and age. The classes Professor and Student should inherit from the class Person.
 * The class Professor should have two integer members: publications and cur_id. There will be two member functions: getdata and putdata.
 * The function getdata should get the input from the user: the name, age and publications of the professor.
 * The function putdata should print the name, age, publications and the cur_id of the professor.
 *
 * The class Student should have two data members: marks, which is an array of size 6 and cur_id.
 * It has two member functions: getdata and putdata. The function getdata should get the input from the user: the name, age,
 * and the marks of the student in 6 subjects. The function putdata should print the name, age, sum of the marks and the cur_id of the student.
 *
 * For each object being created of the Professor or the Student class, sequential id's should be assigned to them starting from 1.
 * Solve this problem using virtual functions, constructors and static variables. You can create more data members if you want.
 *
 * Input Format
 * The first line of input contains the number of objects that are being created. If the first line of input for each object is 1,
 * it means that the object being created is of the Professor class, you will have to input the name, age and publications of the professor.
 *
 * If the first line of input for each object is 2, it means that the object is of the Student class, you will have to input the name,
 * age and the marks of the student in 6 subjects.
 *
 * Output Format
 * There are two types of output depending on the object.
 * If the object is of type Professor, print the space separated name, age, publications and id on a new line.
 * If the object is of the Student class, print the space separated name, age, the sum of the marks in 6 subjects and id on a new line.
 */
class Person {
public:
    std::string name;
    int age;
    int cur_id;

public:
    virtual void getdata() {};
    virtual void putdata() {};
};

class Professor : public Person {

public:
    int publication;
    static int count_id;

public:
    Professor() {
        count_id++;
        this->cur_id=count_id;
    };


    void getdata() override
    {
        std::cin >> name >> age >> publication;
    };

    void putdata() override {
        std::cout << name << " " << age << " " << publication << " " << cur_id << std::endl;
    }
};

int Professor::count_id = 0;

class StudentVF : public Person {
private:
    static const int numOfExams = 6;

public:
    static int count_id;
    int marks[numOfExams];

    StudentVF()
    {
        count_id++;
        this->cur_id=count_id;
    };

    void getdata() override
    {
        std::cin >> name >> age;
        for(int i=0; i < numOfExams; i++)
        {
            std::cin >> marks[i];
        }
    }
    void putdata() override {
        int markSum = 0;
        for (int i=0; i < numOfExams; i++)
        {
            markSum +=marks[i];
        }
        std::cout << name << " " << age << " " << markSum << " " << cur_id << std::endl;
    }
};

int StudentVF::count_id = 0;

void call_virtual_function(){

    int n, val;
    std::cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        std::cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new StudentVF; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.

}