#include <stdio.h>
#include <stdlib.h>

int main()
{
   int ch;
   FILE *fp;

   fp = fopen("chiffer.txt", "rb"); // read mode
   FILE *filj;
   filj = fopen("chifferhversjette.txt", "wb"); //write mode

   if (fp == NULL)
   {
      perror("Error while opening the file.\n");
      exit(EXIT_FAILURE);
   }

   int teller = 0;
   while(teller < 2453) {
     teller++;
     ch = fgetc(fp);
   }

   teller = 0;
   while((ch = fgetc(fp)) != EOF) {
     teller++;

     if(teller == 6) {
       printf("%i", ch);
       fputc(ch,filj);
     }
     /*else if(teller == 174) {
       printf("%i", ch);
       fputc(ch,filj);
     }*/
     else if(teller > 6) {
       teller = 1;
     }
     else if(teller > 7) {
       printf("\nOISANN\n");
     }
    }

   fclose(fp);
   return 0;
}
