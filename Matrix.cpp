#include "Matrix.hpp"

namespace zich
{
    Matrix::Matrix(const vector<double> nums, const int n, const int m)
    {
        if (n <= 0 || m <= 0){__throw_invalid_argument("Enter positive args");}
        this->data = nums;
        this->rows = n;
        this->cols = m;
    }
    Matrix Matrix::operator+(const Matrix &a)
    {
        if (this->rows != a.rows || this->cols != a.cols){__throw_runtime_error("Sizes aren't equal!");}        
        size_t len = (size_t )(this->rows * this->cols);
        vector<double> DATA;
        DATA.resize(len);
        for (size_t  i = 0; i < len; i++)
        {
            DATA[i] = this->data[i] + a.data[i];
            
        }
        return Matrix(DATA, this->rows , this->cols);
    }
    Matrix Matrix::operator++(const int n)
    {
        Matrix ans=*this;
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                data[(size_t)(i * (size_t)this->cols + j)] += 1;
            }
        }
        return ans;
    }
    Matrix Matrix::operator+=(const Matrix &a)
    {
        if (this->rows != a.rows || this->cols != a.cols){__throw_runtime_error("Sizes aren't equal!");} 
        for(size_t i=0; i<this->rows; i++)
        {
            for(size_t j=0; j<this->cols;j++)
            {
                this->data[(size_t)(i * (size_t)this->cols + j)]+=a.data[(size_t)(i * (size_t)this->cols + j)];
            }
        }
        return *this;
    }
    Matrix Matrix::operator-(const Matrix &a)
    {
       if (this->rows != a.rows || this->cols != a.cols){__throw_runtime_error("Sizes aren't equal!");}        
        size_t len = (size_t )(this->rows * this->cols);
        vector<double> DATA;
        DATA.resize(len);
        for (size_t  i = 0; i < len; i++)
        {
            DATA[i] = this->data[i] - a.data[i];
            
        }
        return Matrix(DATA, this->rows , this->cols);
    }
    Matrix Matrix::operator--(const int n)
    {
        Matrix ans=*this;
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                data[(size_t)(i * (size_t)this->cols + j)] -= 1;
            }
        }
        return ans;
    }
    Matrix Matrix::operator-=(const Matrix &a)
    {
        if (this->rows != a.rows || this->cols != a.cols){__throw_runtime_error("Sizes aren't equal!");} 
        for(size_t i=0; i<this->rows; i++)
        {
            for(size_t j=0; j<this->cols;j++)
            {
                this->data[(size_t)(i * (size_t)this->cols + j)]-=a.data[(size_t)(i * (size_t)this->cols + j)];
            }
        }
        return *this;
    }
    double Matrix::sum() const
    {
        double sum = 0;
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                sum += data[(size_t)(i * (this->cols) + j)];
            }
        }
        return sum;
    }
    bool Matrix::operator>(const Matrix &a)
    {
        if((double)this->sum()>(double)a.sum()){return true;}
        return false;
    }
    bool Matrix::operator<(const Matrix &a)
    {
        if((double)this->sum()<(double)a.sum()){return true;}
        return false;
    }
    bool Matrix::operator==(const Matrix &a)
    {
        if (this->rows != a.rows || this->cols != a.cols){__throw_runtime_error("Sizes aren't equal!");}
        for(size_t i=0;i<this->rows;i++)
        {
            for(size_t j =0;j<this->cols;j++)
            {
                if(this->data[(size_t)(i * (size_t)(this->cols) + j)]!=a.data[(size_t)(i * (size_t)(this->cols) + j)]){return false;}
            }
        }
        return true;    
    }
    bool Matrix::operator!=(const Matrix &a)
    {
        if (this->rows != a.rows || this->cols != a.cols){__throw_runtime_error("Sizes aren't equal!");}
        for(size_t i=0;i<this->rows;i++)
        {
            for(size_t j =0;j<this->cols;j++)
            {
                if(this->data[(size_t)(i * (size_t)(this->cols) + j)]!=a.data[(size_t)(i * (size_t)(this->cols) + j)]){return true;}
            }
        }
        return false; 
    }
    bool Matrix::operator>=(const Matrix &a)
    {
        if (this->rows != a.rows || this->cols != a.cols){__throw_runtime_error("Sizes aren't equal!");}
        for(size_t i=0;i<this->rows;i++)
        {
            for(size_t j =0;j<this->cols;j++)
            {
                if(this->data[(size_t)(i * (size_t)(this->cols) + j)]<=a.data[(size_t)(i * (size_t)(this->cols) + j)]){return false;}
            }
        }
        return true;    
    }
    bool Matrix::operator<=(const Matrix &a)
    {
        if (this->rows != a.rows || this->cols != a.cols){__throw_runtime_error("Sizes aren't equal!");}
        for(size_t i=0;i<this->rows;i++)
        {
            for(size_t j =0;j<this->cols;j++)
            {
                if(this->data[(size_t)(i * (size_t)(this->cols) + j)]>a.data[(size_t)(i * (size_t)(this->cols) + j)]){return false;}
            }
        }
        return true;    
    }
    void Matrix::operator++()
    {
        for(size_t i=0;i<this->rows;i++)
        {
            for(size_t j =0;j<this->cols;j++)
            {
                this->data[(size_t)(i * (size_t)(this->cols) + j)]++;
            }
        }
    }
    void Matrix::operator--()
    {
        for(size_t i=0;i<this->rows;i++)
        {
            for(size_t j =0;j<this->cols;j++)
            {
                this->data[(size_t)(i * (size_t)(this->cols) + j)]--;
            }
        }
    }
    Matrix Matrix::operator*(const double a)
    {
        Matrix ans = *this;
        for (size_t i = 0; i < this->rows; i++)
        {
            for (size_t j = 0; j < this->cols; j++)
            {
                ans.data[(size_t)(i * (size_t)(this->cols) + j)] *= a;
            }
        }
        return ans;
    }
    double Matrix::mul(const int r, const int c, const Matrix &a)
    {
        double sum = 0;
        for (int i = 0; i < this->cols; i++)
        {
            sum += a.data[(size_t)(a.cols * i + c)]*this->data[(size_t)(this->cols * r + i)];
        }
        return sum;
    }
    Matrix Matrix::operator*(const Matrix &a)
    {
        if (this->cols != a.rows){__throw_runtime_error("Sizes aren't equal!");}
        vector<double> n;
        Matrix ans(n, this->rows, a.cols);
        for (int i = 0; i < ans.rows; i++)
        {
            for (int j = 0; j < ans.cols; j++)
            {
                ans.data[(size_t)(i * ans.cols + j)] = mul(i, j,a);
            }
        }
        return ans;
    }
    ostream &operator<<(ostream &o, const Matrix &a)
    {
        for (int i = 0; i < a.rows; i++)
        {
            o << '[';
            for (int j = 0; j < a.cols; j++)
            {
                o << a.data[(size_t)(a.cols * i + j)] << " ";
            }
            o << "]" << endl;
        }
        return o;
    }
    istream &operator>>(istream &o, Matrix &mat)
    {
        return o;
    }
    Matrix Matrix::operator-(Matrix &a)
    {
        return a *= -1;
    }
}
