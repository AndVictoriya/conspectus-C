GCC 
utf8

	Настройка переменных сред для возможности ввода gcc без полного пути:
	Переменные среды, создать PATH с значением D:\GDrive\books\C\MinGW\bin\

	Настройка директории по-умолчанию при запуске консоли:
	[HKEY_CURRENT_USER\Software\Microsoft\Command Processor] "Autorun"="cd /d D:\GDrive\books\С\MinGW\CUBEC" 
	/d нужна при смене диска

	Директории gcc:
	MinGW\libexec\mingw-get\guimain.exe - update and setup
	MinGW\bin\gcc.exe

	SUBLIME 
	{
	"fallback_encoding": "Cyrillic (Windows 1251)",
	"auto_complete" : false,
	"tab_completion" : false,
	"update_check": false,
	"word_wrap": "true"
	}

	keyBinding:
	{ "keys": ["f5"], "command": "save" },

	Ctr+K,B скрыть панель папки слева, если она была. 
	ctrl+[ сдвинуть влево
	ctrl+] сдвинуть вправо

	Сompile 
	Экранирование символов — механизм, имеющийся в текстовых языках и протоколах. 
	Он служит, чтобы символы, которые считаются служебными и имеют особое значение, этого значения лишить и объявить «просто символами». 
	Нам нужно двойное экранирование: для ОС (строка с пробелами закавычивается) и для Си (перед кавычкой слэш).

	system("gcc \"C:/Folder/My Folder/example.c\" ");
	Точно так же экранируется и обратный слэш, если вдруг потребуется.
	system("gcc \"C:\\Folder\\My Folder\\example.c\"" );

	cd D:\books
	gcc C:\Cex\test.c -o C:\Cex\test.exe

	-c Compile or assemble the source files, but do not link
	-S Stop after the stage of compilation proper; do not assemble. 




	Исходник > 
		препроцессор (подключает прототипы функций из заголовочных файлов) > 
			компилятор (сначало в асм?, потом в объектный/машинный код) > 
				компоновщик (линкер, линковщик добавляет куски скомпилированных библиотек)









	Настройка для компиляции из саблайма.
	tools>build system
	{
	    "cmd": ["gcc", "${file}", "-o", "${file_base_name}.exe"],
	    "file_regex": "^(..[^:]*):([0-9]+):?([0-9]+)?:? (.*)$",
	    "working_dir": "${file_path}",
	    "selector": "source.c, source.c++",
	    "shell": true,

	    "variants":
	    [
	        {
	            "name": "Run",
	            "cmd": ["start", "cmd", "/k", "${file_path}/${file_base_name}.exe"],
	            "shell": true
	        }
	    ]
	}





	"Компилятор".
	#include <stdlib.h> 
	#include <stdio.h>
	#include <conio.h> 
	int main (void){
		system("gcc \"C:/GD/books/Coding/MinGW/CUBEC/test.c\" ");
		printf("\n\n\n				End of LOG... Press ENTER.\n");
		getchar();
		system("a");
		return 0;
	}



















Введение
We use the structured approach (подход) throughout the remainder (на протяжении оставшейся) of the C portion (части) of the text.

Наступает великий миг: я утверждаю, что собранное нами
устройство может с полным правом именоваться компьютером!
Очень примитивным, но компьютером. Его ключевое свойство
— наличие команды условного перехода. Именно возможность
управляемых циклических процедур отличает компьютер от
калькулятора. Петцольд, 283.


1	#include <stdio.h>

Lines beginning with # are processed by the preprocessor before compilation. 
This is a directive to the C preprocessor. It tells the preprocessor to include the contents of the standard input/output header (<stdio.h>) in the program. 
This header contains information used by the compiler when compiling calls to standard input/output library functions such as printf. 
We explain the contents of headers in more detail in Chapter 5 and 13.




2	int main (void)//int main () 
	{

	}

The parentheses () after main indicate that main is a program building block called a function. 
C programs contain one or more functions, one of which must be main. The main function is a part of every C program. Every program in C begins executing at the function main. 

A left brace { begins the body of every function. A corresponding right brace } ends each function.
This pair of braces and the portion of the program between the braces is called a block. The block is an important program unit in C. 

Functions can return information. The keyword int to the left of main indicates that main “returns” an integer (whole-number) value. 
We’ll explain what it means for a function to “return a value” when we demonstrate how to create your own functions in Chapter 5. 

Functions can receive information when they’re called upon to execute. 
The void in parentheses here means that main does not receive any information. In Chapter 14, we’ll show an example of main receiving information. 




3	printf( "Welcome \\ to C!\n" );

An Output Statement instructs the computer to perform an action (namely to print on the screen the string of characters marked by the quotation marks ""). 
A string is sometimes called a character string (символьная строка), a message or a literal. 
The entire line, including the printf function (the “f” stands for “formatted”), its argument within the parentheses () and the semicolon ; , is called a statement. 
Every statement must end with statement terminator a semicolon ; . 

The backslash (\) is called an escape character. Они же esq-коды.

Printf causes the computer to perform an action. 
As any program executes, it performs a variety (множество) of actions and makes decisions. 
Executable statements either perform actions (calculations, input or output of data, etc) or make decisions (if, while, etc) (стр 54). 


The Linker and Executables. Standard library functions like printf and scanf are not part of the C programming language. Сompiler cannot find a spelling error in printf or scanf. When the compiler compiles a printf statement, it merely provides space in the object program for a “call” to the library function (e.g printf). But the compiler does not know where the library functions are — the linker does. When the linker runs, it locates the library functions and inserts the proper calls (соответствующие вызовы) to these library functions in the object program (причем, вставляет он уже обжекнутые куски кода). Now the object program is complete and ready to be executed. For this reason, the linked program is called an executable. If the function name is misspelled, the linker will spot the error, because it will not be able to match the name in the C program with the name of any known function in the libraries.




4	int integer1, integer2;
	int sum; 

This line are definitions (определения). The names integer1, integer2 and sum are the names of variables (переменных). Variables is the locations in memory where values can be stored for use by a program. Variable names such as integer1 and sum actually correspond to locations in the computer’s memory. These definitions specify (указывают) that variables integer1, integer2 and sum are of type int, which means that they’ll hold integer values, i.e., whole numbers such as 7, –11, etc. Every variable has a name, a type and a value. All variables must be defined with a name and a data type before they can be used in a program. 

Definitions are not executable statements—they’re simply messages to the compiler (стр 72). 

