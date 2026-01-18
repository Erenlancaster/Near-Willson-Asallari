#include <iostream>
using namespace std;

int main() {

    int limit = 10000;

    for (int p = 2; p <= limit; p++) {

        bool asal = true;

        // asal kontrolü
        for (int i = 2; i <= p / 2; i++) {
            if (p % i == 0) {
                asal = false;
                break;
            }
        }
        if (!asal) continue;

        long long mod = p * p; // p^2
        long long fact = 1;

        
        for (int i = 2; i <= p - 1; i++) {
            fact = (fact * i) % mod;   // burda mod kullanıyoruz yoksa long long limitine ulaşıyor. 
            // modu adım adım parça parça alsak bile işlemin sonucu değişmiyor ispat (a⋅b)modn=((amodn)⋅(bmodn))modn
        }

        // (p-1)! + 1 mod p^2
        long long kalan = (fact + 1) % mod;

        if (kalan == p || kalan == mod - p) {
            cout << p << endl;
        }
    }

    return 0;
}
