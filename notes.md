- Датчик света:
  - Датчик линии выдает изменение напряжения от 0 до 5 Вольт.
  - В программном коде это изменение значения от 0 до 1023 ((??) 0 - максимальная освещенность, 1023 - минимальная освещенность).
  - Подключать к аналоговых входам.
- (с. 36) Датчик линии:
  - Выдает HIGH или LOW.
- (с. 39) 2-Wire Motor 269 w (двигатель):
  - Чтобы подключить двигатель к плате нужно использовать драйвер двигателя - Motor Controller 29 (маленький черный параллелепипед с проводами на вход и выход).
  - Управляется с помощью изменения значения ШИМ сигнала.
  - Нужно соеденить вместе драйвер двигателя и двигатель, причем подключение зависит от полярности (крутится в разные стороны при перемене порядка подключения).
  - Чтобы подключить мотор к плате, нужно подкючить драйвер мотора к специальному порту на плате (порт M13(5)), таким образом, чтобы белый (сигнальный провод) смотрел внутрь платы.
  - Чтобы управлять мотором нужно подавать значения от -127 до 127, что соответствует оборотам в положительном и отрицательном направлении.
- Сервопривод:
  - Нужен для точных перемещений деталей робота.
  - У него есть рабочий диапозон ((??) сдесь - 100 градусов).
  - Может крутится в обе стороны в пределах рабочего диапозона.
  - Подключается так же как и мотор.
- Энкодер:
  - Один оборот колеса равен 2 единицам энкодера.