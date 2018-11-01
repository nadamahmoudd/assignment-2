#include "ass2.h"
#include <iostream>

using namespace std;

Matrix::Matrix(int r,int c)
{
  row=r;
  col=c;
  data=new int* [row];

  for (int i = 0; i < row; i++)
    data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      data[i][j] = 0;

}
Matrix::Matrix(int r,int c,int num[])
{
   row = r;
  col = c;
  data = new int* [row];

  for (int i = 0; i < row; i++)
    data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      data[i][j] = num[i * col + j];

}
void Matrix::setrow(int r){
    row=r;
}
void Matrix::setcol(int c){
    col=c;
}
int Matrix::getrow(){
    return row;
}
int Matrix::getcol(){
    return col;
}
void Matrix::setdata (int num[]){
     data = new int* [row];

  for (int i = 0; i < row; i++)
    data[i] = new int [col];

  for (int i = 0; i < row; i++)
    for (int j = 0; j < col; j++)
      data[i][j] = num[i * col + j];

}

int** Matrix::getData(){
    return data;
}
///part1
Matrix Matrix::operator+(Matrix &ob2){
   if(row==ob2.row && col==ob2.col){
        Matrix ob3(row,col);
        for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    ob3.data[i][j]=data[i][j]+ob2.data[i][j];
                }
        }
   return ob3;
   }
   else{cout<<"Matrices have different dimensions"<<endl;}
}
Matrix Matrix::operator-(Matrix &ob2){
   if(row==ob2.row && col==ob2.col){
        Matrix ob3(row,col);
        for(int i=0;i<row;i++){
                for(int j=0;j<col;j++){
                    ob3.data[i][j]=data[i][j]-ob2.data[i][j];
                }
        }
   return ob3;
   }
   else{cout<<"Matrices have different dimensions"<<endl;}
}
Matrix Matrix::operator*(Matrix &ob2){
  Matrix ob3(row,col);
   if(col==ob2.row){
        for(int i=0;i<row;i++){
            for(int j=0;j<ob2.col;j++){
                for(int r=0;r<col;r++){
                    ob3.data[i][j]+=(data[i][r]*ob2.data[r][j]);
        }}}
    return ob3;;
   }
    else{cout<<"matrix1 columns not equal matrix2 rows"<<endl;}

}
Matrix Matrix::operator+ (int scalar){
    Matrix ob(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ob.data[i][j]=data[i][j]+scalar;
        }
    }
   return ob;
}
Matrix Matrix::operator- (int scalar){
    Matrix ob(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ob.data[i][j]=data[i][j]-scalar;
        }
    }
   return ob;
}
Matrix Matrix::operator* (int scalar){
    Matrix ob(row,col);
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            ob.data[i][j]=data[i][j]*scalar;
        }
    }
   return ob;
}
///part2
void Matrix::operator-= (int scalar){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
                data[i][j]=data[i][j]-scalar;
        }
    }
}
void Matrix::operator+= (int scalar){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
                data[i][j]=data[i][j]+scalar;
        }
    }
}
Matrix& Matrix::operator++ (){  //prefix
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
                data[i][j]=data[i][j]+1;
        }
    }

    return *this;
}
Matrix Matrix::operator++ (int){    //postfix
    Matrix ret(*this);
    ++(*this);
    return ret;    /// equivalent to return ++(*this);
}
Matrix& Matrix::operator-- (){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
                data[i][j]=data[i][j]-1;
        }
    }

    return *this;
}
Matrix Matrix::operator-- (int){
    Matrix ret(*this);
    --(*this);
    return ret;
}
void Matrix::operator+= ( Matrix &ob2 ){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            data[i][j]=data[i][j]+ob2.data[i][j];
        }
    }
}
void Matrix::operator-= ( Matrix &ob2 ){
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            data[i][j]=data[i][j]-ob2.data[i][j];
        }
    }
}
bool Matrix::operator!= (Matrix &ob2){
    int n=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if (data[i][j]== ob2.data[i][j])
                n++;
        }
     }
     if (n==(row*col )&& (row *col))
        return 0;
     else
        return 1;
}
///part3
bool Matrix::operator== ( Matrix &ob2){
    int n=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<col;j++){
            if (data[i][j] == ob2.data[i][j])
                n++;
        }
     }
     if (n==(row*col )&& n==(row *col))
        return 1;
     else
        return 0;
}
bool Matrix::isSymetric (){
    int n=0;
    for(int i=0;i<row;i++){
        for(int j=0;j<i;j++){
            if(data[i][j]!=data[j][i])
                n++;
        }
    }
    if (n==0)
        return 1;
    else
        return 0;

}

bool Matrix::isSquare (){
    if (row == col)
        return 1;
    else
        return 0;

}

bool Matrix::isIdentity ()
{
    int c=0;
    if(isSquare())
    {
        for(int i=0; i<row; i++)
        {
            for(int j=0 ; j<col; j++)
            {
                if( i==j && data[i][j]==1)
                    c++;
                if (data[i][j]==0 && i!=j)
                    c++;
            }
        }
    }

    if(c==row*col)
        return 1;
    else
        return 0;
}

Matrix Matrix::transpose()
{
    Matrix neww;
    neww.row=col;
    neww.col=row;
    neww.data = new int* [neww.row];

    for (int i = 0; i < neww.row; i++)
        neww.data[i] = new int [neww.col];

    for(int i=0; i<neww.row; i++)
    {
        for(int j=0; j<neww.col; j++)
        {
            neww.data[i][j]=data[j][i];
        }
    }
    return neww;
}

