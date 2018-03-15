#include <StepperDriver.h>
#define EN 8

axis_t right, left;

void setup ()
{
  //need to set the enable to LOW because if it is HIGH the motors are desabled
  pinMode(EN, OUTPUT);
  digitalWrite(EN, LOW);

  StepperDriver.init ();

/* Registrare gli assi controllati. Qui in ordine
   * ci sono tre numeri di pin: STEP, DIR, ENABLE.
   * Se ENABLE non è necessario o non esiste, immettere 255,
   * questo valore è uno stub. Il quarto valore è il numero di passi per giro
   * Al motore.
*/
  left = StepperDriver.newAxis (2, 5, 255, 200);
  right = StepperDriver.newAxis (3, 6, 255, 200);

// StepperDriver.disable (asse); if needed
  StepperDriver.enable(left);
  StepperDriver.enable(right);

  StepperDriver.setDir (left, FORWARD);
  StepperDriver.setDir (right, FORWARD);
  StepperDriver.setDelay(left, 65000);
  StepperDriver.setSpeed (left, 100);
  StepperDriver.setSpeed (right, 100);
  StepperDriver.setDelay(right, 200000);


}

void loop(){
}
