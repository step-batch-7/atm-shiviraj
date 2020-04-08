#include "atm.h"

int get_unit(int *amount, int note)
{
  int unit = *amount / note;
  if (unit > 15)
  {
    unit = 15;
  }
  *amount = *amount - (unit * note);
  return unit;
}

void get_denominations(int amount, int *notes)
{
  int denominations[] = DENOMINATIONS;
  for (int i = 0; i < 8; i++)
  {
    int note_unit = get_unit(&amount, denominations[i]);
    *notes = ((*notes << 4) | note_unit);
  }
}

unsigned int get_money(unsigned short int amount)
{
  int notes = 0x00000000;
  if (amount <= LIMIT_OF_AMOUNT)
  {
    get_denominations(amount, &notes);
  }
  return notes;
};