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










Введение. Разбито на 7 абзацев.
Наступает великий миг: я утверждаю, что собранное нами устройство может с полным правом именоваться компьютером! Очень примитивным, но компьютером. Его ключевое свойство — наличие команды условного перехода. Именно возможность управляемых циклических процедур отличает компьютер от калькулятора. Петцольд, 281. We use the structured approach (подход) throughout the remainder (на протяжении оставшейся) of the C portion (части) of the text.

1	#include <stdio.h>
Lines beginning with # are processed by the preprocessor before compilation. 
This is a directive to the C preprocessor. It tells the preprocessor to include the contents of the standard input/output header (<stdio.h>) in the program. This header contains information used by the compiler when compiling calls to standard input/output library functions such as printf. We explain the contents of headers in more detail in Chapter 5 and 13.

2	int main (void)//int main () 
	{
		statement;
	}
The parentheses () after main indicate that main is a program building block called a function. C programs contain one or more functions, one of which must be main. The main function is a part of every C program. Every program in C begins executing at the function main. 
A left brace { begins the body of every function. A corresponding right brace } ends each function. This pair of braces and the portion of the program between the braces is called a block. The block is an important program unit in C. 
Functions can return information. The keyword int to the left of main indicates that main “returns” an integer (whole-number) value. We’ll explain what it means for a function to “return a value” when we demonstrate how to create your own functions in Chapter 5. 
Functions can receive information when they’re called upon to execute. The void in parentheses here means that main does not receive any information. In Chapter 14, we’ll show an example of main receiving information. 

3	printf( "Welcome \\ to C!\n" );
An Output Statement instructs the computer to perform an action (namely to print on the screen the string of characters marked by the quotation marks ""). 
A string is sometimes called a character string (символьная строка), a message or a literal. 
The entire line, including the printf function (the “f” stands for “formatted”), its argument within the parentheses () and the semicolon ; , is called a statement (инструкция). Every statement must end with statement terminator a semicolon ; . 
The backslash (\) is called an escape character. Они же esq-коды.
Printf causes the computer to perform an action. 
As any program executes, it performs a variety (множество) of actions and makes decisions. 
Executable statements either perform actions (calculations, input or output of data, etc) or make decisions (if, while, etc) (стр 54). 
The Linker and Executables. Standard library functions like printf and scanf are not part of the C programming language. Сompiler cannot find a spelling error in printf or scanf. When the compiler compiles a printf statement, it merely provides space in the object program for a “call” to the library function (e.g printf). But the compiler does not know where the library functions are — the linker does. When the linker runs, it locates the library functions and inserts the proper calls (соответствующие вызовы) to these library functions in the object program (причем, вставляет он уже обжекнутые куски кода). Now the object program is complete and ready to be executed. For this reason, the linked program is called an executable. If the function name is misspelled, the linker will spot the error, because it will not be able to match the name in the C program with the name of any known function in the libraries.

4	int integer1, integer2;
	int sum; 
