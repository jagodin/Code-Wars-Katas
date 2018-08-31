/*

The drawing shows 6 squares the sides of which have a length of 1, 1, 2, 3, 5, 8. It's easy to see that the sum of the perimeters of these squares is : 4 * (1 + 1 + 2 + 3 + 5 + 8) = 4 * 20 = 80

Could you give the sum of the perimeters of all the squares in a rectangle when there are n + 1 squares disposed in the same manner as in the drawing:

#Hint: See Fibonacci sequence

#Ref: http://oeis.org/A000045

The function perimeter has for parameter n where n + 1 is the number of squares (they are numbered from 0 to n) and returns the total perimeter of all the squares.

perimeter(5)  should return 80
perimeter(7)  should return 216

*/

typedef unsigned long long ull;
class SumFct
{
  public:
  static ull perimeter(int n);
};

ull SumFct::perimeter(int n) {
  ull fibo[n+1];
  fibo[0] = 1;
  fibo[1] = 1;

  ull sum = fibo[0] + fibo[1];

  for (int i = 2; i < n+1; i++) {
   fibo[i] = fibo[i-1] + fibo[i-2];
   sum += fibo[i];
  }
  return sum*4;
}
