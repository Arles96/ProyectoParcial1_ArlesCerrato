#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <time.h>

using namespace std;

//Funcion para que muestra el inicio del del juego
void beginGame();
//Funcion que retorna un numero aleatorio
int randomNumber(vector<int>, vector<int>);
//Funcion que contiene los nombres de las cartas
void nameCards(string*);
//Funcion que contiene el valor de las cartas
void valueCards(int*);
//Funcion que muestra el fin del juego
void gameover();

int main ()
{
  //Variable de respuesta de usuario si la persona desea continuar jugando
  string answergame = "s";
  while(answergame=="s"){
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
    cout<<"*Ingrese su nombre: ";
    cin>>name;
    //variable para acumular las sumas de las cartas de la persona
    int plusPerson = 0;
    //Boleanos para el control de las operaciones de las A
    bool clubs= false;
    bool diamonds = false;
    bool hearts = false;
    bool spades = false;
    //variable que almacena los numeros random
    int random=0;
    //Entrega de dos cartas a la persona
    //cout<<"Hla"<< endl;
    random = randomNumber(person, pc);
    person.push_back(random);
    plusPerson += valuecard[random];
    //Turno de la persona
    while(answer=="s"){
      random = randomNumber(person, pc);
      person.push_back(random);
      plusPerson += valuecard[random];
      for (int i=0; i<person.size(); i++){
        if (person[i]==0 && clubs==false && plusPerson>21) {
          plusPerson-=10;
          clubs=true;
        }else if (person[i]==13 && hearts==false && plusPerson>21) {
          plusPerson-=10;
          hearts=true;
        }else if (person[i]==26 && spades==false && plusPerson>21) {
          plusPerson-=10;
          spades=true;
        }else if (person[i]==39 && diamonds==false && plusPerson>21) {
          plusPerson-=10;
          diamonds=true;
        }
      }
      if (plusPerson==21){
        cout<< endl << "*Usted es el ganador " << name << endl;
        cout<< endl << "*Su valor en mano es: " << plusPerson << endl;
        cout<<"*Su mano es: " << endl;
        for (int i=0; i<person.size(); i++){
          cout<<namecard[person[i]] << ", ";
        }
        break;
      }
      cout<<"*Su valor en mano es: " << plusPerson << endl;
      cout<<"*Su mano es: " << endl << "* ";
      for (int i=0; i<person.size(); i++){
        cout<<namecard[person[i]] << ", ";
      }
      if (plusPerson>21) {
        cout<< endl << "*Usted a perdido " << endl;
        cout<< endl << "*Ha ganado la pc" << endl;
        break;
      }
      cout<< endl << "*Desea mas cartas: ";
      cin>> answer;

    }
    //Turno de la pc cuando la persona no ha ganado o perdido
    if (plusPerson<21){
      //Acumulador de la suma de las cartas de la pc
      int plusPc = 0;
      //reutilizando los booleanos que controlan las operaciones de la A
      clubs = false;
      hearts = false;
      diamonds = false;
      spades = false;
      //Variable que almacena los numeros aleatorios para la pc
      int random2;
      //Entrega de la primera carta a la pc
      random2 = randomNumber(person,pc);
      plusPc+=valuecard[random2];
      pc.push_back(random2);
      //turno de la pc
      while (true){
        random2 = randomNumber(person,pc);
        plusPc+=valuecard[random2];
        pc.push_back(random2);
        random2 = randomNumber(person,pc);
        plusPc+=valuecard[random2];
        pc.push_back(random2);
        for (int i=0; i<pc.size(); i++){
          if (pc[i]==0 && clubs==false && plusPc>21) {
            plusPc-=10;
            clubs=true;
          }else if (pc[i]==13 && hearts==false && plusPc>21) {
            plusPc-=10;
            hearts=true;
          }else if (pc[i]==26 && spades==false && plusPc>21) {
            plusPc-=10;
            spades=true;
          }else if (pc[i]==39 && diamonds==false && plusPc>21) {
            plusPc-=10;
            diamonds=true;
          }
        }
        if (plusPc>plusPerson && plusPc<=21){
          cout<< endl << "*El ganador es la pc" << endl;
          break;
        }
        if (plusPc>21){
          cout << endl <<"*La pc ha perdido" << endl << "*El ganador es " << name << endl;
          break;
        }

      }
      //Imprimiendo la sumatoria de los valores de la cartas de la pc
      cout<<"*El total de la suma de las cartas de la pc es " << plusPc << endl;
      cout<<"*Las cartas que contiene la pc es" << endl << "* ";
      for (int i=0; i<pc.size(); i++){
        cout<< namecard[pc[i]] << ", ";
      }
      cout << endl;
    }
    cout<< endl << "*Desea continuar jugando: ";
    cin>>answergame;
    delete [] valuecard;
    delete [] namecard;
  }
  gameover();
  return 0;
}

