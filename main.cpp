#include <iostream>
#include "ass2.h"

using namespace std;

ostream& operator<< (ostream& out, Matrix mat){
    for(int i=0; i < mat.row; i++){
        for(int j=0; j < mat.col; j++)
            out << mat.data[i][j] << " ";
        out << endl;
    }
    out << endl;
}

istream& operator>> (istream& in, Matrix& mat){
    int row, col;
    in >> row >> col;
    mat.setrow(row);
    mat.setcol(col);
    for(int i=0; i < mat.row; i++){
        for(int j=0; j < mat.col; j++)
            in >> mat.data[i][j];
    }
}

int main()
{
    int data1 [] = {5,1,3,2,0,2,3,1,5};
    int data2 [] = {13,233,3,4,5,6};
    int data3 [] = {10,100,10,100,10,100,10,100,10};
    int data4 [] = {1, 0, 0, 1,5,6};
    Matrix ob1(3,3,data1);
    Matrix ob2(3,2,data2);
    Matrix ob3(3,3,data3);
    ob1-=ob3;
    cout<<ob1;
}

