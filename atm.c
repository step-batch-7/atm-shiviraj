#include <stdio.h>
#include "atm.h"

int get_unit(cash_ptr amount, int note)
{
  int unit = *amount / note;
  if (unit > 15)
  {
    unit = 15;
  }
  *amount = *amount - (unit * note);
  return unit;
}

void get_denominations(cash amount, int *notes)
{
  int denominations[] = DENOMINATIONS;
  for (int i = 0; i < 8; i++)
  {
    int note_unit = get_unit(&amount, denominations[i]);
    *notes = ((*notes << 4) | note_unit);
  }
}

cash get_money(short_cash amount)
{
  int notes = 0x00000000;
  if (amount <= LIMIT_OF_AMOUNT)
  {
    get_denominations(amount, &notes);
  }
  return notes;
};

void print_note(int notes_in_hex, short_cash note, int byte_no)
{

  int note_units = (notes_in_hex >> (byte_no * 4)) & 0x0f;
  if (note_units)
  {
    printf("\t%2d notes of Rs %d\n", note_units, note);
  }
}

void print_notes(int notes_in_hex)
{
  int denominations[] = DENOMINATIONS;
  for (int i = 0; i < 8; i++)
  {
    print_note(notes_in_hex, denominations[i], 7 - i);
  }
}