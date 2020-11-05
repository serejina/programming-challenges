//
// Created by masha on 11/4/20.
//

#ifndef CPP_PRACTICE_STRING_H
#define CPP_PRACTICE_STRING_H

#endif //CPP_PRACTICE_STRING_H

#include <iostream>

/*
 * StringStream
 * Complete the parseInts function in the editor below.
 * parseInts has the following parameters:
 * string str: a string of comma separated integers
 * Returns
 * vector<int>: a vector of the parsed integers.
 * Note You can learn to push elements onto a vector by solving the first problem in the STL chapter.
 * Input Format
 * There is one line of n integers separated by commas.
 */
#include <sstream>
#include <vector>

std::vector<int> parseInts(std::string str) {
    // Complete this function
    std::vector<int> res_vector;
    std::stringstream ss(str);
    char ch;
    int tmp;
    while (ss) {
        ss >> tmp >> ch;
        res_vector.push_back(tmp);
    }
    return res_vector;
}

void call_parserInts() {
    std::string str;
    std::cin >> str;
    std::vector<int> integers = parseInts(str);
    for (int i = 0; i < integers.size(); i++) {
        std::cout << integers[i] << "\n";
    }
}

/*
 * Strings
 * Input Format
 * You are given two strings, a and b, separated by a new line. Each string will consist of lower case Latin characters ('a'-'z').
 *
 * Output Format
 * In the first line print two space-separated integers, representing the length of a and b respectively.
 * In the second line print the string produced by concatenating a and b (a+b).
 * In the third line print two strings separated by a space, a' and b'.
 * a' and b' are the same as  and , respectively, except that their first characters are swapped.
 */
void strings()
{    std::string a;
    std::string b;

    std::cin >> a;
    std::cin >> b;

    std::cout << a.length() << " " << b.length() << std::endl;
    std::cout << a+b << std::endl;

    char tmp = a[0];
    a[0] = b[0];
    b[0] = tmp;
    std::cout << a << " " << b << std::endl;}