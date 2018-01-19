// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>

// имя для пина, к которому подключен датчик
#define PIN_MQ6         A0
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ6_HEATER  11

// создаём объект для работы с датчиком
// и передаём ему номер пина выходного сигнала и нагревателя
MQ6 mq6(PIN_MQ6, PIN_MQ6_HEATER);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // включаем нагреватель
  mq6.heaterPwrHigh();
  Serial.println("Heated sensor");
}

void loop()
{
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq6.isCalibrated() && mq6.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq6.calibrate();
    // при знании сопративления датчика на чистом воздухе
    // можно его указать вручную, допустим 8.2
    // mq6.calibrate(8.2);
    // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
    Serial.print("Ro = ");
    Serial.println(mq6.getRo());
  }
  // если прошёл интервал нагрева датчика
  // и калибровка была совершена
  if (mq6.isCalibrated() && mq6.heatingCompleted()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
    Serial.print("Ratio: ");
    Serial.print(mq6.readRatio());
    // выводим значения газов в ppm
    Serial.print("LPG: ");
    Serial.print(mq6.readLPG());
    Serial.println(" ppm ");
    delay(100);
  }
}
