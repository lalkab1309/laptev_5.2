#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>

class newintegral {
public:
    using size_t = unsigned int;
    using value_t = float;
    using Iterator = value_t*;

    newintegral(const vector<double>& val, const vector<double>& elem)
        : funcval(val), arrayelem(elem) {
        n = val.size() - 1; 
        step = elem[n] - elem[0]; 
    }

    newintegral(size_t s) : newsize(s) {
        if (s > getMaxSize()) {
            throw range_error("invalid array size");
        }
        newdata = new value_t[s];
    }

    newintegral(size_t size, value_t default_value) : newintegral(size) {
        for (auto& element : *this) {
            element = default_value;
        }
    }

    double calculateLeftRectangle()
    {
        double newintegral = 0;

        for (int i = 0; i < n; ++i)
            newintegral += funcval[i] * (arrayelem[i + 1] - arrayelem[i]);

        return newintegral;
    }

    double calculateMiddleRectangle()
    {
        double newintegral = 0;

        for (int i = 0; i < n; ++i)
        {
            double help = (funcval[i] + funcval[i + 1]) / 2.0;

            newintegral += help * (arrayelem[i + 1] - arrayelem[i]);
        }

        return newintegral;
    }

    double calculateRightRectangle()
    {
        double newintegral = 0;

        for (int i = 0; i < n; ++i)
            newintegral += funcval[i + 1] * (arrayelem[i + 1] - arrayelem[i]);

        return newintegral;
    }

    double calculateTrapezia()
    {
        double newintegral = 0;

        for (int i = 0; i < n; ++i)
            newintegral += (funcval[i] + funcval[i + 1]) * (arrayelem[i + 1] - arrayelem[i]) / 2;
        return newintegral;
    }

    double calculateSimpson()
    {
        double newintegral = 0;

        for (int i = 0; i < n; i += 2)
        {
            double step = arrayelem[i + 2] - arrayelem[i];

            newintegral += (funcval[i] + 4 * funcval[i + 1] + funcval[i + 2]) * step / 6;
        }
        return newintegral;
    }

    double calculateNewton()
    {
        double newintegral = 0;

        if (n % 3 == 0)
        {
            for (int i = 0; i < n; i += 3)
                newintegral += (funcval[i] + 3 * funcval[i + 1] + 3 * funcval[i + 2] + funcval[i + 3]) * (arrayelem[i + 3] - arrayelem[i]) / 8;
        }
        return newintegral;
    }

    void displayInput() {
        
        std::cout << endl;
        std::cout << "input = argument ";

        for (int i = 0; i < arrayelem.size(); ++i)
            std::cout << arrayelem[i] << " ";

        std::cout << '\n';

        std::cout << "function ";

        for (int i = 0; i < funcval.size(); ++i)
            std::cout << funcval[i] << " ";

        std::cout << '\n';
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
        std::oss << static_cast<int>(v);
    else
        std::oss << fixed << setprecision(1) << v;

    return oss.str();
}

int main() {
    int arrsize;

    std::cin >> arrsize;

    vector<double> elem(arrsize);

    vector<double> val(arrsize);

    for (int i = 0; i < arrsize; ++i)
        std::cin >> elem[i];

    for (int i = 0; i < arrsize; ++i)
        std::cin >> val[i];

    newintegral findnewintegral(val, elem);

    findnewintegral.displayInput();

    double leftRectanglenewintegral = findnewintegral.calculateLeftRectangle();
    double middleRectanglenewintegral = findnewintegral.calculateMiddleRectangle();
    double rightRectanglenewintegral = findnewintegral.calculateRightRectangle();
    double trapezianewintegral = findnewintegral.calculateTrapezia();
    double simpsonnewintegral = findnewintegral.calculateSimpson();
    double newtonnewintegral = findnewintegral.calculateNewton();

    std::cout << "lev priam= " << transform(leftRectanglenewintegral) << "\n";
    std::cout << "sr priam= " << transform(middleRectanglenewintegral) << "\n";
    std::cout << "prav priam= " << transform(rightRectanglenewintegral) << "\n";
    std::cout << "trapeciy= " << transform(trapezianewintegral) << "\n";
    std::cout << "Simpson= " << transform(simpsonnewintegral) << "\n";
    std::cout << "Newton " << transform(newtonnewintegral) << "\n";

    return 0;
}
