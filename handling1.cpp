#include <iostream>
#include <string>

class ExceptionHandler {
public:
    void divideAndPrint(int numerator, int denominator) {
        try {
            if (denominator == 0) {
                throw "Division by zero is not allowed.";
            }
            int result = numerator / denominator;
            std::cout << "Result of division: " << result << std::endl;
        }
        catch (const char* errorMessage) {
            handleException(errorMessage);
        }
        catch (...) {
            handleException("An unknown exception occurred.");
        }
    }

    void handleException(const char* errorMessage) {
        std::cerr << "Exception: " << errorMessage << std::endl;
    }
};

int main() {
    ExceptionHandler handler;

    try {
        handler.divideAndPrint(10, 2);     // Valid division
        handler.divideAndPrint(5, 0);      // Division by zero
        handler.divideAndPrint(15, 3);     // Valid division
        handler.divideAndPrint(12, -4);    // Valid division
    }
    catch (std::exception& e) {
        std::cerr << "Standard exception caught: " << e.what() << std::endl;
    }

    return 0;
}

