/ VJEZBA 11
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define FILE_NAME_LEN 129
#define BUFFER_LEN 512               //max 512 znakova u liniji, 4. zadatak
#include  <string.h>
#include <ctype.h>
#define DULJNAZIVADATOT 129         //max duljina naziva datoteke
#define FILE_NAME_LEN 129
#define NAME_LEN 64
#define MAX_ROWS 100

void vjezba1();
void vjezba2();
void vjezba3();
void vjezba4();
int main()
{
    //vjezba1();      
                      /*Nap program koji kop sadržaj 1 datot u 2. datot.
                           Nazive obiju datot treba unijeti korisnik, a unose se u main() fji.
                           Kop sadržaja datot treba implementirati u fji copyFileContent().*/
                           //vjezba2();
                                                  /*Nap program koji iz datot èita znamenke sve dok ne proèita podatak koji nije
                                             znam ili dok ne dosegne kraj datot.Proèitane znamenke treba pretvoriti u
                                         cijeli br i ispisati ga u konzolu.
                                         Èitanje datot treba obaviti znak po znak.
                                         Naziv datot treba unijeti korisnik, a unosi se u main() fji.
                                         Èitanje datot treba implementirati u fji readFile(), a ispis br u konzolu
                                         treba implementirati u fji printParsedNumber()*/
                                         //vjezba3();
                                                           /*Nap program koji iz datot èita podatke o max. 100 osoba (ime, prezz i
                                                                god roð). Zatim u konzoli treba ispisati koliko se osoba zove Ana.
                                                                Naziv datot treba unijeti korisnik, a unosi se u main() fji.
                                                                Èitanje podataka iz datot treba implementirati u fje readDataFromFile().
                                                                Prebrojavanje osoba treba implementirati u fji countPeopleWithFirstName(),
                                                                a ispis broja osoba treba implementirati u main() fji.*/
    vjezba4();
    /*Nap program koji iz datot èita 1 redak podataka. Zatim podatke iz proè
         retka ispisuje rijeè po rijeè u konzolu. Svaka rijeè mora biti ispisana u zasebnom retku.
         Naziv datot treba unijeti korisnik.*/

    return 0;
}



//ZADATAK1
//deklaracija fje
int kopiranjedatot(char*, char*);             //fja, vraca int a prima 2 stringa                                        

//main fja
void vjezba1()
{
    char imedatot1[DULJNAZIVADATOT] = "\0";              //kreiramo 2 stringa (1 za citanje, 1 za pisanje)
    char imedatot2[DULJNAZIVADATOT] = "\0";
    int result = 0;
    printf("unesi nazive datoteka: \n");                 //pitamo korisnika da unese nazive datot
    printf("citanje: \t");
    scanf("%s", imedatot1);
    printf("pisanje: \t");
    scanf("%s", imedatot2);
    result = kopiranjedatot(imedatot1, imedatot2);        //pozivanje fje koja ce vrsiti kopiranje, prima 2 parametra, ta fja vraca neku vrijednost tj nekakav result tkd znamo jl se kop uspjesno izvrsilo ili ne
    if (result == 0)                                     //ovisno o resultu cemo ispisati jeli kopp uspjesno izvrseno ili nije      
    {
        printf("kopiranje je uspjesno \n");
    }
    else
    {
        printf("kopiranje nije uspjesno \n");
    }

    return;
}
//deff fje
int kopiranjedatot(char* imedatot1, char* imedatot2)     //kreiramo 2 file pointera i otvarao file
{
    FILE* imedatot1File = NULL; //2 file pointera
    FILE* imedatot2File = NULL;
    char buffer = 0;                                     //sadrzaj filea cemo citati znak po znak, citan znak iz 1 filea zapisen ga u buffer i onda ga nakon toga proslijedin u drugi file
    imedatot1File = fopen(imedatot1, "r");               //otvaramo svaki od ta 2 filea(saljemo ime i otvaramo ga u modu za citanje tj r
    if (imedatot1File == NULL)
    {
        return -1;                                       //znaci da je doslo do greske, file se nije uspjesno otvorio
    }
    imedatot2File = fopen(imedatot2, "w");               //w jer zelim pisati u taj file
    if (imedatot2File == NULL)
    {
        fclose(imedatot1File);                          //moramo zatvorit prvi file kako bi mogli zatvoriti drugi, jr ako drugi ne valja ond se i prvi mora zatvorit kako bi program presta s radom
        return -1;
    }

    while ((buffer = fgetc(imedatot1File)) != EOF)  //u while petlji se prvo pozove buffer=fgetc i vrijednosti iz filea se zapp u buffer, nakon toga se provjeraje jl buffer razlicit od end of dfile, ako je razlicit ond ulazimo u tijelo while petlje, a ako nije izlazimo
    {
        fputc(buffer, imedatot2File);
    }
    fclose(imedatot1File);         //zatvaramo oba filea
    fclose(imedatot2File);
}
//citanje iz 1 filea i pisanje u drugi
/*do {
buffer = fgetc(imedatot1File);                //prima filepointer i vraca znak, to stavljamo u do while petlju jer sigg moramo procitat samo 1 znak, nakon sto smo procitali taj znak iz source filea moramo provjerit jeli buffer tj znak razlicit od znaka file end of file
if (buffer != EOF)                               //ako razlicit od eof triba ga zapp u drugi file
{
fputc(buffer, imedatot2File);              //fja za zapp 1 znaka u file ( prima znak i pointer)
}
else
{
break;
}
} while (1);
}
*/








