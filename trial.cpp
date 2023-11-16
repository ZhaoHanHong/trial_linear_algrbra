#include "poly.h"
#include "matrix.h"

unsigned long long counter=0;
int solution_cnt=0;
bool TestMatrix(const Matrix<Poly> &matrix, const Poly &answer){
    //std::cout<<matrix<<"Is On Test!\n";
    bool pass_tests=1;
    Matrix<Poly> test_matrix=matrix;
    //Det test
    if(!(Det(test_matrix) == answer)){
        pass_tests=0;
        //std::cout<<"The det is "<<Det(test_matrix)<<", while the answer is"<<answer<<std::endl;
    }
    //Test elementary op
    if(pass_tests){
        test_matrix.ElementaryOp(3,3,2,-2);
        test_matrix.ElementaryOp(3,3,1,-1);
        if(test_matrix(3,1).Getdeg()>0){
            pass_tests=0;
        }else if(test_matrix(3,1)[0]!=0){
            pass_tests=0;
        }else{
            if(!(test_matrix(3,2)==test_matrix(3,3)))pass_tests=0;
        }
    }
    if(pass_tests){
        //print the matrix
        solution_cnt++;
        printf("\nThe %d th answer is:\n", solution_cnt);
        std::cout << matrix << std::endl;
        //output elementary op
        // std::cout<<"After the elementary operation, the matrix becomes"<<std::endl;
        // std::cout<<test_matrix<<std::endl;
        test_matrix.ElementaryOp(3,3,1,1);
        test_matrix.ElementaryOp(3,3,2,2);
        //output Cramer's rule
        {
        Matrix<Poly> tmp(3, 1);
        for (int i = 1; i <= 3; i++){ // col
            for (int j = 1; j <= 3; j++){ // row
                tmp(j, 1) = test_matrix(j, i);
            }
            test_matrix(1, i) = "0,1", test_matrix(2, i) = "1,0", test_matrix(3, i) = "2,0";
            std::cout << test_matrix << std::endl;
            std::cout << "The Det in Cramer's rule for x_" << i << " is " << Det(test_matrix) << std::endl;
            for (int j = 1; j <= 3; j++){ // row
                test_matrix(j, i) = tmp(j, 1);
            }
        }
        }
        return false;
    }else{
        return false;
    }
}

bool Search(int search_index,Matrix<Poly> &matrix,const Poly &answer){
    int search_up_bound=2,search_low_bound=-2;
    if(search_index==0)search_index++;
    //if(search_index==1)search_index++;//de
    //if(search_index==2)search_index++;//de
    if(search_index==3)search_index++;
    //if(search_index==4)search_index++;//de
    if(search_index==5)search_index++;
    if(search_index==6)search_index++;
    if(search_index==9){
        counter++;
        if(counter>=10000000){
            printf("Sorry, but too much search!\n");
            return true;
        }
        if(counter%100000==0){
            printf("\nWe have been searching %lld\n",counter);
        }
        return TestMatrix(matrix,answer);
    }else{
        bool find_ended=0;
        for(int i=search_low_bound;i<=search_up_bound;i++){
            if (search_index % 3 == 1){// the second col has no values pm2
                if (i == search_low_bound || i == search_up_bound)
                    continue;
            }
            matrix(search_index/3+1,search_index%3+1).SetCoeff(0,i);
            for(int j=search_low_bound;j<=search_up_bound;j++){
                if(search_index%3==1){// the second col has no values pm2
                    if(j==search_low_bound||j==search_up_bound)continue;
                }
                if(i==0&&j==0)continue;//no zero elements
                matrix(search_index/3+1,search_index%3+1).SetCoeff(1,j);
                if(Search(search_index+1,matrix,answer)){
                    find_ended=1;break;
                }
            }
            if(find_ended)break;
        }
        return find_ended;
    }
}

int main(){
    int n=3;
    freopen("answer_out.out","w",stdout);
    Matrix<Poly> matrix(3,3);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            matrix(i,j).Resize(1);
        }
    }
    matrix(1,1)="1,3";
    matrix(2,1)="1,0";
    //matrix(1,2)="1,0";//de
    //matrix(2,2)="1";//de
    //matrix(1,3)="1,-1";//de
    matrix(3,1)="3,3";
    matrix(2,3)="1";
    Poly answer("1,-1,0,0");
    if(!Search(0,matrix,answer))printf("Search finished!\n");
    //std::cout<<matrix<<std::endl;
    if(!solution_cnt)printf("Sorry, but no results!\n");
    else printf("Test finished with %d solutions.\n",solution_cnt);
    return 0;
}


