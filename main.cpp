#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Funcion para que muestra el inicio del del juego
void beginGame();
//Funcion que retorna un numero aleatorio
int randomNumber();
//Funcion que contiene los nombres de las cartas
string* nameCards();
//Funcion que contiene el valor de las cartas
int* valueCards();
//Funciones para la eliminacion de memoria
void removeNamesCards(string*);
void removeValueCards(int*);

int main ()
{
  vector<int> person;
  vector<int> pc;
  string answer="s";
  beginGame();
  string name;
  cout<<"Ingrese su nombre:" ;
  getline(cin,name);
  cin.ignore(256,'\n');
  //Turno de la persona
  while(answer=="s"){
    int random = randomNumber();

  }
  return 0;
}

int randomNumber()
{
  int number;
  srand(time(NULL));
  number = 1 + rand()%(52-1);
  return number;
}

void beginGame()
{
  cout<<"******************************" << endl;
  cout<<"*Bienvenido al Casino Cerrato*"<< endl;
  cout<<"******************************"<< endl;
}

string* nameCards()
{
  string* cards = new string[52];
  cards[0] = "A trebol";
  cards[1] = "1 trebol";
  cards[2] = "2 trebol";
  cards[3] = "3 trebol";
  cards[4] = "4 trebol";
  cards[5] = "5 trebol";
  cards[6] = "6 trebol";
  cards[7] = "7 trebol";
  cards[8] = "8 trebol";
  cards[9] = "9 trebol";
  cards[10]= "J trebol";
  cards[11]= "Q trebol";
  cards[12]= "K trebol";
  cards[13]= "A corazones";
  cards[14]= "1 corazones";
  cards[15]= "2 corazones";
  cards[16]= "3 corazones";
  cards[17]= "4 corazones";
  cards[18]= "5 corazones";
  cards[19]= "6 corazones";
  cards[20]= "7 corazones";
  cards[21]= "8 corazones";
  cards[22]= "9 corazones";
  cards[23]= "J corazones";
  cards[24]= "Q corazones";
  cards[25]= "K corazones";
  cards[26]= "A espadas";
  cards[27]= "1 espadas";
  cards[28]= "2 espadas";
  cards[29]= "3 espadas";
  cards[30]= "4 espadas";
  cards[31]= "5 espadas";
  cards[32]= "6 espadas";
  cards[33]= "7 espadas";
  cards[34]= "8 espadas";
  cards[35]= "9 espadas";
  cards[36]= "J espadas";
  cards[37]= "Q espadas";
  cards[38]= "K espadas";
  cards[39]= "A diamantes";
  cards[40]= "1 diamantes";
  cards[41]= "2 diamantes";
  cards[42]= "3 diamantes";
  cards[43]= "4 diamantes";
  cards[44]= "5 diamantes";
  cards[45]= "6 diamantes";
  cards[46]= "7 diamantes";
  cards[47]= "8 diamantes";
  cards[48]= "9 diamantes";
  cards[49]= "J diamantes";
  cards[50]= "Q diamantes";
  cards[51]= "K diamantes";
  return cards;
}

int* valueCards()
{
  int* cards = new int[52];
  int counter1=1;
  int counter2=1;
  int counter3=1;
  int counter4=1;
  for (int i=0; i<52; i++){
    if (i==0 || i==13 || i==26 || i==39){
      cards[i]=11;
    }
    if (i>=1 && i<=9){
      cards[i]=counter1;
      counter1++;
    }
    if (i>=14 && i<=22){
      cards[i]=counter2;
      counter2++;
    }
    if (i>=27 && i<=35){
      cards[i] = counter3;
      counter3++;
    }
    if (i>=40 && i<=48){
      cards[i]=counter4;
      counter4++;
    }
    if (i>=10 && i<=12){
      cards[i]=10;
    }
    if (i>=23 && i<=25){
      cards[i]=10;
    }
    if (i>=36 && i<=38) {
      cards[i]=10;
    }
    if (i>=49 && i<=51) {
      cards[i]=10;
    }
  }
  return cards;
}

void removeNamesCards(sring* cards)
{
  delete [] cards;
}

void removeValueCards(int* cards)
{
  delete [] cards;
}
