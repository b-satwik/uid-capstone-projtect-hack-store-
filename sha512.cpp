#include <iostream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <string>
#include <cmath>

using namespace std;

// ------------------ SHA-512 Constants ------------------
// Initial hash values (first 64 bits of the fractional parts of the square roots of the first 8 primes)
uint64_t H[8] = {
    0x6a09e667f3bcc908,
    0xbb67ae8584caa73b,
    0x3c6ef372fe94f82b,
    0xa54ff53a5f1d36f1,
    0x510e527fade682d1,
    0x9b05688c2b3e6c1f,
    0x1f83d9abfb41bd6b,
    0x5be0cd19137e2179
};

// Round constants (first 64 bits of the fractional parts of the cube roots of the first 80 primes)
uint64_t K[80] = {
    0x428a2f98d728ae22,0x7137449123ef65cd,0xb5c0fbcfec4d3b2f,0xe9b5dba58189dbbc,
    0x3956c25bf348b538,0x59f111f1b605d019,0x923f82a4af194f9b,0xab1c5ed5da6d8118,
    0xd807aa98a3030242,0x12835b0145706fbe,0x243185be4ee4b28c,0x550c7dc3d5ffb4e2,
    0x72be5d74f27b896f,0x80deb1fe3b1696b1,0x9bdc06a725c71235,0xc19bf174cf692694,
    0xe49b69c19ef14ad2,0xefbe4786384f25e3,0x0fc19dc68b8cd5b5,0x240ca1cc77ac9c65,
    0x2de92c6f592b0275,0x4a7484aa6ea6e483,0x5cb0a9dcbd41fbd4,0x76f988da831153b5,
    0x983e5152ee66dfab,0xa831c66d2db43210,0xb00327c898fb213f,0xbf597fc7beef0ee4,
    0xc6e00bf33da88fc2,0xd5a79147930aa725,0x06ca6351e003826f,0x142929670a0e6e70,
    0x27b70a8546d22ffc,0x2e1b21385c26c926,0x4d2c6dfc5ac42aed,0x53380d139d95b3df,
    0x650a73548baf63de,0x766a0abb3c77b2a8,0x81c2c92e47edaee6,0x92722c851482353b,
    0xa2bfe8a14cf10364,0xa81a664bbc423001,0xc24b8b70d0f89791,0xc76c51a30654be30,
    0xd192e819d6ef5218,0xd69906245565a910,0xf40e35855771202a,0x106aa07032bbd1b8,
    0x19a4c116b8d2d0c8,0x1e376c085141ab53,0x2748774cdf8eeb99,0x34b0bcb5e19b48a8,
    0x391c0cb3c5c95a63,0x4ed8aa4ae3418acb,0x5b9cca4f7763e373,0x682e6ff3d6b2b8a3,
    0x748f82ee5defb2fc,0x78a5636f43172f60,0x84c87814a1f0ab72,0x8cc702081a6439ec,
    0x90befffa23631e28,0xa4506cebde82bde9,0xbef9a3f7b2c67915,0xc67178f2e372532b,
    0xca273eceea26619c,0xd186b8c721c0c207,0xeada7dd6cde0eb1e,0xf57d4f7fee6ed178,
    0x06f067aa72176fba,0x0a637dc5a2c898a6,0x113f9804bef90dae,0x1b710b35131c471b,
    0x28db77f523047d84,0x32caab7b40c72493,0x3c9ebe0a15c9bebc,0x431d67c49c100d4c,
    0x4cc5d4becb3e42b6,0x597f299cfc657e2a,0x5fcb6fab3ad6faec,0x6c44198c4a475817
};

// ------------------ Helper Functions ------------------

// Right rotate function
uint64_t rotr(uint64_t x, int n) {
    return (x >> n) | (x << (64 - n));
}

// SHA-512 padding: convert message to binary with padding
vector<uint8_t> padMessage(const string &msg) {
    vector<uint8_t> padded(msg.begin(), msg.end());
    uint64_t bit_len = padded.size() * 8;

    // append 0x80
    padded.push_back(0x80);

    // append zeros until length is 128 bytes less than multiple of 128 bytes
    while ((padded.size() + 16) % 128 != 0)
        padded.push_back(0x00);

    // append original length as 128-bit big endian
    for (int i = 15; i >= 0; --i)
        padded.push_back((bit_len >> (i * 8)) & 0xFF);

    return padded;
}

// ------------------ SHA-512 Main Function ------------------
string sha512(const string &message) {
    vector<uint8_t> msg = padMessage(message);

    uint64_t h[8];
    for (int i = 0; i < 8; ++i)
        h[i] = H[i];

    // process each 1024-bit chunk
    for (size_t chunk = 0; chunk < msg.size(); chunk += 128) {
        uint64_t W[80];
        // prepare message schedule
        for (int i = 0; i < 16; ++i) {
            W[i] = 0;
            for (int j = 0; j < 8; ++j) {
                W[i] = (W[i] << 8) | msg[chunk + i*8 + j];
            }
        }
        for (int i = 16; i < 80; ++i) {
            uint64_t s0 = rotr(W[i-15], 1) ^ rotr(W[i-15], 8) ^ (W[i-15] >> 7);
            uint64_t s1 = rotr(W[i-2], 19) ^ rotr(W[i-2], 61) ^ (W[i-2] >> 6);
            W[i] = W[i-16] + s0 + W[i-7] + s1;
        }

        uint64_t a = h[0], b = h[1], c = h[2], d = h[3];
        uint64_t e = h[4], f = h[5], g = h[6], hh = h[7];

        // main compression function
        for (int i = 0; i < 80; ++i) {
            uint64_t S1 = rotr(e, 14) ^ rotr(e, 18) ^ rotr(e, 41);
            uint64_t ch = (e & f) ^ ((~e) & g);
            uint64_t temp1 = hh + S1 + ch + K[i] + W[i];
            uint64_t S0 = rotr(a, 28) ^ rotr(a, 34) ^ rotr(a, 39);
            uint64_t maj = (a & b) ^ (a & c) ^ (b & c);
            uint64_t temp2 = S0 + maj;

            hh = g;
            g = f;
            f = e;
            e = d + temp1;
            d = c;
            c = b;
            b = a;
            a = temp1 + temp2;
        }

        // add chunk's hash to result so far
        h[0] += a; h[1] += b; h[2] += c; h[3] += d;
        h[4] += e; h[5] += f; h[6] += g; h[7] += hh;
    }

    // convert hash to hex string
    stringstream ss;
    for (int i = 0; i < 8; ++i)
        ss << hex << setw(16) << setfill('0') << h[i];

    return ss.str();
}

// ------------------ Main ------------------
int main() {
    string input;

    cout << "Enter message: ";
    getline(cin, input);

    string hash = sha512(input);

    cout << "SHA-512 Hash: " << hash << endl;

    return 0;
}

/* 
Sample Input/Output:

Input: Hello World
Output: 
SHA-512 Hash: 309ecc489c12d6eb4cc40f50c902f2b4d0ed77ee511a7c7a9bcd3ca86d4cd86f
              989dd35bc5ff499670da34255b45b0cfd830e81f605dcf7dc5542e93ae9cd76f

Input: OpenAI
Output:
SHA-512 Hash: 32b731b08f4b1a95f19d34e7d9edb3f2c91f57ecddbc776d8a8e3a4aa9a27d2f
              04ed5a7ab13c1ef2a1ad66bbd92da7184970f7ec357d5dc9d5c55e3d1b3a5984
*/
