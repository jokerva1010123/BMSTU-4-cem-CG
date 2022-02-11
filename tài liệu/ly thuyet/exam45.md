# 45. Определение направления  преломленного луча.

В сложных моделях освещения придется учитывать пропускающие свойства поверхностей, т.е. прозрачность этих поверхностей, что приводит к наличию преломленного луча. Для получения вектора преломленного луча воспользуемся законом преломления Снеллиуса, который утверждает, что падающий и преломленный лучи, а также вектор нормали лежат в одной плоскости, а углы падения и преломления связаны следующей формулой:

<a href="https://www.codecogs.com/eqnedit.php?latex=\eta_1sin\theta_L&space;=&space;\eta_2sin\theta_T" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\eta_1sin\theta_L&space;=&space;\eta_2sin\theta_T" title="\eta_1sin\theta_L = \eta_2sin\theta_T" /></a> (1)

Как и в предыдущем случае, будем считать, что вектор преломления представляет собой линейную комбинацию вектора падающего света и вектора нормали, т.е.:

<a href="https://www.codecogs.com/eqnedit.php?latex=T&space;=&space;\alpha&space;L&space;&plus;&space;\beta&space;n" target="_blank"><img src="https://latex.codecogs.com/svg.latex?T&space;=&space;\alpha&space;L&space;&plus;&space;\beta&space;n" title="T = \alpha L + \beta n" /></a>

Поскольку скалярное произведение единичных векторов численно равно косинусу угла между ними, то можно записать следующие два равенства:

<a href="https://www.codecogs.com/eqnedit.php?latex=(-L)n&space;=&space;cos\theta_L" target="_blank"><img src="https://latex.codecogs.com/svg.latex?(-L)n&space;=&space;cos\theta_L" title="(-L)n = cos\theta_L" /></a> (2)

<a href="https://www.codecogs.com/eqnedit.php?latex=n(-T)&space;=&space;cos\theta_T" target="_blank"><img src="https://latex.codecogs.com/svg.latex?n(-T)&space;=&space;cos\theta_T" title="n(-T) = cos\theta_T" /></a> (3)

Вычислим скалярное произведение единичного вектора преломления самого на себя, которое равно единице:

<a href="https://www.codecogs.com/eqnedit.php?latex=TT&space;=&space;(\alpha&space;L&space;&plus;&space;\beta&space;n)^2&space;=&space;\alpha&space;^2&space;LL&space;&plus;&space;2\alpha\beta&space;Ln&space;&plus;&space;\beta^2&space;nn&space;=&space;1" target="_blank"><img src="https://latex.codecogs.com/svg.latex?TT&space;=&space;(\alpha&space;L&space;&plus;&space;\beta&space;n)^2&space;=&space;\alpha&space;^2&space;LL&space;&plus;&space;2\alpha\beta&space;Ln&space;&plus;&space;\beta^2&space;nn&space;=&space;1" title="TT = (\alpha L + \beta n)^2 = \alpha ^2 LL + 2\alpha\beta Ln + \beta^2 nn = 1" /></a>

<a href="https://www.codecogs.com/eqnedit.php?latex=\alpha^2&space;&plus;&space;2\alpha\beta&space;Ln&space;&plus;&space;\beta^2&space;=&space;1" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\alpha^2&space;&plus;&space;2\alpha\beta&space;Ln&space;&plus;&space;\beta^2&space;=&space;1" title="\alpha^2 + 2\alpha\beta Ln + \beta^2 = 1" /></a>

Заменив скалярное произведение вектора падающего света на нормаль через (2), получаем:

<a href="https://www.codecogs.com/eqnedit.php?latex=\alpha^2&space;-&space;2\alpha\beta&space;cos\theta_L&space;&plus;&space;\beta^2&space;=&space;1" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\alpha^2&space;-&space;2\alpha\beta&space;cos\theta_L&space;&plus;&space;\beta^2&space;=&space;1" title="\alpha^2 - 2\alpha\beta cos\theta_L + \beta^2 = 1" /></a> (4)

Равенство (4) перепишем с учетом исходного выражения, определяющего значение вектора преломления:

<a href="https://www.codecogs.com/eqnedit.php?latex=n(\alpha&space;L&space;&plus;&space;\beta&space;n)&space;=&space;\alpha&space;Ln&space;&plus;&space;\beta&space;nn&space;=&space;\alpha&space;Ln&space;&plus;&space;\beta&space;=&space;\alpha(-cos\theta_L)&space;&plus;&space;\beta&space;=&space;-cos\theta_T&space;\rightarrow&space;cos\theta_T&space;=&space;\alpha&space;cos\theta_L&space;-&space;\beta" target="_blank"><img src="https://latex.codecogs.com/svg.latex?n(\alpha&space;L&space;&plus;&space;\beta&space;n)&space;=&space;\alpha&space;Ln&space;&plus;&space;\beta&space;nn&space;=&space;\alpha&space;Ln&space;&plus;&space;\beta&space;=&space;\alpha(-cos\theta_L)&space;&plus;&space;\beta&space;=&space;-cos\theta_T&space;\rightarrow&space;cos\theta_T&space;=&space;\alpha&space;cos\theta_L&space;-&space;\beta" title="n(\alpha L + \beta n) = \alpha Ln + \beta nn = \alpha Ln + \beta = \alpha(-cos\theta_L) + \beta = -cos\theta_T \rightarrow cos\theta_T = \alpha cos\theta_L - \beta" /></a> (5)

