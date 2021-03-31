
#include <SPI.h>
#include <SD.h>


int var;                                                              //variable archivo .txt
int acabo;                                                            // variable para acabar progra
void printDirectory(void);
File myFile;                                                          // Lectura SD

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);                                                 // Velocidad en Baudios
  while(!Serial){
  ;                                                                   // A espera de conexión con puerto
}
  SPI.setModule(0);                                                   // Inicializacion de comunicación SPI
  Serial.println();
  Serial.println("Dando inicio a la memoria SD...");
  Serial.println();
 
    if (!SD.begin(4)){                     
      Serial.println("Inicio de memoria fallido...!");                // Inicio de SD fallido
    return;
}
  Serial.println("Inicio de SD correcto ");                           // Mensaje en la pantalla
  Serial.println();                                                
  Serial.println("* ARCHIVOS EN SD *");
  Serial.println();
  myFile = SD.open("/");                                              // Permite que el archivo en la SD se abra
  printDirectory(myFile, 0);                                          //Muestra el archivo dentro de la SD
  Serial.println("");
  Serial.println("************************************************");
  Serial.println("        Escoja el archivo que quiera ver        ");
  Serial.println("************************************************");
}

void loop() {
  // put your main code here, to run repeatedly: 
  while (acabo !=4){                                                    // Si el usuario no selecciona 4 el programa continua
if (Serial.available()>0){
  var = Serial.read();
   }
  if (var == '1'){                                                   // Primer archivo
    myFile = SD.open("FT.txt");                                   
    if (myFile){
      Serial.println();
      Serial.println("*****");
      Serial.println("                  FAIRY TAIL :v                   ");
      Serial.println("*****");
      
      while (myFile.available()){
        Serial.write(myFile.read());
      }
      myFile.close();
    }
    else{
      Serial.println("Error al abrir archivo .txt");
    }
      Serial.println();
      Serial.println("****************************************************************************");
      Serial.println("         Escoja nuevamente o seleccione 4 para acabar programa              ");
      Serial.println("****************************************************************************");
  }
  
if (var == '2'){
  myFile = SD.open("PI.txt");//segundo archivo
  if(myFile){
      Serial.println();
      Serial.println("********************************************");
      Serial.println("                PINGUI XD                   ");
      Serial.println("********************************************");
      
      while (myFile.available()){
        Serial.write(myFile.read());
    }
    myFile.close();
  }
  else{
    Serial.println("Error al abrir archivo .txt");
  }
      Serial.println();
      Serial.println("*******************************************************************");
      Serial.println("         Escoja nuevamente o seleccione 4 para acabar              ");
      Serial.println("*******************************************************************");
}

if(var == '3'){
  myFile = SD.open("CHA.txt");//tercer archivo
  if(myFile){
      Serial.println();
      Serial.println("*********************************************************");
      Serial.println("                  Cha Cha Charmander!!!                  ");
      Serial.println("*********************************************************");
      
    while (myFile.available()){
      Serial.write(myFile.read());
    }
    myFile.close();
  } else{
    Serial.println("Error al abrir archivo .txt");
  }
      Serial.println("*******************************************************************");
      Serial.println("         Escoja nuevamente o seleccione 4 para acabar              ");
      Serial.println("*******************************************************************");   
  } 
else if (var =='4'){                                                                              // Función para acabar el programa
  Serial.println("");
  Serial.println(" Fin de Programa ");
  acabo = 4;
}
else{}      
}
}
/*La funcion del vector para interrupciones asi como subrutinas para directorio de SD */

void printDirectory(File dir, int numTabs){                                                 // Función que muestra directorio
  while(true){                                                                              // Ya entra al directorio 
    File entry = dir.openNextFile();
    if(!entry){                                                                             // No hay más archivos
      break;
    }
    for (uint8_t i=0; i<numTabs; i++){ 
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()){
      Serial.println("/");
      printDirectory(entry, numTabs+1);
    }
    else{
                                                                                              // Mostrara el tamaño que tengan los archivos 
      Serial.print("\t\t");
      Serial.println(entry.size(), DEC);
    }
    entry.close();
  }
}
