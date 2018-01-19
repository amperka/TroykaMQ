// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>
 
//имя для пина, к которому подключен датчик
#define PIN_MQ5  A0
// создаём объект для работы с датчиком и передаём ему номер пина
MQ5 mq5(PIN_MQ5);
 
void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // перед калибровкой датчика прогрейте его 60 секунд
  // выполняем калибровку датчика на чистом воздухе
  mq5.calibrate();
  // при знании сопративления датчика на чистом воздухе
  // можно его указать вручную, допустим 4.7
  // mq5.calibrate(4.7);
  // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
  Serial.print("Ro = ");
  Serial.println(mq5.getRo());
}
 
void loop()
{
  // выводим отношения текущего сопротивление датчика
  // к сопротивление датчика в чистом воздухе (Rs/Ro)
  Serial.print("Ratio: ");
  Serial.print(mq5.readRatio());
  // выводим значения газов в ppm
  Serial.print(" LPG: ");
  Serial.print(mq5.readLPG());
  Serial.print(" ppm ");
  Serial.print(" Methane: ");
  Serial.print(mq5.readMethane());
  Serial.println(" ppm ");
  delay(100);
}
