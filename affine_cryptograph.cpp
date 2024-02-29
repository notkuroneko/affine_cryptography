#include <iostream>

/*
Letters of the alphabet with indexes (for reference)
 A | B | C | D | E | F | G | H | I | J | K | L | M | N | O | P | Q | R | S | T | U | V | W | X | Y | Z
 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10| 11| 12| 13| 14| 15| 16| 17| 18| 19| 20| 21| 22| 23| 24| 25
*/

const int keyList[12] = {1, 3, 5, 7, 9, 11, 15, 17, 19, 21, 23, 25};
const int keyListInverted[12] = {1, 9, 21, 15, 3, 19, 7, 23, 11, 5, 17, 25};

using namespace std;

//object-oriented

class encode_affine{
    private: 
        string ciphertext(string P, int a, int b){
            string C;
            for (int i=0; i<P.length(); i++) {
                if (P[i]==32) C+=' ';
                else if (P[i]>=65&&P[i]<=90) C+=((((int)P[i]-65)*a+b)%26)+65;
                else if (P[i]>=97&&P[i]<=122) C+=((((int)P[i]-97)*a+b)%26)+97;
                else C+=P[i];
            }
            return C;
        }
    public:
        encode_affine(string P, int a, int b){
            cout << "Cipher text: " << ciphertext(P, a, b) << endl;
        } 
};

class decode_affine{
    private:
        string plaintext(string C, int a, int b){
            string P; int temp;
            for (int i=0; i<C.length(); i++) {
                if (C[i]==32) P+=' ';
                else if (C[i]>=65&&C[i]<=90) 
                    {
                        temp = a*((int)C[i]-65-b)%26;
                        if (temp<0) temp+=26;
                        P+=temp+65;
                    }
                else if (C[i]>=97&&C[i]<=122) 
                    {   
                        temp = a*((int)C[i]-97-b)%26;
                        if (temp<0) temp+=26;
                        P+=temp+97;
                    }
                else P+=C[i];
            }
            return P;
        }
    public:
        decode_affine(string C, int a, int b){
            cout << "Plain text: " << plaintext(C, a, b) << endl;
        }
};

int check(int x){
    for (int i=0; i<12; i++) 
    if (x==keyList[i]) return keyListInverted[i];
    return 0;
}

void encode() {
    string P,C;
    int a,b;
    cin.ignore();
    cout << "Enter plain text (in uppercase): ";
    std::getline(std::cin, P);
    cout << "Enter key a (a must be co-prime with and smaller than 26): ";
    cin >> a;
    while (!check(a)) {
        cout << "Invalid key, re-enter: ";
        cin >> a;
    }
    cout << "Enter key b (b must be co-prime with and smaller than 26): ";
    cin >> b;
    while (!check(b)) {
        cout << "Invalid key, re-enter: " << endl;
        cin >> b;
    }
    new encode_affine(P,a,b);
}

void decode(){
    string P,C;
    int a,b;
    cin.ignore();
    cout << "Enter cipher text (in uppercase): ";
    std::getline(std::cin, C);
    cout << "Enter key a (a must be co-prime with and smaller than 26): ";
    cin >> a;
    while (!check(a)) {
        cout << "Invalid key, re-enter: ";
        cin >> a;
    }
    a=check(a);
    cout << "Enter key b (b must be co-prime with and smaller than 26): ";
    cin >> b;
    while (!check(b)) {
        cout << "Invalid key, re-enter: " << endl;
        cin >> b;
    }
    new decode_affine(C,a,b);
}

int main() {
    int mode;
    cout << "Choose mode (0 for encode, 1 for decode): ";
    cin >> mode;
    if (mode==0) encode();
    if (mode==1) decode();
    return 0;
}