#include <iostream>
#include <windows.h>
#include <conio.h>	// permite usar cprintf
#include <string>
#include <stdio.h>
#include <unistd.h>
#include <cmath>

using namespace std;

//Rutina para movimiento del cursor en toda la pantalla
void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = (SHORT)x-1;
	coord.Y =(SHORT)y-1;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

float OperacionesBasicas()
{
	char operando;
	float num1, num2, resultado;
		
	cout<<endl;
	cout<<"Ingrese primer  número: ";
	cin>>num1;
	cout<<"Ingrese segundo número: ";
	cin>>num2;
	cout<<endl;
	cout<<"Ingrese operación a realizar"<<endl;
	cout<<"Suma(s), Resta(r), Multiplicación(m), División(d): ";
	cin>>operando;
	
	switch (operando)
	{
		case 's': {resultado = num1 + num2;} break;
		case 'r': {resultado = num1 - num2;} break;
		case 'm': {resultado = num1 * num2;} break;
		case 'd': {resultado = num1 / num2;} break;
	}
	return resultado;
}

void ParImpar()
{
	int num;
	
	cout<<endl;
	cout<<"Ingrese número: ";
	cin>>num;
	cout<<endl;
	if (num % 2 == 0){
		cout<<"El número es PAR."<<endl;
	}
	else {
		cout<<"El número es IMPAR."<<endl;
	}
}

float Conversor(float constant, string med1, string med2)
{
	float resultado, valini;
	_cprintf("\nIngrese cantidad de %s: ",med1.c_str());
	cin>>valini;
	resultado = valini * constant;
	_cprintf ("\n%8.4f %s son %8.4f %s.",valini,med1.c_str(),resultado,med2.c_str());

return resultado;	
}

MenuConversor()
{
	float valorIni, constante, respuesta;
	int   opcion;
	string Medida1, Medida2;
	
	do
	{
		system("cls"); system("color F6");
		gotoxy(18, 7); cout << " 1. Millas     -->>  Kilómetros";
		gotoxy(18, 8); cout << " 2. Kilómetros -->>  Millas";
		gotoxy(18, 9); cout << " 3. Metros     -->>  Pulgadas";
		gotoxy(18,10); cout << " 4. Pulgadas   -->>  Metros";
		gotoxy(18,11); cout << " 5. Libras     -->>  Kilos";
		gotoxy(18,12); cout << " 6. Kilos      -->>  Libras";
		gotoxy(18,14); cout << " 0. Regresar al menú principal";
		gotoxy(28,16); cout << "Opcion: ";

		gotoxy(36,16); cin >> opcion;

		switch (opcion)
		{
		case 1: 
			{
				constante = 1.609;
				Medida1   = "Millas";
				Medida2   = "Kilómetros";
				respuesta = Conversor(constante, Medida1, Medida2);
				gotoxy(1,27); _getch();
			}
			break;

		case 2: 
			{
				constante = 0.6215;
				Medida1   = "Kilómetros";
				Medida2   = "Millas";
				respuesta = Conversor(constante, Medida1, Medida2);
				gotoxy(1,27); _getch();
			}
			break;

		case 3: 
			{
				constante = 39.3701;
				Medida1   = "Metros";
				Medida2   = "Pulgadas";
				respuesta = Conversor(constante, Medida1, Medida2);
				gotoxy(1,27); _getch();
			}
			break;

		case 4: 
			{
				constante = 0.0254;
				Medida1   = "Pulgadas";
				Medida2   = "Metros";
				respuesta = Conversor(constante, Medida1, Medida2);
				gotoxy(1,27); _getch();
			}
			break;

		case 5: 
			{
				constante = 0.4536;
				Medida1   = "Libras";
				Medida2   = "Kilogramos";
				respuesta = Conversor(constante, Medida1, Medida2);
				gotoxy(1,27); _getch();
			}
			break;

		case 6: 
			{
				constante = 2.2046;
				Medida1   = "Kilogramos";
				Medida2   = "Libras";
				respuesta = Conversor(constante, Medida1, Medida2);
				gotoxy(1,27); _getch();
			}
			break;

		case 0:
			break;
			
		default:
			{
				gotoxy(28,26); cout << "OPCION INVALIDA.";
				gotoxy(1,27); _getch();
			}
			break;

		}
	} while (opcion != 0);
}

