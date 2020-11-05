//
// Created by masha on 10/21/20.
//
#include <vector>
#include <iostream>
#include <set>

#ifndef CPP_PRACTICE_STL_H
#define CPP_PRACTICE_STL_H

#endif //CPP_PRACTICE_STL_H

/*
 * Vector-Sort
 * You are given N integers.Sort the N integers and print the sorted order.
 * Store the N integers in a vector. Vectors are sequence containers representing arrays that can change in size.
 * Example:
 *  Sample Input
 *      5
 *      1 6 10 8 4
 *  Sample Output
 *      1 4 6 8 10
 */
void vector_sort() {
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (std::size_t i{0}; i < n; ++i) {
        std::cin >> vec[i];
    }

    std::sort(vec.begin(), vec.end());

    for (int element: vec) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}

/*
 * Vector-Erase
 * You are provided with a vector of N integers. Then, you are given 2 queries.
 * For the first query, you are provided with 1 integer, which denotes a position in the vector.
 * The value at this position in the vector needs to be erased.
 * The next query consists of 2 integers denoting a range of the positions in the vector.
 * The elements which fall under that range should be removed.
 * The second query is performed on the updated vector which we get after performing the first query.
 * Input Format:
 * The first line of the input contains an integer N.The next line contains N space separated integers(1-based index).
 * The third line contains a single integer x,denoting the position of an element that should be removed from the vector.
 * The fourth line contains two integers a and b denoting the range that should be erased from the vector inclusive of a and exclusive of b.
 * Output Format:
 * Print the size of the vector in the first line and the elements of the vector after the two erase operations in the second line separated by space.
 */
void vector_erase() {
    int n, x, a, b;
    std::cin >> n;

    std::vector<int> vec(n);
    for (std::size_t i{0}; i < n; ++i) {
        std::cin >> vec[i];
    }

    std::cin >> x;
    vec.erase(vec.begin() + x - 1);
    std::cin >> a >> b;
    vec.erase(vec.begin() + a - 1, vec.begin() + b - 1);

    std::cout << vec.size() << std::endl;
    for (int element: vec) {
        std::cout << element << ' ';
    }
    std::cout << std::endl;
}


/*
 * You are given N integers in sorted order. Also, you are given Q queries.
 * In each query, you will be given an integer and you have to tell whether that integer is present in the array.
 * If so, you have to tell at which index it is present and if it is not present,
 * you have to tell the index at which the smallest integer that is just greater than the given number is present.
 */
void lower_bound_stl() {
    int n;
    std::cin >> n;

    std::vector<int> vec(n);
    for (std::size_t i{0}; i < n; ++i) {
        std::cin >> vec[i];
    }


    int q;
    std::cin >> q;
    std::vector<int>::iterator Low;
    while (q--) {
        int query;
        std::cin >> query;

        Low = std::lower_bound(vec.begin(), vec.end(), query);

        int idx = Low - vec.begin() + 1;
        if (*Low == query) {
            std::cout << "Yes " << idx;
        } else {
            std::cout << "No " << idx;
        }
        std::cout << std::endl;
    }
}

/*
 * Add an element x to the set.
 * Delete an element x from the set. (If the number x is not present in the set, then do nothing).
 * If the number x is present in the set, then print "Yes"(without quotes) else print "No"(without quotes).
 *
 * Input Format
 * The first line of the input contains Q where Q is the number of queries.
 * The next Q lines contain 1 query each.
 * Each query consists of two integers x and y where y is the type of the query and x is an integer.
 *
 * Output Format
 * For queries of type 3 print "Yes"(without quotes) if the number x is present in the set and if the number is not present, then print "No"(without quotes).
 * Each query of type 3 should be printed in a new line.
 */
void sets_stl() {
    std::set<int> s;
    int q;

    std::cin >> q;

    while (q--) {
        int type, x;

        std::cin >> type >> x;
        if (type == 1) {
            s.insert(x);
        } else {
            std::set<int>::iterator itr = s.find(x);

            if (type == 2 && itr != s.end()) {
                s.erase(x);
            }
            if (type == 3 && itr != s.end()) {
                std::cout << "Yes" << std::endl;
            }
            if (type == 3 && itr == s.end()) {
                std::cout << "No" << std::endl;
            }
        }
    }

}

/*
 * You are appointed as the assistant to a teacher in a school and she is correcting the answer sheets of the students.
 * Each student can have multiple answer sheets. So the teacher has Q queries:
 * 1. Add the marks Y to the student whose name is X;
 * 2. Erase the marks of the students whose name is X;
 * 3. Print the marks of the students whose name is X, (If X didn't get any marks print 0).
 *
 * Input Format
 * The first line of the input contains Q where Q is the number of queries.
 * The next Q lines contain 1 query each.The first integer, type of each query is the type of the query.
 * If query is of type 1, it consists of one string and an integer X and Y where X is the name of the student and Y is the marks of the student.
 * If query is of type 2 or 3,it consists of a single string X where X is the name of the student.
 *
 * Output Format
 * For queries of type 3 print the marks of the given student.
 */
void maps_stl() {
    int q;
    std::map<std::string, int> students;

    std::cin >> q;

    while (q--) {
        int type, grade;
        std::string name;

        std::cin >> type >> name;
        std::map<std::string, int>::iterator itr = students.find(name);

        if (type == 1 && itr != students.end()) {
            std::cin >> grade;
            students[name] += grade;
        } else if (type == 1 && itr == students.end()) {
            std::cin >> grade;
            students.insert(std::make_pair(name, grade));
        } else if (type == 2 && itr != students.end()) {
            students.erase(name);
        } else if (type == 3 && itr != students.end()) {
            std::cout << itr->second << std::endl;
        } else if (type == 3 && itr == students.end()) {
            std::cout << 0 << std::endl;
        }
    }
}

/*
 * Print Pretty
 * Given a text file with many lines of numbers to format and print,
 * for each row of 3 space-separated doubles,
 * format and print the numbers using the specifications in the Output Format section below.
 *
 * Input Format
 * The first line contains an integer, T, the number of test cases.
 * Each of the T subsequent lines describes a test case as 3 space-separated floating-point numbers: A, B, and C, respectively.
 *
 * Output Format
 * For each test case, print 3 lines containing the formatted A, B, and C, respectively.
 * Each A, B, and C must be formatted as follows:
 *  1. A: Strip its decimal (i.e., truncate it) and print its hexadecimal representation (including the 0x prefix) in lower case letters.
 *  2. B: Print it to a scale of 2 decimal places, preceded by a + or - sign (indicating if it's positive or negative),
 *        right justified, and left-padded with underscores so that the printed result is exactly 15 characters wide.
 *  3. C: Print it to a scale of exactly nine decimal places, expressed in scientific notation using upper case.
 */
void print_pretty() {
    int t;
    std::cin >> t;
    std::cout << setiosflags(std::ios::uppercase);
    std::cout << std::setw(0xf) << std::internal;
    while (t--) {
        double A, B, C;
        std::cin >> A >> B >> C;

        std::cout << std::hex << std::showbase << std::nouppercase << std::left << long(A) << std::endl;
        std::cout << std::right << std::setfill('_') << std::setw(15)
                  << std::setprecision(2) << std::showpos
                  << std::dec << std::fixed << B << std::endl;
        std::cout << std::left << std::setprecision(9) << std::noshowpos << std::uppercase << std::scientific << C
                  << std::endl;
    }
}