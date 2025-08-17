#include "math.hpp"
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main(){
    fastio;
    
    // 2. DADO N, ENCONTRAR LA SUMA DE SUS DIJITOS.
    // DEVOLVER: la suma de los digitos
    int n = 5;
    int sum = 0;
    while (n > 0){
        sum = sum + n;
        n = n - 1;
    };
    cout << "Suma de los digitos de " << n << "es: " << sum ;

    return 0;
}