void Palindromo(){
	char Vasc[20]="", Vdes[20]="";
	int j=0;
	
	cout<<endl<<"Ingrese palabra o número: ";
	cin>>Vasc;
	
	for (int i=strlen(Vasc)-1;i>=0;i--)
	{
		Vdes[j] = Vasc[i];
		j++;
	}
	if (strcmp(Vasc,Vdes) == 0){
		cout<<endl<<"Si es Palindromo."<<endl;
		cout<<Vasc<<" es igual a "<<Vdes<<endl;
	}
	else {
		cout<<endl<<"No es Palidromo."<<endl;
		cout<<Vasc<<" NO es igual a "<<Vdes<<endl;
	}

	gotoxy(1,27); _getch();
	
}

void UnaTablaMultipicar()
{
	int multiplicador;
	
	cout<<endl<<"Ingrese el valor de la tabla de multiplicar que desea ver: ";
	cin>>multiplicador;
	
	for (int i=1;i<=10;i++)
	{
		cout<<endl<<"   "<<multiplicador<<" x "<<i<<" = "<<multiplicador*i<<endl;
	}
	gotoxy(1,27); _getch();
}

void TodasLasTablasDeMultipicar()
{
	for (int i=1;i<=10;i++)
	{
		cout<<endl<<"      Tabla del "<<i<<endl;
		for (int j=1;j<=10;j++)
		{
			cout<<"   "<<i<<" x "<<j<<" = "<<i*j<<endl;
		}
	}
	gotoxy(1,27); _getch();
}

void GraficaMultiplicacion(){
	int num1, num2;
	int cociente, residuo;
	int linea = 9, posicion = 11;
	
	cout<<endl<<"Ingrese  primer número: ";
	cin>>num1;
	cout<<endl<<"Ingrese segundo número: ";
	cin>>num2;

	_cprintf("\n%20d x\n",num1);
	_cprintf("%20d\n",num2);
	_cprintf("____________________\n");
	
	cociente = num2;
	residuo  = num2;

	while (cociente > 0) 
	{
		residuo  = cociente % 10;
		cociente = cociente / 10;

		gotoxy(posicion, linea); _cprintf("%10d\n",residuo * num1);
		linea++;
		posicion--;
	} 

	_cprintf("____________________\n");
	_cprintf("%20d\n",num1*num2);

	gotoxy(1,27); _getch();
}

void DecimalBinario()
{
	int decimal = 0, cociente = 0, residuo = 0;
	string binario = "";
		
	cout << "Ingrese Número Entero Decimal: ";
	cin >> decimal;

	cociente = decimal;	
	if (decimal==0){binario = "0";}
	while (cociente > 0)
	{
		residuo  = cociente % 2;
		cociente = cociente / 2;

		if (residuo == 0){
			binario = "0" + binario;
		}
		else {
			binario = "1" + binario;
		}
	}
	
	cout<<"El número binario es: "<<binario<<endl;

	gotoxy(1,27); _getch();
}

void DecimalHexadecimal()
{
	int decimal = 0, cociente = 0, residuo = 0;
	string hexa = "";
	char buffer[33];
		
	cout << "Ingrese Número Entero Decimal: ";
	cin >> decimal;

	cociente = decimal;	
	if (decimal==0){hexa = "0";}
	while (cociente > 0)
	{
		residuo  = cociente % 16;
		cociente = cociente / 16;

		switch (residuo)
		{
			case 10:{hexa="A" + hexa;} break;
			case 11:{hexa="B" + hexa;} break;
			case 12:{hexa="C" + hexa;} break;
			case 13:{hexa="D" + hexa;} break;
			case 14:{hexa="E" + hexa;} break;
			case 15:{hexa="F" + hexa;} break;
			default:{hexa=itoa(residuo,buffer,10)+ hexa;} break;
		}

	}
	
	cout<<"El número hexadecimal es: "<<hexa<<endl;

	gotoxy(1,27); _getch();
}

void MovimientoPunto()
{
	int columna=1, fila=1;
	unsigned int microseg;
	
	microseg = 100000;
	
	string horizontal = "d"; /* izquierda, derecha */
	string vertical   = "s"; /* superior, inferior */

	columna = rand() % 150;
	fila = rand() % 30;
	
	for (int i=0;i<100;i++)
	{
		gotoxy(columna,fila); cout<<"*";
		usleep(microseg);
cout<<columna;
cout<<fila;
		if ((horizontal == "d") && (columna < 150))
		{	columna++;}
		else if ((horizontal == "d") && (columna = 150))
		{	horizontal = "i";
			columna--;}
	
		if ((horizontal == "i") && (columna > 1))
		{	columna--;}
		else if ((horizontal == "d") && (columna = 1))
		{	horizontal = "d";
			columna++;}

		if ((vertical == "s") && (fila < 30))
		{	fila++;}
		else if ((vertical == "s") && (fila = 30))
		{	vertical = "i";
			fila--;}
	
		if ((vertical == "i") && (fila > 1))
		{	fila--;}
		else if ((vertical == "i") && (fila = 1))
		{	vertical = "s";
			fila++;}
	}
}

