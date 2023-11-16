#ifndef __POLY_H__
#define __POLY_H__

#include <iostream>
#include <string>
#include <cmath>
class Poly{
	private:
		int deg_;
		int* coeff_;
	public:
		Poly(): deg_(0){
            coeff_ = new int[deg_ + 1];
        }
		Poly(int n):deg_(n){
			coeff_=new int  [deg_+1];
		}
        Poly(Poly &&other);
        Poly(const Poly &other);
        Poly(const std::string &name);
        Poly &operator= (Poly &&other);
        Poly &operator= (const Poly &other);
        void CopyFromString(const std::string &name);
        Poly &operator= (const std::string &name);

		void Resize(int size);
        void CheckCoeff();
        const int Getdeg() const{return deg_;}
        const int operator[](int index)const; 
        void SetCoeff(int index,int val_);

        friend std::ostream &operator<<(std::ostream &out,const Poly& poly);
		friend Poly operator *(const Poly &a,const Poly &b);
        friend Poly operator +(const Poly &a,const Poly &b);
        friend Poly operator *(int c,const Poly &a);
        friend bool operator==(const Poly &a,const Poly &b);
};

Poly::Poly(Poly &&other){
    this->deg_=other.deg_;
    this->coeff_=other.coeff_;
    other.deg_=0;
    other.coeff_=nullptr;
}

Poly::Poly(const Poly &other){
    this->deg_=other.deg_;
    coeff_=new int  [deg_+1];
    for(int i=0;i<=deg_;i++){
        coeff_[i]=other.coeff_[i];
    }
}

inline Poly::Poly(const std::string &name){
    this->CopyFromString(name);
}

Poly &Poly::operator= (Poly &&other){
    if(coeff_)delete[] coeff_;
    this->deg_=other.deg_;
    this->coeff_=other.coeff_;
    other.deg_=0;
    other.coeff_=nullptr;
    return *this;
}

Poly &Poly::operator= (const Poly &other){
    this->deg_=other.deg_;
    //if(coeff_)delete[] coeff_;
    coeff_=new int [deg_+1];
    for(int i=0;i<=deg_;i++){
        coeff_[i]=other.coeff_[i];
    }
    //this->CheckCoeff();
    return *this;
}

inline void Poly::CopyFromString(const std::string &name){
    deg_=0;
    for(int i=0;i<name.length();i++){
        if(name[i]==',')deg_++;
    }
    coeff_=new int [deg_+1];
    int beg_index=0;
    for(int i=deg_;i>=0;i--){
        coeff_[i]=0;
        //std::cout<<name<<std::endl;
        int index=name.find(',',beg_index);
        if(index==-1)index=name.size();
        for(int j=beg_index;j<index;j++){
            if(name[j]>='0'&&name[j]<='9')coeff_[i]+=pow(10,index-j-1)*(name[j]-'0');
        }
        if(name[beg_index]=='-')coeff_[i]*=-1;
        if(index==name.size())break;
        beg_index=index+1;
    }
    CheckCoeff();
}

inline Poly &Poly::operator=(const std::string& name)
{
    if(coeff_)delete[]this->coeff_;
    this->CopyFromString(name);
    return *this;
    // TODO: insert return statement here
}

void Poly::Resize(int size){
    deg_=size;
	if(coeff_)delete[] coeff_;
	coeff_=new int [deg_+1];
    for(int i=0;i<=deg_;i++){
        coeff_[i]=0;
    }
}

void Poly::CheckCoeff(){
    int i=deg_;
    while(coeff_[i]==0)i--;
    if(i==-1)i++;
    deg_=i;
}

const int Poly::operator[](int index)const{
    //printf("Calling reading, index %d\n",index);
    if((index>deg_)||(index<0)){
        //printf("Error: asking for useless index\n");
        return 0;
    }else{
        return coeff_[index];
    }
}

inline void Poly::SetCoeff(int index, int val_){
    // printf("Calling assignment, index %d\n",index);
    if ((index < 0)){
        printf("Error: setting useless index\n");
        return;
    }
    else if(index<=deg_){
        coeff_[index]=val_;
    }
    if(index==deg_&&val_==0){
        CheckCoeff();
    }
    if(index>deg_&&val_!=0){
        int* tmp=new int[index+1];
        for(int i=0;i<=deg_;i++){
            tmp[i]=coeff_[i];
        }
        for(int i=deg_+1;i<=index;i++){
            tmp[i]=0;
        }
        tmp[index]=val_;
        Resize(index);
        for(int i=0;i<=index;i++){
            coeff_[i]=tmp[i];
        }
        if(tmp)delete[] tmp;
    }
}

std::ostream &operator<<(std::ostream &out,const Poly & poly)
{
    int deg=poly.Getdeg();
    if (deg < 0)out<<"Print failure, this polynomial is null\n";
    for (int i = deg; i >= 1; i--)
    {
        if(poly[i]!=0){
            if(poly[i]>0&&i!=deg)out<<"+";
            else if(poly[i]<0) out<<"-";
            if(poly[i]!=1&&poly[i]!=-1){
                out<<abs(poly[i]);
            }
            if(i==1)out<<"x";
             else  out<<"x^"<<i;
        }  
    }
    if(poly[0]>0&&deg>0)out<<"+";
    if(poly[0]!=0&&deg>0)out<<poly[0];
    if(deg==0){
        out<<poly[0];
    } 
    return out;
    // TODO: insert return statement here
}
Poly operator*(const Poly &a, const Poly &b)
{
    int thisdeg=a.Getdeg()+b.Getdeg();
    Poly ans(thisdeg);
    for(int i=0;i<=thisdeg;i++){
        ans.SetCoeff(i,0);
        //printf("calculating %d\n",i);
        for(int j=0;j<=i;j++){
            // printf("a,%d\n",j);
            // printf("b,%d\n",i-j);
            ans.SetCoeff(i,ans[i]+(a[j])*(b[i-j]));
        }
    }
    return ans;
}
Poly operator +(const Poly &a,const Poly &b){
    int deg=a.Getdeg();
    if(b.Getdeg()>deg)deg=b.Getdeg();
    Poly ans(deg);
    for(int i=0;i<=deg;i++){
        ans.SetCoeff(i,a[i]+b[i]);
    }
    return ans;
}
Poly operator *(int c,const Poly &a){
    Poly ans(a.Getdeg());
    for(int i=0;i<=a.Getdeg();i++){
        ans.SetCoeff(i,a[i]*c);
    }
    return ans;
}

bool operator==(const Poly &a,const Poly &b)
{
    if(a.Getdeg()!=b.Getdeg())return false;
    for(int i=0;i<=a.Getdeg();i++){
        if(a[i]!=b[i])return false;
    }
    return true;
}


#endif//! POLY_H