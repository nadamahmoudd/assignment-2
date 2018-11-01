#ifndef ASS2_H
#define ASS2_H

#include <iostream>

using namespace std;

class Matrix
{
    friend ostream& operator<< (ostream&, Matrix);
    friend istream& operator>> (istream&, Matrix&);

    public:
Matrix(){};
Matrix(int r,int c);
Matrix(int r,int c,int num[]);
void setrow(int r);
void setcol(int c);
int getrow();
int getcol();
void setdata (int num[]);
int** getData();
///part1
Matrix operator+(Matrix &ob2);
Matrix operator-(Matrix &ob2);
Matrix operator*(Matrix &ob2);
Matrix operator+ (int scalar);
Matrix operator- (int scalar);
Matrix operator* (int scalar);
///part2
void operator-= (int scalar);
void operator+= (int scalar);
Matrix& operator++ ();  //prefix
Matrix operator++ (int);    //postfix
Matrix& operator-- ();
Matrix operator-- (int);
void operator+= ( Matrix &ob2 );
void operator-= ( Matrix &ob2 );
///part3
bool operator!= (Matrix &ob2);
bool operator== ( Matrix &ob2);
bool isSymetric ();
bool isSquare ();
bool isIdentity ();
Matrix transpose();

    protected:

    private:
    int** data;       // Pointer to 2-D array that will simulate matrix
    int row, col;
};

#endif // MATRIX_H

