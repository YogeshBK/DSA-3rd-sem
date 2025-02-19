#include<iostream>
using namespace std;

// Recursive function 
void towerOfHanoi(int n, char from, char to, char aux) {
    if (n == 1) {
        cout << "Move disk 1 from " << from << " to " << to << endl;
        return;
		}
   towerOfHanoi(n - 1, from, aux, to);
    	 cout << "Move disk " << n << " from " << from << " to " << to << endl;
    towerOfHanoi(n - 1, aux, to, from);
}

int main() {
    int n;
    cout << "Enter the number of disks: ";
    cin >> n;
    	 cout << "The sequence of moves are:"<<endl;
    towerOfHanoi(n, 'A', 'C', 'B'); 
    return 0;
}


