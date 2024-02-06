# mathico v0.2
Визуализация на базе SFML таких фракталов как треугольник Серпинского и папоротник Барнсли с помощью вероятностно-итерационных функций. Сгенерированные картинки можно будет сохранить в формате '.png' или '.jpg' (указывается при сохранении файла).

Построение многоугольников на целочисленной решетке, близких к правильным --- третий проект с майской смены Сириуса 2021 года. Можно легко доказать, что почти все многоугольники нельзя расположить на целочисленной решетке,
а следовательно и нельзя сделать идеальное растровое изображение правильного многоугольника.

(old)

Соответственно я сделал программу, которая строит многоугольник по заданной пользователем стороне,
при этом благодаря дискретному преобразованию Фурье можно относительно быстро выяснить насколько исходный многоугольник близок к правильному
с заданной стороной. Информация о "близости" (приближении) выводится в консоль приложения.

Когда-нибудь следует реализовать аналог "векторной графики", чтобы можно было приблизить "изображение" и найти разницу между правильным и целочисленным многоугольником. После этого и будет смысл выводить пользователю приближение многоугольника.


Что нового?
-
1) Добавлены слайдеры, обновлена логика главных элементов интерфейса, теперь это sf::Drawable объекты, сделан шаг к унификации кода.

2) Реорганизована работа с кнопками и соотв. им функциями. Больше нет одного главного switch-case, в котором кнопка и находила собственную функцию. Начинаю отказываться от спагетти-кода. (Хотя вохможно я сделал тольько хуже)

3) Добавлены фракталы Серпинского и Барнсли.
