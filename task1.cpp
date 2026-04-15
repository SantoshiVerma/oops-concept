#include <iostream>
#include <vector>
using namespace std;

class Account
{
private:
  int accNo;
  string name;
  double balance;
  vector<string> history;

public:
  // Constructor
  Account(int a, string n, double b)
  {
    accNo = a;
    name = n;
    balance = b;
    history.push_back("Account created with balance: " + to_string(b));
  }

  // Deposit
  void deposit(double amount)
  {
    if (amount <= 0)
    {
      throw "Invalid deposit amount!";
    }
    balance += amount;
    history.push_back("Deposited: " + to_string(amount));
  }

  // Withdraw
  void withdraw(double amount)
  {
    if (amount <= 0)
    {
      throw "Invalid withdraw amount!";
    }
    if (amount > balance)
    {
      throw "Insufficient balance!";
    }
    balance -= amount;
    history.push_back("Withdrawn: " + to_string(amount));
  }

  // Show Details
  void show()
  {
    cout << "\nAccount No: " << accNo;
    cout << "\nName: " << name;
    cout << "\nBalance: " << balance << endl;
  }

  // Transaction History
  void showHistory()
  {
    cout << "\nTransaction History:\n";
    for (string h : history)
    {
      cout << "- " << h << endl;
    }
  }
};

int main()
{
  Account acc1(101, "Santoshi", 1000);

  try
  {
    acc1.deposit(500);
    acc1.withdraw(200);
    acc1.withdraw(2000); // error
  }
  catch (const char *msg)
  {
    cout << "Error: " << msg << endl;
  }

  acc1.show();
  acc1.showHistory();

  return 0;
}