Возведя (1) в квадрат и произведя замену η=η1/ η2, получим:

<a href="https://www.codecogs.com/eqnedit.php?latex=sin^2\theta_T&space;=&space;\eta^2sin^2\theta_L&space;\rightarrow&space;1&space;-&space;cos^2\theta_T&space;=&space;\eta^2(1&space;-&space;cos^2\theta_L)&space;\rightarrow&space;cos^2\theta_T&space;=&space;1&space;-&space;\eta^2(1&space;-&space;cos^2\theta_L)" target="_blank"><img src="https://latex.codecogs.com/svg.latex?sin^2\theta_T&space;=&space;\eta^2sin^2\theta_L&space;\rightarrow&space;1&space;-&space;cos^2\theta_T&space;=&space;\eta^2(1&space;-&space;cos^2\theta_L)&space;\rightarrow&space;cos^2\theta_T&space;=&space;1&space;-&space;\eta^2(1&space;-&space;cos^2\theta_L)" title="sin^2\theta_T = \eta^2sin^2\theta_L \rightarrow 1 - cos^2\theta_T = \eta^2(1 - cos^2\theta_L) \rightarrow cos^2\theta_T = 1 - \eta^2(1 - cos^2\theta_L)" /></a>

Возведем теперь в квадрат (5) и, заменив неизвестное значение косинуса угла преломления на известное значение косинуса угла падения, получим:

<a href="https://www.codecogs.com/eqnedit.php?latex=\alpha^2cos^2\theta_L&space;-&space;2\alpha\beta&space;cos\theta_L&space;&plus;&space;\beta^2&space;=&space;1&space;-&space;\eta^2(1-cos^2\theta_L)" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\alpha^2cos^2\theta_L&space;-&space;2\alpha\beta&space;cos\theta_L&space;&plus;&space;\beta^2&space;=&space;1&space;-&space;\eta^2(1-cos^2\theta_L)" title="\alpha^2cos^2\theta_L - 2\alpha\beta cos\theta_L + \beta^2 = 1 - \eta^2(1-cos^2\theta_L)" /></a> (6)

Вычитая из (4) выражение (6), получаем:

<a href="https://www.codecogs.com/eqnedit.php?latex=\alpha^2(1-cos^2\theta_L)&space;=&space;\eta^2(1-cos^2\theta_L)" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\alpha^2(1-cos^2\theta_L)&space;=&space;\eta^2(1-cos^2\theta_L)" title="\alpha^2(1-cos^2\theta_L) = \eta^2(1-cos^2\theta_L)" /></a>

Из последнего уравнения получаем α= η (второй корень α= -η не подходит по физическому смыслу). Подставив полученное значение α в (6), получим уравнение:

<a href="https://www.codecogs.com/eqnedit.php?latex=\beta^2&space;-&space;2\beta\eta&space;cos\theta_L&space;&plus;&space;\eta^2&space;-1&space;=&space;0" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\beta^2&space;-&space;2\beta\eta&space;cos\theta_L&space;&plus;&space;\eta^2&space;-1&space;=&space;0" title="\beta^2 - 2\beta\eta cos\theta_L + \eta^2 -1 = 0" /></a>

Решая это уравнение, получим следующие корни, определяющие неизвестное значение коэффициента:

<a href="https://www.codecogs.com/eqnedit.php?latex=\beta_{1,2}&space;=&space;\eta&space;cos\theta_L&space;\pm&space;\sqrt{\eta^2(cos^2\theta_L-1)&plus;1}" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\beta_{1,2}&space;=&space;\eta&space;cos\theta_L&space;\pm&space;\sqrt{\eta^2(cos^2\theta_L-1)&plus;1}" title="\beta_{1,2} = \eta cos\theta_L \pm \sqrt{\eta^2(cos^2\theta_L-1)+1}" /></a>

Из двух возможных значений из физического смысла следует взять меньший корень (отрицательный):

<a href="https://www.codecogs.com/eqnedit.php?latex=\beta&space;=&space;\eta&space;cos\theta_L&space;-&space;\sqrt{\eta^2(cos^2\theta_L-1)&plus;1}" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\beta&space;=&space;\eta&space;cos\theta_L&space;-&space;\sqrt{\eta^2(cos^2\theta_L-1)&plus;1}" title="\beta = \eta cos\theta_L - \sqrt{\eta^2(cos^2\theta_L-1)+1}" /></a>

В последнем выражении под знаком квадратного корня может стоять отрицательная величина:  
<a href="https://www.codecogs.com/eqnedit.php?latex=\eta^2(cos^2\theta_L-1)&plus;1&space;<&space;0" target="_blank"><img src="https://latex.codecogs.com/svg.latex?\eta^2(cos^2\theta_L-1)&plus;1&space;<&space;0" title="\eta^2(cos^2\theta_L-1)+1 < 0" /></a>  
Это будет означать полное внутреннее отражение, т.е. отсутствие преломленного луча при переходе из оптически более плотной среды в оптически менее плотную среду.

**Следующий вопрос:**  [01. Задача синтеза сложного динамического изображения. Этапы синтеза изображения. Последовательность и основное  содержание.](./exam01)


**Предыдущий вопрос:**  [44. Алгоритм трассировки лучей с использованием глобальной модели  освещения.](./exam44)
