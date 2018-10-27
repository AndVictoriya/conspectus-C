GCC 

Настройка переменных сред для возможности ввода gcc без полного пути:
Переменные среды, создать PATH с значением D:\GDrive\books\C\MinGW\bin\

Настройка директории по-умолчанию при запуске консоли:
[HKEY_CURRENT_USER\Software\Microsoft\Command Processor] "Autorun"="cd /d D:\GDrive\books\С\MinGW\CUBEC" 
/d нужна при смене диска

Директории gcc:
MinGW\libexec\mingw-get\guimain.exe - update and setup
MinGW\bin\gcc.exe

SUBLIME 
"fallback_encoding": "Cyrillic (Windows 1251)",
"auto_complete" : false,
"tab_completion" : false,
"update_check": false,

keyBinding:
{ "keys": ["f5"], "command": "save" },

Ctr+K,B скрыть панель папки слева, если она была. 
ctrl+[ сдвинуть влево
ctrl+] сдвинуть вправо

Сompile 
Экранирование символов — механизм, имеющийся в текстовых языках и протоколах. 
Он служит, чтобы символы, которые считаются служебными и имеют особое значение, 
	этого значения лишить и объявить «просто символами». 
Нам нужно двойное экранирование: для ОС (строка с пробелами закавычивается) и для Си (перед кавычкой слэш).

system("gcc \"C:/Folder/My Folder/example.c\" ");
Точно так же экранируется и обратный слэш, если вдруг потребуется.
system("gcc \"C:\\Folder\\My Folder\\example.c\"" );

cd D:\books
gcc C:\Cex\test.c -o C:\Cex\test.exe

-c Compile or assemble the source files, but do not link
-S Stop after the stage of compilation proper; do not assemble. 

Исходник > препроцессор (что-то делает с .h) > компилятор (преобразует в объектный код?) > компоновщик (линкер, линковщик)
В асме сначала идёт исходник, он трансилруется ассемблером в объектный код, замет линкуется линкером. 

Про типы данных.
Тут есть некоторые вопросы с char. signed char и unsigned char.
char будет зависеть от ключей компиляции, вероятно.

Массив из char или signed char
C:\Users\Qyb>a
0000007E 126 126
0000007F 127 127
FFFFFF80 -128 4294967168
FFFFFF81 -127 4294967169
FFFFFF82 -126 4294967170

C:\Users\Qyb>gcc test.c
unsigned char
C:\Users\Qyb>a
0000007E 126 126
0000007F 127 127
00000080 128 128
00000081 129 129
00000082 130 130

1. define 

Умеют много чего, не путать с функцией, это именно символьная замена, 
	с которой работает препроцессор.

#include <stdio.h>
#define SIZE 10
#define MASK(x) x&0xFF
int main(){
	printf("%d\n", SIZE);//n - ESC код переноса строки. Равносильно написанию:
	printf("%d\n", 10);	

	printf("%d\n", MASK(4095)	);//равносильно написанию:
	printf("%d\n", 4095 & 0xFF	);
	return 0;
}
4095	1111 1111 1111
0xFF	0000 1111 1111
AND=	0000 1111 1111

2. main - главная функция (в win нужно указывать тип возвращаемых int данных). 

