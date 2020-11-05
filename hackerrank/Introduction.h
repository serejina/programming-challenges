#include <iostream>

/*
 * Say "Hello, World!" With C++
 * We're starting out by printing the most famous computing phrase of all time!
 * In the editor below, use either printf or cout to print the string 'Hello, World!' to stdout.
 */
void hello_world() {
    std::cout << "Hello, World!" << std::endl;
}

/*
 * Input and Output
 * Read 3 numbers from stdin and print their sum to stdout.
 *
 * Input Format
 * One line that contains 3 space-separated integers: a, b, and c.
 */
void input_output() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << a + b + c << std::endl;
}

/*
 * Basic Data Types
 * To print a data type, use the following syntax: printf("`format_specifier`", val)
 *
 * Input Format
 * Input consists of the following space-separated values: int, long, char, float, and double, respectively.
 *
 * Output Format
 * Print each element on a new line in the same order it was received as input.
 * Note that the floating point value should be correct up to 3 decimal places and the double to 9 decimal places.
 */
void basic_data_types() {
    int a;
    long b;
    char ch;
    float f;
    double d;
    scanf("%d %ld %c %f %lf", &a, &b, &ch, &f, &d);
    printf("%d\n%ld\n%c\n%.3f\n%.9lf", a, b, ch, f, d);
}

/*
 * Conditional Statements
 * Given a positive integer , do the following:
 * If 1<=n<=9, print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.).
 * If n>9, print Greater than 9.
 *
 * Input Format
 * A single integer, n.
 *
 * Output Format
 * If 1<=n<=9, then print the lowercase English word corresponding to the number (e.g., one for 1, two for 2, etc.);
 * otherwise, print Greater than 9.
 */
void conditional_statements() {
    int n;
    std::cin >> n;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (n > 9) {
        std::cout << "Greater than 9" << std::endl;
    } else {
        if (n == 1) { std::cout << "one" << std::endl; }
        else if (n == 2) { std::cout << "two" << std::endl; }
        else if (n == 3) { std::cout << "three" << std::endl; }
        else if (n == 4) { std::cout << "four" << std::endl; }
        else if (n == 5) { std::cout << "five" << std::endl; }
        else if (n == 6) { std::cout << "six" << std::endl; }
        else if (n == 7) { std::cout << "seven" << std::endl; }
        else if (n == 8) { std::cout << "eight" << std::endl; }
        else { std::cout << "nine" << std::endl; }
    }
}

/*
 * For Loop
 * Input Format
 * You will be given two positive integers, a and b (a<=b), separated by a newline.
 *
 * Output Format
 * For each integer n in the inclusive interval [a,b]:
 * If 1<=n<=9, then print the English representation of it in lowercase. That is "one" for 1, "two" for 2, and so on.
 * Else if n>9 and it is an even number, then print "even".
 * Else if n>9 and it is an odd number, then print "odd".
 */
void for_loop() {
    int a;
    int b;

    std::cin >> a;
    std::cin >> b;

    for (int i = a; i <= b; i++) {
        if (i > 9 && i % 2 == 0) { std::cout << "even" << std::endl; }
        if (i > 9 && i % 2 != 0) { std::cout << "odd" << std::endl; }

        if (i >= 1 && i <= 9) {
            if (i == 1) { std::cout << "one" << std::endl; }
            else if (i == 2) { std::cout << "two" << std::endl; }
            else if (i == 3) { std::cout << "three" << std::endl; }
            else if (i == 4) { std::cout << "four" << std::endl; }
            else if (i == 5) { std::cout << "five" << std::endl; }
            else if (i == 6) { std::cout << "six" << std::endl; }
            else if (i == 7) { std::cout << "seven" << std::endl; }
            else if (i == 8) { std::cout << "eight" << std::endl; }
            else { std::cout << "nine" << std::endl; }
        }
    }
}

/*
 * Functions
 * Write a function int max_of_four(int a, int b, int c, int d) which returns the maximum of the four arguments it receives.
 * Input Format
 * Input will contain four integers - a,b,c,d , one per line.
 * Output Format
 * Return the greatest of the four integers.
 * PS: I/O will be automatically handled.
 */
int max_of_four(int a, int b, int c, int d) {
    int max = a;
    if (max < b) { max = b; }
    if (max < c) { max = c; }
    if (max < d) { max = d; }
    return max;
}

void call_max_of_four() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int ans = max_of_four(a, b, c, d);
    printf("%d", ans);
}

/*
 * Pointer
 * Function Description
 * Complete the update function in the editor below.
 * update has the following parameters:
 *  int *a: an integer
 *  int *b: an integer
 * Returns
 * The function is declared with a void return type, so there is no value to return.
 * Modify the values in memory so that a contains their sum and b contains their absoluted difference.
 * a'=a+b
 * b'=|a-b|
 * Input Format
 * Input will contain two integers, a and b, separated by a newline.
 */
void update(int *a, int *b) {
    // Complete this function
    int tmp_a = *a;
    *a = tmp_a + *b;
    *b = std::abs(tmp_a - *b);
}

int call_pointer() {
    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}

/*
 * Arrays Introduction
 * You will be given an array of N integers and you have to print the integers in the reverse order.
 * Input Format
 * The first line of the input contains N, where N is the number of integers.The next line contains N space-separated integers.
 * Output Format
 * Print the N integers of the array in the reverse order, space-separated on a single line.
 */
void array_intro() {
    int n;
    std::cin >> n;

    int a[n];

    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--) {
        std::cout << a[i] << " ";
    }
}

/*
 * Variable Sized Arrays
 * Consider an n-element array, a, where each index i in the array contains a reference to an array of ki integers
 * (where the value of ki varies from array to array). See the Explanation section below for a diagram.
 * Given a, you must answer q queries. Each query is in the format i j, where i denotes an index in array a and
 * j denotes an index in the array located at a[i]. For each query, find and print the value of element j
 * in the array at location a[i] on a new line.
 *
 * Input Format
 * The first line contains two space-separated integers denoting the respective values of n
 * (the number of variable-length arrays) and q (the number of queries).
 * Each line i of the n subsequent lines contains a space-separated sequence
 * in the format k a[i]0 a[i]1 … a[i]k-1 describing the k-element array located at a[i].
 * Each of the q subsequent lines contains two space-separated integers describing the respective values of i
 * (an index in array a) and j (an index in the array referenced by a[i]) for a query.
 *
 * Output Format
 * For each pair of i and j values (i.e., for each query), print a single integer that denotes
 * the element located at index j of the array referenced by a[i]. There should be a total of q lines of output.
 */
#include <vector>
void variable_sized_array() {
    int n, q;

    std::cin >> n >> q;
    std::vector<std::vector<int>> a(n);

    for (int i = 0; i < n; i++) {
        int k;
        std::cin >> k;

        a[i].resize(k);
        for (int j = 0; j < k; j++) {
            std::cin >> a[i][j];
        }
    }

    std::vector<std::pair<int, int>> coord_list;
    for (int q_i = 0; q_i < q; q_i++) {
        int i, j;
        std::cin >> i >> j;
        coord_list.push_back(std::make_pair(i, j));
    }

    for (int i = 0; i < q; i++) {
        std::cout << a[coord_list[i].first][coord_list[i].second] << std::endl;
    }
}
