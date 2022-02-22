#include <stdio.h>

int main()
{
    unsigned char num1;
    unsigned char num2;
    unsigned char num3;
    unsigned char num4;
    unsigned char num5;

    num1 = 4;   // 4: 0000 0100
    num2 = 4;   // 4: 0000 0100
    num3 = 4;   // 4: 0000 0100
    num4 = 4;   // 4: 0000 0100
    num5 = 4;   // 4: 0000 0100

    num1 &= 5;   // 5(0000 0101) AND 연산 이후 할당
    num2 |= 2;  // 2(0000 0010) OR 연산 이후 할당
    num3 ^= 3;  // 3(0000 0011) XOR 연산 이후 할당
    num4 <<= 2; // 비트를 왼쪽으로 2번 이동한 후 할당
    num5 >>= 2; // 비트를 오른쪽으로 2번 이동한 후 할당

    printf("%u\n", num1); // 4: 100, 101 and 100
    printf("%u\n", num2); // 6: 100, 010 or 110
    printf("%u\n", num3); // 7: 100, 011 xor 111
    printf("%u\n", num4); // 16: 100 을 두번 왼쪽으로 0001 0000
    printf("%u\n", num5); // 1: 100 두번 오른쪽 0000 0001
    return (0);
}
