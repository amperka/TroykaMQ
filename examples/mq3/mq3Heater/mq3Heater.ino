// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>

// имя для пина, к которому подключен датчик
#define PIN_MQ3         A0
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ3_HEATER  11

// создаём объект для работы с датчиком
// и передаём ему номер пина выходного сигнала и нагревателя
MQ3 mq3(PIN_MQ3, PIN_MQ3_HEATER);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // включаем нагреватель
  mq3.heaterPwrHigh();
  Serial.println("Heated sensor");
}

void loop()
{
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq3.isCalibrated() && mq3.heatingCompleted()) {
    // выполняем калибровку датчика на чистом воздухе
    mq3.calibrate();
    // при знании сопративления датчика на чистом воздухе
    // можно его указать вручную, допустим 6.3
    // mq3.calibrate(6.3);
    // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
    Serial.print("Ro = ");
    Serial.println(mq3.getRo());
  }
  // если прошёл интервал нагрева датчика
  // и калибровка была совершена
  if (mq3.isCalibrated() && mq3.heatingCompleted()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
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
}
