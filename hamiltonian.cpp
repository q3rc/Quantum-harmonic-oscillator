#include <iostream>
#include <Eigen/Dense>


using Eigen::MatrixXd;
using namespace std;

double x_min = -5;
double x_max = 5;
int N = 300;
double dx = (x_max-x_min)/(N-1);

double k = 1.0;
double m = 1.0; 
double h = 1.0; 

Eigen::MatrixXd Hamiltonian(){

    Eigen::MatrixXd A = Eigen::MatrixXd::Zero(N,N);

    for (int i=0; i<N; i++ ){
        double x = x_min+i*dx;
        A(i,i) = 0.5 * k * (x*x);
    }

    Eigen::MatrixXd B = Eigen::MatrixXd::Zero(N,N);

    for (int i=0; i<N; i++){
        B (i,i) = -2/(dx*dx);
        if(i>0){
            B (i-1,i) = 1/(dx*dx);
        }
        if(i<N-1){
            B (i+1,i) = 1/(dx*dx); 
        }
    }

    Eigen::MatrixXd C = -(h*h)/(2*m) * B;
    Eigen::MatrixXd H = A + C;

    return H;
}


Eigen::MatrixXd Solver(){
    
    Eigen::MatrixXd H = Hamiltonian();
    Eigen::SelfAdjointEigenSolver<Eigen::MatrixXd> eigensolver(H);

    Eigen::MatrixXd psi = eigensolver.eigenvectors();
    
    return psi;
}


int main(){
    cout<<"x range: {-5,5}"<<"\n";
    cout<<"k, m, and h set to 1"<<"\n";
    Eigen::MatrixXd psi = Solver();

    int n{};
    cout<<"Enter a desired state number {0,300): "<<"\n";
    cin>>n;

    double pos{0};

    if (n<300 && n>=0){
        Eigen::VectorXd npsi = psi.col(n);
        for (int i=0; i<N; i++){

            double xi = x_min + i *dx;
            
            double prob = npsi(i) * npsi(i);
            pos += xi * prob * dx;
        }
        cout<<"\n"<< "The state "<<n<< " <x> is "<< pos <<"\n";
    }
    else{
        cout<< "\n"<< "Wrong number ";
    }

    cin.get();
    cin.get();

    return 0;

}