int randomNumber(vector<int> person, vector<int> pc)
{
  int number;
  srand(time(0));
  number =rand()%52;
  if (person.size()>=0 || pc.size()>=0){
    for (int i=0; i< person.size();i++){
      if (number==person[i]){
        number = rand()%52;
        i--;
      }
    }
    for (int i = 0; i<pc.size(); i++){
      if (number==pc[i]) {
        number = rand()%52;
        i--;
      }
    }
  }
  return number;
}

void beginGame()
{
  cout<< endl ;
  cout<<"***********************************" << endl;
  cout<<"*Bienvenido al Casino Cesar Palace*"<< endl;
  cout<<"***********************************"<< endl;
  cout<<"*******Observacion del juego*******"<< endl;
  cout<<"*1- Presione s para continuar     *"<< endl;
  cout<<"*2- Presione otra tecla para salir*"<< endl;
  cout<<"*3- Disfrute del juego            *" << endl;
  cout<<"***********************************" << endl;
}

void nameCards(string* cards)
{
  cards[0] = "A trebol";
  cards[1] = "2 trebol";
  cards[2] = "3 trebol";
  cards[3] = "4 trebol";
  cards[4] = "5 trebol";
  cards[5] = "6 trebol";
  cards[6] = "7 trebol";
  cards[7] = "8 trebol";
  cards[8] = "9 trebol";
  cards[9] = "10 trebol";
  cards[10]= "J trebol";
  cards[11]= "Q trebol";
  cards[12]= "K trebol";
  cards[13]= "A corazones";
  cards[14]= "2 corazones";
  cards[15]= "3 corazones";
  cards[16]= "4 corazones";
  cards[17]= "5 corazones";
  cards[18]= "6 corazones";
  cards[19]= "7 corazones";
  cards[20]= "8 corazones";
  cards[21]= "9 corazones";
  cards[22]= "10 corazones";
  cards[23]= "J corazones";
  cards[24]= "Q corazones";
  cards[25]= "K corazones";
  cards[26]= "A espadas";
  cards[27]= "2 espadas";
  cards[28]= "3 espadas";
  cards[29]= "4 espadas";
  cards[30]= "5 espadas";
  cards[31]= "6 espadas";
  cards[32]= "7 espadas";
  cards[33]= "8 espadas";
  cards[34]= "9 espadas";
  cards[35]= "10 espadas";
  cards[36]= "J espadas";
  cards[37]= "Q espadas";
  cards[38]= "K espadas";
  cards[39]= "A diamantes";
  cards[40]= "2 diamantes";
  cards[41]= "3 diamantes";
  cards[42]= "4 diamantes";
  cards[43]= "5 diamantes";
  cards[44]= "6 diamantes";
  cards[45]= "7 diamantes";
  cards[46]= "8 diamantes";
  cards[47]= "9 diamantes";
  cards[48]= "10 diamantes";
  cards[49]= "J diamantes";
  cards[50]= "Q diamantes";
  cards[51]= "K diamantes";
}

void valueCards(int* cards)
{
  //Contador de los treboles
  int counter1=2;
  //Contador de los corazones
  int counter2=2;
  //Contador de las espadas
  int counter3=2;
  //Contador de los diamantes
  int counter4=2;
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

void gameover(){
  cout<< endl;
  cout<<"***********************************" << endl;
  cout<<"*********EL JUEGO TERMINO**********" << endl;
  cout<<"***********************************" << endl;
  cout << endl;
}
