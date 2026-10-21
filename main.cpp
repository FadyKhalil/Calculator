#include <fstream>
#include <iostream>
#include <string>
#include "Calculator.h"

// Provided display helper. Students do not need to edit this function.
void addRow(std::ofstream& page, const std::string& name, double result) {
    page << "<tr><td>" << name << "</td><td>" << result << "</td></tr>\n";
    std::cout << name << ": " << result << '\n';
}

int main() {
    double first;
    double second;

    std::cout << "Enter A and B (try 12 3): ";
    if (!(std::cin >> first >> second)) {
        std::cout << "Please run again and enter two numbers.\n";
        return 1;
    }

    Calculator calculator(first, second);
    std::ofstream page("calculator.html");
    if (!page) {
        std::cout << "Could not save calculator.html in this folder.\n";
        return 1;
    }

    // Provided HTML. C++ calculates the results; the browser displays them.
    page << "<!doctype html><html lang='en'><head><meta charset='utf-8'>"
            "<meta name='viewport' content='width=device-width, initial-scale=1'>"
            "<title>Our C++ Calculator</title><style>"
            "body{font:18px system-ui;background:#eef3f8;color:#17314c;margin:0;padding:32px}"
            "main{max-width:680px;margin:auto;background:white;padding:28px;border-radius:16px}"
            "h1{margin:8px 0}p{line-height:1.6}table{width:100%;border-collapse:collapse}"
            "th,td{text-align:left;padding:14px;border-bottom:1px solid #dce5ee}"
            "th{background:#e7f5ef}small{color:#48627a}"
            "</style></head><body><main><small>13 STUDENTS / ONE SHARED PROJECT</small>"
            "<h1>Our C++ Calculator</h1><p>Every new row is a teammate's contribution.</p>";
    page << "<p>A = <strong>" << first << "</strong> &nbsp; B = <strong>"
         << second << "</strong></p>";
    page << "<table><tr><th>Operation</th><th>Result</th></tr>\n";

    addRow(page, "Addition", calculator.add());
    addRow(page, "Subtraction", calculator.subtract());
    addRow(page, "Multiplication", calculator.multiply());
    if (second != 0) {
        addRow(page, "Division", calculator.divide());
    } else {
        page << "<tr><td>Division</td><td>Cannot divide by zero</td></tr>\n";
        std::cout << "Division: cannot divide by zero\n";
    }

    addRow(page, "Square", calculator.square());

    // return absolute value.
    // Keep both rows when merging.
    addRow(page, "student03's line calls:Absolute",calculator.absolute());
    addRow(page, "Negate", calculator.negate());

    // Pair C works below.
    // Keep both rows when merging.
    addRow(page, "Minimum", calculator.minimum());
    addRow(page,"maximum",calculator.maximum());

    addRow(page, "Percentage", calculator.percentage());
    addRow(page, "Sum of Squares", calculator.sumOfSquares());
    addRow(page, "Average", calculator.average());
    // OTHER_ROWS: students 07 through 13 add their rows above this line.

    page << "</table><p><small>Calculated in C++. To change the inputs, run the program again"
            " and refresh this page.</small></p></main></body></html>";
    page.close();
    std::cout << "\nOpen calculator.html from the program's working folder in your browser.\n";
    std::cout << "Run again with different inputs, then refresh the page.\n";
    return 0;
}
