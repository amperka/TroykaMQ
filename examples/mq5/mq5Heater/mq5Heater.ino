// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>

// имя для пина, к которому подключен датчик
#define PIN_MQ5         A0
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ5_HEATER  11

// создаём объект для работы с датчиком
// и передаём ему номер пина выходного сигнала и нагревателя
MQ5 mq5(PIN_MQ5, PIN_MQ5_HEATER);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // включаем нагреватель
  mq5.heaterPwrHigh();
  Serial.println("Heated sensor");
}

void loop()
{
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq5.isCalibrated() && mq5.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq5.calibrate();
    // при знании сопративления датчика на чистом воздухе
    // можно его указать вручную, допустим 4.7
    // mq5.calibrate(4.7);
    // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
    Serial.print("Ro = ");
    Serial.println(mq5.getRo());
  }
  // если прошёл интервал нагрева датчика
  // и калибровка была совершена
  if (mq5.isCalibrated() && mq5.heatingCompleted()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
    Serial.print("Ratio: ");
    Serial.print(mq5.readRatio());
    // выводим значения газов в ppm
    Serial.print("LPG: ");
    Serial.print(mq5.readLPG());
    Serial.print(" ppm ");
    Serial.print(" Methane: ");
    Serial.print(mq5.readMethane());
    Serial.println(" ppm ");
    delay(100);
  }
}
