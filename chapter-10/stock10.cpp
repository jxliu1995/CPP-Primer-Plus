// stock10.cpp --Stock class with constructors, deconstructor added
#include <iostream>
#include "stock10.h"

// constructors (verbose versions)
Stock::Stock()
{
    std::cout << "Default constructor called\n";
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}

Stock::Stock(const std::string & co, long n, double pr)
{
    std::cout << "Constructor using " << co << " called.\n";
    company = co;

    if (n < 0)
    {
        std::cout << "Number of shares can not be negative; "
                  << company << " shares set to be 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

// class deconstructor
Stock::~Stock()
{
    std::cout << "Bye, " << company << " !\n";
}

// other methods
void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares purchased can not be negative. "
                  << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        std::cout << "Number of shares sold can not be negative. "
                  << "Transaction is aborted.\n";
    }
    else if (num > shares)
    {
        std::cout << "You can not sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
    {
        share_val = price;
        set_tot();
    }

void Stock::show() const
{
    using std::cout;
    using std::endl;
    using std::ios_base;
    // set format
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);
    std::streamsize prec = cout.precision(3);

    cout << "Company: " << company << " Shares " << shares << endl;
    cout << " Share Price: $" << share_val;
    cout.precision(2);
    cout << " Total Worth: $" << total_val << std::endl;

    // restore original format
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}