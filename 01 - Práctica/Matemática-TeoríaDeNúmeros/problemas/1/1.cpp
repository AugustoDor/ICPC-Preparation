#include "math.hpp"
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;

int main(){
    fastio;
    
    // 1. DADO UN NUMERO N, ENCONTRAR 2 NUMEROS DISTINTOS Y ENTEROS QUE SUMADOS DEN N.
    // DEVOLVER: a y b
    // Verificar que n sea mayor que 2
    int n = 4;
    int a = n-1;
    int b = n-a;
    cout << "Enteros que suman: " << n << "Son: " << a << " " << b ;

    
    return 0;
}