void Hipotenusa()
{
	float ladoA, ladoB, hipotenusa;
	
	cout<<"Ingrese valor del lado A: ";
	cin>> ladoA;
	cout<<"Ingrese valor del lado B: ";
	cin >> ladoB;
	
	hipotenusa = sqrt((ladoA*ladoA)+(ladoB*ladoB));
	cout<<endl<<endl<<"El valor de la hipotenusa es: "<<hipotenusa<<endl;

	gotoxy(1,27); _getch();
}

void SumaVectores()
{
	//Declaración de variables. Primero se declaran estructuras y luego variables.
	int vectorA[7];
	float vectorB[7], SumaDeVectores[7];
	int i, fila, columna;

	gotoxy(10,3); cout << "INGRESE DATOS";

	fila = 5; columna = 30;
	gotoxy(10,fila); cout << "VectorA:";
	for (i=0;i<=6;i++)
	{
		gotoxy(columna,fila); cin >> vectorA[i];
		columna = columna + 7;
	}

	fila = 7; columna = 30;
	gotoxy(10,fila); cout << "VectorB:";
	for (i=0;i<=6;i++)
	{
		gotoxy(columna,fila); cin >> vectorB[i];
		columna = columna + 7;
	}

	fila = 9; columna = 30;
	gotoxy(10,fila); cout << "Suma de Vectores:";
	for (i=0;i<=6;i++)
	{
		gotoxy(columna,fila); _cprintf("%5.2f", vectorA[i] + vectorB[i]);
		columna = columna + 7;
	}

	gotoxy(1,27); _getch();

}

void MovimientoVectores()
{
	//Declaración de variables. Primero se declaran estructuras y luego variables.
	int vectorAlfa[10], vectorOmega[5];
	int i, par, fila, columna;
	float promedioAlfa, promedioOmega, suma;

	gotoxy(10,3); cout << "INGRESE DATOS";

	//Ingreso datos vector Alfa
	fila = 5; columna = 30; suma = 0; promedioAlfa = 0.00;
	gotoxy(10,fila); cout << "VectorAlfa:";
	for (i=0;i<=9;i++)
	{
		gotoxy(columna,fila); cin >> vectorAlfa[i];
		columna = columna + 7;
		suma = suma + vectorAlfa[i];
	}
	promedioAlfa = suma / 10;
	gotoxy(110, fila); _cprintf("%7.2f", promedioAlfa);

	//Traslado de datos de las posiciones pares al vector Omega
	par = 0; suma = 0; promedioOmega = 0.00;
	for (i=0;i<=9;i=i+2)
	{
		vectorOmega[par] = vectorAlfa[i];
		columna = columna + 7;
		suma = suma + vectorOmega[par];
		par++;
	}
	promedioOmega = suma / 5;

	//Depsliegue del Vector Omega
	fila = 7; columna = 30;
	gotoxy(10,fila); cout << "VectorOmega:";
	for (i=0;i<=4;i++)
	{
		gotoxy(columna,fila); _cprintf("%d", vectorOmega[i]);
		columna = columna + 7;
	}
	gotoxy(110, fila); _cprintf("%7.2f", promedioOmega);

	//Validar cual promedio es mayor o si son iguales
	if (promedioAlfa > promedioOmega)
	{
		gotoxy(15,10); printf("El promedio mayor es del VectorAlfa..........:%8.2f",promedioAlfa);
	}
	else
	{
		if (promedioOmega > promedioAlfa)
		{
			gotoxy(15,10); printf("El promedio mayor es del VectorOmega..........:%8.2f",promedioOmega);
		}
		else
		{
			gotoxy(15,10); printf("Los promedios son iguales.");
		}
	}

	gotoxy(10,20); _getch();
	
}

//Declaración de variables y estructuras públicas

int matrizA[3][3], matrizB[3][3], matrizSumada[3][3];

void encabezado()
{
	system("cls"); system("color f3");
	gotoxy(10,1); cout << "CARNE          MATEMATICAS    IDIOMA         CIENCIAS       SOCIALES";
}

