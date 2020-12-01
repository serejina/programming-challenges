//
// Created by masha on 11/15/20.
//

#ifndef CPP_PRACTICE_EXCEPTIONHANDLING_H
#define CPP_PRACTICE_EXCEPTIONHANDLING_H

/*
 * Cpp exception handling
 * You are required to extend the existing code so that it handles std::invalid_argument exception properly.
 * More specifically, you have to extend the implementation of process_input function.
 * It takes integer n as an argument and has to work as follows:
 *  1. It calls function largest_proper_divisor(n).
 *  2. If this call returns a value without raising an exception,
 *     it should print in a single line result=d where d is the returned value.
 *  3. Otherwise, if the call raises a std::invalid_argument exception,
 *     it has to print in a single line the string representation of the raised exception, i.e. its message.
 *  4. Finally, no matter if the exception is raised or not,
 *     it should print in a single line returning control flow to caller after any other previously printed output.
 * To keep the code quality high, you are advised to have exactly one line printing returning control flow
 * to caller in the body of process_input function.
 * Input Format
 *  The input is read by the provided locked code template. In the only line of the input, there is a single integer n,
 *  which is going to be the argument passed to function process_input.
 * Output Format
 *  The output should be produced by function process_input as described in the statement.
 */
int largest_proper_divisor(int n) {
    if (n == 0) {
        throw std::invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw std::invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n / 2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

void process_input(int n) {
    try {
        int d = largest_proper_divisor(n);
        std::cout << "result=" << d << std::endl;
    }
    catch (std::invalid_argument &ai) {
        std::cout << ai.what() << std::endl;
    }
    std::cout << "returning control flow to caller" << std::endl;
}

int call_process_input() {
    int n;
    std::cin >> n;
    process_input(n);
    return 0;
}


#endif //CPP_PRACTICE_EXCEPTIONHANDLING_H
