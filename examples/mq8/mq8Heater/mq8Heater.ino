// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>

// имя для пина, к которому подключен датчик
#define PIN_MQ8         A0
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ8_HEATER  11

// создаём объект для работы с датчиком
// и передаём ему номер пина выходного сигнала и нагревателя
MQ8 mq8(PIN_MQ8, PIN_MQ8_HEATER);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // включаем нагреватель
  mq8.heaterPwrHigh();
  Serial.println("Heated sensor");
}

void loop()
{
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq8.isCalibrated() && mq8.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq8.calibrate();
    // при знании сопративления датчика на чистом воздухе
    // можно его указать вручную, допустим 6.1
    // mq8.calibrate(6.1);
    // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
    Serial.print("Ro = ");
    Serial.println(mq8.getRo());
  }
  // если прошёл интервал нагрева датчика
  // и калибровка была совершена
  if (mq8.isCalibrated() && mq8.heatingCompleted()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
    Serial.print("Ratio: ");
    Serial.print(mq8.readRatio());
    // выводим значения газов в ppm
    Serial.print("LPG: ");
    Serial.print(mq8.readHydrogen());
    Serial.println(" ppm ");
    delay(100);
  }
}
