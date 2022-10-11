#include <stdio.h>

int main(void) {
  int num = 123, numInv = 0, centena, unidade, dezena, result, resultInv,
      totalresult;
  for (int i = 1; num < 1000; num++) {
    centena = num / 100;
    unidade = num % 10;
    dezena = (num / 10) - (centena * 10);
    if (centena != unidade && unidade != dezena && dezena != centena &&
        unidade != 0 && centena != 0 && dezena != 0) {
      numInv = centena + dezena * 10 + unidade * 100;
      if (numInv > num) {
        result = numInv - num;
      } else {
        result = num - numInv;
      }
      centena = result / 100;
      dezena = (result / 10) - (centena * 10);
      unidade = result % 10;
      resultInv = centena + dezena * 10 + unidade * 100;
      totalresult = resultInv + result;
      if (numInv > num) {
        printf("caso %3d: %3d-%3d=%3d, %3d+%3d=%3d\n", i, numInv, num, result,
               result, resultInv, totalresult);
        i++;
      } else {
        printf("caso %3d: %3d-%3d=%3d, %3d+%3d=%3d\n", i, num, numInv, result,
               result, resultInv, totalresult);
        i++;
      }
    } else {
    }
  }
}
