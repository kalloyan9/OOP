Домашна работа
Практикум
			курс Обектно-ориентирано програмиране 
за специалност Информатика
Летен семестър 2019/20 г.



Релации

Да се реализира шаблон на клас BinaryRelation, който описва двуместна релация между елементи от тип T и елементи от тип U. Релацията се представя като последователност от двойки, които са в релация. За шаблона да се реализират следните операции:
подходящи конструктори
r(t,u), която проверява дали t и u са в релация
!r, която намира обратната релация на r
(всички двойки (u,t), които са в релация r)
r1 + r2, която намира обединението на r1 и r2
(всички двойки (t,u), които са в релация r1 или в релация r2)
r1 ^ r2, която намира сечението на r1 и r2
(всички двойки (t,u), които са в релация r1 и в релация r2)
r[t], която намира образа на елемента t
(всички елементи u, за които (t,u) са в релация r)
r(u), която намира първообраза на елемента u
(всички елементи t, за които (t,u) са в релация r)
r1 * r2, която намира композицията на релациите r1 и r2
(всички двойки (t,v), за които има u, така че (t,u) е в r1 и (u,v) е в r2)
r.dom(), която намира домейна на r
(всички елементи t, които участват в някоя двойка (t,u) от r)
r.ran(), която намира образа на r
(всички елементи u, които участват в някоя двойка (t,u) от r)

операциите за съкратено присвояване +=, ^= и *=
операции за вход (>>) и изход (<<), които записват релацията в поток с подходящ формат
предикати
function, който проверява дали релацията е графика на частична функция
injection, който проверява дали релацията е графика на инективна функция
С помощта на шаблона BinaryRelation да се реализира шаблон KnowledgeBase, който описва “база от знания”: множество от връзки между двойки елементи от тип T и U, като всяка връзка има низ за етикет.
Пример: за T = int, U = char const*, една база от знания би могла да съдържа следните връзки (използван е форматът <име-на-връзка>(<елемент-от-тип-T>,  <елемент-от-тип-U>)):
nameOf(4, "four")
nameOf(42, "fourty-two")
nameOf(42, "forty-two")
nameOf(5, "five")
nameOf(4, "vier")
nameOf(99, "neunundneunzig")
romanNumeral(5, "V")
romanNumeral(42, "XLII")
romanNumeral(42, "xlii")
binaryString(4, "100")
binaryString(5, "101")
hexString(42, "2A")
hexString(42, "2a")
hexString(99, "63")
octString(51, "63")
octString(65, "101")
famousfor(10, "number of fingers on human hand")
famousfor(10, "smallest number with two decimal digits")
famousfor(99, "largest number with two decimal digits")
famousfor(42, "answer to the ultimate question of life, the universe, and everything")

Шаблонът KnowledgeBase трябва да поддържа всички операции, които поддържа BinaryRelation, като изпълнява съответните операции едновременно върху всички релации в KnowledgeBase. В допълнение, KnowledgeBase да поддържа операцията kb("relationName"), която връща релацията с име relationName от базата от знания kb. Ако няма нито една връзка с това име, операцията да връща празната релация.
Да се реализира програма, която демонстрира действието на шаблоните BinaryRelation и KnowledgeBase с подходящи примери с различни стойности на типовите параметри T и U.
