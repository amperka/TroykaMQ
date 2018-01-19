// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>
 
//имя для пина, к которому подключен датчик
#define PIN_MQ3  A0
// создаём объект для работы с датчиком и передаём ему номер пина
MQ3 mq3(PIN_MQ3);
 
void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // перед калибровкой датчика прогрейте его 60 секунд
  // выполняем калибровку датчика на чистом воздухе
  mq3.calibrate();
  // при знании сопративления датчика на чистом воздухе
  // можно его указать вручную, допустим 6.3
  // mq3.calibrate(6.3);
  // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
  Serial.print("Ro = ");
  Serial.println(mq3.getRo());
}
void loop()
{
  // выводим отношения текущего сопротивление датчика
  // к сопротивление датчика в чистом воздухе (Rs/Ro)
  Serial.print("Ratio: ");
  Serial.print(mq3.readRatio());
  // выводим значения паров алкоголя
  Serial.print(" Alcohol: ");
  Serial.print(mq3.readAlcoholMgL());
  Serial.print(" mG/L ");
  Serial.print(mq3.readAlcoholPpm());
  Serial.println(" ppm ");
  delay(100);
}
