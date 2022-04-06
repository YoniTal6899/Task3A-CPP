#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

using namespace std;

namespace zich
{
    class Matrix
    {
    private:
        vector<double> data;
        int rows;
        int cols;
        double sum() const;
        double mul(const int row, const int col, const Matrix &a);
    public:
        Matrix(vector<double> nums, int n, int m);

        friend Matrix operator+(const Matrix &a,const Matrix &b);
        friend Matrix operator+=(const Matrix &a,const Matrix &b);
        friend Matrix operator+(const Matrix &a);
        friend Matrix operator-(const Matrix &a,const Matrix &b);
        friend Matrix operator-=(const Matrix &a,const Matrix &b);
        friend Matrix operator-(const Matrix &a);
        friend bool operator>(const Matrix &a,const Matrix &b);
        friend bool operator<(const Matrix &a,const Matrix &b);
        friend bool operator==(const Matrix &a,const Matrix &b);
        friend bool operator!=(const Matrix &a,const Matrix &b);        
        friend bool operator>=(const Matrix &a,const Matrix &b);
        friend bool operator<=(const Matrix &a,const Matrix &b);
        friend Matrix operator++(const Matrix &a);//suffix
        friend Matrix operator--(const Matrix &a);//suffix
        friend Matrix& operator++(const Matrix &a,const int b);//prefix
        friend Matrix& operator--(const Matrix &a,const int b);//prefix
        friend Matrix operator*(const Matrix &a,const double n);
        friend Matrix operator*(const double n,const Matrix &a);
        friend Matrix operator*(const Matrix &a,const Matrix &b);
        friend Matrix operator*=(const Matrix &a,const double n);
        friend Matrix operator*=(const Matrix &a,const Matrix &b);
        friend ostream& operator<<(ostream &os, const Matrix &a);
        friend istream& operator>>(istream &os, Matrix &a);
    };

};