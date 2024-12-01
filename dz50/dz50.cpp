#include <iostream>
#include <string>

class Account {
private:
    std::string lastName;
    std::string accountNumber;
    double interestRate;
    double deductionRate;
    double balance;
    static int accountCount;

public:

    Account()
        : lastName("Unknown"), accountNumber("00000000"), interestRate(0.0), deductionRate(0.0), balance(0.0) {
        accountCount++;
    }

    Account(const std::string& lastName, const std::string& accountNumber, double interestRate, double deductionRate, double balance)
        : lastName(lastName), accountNumber(accountNumber), interestRate(interestRate), deductionRate(deductionRate), balance(balance) {
        accountCount++;
    }

    ~Account() {
        accountCount--;
    }

    std::string getLastName() const {
        return lastName;
    }

    std::string getAccountNumber() const {
        return accountNumber;
    }

    double getInterestRate() const {
        return interestRate;
    }

    double getDeductionRate() const {
        return deductionRate;
    }

    double getBalance() const {
        return balance;
    }

    void applyInterest() {
        balance += balance * (interestRate / 100.0);
    }

    void withdraw(double amount) {
        double totalDeduction = amount + (amount * (deductionRate / 100.0));
        if (totalDeduction <= balance) {
            balance -= totalDeduction;
        }
        else {
            std::cerr << "Error" << std::endl;
        }
    }

    static int getAccountCount() {
        return accountCount;
    }

    void printInfo() const {
        std::cout << "Account Owner: " << lastName << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Interest Rate: " << interestRate << "%" << std::endl;
        std::cout << "Deduction Rate: " << deductionRate << "%" << std::endl;
        std::cout << "Balance: " << balance << " UAH" << std::endl;
    }
};

int Account::accountCount = 0;

int main() {
    Account account1("Ivanov", "12345678", 5.0, 1.5, 1000.0);
    Account account2("Petrov", "87654321", 3.0, 2.0, 500.0);

    account1.printInfo();
    account2.printInfo();

    std::cout << "Total accounts created: " << Account::getAccountCount() << std::endl;

    account1.applyInterest();
    account1.withdraw(200);

    std::cout << "\nAfter applying interest and withdrawal:\n";
    account1.printInfo();

    std::cout << "Total accounts created: " << Account::getAccountCount() << std::endl;
}
