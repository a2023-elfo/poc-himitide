/*
Capteur d'humidité pour le robot jardinier
Anahi Michelle Mongelos Toledo
11 novembre 2023
*/

#include <stdio.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
//valeurs d'humidite
const int sec = 595;
const int humide = 239;

void setup() {
Serial.begin(9600);
}

void loop() {
  int valeurCapteur = analogRead(A0);

  int pourcentageHumidite = map(valeurCapteur, humide, sec, 100, 0);

   if (pourcentageHumidite >= 0 && pourcentageHumidite <= 100) 
   {
    Serial.print(pourcentageHumidite);
    Serial.println("%");
  } 
  
  else 
  {
    Serial.println("Erreur de lecture");
  }
  delay(1000); //delai d'une seconde avant la prochaine lecture 
}
