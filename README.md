# Proiect Senzor de Parcare cu ESP32

## Componente utilizate

- **ESP32**: Microcontroller care gestionează senzorul ultrasonic, LED-urile și buzzer-ul.
- **Senzor ultrasonic HC-SR04**: Măsoară distanța față de un obstacol.
- **Buzzer**: Emite sunete de avertizare pe măsură ce distanța față de obstacol scade.
- **6 LED-uri**: Două LED-uri verzi, două galbene și două roșii care indică distanța de parcare.
  - **Verzi**: Obiectul este la o distanță mai mare, sigură.
  - **Galbene**: Atenție, obiectul este la o distanță mai apropiată.
  - **Roșii**: Pericol, obiectul este foarte aproape.
- **Interfață grafică în Processing**: Afișează grafic un senzor de parcare stilizat, utilizând 6 semicercuri pentru a reprezenta diferite intervale de distanță.

## Funcționalitate

- **Măsurarea distanței**: Senzorul ultrasonic măsoară distanța dintre senzor și obstacol.
  - **Intervale de distanță**:
    - **60 cm**: Primul LED verde se aprinde.
    - **50 cm**: Ambele LED-uri verzii sunt aprinse.
    - **40 cm**: Primul LED se aprinde.
    - **30 cm**: Ambele LED-uri galbene sunt aprinse.
    - **< 10 cm**: Toate LED-urile roșii sunt aprinse.

- **Indicație sonoră**: Buzzer-ul emite semnale sonore cu frecvență în creștere pe măsură ce distanța față de obiect scade, ajutând la avertizarea utilizatorului.

- **Interfață grafică în Processing**: 
  - Am creat o interfață grafică stilizată a unui senzor de parcare, folosind 6 semicercuri, fiecare corespunzând unui interval de distanță. Semicercurile își schimbă culoarea în funcție de distanța măsurată de senzorul ultrasonic:
    - **Verzi** pentru distanțe sigure (> 60 cm),
    - **Galbene** pentru distanțe moderate (20-40 cm),
    - **Roșii** pentru distanțe periculoase (< 20 cm).

- **Comunicare ESP32 cu Processing**: Interfața grafică și ESP32 comunică prin port serial. ESP32 trimite date despre distanță către Processing, care actualizează vizualizarea grafică în timp real.


## Codul sursă

- **Firmware ESP32**: Codul ESP32 se ocupă de măsurarea distanței cu senzorul ultrasonic, aprinderea LED-urilor și activarea buzzer-ului în funcție de distanța detectată. Datele despre distanță sunt trimise la PC prin serial pentru a fi procesate de aplicația Processing.
- **Aplicație Processing**: Codul din Processing interpretează datele primite de la ESP32 și actualizează interfața grafică, oferind un feedback vizual în timp real despre distanța până la obstacol.

