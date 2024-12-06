# cpp_exercise

To compile:
1. Check file under /usr/local/include/bits/stdc++.h. If file doesn't exist, create "bits" dir,
and copy the file from current dir over.
2. Execute ~/bin/genX.sh. If file doesn't exist, copy from current to ~/bin.

# For now following parameters are not used.
-02 : optimize code
-Wall: show warnings about possible errors.
-std=c++11 : c++ 11 standard
-std=c++17 : c++ 17 standard

# Command to compile
$ genX.sh -g (Compile and generate main.cpp, debug with "lldb test")
$ genX.sh -s (Compile and generate sample.cpp, debug with "lldb stest")

Misc notes:
int : (-2^31 - 2^31-1) (-2 * 10^9 - 2 * 10^9 )
long long : (-2^63 - 2^63-1) (-9 * 10^18 - 9 * 10^18 )

* input size                        required time complexity *
n ≤ 10                                O(n!)
n ≤ 20O                               O(2n)
n ≤ 50O                               O(n3)
n ≤ 5000                              O(n2)
n ≤ 10^6                              O(n log n) or O(n)
n is larger                           O(1) or O(log n)

* Power of BITS *

Numbers are stored as binary bits in the memory so bits manipulation are alway faster.
Bitwise or operator     : |
Bitwise and operator    : &
Bitwise xor operator    : ^
Bitwise left shift      : <<
Bitwise right shift     : >>
Memset and its uses using function : sizeof()
Bitmask and use of Bitmask in Dynamic Programming [[subset DP]]
`
Some cool Tricks

n = n * 2 :: n = n << 1
n = n /2  :: n = n >> 1
checking if n is power of 2 (1,2,4,8…) ::checking !(n & (n-1))
if x is max power of 2 dividing n, then x = (n & -n)
Total number of bits which are set in n = __builtin_popcount(n)
setting xth bit of n  :: n |= (1<<x)
checking if xth bit of n is set :: checking if  n&(1<<x) is non zero
