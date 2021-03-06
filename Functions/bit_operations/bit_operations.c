/************************************************************
* REGISTERS
************************************************************/
#define REGISTER0                   (0x67F1)
#define REGISTER1                   (0xE7F2)
#define REGISTER2                   (0x05CE)

/************************************************************
* STANDARD BITS
************************************************************/

#define BIT0                        (0x0001)
#define BIT1                        (0x0002)
#define BIT2                        (0x0004)
#define BIT3                        (0x0008)
#define BIT4                        (0x0010)
#define BIT5                        (0x0020)
#define BIT6                        (0x0040)
#define BIT7                        (0x0080)
#define BIT8                        (0x0100)
#define BIT9                        (0x0200)
#define BITA                        (0x0400)
#define BITB                        (0x0800)
#define BITC                        (0x1000)
#define BITD                        (0x2000)
#define BITE                        (0x4000)
#define BITF                        (0x8000)

//Set bit
REGISTER0 |= BIT0;
//or
number |= 1 << x;

//Clear bit
REGISTER1 &= ~BIT1;
//or
number &= ~(1 << x);

//Toggle bit
REGISTER2 ^= BIT2;
//or
number ^= 1 << x;

//Check bit
unsigned char bit = REGISTER0 & BIT0;
//or
bit = number & (1 << x);
