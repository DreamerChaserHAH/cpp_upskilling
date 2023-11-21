// Using Multiplication Rule of Modular Arithmetic,
// if a * b ≡ c,
// a (mod N) * b (mod N) ≡ c (mod N)
// which can be recursed multiple times over
// The script also uses pointers so that value can be obtained by doing the same operation over and over again

#include <iostream>

using namespace std;

int get_modular(int target, int modular_divider){
    return target % modular_divider;
}

void continuous_recursive_modular(int factorial, int modular_divider, int* current_modular, int current = 1){
    // cout << get_modular(current, modular_divider) << "\n";
    *current_modular = get_modular((*current_modular * get_modular(current, modular_divider)), modular_divider);

    if (current != factorial){
        continuous_recursive_modular(factorial, modular_divider, current_modular, current + 1);
    }
}

int get_factorial_remainder(int factorial, int modulur_divider){
    int current_modular = 1;
    continuous_recursive_modular(factorial, modulur_divider, &current_modular);
    return current_modular;
}

int main(){
    int factorial, modular_divider;

    cin >> factorial >> modular_divider;
    cout << get_factorial_remainder(factorial, modular_divider);
}