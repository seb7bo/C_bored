/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

typedef unsigned char uint8;
enum elanguage
 {
     eSpanish,
     eEnglish
 };
typedef enum elanguage tlanguage;

static void count_letters_in_txt(uint8 *ptext, tlanguage language,uint8 *alphabet)
{
    uint8 *plocal = ptext;
    uint8 index = 0;
    uint8 localIndex = 0;
    while(plocal[index] != '\0')
    {
     
         if((uint8)96<plocal[index] && (uint8)123 > plocal[index])
         {
            localIndex = plocal[index] - (uint8)97;
            alphabet[localIndex] += 1;
         }
         else if((uint8)64<plocal[index] && (uint8)91 > plocal[index])
         {
            localIndex = plocal[index] - (uint8)65; 
            alphabet[localIndex] += 1;
         }
         else
         {
             alphabet[26]+=1;
         }
         index++;
    }
}

static void print_no_letters(tlanguage language,uint8 *alphabet)
{
    uint8 i;
    for(i = 0; i<27; i++)
    {
        printf("Letter %c No %d \n",(i+65),alphabet[i]);
    }
}

int main()
{
    uint8 alphabet_english[27] = {0};
    uint8 text[] = {"Asi quiero tapar el patio de atras, y unas protecciones en las ventanas chicas de los cuartos de atras"};
    count_letters_in_txt(&(text[0]),eEnglish,&(alphabet_english[0]));
    print_no_letters(eEnglish,&(alphabet_english[0]));

    return 0;
}
