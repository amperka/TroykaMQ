// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>

// имя для пина, к которому подключен датчик
#define PIN_MQ4         A0
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ4_HEATER  11

// создаём объект для работы с датчиком
// и передаём ему номер пина выходного сигнала и нагревателя
MQ4 mq4(PIN_MQ4, PIN_MQ4_HEATER);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // включаем нагреватель
  mq4.heaterPwrHigh();
  Serial.println("Heated sensor");
}

void loop()
{
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq4.isCalibrated() && mq4.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq4.calibrate();
    // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
    Serial.print("Ro = ");
    Serial.println(mq4.getRo());
  }
  // если прошёл интервал нагрева датчика
  // и калибровка была совершена
  if (mq4.isCalibrated() && mq4.heatingCompleted()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
    Serial.print("Ratio: ");
    Serial.print(mq4.readRatio());
    // выводим значения газов в ppm
  // выводим значения газов в ppm
  Serial.print(" Methane: ");
  Serial.print(mq4.readMethane());
  Serial.println(" ppm ");
  delay(100);
  }
}
