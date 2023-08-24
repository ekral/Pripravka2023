#include <stdlib.h>
#include <assert.h>

struct Matice
{
    char* data;
    int pocetRadku;
    int pocetSloupcu;
};

void matice_init(struct Matice* matice, int max_x, int max_y, char znak)
{    
    int pocetPrvku = max_x * max_y;
    // pozadam OS o alokaci pameti pro pocetPrvku * sizeof(char) bajtu
    matice->data = malloc(pocetPrvku * sizeof(char)); 
    // matice-> je kratsi zapis pro (*matice). 
    matice->pocetRadku = max_x; 
    (*matice).pocetSloupcu = max_y;
    
    for(int i = 0; i < pocetPrvku; i++)
    {
        matice.data[i] = znak;
    }
}

void matice_vypis(struct Matice* matice)
{
    for(int i = 0; i < matice->pocetRadku)
    {
        for(int j = 0; j < matice->pocetSloupcu)
        {
            putchar(matice[i]);
        }
        
        putchar('\n');
    }
}

void matice_free(struct Matice* matice)
{
    free(matice->data);
    matice->data = NULL;
}

int main()
{
    int max_x = 50;
    int max_y = 20;
    
    struct Matice matice;
    matice_init(&matice, max_x, max_y, 'x');
    
    assert(matice.pocetRadku == max_x);
    assert(matice.pocetSloupcu == max_y);
    
    matice_free(&matice_free);
    
	return 0;
}
