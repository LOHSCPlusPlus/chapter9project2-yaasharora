#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

//Cereal struct that includes all variables
struct Cereal {
enum {MAX_CHAR_LEN = 500};
char Name[MAX_CHAR_LEN];
double Calories;
int Protein;
double Fat;
double Sodium;
double Fiber;
double Carbohydrates;
double Sugar;
double Serving;
Cereal();
};

//default constructor
Cereal::Cereal() {
  Calories = 0.0;
  Protein = 0.0;
  Fat = 0.0;
  Sodium = 0.0;
  Fiber = 0.0;
  Carbohydrates = 0.0;
  Sugar = 0.0;
  Serving = 0.0;
}
const int MAX_NUM_CEREALS = 100;
//reads each cereal
Cereal readCereal(ifstream &inFile){
  Cereal Cereal;
    inFile.get(Cereal.Name, Cereal::MAX_CHAR_LEN, ';');
    inFile.ignore(100,';');
    inFile >> Cereal.Calories;
    inFile.ignore(100,';');
    inFile >> Cereal.Protein;
    inFile.ignore(100,';');
    inFile >> Cereal.Fat;
    inFile.ignore(100,';');
    inFile >> Cereal.Sodium;
    inFile.ignore(100,';');
    inFile >> Cereal.Fiber;
    inFile.ignore(100,';');
    inFile >> Cereal.Carbohydrates;
    inFile.ignore(100,';');
    inFile >> Cereal.Sugar;
    inFile.ignore(100,';');
    inFile >> Cereal.Serving;
    inFile.ignore(100,'\n');
  return Cereal;
  }

//print function
void printCereal(Cereal temp){
   cout << temp.Name << ";" 
    << temp.Calories << ";" 
    << temp.Protein << ";" 
    << temp.Fat << ";" 
    << temp.Sodium << ";" 
    << temp.Fiber << ";" 
    << temp.Carbohydrates << ";" 
    << temp.Sugar << ";" 
    << temp.Serving << endl;
  }

//prints array
void printArrayToFile(const char fileName[], Cereal cereal[], int MAX_NUM_CEREALS) {
  ofstream outFile(fileName);
  for (int index = 0; index < MAX_NUM_CEREALS; index++) {
    printCereal(cereal[index]);
  }
}

//next two functions both copied from p1

 //checks if the input is valid and tells the user if it isn't
int intVal(const char val[]){
  //x is just a temporary value
    int x = 0;
    cout << val;
    cin >> x;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << val;
        cin >> x;
    }
    return x;
}

//same as int val
double doubleVal(const char val[]){
    int x = 0;
    cout << val;
    cin >> x;
    while (!cin) {
        cin.clear();
        cin.ignore(1000,'\n');
        cout << "Invalid Data!" << endl;
        cout << val;
        cin >> x;
    }
    return x;
}

//remove cereal index
void removeCereal(Cereal cereal[], int size){
  int num = 0;
  num = intVal("Enter index to remove: ");
  for (int count = num; count < (size-1); count++) {
    cereal[num] = cereal[1+num];
  }
}

// add cereal
void addCereal(Cereal list[], int num) {
  cout << "Enter the name: " << endl;
  cin.ignore(100,'\n');
  cin.getline(list[num].Name, Cereal::MAX_CHAR_LEN);
  list[num].Calories = doubleVal("Number of calories: ");
  list[num].Protein = doubleVal("Amount of protein: ");
  list[num].Fat = doubleVal("Amount of fat: ");
  list[num].Sodium = doubleVal("Amount of sodium: ");
  list[num].Fiber = doubleVal("Amount of fiber: ");
  list[num].Carbohydrates = doubleVal("Amount of carbohydrates: ");
  list[num].Sugar = doubleVal("Amount of sugar: ");
  list[num].Serving = doubleVal("Number of servings: ");
}

//prints cereals under 100 kcals
void printCerealByCal(Cereal cereal[], int listLength) {
  for(int num = 0; num < 100; num++) {
    if(cereal[num].Calories < 100 && cereal[num].Calories > 0) {
      printCereal(cereal[num]);
      cout << endl;
    }
  }
}
//prints ever cereals, including >100 kcals
void printCereals(Cereal cereal[], int listLength) {
  for (int num = 0; num < listLength; num++) {
    cout << "Index " << num;
    printCereal(cereal[num]);
    cout << endl;
  }
}
//reads the whole database
int readCerealData(Cereal cereal[]){
ifstream cerealFile("cereal.txt");
    int numCereal = 0;
    while(numCereal < MAX_NUM_CEREALS) {
        cereal[numCereal] = readCereal(cerealFile);
        numCereal++;
    }
    return numCereal;
}

//menu function
int menu() {
  int input = 0;
  cout << "Choose an option" << endl;
  cout << "1. Load list" << endl;
  cout << "2. Print list" << endl;
  cout << "3. Add cereal" << endl;
  cout << "4. Remove cereal" << endl;
  cout << "5. Print cereals with less than 100 kcals" << endl;
  cout << "6. Quit " << endl;
  input = intVal("");

  return input;
  }

//main
int main() {
  ifstream cerealFile("cereal.txt");
  Cereal list[MAX_NUM_CEREALS];
  int input = 0;
  int num = 0;

while (cerealFile.peek() != EOF) {
  list[num] = readCereal(cerealFile);
  num++;
  }
  

while(input != 7) {
  input = menu();
  
  switch(input) {
    case 1:
    printArrayToFile("cereal1.txt", list, num);
      break;
    case 2:
    printCereals(list, num);
      break;
    case 3:
    addCereal(list, num);
    num++;
      break;
    case 4:
    removeCereal(list, num);
    num--;
      break;
    case 5:
    printCerealByCal(list, num);
      break;
    case 6:
      break;

    default:
    cout << "Invalid" << endl;
      break;
    }
  }
  }
