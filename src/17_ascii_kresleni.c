#include <stdlib.h>
#include <assert.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <Windows.h>

struct Matice
{
    char* data;
    int pocetRadku;
    int pocetSloupcu;
    char pozadi;
    char popredi;
};

// Pokud je normalni stav, ze nebude dostatek pameti, napriklad ze matice bezne zabira nekolk GB pameti
bool try_matice_init(struct Matice* matice, int max_x, int max_y, char pozadi, char popredi)
{ 
    int pocetPrvku = max_x * max_y;
    matice->data = malloc(pocetPrvku * sizeof(char));
    
    if(matice->data == NULL)
    {
        return false;
    } 
    
    return true;
}

// Pokud je normalni stav, ze pamet bude, nekolik kilobajtu musi mit OS vzdy k dispozici
void matice_init(struct Matice* matice, int max_x, int max_y, char pozadi, char popredi)
{       
    int pocetPrvku = max_x * max_y;
    assert(max_x > 0);
    assert(max_y > 0);
    
    matice->data = malloc(pocetPrvku * sizeof(char));
    
    if(matice->data == NULL)
    {
        exit(EXIT_FAILURE);
    } 
    
    matice->pocetRadku = max_y; 
    matice->pocetSloupcu = max_x;
    matice->pozadi = pozadi;
    matice->popredi = popredi;
}

void matice_free(struct Matice* matice)
{
    free(matice->data);
    matice->data = NULL;
}

void matice_vymaz(struct Matice* matice)
{
    int pocetPrvku = matice->pocetRadku * matice->pocetSloupcu;
    
    for(int i = 0; i < pocetPrvku; i++)
    {
        matice->data[i] = matice->pozadi;
    }
}

void matice_vypis(struct Matice* matice)
{
    int pos = 0;
    for(int i = 0; i < matice->pocetRadku; i++)
    {
        for(int j = 0; j < matice->pocetSloupcu; j++)
        {
            putchar(matice->data[pos]);
            ++pos;
        }
        
        putchar('\n');
    }
}

void matice_nakresli_bod(struct Matice* matice, int x, int y)
{
    int pos = x + (y * matice->pocetSloupcu);
    matice->data[pos] = matice->popredi;
}

int main()
{    
    int max_x = 50;
    int max_y = 10;
    
    char pozadi = 'x';
    char popredi = 'o';
    
    struct Matice matice;
    matice_init(&matice, max_x, max_y, pozadi, popredi); // init nebude mazat
    
    int x = 7;
    int y = 5;
    
    bool konec = false;
    
    do
    {
        matice_vymaz(&matice); // nastavi znaky na pozadi
        
        matice_nakresli_bod(&matice, x, y); // nakresli pod znakem popredi

        COORD pos = {0, 0};
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(output, pos);
        
        matice_vypis(&matice);
     
        int znak = _getch(); // Jen pro windows
        
        if(znak == 'q')
        {
            konec = true;
        }
        else if(znak == 'd')
        {
            ++x;
        }
        
    } while(!konec);
    
    matice_free(&matice);
    
	return 0;
}