For readers using the Microsoft Visual C++ compiler, note that we’re placing our variable definitions immediately after the left brace { that begins the body of main. The C standard allows you to place each variable definition anywhere in main before that variable’s first use in the code. Some compilers, such as GNU gcc, have implemented this capability. We’ll address this issue in more depth in later chapters.
Recall that the Microsoft Visual C++ compiler requires variable definitions to be placed after the left brace { of a function and before any executable statements. Therefore, in the program in Fig. 2.5, inserting the definition of integer1 after the first printf would cause a syntax error in Visual C++. 

Вдобавок объявления могут быть внутри выделенных блоков, см. области действия. 
	int main (void){
			int x = 1;
			printf("%d\n", x);//1
		{
			x = x + 10; 
			printf("%d\n", x);//11
		}
		{	
			printf("%d\n", x);//11
		}
		{	
			int x = 3;
			printf("%d\n", x);//3
		}
			printf("%d\n", x);//11
		return 0;
	}

A variable name in C is any valid identifier (идентификатор). An identifier is a series of characters consisting of letters, digits and underscores (_) that does not begin with a digit. C is case sensitive — uppercase and lowercase letters are different in C, so a1 and A1 are different identifiers. The first letter of an identifier used as a simple variable name should be a lowercase letter. Later in the text we’ll assign special significance to identifiers that begin with a capital letter and to identifiers that use all capital letters. 



 
5	scanf("%d", &integer1);
	scanf("%d", &integer2);

This statement uses scanf (the “f” stands for “formatted”) to obtain a value from the user. The function reads from the standard input, which is usually the keyboard. 

This scanf has two arguments: "%d" and &integer1. 

The first, the format control string (строка управляющая форматом) "%d". It indicates the type of data that should be entered by the user. 
The %d conversion specifier (спецификатор преобразования) indicates that the data should be an integer. 
The % in this context is treated (рассматривается) by scanf (and printf as we’ll see) as a special character (специальный символ, как esq-код) that begins a conversion specifier. 
The letter d stands for “decimal integer”. 

The second argument &integer1 of scanf begins with an ampersand & (address operator) followed by the variable name (& (адрес оператор) за которым следует имя переменной). 
The &, when combined with the variable name integer1, tells scanf the location (or address) in memory at which the variable integer1 is stored. 
The computer then stores the value that the user enters for integer1 at that location. 

Some exceptions to this rule are discussed in Chapters 6 and 7. The use of the ampersand will become clear after we study pointers in Chapter 7. 
Forgetting to precede a variable in a scanf statement with an ampersand when that variable should, in fact, be preceded by an ampersand this causes a “segmentation fault” or “access violation.” The precise cause of this error will be explained in Chapter 7.




6	sum = integer1 + integer2;	

This is assignment (присваивания) statement calculates the total of variables integer1 and integer2 and assigns the result to variable sum using the assignment operator =. 
Most calculations are performed in assignments. 
The = operator and the + operator are called binary operators because each has two operands. 
The + operator’s two operands are integer1 and integer2. 
The = operator’s two operands are sum and the value of the expression (выражение) integer1 + integer2




7	printf( "Sum is %d\n", sum ); 

This printf has two arguments, "Sum is %d\n" and sum. 

The first argument "Sum is %d\n" is the format control string. 
It contains some literal characters Sum is  to be displayed, and it contains the conversion specifier %d indicating that an integer will be printed. 

The second argument sum specifies (задает, указывает) the value to be printed. 


Secure print:
	Avoid Single-Argument printfs:
	good:
		puts( "Welcome to C!" );
		printf( "%s", "Welcome " );
	bad:
		printf( "Welcome to C!\n" );
		printf( "Welcome " );





wiki
In computer programming, a statement is a syntactic unit of an imperative programming language that expresses (выражает) some action to be carried out (которые необходимо выполнить). A program written in such (таком) a language is formed (сформирована чем) by a sequence of one or more statements. A statement may have internal components (e.g. например, expressions). Many imperative languages (e.g. C) make a distinction (делают различие) between statements and definitions, with (причем) a statement only containing executable code and a definition instantiating an identifier (определение, создающее экземпляр идентификатора), while (тогда как) an expression evaluates (оценивается) to a value only. A distinction (различие) can also be made between simple and compound statements; the latter may contain statements as components. 
Simple statements a = a + b; return z;
Compound statements {} блок, if, for.
In most languages, statements contrast with expressions, in that statements do not return results and are executed solely for their side effects, while (когда как) expressions always return a result and often do not have side effects at all. This distinction (различие) is frequently observed in wording (в формулировках) : a statement is executed, while an expression is evaluated. a = b = c = 0 - выражение оценивается справа налево, сначала с, потом b, потом a.
In purely (чисто) functional programming, there are no statements; everything is an expression.

C how to program
Pseudocode consists only of action statements—those that are executed when the program has been converted from pseudocode to C and is run in C. Definitions are not executable statements—they’re simply messages to the compiler. For example, the definition tells the compiler the type of variable i and instructs the compiler to reserve space in memory for the variable. But this definition does not cause any action—such as input, output, a calculation or a comparison—to occur when the program is executed. 

wiki
An expression in a programming language is a combination of one or more constants, variables, operators, and functions that the programming language interprets (according (в соответсвтии с) to its particular rules of precedence and of association) and computes (вычисляет) to produce (производства) ("to return", in a stateful environment (в состояние среды??)) another value. This process, as for mathematical expressions, is called evaluation.

хз откуда
An expression (выражение) is a sequence of operators.
Statements are fragments of the C program that are executed in sequence (в последовательности или последовательно?). 
The body of any function is a compound (составная) statement which in turn is a sequence of statements and declarations (объявлений).







Assignment Operators, Increment and Decrement Operators, стр 93.
	
	Statement c = c + 3; can be abbreviated (сокращена) with the addition assignment operator += as c += 3; 
	Это компилируется быстрее.
		
	C also provides the unary increment operator ++ and the unary decrement operator --.

	++a преинкремент, увеличивает на 1, использует новое значение.
	a++ постинкремент, использует значение, потом увеличивает на 1.  
	Преинкремент работает быстрее. 
	И обрати внимание на while.

	a = 5;
	printf("%d\n", ++a);	//6
	printf("%d\n", a	);	//6	
	a = 5;
	printf("%d\n", a++);	//5
	printf("%d\n", a	);	//6









Operator precedence (приоритетность, старшинство) and associativity (ассоциативность), стр 136, 218, 281.
	А понятнее Associativity and Operator precedence (or Order of operations), потому что сначала нужно разобраться почему 7-4 + 2 = 5, а не 1; и только потом разбираться почему * старше +.

	Operators								Associativity	Type			My comment
	
1	() () []								left to right	parentheses		(expression) in parentheses evaluated first, func() function call operator, [] for to enclose (заключить) the subscript (индекс) of an array
2	++(postfix) --(postfix)					right to left					type длинный: postfix, unary, highest; возможно имеет одинаковую приоритетность со строчкой выше; a++, b--			
3	+ - ! ++(prefix) --(prefix) (type) & *	right to left	unary			унарные версии (+5,-7), !(grade != sum), ++a, --b, cast operator a(float),  address operator, indirection Operator
4	* / %									left to right	multiplicative	binary
5	+ -										left to right	additive		binary
6	< <= > >=								left to right	relational
7	== !=									left to right	equality		The equality operators have a lower level of precedence than the relational operators and they also associate left to right (см ниже, в if и в logical)
8	&&										left to right	logical AND		binary
9	||										left to right	logical OR		binary
10	?:										right to left	conditional		ternary
11	= += -= *= /= %=						right to left	assignment		binary
12	,										left to right	comma			119 стр for Repetition Statement, Comma-Separated Lists (списки) of Expressions; 122 стр could actually be merged into

https://en.wikipedia.org/wiki/Order_of_operations
https://en.wikipedia.org/wiki/Operator_associativity

2:	Therefore you should use increment or decrement operators only in statements in which one variable is incremented or decremented by itself (использовать в отдельных инструкциях). 

4:	8 / 16 / 2 распознается как 1/2 / 2 = 1/4   , а не 8 / 8 = 1
		4/8/2/3 = 4 / (8*2*3)
		4/8/2/3 в реале нужно следить за associativity , а если в реале в виде дробей 4 * 1/8 * 1/2 * 1/3 то необязательно (в си везде следить нужно).

5:	7 - 4  + 2 из-за левоассоциативности распознается как (7 - 4) + 2 = 5 ; если бы эти операции были правоассоциативными, то 7 - (4 + 2) = 1.

6:	a < b < c  распознается как ( a < b ) && ( b < c ). wiki.

	a = 2    b = 1    c = 3
	a == b 			0
	a != b 			1
	b <= c 			1
	a == b <= c 	0
	(a == b) <= c 	1
	a != b <= c 	1
	a != b <= c 	1

11:	a = b = c = 0 распознается как a = (b = (c = 0))


Keywords
	auto double int struct
	break else long switch
	case enum register typedef
	char extern return union
	const float short unsigned
	continue for signed void
	default goto sizeof volatile
	do if static while

	Keywords added in C99 standard
	_Bool _Complex _Imaginary inline restrict
	Keywords added in C11 draft standard
	_Alignas _Alignof _Atomic _Generic _Noreturn _Static_assert _Thread_local




Data type/printf conversion specification/scanf conversion specification

	Floating-point types
	long double %Lf %Lf
	double %f %lf
	float %f %f

	Integer types
	unsigned long long int %llu %llu
	long long int %lld %lld
	unsigned long int %lu %lu
	long int %ld %ld  +2147483647 4 байта
	unsigned int %u %u
	int %d %d
	unsigned short %hu %hu
	short %hd %hd +32767 2 байта
	char %c %c 
	signed char +127 1 байт (разница между чарами хз)

	Fig. 5.5 | Arithmetic data types and their conversion specifications.

	sizeof(int) sizeof(A) sizeof(sum)  


Про типы данных.
	Тут есть некоторые вопросы с char. signed char и unsigned char.
	char будет зависеть от ключей компиляции, вероятно.

	Массив из char или signed char
	C:\Users\Qyb>a
	0000007E  126 126
	0000007F  127 127
	FFFFFF80 -128 4294967168
	FFFFFF81 -127 4294967169
	FFFFFF82 -126 4294967170

	C:\Users\Qyb>gcc test.c
	unsigned char
	C:\Users\Qyb>a
	0000007E  126 126
	0000007F  127 127
	00000080  128 128
	00000081  129 129
	00000082  130 130




Явные - неявные преобразования???
	int A = 2; int B = 5;
	float C = 7;
	int p; float g;
	printf("%d_%d\n", A/B, B/A );//0 2 0.000000 -1.#QNAN0 ; если %f единственный - то 5/2 или 2/5 даст 0.00000
	printf("%f %f\n", A/B, B/A );//0 2 0.000000 -1.#QNAN0 ; если %f единственный - то 5/2 или 2/5 даст 0.00000
	printf("%f\n", 3/2 );		//Выдаст ноль... 
	printf("%f\n", 3.0/2.0 );	//или хотя бы один с .0 вызовет преобразование и будет ок.
	printf("%f\n", 3/2*3.14 );	//3.140000
	printf("%f\n", 2/3*3.14 );	//0.000000.
	printf("%f\n", 3.0/2*3.14 );//4.710000
	printf("%f\n", A/C) ;		//0.285714 - выполнит неявное преобразование (создаст копию) int A во float.
	printf("%f\n", (float) A/B );//0.50 - выполнит явное преобразование int A во float, что потом неявно возведёт int B до float.
	printf("%f\n", x>2 && x <5);//Тоже выдает ноль, вне зависимости от истинности... Похоже, что %f при работе с int выдет бред.
	
	p=4; 
	g=4.35;
	printf ("%d\n", p);//4
	printf ("%f\n", p);//-1.#QNAN0
	printf ("%d\n", g);//1610612736
	printf ("%f\n", g);//4.350000

	p=4; 
	g=4.35;
	p = g;
	printf ("p=g\n");

	printf ("%d\n", p);//4
	printf ("%f\n", p);//4.349998

	p=4; 
	g=4.35;
	g = p;
	printf ("g=p\n");

	printf ("%d\n", g);//0
	printf ("%f\n", g);//4.000000



















Control structures (управляющие структуры). Структуры - это из датасаенс, общее понятие. 
В C эти структуры реализованы в виде инструкций.

В основе лежит структурное программирование и отказ от goto. Суть в том, что бы любая структура подключалась к остальным как блок со входом и выходом. Это отлично видно в flowcharts!

All programs could be written in terms of only three control structures: the sequence structure, the selection structure and the repetition structure.
	1. The sequence structure (любой тип действий, вычисление, ввод/вывод) is simple — unless directed otherwise, the computer executes C statements one after the other in the order in which they’re written. 
	2. C provides three types of selection structures in the form of statements: if, if/else, switch.
	3. Repetition Statements, three types of in the form of statements: while, for, do/while.











The if Statement, single-selection statement (с одиночным выбором).

	if ( a > b ){
			printf("something\n");
		}

Conditions in if statements are formed by using the equality operators and relational (отношения) operators. 
Если condition есть constant, то условие всегда будет возвращать истину.
The relational operators all have the same level of precedence and associate (ассоциируется) left to right. 
The equality operators have a lower level of precedence than the relational operators and they also associate left to right. 

	scanf ("%d", &x); 
	printf("%d\n", x>=2); 

Напечатает 0 или 1 в зависимости от истинности.

Совокупность инструкций внутри {} скобок называтеся составной инструкцией или блоком:
	if(/* condition */) {//condition представляет собой, я так понимаю, expression, то есть выражение; хотя там же есть getchar()=, значит и statement.
		инструкция1;
		инструкция2;
	}

Составную инструкцию можно помещать где угодно. 
Так же можно использовать пустой оператор ";" на месте, обычно занимаемым некоторым оператором. 

	int main (void){	
		int A;
		scanf ("%d", &A);
		if (A >= 2){
			printf(">=2\n");
		}
		if (A < 2){
			printf("<2\n");
			printf("LOL\n");
		}
	}










The if…else Selection Statement, double-selection statement. 


	if ( grade >= 60 ){
	 puts( "Passed" );
	} // end if
	else{
	 puts( "Failed" );
	} // end else

Simple if…else statements.
 

	if (/* condition */){
		printf("AAA");
	}
	else if (/* condition */){
		printf("BBB");
	}
	else if (/* condition */){
		printf("CCC");
	}

Nested if…else statements.


	printf 	(			grade >= 60 ? "1Passed\n" : "Failed\n" );
	printf 	("%s\n" , 	grade >= 60 ? "2Passed" : "Failed" );
	puts 	(			grade >= 60 ? "3Passed" : "Failed" );

	grade >= 60 ? printf( "Passed" ) : printf( "Failed" );
	grade >= 60 ? printf("%s", "Passed") : printf("%s", "Failed" );
	grade >= 60 ? puts 	( "Passed" ) : puts( "Failed" );

The conditional operator ?: is C’s only ternary operator — it takes three operands. These (three operands) together with the conditional operator ?: form a conditional expression (условное выражение). 
The first operand grade >= 60 is a condition (условие). 
The second operand string "Passed" is the value for the entire(всего) conditional expression (условного выражения) if the condition is true.
The third operand string "Failed" is the value for the entire conditional expression if the condition is false. 









rvalue lvalue:
имена переменных lvalue.
константы rvalue. 
lvalue может использоваться в качестве rvalue, но не наоборот. 
	int  day = 10, a;
	day == 10 ? a = 1 : a = 0 ;	
	printf("%d\n", a);
Так работать не будет, потому что нарушается принцип. ???

Variable names are said to be lvalues (for “left values”) because they can be used on the left side of an assignment operator. 
Constants are said to be rvalues (for “right values”) because they can be used on only the right side of an assignment operator. 
lvalues can also be used as rvalues, but not vice versa.








The while Repetition Statement.

	int stud = 0; //stud = 0  - initialized
	while (stud < 3){
		printf("AAA");
		stud = stud + 1;
		}
	AAA
	AAA
	AAA

	int counter = 0;
	while (++counter <= 2) // 0 + 1 ; 1 <= 2 ; print 1
		printf("%d\n", counter);
	printf("%d\n", counter);
	1
	2
	3

	int counter = 0;
	while (counter++ <= 2)	// 0 <= 2 ; 0+1 ; print 1
		printf("%d\n", counter);
	printf("%d\n", counter);	
	1
	2
	3
	4









The for Repetition Statement.

	for ( expression1; expression2; expression3 )//header. 
	{
		statement
	}
In most cases, the for statement can be represented with an equivalent while statement as follows:

	expression1;
	while ( expression2 ) 
	{
		statement
		expression3;
	}

	int main (void)
	{
		int i;
		for (i = 0; i <= 2; ++i){//постинкремент выглядит естественнее, но прединкремент здесь эквивалентен и выполняется быстрее.
			printf("%d\n", i );
		}
		return 0;
	}


В стандарте С99 добавили возможность объявления и инициализации переменной внутри цикла for. 
Тогда i будет экранирована от i в main.
	Смотри раздел про классы памяти и 
	{
		и области действия.
	}









Switch, a multiple-selection statement (с множественным выбором).
Работает только с константами.

The switch statement consists of a series of case labels, an optional default case and statements to execute for each case. 
	
	#include <stdio.h>
	int main (void)
	{
		int x;
		while ( ( x = getchar() ) != EOF ) //считывает введенный символ; enter = 10;
		{
			//scanf ("%d", &pas);
			//switch (pas)	
			switch (x)	//Keyword switch is followed by the variable name grade in parentheses. This is called the controlling expression. 
						//The value of this expression is compared with each of the case labels (метками каждого кейса). 
			{
				case 'A' : case 'a' : //A character constant can be represented as the specific character in single quotes ' '.
					printf("this is A or a \n");
					break;

				case 66 : 
					printf("this is B \n");
					break;

				case '\n' : case ' ' : case '\t': // игнор символа переноса, пробела и табов, если работа с символами.
					break;

				default : // все остальные случаи.
					printf("this is other \n");
					break;
			}
		}
		printf("\n End");
		return 0;
	}	

При отсутсвии brake будет выполнять все следующие операторы до brake или до конца. 
case '\n' : case 10 - будет ошибка duplicate case value.
Не путай dec с hex. По-умолчанию, все цифры - это dec!









Do While

	int main (void){
		int counter = 1;
		do {
			printf("%d\n", counter);
		}	while ( ++counter <= 10);
		return 0;
	}









Break Continue

The break statement, when executed in a while, for, do…while or switch statement, causes an immediate exit from that statement. 
The continue statement, when executed in a while, for or do…while statement, skips the remaining statements in the body of that control statement and performs the next iteration of the loop. 

	int main (void){
		int  x;
		for (x = 1; x <= 10; x++){
			if(x == 5)
				break; // break досрочно выводит из цикла, есть и другие структурные способы это сделать.
			printf("%d ", x );
		}
		printf("End %d\n", x);
		return 0;
	}

	int main (void){
		int  x;
		for (x = 1; x <= 10; x++){
			if(x == 5)
				continue; // continue пропускает оставшийся код, переходит к следующей итерации.
			printf("%d ", x );
		}
		printf("End %d\n", x);
		return 0;
	}



















Logical Operators.

In expressions using operator &&, make the condition that’s most likely to be false the leftmost condition. 
In expressions using operator ||, make the condition that’s most likely to be true the leftmost condition. 
This can reduce a program’s execution time.
 
	int main (void){
		int  a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if ( a == 2 )	
			printf("%d==2\n", a);

		if ( !(a == 2) )	
			printf("!(%d==2)\n", a);
		
		if ( b == 1 && c >= 10)//Слева от && стараться ставить более вероятное условие, чтобы раньше перестать считать. 
			//The equality operators have a lower level of precedence than the relational operators and they also associate left to right
			printf("%d == 1 && %d >= 10", b, c);
		return 0;
	}









Булева алгебра. 
Короче, вся эта муть дальше, потому что Петцольд не объяснил, что множества и логические высказывания - это две разных вещи. Факт принадлежности кошки к множеству Рыжих - это логическое высказывание, которое может быть истинным или ложным!!! На матпрофи - сначала идут множества, чтобы описать что это такое, а уже ПОТОМ идет логика.

	Рациональное мышление происходит по законам логики. Если описать эти законы средствами математики - то получится описание мышления. 
	Для обозначения чисел используются операнды (буквы). Для указания способа объединения чисел используются операторы, например, + или х.

	В обычной алгебре:
	Операции сложения и умножения коммутативны, их операнды можно поменять местами, а результат не изменится (вычитание и деление некоммутативны):
	A + B = B + A
	A x B = B x A
	Сложение и умножение ассоциативны:
	(A + B) + C = A + (B + C) 
	A х (B x C) = (A x B) x C
	Умножение дистрибутивно относительно сложения:
	A х (B + C) = (A x B) + (A x C)
	От себя добавлю:
	А + (В х С) = А + (В х С)

	Особенность обычной алгебры в том, что она всегда работает с числами: количествами, весами, расстояниями, возрастами и пр. Понадобился гений Буля, чтобы
	сделать алгебру более абстрактной, отделив ее от концепции числа. В булевой алгебре операнды обозначают не числа, а множества, т. е. наборы чего угодно. 
	Кошки: М-коты, Ж-кошки, Ч-черный цвет, Б-белый цвет, Р-рыжий цвет, С - стерильная/ый, Н - нестерильная/ый.

	union - объединение двух множеств.
	Множество Ч + Б = состоит из всех черных и белых котов и кошек.
	intersection - пересечение двух множеств.
	Множество Р х Ж = состоит из рыжих кошек женского пола.

	Коммутативный, ассоциативный и дистрибутивный законы действуют и в булевой алгебре. 
	Сложение дистрибутивно относительно умножения. 
	В обычной алгебре такое выражение несправедливо, а в булевой можно:
	Б + (Ч х Ж) = (Б + Ч) х (Б + Ж)
	От себя добавлю, забегая вперед. 
	В булевой алгебре и сложение дистрибутивно относительно умножения, и умножение дистрибутивно относительно сложения:
	Б х (Ч + Ж) = (Б х Ч) + (Б х Ж) = 0 + Б х Ж
	Б х (Ч + Ж) = ( Ч х М + все цвета х Ж ) х Б = 0 + все цвета х Ж х Б = 0 + Ж х Б

	Объединение белых кошек с черными кошками женского пола
		(это белые коты, белые кошки, черные кошки) 
	содержит те же элементы, что и пересечение двух объединений:
	белых кошек с черными и белых — с кошками женского пола
		(это белые коты, белые кошки плюс черные коты, черные кошки 
		пересекаются с 
		белые коты, белые кошки плюс черные кошки, белые кошки). 
	Белые коты и белые кошки есть и там и там, но нет общих черных котов. 
	В итоге белые коты, белые кошки, черные кошки.

	Символ 1 - это все кошки:
	М + Ж = 1 - все кошки.
	Р + Ч + Б + Д = 1 - все кошки.
	С + Н = 1 - все кошки.
	1 – М = Ж все кошки, кроме М.

	Пустое множество получается в результате пересечения неперекрывающихся множеств,
	например, множеств кошек женского и мужского пола:
	Ж х М = 0

	1 х Ж = Ж - пересечение всех кошек с кошками женского пола есть множество кошек женского пола.
	0 x Ж = 0 - пересечение пустого множества с множеством есть пустое множество.
	0 + Ж = Ж - объединение пустого множества с множеством кошек женского пола есть множество кошек женского пола.
	1 + Ж = 1 - все кошки и женские кошки есть все кошки.

	Ж + (1 – Ж) = 1 - женские кошки и все кошки без женских есть все кошки.

	Ж х (1 – Ж) = 0 - это выражение сыграло важную роль в истории алгебры логики,
	поэтому у него есть собственное название — закон противоречия.
	Он гласит, что ничто не может быть одновременно собой и своей противоположностью.

	Ж х Ж = Ж - пересечение множества кошек женского пола с самим собой равно тому же самому множеству. 
	Ж + Ж = Ж - объединение множества кошек женского пола с самим собой равно тому же самому множеству.

	Все люди смертны;
	Сократ — человек.

	Обозначим буквой Л множество всех людей, буквой Х — множество смертных существ, а буквой К — множество Сократов. 
	Высказывание «Все люди смертны» означает, что пересечение множества людей со множеством смертных существ равно множеству людей:
	Л х Х = Л
	А вот выражение Л х Х = Х было бы неверным, поскольку в множество смертных существ помимо людей входят кошки, собаки и даже пальмы. 

	Высказывание «Сократ — человек» можно передать следующим образом: пересечение множества Сократов (в нем элементов не так много) 
	со множеством людей (в нем элементов гораздо больше) равно множеству Сократов:
	К х Л = К

	Из первого выражения мы знаем, что множество Л равно Л х Х. Подставим это во второе выражение:
	К х (Л х Х) = К
	Используя ассоциативный закон, переписываем это в виде:
	(К х Л) х Х = К

	Но, как мы знаем, пересечение К х Л равно К, а значит:
	К х Х = К
	Эта формула говорит о том, что пересечение множества Сократов со множеством смертных существ равно множеству Сократов, 
	а это как раз и означает, что Сократ смертен.
	Равенство этого же выражения нулю означало бы, что Сократ не является смертным. 
	Если бы мы нашли, что пересечение К х Х равно Х, 
	то пришли бы к выводу, что Сократ — единственное смертное существо, а все остальные существа бессмертны! 

	«Мне нужна кошка мужского пола, стерилизованная, белая или рыжая; 
	или кошка женского пола, стерилизованная, любого цвета, кроме белого; 
	или любая кошка черного окраса» - это кошка из множества, описываемого выражением:
	(М х С х (Б + Р)) + (Ж х С х (1 – Б)) + Ч

	Формируя объединение двух множеств, вы в действительности выбираете элементы из одного множества ИЛИ из другого множества. 
	В пересечение вы включаете только элементы, входящие в первое множество И во второе множество. 
	Кроме того, вместо единицы со знаком «минус» можно использовать оператор НЕ (NOT). 
	Итак:
		вместо оператора объединения + пишем ИЛИ;
		вместо оператора пересечения х пишем И;
	 	вместо 1– (все за исключением чего-то) пишем НЕ.
	(М И С И (Б ИЛИ Р)) ИЛИ (Ж И С И (НЕ Б)) ИЛИ Ч

	В другой форме булевой алгебры буквы уже не обозначают множеств, и им теперь можно присваивать численные значения. 
	Фокус в том, что выбор допустимых значений очень ограничен: 0 или 1. 
	1 означает «истина»:
	да, эта кошка удовлетворяет данному условию. 
	0 означает
	«ложь»: нет, эта кошка не удовлетворяет данному условию.

	Подставим нестерильного рыжего кота НРМ:
	(М И С И (Б ИЛИ Р)) ИЛИ (Ж И С И (НЕ Б)) ИЛИ Ч
	(1 х 0 х (0  +  1))  +  (0 х 0 х (1 -0))  х  0 = 0

	Правила:
	0 х 0 = 0 ; 0 + 0 = 0
	0 х 1 = 0 ; 0 + 1 = 1
	1 х 0 = 0 ; 1 + 0 = 1
	1 х 1 = 1 ; 1 + 1 = 1










Задание 4.14. Факториал интеративный.

	int main (void){
		int x,i;
		scanf ("%d", &x);
		i = 1;
		while (x > 1){
			i *= x;
			--x;
		}
		printf("%d\n", i );
		return 0;
	}


	mov 5, r0
	call fact
	stop

	fact:
	push r1; бекап регистра r1

	mov 1, r1 ; понеслась

	a:
	mul r0, r1 ; 5 * 1 = 5 , поместить в r1
	sub 1, r0 ;  5 - 1 = 4 , поместить в r0
	jnz a

	mov r1, r0

	pop r1 ; применение бэкапа
	ret









Побитовые операции.

	PORTX |= (1 << 2);
	PORTX = PORTX | (1 << 2);

	PORTX &= ~(1 << 2);
	PORTX = PORTX & ~(1 << 2);

	| - побитовое ИЛИ;
		PORTX =  PORTX | 4; устанавливает 2-й бит числа PORTX в единицу;
		остальные биты не трогаются.

	& - И;
		PORTX & 4 "извлекает" 2-й бит из числа:
		PORTX & 4 == 0 когда 2-й бит равен 0; 
		PORTX & 4 != 0 когда 2-й бит равен 1;
		остальные биты обнуляются.

	<< - побитовый сдвиг, сдвигает биты на 2 влево у числа 1; 
		(1 << 2) == 4;
		0000 0001
		0000 0100
		PORTX | 0000 0100.

	~ - побитовое НЕ,  инвертирует биты.




















Functions.


The general format for a function definition is
	return-value-type function-name( parameter-list )//header.
	{
		definitions
		statements
	}
	
	тип_возвращаемых_значений ИМЯ_функции (тип_принимаемых_значений/список_параметров)
	float FUNC(int, double);		//прототип; лучше float FUNC(int x, double y);		
	float FUNC(int x, double y) {}	//тело функции

All variables defined in function definitions are local variables — they can be accessed only in the function in which they’re defined.
The definitions and statements within braces form the function body, which is also referred (называться, упоминаются, передается) to as a block. 
Variables can be declared in any block, and blocks can be nested. 
All variables defined in function definitions are local variables. They can be accessed only in the function in which they’re defined.

Прототип заставляет компилятор преобразовывать тип данных (int>float, etc). Если прототип не указать - компилятор сам создаст кое-как прототип. Function sqrt can be called with an int argument even though the function prototype in <math.h> specifies a double parameter, and the function will still work correctly. 

Each time a function calls another function, an entry is pushed onto the stack. This entry, called a stack frame, contains the return address that the called function needs in order to return to the calling function. Most functions have automatic variables. When a called function returns to its caller, the called function’s automatic variables need to “go away.” When that function returns—and no longer needs its local automatic variables — its stack frame is popped from the stack, and those local automatic variables are no longer known to the program.


	float FUNC(int);
	int main (void){
		printf("%.3f", FUNC(3));
		return 0;
	}
	float FUNC(int x){
		float tmp = x / 2.0 ;
		return tmp;
	}


	void funk (void);
	int main (void){
		funk();	// если void - то в скобках должно быть пусто.
		return 0;
	}
	void funk(void){
		printf("HELLO\n");
		return;	// return здесь можно не писать .
	}


	int AAA(int);
	int BBB(int);

	int main (void){
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









Заголовочные файлы .h

Каждая библиотека имеет свой заголовочный файл, содержащий прототипы для всех функций данной библиотеки, а также определение типов данных и констант для этих функций.	
Можно создавать собственные заголовочные файлы. Подробнее в главе 13.
#include "square.h" - файл лежит в рабочей директории.

Директивы сообщают препроцессору о необходимости включения заголовочных файлов, 
	которые содержат много всего, в том числе - прототипы функций.

#include <stdio.h> printf(), scanf(), NULL, sizeof(type or name)
#include <stdlib.h> system(), rand()
#include <math.h> 
#include <conio.h> getchar()
#include <time.h> time(NULL)
#include <unistd.h> sleep()
#include <stddef.h> NULL








Passing Arguments By Value (значению) and By Reference (ссылке).	("вызов функций", лооол; "когда аргумент исполь в вызове по значению", when arguments are passed by value лооол).

In many programming languages, there are two ways to pass arguments—pass-by-value and pass-by-reference. 
When arguments are passed by value, a copy of the argument’s value is made and passed to the called function. Changes to the copy do not affect an original variable’s value in the caller. When an argument is passed by reference, the caller allows the called function to modify the original variable’s value.
In C, all arguments are passed by value. As we’ll see in Chapter 7, it’s possible to simulate pass-by-reference by using the address operator and the indirection operator. In Chapter 6, we’ll see that array arguments are automatically passed by reference for performance reasons.







An enumeration, introduced by the keyword enum, is a set of integer constants represented by identifiers. Enumeration constants are sometimes called symbolic constants. Values in an enum start with 0 and are incremented by 1. The constant CONTINUE has the value 0, WON has the value 1 and LOST has the value 2. It’s also possible to assign an integer value to each identifier in an enum (see Chapter 10; WON = 34,). The identifiers in an enumeration must be unique, but the values may be duplicated.	

	#include <stdio.h>
	enum Status { CONTINUE, WON, LOST };//a programmer-defined type called an enumeration. 
	int main (void)
	{
		enum Status gameStatus; // Variable gameStatus, defined to be of a new type — enum Status — stores the current status. 
		printf("%d\n", CONTINUE );//0
		printf("%d\n", WON );//1
		printf("%d\n", LOST );//2
		printf("%d\n", gameStatus );//
		
		gameStatus = WON; 
		printf("%d\n", gameStatus );//1
	}



















Storage Classes.


We used identifiers for variable names. 
The attributes of variables include: 

	1. Name. 

	2. Type. 

	3. Size (data type sizes). 

	4. Value. 

We also use identifiers as names for user-defined functions. 
Actually, each identifier in a program has other attributes: 

	5. Storage class.
		C provides the storage class specifiers: 

			auto, 
			register (archaic), 
			static, 
			extern,
			_Thread_local.
		
		An identifier’s storage class determines: storage duration, scope, linkage.

	6. Storage duration. 
		The storage-class specifiers can be split automatic storage duration and static storage duration. 
		
		Automatic storage duration: 

			auto (variables with automatic storage duration are created when the block in which they’re defined is entered; they exist while the block is active, and they’re  destroyed when the block is exited),
			register. 
		
		Static storage duration: 

			static (for static variables, storage is allocated and initialized only once, before the program begins execution. For functions, the name of the function exists when the program begins execution),
			extern (global variables and function names are of storage class extern by default. Global variables are created by placing variable declarations outside any function definition, and they retain their values throughout the execution of the program).	
	
	7. Scope.
		The four identifier scopes:

			function (labels (identifiers followed by a colon such as start:) are the only identifiers with function scope. Labels can be used anywhere in the function in which they appear, but cannot be referenced (не доступны для обращения, не могут передаваться, не могут быть сосланы) outside the function body. Labels are used in switch statements (as case labels) and in goto statements (see Chapter 14)),

			file (an identifier declared outside any function, gloobal variables, function definitions, and function prototypes), 

			block {} (local variables defined at the beginning of a function, function parameters, which are considered local variables by the function), 

			function-prototype (int funk(int) - причем, прототипы требуют только типы идентификаторов, имена им не нужны), 
		
	
	8. Linkage. 


Локальная переменная	- объявлена в списке параметров, теле функции или блоке.
Глобальная переменная	- объявлена вне любого блока или вне функции.
Если своими словами:
	Дурацкое описание в принципе.
	Период хранения и область действия - разные вещи.
	Атрибуты по-разному переплетаются в зависимости от ключевых слов и местоположения. 
	Глобальная переменная X будет "скрыта" для функции, если в функции будет объявлена переменная X.
	Локальные скрываются аналогично:
	int main (void){
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
	int main (void){
		int i = 10;
		for(i = 0; i <=2; i++ ){		//i доступна для блока for.
			printf("%d\n", i);			//0	1	2
		}
		printf("%d\n", i);				//3
		return 0;
	}

	int main (void){
		int i = 10;
		for(int i = 0, i <=2, i++ ){	//i из main скрывается для блока с for.
			printf("%d\n", i);			//0	1	2
		}
		printf("%d\n", i);				//10
		return 0;
	}

	int main (void){
		int i = 10;
		for(; i <=2; i++)				//можно и так.
			printf("%d\n", i);
		return 0;
	}

















Пример с демонстрацией scope.

	// Fig. 5.16: fig05_16.c
	// Scoping.
	void useLocal( void ); // function prototype
	void useStaticLocal( void ); // function prototype
	void useGlobal( void ); // function prototype

	int x = 1;

	// function main begins program execution
	int main ( void )
	{
		int x = 5; // local variable to main
		printf("local x in outer scope of main is %d\n", x ); 

		{ // start new scope
			int x = 7; // local variable to new scope
			printf( "local x in inner scope of main is %d\n", x );
		} // end new scope 

		printf( "local x in outer scope of main is %d\n", x );

		useLocal(); // useLocal has automatic local x 
		useStaticLocal(); // useStaticLocal has static local x 
		useGlobal(); // useGlobal uses global x

		useLocal(); // useLocal reinitializes automatic local x
		useStaticLocal(); // static local x retains its prior value
		useGlobal(); // global x also retains its value

		printf( "\nlocal x in main is %d\n", x );
	} 

	// useLocal reinitializes local variable x during each call
	void useLocal( void )
	{
		int x = 25;
		printf( "\nlocal x in useLocal is %d after entering useLocal\n", x );
		++x;
		printf( "local x in useLocal is %d before exiting useLocal\n", x );
	} 

	// useStaticLocal initializes static local variable x only the first time
	// the function is called; value of x is saved between calls to this
	// function
	void useStaticLocal( void )
	{
		static int x = 50;//то есть суть в том, что эта инструкция выполняется только один раз при запуске
		printf( "\nlocal static x is %d on entering useStaticLocal\n", x );
		++x;
		printf( "local static x is %d on exiting useStaticLocal\n", x );
	} 

	// function useGlobal modifies global variable x during each call
	void useGlobal( void )
	{
		printf( "\nglobal x is %d on entering useGlobal\n", x );
		x *= 10;
		printf( "global x is %d on exiting useGlobal\n", x );
	} 

	local x in outer scope of main is 5
	local x in inner scope of main is 7
	local x in outer scope of main is 5

	local x in useLocal is 25 after entering useLocal
	local x in useLocal is 26 before exiting useLocal

	local static x is 50 on entering useStaticLocal
	local static x is 51 on exiting useStaticLocal

	global x is 1 on entering useGlobal
	global x is 10 on exiting useGlobal

	local x in useLocal is 25 after entering useLocal
	local x in useLocal is 26 before exiting useLocal

	local static x is 51 on entering useStaticLocal
	local static x is 52 on exiting useStaticLocal

	global x is 10 on entering useGlobal
	global x is 100 on exiting useGlobal

	local x in main is 5










Стохастическая игра

	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>

	int main (void){
		int x, y, z=0, sum;
		srand( time(NULL) );
		x = rand () % 6 +1;
		y = rand () % 6 +1;
		sum = x + y;	

		switch (sum){
			case 7 : case 11 :
				printf("x=%d y=%d\n", x, y);
				puts ("Win: 7 or 11");
				break;
			case 2 : case 3 : case 12 : 
				printf("x=%d y=%d\n", x, y);
				puts ("Lose: 2, 3 or 12");
				break;

			default : // 4,5,6,8,9,10
				printf("x=%d y=%d\n", x, y);
				puts("First lose! Again!");
				getchar();

				while (z==0){
					x = rand () % 6 +1;
					y = rand () % 6 +1;
					if (x + y == sum){ //if x + y == 4,5,6,8,9,10
						printf("x=%d y=%d\n", x, y);
						puts ("Win: x+y=first sum");
						z=1;
					}
					if (x + y == 7){
						printf("x=%d y=%d\n", x, y);
						puts ("Lose: 7");
						z=1;
					}	
					else{//удобно отсутствием условий
						printf("x=%d y=%d\n", x, y);
						puts ("Again: x+y!=first sum");
						getchar();
						//z=0;
					}
				}
				break;
		}
		return 0;
	}











Рекурсия.

Всё, что можно написать рекурсией - можно написать и итерацией. 
Нужно выбирать подход в зависимости от обстоятельств. Рекурсия требует больше ресурсов. 

Факториал рекурсивный.

	int FUNC(int);

	int main (void){
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


Или рекурсивная функция
	int fact(int x) {
	    return x<2?1:x*fact(x-1);
	}




	int FUNC(int);

	int main (void)
	{
		int number = 10;
		FUNC(number);
				
	}

	int FUNC(int x)
	{
		printf ("%d\n", x);//получен х
		if(x <= 1)
		{
			return 1;
		}
		else
		{
			return( FUNC(x-1) );//вычесть 1 из х и передать его в функцию
		}	
	}



















Вывод с задержкой в секунду.
	#include <stdio.h>
	#include <stdlib.h> 
	#include <unistd.h> 
	int main (void){

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

	или так
	int main (void){

		for(int i=0; i != EOF; ){
			system("cls");
			for(int i=0; i<4; i++)
				printf("1111\n");
			sleep(1);
			
			system("cls");
			for(int i=0; i<4; i++)
				printf("0000\n");
			sleep(1);
			
		}
	}



Секундомер

	#include <stdio.h>
	#include <time.h>


	int main (void)
	{
		int i = 0;
		while ( i != EOF)
		{
			if (i != time(NULL) )
			{
				i = time(NULL);	
				printf ("%d\n", i);
			}
		}
		
	}




Перевод в двоичную систему.

	#include <stdio.h>
	#include <math.h>
	#include <stdlib.h>
	void FUNC (int);
	int main (void){
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





putchar.

	#include <stdio.h>
	int main (void){    
		int s = 90; 
		putchar (s);
		putchar (90);
		putchar ('\n');
		putchar ('Z');
		return 0;
	}





getchar и putchar.

	#include <stdio.h>
	int main (void){
		int c;
		while ( ( c = getchar() ) != 113 )
			printf("%d\n", c);
			putchar (c);
	}

	int main (void){
		char enter;
		scanf ("%d", &enter);
		printf("%c , code=%d\n", enter, enter);// берет целое, приравнивает к переменной char, выводит как символ или целое. 
		return 0;
	}


	int main (void){
		int c;

		while ( ( c = getchar() ) != 113 ){
			printf("=%d\n", c);
			putchar (c);
			putchar ('\n'); //по второму кругу забавно выводит пустую строку как символ новой строки 10
		}
	}

	int main (void){
		int c;
		
		while ( ( c = getchar() ) != 113 ){
			printf("%d\n", c);
		}
		putchar (c); //забавно, что тут путчар выведет в случае q только q
	}








	
	#include <stdio.h>	

	int integerPower (int a, int b );
	int numberOfDigits (int number);

	int main (void)
	{
		int a = 23562;
		int f;
		int i = integerPower ( 10, numberOfDigits(a) - 1 ) ;
		
		while (i > 0)
		{
			// f = a - a % i;
			// printf ("%2d", f/i);
			// a = a - f;
			// i/=10;
			
			printf ("%2d", (a - a % i) /i);//2 3 5 6 2
			a = a - (a - a % i);
			i/=10;
		}
	}


	int numberOfDigits (int number)
	{
		int step = 1;
		int digit = 0;
		while ( (number % step) != number  )
			{
				step*=10;
				++digit;
			}
		return digit;
	}


	int integerPower (int a, int b )//a^b
		{
			int z = a;
			while ( b != 1 )
			{
				z *= a;
				--b; 
			}
			return z;
		}



















#define preprocessor directive
	Умеют много чего, не путать с функцией, это именно символьная замена, с которой работает препроцессор.
	#include <stdio.h>
	#define SIZE 10// symbolic constant SIZE
	#define MASK(x) x&0xFF
	int main (void){
		printf("%d\n", SIZE);//равносильно написанию:
		printf("%d\n", 10);	
		printf("%d\n", MASK(4095)	);//равносильно написанию:
		printf("%d\n", 4095 & 0xFF	);
		return 0;
	}
	4095	1111 1111 1111
	0xFF	0000 1111 1111
	AND=	0000 1111 1111

0x1234 - шестнадцатиричная. 4095 - десятичная.

















Arrays.
(кратко - одномерные, передача одномерного, многомерные, передача многомерного и передача одной строки многомерного, переменные и передача переменных)

Arrays are data structures consisting of related (связанных) data items of the same (одного) type. In Chapter 10, we discuss C’s notion of struct (structure) — a data structure consisting of related data items of possibly different types.
Arrays and structures are “static” entities (remain the same size throughout program execution). They may be of automatic storage class.
size_t - an unsigned integral type <stddef.h>.


	int MAS[3] = {0};//массив с 3 ячейками типа int с нулями. 
	Номера ячеек: 0, 1, 2.
	{0} поместит нули во все ячейки.
	{1} поместит единицу только в нулевую ячейку, а в остальные - нули.

	int MAS[3] = {1, 2, 3};//Можно перечислять переменные по отдельности
	int MAS[] = {1, 2, 3};//Можно перечислять переменные по отдельности и размер будет указан автоматически
	int MAS[3];//Будут заняты 3 ячейки, в них будет мусор.
	//Число перечисленных членов не должно превышать размер массива [], если записать его вручную. Программа может выйти за пределы массива, этого нельзя допускать.
	
	MAS[i] = 2;//i subscript - индекс; a subscripted array name is an lvalue — it can be used on the left side of an assignment.

	printf ("%s\n", "Hello" );//раньше было так; a string with printf.




ВАЖНЫЙ МОМЕНТ - printf ожидает работать просто с числами! Как вариант, в параметрах написано (int a). Поэтому здесь можно передавать все, что угодно. Адрес будет распознаваться просто как число. А вот в функцию, ождающую массив или переменную, так передавать нельзя!!! И об этом не было написано (стр 233)! Scanf работает с цифрами, как с адресами, поэтому ей тоже безразличен способ получения числа.

printf не волнует способ передачи. Она рассматривает всех как просто числа.
	printf("%d\n", MAS);// The name of the array evaluates to the address of the first element of the array. Можно перевести в шестнадцатиричную систему %p conversion specifier - printf("%p\n", MAS);.
	printf("%p\n", MAS );//0028FF34
	printf("%d\n", &MAS);//аналогично выше написанному. 
	printf("%p\n", &MAS );//0028FF34
	printf("%d\n", &MAS[0]);//аналогично выше написанному. 
	printf("%p\n", &MAS[0] );//0028FF34
	printf("%d\n", &MAS[1]);//следующий адрес после адреса MAS[0]. 
	printf("%p\n", &MAS[1] );//0028FF38
	printf("%p\n", &MAS[i] );

	printf("%d\n", MAS[i]);//это уже конкретный член массива, и работа с ним, как с переменной.
	

scanf не волнует способ передачи. Она рассматривает всех как адреса.
	scanf("%5s", MAS);// & не нужен, см.выше. 5s введет строку не длиннее 5 символов. scanf может выйти за пределы массива.
	scanf("%5s", &MAS);//взять адрес адреса, но это так. В функциях остальных это не работает.
	scanf("%5s", &MAS[0]);//аналогично выше сказанному. MAS - это адрес первого элемента, но MAS[i] - это элемент! Так же, как a - это переменная, но &a - это адрес переменной. Не путать высокий язык с асмом. 
	scanf("%c" , &MAS[i]);//Алярам, %c будет распозновать ввод как символ конца строки!
	scanf("%d" , MAS[0]);//Запишет полученное значение по адресу равному значению ячейки номер MAS[0]!
	
	


	char MAS [] = "first";//cимвольный массив инициированный строковым литералом. The string "first" contains 5 characters plus a special string-termination character called the null character '\0'. 
	char MAS [] = { 'f', 'i', 'r', 's', 't', '\0' };//эквивалентно предыдущему.
	for (int i = 0; MAS[i] != '\0' ; ++i)
	{
		printf("%c\n", MAS[i]);//вывести значение ячейки MAS[i].
	}

Работа с остальными функциями ниже! И она отличается.



	
	




Static Local Arrays and Automatic Local Arrays.
	
static int A[3]; - массив не будет всякий раз создаваться при вызове функции и уничтожаться после выхода из неё. Все тоже самое, что и с static переменными в примере про scope. Только еще static array автоматически инициализируются нулями, если не указано иное.
	
	#include <stdio.h>

	void A (void);
	void S (void);

	int main (void)
	{
		printf("first\n");	
		A();
		S();
		
		printf("second\n");
		A();
		S();
		return 0;
	}
	void A (void)
	{
		int a[] = {1,2,3};

		printf("A\n");
		for (int i = 0; i < 3; ++i)
			printf("i=%d____p=%p____%d\n", i, &a[i], a[i] );
		
		printf("A+5\n");
		for (int i = 0; i < 3; ++i)
			printf("i=%d____p=%p____%d\n", i, &a[i], a[i]+=5);
	}
	void S(void)
	{
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









Passing Arrays to Functions.	

Recall that all arguments in C are passed by value. 

C automatically passes arrays to functions by reference — the called functions can modify the element values in the callers’ original arrays. The name of the array evaluates (соответствует) to the address of the first element of the array. It’s possible to pass an array by value (by using a simple trick we explain in Chapter 10). Си передаёт массив в функцию путём имитации передачи параметра по ссылке, вызываемые функции могут изменять значения элементов массива.

Individual array elements (scalars) are passed by value exactly as simple variables are. In Chapter 7, we show how to pass scalars (i.e., individual variables and array elements) to functions by reference. Отдельные значения (скаляры) передются по значению. Но можно имитировать ссылку для скаляров. Чем имитация отличается от передачи по ссылке - пока хз.


Передача массива и элемента.

	#include <stdio.h>
	#define SIZE 5//нужно для удобной передачи разных массивов в одну и ту же функцию. В параметрах функции объявляют int переменную, которая внутри функции будет служить размером массива. Это позволяет передавать разные массивы с разными размерами одной и той же функции.

	void modifyArray (int b[], int size);//modifyArray expects to receive an array of integers in parameter b and the number of array elements in parameter size.
	//Принимается здесь АДРЕС! Вот size, например, - это передача по значению, то есть создается просто копия.
	//The size of the array is not required between the array brackets. If it’s included, the compiler checks that it’s greater than zero, then ignores it. 
	void modifyElement (int e);
	void printMAS (int b[], int size);

	int main (void)
	{
		int MAS[SIZE] = {0,1,2,3,4};

		printMAS (MAS, SIZE);//   0   1   2   3   4
	!!!	printMAS (&MAS, SIZE);// Ошибка.
		printMAS (&MAS[0], SIZE);//   0   1   2   3   4
		printMAS (&MAS[2], SIZE);//   2   3   4   0   0; printMAS внутри будет "иметь" массив b, который будет начинаться с адреса MAS[2].
	!!!	printMAS (MAS[0], SIZE);// Ошибка, происходит передача значения. А вот одномерный массив (строка) двумерного массива передавался бы именно так!
		


		modifyArray(MAS, SIZE); 
		printMAS (MAS, SIZE);//   0   2   4   6   8
	!!!	modifyArray(&MAS, SIZE);// Ошибка.
	
		modifyArray(&MAS[0], SIZE);
		printMAS (MAS, SIZE);//   0   4   8  12  16
		modifyArray(&MAS[2], SIZE);//modifyArray внутри будет "иметь" массив b, который будет начинаться с адреса MAS[2].
		printMAS (MAS, SIZE);//   0   4  16  24  32


		modifyElement (MAS[4]);//64 ; 
		printMAS (MAS, SIZE);//   0   4  16  24  32

		return 0;
	}

	void modifyArray (int b[], int size)
	{
		for (int i = 0; i < size; i++)
			b[i] *= 2;
	}

	void modifyElement (int e)
	{
		printf("%3d", e*=2 );
		printf("\n");
	}

	void printMAS (int b[], int size)
	{
		for (int i=0; i < size; i++)
		{	
			printf("%3d", b[i]);
		}
		printf("\n");
	}









Сортировка массивов. Пузырьковая сортировка - меньшие значения всплывают вверх.

	#include <stdio.h>
	#define  SIZE 5

	int main (void)
	{
		int hold;
		int M[SIZE] = {0,4,3,2,1};
		for (int i=0; i < SIZE; i++)
			printf("%d\n", M[i]);

		for (int pass = 1; pass < SIZE; pass++ )
		{
			for (int i = 0; i < SIZE-1	; i++)
			{
				if (M[ i ]	> M[ i+1 ])	
				{
					hold	= M[ i ] ;
					M[ i ]	= M[ i+1 ] ;
					M[ i+1 ]= hold ;
				}
			}	
		}
				
		for (int i=0; i < SIZE; i++)
			printf("%d\n", M[i]);
					
		return 0;
	}

Среднее, медиана и наиболее вероятное - стр 270.

Поиск в массивах. Linear Search.

	#include <stdio.h>
	#define SIZE 5

	int findM(int [], int, int);

	int main (void)
	{
		int key;
		int M[SIZE] = {0,1,2,3,4};
		scanf("%d", &key);
		printf("element=%d\n", findM (M, SIZE, key)	);
		return 0;
	}

	int findM (int array[], int size, int key)
	{

		for(int i=0; i <= size - 1; i++)
			if (array[i]==key)
				return i;
			return -1;
	}

Двоичный поиск, стр 245









Multidimensional Arrays.

M[число строк][число столбцов (по сути - длина строки)] 
Значения группирируются в фигурных скобках по строкам.
	int A[2][3] = {	{1,2,3}, 
					{4,5,6};

	int M[2][2] = {	{1,2} , {3,4} };
			0стлбц	1стлбц
		0стрк//1//	//2//
		1стрк//3//	//4//

	int M[2][2] = {	{1} , {3,4} };`
			0стлбц	1стлбц
		0стрк//1//	//0//
		1стрк//3//	//4//

	int M[2][2] = { 1,2,3 };
			0стлбц	1стлбц
		0стрк//1//	//2//
		1стрк//3//	//0//

	int M[][3] = {1,2,3,4,};//число строк = 1 + число элементов % длину строки, но это дичъ; без указания длины вообще работать не будет, что логично.
			0стлбц	1стлбц	2стлбц
		0стрк//1//	//2//	//3//	
		1стрк//4//	//0//	//0//




Вывод многомерного массива и передача в функцию.

В памяти строка идет за строкой. Каждая строка - по сути одномерный массив. When accessing (при обращении) a[1][2] in our example, the compiler knows to skip the 3 elements of the 1 row (row 0) to get to the 2 row (row 1). Then, the compiler accesses element 2 of that row. 

	#include <stdio.h>
	void printM(int [][3]);//первый индекс не требуется и бесполезен, последующие - обязательно требуются, иначе компилятор не будет знать длину строки.
	//в списке параметров функции определяется о чем идет речь - переменной, одномерном массиве или многомерном массиве!

	int main (void)
	{
		int M[2][3] = {0,1,2,3,4};
		printM (M);//передаем адрес первого элемента в функцию, работа с двумерным. 
	!!!	//Иные варианты не работают, потому что в параметрах функции идет речь о двумерном массиве. В примере ниже в параметрах функции речь идет об одномерном массиве.

		return 0;
	}

	void printM (int M[][3])//первый индекс не требуется и бесполезен, последующие - обязательно требуются.
	{	
		for(int i=0; i < 2; i++)//2 число строк.
		{
			for (int j = 0; j < 3; j++)//3 длина строки.
			{
				printf("%d ", M[i][j] );//i номер строки row, j номер столбца column.
			}
			printf("\n");
		}
	}




Передача строки массива как одномерного массива в функцию. Упрощенная версия fig06_22.c . 

	#include <stdio.h>
	#define LONG 4
	#define ROWS 3


	int main (void)
	{
		int M[ROWS][LONG] = {0,1,2,3,4,5,6,7,8,9,10,11};
		for (int i = 0; i < ROWS; ++i)//Проход по каждой строке массива.
		{
			average( M[i], LONG );//Передача одномерного массива (одной строки многомерного), это не значение ячейки в данном случае!
			//This causes (это приводит к тому) the address of one row of the double-subscripted array to be passed to average. The argument M[1] is the starting address of row 1 of the array.
			puts ("");
		}
		average( M[0], LONG );//будет аналогично предыдущему; вызывающая функция ожидает одномерный массив, а не значение.
	!!!	average( M, LONG );// это будет ошибкой, потому что M есть двумерный массив. А функция ожидает одномерный. Несмотря на то, что по логике, M есть адрес первого элемента. 
	!!!	average( &M, LONG );//  это будет ошибка по той же причине, что и выше.
	!!!	average( &M[0], LONG );// и это будет ошибкой!
	}

	void average( int A[], int size )// Принимает одномерные массивы.
	{
		for (int i = 0; i < size; ++i)
		{
			printf ("%3d", A[i] );
		}
		puts ("");
	}	





Variable-Length Arrays
Во всех предыдущих примерах массивы задавались константами (в том числе и через define). А здесь суть в объявлении размера массива уже после запуска программы. Именно для этого в индексах используют переменные, которые можно инициализировать в коде или получить от пользователя.

	#include <stdio.h>
	
	void print1DArray( int size, int array[size] )//сначала объявить size, чтобы можно было его использовать в int array [size]; 
	//void print1DArray( int size, int array[] )//здесь size был бы нужен по привычным причинам удобства;
	{
		for ( int i = 0; i < size; i++ ) 
		{
			printf( "%4d", array[ i ] );
		}
		puts ("");
	}

	void print2DArray( int row, int col, int array[row][col] )//col будет удовлетворять требованию указывать все индексы, кроме первого!
	{
		for ( int i = 0; i < row; ++i ) 
		{
			for ( int j = 0; j < col; ++j ) 
			{
				printf( "%4d", array[ i ][ j ] );
			}
		}
		puts ("");
	}	
	

	int main (void)	
	{
		int x, row1, col1;
		x = 5;
		row1 = 2;
		col1 = 3;

		int d1 [x];//Размер указывает переменная. 
		int d2 [row1][col1];//С многомерными все тоже самое.

		for ( int i = 0; i < x; ++i ) 
		{
			d1[i] = i * i;
		} 

		for ( int i = 0; i < row1; ++i ) 
		{
			for ( int j = 0; j < col1; ++j ) 
			{
				d2[i][j] = i + j;
			}
		}

		print1DArray( x, d1 );//Все передается точно так же, как и во всех предыдущих примерах. Разве что сначала идет переменная, а потом массив.
		//Теперь передача переменных в списке параметров функций необходима, ведь это теперь не заранее известные константы!
		print2DArray( row1, col1, d2 );

	}









Pointers.

Pointers are variables whose values are memory addresses. 
Normally, a variable directly contains a specific value. A pointer, on the other hand, contains an address of a variable that contains a specific value. In this sense, a variable name directly references (непосредственной ссылкой) a value, and a pointer indirectly references (косвенной ссылкой) a value. Referencing a value through (обращение/ссылка к/на значение через) a pointer is called indirection (косвенным доступом).

	int *countPtr; //объявлет переменную, которая является указателем. The asterisk (*) notation used to declare pointer variables.

A pointer may be initialized to NULL, 0 or an address. 
Initializing a pointer to 0 is equivalent to initializing a pointer to NULL, but NULL is preferred. When 0 is assigned, it’s first converted to a pointer of the appropriate (соответствующего) type. The value 0 is the only integer value that can be assigned directly to a pointer variable.

	int y = 5;
	int *yPtr;//definitions that yPtr is the pointer.
	yPtr = &y;//assigns the address of the variable y to pointer variable yPtr. Variable yPtr is then said to “point to” y. The operand of the address operator must be a variable; the address operator cannot be applied to constants or expressions or register.
	printf( "%p \n", yPtr );//0028FF38
	printf( "%p \n", &y );//0028FF38
	printf( "%d \n", *yPtr );//5; The unary * operator, commonly referred (часто называемый?) to as the Indirection Operator (оператор косвенного обращения) or Dereferencing Operator (оператор разыменовывания), returns the value of the object to which its operand (i.e., a pointer) points (объекта, на который его операнд (т.е. указатель) указывает). Using * in this manner is called dereferencing a pointer (разыменованием указателя). 
	printf( "%d \n", y );//5
	printf( "%d \n", y+*yPtr );//10




In C, you use pointers and the indirection operator to simulate pass-by-reference (имитации передачи по ссылке). When calling a function with arguments that should be modified, the addresses of the arguments are passed.

	#include <stdio.h>
	int cubeByValue( int n ); 
	void cubeByReference( int *nPtr );

	int main( void )
	{
		int number;

		number = 5; 
		number = cubeByValue( number );
		printf( "\nThe new value of number is %d\n", number );//125

		number = 5; 
		cubeByReference( &number );//передача адреса.
		printf( "\nThe new value of number is %d\n", number );//125
	}
	
	int cubeByValue( int n )
	{
		return n * n * n;
	}

	void cubeByReference( int *nPtr )//pointer definitions; cubeByReference receives the address of an integer variable as an argument, stores the address locally in nPtr and does not return a value. 
	{
		*nPtr = *nPtr * *nPtr * *nPtr; //разыменовывает указатель; number = number * number * number
	} 




For a function that expects a single-subscripted array as an argument, the function’s prototype and header can use the pointer notation shown in the parameter list of function cubeByReference. The compiler does not differentiate between a function that receives a pointer and one that receives a single-subscripted array. 
This, of course, means that the function must “know” when it’s receiving an array or simply a single variable for which it’s to perform pass-by-reference. When the compiler encounters a function parameter for a single-subscripted array of the form int b[], the compiler converts the parameter to the pointer notation int *b. The two forms are interchangeable.
	
	#include <stdio.h>
	void cubeByReference( int *nPtr );
	void cubeByReference2( int b[] );

	int main()
	{
		int MAS[] = {1,2,3,4,5};
		arrayByReference1 (MAS);
		arrayByReference2 (MAS);
		return 0;
	}
	
	void arrayByReference1( int *nPtr )
	{
		printf ("%d\n", nPtr );//2686764
		printf ("%d\n", *nPtr );//1
		printf ("%d\n", nPtr[3] );//4
		printf ("%d\n", &nPtr[0] );//2686764
	} 

	void cubeByReference2( int b[] )
	{
	} 










Const Qualifier. 

Опечатки: en fig06_16 unsigned const int answer[] , en as const int a[][3] и ru объявляется как const int a[][3] (хотя везде в коде без const, демонстрируются [][size] многомерных массивов) , 

	#include <stdio.h>
	void modA (const int x , const int c[] );
	void modB (int x, int c[] );

	int main()
	{
		int a = 2;
		int MASA [] = {1,2,3};
		
		const int b = 5;//запрет любых изменений, поэтому инициализировать нужно сразу.
	!!!	b = 7;// Ошибка.
		const int MASB [] = {4,5,6};
	!!!	MASB [2] = 33;// Ошибка.

		modA(a, MASA);
	!!!	modB(b, MASB);// Ошибка, требует const int c[]! Ошибка будет даже несмотря на отсутствие модифицирующих его инструкций в функции. 
	}

	void modA (const int x , const int c[])//any attempt to modify an element of the array in the function body results in a compile-time error. 
	{
	!!!	x = 2;// Ошибка.
	!!! c[2]= 99;// Ошибка.
	}

	void modB (int x, int c[] )
	{
		x = 2;//Ошибки нет 
	}









The Const Qualifier with Pointers.
См. Const Qualifier. ранее.
Six possibilities exist for using (or not using) const with function parameters: 2 with pass-by-value parameter passing and 4 with pass-by-reference parameter passing.

Представьте функцию, которая ожидает массив и переменную для его размеры. И эти параметры не должны меняться в функции, даже не смотря на то, что и так передаются по значению. Обе инструкции будут ошибкой.




There are 4 ways to pass a pointer to a function: 

1. a non-constant pointer to non-constant data. 
	
	#include <stdio.h>
	#include <ctype.h>

	void convertToUppercase( char *sPtr );

	int main( void )
	{
		char string1[] = "cHaRaCters and $32.98";//массив можно изменять;
		const char string2[] = "Hello";

		printf("%s \n", string1 );//cHaRaCters and $32.98
		convertToUppercase( string1 );
		printf("%s \n", string1 );//CHARACTERS AND $32.98

	!!!	convertToUppercase( string2 );// Ошибка, требует const char *sPtr ! Ошибка будет даже несмотря на отсутствие модифицирующих его инструкций в функции. 
	}

	void convertToUppercase( char *sPtr )
	{
		while( *sPtr != '\0' )
		{
			*sPtr = toupper( *sPtr );
			++sPtr; // увеличивает значение указателя на 1 длину типа данных; в данном случае на 1 байт.
		} 
	}




2. a non-constant pointer to constant data.
	
	#include <stdio.h>
	#include <ctype.h>

	void printCharacters1( const char *sPtr );
	
	int main( void )
	{
		char string1[] = "print characters of a string";// non-constant массив можно изменять; но в этом примере это constant data почему-то.
		printCharacters1( string1 );
	}

	void printCharacters1( const char *sPtr )// указатель sPtr не может использоваться для изменения символа, на который он указывает, то есть sPtr – указатель "только для чтения"; аналогично свойствам const int b[].
	{	
		!!!	*sPtr = 'L';// Ошибка

		for ( ; *sPtr != '\0'; ++sPtr ) 
		{ 
			printf( "%c", *sPtr );
		} 
		
		char x;
		sPtr += 99;//нет ошибки
		sPtr = &x;//нет ошибки
	}

	


3. a constant pointer to non-constant data. 

		int x = 1;
		int y = 2;
		int *const aPtr = &x;//constant pointer; нельзя менять адрес указателя.
		const int *bPtr = &y;//нельзя менять значение через dereferencing.

		printf ("%d  %d\n", aPtr, *aPtr );//
		printf ("%d  %d\n", bPtr, *bPtr );//

	!!!	aPtr = &y;// Ошибка.
		bPtr = &x;
		
		*aPtr = 5;
	!!!	*bPtr = 7;// Ошибка.




4. a constant pointer to constant data. 

		int n = 5;
		int m;
		const int *const ptr = &n;//константный указатель на целочисленную константу; ptr всегда указывает на один и тот же адрес; целое число по этому адресу не может быть изменено.
		printf( "%d\n", *ptr );
		*ptr = 7; // ошибка: *ptr - константа; нельзя присвоить новое значение
		ptr = &m; // ошибка: ptr - константа; нельзя присвоить новый адрес
	

	

	































Передача параметра по ссылке.

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

int main (void){
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
		int main (void){
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
int main (void){
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
int main (void){
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
int main (void){
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
int main (void){
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
int main (void){
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

int main (void){
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
