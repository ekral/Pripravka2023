#include <stdlib.h>
#include <assert.h>
#include <conio.h>
#include <ctype.h>
#include <stdbool.h>
#include <Windows.h>
#include <math.h>

struct Platno
{
    char* data;
    int pocetRadku;
    int pocetSloupcu;
    char pozadi;
    char popredi;
};

struct Bod2D
{
    int x;
    int y;
};

struct Ctverec
{
    struct Bod2D stred;
    int delkaStrany;
};

struct Trojuhelnik
{
    struct Bod2D bodA;
    struct Bod2D bodB;
    struct Bod2D bodC;
};

// Pokud je normalni stav, ze nebude dostatek pameti, napriklad ze matice bezne zabira nekolk GB pameti
bool try_matice_init(struct Platno* platno, int max_x, int max_y, char pozadi, char popredi)
{ 
    int pocetPrvku = max_x * max_y;
    platno->data = malloc(pocetPrvku * sizeof(char));
    
    if(platno->data == NULL)
    {
        return false;
    } 
    
    return true;
}

// Pokud je normalni stav, ze pamet bude, nekolik kilobajtu musi mit OS vzdy k dispozici
void platno_init(struct Platno* platno, int max_x, int max_y, char pozadi, char popredi)
{       
    int pocetPrvku = max_x * max_y;
    assert(max_x > 0);
    assert(max_y > 0);
    
    platno->data = malloc(pocetPrvku * sizeof(char));
    
    if(platno->data == NULL)
    {
        exit(EXIT_FAILURE);
    } 
    
    platno->pocetRadku = max_y; 
    platno->pocetSloupcu = max_x;
    platno->pozadi = pozadi;
    platno->popredi = popredi;
}

void platno_free(struct Platno* platno)
{
    free(platno->data);
    platno->data = NULL;
}

void platno_vymaz(struct Platno* platno)
{
    int pocetPrvku = platno->pocetRadku * platno->pocetSloupcu;
    
    for(int i = 0; i < pocetPrvku; i++)
    {
        platno->data[i] = platno->pozadi;
    }
}

void platno_vypis(struct Platno* platno)
{
    int pos = 0;
    for(int i = 0; i < platno->pocetRadku; i++)
    {
        for(int j = 0; j < platno->pocetSloupcu; j++)
        {
            char znak = platno->data[pos];
            putchar(znak);
            ++pos;
        }
        
        putchar('\n');
    }
}

void platno_nakresli_bod(struct Platno* platno, int x, int y)
{
    assert(x >= 0 && x < platno->pocetSloupcu);
    assert(y >= 0 && y < platno->pocetRadku);
    
    int pos = x + ((platno->pocetRadku - y - 1) * platno->pocetSloupcu); // PREDELAT
    platno->data[pos] = platno->popredi;
}

void platno_nakresli_usecku(struct Platno* platno, struct Bod2D bodA, struct Bod2D bodB)
{
    // zvoleny vypocet neni optimalni, ale jednoduchy
    
    double dx = (double)(bodB.x - bodA.x);
    double dy = (double)(bodB.y - bodA.y);
    
    // najit vetsi, pozor na zaporne hodnoty, asi budu porovnat absolutni
    // double max = abs(dx) > abs(dy) ? abs(dx) : abs(dy)
    double max = fmax(abs(dx), abs(dy));
    
    double step_x = dx / max;
    double step_y = dy / max;
    
    double x = bodA.x;
    double y = bodA.y;
    
    int max_i = (int)max;
    
    for(int i = 0; i < max_i; ++i)
    {
        platno_nakresli_bod(platno, x, y);
        
        x += step_x;
        y += step_y;
    }
}

void ctverec_nakresli(struct Ctverec* ctverec, struct Platno* platno)
{
    // TODO nakreslit ctverec
}

void trojuhelnik_nakresli(struct Trojuhelnik* trojuhelnik, struct Platno* platno)
{
    platno_nakresli_usecku(platno, trojuhelnik->bodA, trojuhelnik->bodB );
    platno_nakresli_usecku(platno, trojuhelnik->bodB, trojuhelnik->bodC );
    platno_nakresli_usecku(platno, trojuhelnik->bodA, trojuhelnik->bodC );
}

int main()
{    
    int max_x = 50;
    int max_y = 10;
    
    char pozadi = '-';
    char popredi = 'o';
    
    struct Platno platno;
    platno_init(&platno, max_x, max_y, pozadi, popredi); // init nebude mazat
    
    int x = 7;
    int y = 5;
    
    bool konec = false;
    
    struct Ctverec c1 = { (struct Bod2D) { 4, 7 }, 5 };
    struct Trojuhelnik t1 = { (struct Bod2D){ 2, 2 }, (struct Bod2D){ 5, 2 }, (struct Bod2D){ 5, 7 }};
    
    do
    {
        platno_vymaz(&platno); // nastavi znaky na pozadi
        
        platno.popredi = 'O';
        platno_nakresli_bod(&platno, 0, 0);
        
        platno.popredi = '1';
        platno_nakresli_bod(&platno, platno.pocetSloupcu - 1, platno.pocetRadku - 1);
        
        platno.popredi = popredi;
        
        trojuhelnik_nakresli(&t1, &platno);
        ctverec_nakresli(&c1, &platno);
        
        struct Bod2D bodA = { 1, 2 };
        struct Bod2D bodB = { 5, 6 };
        
        //platno_nakresli_usecku(&platno, bodA, bodB);
        
        platno_nakresli_bod(&platno, x, y); // nakresli pod znakem popredi

        COORD pos = {0, 0};
        HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleCursorPosition(output, pos);
        
        platno_vypis(&platno);
     
        int znak = _getch(); // Jen pro windows
        
        switch(znak)
        {
            case 'q':
                konec = true;
                break;
            case 'd':
                ++x;
                break;
            case 'a':
                --x;
                break;
            case 'w':
                --y;
                break;
            case 's':
                ++y;
                break;
        }
       
        
    } while(!konec);
    
    platno_free(&platno);
    
	return 0;
}
