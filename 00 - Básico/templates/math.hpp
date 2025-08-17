#pragma once
#include <bits/stdc++.h>
using namespace std;

#define fastio ios::sync_with_stdio(false); cin.tie(nullptr);

typedef long long ll;
typedef __int128 i128;

// ==============================
// 🔢 Álgebra
// ==============================

// Producto seguro bajo mod
ll mul_safely(ll a, ll b, ll mod){ return (i128)a*b % mod; }

// Potenciación rápida (con y sin módulo)
ll binpow(ll a, long long e){ ll r=1; while(e){ if(e&1) r=r*a; a=a*a; e>>=1; } return r; }
ll modpow(ll a, long long e, ll mod){ ll r=1%mod; a%=mod; while(e){ if(e&1) r=(i128)r*a%mod; a=(i128)a*a%mod; e>>=1; } return r; }

// Raíz cuadrada entera
long long isqrt_floor(long long x){ long long r=sqrtl((long double)x); while((r+1)*(r+1)<=x) ++r; while(r*r>x) --r; return r; }
long long isqrt_ceil(long long x){ long long f=isqrt_floor(x); return f*f==x?f:f+1; }

// Comparación de fracciones
ll gcdll(ll a,ll b){ return b?gcdll(b,a%b):llabs(a); }
int cmp_frac(ll a,ll b,ll c,ll d){ i128 L=(i128)a*d, R=(i128)c*b; return (L<R)?-1:(L>R?1:0); }

struct Frac{ ll p,q; Frac(ll _p=0,ll _q=1){ if(_q<0) _p=-_p,_q=-_q; ll g=gcdll(llabs(_p),_q); p=_p/g; q=_q/g; } };

// ==============================
// 📊 Combinatoria
// ==============================

// Preprocesamiento de factoriales e inversos módulo MOD
const int MOD = 1'000'000'007;
const int MAXF = 2'000'000; // ajustar según límites
long long fact[MAXF+1], invfact[MAXF+1];

// Inverso modular por exponenciación rápida
long long modinv(long long a){ return modpow(a, MOD-2, MOD); }

// Construcción de factoriales e inversos
void build_fact(){
    fact[0]=1;
    for(int i=1;i<=MAXF;i++) fact[i]=fact[i-1]*i%MOD;
    invfact[MAXF]=modinv(fact[MAXF]);
    for(int i=MAXF;i>0;i--) invfact[i-1]=invfact[i]*i%MOD;
}

// Combinatoria clásica: nCk con factoriales
long long nCk(int n,int k){
    if(k<0||k>n) return 0;
    return fact[n]*invfact[k]%MOD*invfact[n-k]%MOD;
}

// nCk para n grande y k pequeño (multiplicación directa)
long long nCk_mult(long long n,int k){
    if(k<0||k>n) return 0;
    long long num=1, den=1;
    for(int i=1;i<=k;i++){
        num = (i128)num * ((n-k+i)%MOD) % MOD;
        den = (i128)den * i % MOD;
    }
    return num * modinv(den) % MOD;
}

// Inclusión-exclusión genérica
// count_with_mask(S) debe devolver el conteo para una máscara S
// Se aplica la fórmula estándar con signos alternados
// Retorna el resultado módulo MOD
template<class F>
long long inclusion_exclusion(int m, F count_with_mask){
    long long ans=0;
    for(int S=0; S<(1<<m); ++S){
        int bits=__builtin_popcount((unsigned)S);
        long long add=count_with_mask(S);
        if(bits&1) ans=(ans-add)%MOD;
        else ans=(ans+add)%MOD;
    }
    if(ans<0) ans+=MOD;
    return ans;
}

// ==============================
// 🔢 Teoría de Números
// ==============================

// Criba de Eratóstenes para primos hasta MAXP
const int MAXP = 1'000'000;
vector<int> primes; bitset<MAXP+1> isPrime;

void sieve(){
    isPrime.set(); isPrime[0]=isPrime[1]=0;
    for(int i=2;i*i<=MAXP;i++) if(isPrime[i])
        for(int j=i*i;j<=MAXP;j+=i) isPrime[j]=0;
    for(int i=2;i<=MAXP;i++) if(isPrime[i]) primes.push_back(i);
}