//ZADATAK2
void vjezba2()
{
    char filename[DULJNAZIVADATOT] = "\0";     //varijabla s nazivom datoteke, duljine je duljnazivadatot
    char buffer = '\0';                             //za citanje sadrzaja datoteke
    int broj = 0;
    FILE* filepetlja = NULL;
    printf("unesi ime file-a \n");
    scanf("%s", filename);
    filepetlja = fopen(filename, "r");     //ovaramo ga u modu za citanje tj r, u zagradi moramo  upisati naziv filea
    if (filepetlja == NULL)                                       //provera jesmo stvarno otvorili taj file
    {
        printf("file se nije otvorio \n");
        return;
    }
    while (!feof(filepetlja))        //dok god nismo dosli do kraja filea, trebamo procitat 1 znak iz filea
    {
        buffer = fgetc(filepetlja);
        if (isdigit(buffer))         //da provj jl vrijednost koju smo unijeli tj vrijednost koju smo proc iz filea jeli razlicita od znamenke, i to zapp u neki br tj integer
        {
            broj *= 10;            //pretvaramo ju u int vrijednost
            broj += buffer - '0';   //0 ide da nam se nebi ispisala ascii vrijednost znaka
        }
        else
        {
            break;      //da ne cita druge znakove iza greske ako nade neku gresku
        }
    }
    fclose(filepetlja);     //moramo zatvorit petlju tj file
    printf("broj iz filea je %d \n", broj);
    return;
}




//ZADATAK 3

typedef struct _Person {                 //struktura osoba, ima 3 podatka tj ime prezz i god rodenja
    char firstName[NAME_LEN];
    char lastName[NAME_LEN];
    int yearOfBirth;
} Person;
//deklaracije fje
int readData(char*, Person*);
int countPeopleByName(Person*, int, char*); //prima 2 parametra, niz osoba, zbroj ljudi, ime koje trazimo
//main fja
void zadatak3() {
    char filename[FILE_NAME_LEN] = "\0";
    Person people[MAX_ROWS];                  //max sto redaka
    int peopleCount = 0;                       //gleda koliko ljudi ima u datoteci tj koliki broj
    int anaCount = 0;
    printf("Unesi naziv file-a\n");
    scanf(" %s", filename);
    peopleCount = readData(filename, people); //fja read data vraca people count
    if (peopleCount < 0) {
        printf("greska\n");
        return;
    }
    else if (peopleCount == 0) {
        printf("File je prazan\n");
        return;
    }
    anaCount = countPeopleByName(people, peopleCount, "Ana"); //fja koja racuna koliko ima osoba koje se nazz ana, saljemo joj 3 parametra, 1.niz struktura osoba 2. broj osoba koliko smo ih procitali 3.naziv osobe koju trazimo
    printf("U file-u se nalazi %d osoba imena Ana\n", anaCount);
    return;
}
int readData(char* filename, Person* people) {
    FILE* fp = NULL;          //file pointer
    int counter = 0;                    //counter koji zapp koliko smo osoba procitali
    fp = fopen(filename, "r");         //za citanje
    if (fp == NULL) {                        //ako file nije otvoren
        return -1;
    }
    while (!feof(fp) && counter < 100) { //traje sve dok nismo dosli do file end of file, mozemo proc max sto osoba
        fscanf(fp, " %s %s %d", people[counter].firstName, people[counter].lastName, &people[counter].yearOfBirth);    //s njom citamo sadrzaj datot tj ime prezime i godinu rodenja
        counter++;

    }
    fclose(fp);
    return counter;          //fja treba vratit broj osoba
}
int countPeopleByName(Person* people, int counter, char* name) {
    int i = 0;
    int nameCount = 0;             //koliko osoba ima naziv ana
    for (i = 0; i < counter; i++) {
        if (strcmp(people[i].firstName, name) == 0) {
            nameCount++;
        }
    }
    return nameCount;
}




//zadatak4
void vjezba4()
{
    char filename[FILE_NAME_LEN] = "\0";
    FILE* fp = NULL;                             //za otvorit file
    char buffer[BUFFER_LEN] = "\0";
    char* word = NULL;
    printf("Unesi naziv file-a\n");
    scanf(" %s", filename);
    fp = fopen(filename, "r");   //otvaramo ga u read jr ga zelimo procitati
    if (fp == NULL) {
        printf("ERROR!\n");
        return;
    }
    if (!feof(fp)) {                                  //provjera jesmo dosli do kraja filea
        fgets(buffer, BUFFER_LEN - 1, fp);      //ako nismo dosli do kraja filea trebamo procitati 1 redak, saljemo buffer, max duljina znakova u bufferu i file pointer
        word = strtok(buffer, " "); //strtok prima 1 string, vrati niz stringova koji su razdijeljeni
        while (word != NULL) {
            printf("%s\n", word);
            word = strtok(NULL, " "); //razmak, jr smo s njim razbijali rijeci na vise dijelova
        }
    }
    fclose(fp);
    return;

}
