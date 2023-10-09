#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>
using namespace std;

class Integral {
public:
    using size_t = unsigned int;
    using value_t = float;
    using Iterator = value_t*;

    Integral(const vector<double>& val, const vector<double>& elem)
        : funcval(val), arrayelem(elem) {
        n = val.size() - 1; 
        step = elem[n] - elem[0]; 
    }

    Integral(size_t s) : newsize(s) {
        if (s > getMaxSize()) {
            throw range_error("invalid array size");
        }
        newdata = new value_t[s];
    }

    Integral(size_t size, value_t default_value) : Integral(size) {
        for (auto& element : *this) {
            element = default_value;
        }
    }

    double calculateLeftRectangle()
    {
        double integral = 0;

        for (int i = 0; i < n; ++i)
            integral += funcval[i] * (arrayelem[i + 1] - arrayelem[i]);

        return integral;
    }

    double calculateMiddleRectangle()
    {
        double integral = 0;

        for (int i = 0; i < n; ++i)
        {
            double help = (funcval[i] + funcval[i + 1]) / 2.0;

            integral += help * (arrayelem[i + 1] - arrayelem[i]);
        }

        return integral;
    }

    double calculateRightRectangle()
    {
        double integral = 0;

        for (int i = 0; i < n; ++i)
            integral += funcval[i + 1] * (arrayelem[i + 1] - arrayelem[i]);

        return integral;
    }

    double calculateTrapezia()
    {
        double integral = 0;

        for (int i = 0; i < n; ++i)
            integral += (funcval[i] + funcval[i + 1]) * (arrayelem[i + 1] - arrayelem[i]) / 2;
        return integral;
    }

    double calculateSimpson()
    {
        double integral = 0;

        for (int i = 0; i < n; i += 2)
        {
            double step = arrayelem[i + 2] - arrayelem[i];

            integral += (funcval[i] + 4 * funcval[i + 1] + funcval[i + 2]) * step / 6;
        }
        return integral;
    }

    double calculateNewton()
    {
        double integral = 0;

        if (n % 3 == 0)
        {
            for (int i = 0; i < n; i += 3)
                integral += (funcval[i] + 3 * funcval[i + 1] + 3 * funcval[i + 2] + funcval[i + 3]) * (arrayelem[i + 3] - arrayelem[i]) / 8;
        }
        return integral;
    }

    void displayInput() {
        
        cout << endl;
        cout << "input = argument ";

        for (int i = 0; i < arrayelem.size(); ++i)
            cout << arrayelem[i] << " ";

        cout << '\n';

        cout << "function ";

        for (int i = 0; i < funcval.size(); ++i)
            cout << funcval[i] << " ";

        cout << '\n';
    }

    size_t
        getSize() const
    {
        return newsize;
    }
    static size_t getMaxSize()
    {
        return sizemax;
    }

    const Iterator begin() const
    {
        newdata;
    }
    const Iterator end() const
    {
        return newdata + newsize;
    }



private:
    double step;

    int n;
    std::vector<double> funcval;

    std::vector<double> arrayelem;


    double helpfunc(double x)
    {
        return x * x;
    }

    const static size_t sizemax = 10000;

    size_t newsize;

    value_t* newdata;
};

std::string transform(double v) {

    double help = numeric_limits<double>::epsilon() * 1000.0;

    ostringstream oss;

    if (std::abs(v - std::round(v)) < help)
        oss << static_cast<int>(v);
    else
        oss << fixed << setprecision(1) << v;

    return oss.str();
}

int main() {
    int arrsize;

    cin >> arrsize;

    vector<double> elem(arrsize);

    vector<double> val(arrsize);

    for (int i = 0; i < arrsize; ++i)
        cin >> elem[i];

    for (int i = 0; i < arrsize; ++i)
        cin >> val[i];

    Integral findIntegral(val, elem);

    findIntegral.displayInput();

    double leftRectangleIntegral = findIntegral.calculateLeftRectangle();
    double middleRectangleIntegral = findIntegral.calculateMiddleRectangle();
    double rightRectangleIntegral = findIntegral.calculateRightRectangle();
    double trapeziaIntegral = findIntegral.calculateTrapezia();
    double simpsonIntegral = findIntegral.calculateSimpson();
    double newtonIntegral = findIntegral.calculateNewton();

    std::cout << "lev priam= " << transform(leftRectangleIntegral) << "\n";
    std::cout << "sr priam= " << transform(middleRectangleIntegral) << "\n";
    std::cout << "prav priam= " << transform(rightRectangleIntegral) << "\n";
    std::cout << "trapeciy= " << transform(trapeziaIntegral) << "\n";
    std::cout << "Simpson= " << transform(simpsonIntegral) << "\n";
    std::cout << "Newton " << transform(newtonIntegral) << "\n";

    return 0;
}
