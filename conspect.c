#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>
#include <time.h>
/*
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h> 
void main(){
	for(int i=0; ; i++){
		system("cls");
		printf("%d sec", i);
		sleep(1);
	}
}


*/

//main - главная функция (в win нужно указывать тип возвращаемых (void, int) ею данных). 
//в случае, если функция возвращает ничего (void), указание возврата (return) можно не писать.
// в main return 0 означает конец  программы.
void main(){
}
// ИЛИ
int main(){
	return 0;
}
// \n - ESC код, их много, работают с функцией printf.
void maim(){
	int integer1; // объявление имен переменных и их типа данных, а также можно и значение указать.
				  // имя до 31 символа, учитываются строчные и заглавные буквы.
				  // объявления должны располагаться после первой левой скобки и перед первым исполняемым оператором.
	int integer2 = 123;
	scanf ("%d", &integer1) //%d - показывает, что данные должны быть целым числом
					//&d - знаком амперсанда задается операция взятия адреса следующей за ним переменной.
					//Сообщает сканфу ячейку памяти, в которой хранится переменная integer1. Компьютер будет хранить 
					//величину для integer1 в этой ячейке. Подробнее расмотрено в главе про указатели.
}
//Явные и неявные преобразования
void main(){
	int A = 5; 
	int B = 2;
	float C = 2;
	printf("%d\n", A/B ); // целое на целое отбросит дробную часть
	printf("%f\n", A/C) ; // выполнит неявное преобразование целого B в float (создаст копию)
	printf("%f\n", (float) A/B ); //выполнит явное преобразование A в float, B тогда возведётся до float
}
//Ибо первое преобразование int даст 1.
3/2*3.14=3.14 
//конструкция IF
void main(){	
	int A;
	scanf ("%d", &A);
	
	if (A >= 2){
		printf(">=2\n");
	}

	if (A < 2){
		printf("<2\n");
	}

}

if (/* condition */)
	printf("AAA");
else
	if (/* condition */)
		printf("BBB");
	else
		if ()
			printf("CCC");

if (/* condition */)
	printf("AAA");
else if (/* condition */)
	printf("BBB");
else if (/* condition */)
	printf("CCC");

//дополнение
printf("%s\n", grade >= 60 ? "Passed" : "Failed" );

grade >= 60 ? printf("Passed") : printf("Failed" );

//While
 while (stud < 10){
 	printf("AAA");
 	stud = stud + 1;
 }

//Операции присваивания
c = c + 3;
// равносильно
c += 3;
	
++a; // преинкремент, увеличивает на 1, использует новое значение.
a++; // постинкремент, использует значение, потом увеличивает на 1.  

a = 5;
printf("%d\n", ++a );
printf("%d\n", a);
a = 5;
printf("%d\n", a++);
printf("%d\n", a);

даст:
6
6
5
6

//
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

// for

void main(){
	
	for (int i = 0; i <= 2; i++){

		printf("%d\n", i );
	}

}

//switch
void main(){

	int gon = 0;
	
	while ( gon != -1 ) {
		scanf ("%d", &gon);
		switch (gon) {
			case 1 : case 2 : // если gon = 1 или gon = 2
				printf("1or2");
				break;

			case 5 : // если равен 5
				printf("5");
				break;

			case '\n' : case '': // игнор символа переноса и пробела, если работа с символами
				break;

			default : // все остальные случаи
				printf("other");
				break;
		}			
	}

}	

// do while
void main(){
	int counter = 1;
	do {
		printf("%d\n", counter);
	}	while ( ++counter <= 10);
}

// break continue

void main(){
	int  x;

	for (x = 1; x <= 10; x++){
		if(x == 5)
			break; // break досрочно выводит из цикла, есть и другие структурные способы это сделать.
		printf("%d ", x );
	}

	printf("lalala %d\n", x);
}

void main(){
	int  x;

	for (x = 1; x <= 10; x++){
		if(x == 5)
			continue; // continue пропускает оставшийся код в цикле, если х == 5.
		printf("%d ", x );
	}

	printf("lalala %d\n", x);
}

//логические
void main(){
	int  x;

	scanf("%d", &x);

	if ( !(x == 2) )	{
		printf("!(%d==2)\n", x);
	}		

}


//Функции
//Любая функция должна быть объявлена перед тем, как будет использована. Просто надо, иначе будут ошибки. Хоть и есть нюансы. Стр180 Дейтла.
//Прототип соответствует списку параметров. Если прототип не указать - компилятор сам создаст кое-как прототип и будет бида.
//Имена лучше делать разными.
тип возвращаемых ИМЯ (тип принимаемых значений по порядку, оно же список параметров)

float FUNC(int, double); 
float FUNC(int x, double y) {
}

//1
float FUNC(int);
	
void main() {
	printf("%.3f", FUNC(2));
}

float FUNC(int x ) {
	float tmp = x / 3.0 ;
	return tmp;
}

//2
void funk (void);

void main (void) {
	funk();	//() если void - то в скобках именно пусто быть должно. Даже void в скобках быть не	должен.
}

void funk(void){
		printf("HELLO\n");
	}

//3
int AAA(int);
int BBB(int);


int AAA(int aaa){
		int a ;
		
		a=BBB(aaa);
		return a;
	}

int BBB(int aaa){
		int y;	

		y = aaa * 1000; 
	    return y;
	}

void main(){
		int ZZZ;

	  	scanf ("%d", &ZZZ );
	    printf("%d", AAA(ZZZ) );
   	}
//
/*
Вызов по значению - вызываемой функции передаётся копия значения аргумента.
	Изменения с копией не отражаются на значении исходной переменной в вызывающей функции.
Вызов по ссылке - вызывающая функция позволяет вызываемой функции изменять значение исходной переменной.
В С все вызовы передают аргументы по значению. При этом есть методы имитации передачи по ссылке используя операцию взятия адреса 
	и косвенные операции.
Массивы автоматически передаются посредством имитации по ссылке. 
*/
//Классы памяти
Автоматический период хранения:
Существуют, пока блок активен, уничтожаются после выхода из блока.
auto float x; - слово auto используется редко, т.к. локальные переменные имеют auto по умолчанию. Auto экономит место в памяти.
register int counter = 1; - рекомендует компилятору поместить в регистр.

Статический период хранения:
Существуют с того момента, когда программа начинает выполнятся
extern - глобальные переменные	
static - локальные переменные
Дейтл, стр.211

//Рекурсия
Всё, что можно написать рекурсией - можно написать и итерацией. Нужно выбирать подход в зависимости от обстоятельств. Рекурсия требует
	больше ресурсов. 

int FUNC(int);

void main(void){
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
