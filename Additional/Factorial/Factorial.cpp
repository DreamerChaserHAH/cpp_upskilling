#include <iostream>

using namespace std;

int continuous_multiplication(int max, int current = 1){
    return (current == max)? current: current * continuous_multiplication(max, current + 1);
}

int get_factorial_sum(int factorial){
    return continuous_multiplication(factorial);
}

int main(){

    int factorial;
    cin >> factorial;
    cout << get_factorial_sum(factorial);

    return 0;
}