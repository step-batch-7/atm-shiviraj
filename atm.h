/* This function should accept the amount needed in cash 
   as input and return the number of notes per each of
   the following denominations:
   2000, 500, 100, 50, 20, 10, 5, 1
   The function can dispense a maximum of 15 notes per denomination. 
   Each hexa digit represents the number of notes for that denomination.

   Ex: 00000100 represents one 10 Rs note

   So the largest input you can accept based on the above denomination is 
   31999. Larger values than that should return 0.

  Here are some amounts and their return values
      1 0x00000001
     10 0x00000100
     39 0x00001114
    589 0x01011114
   2590 0x11012000
  31999 0xf3412014
*/
#define LIMIT_OF_AMOUNT 31999
#define DENOMINATIONS {2000, 500, 100, 50, 20, 10, 5, 1};

typedef unsigned int cash;
typedef unsigned int *cash_ptr;
typedef unsigned short int short_cash;

int get_unit(cash_ptr, int);
void get_denominations(cash, int *);
cash get_money(short_cash);

void print_note(int, short_cash, int);
void print_notes(int);