// библиотека для работы с датчиками MQ (Troyka-модуль)
#include <TroykaMQ.h>

// имя для пина, к которому подключен датчик
#define PIN_MQ9         A0
// имя для пина, к которому подключен нагреватель датчика
#define PIN_MQ9_HEATER  11

// создаём объект для работы с датчиком
// и передаём ему номер пина выходного сигнала и нагревателя
MQ9 mq9(PIN_MQ9, PIN_MQ9_HEATER);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
  // запускаем термоцикл
  // в течении 60 секунд на нагревательный элемент подаётся 5 вольт
  // в течении 90 секунд — 1,5 вольта
  mq9.cycleHeat();
}

void loop()
{
  // если прошёл интервал нагрева датчика
  // и калибровка не была совершена
  if (!mq9.isCalibrated() && mq9.atHeatCycleEnd()) {
    // выполняем калибровку датчика на чистом воздухе
    mq9.calibrate();
    // при знании сопративления датчика на чистом воздухе
    // можно его указать вручную, допустим 7.2
    // mq9.calibrate(7.2);
    // выводим сопротивление датчика в чистом воздухе (Ro) в serial-порт
    Serial.print("Ro = ");
    Serial.println(mq9.getRo());
    // запускаем термоцикл
    mq9.cycleHeat();
  }
  // если прошёл интевал нагрева датчика
  // и калибровка была совершена
  if (mq9.isCalibrated() && mq9.atHeatCycleEnd()) {
    // выводим отношения текущего сопротивление датчика
    // к сопротивлению датчика в чистом воздухе (Rs/Ro)
    Serial.print("Ratio: ");
    Serial.print(mq9.readRatio());
    // выводим значения газов в ppm
    Serial.print(" LPG: ");
    Serial.print(mq9.readLPG());
    Serial.print(" ppm ");
    Serial.print(" Methane: ");
    Serial.print(mq9.readMethane());
    Serial.print(" ppm ");
    Serial.print(" CarbonMonoxide: ");
    Serial.print(mq9.readCarbonMonoxide());
    Serial.println(" ppm ");
    delay(100);
    // запускаем термоцикл
    mq9.cycleHeat();
  }
}

