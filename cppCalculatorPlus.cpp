#include <iostream>
#include <string>
#include <cmath>
#include <cfloat>

using namespace std;

// ---------- Version ----------
struct Version {
    int major = 0, minor = 0, patch = 0;
    std::string suffix;

    std::string str() const {
        std::string s = std::to_string(major) + "." +
                        std::to_string(minor) + "." +
                        std::to_string(patch);
        if (!suffix.empty()) s += "-" + suffix;
        return s;
    }
};

string preWrd;
string suffWrd;
char ender = '!';

void senMaker() {
    while (true) {
        cout << "Enter a word [or 'quit' to exit]: ";
        if (!(cin >> preWrd) || preWrd == "quit") break;

        cout << "Enter another word: ";
        if (!(cin >> suffWrd)) break;

        if (preWrd != suffWrd)
            cout << preWrd << " " << suffWrd << ender << "\n";
        else
            cout << "Enter same word twice\n";
    }

}
char op;
double a, b, res;

void calculate() {
    cout << "Enter an operator (+, -, *, /): ";
    cin >> op;

    cout << "Enter two numbers: ";
    cin >> a >> b;

    if (op == '+')
        res = a + b;
    else if (op == '-')
        res = a - b;
    else if (op == '*')
        res = a * b;
    else if (op == '/')
        res = a / b;
    else {
        cout << "Error! Operator is not correct";
        res = -DBL_MAX;
    }

    if (res != -DBL_MAX)
        cout << "Result: " << res;

}

int main() {
    Version v{0, 0, 0, "dev"};
    cout << (v.suffix == "dev" ? "in dev version\n" : "not in dev version\n");
    cout << "Randon C++ Project: " << v.str() << "\n";
    char usrOption;
    cout << "What do you want to do to?" << endl;
    cout << "|a)Hello Word |b)Calculate |\n";
    cin >> usrOption;
    switch (usrOption) {
        case 'a':
            senMaker();
            break;
        case 'b':
            calculate();
            break;
        case 'q':
            return 0;
        default:
            cout << "Invalid option" << endl;

    }

   
    return 0;
}
