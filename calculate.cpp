#include "matrix.h"
#include "poly.h"

int main(){
    Matrix<Poly> coeff_matrix(3,3);
    coeff_matrix(1,1)="1,3",coeff_matrix(1,2)="1,0",coeff_matrix(1,3)="1,-1";
    coeff_matrix(2,1)="1,0",coeff_matrix(2,2)="0,1",coeff_matrix(2,3)="0,1";
    coeff_matrix(3,1)="3,3",coeff_matrix(3,2)="1,-1",coeff_matrix(3,3)="-2";
    std::cout<<coeff_matrix<<std::endl;
    coeff_matrix.ElementaryOp(3,1,2,3);
    std::cout<<"After change:\n"<<coeff_matrix<<std::endl;
    std::cout<<"The Det is "<<Det(coeff_matrix)<<std::endl;
    //std::cout<<"SubMatrix(1,1)\n"<<coeff_matrix.GetSubMatrix(1,1)<<std::endl;
    return 0;
}