#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Funcion para que muestra el inicio del del juego
void beginGame();
//Funcion que retorna un numero aleatorio
int randomNumber(vector<int>);
//Funcion que contiene los nombres de las cartas
void nameCards(string*);
//Funcion que contiene el valor de las cartas
void valueCards(int*);

int main ()
{
  //Arreglo de nombre de las cartas
  string* namecard = new string[52];
  nameCards(namecard);
  //Arreglo de valor de cada una de las cartas
  int* valuecard = new int[52];
  valueCards(valuecard);
  //Vector que contendra la posicion de las cartas de la persona
  vector<int> person;
  //Vector que contendra la posicion de las cartas de la computadora
  vector<int> pc;
  //variable para la respuesta si desea la persona desea mas cartas
  string answer="s";
  beginGame();
  //variable para el nombre de la persona
  string name;
  cout<<"Ingrese su nombre: ";
  cin>>name;
  //variable para acumular las sumas de las cartas de la persona
  int plusPerson = 0;
  //Boleanos para el control de las operaciones de las A
  bool clubs= false;
  bool diamonds = false;
  bool hearts = false;
  bool spades = false;
  //Turno de la persona
  while(answer=="s"){
    int random = randomNumber(person);
    person.push_back(random);
    plusPerson += valuecard[random];
    if (plusPerson>21) {
      for (int i=0; i<person.size(); i++){
        if (person[i]==0 && clubs==false) {
          plusPerson-=10;
          clubs=true;
        }else if (person[i]==13 && hearts==false) {
          plusPerson-=10;
          hearts=true;
        }else if (person[i]==26 && spades==false) {
          plusPerson-=10;
          spades=true;
        }else if (person[i]==39 && diamonds==false) {
          plusPerson-=10;
          diamonds=true;
        }
      }
    }else if (plusPerson==21){
      cout<<"Usted es el ganador " << name << endl;
      break;
    }
    cout<<"Su valor es mano es: " << plusPerson << endl;
    cout<<"Su mano es: " << endl;
    for (int i=0; i<person.size(); i++){
      cout<<namecard[person[i]] << ", ";
    }
    if (plusPerson>21) {
      cout<<"Usted a perdido " << endl;
      break;
    }
    cout<< endl << "Desea mas cartas (presione s para continuar/presione cualquier letra para salir): ";
    cin>> answer;
  }
  delete [] valuecard;
  delete [] namecard;
  return 0;
}

int randomNumber(vector<int> person)
{
  int number;
  srand(time(NULL));
  number = 1 + rand()%(52-1);
  for (int i=0; i<person.size(); i++){
    if (number==person[i]) {
      return randomNumber(person);
    }else{
      return number;
    }
  }
}

void beginGame()
{
  cout<<"******************************" << endl;
  cout<<"*Bienvenido al Casino Cerrato*"<< endl;
  cout<<"******************************"<< endl;
}

void nameCards(string* cards)
{
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
}

void valueCards(int* cards)
{
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
}
