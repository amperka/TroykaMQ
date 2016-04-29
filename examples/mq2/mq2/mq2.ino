// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>

//имя для пина, к которому подключен датчик
#define PIN_MQ2  A0
// создаём объект для работы с датчиком и передаём ему номер пина
MQ2 mq2(PIN_MQ2);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // перед калибровкой датчика прогрейте его 60 секунд
  // выполняем калибровку датчика на чистом воздухе
  mq2.calibrate();
  // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
  Serial.print("Ro = ");
  Serial.println(mq2.getRo());
}

void loop()
{
  // выводим отношения текущего сопротивление датчика
  // к сопротивлению датчика в чистом воздухе (Rs/Ro)
  Serial.print("Ratio: ");
  Serial.print(mq2.readRatio());
  // выводим значения газов в ppm
  Serial.print("LPG: ");
  Serial.print(mq2.readLPG());
  Serial.print(" ppm ");
  Serial.print(" Methane: ");
  Serial.print(mq2.readMethane());
  Serial.print(" ppm ");
  Serial.print(" Smoke: ");
  Serial.print(mq2.readSmoke());
  Serial.print(" ppm ");
  Serial.print(" Hydrogen: ");
  Serial.print(mq2.readHydrogen());
  Serial.println(" ppm ");
  delay(100);
}

