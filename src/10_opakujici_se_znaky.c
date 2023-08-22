#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_LEN 256

int main()
{
    char pole[MAX_LEN];

    if(!gets_s(pole, MAX_LEN))
    {
        puts("Selhani");
        return 0;
    }
   
    // vypiste pocet opakujicich dvojic stejnych po sobe nasledujicich znaku. 
    // Hodnota v poli s konrektnim indexem muze byt soucasti jen jedne dvojice, nemuze byt soucasti vice dvojic.
    // napriklad "Zoo bylo uuuplne nejlepsi."
    // vypise hodnotu 2, protoze jsou tam dve dvojice, oo a uu.
    // Text "uuuplne nejlepsi" obsahuje jednu dvojici.
    // Text "uuuuplne nejlepsi" obsahuje dve dvojice.
    
    int i = 0;
    int pocetDvojic = 0;
    char znak;
    
    while(znak = pole[i])
    {
        if(znak == pole[i + 1])
        {
            pocetDvojic++;
            i++;
        }
        i++;
    }
    
    printf("Pocet dvojic: %d", pocetDvojic);
    
	return 0;
}
