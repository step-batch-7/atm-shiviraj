void get_denomination_unit(char *notes_ptr, int tenth_digit, int unit_digit)
{
  *notes_ptr = tenth_digit * 16 + unit_digit;
}

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

void get_denominations(int amount, char *notes_ptr)
{
  int denomination[8] = {2000, 500, 100, 50, 20, 10, 5, 1};
  int index = 0;
  for (int i = 3; i >= 0; i--)
  {
    int tenth_digit = get_unit(&amount, denomination[index++]);
    int unit_digit = get_unit(&amount, denomination[index++]);
    get_denomination_unit((notes_ptr + i), tenth_digit, unit_digit);
  }
}

unsigned int get_money(unsigned short int amount)
{
  int notes = 0x00000000;
  if (amount < 40290)
  {
    char *notes_ptr = &notes;
    get_denominations(amount, notes_ptr);
  }
  return notes;
};