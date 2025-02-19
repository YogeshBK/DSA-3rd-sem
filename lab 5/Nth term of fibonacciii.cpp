#include<iostream>
using namespace std;


int fibo(int n) {
    if (n <= 1) {
        return n; 
    }
    return fibo(n - 1) + fibo(n - 2); // Recursive call
}

int main() {
    int n;
    
   
    cout << "Enter the term  to find in the Fibonacci series: ";
    cin >> n;
    for(int i=0;i<=n;++i){
		cout<<fibo(i)<<" ";
    
}
    cout <<endl<< "The " << n << "-th term of the Fibonacci series is: " << fibo(n) << endl;

    return 0;

}