void IngresoMatrizA()
{
	system("cls"); system("color f3");

	int i,j,fila,columna;

	fila=3;
	columna=25;
	gotoxy(columna,fila);cout << "Ingrese Valores de Matriz A";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			gotoxy(columna+j*10,fila+i+2); cin >> matrizA[i][j];
		}
	}
}

void IngresoMatrizB()
{
	int i,j,fila,columna;

	fila=10;
	columna=25;
	gotoxy(columna,fila);cout << "Ingrese Valores de Matriz B";
	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			gotoxy(columna+j*10,fila+i+2); cin >> matrizB[i][j];
		}
	}
}

void Visualizacion()
{
	system("cls"); system("color f3");

	int i,j,fila,columna;

	fila=3;
	columna=25;
	gotoxy(columna,fila);cout << "MATRIZ A";

	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			gotoxy(columna+j*10,fila+i+2); cout << matrizA[i][j];
		}
	}

	fila=10;
	columna=25;
	gotoxy(columna,fila);cout << "MATRIZ B";

	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			gotoxy(columna+j*10,fila+i+2); cout << matrizB[i][j];
		}
	}

	gotoxy(22,16); cout << "===========================";

	fila=18;
	columna=25;
	gotoxy(columna,fila);cout << "MATRICES SUMADAS";

	for (i=0;i<3;i++)
	{
		for (j=0;j<3;j++)
		{
			gotoxy(columna+j*10,fila+i+2); cout << matrizA[i][j] + matrizB[i][j];
		}
	}

	gotoxy(1,24); _getch();
}

void menu()
{
	system("cls"); system("color f3");
	gotoxy(30, 9); cout << "1. Ingreso de valores para las matrices";
	gotoxy(30,10); cout << "2. Matrices sumadas";
	gotoxy(30,11); cout << "0. SALIR";
	gotoxy(35,13); cout << "Opcion: ";
}

void SumaMatrices()
{
	int opcion;
	do
	{
		menu();
		gotoxy(43,13); cin >> opcion;
		switch (opcion)
		{
		case 1: 
		{
			IngresoMatrizA();
			IngresoMatrizB();
		}
		break;

		case 2:
		{
			Visualizacion();
		}
		break;
		}
	} while (opcion != 0);

}

void probabilidadSimple()
{
	system("cls");

	char colores[3][20] = { "Azul", "Verde", "Roja"};
	float cantcolor[3];
	float acumulado, total;
	int   otro1, otro2;
	int   i, j, fila, columna;

	columna=25;
	fila=3;
	gotoxy(columna, fila); _cprintf("PROBABILIDAD SIMPLE");

	gotoxy(columna, fila + 2); _cprintf("Ingrese cantidad de canicas de cada color");

	acumulado=1;
	total=0;
	for (i=0;i<3;i++)
	{
		gotoxy(columna + 5, fila + 3 + i); cout << colores[i] << ": ";
		cin >> cantcolor[i];
		total = total + cantcolor[i];
	}

	gotoxy(columna, fila + 7); _cprintf("Se selecciona la primera canica.");
	for (i=0;i<3;i++)
	{
		gotoxy(columna + 5, fila + 8 + i); cout << colores[i]; cout << cantcolor[i];
		gotoxy(columna + 5, fila + 8 + i); _cprintf("La probabilidad de que sea %s es:  %5.2f %%", colores[i], (cantcolor[i]/total)*100);
	}
	
	gotoxy(columna, fila + 12); _cprintf("Se seleccionan 2 canicas.");
	for (i=0;i<3;i++)
	{
		switch (i)
		{
		case 0: { otro1 = 1; otro2 = 2;}; break;
		case 1: { otro1 = 0; otro2 = 2;}; break;
		case 2: { otro1 = 0; otro2 = 1;}; break;
		}
		gotoxy(columna + 5, fila + 13 + (i*3)); _cprintf("La probabilidad de que la segunda sea %s, si la primera fue %s, es:  %5.2f %%", colores[i], colores[otro1], (cantcolor[i]/(total-1))*100);
		gotoxy(columna + 5, fila + 14 + (i*3) ); _cprintf("La probabilidad de que la segunda sea %s, si la primera fue %s, es:  %5.2f %%", colores[i], colores[otro2], (cantcolor[i]/(total-1))*100);
		gotoxy(columna + 5, fila + 15 + (i*3) ); _cprintf("La probabilidad de que la segunda sea %s, si la primera fue %s, es:  %5.2f %%", colores[i], colores[i], ((cantcolor[i]-1)/(total-1))*100);
	}

	gotoxy(1,27);
	_getch();
}