#include <stdio.h>//директива для препроцессора С, выполняется до компиляции. В данном случае заставляет препроцессор 
//включить в программу содержание заголовочного файла stdio.h. Подробнее в главе 5.
int main(){
	int A, Z;//объявление имени и типа данных переменной.
	A = 3;//инициализация переменной.
	int B = 2;
	float C = 2;
	printf("%.2f\n", A/B );//1.00 - целое на целое отбросит дробную часть.
	printf("%.2f\n", A/C) ;//1.50 - выполнит неявное преобразование целого B в float (создаст копию).
	printf("%.2f\n", (float) A/B );//1.50 - выполнит явное преобразование A в float, что потом неявно возведёт B до float.
	scanf(("%d", &Z );
	printf("%d\n", Z );
	return 0; //return 0 - показывает успешное завершение, пиши это.
}

Круглые скобки () означают, что main это "строительный блок" программы, функция. 
Программа С может содержать одну или большее количество функций, но одна из 
	функций должна быть main.
Левая фигурная скобка { начинает тело функции, а правая ее заканчивает. 
	Эта пара скобок и код между ними называется блоком. 

Вся строчка printf("%.2f\n", A/B ); с точкой с запятой (символ конца оператора) называется оператором. 

Объявление (конкретной переменной) должно располагаться после первой левой скобки и перед первым исполняемым оператором (с этой переменной). 
	Если после printf(A) инициализировать int Z = 2 и отправить на печать - то ошибки компилятор не выдает... 
	Плюс, объявления могут быть внутри функций, см. далее. 

Идентификатор (имя) - это последовательность символов (букв, цифр и _) для обозначения: 
	переменных, типов, фукнций, меток. 
Имя до 31 символа, учитываются строчные и заглавные буквы, не должно начинаться с цифры. 
main, printf - идентификатора для функции. 
integer1, A, Z - идентификатор целой переменной.

%d - esc-код, спецификация преобразования, показывает, что данные должны быть целым числом.
&Z - операция взятия адреса следующей за ним переменной. Сообщает сканфу ячейку памяти, 
	в которой хранится переменная Z. Компьютер будет хранить 
	величину для Z в этой ячейке. Подробнее расмотрено в главе про указатели.

Явные и неявные преобразования:
	Если написать 3/2*3.14, то получится =3.14 , потому что 3/2 будет равно 1.

3. Структуры (конструкции)

Всего 3 вида управляющих структур (итого семь): 
	1. Структура последовательная:
		Любой тип действий, вычисление, ввод/вывод.
	2. Структура выбора:
		if, if/else, switch.
	3. Структура повторения:
		while, do/while, for.

Маленькое пояснение по операторам и "структурам". 
	Глава 3.4 Control Structures Управляющие структуры.
	Normally, statements - Обычно, операторы...
	Но в английском operators - это +, -, += и так далее.

	Можно переводить тогда так: 
	statement - инструкция, operator - оператор

	An expression is a sequence of operators.
	Выражение - это последовательность операторов.
	
	Statements are fragments of the C program that are executed in sequence. 
	(Инструкции)Операторы есть фрагменты что выполняются в последовательности.
	"конструкция if", "конструкция switch" или "инструкция goto", "инструкция return"

	The body of any function is a compound statement, which, in turn is a sequence of statements and declarations:
	Тело функции есть составной оператор, который в свою очередь есть последовательность операторов и объявлений.

3.2 Оператор if (является структурой с одиночным выбором)

if ( a > b )
	printf("something\n");

Совокупность операторов внутри {} скобок называтеся составным оператором (составным блоком):
if(condition) {
	оператор1;
	оператор2;
}
Составной оператор можно помещать где угодно. 
Так же можно использовать пустой оператор ";" на месте, обычно занимаемым некоторым оператором. 

int main(){	
	int A;
	scanf ("%d", &A);
	
	if (A >= 2)
		printf(">=2\n");
	
	if (A < 2){
		printf("<2\n");
		printf("LOL\n");
	}
}

3.2 Оператор if/else (является структурой с двойным выбором). Почему внутри оператора есть ; - непонятно.

if (/* condition */)
	printf("AAA");
else if (/* condition */)
	printf("BBB");
else if (/* condition */)
	printf("CCC");

дополнение к if:
printf("%s\n", grade >= 60 ? "Passed" : "Failed" );
grade >= 60 ? printf("Passed") : printf("Failed" );

rvalue lvalue
int  day = 10, a;
day == 10 ? a = 1 : a = 0 ;	
printf("%d\n", a);
Так работать не будет, потому что нарушается принцип. ???

3.3 Оператор while  (одна из структур повторения)

int stud = 0;
while (stud < 10){
	printf("AAA");
	stud = stud + 1;
}

				4. Операции присваивания, пре/пост, инкремента/декремента (стр.113)

				c += 3 равносильно c = c + 3, но компилируется быстрее.
					
				++a; // преинкремент, увеличивает на 1, использует новое значение.
				a++; // постинкремент, использует значение, потом увеличивает на 1.  
				Преинкремент работает быстрее. 

				a = 5;
				printf("%d\n", ++a);	//6
				printf("%d\n", a	);	//6	
				a = 5;
				printf("%d\n", a++);	//5
				printf("%d\n", a	);	//6

while со счетчиком

int counter = 0;
while (++counter <= 2)
	printf("%d\n", counter);
1
2

int counter = 0;
while (counter++ <= 2)
	printf("%d\n", counter);
1
2
3

3.3 for

int main(){
	int i;
	for (i = 0; i <= 2; ++i){//постинкремент выглядит естественнее, но прединкремент здесь эквивалентен и выполняется быстрее.
		printf("%d\n", i );
	}
	return 0;
}
В стандарте С99 добавили возможность инициализации и объявления переменной внутри цикла for. 
Тогда i будет экранирована от i в main.
	Смотри раздел про классы памяти и 
	{
		и области действия.
	}

3.2 switch

int main(){
	int x = 0;
	scanf ("%d", &x);
	switch (x) {
		case 1 : case 2 : // если gon = 1 или gon = 2.
			printf("1or2");
			break;
		case 5 : // если равен 5.
			printf("5");
			break;
		case '\n' : case ' ': // игнор символа переноса и пробела, если работа с символами.
			break;
		default : // все остальные случаи.
			printf("other");
			break;
	}
	printf("\n End");
	return 0;
}	

9. do/while

int main(){
	int counter = 1;
	do {
		printf("%d\n", counter);
	}	while ( ++counter <= 10);
	return 0;
}

10. break/continue

int main(){
	int  x;
	for (x = 1; x <= 10; x++){
		if(x == 5)
			break; // break досрочно выводит из цикла, есть и другие структурные способы это сделать.
		printf("%d ", x );
	}
	printf("lalala %d\n", x);
	return 0;
}

int main(){
	int  x;
	for (x = 1; x <= 10; x++){
		if(x == 5)
			continue; // continue пропускает оставшийся код в цикле, если х == 5.
		printf("%d ", x );
	}
	printf("lalala %d\n", x);
	return 0;
}

11. Логические операции

int main(){
	int  x, A, B;
	scanf("%d%d%d", &x, &A, &B);

	if ( !(x == 2) )	
		printf("!(%d==2)\n", x);
	
	if ( A == 1 && B >= 10)		//Слева от && стараться ставить более вероятное условие, чтобы раньше перестать считать. 
		printf("Ab");
	return 0;
}
	
11.2. Побитовые операции.

PORTX |= (1 << 2);	// PORTX = PORTX | (1 << 2);
PORTX &= ~(1 << 2);	//	PORTX = PORTX & ~(1 << 2);

<< - побитовый сдвиг, сдвигает биты на 2 влево у числа 1.
	Получается 4, то есть (1 << 2) == 4.
~ - побитовое НЕ,  инвертирует биты.
| - побитовое ИЛИ.
	PORTX =  PORTX | 4; устанавливает 2-й бит числа PORTX в единицу.
& - И. 
	PORTX & 4 "извлекает" 2-й бит из числа (то есть PORTX & 4 == 0 когда 2-й бит равен 0 и PORTX & 4 != 0 когда 2-й бит равен 1)

12. функции

Любая функция должна быть объявлена перед тем, как будет использована, иначе будут ошибки. 

тип_возвращаемых_значений ИМЯ (тип_принимаемых_значений/список_параметров)
float FUNC(int, double);			//прототип
float FUNC(int x, double y) {}	//тело функции
Прототип соответствует списку параметров. 
Если прототип не указать - компилятор сам создаст кое-как прототип.
Прототип заставляет компилятор преобразовывать тип данных (int>float, etc). 
Имена лучше делать разными. 

float FUNC(int);
int main(){
	printf("%.3f", FUNC(3));
	return 0;
}
float FUNC(int x){
	float tmp = x / 2.0 ;
	return tmp;
}

void funk (void);
int main (void) {
	funk();	// если void - то в скобках должно быть пусто.
	return 0;
}
void funk(void){
	printf("HELLO\n");
	return;	// return здесь можно не писать .
}

int AAA(int);
int BBB(int);

int main(){
	int ZZZ;
	scanf ("%d", &ZZZ );
	printf("%d", AAA(ZZZ) );
	return 0;
}

int AAA(int aaa){
	return BBB(aaa);
}

int BBB(int aaa){
	return aaa * 1000;
}

13. Заголовочные файлы .h//////////////////////////////////////////////////////////////////

Каждая библиотека имеет свой заголовочный файл, содержащий прототипы для всех функций
	данной библиотеки, а также определение типов данных и констант для этих функций.	
Можно создавать собственные заголовочные файлы. Подробнее в главе 13.

Директивы сообщают препроцессору о необходимости включения заголовочных файлов, 
	которые содержат много всего, в том числе - прототипы функций.

#include <stdio.h>	printf(), scanf() 
#include <stdlib.h>	system()
#include <math.h> 
#include <conio.h>	getchar()
#include <time.h>		time(NULL)
#include <unistd.h>	sleep()


14. Вызов функций///////////////////////////////////////////////////////////////

По значению - вызываемой функции передаётся копия значения аргумента.
	Изменения с копией не отражаются на значении исходной переменной в вызывающей функции.

По ссылке - вызывающая функция позволяет вызываемой функции изменять значение исходной переменной.

В С все вызовы передают аргументы по значению. 
	При этом есть методы имитации передачи по ссылке используя операцию взятия адреса 
	и косвенные операции.

Массивы автоматически передаются посредством имитации по ссылке. 
	Подробнее будет в главе 7.

15. Классы памяти/////////////////////////////////////////////////////////////////////////

Идентификаторы имеют атрибуты:
	имя, 
	тип, 
	значения, 
	класс памяти, 
	период хранения, 
	область действия, 
	тип компоновки (глава14).

Локальная переменная		- объявлена в списке параметров, теле функции или блоке.
Глобальная переменная	- объявлена вне любого блока или вне функции.

Автоматический период хранения (существуют, пока блок активен, уничтожаются после выхода из блока) :
	auto float x; - слово auto используется редко, т.к. локальные переменные (в списке параметров или блоке)
		имеют auto по умолчанию, auto экономит место в памяти.
	register int counter = 1; - рекомендует компилятору поместить в регистр.

Статический период хранения (существуют с того момента (инициализируются), когда программа начинает выполнятся).
	static - локальные переменные, 
		помнят свои значения и после выхода из функции, по-умолчанию инициализируются нулями.
	extern - глобальные переменные,
		глобальные переменные и имена функций по умолчанию extern.
		И кстати, судя по всему, тоже по-умолчанию инициализируются нулем.	

Области действия (Стр. 209 и 211.):
	файла		test.c , объявленные вне любой функции (в том числе вне main).
	блока		{} и параметры функций.
	прототипа	int funk(int) -причем, прототипы требуют только типы идентификаторов, имена им не нужны.
	функции		метки start: или case: в switch - единственные идентификаторы с областью действия функции.
	
Если своими словами:
	Период хранения и область действия - разные вещи.
	Область действия идентификатора/переменной зависит от расположения кода.
	Глобальная переменная доступна всем функциям, локальная - только своему месту.
	Глобальная переменная X будет "скрыта" для функции, если в функции будет объявлена переменная X.
	Локальные скрываются аналогично:
int main(){
	int a = 1;
	{
		printf ("%d\n", a);		//1
		a = 5;
		printf ("%d\n", a);		//5
	}
	printf ("%d\n", a);			//5
	{
		int a = 3;
		printf ("%d\n", a);		//3
	}
	printf ("%d\n", a);			//5
	}
Локальная переменная с классом static используется, например, в теле функции или массивах.
	
В стандарте С99 добавили возможность инициализации и объявления переменной внутри цикла for:
int main(){
	int i = 10;
	for(i = 0; i <=2; i++ ){		//i доступна для блока for.
		printf("%d\n", i);			//0	1	2
	}
	printf("%d\n", i);				//3
	return 0;
}

int main(){
	int i = 10;
	for(int i = 0, i <=2, i++ ){	//i из main скрывается для блока с for.
		printf("%d\n", i);			//0	1	2
	}
	printf("%d\n", i);				//10
	return 0;
}

int main(){
	int i = 10;
	for(; i <=2; i++)					//можно и так.
		printf("%d\n", i);
	return 0;
}

16. Рекурсия//////////////////////////////////////////////////////////////////////////

Всё, что можно написать рекурсией - можно написать и итерацией. 
Нужно выбирать подход в зависимости от обстоятельств. Рекурсия требует больше ресурсов. 

int FUNC(int);

int main(){
	int number;
	scanf("%d", &number);
	printf("%d!=%d\n", number, FUNC(number) );
}

int FUNC(int x){
	if(x <= 1){
		return 1;
	}
	else{
		return( x*FUNC(x-1) );
	}	
}

17. Массивы/////////////////////////////////////////////////////////////////////////

Массив с 3 ячейками типа int с нулями: 
int MAS[3] = {0};
	Номера ячеек: 0, 1, 2.
	{0} поместит нули во все ячейки.
	{1} поместит единицу только в нулевую ячейку, а в остальные - нули.

Можно перечислять переменные по отдельности:
int MAS[3] = {1, 2, 3};
Можно перечислять переменные по отдельности и размер будет указан автоматически:
int MAS[] = {1, 2, 3};
Число перечисленных членов не должно превышать размер массива [], если записать его вручную.
Программа может выйти за пределы массива, этого нельзя допускать.

Имя массива - это адрес первой ячейки. Адрес первой ячейки - это имя массива.
Адрес ячейки:
printf("%p\n", &string[i] );
& - взять адрес ячейки i и вывести его с помощью %p.
printf("%p\n", string ); равносильно printf("%p\n", &string[0] );

В массивах могут содержаться данные любого типа. 

Символьный массив на 20 ячеек, где 20 ячейка - \0 (символ окончания строки):
char string[20]; 

Строка "hello"  является массивом символов (или символьным литералом):
char string[] = "hello";
	\0 символ и размер подставятся автоматически.
	 
Тоже самое посимвольно:
char string[] = { 'h', 'e', 'l', 'l', 'o', '\0' }; 
			
			что будет если не написать символ???
			этот символ останавливает printf
			этот символ безразличен scanf, scanf считывает до первого space-а.

Вывод строкой:
char string[] = "ABCD"; // \0 тут будет подставлен автоматически.
printf("%s\n", string); - символы выводятся до тех пор, пока не будет встречен \0.
ABCD

char string[] = {'A', 'B', '\0', 'C', 'D','E','\0'};
printf("%s\n", string);
AB

Вывод посимвольно циклом с условием != '\0':
char string[] = "ABCD";
for (int i = 0; string[i] != '\0' ; ++i){
	printf("%c\n", string[i]);
}	
ABCD

Ввод строки:
char string[4];
scanf("%s", string);				//& не нужен.

char string[] = {'A', 'B', '\0', 'C', 'D','E','\0'};
scanf ("%s", string); - scanf перезапишет всё, \0 его не остановит.
			
Ввод посимвольно:
char string[SIZE];
for (int i = 0; i < SIZE ; ++i){
	scanf("%c", &string[i]);	//& нужен.
}	

18. Статические массивы static/////////////////////////////////////////////////////////
	
static int A[3]; - массив не будет всякий раз создаваться при вызове функции и
уничтожаться после выхода из неё. Это уменьшает время работы.
Статический массив по умолчанию инициализируется нулями.

По сути, с практической точки зрения, static инициализирует
	нули по умолчанию или иные перечисленные вручную значения, 
	и при последующих вызовах не "обнуляет" их в исходные значения.
В примере ниже эта фича используется внутри функции. 

void A (void);
void S (void);

int main(){
printf("first\n");	
	A();
	S();
printf("second\n");
	A();
	S();
	return 0;
}
void A (void){
	int a[] = {1,2,3};

	printf("A\n");
	for (int i = 0; i < 3; ++i)
		printf("i=%d____p=%p____%d\n", i, &a[i], a[i] );
	
	printf("A+5\n");
	for (int i = 0; i < 3; ++i)
		printf("i=%d____p=%p____%d\n", i, &a[i], a[i]+=5);
}
void S(void){
	static int a[3];

	printf("S\n");
	for (int i = 0; i < 3; ++i)
		printf("i=%d____p=%p____%d\n", i, &a[i], a[i]);
	
	printf("S+5\n");
	for (int i = 0; i < 3; ++i)
		printf("i=%d____p=%p____%d\n", i, &a[i], a[i]+=5);
}

first
	A
i=0____p=0028FF0C____1
i=1____p=0028FF10____2
i=2____p=0028FF14____3
	A+5
i=0____p=0028FF0C____6
i=1____p=0028FF10____7
i=2____p=0028FF14____8
	S
i=0____p=0040E020____0
i=1____p=0040E024____0
i=2____p=0040E028____0
	S+5
i=0____p=0040E020____5
i=1____p=0040E024____5
i=2____p=0040E028____5

second
	A
i=0____p=0028FF0C____1
i=1____p=0028FF10____2
i=2____p=0028FF14____3
	A+5
i=0____p=0028FF0C____6
i=1____p=0028FF10____7
i=2____p=0028FF14____8
	S
i=0____p=0040E020____5
i=1____p=0040E024____5
i=2____p=0040E028____5
	S+5
i=0____p=0040E020____10
i=1____p=0040E024____10
i=2____p=0040E028____10


19. Передача массива в функции Стр. 264 Дейтл./////////////////////////////////////////

int MAS[10];	- массив объявлен
func(MAS, 10);	- оператор вызова функции передает массив MAS и его размер в функцию.
	
Си передаёт массив в функцию путём имитации передачи параметра по ссылке,
	вызываемые функции могут изменять значения элементов массива. 
	Передача по значению требует копию, это неэффективно.
	Но такая возможно есть.
Отдельные значения (скаляры) передются по значению. 
	Но можно имитировать ссылку для скаляров.
	
	Чем имитация отличается от передачи по ссылке - пока хз.

void func (int b[], int size)	
Функция ожидает приём массива целых чисел в параметре b 
	и числа элементов массива в параметре size. 
	Размер массива не требуется. 
Поскольку массивы автоматически передаются путем имитации передачи по ссылке, 
	то,	когда функция использует имя массива b, 
	она на самом деле ссылается 
	на фактическисуществующий массив в вызывающей функции.
В главе 7 будут подробности. 

Прототип:
void func (int [], int);

Для предотвращения изменения значений массива в функции используется const.
Любая попытка изменить элемент const даст ошибку при компиляции.
void modA (const int b[])

Передача массива или элемента.
#include <stdio.h>
#define SIZE 5
void modA (int [], int);
void modE (int);
void printMAS(int [], int);

int main(){
	int MAS[SIZE] = {0,1,2,3,4};
	printMAS (MAS, SIZE);

	modA(MAS, SIZE);
	printMAS (MAS, SIZE);

	modE (MAS[4]);
	printMAS (MAS, SIZE);

	return 0;
}
void modA (int b[], int size){
	for (int i = 0; i <= size - 1; i++)
		b[i] *= 2;
}
void modE (int e){
	printf("%d\n", e*=2 );
	printf("\n");
}
void printMAS (int b[], int size){
	for (int i=0; i<= size-1; i++)
		printf("%d\n", b[i]);
	printf("\n");
}

20. Сортировка массивов///////////////////////////////////////////////////// 

Пузырьковая сортировка - меньшие значения всплывают вверх.
#include <stdio.h>
#define  SIZE 5

int main(){
	int hold;
	int M[SIZE] = {0,4,3,2,1};
	for (int i=0; i < SIZE; i++)
		printf("%d\n", M[i]);

	for (int pass = 1; pass < SIZE; pass++	)
		for (int i = 0; i < SIZE-1	; i++		)
			if (M[ i ]	> M[ i+1 ])	{
				hold	= M[ i ]			;
				M[ i ]	= M[ i+1 ]	;
				M[ i+1 ]= hold			;
			}
			
	for (int i=0; i < SIZE; i++)
		printf("%d\n", M[i]);
	return 0;
}

Среднее, медиана и наиболее вероятное - стр.270.

21. Поиск в массивах/////////////////////////////////////////////////////////

Последовательный перебор.
#include <stdio.h>
#define SIZE 5

int findM(int [], int, int);

int main(){
	int key;
	int M[SIZE] = {0,1,2,3,4};
	scanf("%d", &key);
	printf("element=%d\n", findM (M, SIZE, key)	);
	return 0;
}

int findM (int array[], int size, int key){

	for(int i=0; i <= size - 1; i++)
		if (array[i]==key)
			return i;
		return -1;
}

Двоичный поиск, стр 275

22. Многомерные массивы//////////////////////////////////////////////////////

M[строка][столбец] 
Значения группирируются в фигурных скобках по строкам.

int M[2][2] = {	{1,2} , {3,4} };
				0стлбц  1стлбц
	0стрк  //1//   //2//
	1стрк  //3//   //4//

int M[2][2] = {	{1} , {3,4} };
				0стлбц  1стлбц
	0стрк  //1//   //0//
	1стрк  //3//   //4//

int M[2][2] = { 1,2,3 };
				0стлбц  1стлбц
	0стрк  //1//   //2//
	1стрк  //3//   //0//

Вывод многомерного массива и передача в функцию.

В памяти строка идет за строкой.
Каждая строка - по сути одномерный массив.
Компилятор должен знать сколько элементов в каждой строке,
	чтобы при обращении к массиву он мог пропустить
	соответствующее число блоков памяти.

void printM(int [][3]);		//первый индекс не требуется, последующие - требуются.
int main(){
	int M[2][3] = {0,1,2,3,4};
	printM (M);							
	return 0;
}
void printM (int M[][3]){	//первый индекс не требуется, последующие - требуются.
	for(int i=0; i < 2; i++){
		for (int j = 0; j < 3; j++)
			printf("%d ", M[i][j] );
		printf("\n");
	}
}

23. Сколько там еще задач всяких.......

24.Указатели//////////////////////////////////////////////////////

Указатель - это переменная, значением которой является адрес памяти.
	Переменная непосредственно/прямо ссылается на значение,
	а указатель косвенно ссылается на значение.
Ссылка на значение через указатель называется косвенной адресацией.

Своими словами. 
Нельзя просто взять адрес и присвоить его переменной.
Сначала нужно объявить переменную как указатель, 
	а уже потом инициализировать каким-либо адресом.

int *countPtr; //* объявлет переменную, которая является указателем.

Указатели должны быть инициализированы при:
	объявлении,
	либо при помощи оператора присваивания. 
	
Указатель может быть инициализирован:
	1. нулем,
	2. макросом NULL (указывает ни на что),
	3. значением адреса.

Символическая константа NULL определяется в файле заголовка <stdio.h>
	(и в некоторых других заголовочных файлах). Инициализация значением 
	0 эквивалентна конастанте NULL, но NULL предпочтительнее.

25. Операции над указателями///////////////////////////////////////////////////////////

int y = 999; 
int *yPrt;	//объявление указателя на целое.
yPrt = &y;	//назначает переменной-указателю yPtr адрес переменной y. 
Операндом взятия адреса должна быть переменная, эта операция не может
	применяться к константам, выражениям или register-переменным.

* - операция косвенной адресации/разыменовывания,
	возвращает значение объекта, 
	на который операнд (то есть указатель) ссылается.

yPtr	 дает адрес ячейки, на которую указывает указатель.
*yPtr	 дает значение ячейки, на адрес которой указывает указатель.
&*yPtr дает адрес ячейки, на которую указывает указатель (или *&yPtr).
&yPtr  дает адрес указателя, судя по всему.

int main(){
	int y = 999;
	int *yPrt;
	yPrt = &y;
	printf("%p	\n",	&y			);	//0028FF3C		%p

	printf("%p	\n",	yPrt		);	//0028FF3C		%p
	printf("%d	\n",	*yPrt		);	//999				%d
	printf("%p	\n",	&*yPrt	);	//0028FF3C		%p
	printf("%p	\n",	&yPrt		);	//0028FF38		%p

	return 0;
}

26. Передача параметра по ссылке///////////////////////////////////////////////////////

Есть два способа передачи параметров функции:
	по значению, 
	по ссылке. 

Все вызовы фукций в С являются вызовами по значению.
	С помощью return можно возвратить единственное значение или вернуть управление. 

Однако, во многих случаях нужно иметь возможность изменять не одну,
	а несколько переменных в вызывающей функции 
	или передавать указатель на большой объект данных, 
	чтобы избежать задержек связанных с передачей параметра по значению 
	(так как в этом случае создается и потом передается копия объекта).
Для этих целей существует возможность вызова функции по ссылке.
	Для этого используют указатели и операции косвенной адресации. 

Если вызывается функция, аргументы которой должны изменять, то в этом случае 
	ей передаются адреса аргументов.
Если в качестве аргумента передается массив - то функция получает
	адрес начала массива.

#include <stdio.h>
void Fnc (int *);

int main(){
	int x = 5;
	printf("%p____%d\n", &x, x );
	Fnc(&x);		//передаем адрес в функцию.
	printf("%p____%d\n", &x, x );
	return 0;
}

void Fnc (int *nPtr){
	printf("%p\n", nPtr );
	*nPtr = *nPtr * *nPtr;		//разыменовывание указателя. Будто x = x*x только в main.
	printf("%p\n", nPtr );
}
0028FF3C____5
0028FF3C
0028FF3C
0028FF3C____25

Заголовок функции void Fnc (int *nPtr) показывает, что функция 
	получает	в качестве аргумента адрес целой переменной, 
	помещает его в локальную переменную nPtr и 
	не возвращает значения.

Если функция может получить в качестве аргумента одномерный массив,
	то в заголовке соответствующий параметр может быть определен как указатель.

Когда компилятор встречает одномерный массив в качестве параметра функции, 
	заданный в форме int b[], 
	то компилятор преобразует это параметр к виду int *b.
	Эти две формы взаимозаменяемы. 
		В чем прикол? Можно в параметрах функции объявить указатель *x, 
			а внутри функции работать с массивом x[].
		Нужно помнить, что имя массива - это адрес первого элемента.
		Нужно помнить, что ожидает и что нужно передавать в функцию -
			адрес или значение.
		Ну и вообще(см. указатель-константа на не-констатные данные):
		int main(){
			int s[] = {4,5,6};
			printf("%p_%d\n", &s[0],s[0]);//0028FF34_4
			printf("%p\n", s );				//0028FF34
			printf("%d\n", *s );				//4
			return 0;
		}

	
27. Использование модификатора const с указателями/////////////////////////////////////////

Модификатор const сообщает компилятору о том, что значение переменной не должно изменяться.
Существует 6 вариантов использования const: 2 по значению и 4 по ссылке.
При вызове функции ей передается копия аргумента. Первоначальное значение аргумента
	в вызвавшей функции остается без изменения. 
	Однако, в некоторых случаях, 
	переданное значение не должно изменяться, несмотря на то, 
	что функция	оперирует лишь копией.

Существует 4 способа передать функции указатель:
	изменяемый		указатель на изменяемые		данные, 
	изменяемый		указатель на неизменяемые	данные,
	неизменяемый	указатель на изменяемые		данные,
	неизменяемый	указатель на неизменяемые	данные.

Не-константный указатель на не-констатные данные:
void Fnc (char *);
int main(){
	char M[]= "hello";
	printf("%s\n", M);
	Fnc(M);
	printf("%s\n", M);	
	return 0;
}
void Fnc (char *s){
	while ( *s != '\0'){
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		++s;
	}
}

Не-константный указатель на данные-константы:
void Fnc (const char *);
int main(){
	char M[] = "hello";
	Fnc(M);
	return 0;
}
void Fnc (const char *s){	//s-указатель на символ-константу.
	for (; *s != '\0'; s++)	//добавляем единицу к адресу.
		putchar(*s);			
}
А такая функция вызовет ошибку:
void Fnc (const char *s){
	*s = 100 ;			//потому что *s это уже значение по адресу s.
}

Указатель-константа на не-констатные данные.
Указатель, который всегда указывает на одно и то же место в памяти,
	а расположенные там данные могут изменяться.
Такой указатель назначается по умолчанию для имени массива.
Имя массива является указателем-константой на начало массива.
int main(){
	int s[] = {4,5};
	printf("%p	%d\n", &s[0],s[0]);	//0028FF38	4
	printf("%p	%d\n", &s[1],s[1]);	//0028FF3C	5
	printf("%p	%d\n", s, *s );		//0028FF38	4 
	*s = 7;
	printf("%p	%d\n", s, *s );		//0028FF38	7
	s = &s; // или иное - уже даст ошибку.
	return 0;
}

Попытка изменения указателя-константы, ссылающегося на не-константные данные 
	приведет к ошибке:
int main(){
	int x, y;
	int *const ptr = &x;//такие указатели необходимо инициализировать при объявлении.
	//Если такой указатель передается функции, то он инициализируется переданным значением.
	ptr = &y
	return 0;
}

Указатель-константа на константные данные.
Такой указатель всегда указывает на то же самое место в памяти,
	а расположенные по этому адресу данные не могут модифицироваться.
Приведет к ошибкам:
int main(){
	int x = 5; y;
	const int *const ptr = &x;
	*ptr = 7;
	ptr = &y;
	return 0;
}	

Программа пузырьковой сортировки, использующая вызов по ссылке.
Функция вызывает функцию. 
Бабл передает свопу элементы по ссылке.
При использовании имени массива в качестве аргумента
	передается весь массив целиком,
	индивидуальные элементы являются скалярами и 
		передаются по значению.
#include <stdio.h>
#define SIZE 10
void bubbleSort(int *array, int size);

int main(){
int i, a[SIZE] = {2,6,4,8,10,12,89,68,45,37};
	for (int i = 0; i < SIZE; ++i)
		printf("%4d\n", a[i]);

	bubbleSort (a, SIZE);

	for (int i = 0; i < SIZE; ++i)
		printf("%4d\n", a[i]);

	return 0;
}

void bubbleSort(int *array, int size){
	void swap(int *, int *);

	for (int pass = 1; pass < size; pass++)
		for (int i = 0; i < size -1; i++)
			if (array[i] > array [ i + 1])
				swap( &array[i] , &array[i+1] );
}

void swap (int *elementPtr, int *element2Ptr){
	int temp;
	temp = *elementPtr;
	*elementPtr = *element2Ptr;
	*element2Ptr = temp;
}














//////////////////////////////////////////////////////////////////////////
"Компилятор".
#include <stdlib.h> 
#include <stdio.h>
#include <conio.h> 
int main(){
	system("gcc \"C:/GD/books/Coding/MinGW/CUBEC/test.c\" ");
	printf("\n\n\n				End of LOG... Press ENTER.\n");
	getchar();
	system("a");
	return 0;
}
//////////////////////////////////////////////////////////////////////////
putchar.
#include <stdio.h>
int main(){    
	int s = 90; 
	putchar (s);
	putchar (90);
	putchar ('\n');
	putchar ('Z');
	return 0;
}
//////////////////////////////////////////////////////////////////////////
Вывод с задержкой в секунду.
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
int main(){

	for(int i=0; i < 100; i++){
		system("cls");

		if( (i % 2) != 0){	
			for(int i=0; i<4; i++)
				printf("1111\n");
			sleep(1);
		}

		if( (i % 2) == 0){	
			for(int i=0; i<4; i++)
				printf("0000\n");
			sleep(1);
		}
	}
}
//////////////////////////////////////////////////////////////////////////
Перевод в двоичную систему.
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void FUNC (int);
int main(){
	int number = 0;

	while ( number != 999){
		printf("Enter chislo:");
		scanf("%d", &number);
		FUNC(number);
		printf("\n");	
	}
}
void FUNC (int x){
	int ZOP[8]={0};
	int I = 0;
	
	while ( x != 0){
		ZOP[I]=x%2;
		x = x / 2 ;

		if (x == 0)
			break;
		I=I+1;
	}
	
	while ( I >= 0){
		printf("%d", ZOP[I]);
		I = I-1;
	}
}
//////////////////////////////////////////////////////////////////////////
Опыты с getchar и putchar

#include <stdio.h>
int main(){
	int c;
	while ( ( c = getchar() ) != 113 )
		printf("%d\n", c);
		putchar (c);
}

int main(){
	char enter;
	scanf ("%d", &enter);
	printf("%c , code=%d\n", enter, enter);// берет целое, приравнивает к переменной char, выводит как символ или целое. 
	return 0;
}


int main(){
	int c;

	while ( ( c = getchar() ) != 113 ){
		printf("=%d\n", c);
		putchar (c);
		putchar ('\n'); //по второму кругу забавно выводит пустую строку как символ новой строки 10
	}
}

int main(){
	int c;
	
	while ( ( c = getchar() ) != 113 ){
		printf("%d\n", c);
	}
	putchar (c); //забавно, что тут путчар выведет в случае q только q
}
//////////////////////////////////////////////////////////////////////////