This line are definitions (определения). The names integer1, integer2 and sum are the names of variables (переменных). Variables is the locations in memory where values can be stored for use by a program. Variable names such as integer1 and sum actually correspond to locations in the computer’s memory. These definitions specify (указывают) that variables integer1, integer2 and sum are of type int, which means that they’ll hold integer values, i.e., whole numbers such as 7, –11, etc. Every variable has a name, a type and a value. All variables must be defined with a name and a data type before they can be used in a program. 
Definitions are not executable statements—they’re simply messages to the compiler (стр 72). 
For readers using the Microsoft Visual C++ compiler, note that we’re placing our variable definitions immediately after the left brace { that begins the body of main. The C standard allows you to place each variable definition anywhere in main before that variable’s first use in the code. Some compilers, such as GNU gcc, have implemented this capability. We’ll address this issue in more depth in later chapters. Recall that the Microsoft Visual C++ compiler requires variable definitions to be placed after the left brace { of a function and before any executable statements. Therefore, in the program in Fig. 2.5, inserting the definition of integer1 after the first printf would cause a syntax error in Visual C++. 
Вдобавок объявления могут быть внутри выделенных блоков, тогда они будут скрыты от остальных областей, см. области действия (Scope). 
A variable name in C is any valid identifier (идентификатор). An identifier is a series of characters consisting of letters, digits and underscores (_) that does not begin with a digit. C is case sensitive — uppercase and lowercase letters are different in C, so a1 and A1 are different identifiers. The first letter of an identifier used as a simple variable name should be a lowercase letter. Later in the text we’ll assign special significance to identifiers that begin with a capital letter and to identifiers that use all capital letters. 
 
5	scanf("%d", &integer1);
	scanf("%d", &integer2);
This statement uses scanf (the “f” stands for “formatted”) to obtain a value from the user. The function reads from the standard input, which is usually the keyboard. 
This scanf has two arguments: "%d" and &integer1. 
The first, the format control string (строка управляющая форматом) "%d". It indicates the type of data that should be entered by the user. The %d conversion specifier (спецификатор преобразования) indicates that the data should be an integer. The % in this context is treated (рассматривается) by scanf (and printf as we’ll see) as a special character (специальный символ, как esq-код) that begins a conversion specifier. The letter d stands for “decimal integer”. 
The second argument &integer1 of scanf begins with an ampersand & (address operator) followed by the variable name (& (адрес оператор) за которым следует имя переменной). The &, when combined with the variable name integer1, tells scanf the location (or address) in memory at which the variable integer1 is stored. The computer then stores the value that the user enters for integer1 at that location. 
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
	puts( "Welcome to C!" );
	printf( "%s", "Welcome " );//a string with printf.

Теперь в общем.
Когда речь заходит о датасаенс и информатике, о философии, логике и языках высого уровня, то появляются выражения и прочее. В асме нельзя написать х = 2+3-5*6, каждый кусочек нужно описать вручную, выделить место в памяти, назвать это место меткой "х", затем поочередно складывать, затем сохранять результат обратно в память, и так далее. А чтобы придумать С нужно придумать логику, законы и абстракции его мира.

https://en.wikipedia.org/wiki/Expression_(computer_science) :
An expression in a programming language is a combination of one or more constants, variables, operators, and functions that the programming language interprets (according (в соответсвтии с) to its particular rules of precedence (приоритет, приоритетность, старшинство, предшествование) and of association (ассоциативность) ) and computes (вычисляет) to produce (производства) ("to return", in a stateful environment) another value. This process, as for mathematical expressions, is called evaluation.

https://en.wikipedia.org/wiki/Statement_(computer_science) :
In computer programming, a statement is a syntactic unit of an imperative programming language that expresses (выражает) some action to be carried out (которые необходимо выполнить). A program written in such (таком) a language is formed (сформирована чем) by a sequence of one or more statements. A statement may have internal components (e.g. например, expressions). Many imperative languages (e.g. C) make a distinction (делают различие) between statements and definitions, with (причем) a statement only containing executable code and a definition instantiating an identifier (определение, создающее экземпляр идентификатора), while (тогда как) an expression evaluates (оценивается) to a value only. A distinction (различие) can also be made between simple and compound (составная) statements; the latter may contain statements as components. Simple statements: a = a + b; return z; Compound statements: {} блок, if, for. In most languages, statements contrast with expressions, in that statements do not return results and are executed solely for their side effects, while (когда как) expressions always return a result and often do not have side effects at all. This distinction (различие) is frequently observed in wording (в формулировках) : a statement is executed, while an expression is evaluated. In purely (чисто) functional programming, there are no statements; everything is an expression.

C how to program:
Pseudocode consists only of action statements—those that are executed when the program has been converted from pseudocode to C and is run in C. Definitions are not executable statements—they’re simply messages to the compiler. For example, the definition tells the compiler the type of variable i and instructs the compiler to reserve space in memory for the variable. But this definition does not cause any action—such as input, output, a calculation or a comparison—to occur when the program is executed. 

Unknown:
An expression is a sequence of operators. Statements are fragments of the C program that are executed in sequence (в последовательности или последовательно?). The body of any function is a compound statement which in turn is a sequence of statements and declarations (объявлений).

Rules of Operator Precedence. The rules of operator precedence specify the order C uses to evaluate expressions (правила, которые определяют порядок). The associativity of the operators specifies whether (будут ли) they evaluate from left to right or from right to left. The circled numbers indicate the order in which C evaluates the operators: 
	z = p * r % q + w / x - y;
	  6   1   2   4   3   5

	while ( ( grade = getchar() ) != EOF )
In the while header the parenthesized assignment (grade = getchar()) executes first. The getchar function (from <stdio.h>) reads one character from the keyboard and stores that character in the integer variable grade. Assignments as a whole actually have a value (присваивание само по себе имеет значение). This value is assigned to the variable on the left side of the =. The value of the assignment expression grade = getchar() is the character that’s returned by getchar and assigned to the variable grade. То есть речь о том, что выражение присваивания (с простыми выражениями из остальных операторов и так все понятно, что можно) само по себе может использоваться как условие. Это похоже на оценку последней инструкции в регистре состояний. Но касается ли это инструкций здесь?
The fact that assignments have values can be useful for setting several variables to the same value. For example, a = b = c = 0; first evaluates the assignment c = 0 (because the = operator associates from right to left). The variable b is then assigned the value of the assignment (переменной b присваивается значение выражениЯ) c = 0 (which is 0). Then, the variable a is assigned the value of the assignment b = (c = 0) (which is also 0).
Any expression in C that produces a value can be used in the decision portion of any control statement. 
	if ( payCode == 4 )
		printf( "%s", "You get a bonus!" );
	if ( payCode = 4 )//всегда истинно, пока присваивается ненулеваое значение.
 		printf( "%s", "You get a bonus!" );

Order of Evaluation of Operands. Не путать с Order of Evaluation of Operators (или precedence). Выражения состоят из операторов и их операндов. Есть порядок оценки операторов, а есть порядок оценки операндов для операторов &&, ||, the comma (,) operator and ?: . А все это вместе как раз и образует порядок оценки выражений?
Это из рекурсивного способа решения чисел Фибоначчи. 
	unsigned long long int fibonacci( unsigned int n )
	{
		if ( 0 == n || 1 == n ) return n;
		else return fibonacci( n - 1 ) + fibonacci( n - 2 );
	} 
This figure raises some interesting issues about the order in which C compilers will evaluate the operands of operators. This is a different issue from the order in which operators are applied to their operands, namely the order dictated by the rules of operator precedence (Это отличается от проблемы порядка, в которой операторы применяются к своим операндам, а именно порядка, определяемого правилами приоритета операторов)! 
Figure 5.20 shows that while evaluating fibonacci(3), two recursive calls will be made, namely fibonacci(2) and fibonacci(1). But in what order will these calls be made? You might simply assume the operands will be evaluated left to right. For optimization reasons, C does not specify the order in which the operands of most operators (C не определяет порядок, в каком будут вычисляться операнды большинства операторов) (including +) are to be evaluated. Therefore, you should make no assumption about the order in which these calls will execute. The calls could in fact execute fibonacci(2) first and then fibonacci(1), or the calls could execute in the reverse order, fibonacci(1) then fibonacci(2).
In this and most other programs, the final result would be the same. But in some programs the evaluation of an operand may have side effects that could affect the final result of the expression. C specifies the order of evaluation of the operands of only four operators— namely &&, ||, the comma (,) operator and ?:. The first three of these are binary operators whose operands are guaranteed to be evaluated left to right. Именно поэтому лучше наиболее вероятную истину ставить слева от ||, а наиболее вероятную ложь слева от &&, с запятой и тренарным смотри примеры ниже. [Note: The commas used to separate the arguments in a function call are not comma operators.] The last operator is C’s only ternary operator. Its leftmost operand is always evaluated first; if the leftmost operand evaluates to nonzero, the middle operand is evaluated next and the last operand is ignored; if the leftmost operand evaluates to zero, the third operand is evaluated next and the middle operand is ignored.

Operator precedence and associativity.
Operators								Associativity	Type			//My comment
() () []								left to right	parentheses		//() Operators in expressions contained within pairs of parentheses are evaluated first; func() function call operator; [] brackets(square brackets) used to enclose (заключить) the subscript (индекс) of an array.
++(postfix) --(postfix)					right to left					//type длинный: postfix, unary, highest; на стр 281 имеют одинаковую приоритетность со строчкой выше, так же не понятно,почему постфикс имеет приоритет выше префикса.
+ - ! ++ -- (type) & * sizeof			right to left	unary			//унарные версии (+5,-7), !(grade != sum), ++a, --b, cast operator a(float),  address operator, indirection Operator.
* / %									left to right	multiplicative	//binary
+ -										left to right	additive		//binary
< <= > >=								left to right	relational
== !=									left to right	equality		//The equality operators have a lower level of precedence than the relational operators and they also associate left to right (см ниже, в if и в Logical Operators).
&&										left to right	logical AND		//binary
||										left to right	logical OR		//binary
?:										right to left	conditional		//ternary
= += -= *= /= %=						right to left	assignment		//binary
,										left to right	comma			//см 12: .

https://en.wikipedia.org/wiki/Order_of_operations
https://en.wikipedia.org/wiki/Operator_associativity

(стр 52, 136, 218, 281) Понятнее было бы associativity and operator precedence/order of operations (operator precedence понятнее звучит), потому что сначала нужно разобраться почему 7-4 + 2 = 5, а не 1; и только потом разбираться почему * старше +.

7 - 4  + 2 из-за левоассоциативности распознается как (7 - 4) + 2 = 5 ; если бы эти операции были правоассоциативными, то 7 - (4 + 2) = 1.

8 / 16 / 2 распознается как 1/2 / 2 = 1/4   , а не 8 / 8 = 1
4/8/2/3 = 4 / (8*2*3)
4/8/2/3 в реале нужно следить за associativity , а если в реале в виде дробей 4 * 1/8 * 1/2 * 1/3 то необязательно (в си везде следить нужно).

3 < 2 < 1 даст 1. А в питоне wiki: a < b < c  распознается как ( a < b ) && ( b < c ). 
a = 2    b = 1    c = 3
a == b 			0
a != b 			1
b <= c 			1
a == b <= c 	0
(a == b) <= c 	1
a != b <= c 	1
a = b <= c 		0

a = b; и b = a; разные инструкции.
a = b = c = 0 распознается как a = (b = (c = 0)) в том числе и потому, что Assignments as a whole actually have a value. То есть здесь суть не только в ассоциативности.
Statement c = c + 3; can be abbreviated (сокращена) with the addition assignment operator += as c += 3; Это компилируется быстрее.

C also provides the unary increment operator ++ and the unary decrement operator --.
++a преинкремент, увеличивает на 1, использует новое значение. a++ постинкремент, использует значение, потом увеличивает на 1. Преинкремент работает быстрее. 
a = 5;
printf("%d\n", ++a);	//6
printf("%d\n", a	);	//6	
a = 5;
printf("%d\n", a++);	//5
printf("%d\n", a	);	//6
Therefore you should use increment or decrement operators only in statements in which one variable is incremented or decremented by itself (использовать в отдельных инструкциях). 

The commas used to separate the arguments in a function call are not comma operators. 
The comma operator guarantees that lists of expressions evaluate from left to right. The value of the entire expression is that of the rightmost expression. The value of the rightmost expression becomes the value of the entire expression.
Смотри пример в for и ниже:
int j = 1;
j = (j++, j+333, 4+j);//2, 2+333, 4+2; без скобок будет 1.
printf ("%d\n", j );//6

!5 равно 0, !!5 равно 1, 3*!5 равно 0, 3!5 ошибка.

lvalues and rvalues. 
	Variable names are said to be lvalues (for “left values”) because they can be used on the left side of an assignment operator. Constants are said to be rvalues (for “right values”) because they can be used on only the right side of an assignment operator. lvalues can also be used as rvalues, but not vice versa.
	x == 7 равносильно 7 == x. х = 7, Но 7 = x есть ошибка. 

	int  day = 10, a;
	day == 10 ? a = 1 : a = 0 ;// a = 0 lvalue required as left operand of assignment???
	day == 10 ? (a = 1) : (a = 0) ;//а так работает.	
	printf("%d\n", a);

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

	Непонятно. Л - логика... %u не помогает.
	short x = 32765;//2 байта.
	for (int i = 0; i < 6; ++i)
	{
		printf("%d\n", x);
		x++;
	}
	32765
	32766
	32767
	-32768
	-32767
	-32766

	unsigned short x = 32765;//2 байта.
	for (int i = 0; i < 6; ++i)
	{
		printf("%d\n", x);
		x++;
	}
	32765
	32766
	32767
	32768
	32769
	32770

	int x = 2147483645;//4 байта.
	for (int i = 0; i < 6; ++i)
	{
		printf("%d\n", x);
		x++;
	}
	2147483645
	2147483646
	2147483647
	-2147483648
	-2147483647
	-2147483646

	unsigned int x = 2147483645;//4 байта.
	for (int i = 0; i < 6; ++i)
	{
		printf("%d\n", x);
		x++;
	}
	2147483645
	2147483646
	2147483647
	-2147483648
	-2147483647
	-2147483646


	Есть некоторые вопросы с char. signed char и unsigned char.
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

sizeof Operator.
	sizeof(int) sizeof(A) sizeof(sum) выполняется на этапе компиляции. 
	double real [ 22 ];//объялен массив.
	printf ("%d", sizeof( real ) / sizeof( real[ 0 ] ) );//количество элементов массива.

Явные - неявные преобразования?
	int A = 2; int B = 5; float C = 7; int p; float g;
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

enumeration
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









Control structures. A procedure for solving a problem in terms (в виде) of the actions to be executed, and the order in which these actions are to be executed is called an algorithm. Управляющие структуры (не путать со структурами данных) - это из датасаенс, общее понятие. В основе лежит отказ от goto и получение структурного программирования. В C эти структуры реализованы в виде инструкций. Суть в том, что бы любая структура подключалась к остальным как блок с одним входом и одним выходом. Это отлично видно в flowcharts. All programs could be written in terms only three control structures: 
		The sequence structure is simple — unless directed otherwise (если не указано иное), the computer executes C statements one after the other in the order in which they’re written; 
		Selection Statements: if, if/else, switch; 
		Repetition Statements: while, for, do/while.

The if Statement, single-selection statement (с одиночным выбором).
	if ( /*condition*/ )
	{
		statement;
	}

Conditions in if statements are formed by using the equality operators and relational (отношения) operators. The relational operators all have the same level of precedence and associate left to right. The equality operators have a lower level of precedence than the relational operators and they also associate left to right. 
In C, a condition may actually be any expression that generates a zero (false) or nonzero (true) value. То есть если condition есть просто constant, то условие всегда будет истинным.
	scanf ("%d", &x); 
	printf("%d\n", x>=2);//>= вернет 1 или 0, что и будет напечатано.

	if ( a > b )
		printf("something\n");//The if selection statement expects only one statement in its body—if you have only one statement in the if’s body, you do not need the enclose it in braces.
	if ( a > b )
	{
		statement1;//To include several statements in the body of an if, you must enclose the set of statements in braces ({ and }). A set of statements contained within a pair of braces is called a compound statement or a block. A compound statement can be placed anywhere in a program that a single statement can be placed. 
		statement2;
	}
	if ( a > b ) 
	{
		;//Just as a compound statement can be placed anywhere a single statement can be placed, it’s also possible to have no statement at all, i.e., the empty statement. The empty statement is represented by placing a semicolon (;) where a statement would normally be.
	}
	if ( a > b )
	{
		//; внутри фигурных скобок не обязателен, хотя в примере про указатели ( s1[ i ] = s2[ i ] ) помещают ; внутрь пустых фигурных скобок. 
	}

Any expression in C that produces a value can be used in the decision portion of any control statement. 
	if ( payCode == 4 )
		printf( "%s", "You get a bonus!" );
	if ( payCode = 4 )//всегда истинно, пока присваивается ненулеваое значение.
 		printf( "%s", "You get a bonus!" );

The if…else Selection Statement, double-selection statement. 
Simple if…else statements.
	if ( grade >= 60 )
	{
	 puts( "Passed" );
	} // end if
	else
	{
	 puts( "Failed" );
	} // end else
 
Nested if…else statements.
	if (/* condition */)
	{
		printf("AAA");
	}
	else if (/* condition */)
	{
		printf("BBB");
	}
	else if (/* condition */)
	{
		printf("CCC");
	}

The conditional operator ?: is C’s only ternary operator — it takes three operands. These (three operands) together with the conditional operator ?: form a conditional expression (условное выражение). 
The first operand grade >= 60 is a condition (условие). 
The second operand string "Passed" is the value for the entire(всего) conditional expression (условного выражения) if the condition is true.
The third operand string "Failed" is the value for the entire conditional expression if the condition is false. 
	printf 	(			grade >= 60 ? "1Passed\n" : "Failed\n" );
	printf 	("%s\n" , 	grade >= 60 ? "2Passed" : "Failed" );
	puts 	(			grade >= 60 ? "3Passed" : "Failed" );
	grade >= 60 ? printf( "Passed" ) : printf( "Failed" );
	grade >= 60 ? printf("%s", "Passed") : printf("%s", "Failed" );
	grade >= 60 ? puts 	( "Passed" ) : puts( "Failed" );

The while Repetition Statement.
	int stud = 0; //stud = 0  - initialized
	while (stud < 3)
	{
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
		statement;
	}
In most cases, the for statement can be represented with an equivalent while statement as follows:
	expression1;
	while ( expression2 ) 
	{
		statement
		expression3;
	}

	int main()
	{
		int sum = 0;
		int number;
		for ( number = 2; number <= 100; number += 2 )
		{
			sum += number;
		}
		for (int i = 0; i < 5; ++i)//В стандарте С99 добавили возможность объявления и инициализации переменной внутри цикла for. Тогда i будет экранирована от i в main; см. области действия (scope).
		{
			printf("%d\n", i);
		}
	}

Сomma-Separated Lists (списки) of Expressions. Often, expression1 and expression3 are comma-separated lists of expressions. The commas as used here are actually comma operators that guarantee that lists of expressions evaluate from left to right (гарантирующим выполнение выражений в списке в порядке слева направо, может все же оценивание?). The value and type of a comma-separated list of expressions are the value and type of the rightmost expression in the list (типом и значением списка выражений являются тип и значение самого правого выражения в списке). The comma operator is most often used in the for statement. Its primary use is to enable you to use multiple initialization and/or multiple increment expressions. For example, there may be two control variables in a single for statement that must be initialized and incremented. 
	for ( number = 2; number <= 100; sum += number, number += 2 )//sum += number; could actually be merged into the rightmost portion of the for header by using the comma operator as follows. The initialization sum = 0 could also be merged into the initialization section of the for. 
	{
		; //empty statement. 
	}

Постинкремент выглядит естественнее, но прединкремент здесь эквивалентен и выполняется ( или компилируется?) быстрее.
	int main (void)
	{
		int i;
		for (i = 0; i <= 2; ++i)
		{
			printf("%d\n", i );
		}
		return 0;
	}

Do While
	int main (void)
	{
		int counter = 1;
		do 
		{
			printf("%d\n", counter);
		}	while ( ++counter <= 10);
		return 0;
	}

Switch, a multiple-selection statement (с множественным выбором).
Работает только с константами.
The switch statement consists of a series of case labels, an optional default case and statements to execute for each case. 
	#include <stdio.h>
	int main (void)
	{
		int grade;
		while ( ( grade = getchar() ) != EOF ) //считывает введенный символ и enter; enter = 10; слева от != будет находиться результат последнего присваивания.
		{
			//scanf ("%d", &pas);
			//switch (pas)	
			switch (x)	//Keyword switch is followed by the variable name grade in parentheses. This is called the controlling expression. The value of this expression is compared with each of the case labels (метками каждого кейса). 
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

Break Continue
The break statement, when executed in a while, for, do…while or switch statement, causes an immediate exit from that statement. 
	int main (void)
	{
		int  x;
		for (x = 1; x <= 10; x++)
		{
			if(x == 5)
				break; // break досрочно выводит из цикла, есть и другие структурные способы это сделать.
			printf("%d ", x );
		}
		printf("End %d\n", x);
		return 0;
	}

The continue statement, when executed in a while, for or do…while statement, skips the remaining statements in the body of that control statement and performs the next iteration of the loop. 
	int main (void)
	{
		int  x;
		for (x = 1; x <= 10; x++)
		{
			if(x == 5)
				continue; // continue пропускает оставшийся код, переходит к следующей итерации.
			printf("%d ", x );
		}
		printf("End %d\n", x);
		return 0;
	}

Logical Operators.
In expressions using operator &&, make the condition that’s most likely to be false the leftmost condition. In expressions using operator ||, make the condition that’s most likely to be true the leftmost condition. This can reduce a program’s execution time. The equality operators have a lower level of precedence than the relational operators and they also associate left to right.
	int main (void)
	{
		int  a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		if ( a == 2 )	
			printf("%d==2\n", a);

		if ( !(a == 2) )	
			printf("!(%d==2)\n", a);
		
		if ( b == 1 && c >= 10) 
			printf("%d == 1 && %d >= 10", b, c);
		return 0;
	}

Булева алгебра. 
Короче, вся эта муть дальше, потому что Петцольд не объяснил, что множества и логические высказывания - это две разных вещи. Факт принадлежности кошки к множеству Рыжих - это логическое высказывание, которое может быть истинным или ложным!!! На матпрофи - сначала идут множества, чтобы описать что это такое, а уже ПОТОМ идет логика. Рациональное мышление происходит по законам логики. Если описать эти законы средствами математики - то получится описание мышления. Для обозначения чисел используются операнды (буквы). Для указания способа объединения чисел используются операторы, например, + или х.

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

Задание 4.14. Факториал итеративный.
	int main (void)
	{
		int x,i;
		scanf ("%d", &x);
		i = 1;
		while (x > 1)
		{
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









Functions. The general format for a function definition is:
	return-value-type function-name( parameter-list )//header 
	{//body
		definitions
		statements
	}

Параметры похожи на объявления.
	int main( void )
	{
		int x;//definitions
		x = 2;//initialization
	}

	int main( void )
	{
		func (2);//initialization
	}
	void func (int x)//definitions
	{

	}

All variables defined in function definitions are local variables — they can be accessed only in the function in which they’re defined.
The definitions and statements within braces form the function body, which is also referred (называться, упоминаются, передается) to as a block. Variables can be declared in any block, and blocks can be nested. 
Прототип заставляет компилятор преобразовывать тип данных (int>float, etc). Если прототип не указать - компилятор сам создаст кое-как прототип. Function sqrt can be called with an int argument even though the function prototype in <math.h> specifies a double parameter, and the function will still work correctly. 
Each time a function calls another function, an entry is pushed onto the stack. This entry, called a stack frame, contains the return address that the called function needs in order to return to the calling function. Most functions have automatic variables. When a called function returns to its caller, the called function’s automatic variables need to “go away.” When that function returns—and no longer needs its local automatic variables — its stack frame is popped from the stack, and those local automatic variables are no longer known to the program.
	void print (void);
	float FUNC(int);
	int main (void)
	{
		pint();	// если void - то в скобках должно быть пусто.
		printf("%.3f", FUNC(3));
		return 0;
	}
	void print(void)
	{
		printf("HELLO\n");
		return;	// return здесь можно не писать .
	}
	float FUNC(int x)
	{
		float tmp = x / 2.0 ;
		return tmp;
	}
	
	int AAA(int);//без прототипов функция должна была бы идти роньше вызывающей функции.
	int BBB(int);
	int main (void)
	{
		int ZZZ;
		scanf ("%d", &ZZZ );
		printf("%d", AAA(ZZZ) );
		return 0;
	}
	int AAA(int aaa)
	{
		return BBB(aaa);
	}
	int BBB(int bbb)
	{
		return bbb * 1000;
	}

К примеру бабл в указателях, сокрытие прототипа.
	int AAA(int);
	int main (void)
	{
		int ZZZ;
		scanf ("%d", &ZZZ );
		printf("%d", AAA(ZZZ) );
		return 0;
	}
	int AAA(int aaa)
	{
		int BBB(int);//прототип BBB находится в AAA, скрыт от main.
		return BBB(aaa);
	}
	int BBB(int bbb)
	{
		return bbb * 1000;
	}

Заголовочные файлы .h
Каждая библиотека имеет свой заголовочный файл, содержащий прототипы для всех функций данной библиотеки, а также определение типов данных и констант для этих функций. Можно создавать собственные заголовочные файлы. Подробнее в главе 13. Директивы сообщают препроцессору о необходимости включения заголовочных файлов, которые содержат много всего, в том числе - прототипы функций.
#include "square.h" - файл лежит в рабочей директории.
#include <stdio.h> printf(), scanf(), NULL, sizeof(type or name)
#include <stdlib.h> system(), rand()
#include <math.h> 
#include <conio.h> getchar()
#include <time.h> time(NULL)
#include <unistd.h> sleep()
#include <stddef.h> NULL

Passing Arguments By Value (значению) and By Reference (ссылке). 
In many programming languages, there are two ways to pass arguments—pass-by-value and pass-by-reference. When arguments are passed by value, a copy of the argument’s value is made and passed to the called function. Changes to the copy do not affect an original variable’s value in the caller. When an argument is passed by reference, the caller allows the called function to modify the original variable’s value. In C, all arguments are passed by value. As we’ll see in Chapter 7, it’s possible to simulate pass-by-reference by using the address operator and the indirection operator. In Chapter 6, we’ll see that array arguments are automatically passed by reference for performance reasons.

Storage Classes.
We used identifiers for variable names. The attributes of variables include: 

1. Name. 
2. Type. 
3. Size (data type sizes). 
4. Value. 

We also use identifiers as names for user-defined functions. Actually, each identifier in a program has other attributes: 

5. Storage class. C provides the storage class specifiers: 
		auto, 
		register (archaic), 
		static, 
		extern,
		_Thread_local.

	An identifier’s storage class determines: storage duration, scope, linkage.

6. Storage duration. The storage-class specifiers can be split automatic storage duration and static storage duration. 
	
	Automatic storage duration: 
		auto (variables with automatic storage duration are created when the block in which they’re defined is entered; they exist while the block is active, and they’re  destroyed when the block is exited),
		register. 
	
	Static storage duration: 
		static (for static variables, storage is allocated and initialized only once, before the program begins execution. For functions, the name of the function exists when the program begins execution),
		extern (global variables and function names are of storage class extern by default. Global variables are created by placing variable declarations outside any function definition, and they retain their values throughout the execution of the program).	

7. Scope. The four identifier scopes:

		function (labels (identifiers followed by a colon such as start:) are the only identifiers with function scope. Labels can be used anywhere in the function in which they appear, but cannot be referenced (не доступны для обращения, не могут передаваться, не могут быть сосланы) outside the function body. Labels are used in switch statements (as case labels) and in goto statements (see Chapter 14)),

		file (an identifier declared outside any function, gloobal variables, function definitions, and function prototypes), 

		block {} (local variables defined at the beginning of a function, function parameters, which are considered local variables by the function), 

		function-prototype (int funk(int) - причем, прототипы требуют только типы идентификаторов, имена им не нужны), 

8. Linkage. 

Дурацкое описание в принципе. Период хранения и область действия - разные вещи. Локальная переменная с классом static используется, например, в теле функции или массивах. Атрибуты по-разному переплетаются в зависимости от ключевых слов и местоположения. Глобальная переменная X будет скрыта для функции, если в функции будет объявлена переменная X. Локальные скрываются аналогично:
	int main (void)
	{
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
	
В стандарте С99 добавили возможность инициализации и объявления переменной внутри цикла for:
	int main (void)
	{
		int i = 10;
		for(i = 0; i <=2; i++ )//i доступна для блока for.
		{
			printf("%d\n", i);//0 1 2
		}
		printf("%d\n", i);//3
		return 0;
	}
	int main (void)
	{
		int i = 10;
		for(int i = 0, i <=2, i++ )//i из main скрывается для блока с for.
		{
			printf("%d\n", i);//0 1 2
		}
		printf("%d\n", i);//10
		return 0;
	}
	int main (void)
	{
		int i = 10;
		for(; i <=2; i++)//можно и так.
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
	int main (void)
	{
		int x, y, z=0, sum;
		srand( time(NULL) );
		x = rand () % 6 +1;
		y = rand () % 6 +1;
		sum = x + y;	
		switch (sum)
		{
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

				while (z==0)
				{
					x = rand () % 6 +1;
					y = rand () % 6 +1;
					if (x + y == sum){ //if x + y == 4,5,6,8,9,10
						printf("x=%d y=%d\n", x, y);
						puts ("Win: x+y=first sum");
						z=1;
					}
					if (x + y == 7)
					{
						printf("x=%d y=%d\n", x, y);
						puts ("Lose: 7");
						z=1;
					}	
					else
					{//удобно отсутствием условий
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

Рекурсия. Всё, что можно написать рекурсией - можно написать и итерацией. Нужно выбирать подход в зависимости от обстоятельств. Рекурсия требует больше ресурсов. Факториал рекурсивный:
	int FUNC(int);
	int main (void)
	{
		int number 10;
	}
	int FUNC(int x)
	{
		if(x <= 1)
		{
			return 1;
		}
		else
		{
			return( x*FUNC(x-1) );
		}	
	}

Или так:
	int fact(int x)
	{
	    return x<2 ? 1: x * fact(x-1);
	}
	int main (void)
	{
		printf ("%d\n", fact (5) );
	}

Просто для понимания:
	int FUNC(int);
	int main (void)
	{
		int number = 10;
		FUNC(number);
	}	}
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
				printf ("%d\n", i%60);
			}
		}
	}

Перевод в двоичную систему.
	#include <stdio.h>
	void FUNC (int);
	int main (void)
	{
		int number = 0;
		while ( number != 999){
			printf("Enter chislo:");
			scanf("%d", &number);
			FUNC(number);
			printf("\n");	
		}
	}
	было
	void FUNC (int x)
	{
		int ZOP[8]={0};//8 разрядов.
		int i = 0;
		while ( x != 0)
		{
			ZOP[i]= x % 2 ;
			x = x / 2 ;//1 / 2 равен 0.
			if (x == 0)
				break;
			i=i+1;
		}
		while ( i >= 0)
		{
			printf("%d", ZOP[i]);
			i = i-1;
		}
	}
	стало
	void FUNC (int x)
	{
		int ZOP[8]={0};//8 разрядов.
		int i;
		for (i = 0; x != 0; ++i)
		{
			ZOP[i]= x % 2 ;
			x = x / 2 ;// 1 / 2 равен 0.
		}
		for ( --i ; i >= 0; --i)
		{
			printf("%d", ZOP[i]);
		}
	}

Количество разрядов числа.	
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

Метод Эйлера вики
	double func(double x, double y)
	{
		return 6*x*x+5*x*y; // функция первой производной
	}
	int main(int argc, char** argv)
	{
	    int i, n; 
	    double x, y, h;
	    h = 0.01; // шаг
	    n = 10; // количество итераций
	    x = 1; // x0
	    y = 1; // y0
	    for (i = 0; i < n; i++)
	    {
	        y += h * func(x, y); // вычисление yi
	        x += h;
	    }
	    return EXIT_SUCCESS;
	}








Arrays. Кратко - одномерные, передача одномерного, многомерные, передача многомерного и передача одной строки многомерного, переменные массивы и передача переменных массивов.
Arrays are data structures consisting of related (связанных) data items of the same (одного) type. In Chapter 10, we discuss C’s notion of struct (structure) — a data structure consisting of related data items of possibly different types. Arrays and structures are “static” entities (remain the same size throughout program execution). They may be of automatic storage class.
size_t - an unsigned integral type <stddef.h>.

	int MAS[3] = {0};//массив с 3 ячейками типа int с нулями; номера ячеек: 0, 1, 2; {0} поместит нули во все ячейки, {1} поместит единицу только в нулевую ячейку, а в остальные - нули.
	int MAS[3] = {1, 2, 3};//Можно перечислять переменные по отдельности. Число перечисленных членов не должно превышать размер массива
	int MAS[ ] = {1, 2, 3};//Можно перечислять переменные по отдельности и размер будет указан автоматически
	int MAS[3];//Будут заняты 3 ячейки, в них будет мусор.
	char string1 [] = "first";//initializes the elements of array string1 to the individual characters in the string literal "first". The string "first" contains 5 characters plus a special string-termination character called the null character '\0'. 
	char string1 [] = { 'f', 'i', 'r', 's', 't', '\0' };//эквивалентно предыдущему.
	for (int i = 0; string1[i] != '\0' ; ++i)
		printf("%c\n", string1[i]);//вывести значение ячейки string1[i]. i subscript - индекс; a subscripted array name is an lvalue — it can be used on the left side of an assignment.
Программа может выйти за пределы массива, этого нельзя допускать.

Static Local Arrays and Automatic Local Arrays.
	#include <stdio.h>
	void A (void);
	void S (void);
	int main (void)
	{
		printf("\nfirst");	
		A(); S();
		printf("\nsecond");
		A(); S();
		return 0;
	}
	void A (void)
	{
		int a[] = {1,2,3};
		printf("\nA ");
		for (int i = 0; i < 3; ++i) printf("\t%p %d ", &a[i], a[i] );
		printf("\nA+5 ");
		for (int i = 0; i < 3; ++i) printf("\t%p %d ", &a[i], a[i]+=5);
	}
	void S (void)
	{
		static int a[3];//массив не будет всякий раз создаваться при вызове функции и уничтожаться после выхода из неё. Все тоже самое, что и с static переменными в примере про scope. static array автоматически инициализируется нулями, если не указано иное.
		printf("\nS ");
		for (int i = 0; i < 3; ++i) printf("\t%p %d ", &a[i], a[i]);
		printf("\nS+5 ");
		for (int i = 0; i < 3; ++i) printf("\t%p %d ", &a[i], a[i]+=5);
	}
	first
	A       0028FF0C 1      0028FF10 2      0028FF14 3
	A+5     0028FF0C 6      0028FF10 7      0028FF14 8
	S       0040E020 0      0040E024 0      0040E028 0
	S+5     0040E020 5      0040E024 5      0040E028 5
	second
	A       0028FF0C 1      0028FF10 2      0028FF14 3
	A+5     0028FF0C 6      0028FF10 7      0028FF14 8
	S       0040E020 5      0040E024 5      0040E028 5
	S+5     0040E020 10     0040E024 10     0040E028 10

Passing Arrays to Functions. Recall that all arguments in C are passed by value. C automatically passes arrays to functions by reference — the called functions can modify the element values in the callers’ original arrays. The name of the array evaluates (соответствует) to the address of the first element of the array. It’s possible to pass an array by value (by using a simple trick we explain in Chapter 10). Си передаёт массив в функцию путём имитации передачи параметра по ссылке, вызываемые функции могут изменять значения элементов массива.
Individual array elements (scalars) are passed by value exactly as simple variables are. In Chapter 7, we show how to pass scalars (i.e., individual variables and array elements) to functions by reference. Отдельные значения (скаляры) передются по значению. Но можно имитировать ссылку для скаляров. Чем имитация отличается от передачи по ссылке - хз.
	#include <stdio.h>
	#define SIZE 5//нужно для удобной передачи разных массивов в одну и ту же функцию. В параметрах функции объявляют int переменную, которая внутри функции будет служить размером массива. Это позволяет передавать разные массивы с разными размерами одной и той же функции.
	void modifyArray (int b[], int size);//modifyArray expects to receive an array of integers in parameter b and the number of array elements in parameter size. The size of the array is not required between the array brackets. If it’s included, the compiler checks that it’s greater than zero, then ignores it. 
	void modifyElement (int e);
	void printMAS (int b[], int size);
	int main (void)
	{
		int MAS[SIZE] = {0,1,2,3,4}; 
		char string1 [] = "first";
		scanf и printf не являются частью языка. ВАЖНЫЙ МОМЕНТ - printf ожидает работать просто с числами! Как вариант, в параметрах написано (int a). Поэтому здесь можно передавать все, что угодно. Адрес будет распознаваться просто как число. А вот в функцию, ождающую массив или переменную, так передавать нельзя!!! И об этом не было написано (стр 233)! Scanf работает с цифрами, как с адресами, поэтому ей тоже безразличен способ получения числа. Работа с остальными функциями ниже и она отличается.
		printf("%p", string1);//0028FF34; The name of the array evaluates to the address of the first element of the array; %p conversion specifier.
		scanf("%5s", string1);//& не нужен; 5s введет строку не длиннее 5 символов; scanf может выйти за пределы массива; более того, scanf используют только со строчными массивами.
	!!!	printf("%p", &string1);//Ошибка; адрес адреса???
	!!!	scanf("%5s", &string1);//Ошибка; адрес адреса???
		printf("%p", &string1[0]);//0028FF34.
	!!!	scanf("%5s", &string1[0]);//%c будет распозновать ввод как символ конца строки; не работает с целочисленными массивами???
		printf("%p", string1[0]);//конкретный член массива, работа с ним, как с переменной; но так же будет передаваться строка двумерного массива.
		scanf("%d" , string1[0]);//запишет введенное значение по адресу равному значению ячейки MAS[0]; Это как scanf("%d", x) вместо scanf("%d", &x); но с массивом указателей это не работает...
		
		printMAS (MAS, SIZE);//  0  1  2  3  4
		modifyArray(MAS, SIZE);
		printMAS (MAS, SIZE);//  0  2  4  6  8
	!!!	modifyArray(&MAS, SIZE);//Ошибка; адрес адреса???
	!!!	printMAS (&MAS, SIZE);//Ошибка; адрес адреса???
	!!!	modifyArray(MAS[0], SIZE);//Ошибка; происходит передача значения; одномерный массив двумерного массива передавался бы именно так.
	!!!	printMAS (MAS[0], SIZE);//Ошибка; 
		modifyArray(&MAS[0], SIZE);
		printMAS (&MAS[0], SIZE);//  0  4  8 12 16
		modifyArray(&MAS[2], SIZE);//внутри будет "иметь" массив b, который будет начинаться с адреса MAS[2].
		printMAS (MAS, SIZE);//  0  4 16 24 32
		modifyElement (MAS[4]);
		printMAS (MAS, SIZE);//  0  4 16 24 32
		return 0;
	}
	void modifyArray (int b[], int size)
	{
		for (int i = 0; i < size; i++)
			b[i] *= 2;
	}
	void modifyElement (int e)
	{
		e*=2;
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
			for (int i = 0; i < SIZE-1	; i++)//0 удобен утилизацией в качестве индекса.
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

Multidimensional Arrays. M[число строк][число столбцов-длина строки]. Значения группирируются в фигурных скобках по строкам.
	int M[2][2] = {	{1,2} , {3,4} };
			0стлбц	1стлбц
		0стрк//1//	//2//
		1стрк//3//	//4//
	int M[2][2] = {	{1} , {3,4} };
			0стлбц	1стлбц
		0стрк//1//	//0//
		1стрк//3//	//4//
	int M[2][2] = { 1,2,3 };
			0стлбц	1стлбц
		0стрк//1//	//2//
		1стрк//3//	//0//
	int M[][3] = {1,2,3,4};//число строк = 1 + число элементов % длину строки; без указания длины вообще работать не будет, что логично.
			0стлбц	1стлбц	2стлбц
		0стрк//1//	//2//	//3//	
		1стрк//4//	//0//	//0//

Вывод многомерного массива и передача в функцию.
	#include <stdio.h>
	void printM(int [][3]);//первый индекс не требуется и бесполезен, последующие - обязательно требуются, иначе компилятор не будет знать длину строки. В списке параметров функции определяется о чем идет речь - переменной, одномерном массиве или многомерном массиве. В памяти строка идет за строкой. Каждая строка - по сути одномерный массив. When accessing (при обращении) a[1][2] in our example, the compiler knows to skip the 3 elements of the 1 row (row 0) to get to the 2 row (row 1). Then, the compiler accesses element 2 of that row. 
	int main (void)
	{
		int M[2][3] = {0,1,2,3,4};
		printM (M);//передаем адрес первого элемента в функцию, работа с двумерным; Иные варианты не работают, потому что в параметрах функции идет речь о двумерном массиве.
		return 0;
	}
	void printM (int M[][3])//первый индекс не требуется и бесполезен, последующие - обязательно требуются.
	{	
		for(int i=0; i < 2; i++)//число строк 2.
		{
			for (int j = 0; j < 3; j++)//длина строки 3. 
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
	void print( int A[], int size );
	int main (void)
	{
		int M[ROWS][LONG] = {0,1,2,3,4,5,6,7,8,9,10,11};
		for (int i = 0; i < ROWS; ++i)//Проход по каждой строке массива.
		{
			print( M[i], LONG );//Передача одномерного массива (одной строки многомерного), это не значение ячейки в данном случае!
			//This causes (это приводит к тому) the address of one row of the double-subscripted array to be passed to average (print). The argument M[1] is the starting address of row 1 of the array.
			puts ("");
		}
	!!!	print( M, LONG );//Ошибка.
	!!!	print( &M, LONG );//Ошибка.
	!!!	print( &M[0], LONG );//Ошибка.
	}
	void print( int A[], int size )// Принимает одномерные массивы.
	{
		for (int i = 0; i < size; ++i)
		{
			printf ("%3d  ", A[i] );
		}
	}	

Variable-Length Arrays VLA. Во всех предыдущих примерах массивы задавались константами (в том числе и через define). А здесь суть в объявлении размера массива уже после запуска программы. Именно для этого в индексах используют переменные, которые можно инициализировать в коде или получить от пользователя.
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









Pointers. Коротко: указатель - это переменная, хранящая адрес в памяти; причем есть ограниченное число способов присваивания адреса, а именно: 0, NULL и & адрес другой переменной; эти ограничения и обуславливает все особенности работы с указателями. При объявлении имхо int * name красивее, чем int *name. Pointers are variables whose values are memory addresses. Normally, a variable directly contains a specific value. A pointer, on the other hand, contains an address of a variable that contains a specific value. In this sense, a variable name directly references (непосредственной ссылкой) a value, and a pointer indirectly references (косвенной ссылкой) a value. Referencing a value through (обращение/ссылка к/на значение через) a pointer is called indirection (косвенным доступом).
There are two ways to pass arguments to a function—pass-by-value and pass-by-reference. All arguments in C are passed by value. As we saw in Chapter 5, return may be used to return one value from a called function to a caller (or to return control from a called function without passing back a value). Many functions require the capability to modify variables in the caller or to pass a pointer to a large data object to avoid the overhead of passing the object by value (which incurs the time and memory overheads of making a copy of the object). In C, you use pointers and the indirection operator to simulate pass-by-reference. When calling a function with arguments that should be modified, the addresses of the arguments are passed. This is normally accomplished by applying the address operator (&) to the variable (in the caller) whose value will be modified. As we saw in Chapter 6, arrays are not passed using operator & because C automatically passes the starting location in memory of the array (the name of an array is equivalent to &arrayName[0]). When the address of a variable is passed to a function, the indirection operator (*) may be used in the function to modify the value at that location in the caller’s memory.
	#include <stdio.h>
	int cubeByValue( int n ); 
	void cubeByReference( int * nPtr );
	int main( void )
	{
		int y, x;
		int * countPtr; //The definition specifies that variable countPtr is of type int * (i.e., a pointer to an integer) and is read (right to left), “countPtr is a pointer to int” or “countPtr points to an object of type int.”
		int * yPtr = &y;//Assigns the address of the variable y to pointer variable yPtr. Variable yPtr is then said to “point to” y. The operand of the address operator must be a variable. The address operator cannot be applied to constants or expressions or register. A pointer may be initialized to NULL, 0 or an address. Initializing a pointer to 0 is equivalent to initializing a pointerto NULL, but NULL is preferred. When 0 is assigned, it’s first converted to a pointer of the appropriate type (Инициализация указателя значением 0 эквивалентна инициализации значением NULL, но вообще предпочтительнее использовать NULL. Когда указателю присваивается значение 0, оно сначала преобразуется в указатель соответствующего типа).
		countPtr = &x;
		
		y = 3;
		printf( "%d\n", y );//3
		printf( "%p\n", &y );//0028FF20
		printf( "%p\n", yPtr );//0028FF20
		printf( "%d\n", *yPtr );//The unary * operator, commonly referred (часто называемый?) to as the Indirection Operator (оператор косвенного обращения) or Dereferencing Operator (оператор разыменовывания), returns the value of the object to which its operand (i.e., a pointer) points (объекта, на который его операнд (т.е. указатель) указывает). Using * in this manner is called dereferencing a pointer (разыменованием указателя); 3 
		printf( "%d\n", y+*yPtr );//6
		
		x = 5; 
		x = cubeByValue( x );
		printf( "%d\n", x );//125

		x = 5; 
		cubeByReference( &x );//In C, you use pointers and the indirection operator to simulate pass-by-reference (имитации передачи по ссылке). When calling a function with arguments that should be modified, the addresses of the arguments are passed.
		printf( "%d\n", x );//125

		x = 5; 
		cubeByReference( countPtr );
		printf( "%d\n", x );//125
	}
	int cubeByValue( int n )
	{
		return n * n * n;
	}
	void cubeByReference( int * nPtr )//pointer definitions; cubeByReference receives the address of an integer variable as an argument, stores the address locally in nPtr and does not return a value. 
	{
		*nPtr = *nPtr * *nPtr * *nPtr; //разыменовывает указатель; number = number * number * number
	} 

For a function that expects a single-subscripted array as an argument, the function’s prototype and header can use the pointer notation shown in the parameter list of function cubeByReference. The compiler does not differentiate between a function that receives a pointer and one that receives a single-subscripted array. This, of course, means that the function must “know” when it’s receiving an array or simply a single variable for which it’s to perform pass-by-reference. When the compiler encounters a function parameter for a single-subscripted array of the form int B[], the compiler converts the parameter to the pointer notation int * B. The two forms are interchangeable. Объяснение этого будет в Relationship between Pointers and Arrays.
	#include <stdio.h>
	void func1( int * BPtr );
	void func2( int B[] );
	int main ()
	{
		int MAS[] = {1,2,3,4,5};
		printf ("%p\n", MAS);//0028FF24
		func1 (MAS);
		func2 (MAS);
	!!!	func1 (&MAS);//Ошибка; адрес адреса???
	}
	void func1( int * BPtr )
	{
		printf ("%p\n", BPtr );//0028FF24
		printf ("%d\n", *BPtr );//1
		printf ("%d\n", BPtr[3] );//4
		printf ("%p\n", &BPtr[0] );//0028FF24
	} 
	void func2( int BAS[] )
	{
		printf ("%p\n", B );//0028FF24
		printf ("%d\n", *B );//1
		printf ("%d\n", B[3] );//4
		printf ("%p\n", &B[0] );//0028FF24
	} 

Scanf и указатель.
	#include <stdio.h>
	int main( void )
	{
		int x, * ptr = &x;
		scanf ("%d", &x);//2
		printf ("%d\n", *ptr);//2
		scanf ("%d", ptr);//345
		printf ("%d\n", *ptr);//345
	}

Const Qualifier. Работает с компилятором.
	int main( void )
	{
		int x = 1;
		const int y = 2;//нельзя менять значение переменной.
		int MAS1[] = {1,2,3};
		const int MAS2[] = {4,5,6};//нельзя менять значения ячеек.
		int * aPtr;//все можно.
		const int * bPtr;//нельзя менять значение через dereferencing.
		int const *cPtr = &y;;//нельзя менять адрес указателя.
		const int const *dPtr;//все нельзя.
	}
	void func( int x, const int y, int MAS1[], const MAS2[], int * aPtr, const int * bPtr; int const *cPtr = &y; const int const *dPtr )//Если передавать const сущность в non-const параметр функции, который может изменить значение const сущности, то будет ошибка, даже если нет ни одной изменяющей инструкции.
	{
	}
	Эта же муть на 10 страниц.
		Из главы про массивы. Не сказали, что имя массива это просто константный указатель(
			#include <stdio.h>
			void modA (const int x , const int c[] );
			void modB (int x, int c[] );
			int main()
			{
				int a = 2;
				const int b = 5;//запрет любых изменений, поэтому инициализировать нужно сразу.
				int MASA [] = {1,2,3};
				const int MASB [] = {4,5,6};
			!!!	b = 7;//Ошибка.
			!!!	MASB [2] = 33;//Ошибка.
				modA(a, MASA);
			!!!	modB(b, MASB);//Ошибка, требует const int c[]! Ошибка будет даже несмотря на отсутствие модифицирующих его инструкций в функции. 
			}
			void modA (const int x , const int c[])//any attempt to modify an element of the array in the function body results in a compile-time error. 
			{
			!!!	x = 2;//Ошибка.
			!!! c[2]= 99;//Ошибка.
			}
			void modB (int x, int c[] )
			{
				x = 2;//Ошибки нет 
			}
		Из главы про указатели. The Const Qualifier with Pointers. Six possibilities exist for using (or not using) const with function parameters: 2 with pass-by-value parameter passing and 4 with pass-by-reference parameter passing. Представьте функцию, которая ожидает массив и переменную для его размера. И эти параметры не должны меняться в функции, даже не смотря на то, что и так передаются по значению. There are 4 ways to pass a pointer to a function: 
			1. a non-constant pointer to non-constant data. 
			#include <ctype.h>//toupper
			void convertToUppercase( char *sPtr );
			int main( void )
			{
				char string1[] = "cHaRaCters and $32.98";//массив можно изменять;
				const char string2[] = "Hello";
				printf("%s \n", string1 );//cHaRaCters and $32.98
				convertToUppercase( string1 );
				printf("%s \n", string1 );//CHARACTERS AND $32.98
			!!!	convertToUppercase( string2 );//Ошибка, требует const char *sPtr ! Ошибка будет даже несмотря на отсутствие модифицирующих его инструкций в функции. 
			}
			void convertToUppercase( char *sPtr )
			{
				while( *sPtr != '\0' )
				{
					*sPtr = toupper( *sPtr );
					++sPtr;//увеличивает значение указателя на 1 длину типа данных; в данном случае на 1 байт; это будет объясняться в разделе арифметики указателей.
				} 
			}
			2. a non-constant pointer to constant data.
			void printCharacters1( const char *sPtr );
			int main( void )
			{
				char string1[] = "print characters of a string";// non-constant массив можно изменять; но с точки зрения функции это constant данные.
				printCharacters1( string1 );
			}
			void printCharacters1( const char *sPtr )// указатель sPtr не может использоваться для изменения символа, на который он указывает, то есть sPtr – указатель "только для чтения"; аналогично свойствам const int b[]; non-constant указатель - потому что можно менять его адрес.
			{	
			!!!	*sPtr = 'L';//Ошибка
				for ( ; *sPtr != '\0'; ++sPtr ) 
				{ 
					printf( "%c", *sPtr );
				} 
				char x;
				sPtr += 99;
				sPtr = &x;
			}
			3. a constant pointer to non-constant data. 
				int x = 1;
				int y = 2;
				int * const xPtr = &x;//constant pointer; нельзя менять адрес указателя.
				const int * yPtr = &y;//нельзя менять значение через dereferencing.
				printf ("%d  %d\n", xPtr, *xPtr );
				printf ("%d  %d\n", yPtr, *yPtr );
			!!!	xPtr = &y;//Ошибка.
				yPtr = &x;
				*xPtr = 5;
			!!!	*yPtr = 7;//Ошибка.
			4. a constant pointer to constant data. 
				int n = 5;
				int m;
				const int * const ptr = &n;//константный указатель на целочисленную константу (с точки зрения указателя или функции); ptr всегда указывает на один и тот же адрес; целое число по этому адресу не может быть изменено.
				printf( "%d\n", *ptr );
			!!!	*ptr = 7;//Ошибка; нельзя присвоить новое значение
			!!!	ptr = &m;//Ошибка; нельзя присвоить новый адрес

Relationship between Pointers and Arrays. Pointer Expressions and Pointer Arithmetic. 
	int main (void)
	{
		int x;
		int * b1Ptr, * b2Ptr;
		int B[5] = {0};//An array name can be thought of as a constant pointer. Причем важно понимать, что при этом нет ячейки с адресом. Имя массива является указателем как бы для компилятора.
		b1Ptr = B;//Because the array name (without a subscript) is a pointer to the first element of the array, we can set b1Ptr equal (равным) to the address of the first element in array B with the statement; 
		b1Ptr = &B[0];//равносильно предыдущему, но нагляднее.
		b2Ptr = b1Ptr;//A pointer can be assigned to another pointer if both have the same type. The exception to this rule is the pointer to void (i.e., void *), which is a generic pointer that can represent any pointer type. All pointer types can be assigned a pointer to void, and a pointer to void can be assigned a pointer of any type. In both cases, a cast operation is not required. A pointer to void cannot be dereferenced. Consider this: The compiler knows that a pointer to int refers to 4 bytes of memory on a machine with 4-byte integers, but a pointer to void simply contains a memory location for an unknown data type—the precise number of bytes to which the pointer refers is not known by the compiler. The compiler must know the data type to determine the number of bytes to be dereferenced for a particular pointer.
		int number;
		void *sPtr = NULL;
		number = *( ( int * ) sPtr );//To dereference the pointer, it must first be cast to an integer pointer.

		//Pointers can be compared using equality and relational operators, but such comparisons are meaningless unless the pointers point to elements of the same array. Pointer comparisons compare the addresses stored in the pointers. A comparison of two pointers pointing to elements in the same array could show, for example, that one pointer points to a higher-numbered element of the array than the other pointer does. A common use of pointer comparison is determining whether a pointer is NULL.

		b2Ptr += 2;//would produce 3008 (3000 + 2 * 4), assuming an integer is stored in 4 bytes of memory and address is 3000 ; 3004 (3000 + 2 * 2) if it's stored in 2 bytes. 
		//A pointer may be incremented (++) or decremented (--), an integer may be added to a pointer (+ or +=), an integer may be subtracted from a pointer (- or -=) and one pointer may be subtracted from another.
		x = b2Ptr - b1Ptr;//statement would assign to x the number of array elements from b2Ptr to bPtr, in this case 2 (3008 - 3000).
		//4 байта - это 4гб озу, тогда адрес любой ячейки (то есть одного байта) - это всегда 4 байта на х86 при х32 ос.

		long long *bp = NULL ;
		printf ("%p\n", bp );//00000000
		++bp;
		printf ("%p\n", bp );//00000008	
	}

Using subscripting and pointer notations with arrays.
	#include <stdio.h>
	#define SIZE 4
	int main (void)
	{
		int MAS[] = { 10, 20, 30, 40 };
		int * Ptr = MAS;
	!!!	printf ("%d\n", *Ptr[2] );//Ошибка; Ptr[2] это фича, элемент массива, а не указатель, который можно разыменовать.

		puts ("int MAS[] = { 10, 20, 30, 40 };" );
		puts ("int * Ptr = MAS;" );
		puts ("i  Ptr+i     &MAS[i]   *(Ptr+i)  Ptr[i]  MAS[i]  *(MAS+i)  *(&MAS[0]+i)");
		for (int i = 0; i < SIZE; ++i)
		{
			printf("%d  %p  %p  %d        %d      %d      %d        %d\n", 
				i, Ptr+i, &MAS[i], *(Ptr+i), Ptr[i], MAS[i], *(MAS+i), *(&MAS[0]+i) );	
		}
	}
	int MAS[] = { 10, 20, 30, 40 };
	int * Ptr = MAS;
	i  Ptr+i     &MAS[i]   *(Ptr+i)  Ptr[i]  MAS[i]  *(MAS+i)  *(&MAS[0]+i)
	0  0028FF18  0028FF18  10        10      10      10        10
	1  0028FF1C  0028FF1C  20        20      20      20        20
	2  0028FF20  0028FF20  30        30      30      30        30
	3  0028FF24  0028FF24  40        40      40      40        40
	Pointer/offset notation *(Ptr+offset). Array element MAS[offset] can alternatively be referenced with the pointer expression; offset is offset; this notation is referred to as pointer/offset notation; the parentheses are necessary because the precedence of * is higher than the precedence of +.
	Pointer subscript notation Ptr[i]. Pointers can be subscripted like arrays. If Ptr has the value MAS, the expression refers to the array element MAS[1]. This is referred to as pointer/subscript notation. &Ptr[i] даст адрес соответствующего элемента или просто сделает прыжок на тИповое число байт.
	Array subscript notation MAS[i]. An array name can be thought of as a constant pointer. 
	Pointer/offset notation *(MAS+offset) where the pointer is the array name. The array itself can be treated as a pointer and used in pointer arithmetic;

Bubble Sort Using Pass-by-Reference.
	#include <stdio.h>
	#define SIZE 10
	void bubbleSort(int * const array, const int size);//прототипа swap внутри bubleSort.
	int main (void)
	{
		int a[SIZE] = {2,6,4,8,10,12,89,68,45,37};
		for (int i = 0; i < SIZE; ++i)
		{
			printf("%4d\n", a[i]);
		}
		puts ("");
		bubbleSort (a, SIZE);
		for (int i = 0; i < SIZE; ++i)
		{
			printf("%4d\n", a[i]);		
		}
		return 0;	
	}
	void bubbleSort(int * const array, const int size)
	{
		void swap(int * , int * );
		for (int pass = 1; pass < size; pass++)
		{	
			for (int i = 0; i < size -1; i++)
			{
				if (array[i] > array [ i + 1])
				{
					swap( &array[i] , &array[i+1] );//можно было бы заменить на (array+i) и (array+i+1), но так удобнее.
				}
			}
		}
	}
	void swap (int * element1Ptr, int * element2Ptr)
	{
		int hold;
		hold = *element1Ptr;
		*element1Ptr = *element2Ptr;
		*element2Ptr = hold;
	}

String Copying with Arrays and Pointers. Из-за этого примера пришлось все переосмыслить. Да и со строками все немного путаннее. 
	#include <stdio.h>
	#define SIZE 10
	void copy1( char * const s1, const char * const s2 );
	void copy2( char *s1, const char *s2 );
	int main( void )
	{
		char string1[ SIZE ];//Обычный char массив;
		char string2[ SIZE ];
		char string3[] = "Good Bye";
		char *string4 = "Hello";//Объявить non-const указатель на строку и инициализировать его строковым литералом (то есть скаляром?);
				
		int MAS[] = {1,2,3,4,5};
	!!! int * MAS = {1,2,3,4,5};//Ошибка; а вот с отдельными значениями так нельзя.
	
		int a = 2;
		int * ptr1 = &a;
		printf ("%d\n", *ptr1 );//2
			
		char * ptr2 = string3;
		printf ("%s\n", string3 );//Good Bye
		printf ("%s\n", ptr2 );//Good Bye
	!!!	printf ("%s\n", *ptr2 );//Ошибка из-за спецификатора. 
	!!!	printf ("%s\n", *(ptr2+3) );//Ошибка из-за спецификатора. 
		printf ("%c\n", *ptr2 );//G
		printf ("%c\n", *(ptr2+3) );//d
			
		copy1( string1, string3 );
		printf( "string1 = %s\n", string1 );//Good Bye
		copy2( string2, string4 );
		printf( "string2 = %s\n", string2 );//Hello
	}
	void copy1( char * const s1, const char * const s2 )//cosnt на всякий случай.
	{
		for (size_t i = 0; ( s1[ i ] = s2[ i ] ) != '\0' ; ++i )//слева от != будет находиться результат последнего присваивания.
		{
			;//после последнего s1[ i ] равного \0 произойдет ложность условия и ++i не будет выполнено, произойдет выход из for.
		}
	}
	void copy2( char *s1, const char *s2 )//cosnt на всякий случай.
	{
		for ( ;  ( *s1 = *s2 ) != '\0' ; ++s1, ++s2 ) 
		{
			;
		}
	}

Arrays of Pointers. Arrays may contain pointers. A common use of an array of pointers is to form an array of strings, referred to simply as a string array. Непонятно как сделать scanf("%s", suit[i]) );
	#define SUITS 4
	#define SIZE 4
	#include <stdio.h>
	void deal( const char * wSuit [] );
	int main(int argc, char const *argv[])
	{
		for (int i = 0; i < argc; ++i)
		{
			printf ("%s\n", argv[i] );
		}
		const char * suit [4] = { "Hearts", "Diamonds", "Clubs", "Spades" };//The suit[4] portion of the definition indicates an array of 4 elements. The char * portion of the declaration indicates that each element of array suit is of type “pointer to char.” Qualifier const indicates that the strings pointed to by each element pointer will not be modified. The four values to be placed in the array are "Hearts", "Diamonds", "Clubs" and "Spades".
		char * suit1[4];//Массив из 4 указателей типа char c garbage.
		char * suit2[4] = {};//Массив из 4 указателей типа char инициализированных 0.
		char * suit3[4] = {0};//Массив из 4 указателей типа char инициализированных 0.
		char * suit4[4] = {NULL};//Массив из 4 указателей типа char инициализированных NULL.
		
		int * MAS[SIZE] = {NULL};//Массив из SIZE указателей типа int инициализированных NULL.
	!!! int * BAS[SIZE] = {1,2,3,4,5};//Ошибка; а вот с отдельными значениями так нельзя.

		deal( suit );
	}
	void deal( const char *wSuit[] )
	{
		for (int i = 0; i < SUITS; ++i)
		{
			printf ("%s ", wSuit[i]);
		}
	}	

Pointer to Function. A pointer to a function contains the address of the function in memory. In Chapter 6, we saw that an array name is really the address in memory of the first element of the array. Similarly (аналогично), a function name is really (в действительности) the starting address in memory of the code that performs the function’s task. Pointers to functions can be passed to functions, returned from functions, stored in arrays and assigned to other function pointers. 

Функция, возвращающая указатель на переменную.
	#include <stdio.h>
	int * lol ( void );
	int main( void )
	{
		printf("%d\n", lol() );
		printf("%d\n", *lol() );
	}
	int * lol (void)
	{
		int lala = 2;
		int * ptr = &lala;
		return ptr;
	}

Указатель на функцию.
	#include <stdio.h>
	int ascending( int a, int b );
	int main( void )
	{
		int (*FunctionPtr)(int x, int y);//FunctionPtr that’s a pointer to a function that receives two integer parameters and returns an integer result.
		//int * FunctionPtr (int x, int y) declares a function that receives two integers as parameters and returns a pointer to an integer. Логично, что функция не может быть параметром другой функции.
		void (*VoidFunctionPtr)(int x, int y);//VoidFunctionPtr that’s a pointer to a function that receives two integer parameters and returns void.
		printf ("%d\n", ascending(7,2) );//ничего интересного.
		FunctionPtr = ascending; 
		printf ("%d\n", (*FunctionPtr)(7,2) );//Just as a pointer to a variable is dereferenced to access the value of the variable, a pointer to a function is dereferenced to use the function; указатель выступает как посредник, который передает полученные значения. 
		printf ("%d\n", FunctionPtr(7,2) );//можно, но через разыменование нагляднее, чтобы не перепутать с функцией.
	}
	int ascending( int a, int b )
	{
		return b - a;
	}

Указатель на функцию в параметрах функции. Все тоже самое, что и в примере выше. bubble получает адрес, после чего сама же передает значения в функцию по этому адресу.
	#include <stdio.h>
	void bubble ( int (*FunctionPtr)(int x, int y) );
	int ascending( int a, int b );
	int descending( int c, int d );
	int main( void )
	{
		bubble( ascending );
		bubble( descending );
	}
	void bubble ( int (*FunctionPtr)(int x, int y) )
	{
		printf ("%d\n", (*FunctionPtr)( 7 , 2 ) );
	}
	int ascending( int a, int b )
	{
		return b - a;
	}
	int descending( int c, int d )
	{
		return c + d;
	}

Универсальная программа сортировки, использующая указатели на функции.
	#include <stdio.h>
	#define SIZE 10
	void bubble( int work[], size_t size, int (*FunctionPtr)( int x, int y ) );
	int ascending( int a, int b );
	int descending( int a, int b );
	int main( void )
	{
		int order ; // 1 - for ascending order, 2 –for descending order
		int a[ SIZE ] = { 10, 4, 6, 8, 2, 12, 89, 68, 45, 37 };
										for ( size_t counter = 0; counter < SIZE; ++counter ) 
										{
											printf( "%3d", a[ counter ] );
										}
		puts ("");
		scanf( "%d", &order );
		if ( order == 1 ) 
		{
			bubble( a, SIZE, ascending );//pass function ascending;
		}
		else 
		{
			bubble( a, SIZE, descending );//pass function descending.
		}
										for ( size_t counter = 0; counter < SIZE; ++counter ) 
										{
											printf( "%3d", a[ counter ] );
										}
	}
	void bubble ( int work[], size_t size, int (*FunctionPtr)(int x, int y) )
	{
		void swap( int * element1Ptr, int * element2ptr );//просто прототип swap.
		for ( int pass = 1; pass < size; ++pass )
		{
			for ( int count = 0; count < size - 1; ++count )//0 удобен утилизацией в качестве индекса.
			{
				if ( (*FunctionPtr) ( work[count], work[count+1] ) == 0	)
				//Передача элементов в функцию асендин или десендин с помощью указателя FuctionPtr. 
				//Если функция вернет 1, то все в порядке; 1 == 0 даст 0.
				//Если функция вернет 0, то нужен своп; 0 == 0 даст 1. Тогда будет вызван своп, чтобы поменять элементы местами.
				{
					swap( &work[count], &work[count+1] );//передача элементов в своп.
				}
			}
		}
	}
	int ascending( int a, int b )
	{
		return b > a;//Ассендин вернет 1, если следующее больше предыдущего; то есть если все в порядке. 
	}
	int descending( int a, int b )
	{
		return b < a;//Дессендин вернет 1, если следующее меньше предыдущего.
	}
	void swap( int * element1Ptr, int * element2Ptr )
	{
		int hold;
		hold = *element1Ptr;
		*element1Ptr = *element2Ptr;
		*element2Ptr = hold;
	}

Демонстрация использования массива указателей на функции. Бонус в отказе от свичей с кейсами? Тогда понятно, почему непонятен указатель на функцию и понятно когда массив указателей на функции.
	#include <stdio.h>
	void function1( int a );
	void function2( int b );
	void function3( int c );
	int main( void )
	{
		void (*f[ 3 ])( int ) = { function1, function2, function3 };// Имя переменной давать необязательно???
		size_t choice;
		scanf( "%u", &choice );
		while ( 0 <= choice && choice < 3 ) 
		{
			(*f[ choice ])( choice );//In the function call, f[choice] selects the pointer at location choice in the array (извлекает указатель на функцию из элемента с индексом choice в массиве). The pointer is dereferenced to call the function, and choice is passed as the argument to the function.
			scanf( "%u", &choice );
		}
		puts( "Program execution completed." );
	}
	void function1( int a )
	{
		printf( "You entered %d so function1 was called\n\n", a );
	}
	void function2( int b )
	{
		printf( "You entered %d so function2 was called\n\n", b );
	} 
	void function3( int c )
	{
		printf( "You entered %d so function3 was called\n\n", c );
	} 