main()
{
	setlocale(LC_CTYPE, "Spanish");

	int  opcion;
	float respuesta=0;

	system("cls"); system("color f6");

	do 
	{ 
		system("cls"); system("color F6");
		gotoxy(31, 2); cout << "PROGRAMACION 1";
		gotoxy(26, 3); cout << "TAREA (20 programas en C++)";
		gotoxy(31, 4); cout << "Eduardo Del Cid";
		gotoxy(32, 5); cout << "5990-21-21461";
		gotoxy(18, 7); cout << " 1. Suma, Resta, Multiplicación, División de 2 números";
		gotoxy(18, 8); cout << " 2. Determinar si número es Par o Impar";
		gotoxy(18, 9); cout << " 3. Conversor Kms a Millas, Mts a Plgds, Lbs a Kilos (y visceversa)";
		gotoxy(18,10); cout << " 4. Determinar si una palabra o número es palíndromo";
		gotoxy(18,11); cout << "      NO    5. Conversión de números arábigos a romanos (mínimo 1000)";
		gotoxy(18,12); cout << "      NO    6. Conversión de números enteros a letras";
		gotoxy(18,13); cout << "      NO    7. Conversión de números enteros con decimal a letras";
		gotoxy(18,14); cout << " 8. Una tabla de multiplicar";
		gotoxy(18,15); cout << " 9. Todas las tablas de multiplicar del 1 al 10";
		gotoxy(18,16); cout << "10. Forma gráfica de la multiplicación manual";
		gotoxy(18,17); cout << "11. Conversión de números decimales a binario";
		gotoxy(18,18); cout << "12. Conversión de números decimales a hexadecimales";
		gotoxy(18,19); cout << "      NO    13. Figuras geométricas básicas";
		gotoxy(18,20); cout << "14. Movimiento de un punto en toda la pantalla";
		gotoxy(18,21); cout << "      NO    15. Simulación de un cajero (autómata)";
		gotoxy(18,22); cout << "16. Calcular la hipotenusa";
		gotoxy(18,23); cout << "17. Suma de Vectores";
		gotoxy(18,24); cout << "18. Traslado de vectores posiciones pares y obtener promedios";
		gotoxy(18,25); cout << "19. Suma de Matrices";
		gotoxy(18,26); cout << "20. Probabilidad estadística simple";
		gotoxy(18,28); cout << "0. SALIR";
		gotoxy(28,29); cout << "Opcion: ";

			gotoxy(36,29); cin >> opcion;

		switch (opcion)
		{
		case 1: 
			{
				system("cls"); system("color 0A");
				respuesta=OperacionesBasicas();
				cout<<endl;
				_cprintf("El resultado es: %6.2f %%", respuesta);
				gotoxy(1,27); _getch();
			}
			break;

		case 2:
			{
				system("cls");
				ParImpar();
				gotoxy(1,27); _getch();
			}
			break;

		case 3:
			{
				system("cls");
				MenuConversor();
			}
			break;

		case 4:
			{
				system("cls");
				Palindromo();
			}
			break;

		case 8:
			{
				system("cls");
				UnaTablaMultipicar();
			}
			break;

		case 9:
			{
				system("cls");
				TodasLasTablasDeMultipicar();
			}
			break;

		case 10:
			{
				system("cls");
				GraficaMultiplicacion();
			}
			break;

		case 11:
			{
				system("cls");
				DecimalBinario();
			}
			break;

		case 12:
			{
				system("cls");
				DecimalHexadecimal();
			}
			break;

		case 14:
			{
				system("cls");
				MovimientoPunto();
			}
			break;

		case 16:
			{
				system("cls");
				Hipotenusa();
			}
			break;

		case 17:
			{
				system("cls"); system("color f4");
				SumaVectores();
			}
			break;

		case 18:
			{
				system("cls"); system("color f4");
				MovimientoVectores();
			}
			break;

		case 19:
			{
				system("cls"); system("color f4");
				SumaMatrices();
			}
			break;

		case 20:
			{
				system("cls"); system("color f4");
				probabilidadSimple();
			}
			break;

		case 0:
			break;

		default:
			{
				gotoxy(28,26); cout << "OPCION INVALIDA.";
				gotoxy(1,27); _getch();
			}
			break;

		}
	} while (opcion != 0);

}

