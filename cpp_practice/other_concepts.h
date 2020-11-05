#include <iostream>

/*
 * C++ Class Templates
 * You are given a main() function which takes a set of inputs. The type of input governs the kind of operation to be performed,
 * i.e. concatenation for strings and addition for int or float. You need to write the class template AddElements which has a function add()
 * for giving the sum of int or float elements. You also need to write a template specialization for the type string with
 * a function concatenate() to concatenate the second string to the first string.
 *
 * Input Format
 * The first line contains an integer n. Input will consist of n+1 lines where n is the number given in the first line of the input followed by n lines.
 * Each of the next n line contains the type of the elements provided and depending on the type,
 * either two strings or two integers or two floating point numbers will be given.
 * The type will be one of int, float or string types only.
 * Out of the following two elements, you have to concatenate or add the second element to the first element.
 *
 * Output Format
 * The code provided in the code editor will use your class template to add/append elements and give the output.
 */
int before() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    return 0;
}

int static r = before();

#define concatenate add

template<class T>
class AddElements {
    T element;
public:
    AddElements(T arg) { element = arg; }

    T add(T arg) { return element + arg; }
};

void call_addElements() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i) {
        std::string type;
        std::cin >> type;
        if (type == "float") {
            double elem1, elem2;
            std::cin >> elem1 >> elem2;
            AddElements<double> o_float(elem1);
            std::cout << o_float.add(elem2) << std::endl;
        } else if (type == "int") {
            int elem1, elem2;
            std::cin >> elem1 >> elem2;
            AddElements<int> o_int(elem1);
            std::cout << o_int.add(elem2) << std::endl;
        } else if (type == "string") {
            std::string elem1, elem2;
            std::cin >> elem1 >> elem2;
            AddElements<std::string> str(elem1);
            std::cout << str.concatenate(elem2);
        }
    }
}

/*
 * Preprocessor Solution
 * Review the locked stub code in your editor and add the preprocessor macros necessary to make the code work.
 *
 * Input Format
 *  The first line contains an integer, N, denoting the size of the array.
 *  The second line contains N space-separated integers, x1, x2, x3,...,xn, describing the elements in the array.
 *
 * Output Format
 *  You are not responsible for printing any output to stdout.
 *  Once the necessary preprocessor macros are written, the locked code in your editor will print a line that says Result = Z,
 *  where Z is the difference between the maximum and minimum values in the array.
 */
#include <vector>

#define io(v) std::cin >> v
#define toStr(x) #x
#define INF 2147483647
#define FUNCTION(name, opr)
#define minimum(a, b) a = (a < b ? a : b)
#define maximum(a, b) a = (a > b) ? a : b
#define foreach(v, i) for(int i=0; i < v.size(); i++)

#if !defined toStr || !defined io || !defined FUNCTION || !defined INF
#error Missing preprocessor definitions
#endif

FUNCTION(minimum, <)
FUNCTION(maximum, >)

int preprocessor_solution() {
    int n;
    std::cin >> n;
    std::vector<int> v(n);
    foreach(v, i) {
        io(v)[i];
    }
    int mn = INF;
    int mx = -INF;
    foreach(v, i) {
        minimum(mn, v[i]);
        maximum(mx, v[i]);
    }
    int ans = mx - mn;
    std::cout << toStr(Result =) << ' ' << ans;
    return 0;
}

/*
 * Overload Operators
 *
 * Input Format
 *  The overloaded operator + should receive two complex numbers (a+ib and c+id) as parameters. It must return a single complex number.
 *  The overloaded operator << should add "a+ib" to the stream where a is the real part and b is the imaginary part of the complex number
 *  which is then passed as a parameter to the overloaded operator.
 *
 * Output Format
 * As per the problem statement, for the output, print "a+ib" followed by a newline where a=c.a and b=c.b.
 */
class Complex {
public:
    int a, b;

    void input(std::string s) {
        int v1 = 0;
        int i = 0;
        while (s[i] != '+') {
            v1 = v1 * 10 + s[i] - '0';
            i++;
        }
        while (s[i] == ' ' || s[i] == '+' || s[i] == 'i') {
            i++;
        }
        int v2 = 0;
        while (i < s.length()) {
            v2 = v2 * 10 + s[i] - '0';
            i++;
        }
        a = v1;
        b = v2;
    }
};

std::ostream &operator<<(std::ostream &os, const Complex &z) {
    if (z.b == 0) {
        os << z.a << std::endl;
    } else {
        os << z.a << (z.b > 0 ? '+' : '-') << 'i' << z.b << std::endl;
    }
    return os;
}

Complex operator+(const Complex &x, const Complex &y) {
    return {x.a + y.a, x.b + y.b};
}

void call_overload_operators() {
    Complex x, y;
    std::string s1, s2;
    std::cin >> s1;
    std::cin >> s2;
    x.input(s1);
    y.input(s2);
    Complex z = x + y;
    std::cout << z << std::endl;
}