// Factorización con primos precalculados
vector<pair<long long,int>> factor_small(long long n){
    vector<pair<long long,int>> f;
    for(int p:primes){
        if(1LL*p*p>n) break;
        if(n%p==0){ int c=0; while(n%p==0) n/=p,++c; f.push_back({p,c}); }
    }
    if(n>1) f.push_back({n,1});
    return f;
}

// Algoritmo extendido de Euclides
long long egcd(long long a,long long b,long long& x,long long& y){
    if(!b){ x=1; y=0; return a; }
    long long x1,y1; long long g=egcd(b,a%b,x1,y1);
    x=y1; y=x1 - y1*(a/b);
    return g;
}

// Inverso modular general (retorna -1 si no existe)
long long inv_mod_gen(long long a,long long m){
    long long x,y; long long g=egcd((a%m+m)%m,m,x,y);
    if(g!=1) return -1;
    x%=m; if(x<0) x+=m; return x;
}

// Teorema Chino del Resto para 2 congruencias
pair<long long,long long> crt_pair(long long r1,long long m1,long long r2,long long m2){
    long long x,y; long long g=egcd(m1,m2,x,y);
    if((r2-r1)%g) return {0,-1};
    long long l=m1/g*m2;
    long long t=( (__int128)(r2-r1)*x % m2 + m2 ) % m2;
    long long r=( (__int128)t * (m1 % l) + r1 ) % l;
    if(r<0) r+=l;
    return {r,l};
}

// ==============================
// 📐 Geometría
// ==============================

// Punto entero con operadores básicos
struct P{ long long x,y; bool operator<(const P& o)const{ if(x!=o.x) return x<o.x; return y<o.y; } bool operator==(const P& o)const{ return x==o.x&&y==o.y; } };

// Producto cruzado con precisión extendida
inline __int128 cross128(const P& a,const P& b,const P& c){ return (__int128)(b.x-a.x)*(c.y-a.y) - (__int128)(b.y-a.y)*(c.x-a.x); }

// Convex Hull (Andrew's monotone chain)
vector<P> convex_hull(vector<P> pts){
    sort(pts.begin(),pts.end());
    pts.erase(unique(pts.begin(),pts.end()),pts.end());
    int n=pts.size(); if(n<=1) return pts;
    vector<P> lo,up;
    for(auto& p:pts){
        while(lo.size()>=2 && cross128(lo[lo.size()-2],lo.back(),p)<=0) lo.pop_back();
        lo.push_back(p);
    }
    for(int i=n-1;i>=0;--i){
        auto p=pts[i];
        while(up.size()>=2 && cross128(up[up.size()-2],up.back(),p)<=0) up.pop_back();
        up.push_back(p);
    }
    lo.pop_back(); up.pop_back();
    lo.insert(lo.end(),up.begin(),up.end());
    return lo;
}

// Signo de un __int128 (para orientación)
int sgn128(__int128 v){ return (v>0)-(v<0); }

// Chequeo de punto sobre segmento
bool on_seg(const P& a,const P& b,const P& p){
    if(sgn128(cross128(a,b,p))!=0) return false;
    return min(a.x,b.x)<=p.x && p.x<=max(a.x,b.x) && min(a.y,b.y)<=p.y && p.y<=max(a.y,b.y);
}

// Intersección de segmentos (incluye casos colineales)
bool seg_inter(const P& a,const P& b,const P& c,const P& d){
    auto o1=sgn128(cross128(a,b,c)), o2=sgn128(cross128(a,b,d));
    auto o3=sgn128(cross128(c,d,a)), o4=sgn128(cross128(c,d,b));
    if(o1*o2<0 && o3*o4<0) return true;
    if(o1==0&&on_seg(a,b,c)) return true;
    if(o2==0&&on_seg(a,b,d)) return true;
    if(o3==0&&on_seg(c,d,a)) return true;
    if(o4==0&&on_seg(c,d,b)) return true;
    return false;
}

