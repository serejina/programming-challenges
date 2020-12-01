//
// Created by masha on 10/28/20.
//

#ifndef CPP_PRACTICE_INHERITANCE_H
#define CPP_PRACTICE_INHERITANCE_H

#endif //CPP_PRACTICE_INHERITANCE_H

#include <iostream>

/*
 * Inheritance Introduction
 * One of the important topics of Object Oriented Programming is Inheritance.
 * Inheritance allows us to define a class in terms of another class,
 * which allows us in the reusability of the code.
 *
 * Now write a function in Isosceles class such that the output is as given below.
 * Sample Output
 * I am an isosceles triangle
 * In an isosceles triangle two sides are equal
 * I am a triangle
 */
class Triangle {
public:
    void triangle() {
        std::cout << "I am a triangle" << std::endl;
    }
};

class Isosceles : public Triangle {
public:
    void isosceles() {
        std::cout << "I am an isosceles triangle" << std::endl;
    }

    void description() {
        std::cout << "In an isosceles triangle two sides are equal" << std::endl;
    }
};

/*
 * Multi Level Inheritance
 * Create a class called Equilateral which inherits from Isosceles
 * and should have a function such that the output is as given below.
 */
class Equilateral : public Isosceles {
public:
    void equilateral() {
        std::cout << "I am an equilateral triangle" << std::endl;
    }
};

int call() {
    Equilateral eqr;
    eqr.equilateral();
    eqr.isosceles();
    eqr.triangle();
    return 0;
}

/*
 * Rectangle Area
 * In this challenge, you are required to compute the area of a rectangle using classes.
 *
 * Create two classes:
 * Rectangle
 *  The Rectangle class should have two data fields-width and height of int types.
 *  The class should have display() method, to print the width and height of the rectangle separated by space.
 * RectangleArea
 *  The RectangleArea class is derived from Rectangle class, i.e., it is the sub-class of Rectangle class.
 *  The class should have read_input() method, to read the values of width and height of the rectangle.
 *  The RectangleArea class should also overload the display() method to print the area (width x height) of the rectangle.
 *
 * Input Format
 *  The first and only line of input contains two space separated integers denoting the width and height of the rectangle.
 *
 * Output Format
 *  The output should consist of exactly two lines:
 *  In the first line, print the width and height of the rectangle separated by space.
 *  In the second line, print the area of the rectangle.
 */
class Rectangle {
public:
    int width;
    int height;

    void display() {
        std::cout << width << " " << height << std::endl;
    }
};

class RectangleArea : public Rectangle {
public:
    void read_input() {
        std::cin >> width >> height;
    }

    void display() {
        std::cout << width * height << std::endl;
    }
};

/*
 * Accessing Inherited Functions
 * You are given three classes A, B and C. All three classes implement their own version of func.
 * In class A, func multiplies the value passed as a parameter by 2.
 * In class B, func multiplies the value passed as a parameter by 3.
 * In class C, func multiplies the value passed as a parameter by 5.
 * You are given a class D.
 * You need to modify the class D and implement the function update_val which sets D's val to new_val
 * by manipulating the value by only calling the func defined in classes A, B and C.
 * It is guaranteed that new_val has only 2,3 and 5 as its prime factors.
 */
class A {
public:
    A() {
        callA = 0;
    }

private:
    int callA;

    void inc() {
        callA++;
    }

protected:
    void func(int &a) {
        a = a * 2;
        inc();
    }

public:
    int getA() {
        return callA;
    }
};

class B {
public:
    B() {
        callB = 0;
    }

private:
    int callB;

    void inc() {
        callB++;
    }

protected:
    void func(int &a) {
        a = a * 3;
        inc();
    }

public:
    int getB() {
        return callB;
    }
};

class C {
public:
    C() {
        callC = 0;
    }

private:
    int callC;

    void inc() {
        callC++;
    }

protected:
    void func(int &a) {
        a = a * 5;
        inc();
    }

public:
    int getC() {
        return callC;
    }
};

class D : public A, B, C {

    int val;
public:
    //Initially val is 1
    D() {
        val = 1;
    }


    //Implement this function
    void update_val(int new_val);

    //For Checking Purpose
    void check(int); //Do not delete this line.
};

void D::check(int new_val) {
    update_val(new_val);
    std::cout << "Value = " << val << std::endl << "A's func called " << getA() << " times " << std::endl
              << "B's func called " << getB() << " times" << std::endl
              << "C's func called " << getC() << " times" << std::endl;
};

void D::update_val(int new_val) {
        while(new_val%2==0) {new_val = new_val/2; A::func(val);}
        while(new_val%3==0) {new_val = new_val/3; B::func(val);}
        while(new_val%5==0) {new_val = new_val/5; C::func(val);}
}

void call_check() {
    D d;
    int new_val;
    std::cin >> new_val;
    d.check(new_val);
}