# Letní programátorská přípravka 2023

TODO
- Ve čtvrtek ráno zopakovat ukazatele.
- Potom ve čtvrtek odpoledne projit struktury.
- V pátek zopakovat co dělalo studentům největší problémy.

## Ukazatele

- **Hodnota** jsou data v paměti s přiřazeným **typem** a **adresou**.
- **Pojmenovaná hodnota** v paměti je **proměnná**.
- S hodnotou v paměti můžu pracovat i jen **s pomocí její adresy**, nemusím být pojmenovaná.
- Typ proměnné ```adresa_hodnoty```, kde uvádíme typ hodnoty, naříklad  ```adresa_hodnoty_int```. 
- Operátor ```adresa_promenne(název proměnné)```.
- Operátor ```hodnota_na_adrese(adresa)```.
  
## Obsah prvního týdne programátorské přípravky

- Obsah prvního týdne programátorské přípravky: [github.com/tdulik/pripravka2023](https://github.com/tdulik/pripravka2023)
- Online reference pro jazyky C a C++: [cppreference.com](https://en.cppreference.com/w/).

## Přihlašovací údaje do PC v učebnách

login: **.\student**

heslo: **student**

Poznámka: znak \ je vedle levé klávesy shift.

## Přihlašovací údaje k WIFI

Název wifi sítě: **Programatorska_pripravka**

heslo: **2023programing**

## Vývojová prostředí

- [Erik Král](https://fai.utb.cz/contacts/ing-et-ing-erik-kral-ph-d/) používá [Visual Studio Community](https://visualstudio.microsoft.com/vs/community/).
- [Tomáš Dulík](https://fai.utb.cz/contacts/ing-tomas-dulik-ph-d/) používá Eclipse, [Codelite](https://codelite.org/) nebo [Clion](https://www.jetbrains.com/clion/).

Poznámka: V pc učebně je funkční jen Visual Studio 2019, verze 2022 nefunguje.

## Organizace kurzu

- 9:00 První blog výuky:
	- první hodina,
	- přestávka na kávu 10-15 minut,
	- druhá hodina.
- 11:00 Obědová přestávka (60 minut).
- 12:00 Druhý blog výuky:
	- třetí hodina,
	- přestávka na kávu 10-15 minut,
	- čtvrtá hodina.
- 14:00 Konec.

## Proměnná a její adresa

Operátor ```&```  vraci adresu promenne, například ```&x```.

Proměnná je pojmenovaná hodnota v paměti.

## Základní typy a aritmetické operace

- Typ ```int``` reprezenuje celé číslo se znaménkem, v jazyce C má minimálně dva bajty.
- Typ ```double``` reprezentuje číslo s desetinnou čárkou (spíše plovoucí řádková čárka, anglicky floating-point, typicky s binárním exponentem) a se znaménkem. Typycky zabíra 8 bajtů.
  
Výraz ```1 / 3``` vrací hodnotu ```0``` protože oba operandy jsou celá čísla, operace dělení je v tomto případě celočíselná.
Naproti tomu výrazy ```1 / 3.0```, ```1.0 / 3``` nebo ```1.0 / 3.0``` vrací číslo s desetinnou čárkou, protože alespoň jeden z operandů je číslo s desetinnou čárkou.

```c
double x1 = 1 / 3;
double x2 = 1 / 3.0;
double x3 = 1.0 / 3;
double x4 = 1.0 / 3.0;
```

Poznámka: V jazyce C se používá desetinná tečka, protože vychází z angličtiny.

## Základní vstupně výstupní operace

Pro výpis typu ```int``` používáme formátovací značku **%d**.

```c
int x = 0;
printf("%d", x);
```

Pro výpis typu ```double``` používáme formátovací značku **%lf**.

```c
double x = 0.0;
printf("%lf", x);
```

Pro vstup z terminálu **bez ověření správnosti** vstupu můžeme použít funkci ```scanf_s```, která má jako parametr adresu proměnné do které ukládá převedenou hodnotu z řetězce dle formátovací značky.

```c
int x = 0;
scanf_s("%d", &x);
```

```c
double x = 0.0;
scanf_s("%lf", &x);
```

Příkazy ```printf``` a ```scanf_s``` jsou deklarované v hlavičkovém souboru **stdio.h**.
 
---
Domácí úkoly

1. Zadejte hodnoty tří celých čísel a vypište jejich průměr.

---
Poznámky

- UNIX -> LINUX


