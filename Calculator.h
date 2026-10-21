#ifndef CALCULATOR_H
#define CALCULATOR_H

class Calculator
{
private:
    double a;
    double b;

public:
    Calculator(double first, double second)
    {
        a = first;
        b = second;
    }

    double add()
    {
        return a + b;
    }

    double subtract()
    {
        return a - b;
    }

    double multiply()
    {
        return a * b;
    }

    // The provided main checks that B is not zero before calling this.
    double divide()
    {
        return a / b;
    }
	
	double square()
	{
		return a*a;
	}

    // Pair B works below.
    // Keep both methods when merging.
    double absolute()
    {
        if (a < 0)
        {
            a = a * -1;
        }
        return a;
    double negate() {
        if (a == 0) {
            return 0;
        }
        return -a;
    }

    // Pair C works below.
    // Keep both methods when merging.
    double maximum(){
        return (a > b)? a : b;
    }

    double percentage()
    {
        return a * (b / 100);
    }
    // OTHER_METHODS: students 07 through 13 add their methods above this line.
	
};

#endif
