// <summary>
//     src: https://open.kattis.com/problems/areal
//     # What I learnt?
//         The program asks for 10^16, initially I use int which only have till 10^10. changed it so that it matchesß
// </summary>
#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double fence_length_calculator(long* area){
    return sqrt(*area) * 4.0;
}

int main(){

    long area;
    cin >> area;
    cout << setprecision(20) << fence_length_calculator(&area);
    return 0;
}