#ifndef __MATRIX_H__
#define __MATRIX_H__

#include <iostream>
#include <cmath>

template<typename T>
class Matrix;

template <typename T>
std::ostream &operator<<(std::ostream &out,const Matrix<T> &matrix);

template<typename T>
class Matrix{
    private:
        int row_;int col_;
        T* elements_;
        static const int INTERCHANGE_ROW=1;
        static const int MULTIPLY_ROW=2;
        static const int ADD_ROW=3;
        static const int INTERCHANGE_COL=4;
        static const int MULTIPLY_COL=5;
        static const int ADD_COL=6;
    public:
        Matrix():row_(0),col_(0){}
        Matrix(int r,int c):row_(r),col_(c){
            elements_=new T [row_*col_];
        }
        Matrix(const Matrix& other);
        Matrix(Matrix &&other);
        Matrix& operator=(const Matrix& other);
        Matrix& operator=(Matrix &&other);

        const T operator()(int x,int y) const;
        T &operator()(int x,int y);
        const int GetRowNumber() const{return row_;}
        const int GetColNumber() const{return col_;}
        friend std::ostream& operator<<<>(std::ostream& out,const Matrix<T> &matrix);

        const Matrix<T> GetSubMatrix(int pos_x,int pos_y) const;
        void ElementaryOp(int op_type,int op_index,int another_index=0,int constant=0);
};

template <typename T>
inline Matrix<T>::Matrix(const Matrix &other){
    this->col_=other.col_,this->row_=other.row_;
    this->elements_=new T [row_*col_];
    for(int i=0;i<row_;i++){
        for(int j=0;j<col_;j++){
            this->elements_[i*col_+j]=other.elements_[i*col_+j];
        }
    }
}
template <typename T>
inline Matrix<T>::Matrix(Matrix &&other){
    this->col_=other.col_,this->row_=other.row_;
    this->elements_=other.elements_;
    other.col_=0,other.row_=0;
    other.elements_=nullptr;
}
template <typename T>
Matrix<T>& Matrix<T>::operator=(const Matrix& other){
    if(this->elements_)delete[] this->elements_;
    this->col_=other.col_,this->row_=other.row_;
    this->elements_=new T [row_*col_];
    for(int i=0;i<row_;i++){
        for(int j=0;j<col_;j++){
            this->elements_[i*col_+j]=other.elements_[i*col_+j];
        }
    }
}
template <typename T>
Matrix<T>& Matrix<T>::operator=(Matrix&& other){
    if(this->elements_)delete[] this->elements_;
    this->col_=other.col_,this->row_=other.row_;
    this->elements_=other.elements_;
    other.col_=0,other.row_=0;
    other.elements_=nullptr;
}

template <typename T>
const T Matrix<T>::operator()(int x, int y) const
{
    x--,y--;
    if(x<0||x>=row_){
        printf("Error: asking for invalid matrix elements\n");
        return 0;
    }
    return elements_[col_*x+y];
}

template <typename T>
T& Matrix<T>::operator()(int x,int y){
    x--,y--;
    if(x<0||x>=row_){
        printf("Error: setting invalid matrix elements\n");
        return elements_[0];
    }
    return elements_[col_*x+y];
}

template <typename T>
const Matrix<T> Matrix<T>::GetSubMatrix(int pos_x,int pos_y)const
{
    Matrix<T> ans(row_-1,col_-1);
    int x=0,y=0;
    for(int i=1;i<row_;i++){
        y=0;
        if(i==pos_x)x++;
        for(int j=1;j<col_;j++){
            if(j==pos_y)y++;
            ans(i,j)=elements_[x*row_+y];
            y++;
        }
        x++;
    }
    return ans;
}

template <typename T>
inline void Matrix<T>::ElementaryOp(int op_type, int op_index, int another_index, int constant){
    switch (op_type)
    {
    case INTERCHANGE_ROW:{
        if (op_index <= 0 || op_index > row_){
            printf("Error: elementary row operation can't execute on %d row\n", op_index);
            return;
        }
        if(another_index<=0||another_index>row_){
            printf("Error: elementary interchange operation can't execute on %d row\n",another_index);
            return;
        }
        op_index--,another_index--;
        for(int i=0;i<col_;i++){
            T tmp=elements_[op_index*col_+i];
            elements_[op_index*col_+i]=elements_[another_index*col_+i];
            elements_[another_index*col_+i]=tmp;
        }
        break;
    }
    case MULTIPLY_ROW:{
        if (op_index <= 0 || op_index > row_){
            printf("Error: elementary row operation can't execute on %d row\n", op_index);
            return;
        }
        op_index--;
        for(int i=0;i<col_;i++){
            elements_[op_index*col_+i]=constant * elements_[op_index*col_+i];
        }
        break;
    }
    case ADD_ROW:{
        if (op_index <= 0 || op_index > row_){
            printf("Error: elementary row operation can't execute on %d row\n", op_index);
            return;
        }
        if(another_index<=0||another_index>row_){
            printf("Error: elementary interchange operation can't execute on %d row\n",another_index);
            return;
        }
        op_index--,another_index--;
        for(int i=0;i<col_;i++){
            elements_[op_index*col_+i]=constant * elements_[another_index*col_+i]+elements_[op_index*col_+i];
        }
        break;
    }    
    
    default:{
        printf("Invalid operation type\n");
        break;
    }
    }

}

template <typename T>
std::ostream &operator<<(std::ostream& out,const Matrix<T>& matrix)
{
    int row=matrix.GetRowNumber();
    int col=matrix.GetColNumber();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            out<<matrix(i+1,j+1)<<" ";
        }
        out<<std::endl;
    }
    return out;
}

template<typename T>
T Det(const Matrix<T> &matrix){
    int col=matrix.GetColNumber(),row=matrix.GetRowNumber();
    if (col != row){
        printf("Error:can't calculate determinant\n");
        return matrix(1,1);
    }
    if (col == 1){
        return matrix(1,1);
    }
    T det = matrix(1,1) * Det(matrix.GetSubMatrix(1, 1));
    for (int i = 2; i <= col; i++){
        det = det+pow(-1, 1 + i) *matrix(1,i) * Det(matrix.GetSubMatrix(1, i));
    }
    return det;
}

#endif