#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator {
private:
    double a;
    double b;

public:
    Calculator(double first, double second) {
        a = first;
        b = second;
    }

    double add() {
        return a + b;
    }

    double subtract() {
        return a - b;
    }

    double multiply() {
        return a * b;
    }

    // The provided main checks that B is not zero before calling this.
    double divide() {
        return a / b;
    }

    // PAIR_A: students 01 and 02 replace this comment with their own method.

    // Pair B works below.
    // Keep both methods when merging.
    // PAIR_B: students 03 and 04 replace this comment with their own method.

    // Pair C works below.
    // Keep both methods when merging.
    // PAIR_C: students 05 and 06 replace this comment with their own method.

    double percentage()
    {
        return a * (b / 100);
    }
    // OTHER_METHODS: students 07 through 13 add their methods above this line.
};

#endif
