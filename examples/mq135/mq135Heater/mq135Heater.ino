// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>

// имя для пина, к которому подключен датчик
#define PIN_MQ135         A0
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ135_HEATER  11

// создаём объект для работы с датчиком
// и передаём ему номер пина выходного сигнала и нагревателя
MQ135 mq135(PIN_MQ135, PIN_MQ135_HEATER);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // включаем нагреватель
  mq135.heaterPwrHigh();
  Serial.println("Heated sensor");
}

void loop()
{
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq135.isCalibrated() && mq135.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq135.calibrate();
    // при знании сопративления датчика на чистом воздухе
    // можно его указать вручную, допустим 160
    // mq135.calibrate(160);
    // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
    Serial.print("Ro = ");
    Serial.println(mq135.getRo());
  }
  // если прошёл интевал нагрева датчика
  // и калибровка была совершена
  if (mq135.isCalibrated() && mq135.heatingCompleted()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
    Serial.print("Ratio: ");
    Serial.print(mq135.readRatio());
    // выводим значения газов в ppm
    Serial.print("\tCO2: ");
    Serial.print(mq135.readCO2());
    Serial.println(" ppm");
    delay(100);
  }
}
