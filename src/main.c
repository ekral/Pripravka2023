#include <assert.h>
#include <stdbool.h>

bool arrayEqual(char original[], char kopie[], char pocetZnaku)
{
    assert(pocetZnaku > 0);
    
    // testuji, zda zacinaji na stejne adrese
    if(original == kopie)
    {
        return true;
    }
    
    // testuji zda maji stejne hodnoty
    for(int i = 0; i <= pocetZnaku; i++)
    {
        if(original[i] != kopie[i])
        {
            return false;
        }
    }
    
    return true;
}

void copyArray(char poleA[], char poleB[], char pocetZnaku)
{
    // 2. zkopiruje originalni pole do kopie
}

int main()
{
    const char * p = "ahoj";  // v readonly statickem bloku
   
    // pole se ukladaji na zasobnik, radove megabajty
    
    char poleA[3];              // prazdne neinicializovane pole, nevim jake hodnoty budou v poli
    char poleB[3] = { 0 };      // inicializovane na nuly, vsechny polozky budou 0
    char poleC[3] = { 1, 2, 3}; // inicializovane na konretni hodnoty
    char poleD[] = { 1, 2, 3};  // muzu vynechat pocet, kdyz inicializuji vsechny
    char poleE[5] = "ahoj";     // string initializations
    char poleF[] = "ahoj";      // string initializations
    
    assert(arrayEqual(poleE, poleE, 5));
    assert(arrayEqual(poleE, poleF, 5));
    
    char kopie[5];
    
    assert(arrayEqual(poleE, kopie, 5));
    
    copyArray(poleE, kopie, 5);
    
    assert(arrayEqual(poleE, kopie, 5));
    
    return 0;
}