/*
Capteur d'humidité pour le robot jardinier
Anahi Michelle Mongelos Toledo
11 novembre 2023
*/

#include <stdio.h>
#include <SoftwareSerial.h>
#include <Arduino.h>
#include <pompe/pompe.h>

//valeurs d'humidite
const int sec = 595;
const int humide = 239;

//valeurs voulues pour certaines plantes
const int eauPlante1 = 50;
const int eauPlante2 = 10;
const int eauPlante3 = 80;
const int eauPlante4 = 0; 
const int eauPlante5 = 20;

void setup() {
Serial.begin(9600);
}

void loop() {
 // Je veux faire cinq lectures pour cinq plantes

 //identification de la plante avec RFID: à faire
  for(int i = 0; i < 5; i++)
  {
    int valeurCapteur = analogRead(A0);

    int pourcentageHumidite = map(valeurCapteur, humide, sec, 100, 0);

    Pompe pompe;

    if (pourcentageHumidite >= 0 && pourcentageHumidite <= 100) 
    {
      Serial.print(pourcentageHumidite);
      Serial.println("%");    

      //regarder l'humidité de chaque plante
      if(pourcentageHumidite < eauPlante1)
      {
        Serial.println("Activation de la pompe");
        //Code pour activer la pompe pendant 2 sec
        pompe.pompeON(2);
      }
      else
      {
        Serial.println("Taux d'humidité ok! Pas besoin d'arroser");
        //Code pour désactiver la pompe si besoin
        pompe.pompeOFF();
      }

      if(pourcentageHumidite < eauPlante2)
      {
        Serial.println("Activation de la pompe");
        //Code pour activer la pompe
        pompe.pompeON(2);
      }
      else
      {
        Serial.println("Taux d'humidité ok! Pas besoin d'arroser");
        //Code pour désactiver la pompe si besoin
        pompe.pompeOFF();
      }

      if(pourcentageHumidite < eauPlante3)
      {
        Serial.println("Activation de la pompe");
        //Code pour activer la pompe
        pompe.pompeON(2);
      }
      else
      {
        Serial.println("Taux d'humidité ok! Pas besoin d'arroser");
        //Code pour désactiver la pompe si besoin
        pompe.pompeOFF();
      }

      if(pourcentageHumidite < eauPlante4)
      {
        Serial.println("Activation de la pompe");
        //Code pour activer la pompe pendant 2 sec
        pompe.pompeON(2);
      }
      else
      {
        Serial.println("Taux d'humidité ok! Pas besoin d'arroser");
        //Code pour désactiver la pompe si besoin
        pompe.pompeOFF();
      }

      if(pourcentageHumidite < eauPlante5)
      {
        Serial.println("Activation de la pompe");
        //Code pour activer la pompe pendant 2 sec
        pompe.pompeON(2);
      }
      else
      {
        Serial.println("Taux d'humidité ok! Pas besoin d'arroser");
        //Code pour désactiver la pompe si besoin
        pompe.pompeOFF();
      }
    } 
  
    else 
    {
      Serial.println("Erreur de lecture");
    }
    delay(1000); //delai d'une seconde avant la prochaine lecture 
  }

  delay(60000);
}