#include <iostream>
#include <cmath>
#include <vector>
#include <string>


class EuropeanOption {
public:
    std::string contractType; // "call" or "put"
    std::string strategy; // "long" or "short"
    double strikePrice;
    int expirationDay;
    int numberOfContracts;
    double underlyingPrice = 5000; // Fixed underlying S&P 500 index price
    double annualReturn = 0.05; // Typical return
    double volatility = 0.20; // Standard deviation (volatility)
    double riskFreeRate = 0.02; // Simplified risk-free rate

    EuropeanOption(std::string type, std::string strat, double strike, int expDay, int numContracts)
    : contractType(type), strategy(strat), strikePrice(strike), expirationDay(expDay), numberOfContracts(numContracts) {}

    void calculateMetrics();


};

void EuropeanOption::calculateMetrics() {
    double mean = 0.0, standardDeviation = 0.0, variance = 0.0;
        
        // Simplified Mean Calculation
        mean = annualReturn * (strategy == "long" ? 1.1 : 0.9); // Adjust mean based on strategy

        // Standard Deviation and Variance (Simplified to use underlying's volatility)
        standardDeviation = volatility;
        variance = pow(standardDeviation, 2);

        // Display the results
        std::cout << "Mean (Expected Return): " << mean * 100 << "%" << std::endl;
        std::cout << "Standard Deviation (Volatility): " << standardDeviation * 100 << "%" << std::endl;
        std::cout << "Variance: " << variance << std::endl;
        
    double varianceThreshold=5.804110e+06;  
    if (variance > varianceThreshold) {
    std::cout << "Variance exceeds threshold, operation halted." << std::endl;
    // Implement halting mechanism or warning as needed
}
}

int main() {
    std::string contractType, strategy;
    double strikePrice;
    int expirationDay, numberOfContracts;

    // Prompting user for inputs
    std::cout << "Enter contract type (put/call): ";
    std::cin >> contractType;
    std::cout << "Enter strategy (long/short): ";
    std::cin >> strategy;
    std::cout << "Enter strike price (multiple of 100, up to 10000): ";
    std::cin >> strikePrice;
    std::cout << "Enter expiration day: ";
    std::cin >> expirationDay;
    std::cout << "Enter number of contracts: ";
    std::cin >> numberOfContracts;

    // Validation of user inputs could be added here
    // For example, ensuring strike price is a multiple of 100 and within the valid range

    // Creating an instance of EuropeanOption with user inputs
    EuropeanOption option(contractType, strategy, strikePrice, expirationDay, numberOfContracts);

    // Calculating and displaying the metrics
    option.calculateMetrics();

    return 0;
}