#include <stdio.h>
 #define LIMITE 25
 #define FALSE 0
 #define TRUE 1
 
 int procura(int x[], int a, int limInf, int limSup)
 {
     int meio;
     if (limInf > limSup) return FALSE;
     else
     {
         meio = (limInf + limSup) / 2;
         if (a < x[meio]) return procura(x, a, limInf, meio - 1);
         else
             if (a > x[meio]) return procura(x, a, meio + 1, limSup);
             else return TRUE;
     }
 }
 
 int main(void)
 {
  22     int a, i, n, seq[LIMITE];
     scanf("%d", &n);
     if (n < LIMITE)
     {
         for (i = 0; i < n; i = i + 1) scanf("%d", &seq[i]);
         scanf("%d", &a);
         if (procura(seq, a, 0, n - 1)) printf("Esta' la'");
         else printf("Nao esta' na sequencia");
     }
     else printf("Vetor excessivamente grande!");
     putchar('\n');
     return 0;
 }