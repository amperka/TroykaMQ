Датчики газа серии MQ
=====================

Библиотека для Arduino, позволяющая считывать данные с [датчиков газа MQ](http://amperka.ru/collection/gas) в ppm от [Амперки](http://amperka.ru/).

Установка библиотеки
====================

В Arduino IDE выберите пункт меню «Скетч» → «Импортировать библиотеку» →
«Добавить библиотеку…». В появившемся окне выберите скачаный архив с
библиотекой. Установка завершена.

Подробности и примеры работы для [датчика MQ-2](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq2).

Подробности и примеры работы для [датчика MQ-3](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq3).

Подробности и примеры работы для [датчика MQ-4](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq4).

Подробности и примеры работы для [датчика MQ-5](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq5).

Подробности и примеры работы для [датчика MQ-6](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq6).

Подробности и примеры работы для [датчика MQ-7](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq7).

Подробности и примеры работы для [датчика MQ-8](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq8).

Подробности и примеры работы для [датчика MQ-9](http://wiki.amperka.ru/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq9).

В библиотеки используются коэффициенты для поиска значений в ppm для каждого газа, которые были найдены путём линейной и логарифмической аппроксимации графика из даташита.

Скачать исходники:
[MQ-2](http://wiki.amperka.ru/_media/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq2:mq2_graph_factors.zip),
[MQ-3](http://wiki.amperka.ru/_media/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq3:mq3_graph_factors.zip),
[MQ-4](http://wiki.amperka.ru/_media/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq4:mq4_graph_factors.zip),
[MQ-5](http://wiki.amperka.ru/_media/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq5:mq5_graph_factors.zip),
[MQ-6](http://wiki.amperka.ru/_media/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq6:mq6_graph_factors.zip),
[MQ-7](http://wiki.amperka.ru/_media/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq7:mq7_graph_factors.zip),
[MQ-8](http://wiki.amperka.ru/_media/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq8:mq8_graph_factors.zip),
[MQ-9](http://wiki.amperka.ru/_media/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq9:mq9_graph_factors.zip),
[MQ-135](http://wiki.amperka.ru/_media/%D0%BF%D1%80%D0%BE%D0%B4%D1%83%D0%BA%D1%82%D1%8B:mq135:mq135_graph_factors.zip)