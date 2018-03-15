
#include <StepperDriver.h>
#define EN        8
/* Identificatori di assi all'interno della libreria; su loro poi
 * Puoi controllare uno specifico. Gli assi possono essere fatti diversi,
 * Il numero massimo nell'assembly nativo è 3. Viene gestito modificando
 * hederfail, c'è una costante NUM_AXSIS
*/
axis_t right, left;

void setup ()
{
  pinMode(EN, OUTPUT);

  digitalWrite(EN, LOW);
  // Inizializzazione driver: timer
  StepperDriver.init ();

/* Registrare gli assi controllati. Qui in ordine
   * ci sono tre numeri di pin: STEP, DIR, ENABLE.
   * Se ENABLE non è necessario o non esiste, immettere 255,
   * questo valore è uno stub. Il quarto valore è il numero di passi per giro
   * Al motore.
*/
  left = StepperDriver.newAxis (2, 5, 255, 200);
  right = StepperDriver.newAxis (3, 6, 255, 200);

// StepperDriver.disable (asse);

  StepperDriver.enable(left);
  StepperDriver.enable(right);

/* Inizializzazione dello chassis: trasferimento qui da
   * ordina gli identificatori degli assi sinistro e destro.
   * Questo oggetto non è necessario da usare, aiuta
   * Solo nel caso in cui la SD sia effettuata direttamente
   * L'unità del robot. Attraverso StepperDriver puoi fare tutto
   * operazioni di base con i motori.
   *
   * In futuro penso di rimuovere questo oggetto, facendo di più
   * Telaio universale per un funzionamento confortevole
   * Telaio robot, indipendentemente dal tipo di motore.
*/
//  StepperChassis.init (sinistra, destra);
}

void loop ()
{

  /* StepperDriver.setDir(right, FORWARD); // dir può essere FORWARD e BACKWARD
   StepperDriver.setDir(left, BACKWARD);
   StepperDriver.setDelay(right, 2000); // imposta la lunghezza del passo
   StepperDriver.setDelay(left, 2000);
   StepperDriver.setSpeed(right, 600); // imposta la velocità.
   StepperDriver.setSpeed(left, 600);

   delay(1000);
*/
   /* La velocità è impostata in giri al minuto!
   * La velocità, come il ritardo, varia da 0 a 65535.
   *
   * Una volta impostata la velocità o il ritardo, il motore si avvia
   * ruota con il parametro specificato e in background.
  */
  StepperDriver.setDir (left, FORWARD);
  StepperDriver.setDelay(left, 2000);
  StepperDriver.setSpeed (left, 200);
  StepperDriver.setDir (right, FORWARD);
  StepperDriver.setDelay(right, 2000);
  StepperDriver.setSpeed (right, 200);
  //StepperDriver.stop (left);
  //StepperDriver.stop (right);
  delay (1000);
  StepperDriver.stop (left);
  StepperDriver.stop (right);


  /*StepperDriver.setDir (left, BACKWARD);
  StepperDriver.setSpeed (left, 40000);
  delay(1000);
*/


  //write(axis, value) - prende un valore con un segno
  // * e lo trasforma in direzione e velocità * /
  /*StepperDriver.write (left, 30000);
  delay (1000);
  StepperDriver.write (left, -30000);
  delay (1000);
*/
  /* Un altro uso della funzione di scrittura:
   * scrivi (asse, valore, percorso)
   * Gira il motore fino a quando non passa il percorso specificato.
   * Il modo qui è di presentare un POSITIVO, direzione da chiedere
   * segno di velocità.
   *
   * Poiché il motore gira ancora in background, c'è
   * due funzioni per determinare la fine del movimento:
   * occupato (asse) - restituisce 1 se il motore è ancora nel percorso e 0 altrimenti
   * aspetta (asse) - stupidamente aspettando la fine del movimento
   *
   * La funzione di spostamento (asse, velocità, percorso) funziona allo stesso modo di
   * scrivi e attendi dopo. (Ovvero, l'uscita dalla funzione avverrà
   * solo alla fine del percorso)
   * /
  StepperDriver.stop (a sinistra);
  ritardo (1000);

  StepperDriver.write (sinistra, 30000, 300);
  StepperDriver.wait (a sinistra);

  StepperDriver.write (sinistra, -30000, 300);
  while (StepperDriver.busy (a sinistra)) {
    / * fa qualcosa di utile * /
  }

  StepperDriver.move (a sinistra, 10000, 300);

  / * Infine, il percorso percorso può essere letto da una funzione
   * getPath (axis) (restituisce int32_t)
   *
   * Resetta il valore accumulato con una funzione
   * resetPath (asse)
   * /
  int32_t path = StepperDriver.getPath (a sinistra);
  Serial.println (percorso);
  StepperDriver.resetPath (a sinistra);
*/
}
