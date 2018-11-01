#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt (string decStr){
    if(decStr[0] == '-'){
        is_positive = false;
        m_number = decStr;
        m_number.erase(0);
    }
    else{
        m_number = decStr;
        is_positive = true;
    }
}
BigDecimalInt::BigDecimalInt (int decInt){
    if(decInt < 0)
        is_positive = false;
    else
        is_positive = true;

    m_number = to_string(decInt);
}

BigDecimalInt BigDecimalInt::operator+ (BigDecimalInt anotherDec){
    if(is_positive != anotherDec.is_positive){
        return ((*this) - anotherDec);
    }

    string str1 = m_number, str2 = anotherDec.m_number;

    if (str1.length() > str2.length())
        swap(str1, str2);

    // Take an empty string for storing result
    string str = "";

    // Calculate lenght of both string
    int n1 = str1.length(), n2 = str2.length();
    int diff = n2 - n1;

    // Initialy take carry zero
    int carry = 0;

    // Traverse from end of both strings
    for (int i=n1-1; i>=0; i--)
    {
        // Do school mathematics, compute sum of
        // current digits and carry
        int sum = ((str1[i]-'0') +
                   (str2[i+diff]-'0') +
                   carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining digits of str2[]
    for (int i=n2-n1-1; i>=0; i--)
    {
        int sum = ((str2[i]-'0')+carry);
        str.push_back(sum%10 + '0');
        carry = sum/10;
    }

    // Add remaining carry
    if (carry)
        str.push_back(carry+'0');

    // reverse resultant string
    reverse(str.begin(), str.end());

    BigDecimalInt ret(str);
    return ret;
}

string complement(string number)
{
    for (int i=0 ; i < number.length() ; i++ )
        if (number[i] != '.')
            number[i] = '9' - number[i] + '0';

    return number;
}

bool isSmaller(string str1, string str2)
{
    // Calculate lengths of both string
    int n1 = str1.length(), n2 = str2.length();

    if (n1 < n2)
    return true;
    if (n2 < n1)
    return false;

    for (int i=0; i<n1; i++)
    if (str1[i] < str2[i])
        return true;
    else if (str1[i] > str2[i])
        return false;

    return false;
}

void rem_Lead_Zeros(string& num){
    reverse(num.begin(), num.end());
    for(int i = num.length() - 1; i > 0; i--){
        if(!num[i])
            num.pop_back();
        else break;
    }
    reverse(num.begin(), num.end());
}

BigDecimalInt BigDecimalInt::operator- (BigDecimalInt anotherDec){
    bool sign = 0;
    string str1 = m_number, str2 = anotherDec.m_number;

    if (isSmaller(str1, str2))
        swap(str1, str2), sign = 1;

    // Take an empty string for storing result
    string str = "";

    // Calculate length of both string
    int n1 = str1.length(), n2 = str2.length();

    // Reverse both of strings
    reverse(str1.begin(), str1.end());
    reverse(str2.begin(), str2.end());

    int carry = 0;

    // Run loop till small string length
    // and subtract digit of str1 to str2
    for (int i=0; i<n2; i++)
    {
        // Do school mathematics, compute difference of
        // current digits

        int sub = ((str1[i]-'0')-(str2[i]-'0')-carry);

        // If subtraction is less then zero
        // we add then we add 10 into sub and
        // take carry as 1 for calculating next step
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    // subtract remaining digits of larger number
    for (int i=n2; i<n1; i++)
    {
        int sub = ((str1[i]-'0') - carry);

        // if the sub value is -ve, then make it positive
        if (sub < 0)
        {
            sub = sub + 10;
            carry = 1;
        }
        else
            carry = 0;

        str.push_back(sub + '0');
    }

    if(sign)
        str += '-';

    // reverse resultant string
    reverse(str.begin(), str.end());

    rem_Lead_Zeros(str);

    BigDecimalInt ret(str);
    return ret;
}
