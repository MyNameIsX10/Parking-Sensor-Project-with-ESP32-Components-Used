import processing.serial.*; // Importa biblioteca "serial" din processing, care permite comunicarea seriala

// Declararea variabilelor
Serial myPort; // Obiect creeat pentru clasa Serial, va gestiona comunicarea pe port serial
String buffer =""; // Buffer pentru datele primite
int lastDistance = 400; // Valoarea implicita a distantei pentru vizibilitate

void setup(){
  size(800, 600); // Dimensiunea ferestrei
  myPort = new Serial(this, "COM3", 115200); // Inițializează portul la 115200 baud, specificând COM3
  background(0); // Fundalul negru
}

void draw(){
  background(0); // Reimprospateaza fundalul negru
  
  // Citirea si procesarea intregului buffer
  while(myPort.available() > 0){
    char inChar = myPort.readChar(); // Citeste caracterul curent
    buffer += inChar; // Adauga in buffer
    
    if(inChar =='\n'){ // Daca intalneste sfarsitul liniei
      processBuffer(); // Proceseaza bufferul
      buffer= ""; // Restarteaza bufferul
    }
  }
  
  // Daca nu s-au gasit date, foloseste distantele implicte pentru a mentine vizibilitatea semicercurilor
  displayDistance(lastDistance);
  
  // Afiseaza distanta detectata in partea de jos a ferestrei
  displayDistanceText(lastDistance);
}

void processBuffer(){
  buffer = trim(buffer); // Elimina spatiile albe de la inceput sau sfarsit
  println("Buffer: " + buffer); // Debugging pentru buffer
  if(buffer.startsWith("Distanta este: ")){ // Verifica daca linia incepe cu eticheta distantei
     String[] parts = split(buffer, " "); // Imparte sirul in parti
     if(parts.length > 2) {
       lastDistance = int(parts[2]); // Extrage valoare distantei
       println("Distanta detectata: " + lastDistance); // Debugging pentru valoarea distantei
     }
  }
}

void displayDistance(int distanta){
  // Dimensiuni si pozitii pentru semicercuri
  int x = width / 2; // Latimea Setează coordonata X a centrului ferestrei.
  int y = height / 2; // Setează coordonata Y a centrului ferestrei.
  int radius = 250; // Raza maxima a semicercurilor
  int offset = 30; // Dimensiunea cu care scade raza pentru fiecare semicerc
  
  // Definim culorile pentru fiecare zona de detectie
  int[] colors = {
    color(0, 255, 0), color(0, 255, 0), // Verde pt primele 2
    color(255, 255, 0), color(255, 255, 0), // Galben pentru urmatoarele 2
    color(255, 0, 0), color(255, 0, 0) // Rosu pentru ultimele 2
  };
  
  // Definim limitele pentru fiecare zona de detectie
  int[] limits = {60, 50, 40, 30, 20, 10};
  
  // Desenam semicercurile si le coloram in functie de distanta
  stroke(255); // Setam conturul alb
  strokeWeight(3); // Setam grosimea conturului
  for(int i = 0; i < 6; i++){
    if(distanta <= limits[i]){
      fill(colors[i]);
    } else {
      fill(100); // Culoarea gri pentru semicercurile inactive
    }
    // Afisam semicercurile unul peste altul, cu dimensiuni descrescatoare
    arc(x, y, radius - (i * offset), radius - (i * offset), PI, TWO_PI);
  }
}

// Functie pentru afisarea distantei detectate
void displayDistanceText(int distanta) {
  fill(255); // Seteaza culoarea textului la alb
  textSize(32); // Seteaza dimensiunea textului
  textAlign(CENTER, CENTER); // Alinerea textului pe centru
  text("Distanta: " + distanta + " cm", width / 2, height - 50); // Afiseaza distanta
}
