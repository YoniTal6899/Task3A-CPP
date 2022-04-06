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
        double mul(const int raw, const int col, const Matrix &a);
    public:
        Matrix(vector<double> nums, int n, int m);
        Matrix operator+(const Matrix &a);
        Matrix operator++(const int n);
        Matrix operator+=(const Matrix &a);
        Matrix operator-(const Matrix &a);
        Matrix operator--(const int n);
        Matrix operator-=(const Matrix &a);
        bool operator>(const Matrix &a);
        bool operator<(const Matrix &a);
        bool operator==(const Matrix &a);
        bool operator!=(const Matrix &a);        
        bool operator>=(const Matrix &a);
        bool operator<=(const Matrix &a);
        void operator++();
        void operator--();
        Matrix operator*(const double a);
        Matrix operator*(const Matrix &a);
        ostream &operator<<(ostream &os, const Matrix &a);
        istream &operator>>(istream &os, Matrix &mat);
        Matrix operator-(Matrix &a);
    };

};