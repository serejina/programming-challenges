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

/*
 * Operator Overloading
 * You are given a main() function which takes a set of inputs to create two matrices and prints the result of their addition.
 * You need to write the class Matrix which has a member a of type vector<vector<int> >.
 * You also need to write a member function to overload the operator +.
 * The function's job will be to add two objects of Matrix type and return the resultant Matrix.
 *
 * Input Format
 *  First line will contain the number of test cases T. For each test case, there are three lines of input.
 *  The first line of each test case will contain two integers N and M which denote the number of the rows and columns respectively of the two matrices
 *  that will follow on the next two lines.
 *  These next two lines will each contain M*N elements describing the two matrices in row-wise format,
 *  i.e. first M elements belong to the first row,next  Melements belong to the second row and so on.
 *
 * Output Format
 * The code provided in the editor will use your class Matrix and overloaded operator function to add the two matrices and give the output.
 */
class Matrix {
public:
    std::vector<std::vector<int>> a;
};

Matrix operator+(Matrix &x, Matrix &y) {
    Matrix result;
    for (int i = 0; i < x.a.size(); ++i) {
        std::vector<int> b;
        for (int j = 0; j < x.a[i].size(); ++j) {
            b.push_back(x.a[i][j] + y.a[i][j]);
        }
        result.a.push_back(b);
    }
    return result;
}

void call_matrix_add() {
    int cases, k;
    std::cin >> cases;
    for (k = 0; k < cases; k++) {
        Matrix x;
        Matrix y;
        Matrix result;
        int n, m, i, j;
        std::cin >> n >> m;
        for (i = 0; i < n; i++) {
            std::vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                std::cin >> num;
                b.push_back(num);
            }
            x.a.push_back(b);
        }
        for (i = 0; i < n; i++) {
            std::vector<int> b;
            int num;
            for (j = 0; j < m; j++) {
                std::cin >> num;
                b.push_back(num);
            }
            y.a.push_back(b);
        }
        result = x + y;
        for (i = 0; i < n; i++) {
            for (j = 0; j < m; j++) {
                std::cout << result.a[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
}

/*
 * C++ Class Template Specialization
 * You are given a main function which reads the enumeration values for two different types as input,
 * then prints out the corresponding enumeration names.
 * Write a class template that can provide the names of the enumeration values for both types.
 * If the enumeration value is not valid, then print unknown.
 *
 * Input Format
 *  The first line contains t, the number of test cases.
 *  Each of the t subsequent lines contains two space-separated integers. The first integer is a color value, c,
 *  and the second integer is a fruit value, f.
 *
 * Output Format
 * The locked stub code in your editor prints t lines containing the color name and the fruit name corresponding to the input enumeration index.
 */

enum class Fruit {
    apple, orange, pear
};
enum class Color {
    red, green, orange
};

template<typename T>
struct Traits;

template<>
struct Traits<Fruit> {
    static std::string name(const int idx) {
        Fruit item = static_cast<Fruit>(idx);
        std::string name;
        switch (item) {
            case Fruit::apple  :
                name = "apple";
                break;
            case Fruit::orange:
                name = "orange";
                break;
            case Fruit::pear :
                name = "pear";
                break;
            default:
                name = "unknown";
        }
        return name;
    }
};

template<>
struct Traits<Color> {
    static std::string name(const int idx) {
        Color item = static_cast<Color>(idx);
        std::string name;
        switch (item) {
            case Color::red  :
                name = "red";
                break;
            case Color::green:
                name = "green";
                break;
            case Color::orange :
                name = "orange";
                break;
            default:
                name = "unknown";
        }
        return name;
    }
};

int call_enam() {
    int t = 0;
    std::cin >> t;

    for (int i = 0; i != t; ++i) {
        int index1;
        std::cin >> index1;
        int index2;
        std::cin >> index2;
        std::cout << Traits<Color>::name(index1) << " ";
        std::cout << Traits<Fruit>::name(index2) << "\n";
    }
}

/*
 * Attending Workshops
 * A student signed up for n workshops and wants to attend the maximum number of workshops where no two workshops overlap.
 * You must do the following:
 * 1. struct Workshop having the following members:
 *  - The workshop's start time.
 *  - The workshop's duration.
 *  - The workshop's end time.
 * 2. struct Available_Workshops having the following members:
 *  - An integer, n (the number of workshops the student signed up for).
 *  - An array of type Workshop array having size n.
 * Implement 2 functions:
 * 1. Available_Workshops* initialize (int start_time[], int duration[], int n)
 *    Creates an Available_Workshops object and initializes its elements using the elements in the start_time[] and duration[]
 *    parameters (both are of size n). Here, tart_time[i] and duration[i] are the respective start time and duration for the i-th workshop.
 *    This function must return a pointer to an Available_Workshops object.
 * 2. int CalculateMaxWorkshops(Available_Workshops* ptr)
 *    Returns the maximum number of workshops the student can attend—without overlap.
 *    The next workshop cannot be attended until the previous workshop ends.
 *
 *    Note: An array of unknown size (n) should be declared as follows:
 *    DataType* arrayName = new DataType[n];
 *
 * Input Format
 *  Input from stdin is handled by the locked code in the editor;
 *  you simply need to write your functions to meet the specifications of the problem statement above.
 *
 *  Output Format
 *  Output to stdout is handled for you. Your initialize function must return a pointer to an Available_Workshops object.
 *  Your CalculateMaxWorkshops function must return maximum number of non-overlapping workshops the student can attend.
 */
struct Workshop {
    int start_time;
    int duration;
    int end_time;
};

struct Available_Workshops {
    int n;
    std::vector<Workshop> Available_Workshops;
};

Available_Workshops *initialize(int start_time[], int duration[], int n) {
    Available_Workshops *avWorkshops = new Available_Workshops;
    avWorkshops->n = n;
    Workshop workshop;
    for (int i = 0; i < n; i++) {
        workshop.duration = duration[i];
        workshop.start_time = start_time[i];
        workshop.end_time = start_time[i] + duration[i];
        avWorkshops->Available_Workshops.push_back(workshop);
    }
    return avWorkshops;
}

int CalculateMaxWorkshops(Available_Workshops *ptr) {
    //sort by increasing of ending times
    std::sort(ptr->Available_Workshops.begin(), ptr->Available_Workshops.end(), [](Workshop &a, Workshop &b) {
        return a.end_time < b.end_time;
    });

    //count numbers of compatible intervals
    int count = 0;
    int current_end_time = 0;
    for(Workshop& ws: ptr->Available_Workshops)
    {
        if(ws.start_time >= current_end_time)
        {
            current_end_time = ws.end_time;
            count++;
        }
    }
    return count;
}

void call_workshop() {
    int n; // number of workshops
    std::cin >> n;
    // create arrays of unknown size n
    int *start_time = new int[n];
    int *duration = new int[n];

    for (int i = 0; i < n; i++) {
        std::cin >> start_time[i];
    }
    for (int i = 0; i < n; i++) {
        std::cin >> duration[i];
    }

    Available_Workshops *ptr;
    ptr = initialize(start_time, duration, n);
    std::cout << CalculateMaxWorkshops(ptr) << std::endl;
}