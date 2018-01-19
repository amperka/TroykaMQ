// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>

// имя для пина, к которому подключен датчик
#define PIN_MQ2         A0
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ2_HEATER  11

// создаём объект для работы с датчиком
// и передаём ему номер пина выходного сигнала и нагревателя
MQ2 mq2(PIN_MQ2, PIN_MQ2_HEATER);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // включаем нагреватель
  mq2.heaterPwrHigh();
  Serial.println("Heated sensor");
}

void loop()
{
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq2.isCalibrated() && mq2.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq2.calibrate();
    // при знании сопративления датчика на чистом воздухе
    // можно его указать вручную, допустим 3.2
    // mq2.calibrate(3.2);
    // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
    Serial.print("Ro = ");
    Serial.println(mq2.getRo());
  }
  // если прошёл интевал нагрева датчика
  // и калибровка была совершена
  if (mq2.isCalibrated() && mq2.heatingCompleted()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
    Serial.print("Ratio: ");
    Serial.print(mq2.readRatio());
    // выводим значения газов в ppm
    Serial.print("\tLPG: ");
    Serial.print(mq2.readLPG());
    Serial.print(" ppm");
    Serial.print("\tMethane: ");
    Serial.print(mq2.readMethane());
    Serial.print(" ppm");
    Serial.print("\tSmoke: ");
    Serial.print(mq2.readSmoke());
    Serial.print(" ppm");
    Serial.print("\tHydrogen: ");
    Serial.print(mq2.readHydrogen());
    Serial.println(" ppm");
    delay(100);
  }
}
