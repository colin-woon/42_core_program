void  ranking_numbers(int *numbers, int *stack_a, int size)
{
  int i;
  int compare_i;
  int rank;
  
  i = 0;
  while (i < size)
  {
    compare_i = 0;
    rank = 0;
    while (compare_i < size)
    {
      if (numbers[compare_i] <= numbers[i])
      {
        rank++;
        compare_i++;
      }
      stack_a[i] = rank;
      i++;
    }
  }
}