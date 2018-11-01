#include <iostream>
#include <BigDecimalInt.h>

using namespace std;

ostream& operator<< (ostream& out, BigDecimalInt bInt){
    string str = "";

    if(!bInt.is_positive)
        str += '-';

    str += bInt.m_number;

    out << str << endl;
    return out;
}

int main()
{
    BigDecimalInt b1("123"), b2("123");

    cout << b1 + b2 << endl << b1 - b2 << endl;
    return 0;
}