// Ordenamiento polar relativo a un punto p0
struct PolarSort{ P p0; bool upper(const P& a)const{ return a.y>p0.y || (a.y==p0.y && a.x>=p0.x); } bool operator()(const P& a,const P& b)const{ bool ua=upper(a), ub=upper(b); if(ua!=ub) return ua>ub; __int128 cr=cross128(p0,a,b); if(cr!=0) return cr>0; long long da=(a.x-p0.x)*(long long)(a.x-p0.x)+(a.y-p0.y)*(long long)(a.y-p0.y); long long db=(b.x-p0.x)*(long long)(b.x-p0.x)+(b.y-p0.y)*(long long)(b.y-p0.y); return da<db; } };

// ==============================
// 🔮 Extensiones Avanzadas
// ==============================

// Miller–Rabin
ll mul_mod(ll a,ll b,ll m){ return (__int128)a*b % m; }

bool is_prime(long long n){
    if(n<2) return false;
    for(long long p:{2,3,5,7,11,13,17,19,23,29,31,37}) if(n%p==0) return n==p;
    long long d=n-1,s=0; while((d&1)==0){ d>>=1; s++; }
    for(long long a:{2,325,9375,28178,450775,9780504,1795265022}){
        if(a%n==0) continue;
        long long x=modpow(a,d,n);
        if(x==1||x==n-1) continue;
        bool comp=true;
        for(int r=1;r<s;r++){ x=mul_mod(x,x,n); if(x==n-1){ comp=false; break; } }
        if(comp) return false;
    }
    return true;
}

// Pollard Rho
long long f_rho(long long x,long long c,long long mod){ return (mul_mod(x,x,mod)+c)%mod; }
long long rho(long long n){ if(n%2==0) return 2; long long x=rand()%(n-2)+2; long long y=x, c=rand()%(n-1)+1, d=1; while(d==1){ x=f_rho(x,c,n); y=f_rho(f_rho(y,c,n),c,n); d=gcd(abs(x-y),n); } if(d==n) return rho(n); return d; }

vector<long long> factorize_rho(long long n){ if(n==1) return {}; if(is_prime(n)) return {n}; long long d=rho(n); auto l=factorize_rho(d); auto r=factorize_rho(n/d); l.insert(l.end(),r.begin(),r.end()); return l; }

// Rotating Calipers (diámetro de un hull)
double dist2(const P& a,const P& b){ return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y); }

pair<double,pair<P,P>> diameter(const vector<P>& hull){ int n=hull.size(); if(n==1) return {0,{hull[0],hull[0]}}; double best=0; pair<P,P> ans={hull[0],hull[0]}; int j=1; for(int i=0;i<n;i++){ int ni=(i+1)%n; while(abs(cross128(hull[i],hull[ni],hull[(j+1)%n])) > abs(cross128(hull[i],hull[ni],hull[j]))) j=(j+1)%n; double d=dist2(hull[i],hull[j]); if(d>best){ best=d; ans={hull[i],hull[j]}; } } return {sqrt(best),ans}; }

// Matrices mod p
struct Mat{ int n; vector<vector<long long>> a; Mat(int _n):n(_n),a(_n,vector<long long>(_n)){} static Mat id(int n){ Mat m(n); for(int i=0;i<n;i++) m.a[i][i]=1; return m; } Mat operator*(const Mat& o) const { Mat r(n); for(int i=0;i<n;i++) for(int k=0;k<n;k++) if(a[i][k]) for(int j=0;j<n;j++) r.a[i][j]=(r.a[i][j]+a[i][k]*o.a[k][j])%MOD; return r; } };
Mat matpow(Mat b,long long e){ Mat r=Mat::id(b.n); while(e){ if(e&1) r=r*b; b=b*b; e>>=1; } return r; }

// ModInt
template<int MOD>
struct ModInt{ long long v; ModInt(long long _v=0){ v=_v%MOD; if(v<0) v+=MOD; } ModInt operator+(const ModInt& o)const{ return ModInt(v+o.v); } ModInt operator-(const ModInt& o)const{ return ModInt(v-o.v); } ModInt operator*(const ModInt& o)const{ return ModInt(v*o.v); } ModInt pow(long long e)const{ ModInt r(1),a(v); while(e){ if(e&1) r=r*a; a=a*a; e>>=1; } return r; } ModInt inv()const{ return pow(MOD-2); } ModInt operator/(const ModInt& o)const{ return *this * o.inv(); } };