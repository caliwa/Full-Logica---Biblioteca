#include <iostream>
using namespace std;

int login();
void MenuPrincipal();
int NuevoPresta(string[], string[], string[], string[], int, int, int, int, int, int, int[]);
void ConsulPena(string[], string[], string[], int[], string[], int, int[], int[], int[], int[], int[]);
int Modientre(string[], string[], string[], string[], int, int[]);
int Devo(string[], string[], string[], string[], int, int[], int[], int[], int[], int[]);
void infoFinal(string[], string[], string[],string[], int[], int, int, int, int, int, int, int, int, int, int, int, int, int[]);

int main() {
	string cedula[100], name[100], apellido[100], Telefono[100];
	int penalizacion[100], Op, Contador = 1, H, R, G, Prestado1 = 3, Prestado2 = 3, Prestado3 = 3, Prestado4 = 3, Prestado5 = 3, Cont1 = 0, Cont2 = 0, Cont3 = 0, Cont4 = 0, Cont5 = 0, Validar2 = 0,Validar[100], Validar22[100], Validar3[100], fechaentrega[100]; 
	int prestado1[100], prestado2[100], prestado3[100], prestado4[100], prestado5[100], devuelto1[100], devuelto2[100], devuelto3[100], devuelto4[100], devuelto5[100];
	int C1 = 0, C2 = 0, C3 = 0, C4 = 0, C5 = 0, CC1 = 0, CC2 = 0, CC3 = 0, CC4 = 0, CC5 = 0, NMay = 0;
	char Seguro, Seguro2;	
	
	for(int i = 0 ; i < 100 ; i++)
	{
		penalizacion[i] = 0;
		Validar[i]= 0, Validar22[i] = 0, Validar3[i] = 0;
		prestado1[100] = 0, prestado2[100] = 0, prestado3[100] = 0, prestado4[100] = 0, prestado5[100] = 0;
	}

	if(login() == 1)
	{
		do{
		if(Cont1 + Cont2 + Cont3 + Cont4 + Cont5 == 3)
		{
			penalizacion[Contador-1] = 1;
		}
		cout<<"BIENVENIDO A LA LIBRERIA, USUARIO #"<<Contador<<" DEL DIA"<<endl<<endl;
		MenuPrincipal();
		fflush(stdin);
		do{
	        cout << "Seleccione su opcion: ";		
			cin>>Op;
		}while(Op < 1 || Op > 7);
		fflush(stdin);
	        switch (Op){
	        	case 1:
	        		if((CC1 + CC2 + CC3 + CC4 + CC5) == 15)
	        		{
	        			cout<<"\nNo hay libros para alquilar, vuelva proximamente.\n";
					}
	        		else
	        		{
		        		if(prestado1[Contador-1] + prestado2[Contador-1] + prestado3[Contador-1] + prestado4[Contador-1] + prestado5[Contador-1] == 3)
		        		{
		        			cout<<"\nUsted ha sido penalizado temporalmente por alquilar el limite de libros(3), consulte penalizaciones para mas informacion (opcion numero 2).\n";
		        			penalizacion[Contador-1] = 1;	
		        			system("pause");
						}
						else
						{
							H = NuevoPresta(name, apellido, cedula, Telefono, Contador, Prestado1, Prestado2, Prestado3, Prestado4, Prestado5, Validar);
		        			switch(H)
							{
								case 1: Cont1++, CC1++, Prestado1--, Validar2++;
								break;
								case 2: Cont2++, CC2++, Prestado2--, Validar2++;
								break;
								case 3: Cont3++, CC3++, Prestado3--, Validar2++;
								break;	
								case 4: Cont4++, CC4++, Prestado4--, Validar2++;
								break;
								case 5: Cont5++, CC5++, Prestado5--, Validar2++;
								break;																	        				
							}
							prestado1[Contador-1] = Cont1;
							prestado2[Contador-1] = Cont2;
							prestado3[Contador-1] = Cont3;
							prestado4[Contador-1] = Cont4;
							prestado5[Contador-1] = Cont5;
							Validar[Contador-1] = 1;
							Validar22[Contador-1] = Validar2;
							fechaentrega[Contador-1] = 5;
						}
					}
	        		system("cls");
				break;
	        	case 2:
        			if(Validar22[Contador-1] == 0)
        			{
        				cout<<"\nEste usuario no ha alquilado nada, por lo que no posee historial de penalizacion.\n";
					}
					else if(Validar22[Contador-1] > 0)
					{
						ConsulPena(name, apellido, cedula, penalizacion, Telefono, Contador, prestado1, prestado2, prestado3, prestado4, prestado5);
					}
					system("pause");
	        		system("cls");
				break;
	        	case 3:
	        		if(Validar22[Contador-1] == 0)
					{	
	        			cout<<"\nEste usuario no ha alquilado nada, por lo que no debe entregar ningun libro.\n";
					}
					else if(Validar22[Contador-1] > 0)
					{
						if(Validar3[Contador-1] == 0)
						{
							G = Modientre(name, apellido, cedula, Telefono, Contador, fechaentrega);
							fechaentrega[Contador-1] = G;
							Validar3[Contador-1] = 1;
						}
						else if(Validar3[Contador-1] == 1)
						{
							cout<<"\nEste usuario ya hizo un cambio de horario para entregar, no puede realizar mas cambios.\n";
						}
					}	
					system("pause");		
	        		system("cls");
				break;
	        	case 4: 
					if(Validar22[Contador-1] == 0)
        			{
        				cout<<"\nEste usuario no ha alquilado ningun libro.\n";
					}
					else if(Validar22[Contador-1] > 0)
					{
						R = Devo(name, apellido, cedula, Telefono, Contador, prestado1, prestado2, prestado3, prestado4, prestado5);
	        			switch(R)
						{
							case 1: Cont1--, C1++, Prestado1++, Validar2--;
							break;
							case 2: Cont2--, C2++, Prestado2++, Validar2--;
							break;
							case 3: Cont3--, C3++, Prestado3++, Validar2--;
							break;	
							case 4: Cont4--, C4++, Prestado4++, Validar2--;
							break;
							case 5: Cont5--, C5++, Prestado5++, Validar2--;
							break;																	        				
						}
						devuelto1[Contador-1] = C1;
						devuelto2[Contador-1] = C2;
						devuelto3[Contador-1] = C3;
						devuelto4[Contador-1] = C4;
						devuelto5[Contador-1] = C5;
						prestado1[Contador-1] = Cont1;
						prestado2[Contador-1] = Cont2;
						prestado3[Contador-1] = Cont3;
						prestado4[Contador-1] = Cont4;
						prestado5[Contador-1] = Cont5;					
						Validar22[Contador-1] = Validar2;
						if(Validar22[Contador-1] == 0)
						{
							fechaentrega[Contador-1] = 4;
						}
	        			if(prestado1[Contador-1] + prestado2[Contador-1] + prestado3[Contador-1] + prestado4[Contador-1] + prestado5[Contador-1] < 3)
	        			{
	        				penalizacion[Contador-1] = 0;
						}						
					}
					system("pause");
	        		system("cls");
				break;
	        	case 5: 
					if(Validar[Contador-1] == 0)
        			{
        				cout<<"\nEste usuario no ha alquilado nada para proceder, por favor dirijase a la primer opcion.\n";
					}
					else
					{
						if(Contador > NMay)
						{
							NMay = Contador;
						}			
						cout<<"Esta seguro de cambiar de usuario? Digite S, si quiere volver al menu digite N";
						cout<<"\nDigite: ";
						cin>>Seguro;
						cout<<"\n";
						if(Seguro == 'S' || Seguro == 's')
						{
							if(NMay == 1){
								Cont1 = 0, Cont2 = 0, Cont3 = 0, Cont4 = 0, Cont5 = 0, Validar2 = 0, Contador++;
								Validar[Contador-1]= 0, Validar22[Contador-1] = 0, Validar3[Contador-1] = 0;
        						cout<<"\nUsuario Ingresando...";									
							}
							else if(NMay > 1)
							{
								if(Contador >= 1)
								{
									if(Contador == 1)
									{
										cout<<"Digite R si quiere ir al siguiente usuario. Digite N para volver al menu";
									}
									else if(Contador > 1)
									{						
										if(Contador == NMay)
										{
											cout<<"Digite R si quiere ingresar un usuario nuevo, digite A si quiere volver a un usuario anterior.Digite N para volver al menu";
										}
										else if(Contador < NMay)
										{
											cout<<"Digite R si quiere ir al siguiente usuario, digite A si quiere volver a un usuario anterior.Digite N para volver al menu";
										}
									}
								}
								cout<<"\nDigite: ";
								cin>>Seguro2;
								cout<<"\n";
								if(Seguro2 == 'R' || Seguro2 == 'r')
								{
									if(NMay > Contador)
									{
										Contador++;
										Cont1 = prestado1[Contador-1], Cont2 = prestado2[Contador-1], Cont3 = prestado3[Contador-1], Cont4 = prestado4[Contador-1], Cont5 = prestado5[Contador-1], Validar2 = 0;
										Validar2 = Validar22[Contador-1];
										cout<<"\nUsuario Ingresando...";
									}
									else if(NMay == Contador)
									{
										Cont1 = 0, Cont2 = 0, Cont3 = 0, Cont4 = 0, Cont5 = 0, Validar2 = 0, Contador++;
										Validar[Contador-1]= 0, Validar22[Contador-1] = 0, Validar3[Contador-1] = 0;
										cout<<"\nUsuario Ingresando...";
									}
								}
								else if (Seguro2 == 'A' || Seguro2 == 'a')
								{
									Contador--;
									Cont1 = prestado1[Contador-1], Cont2 = prestado2[Contador-1], Cont3 = prestado3[Contador-1], Cont4 = prestado4[Contador-1], Cont5 = prestado5[Contador-1], Validar2 = 0;
									Validar2 = Validar22[Contador-1];		
	        						cout<<"\nUsuario Ingresando...";										
								}
								else
								{
									cout<<"\nVolviendo al menu...";
								}
							}
						}
						else
						{
							cout<<"Volviendo al menu...";
						}
					}
					if(Contador > NMay)
					{
						NMay = Contador;
					}			
					system("pause");
	        		system("cls");
		    	break;
	       		case 6: 
					if(Contador > NMay)
					{
						NMay = Contador;
					}			   
					infoFinal(name, apellido, cedula, Telefono, Validar, Contador, NMay, C1, C2, C3, C4, C5, CC1, CC2, CC3, CC4, CC5, fechaentrega);
       				system("pause");
       				system("cls");
				break;	        		
	        	case 7:cout<<"\nSaliendo del Programa...";
				break;
	        	default:cout<<"Opcion no existe";
			}	
		}while (Op!=7);	
  	}
}

int NuevoPresta(string name1 [], string apelli[], string ced [], string Tele[], int Cont, int Prestado1, int Prestado2, int Prestado3, int Prestado4, int Prestado5, int Validar[]){
	system("cls");
	int Op, Num = 0, C,Prestado;
	string name;
	char Op2;
	cout << "Bienvenido usuario #" << Cont << endl;
	if(Validar[Cont-1] == 0)
	{
		cout << "Ingrese su/s nombre/s: ";
		getline(cin, name1[Cont-1]);
		cout << "Ingrese su primer apellido: ";
		getline(cin, apelli[Cont-1]);
		cout << "Ingrese su numero de cedula: ";
		getline(cin, ced[Cont-1]);
		cout << "Ingrese su telefono fijo (7 digitos): ";
		getline(cin, Tele[Cont-1]); 

		cout<<"\n";
	}
	do
	{
		cout<<"Que genero desea alquilar? (Solo puede alquilar 3 libros maximo)"<<endl;
	    cout << "1. Ciencia Ficcion" << endl;
	    cout << "2. Fantasia" << endl;
	    cout << "3. Misterio" << endl;
	    cout << "4. Terror" << endl;
	    cout << "5. Medieval" << endl;
	    do{
		    cout<<"Digite: ";
		    cin>>Op;
		}while(Op < 1 || Op > 5);
		switch(Op)
		{
			case 1: name = "Ciencia Ficcion";
					Prestado = Prestado1;
					C = 1;
			break;
			case 2: name = "Fantasia";
					Prestado = Prestado2;
					C = 2;
			break;
			case 3: name = "Misterio";
					Prestado = Prestado3;
					C = 3;
			break;
			case 4: name = "Terror";
					Prestado = Prestado4;
					C = 4;
			break;
			case 5: name = "Medieval";
					Prestado = Prestado5;
					C = 5;
		}
	    cout<<"\n";
	    
		if(Prestado == 0)
		{
			cout<<"No hay disponible libros del genero "<<name;
			Op = 0;
		}
		else
		{
			if(Prestado == 1)
			{
				cout<<"\nHay un libro disponible del genero Ciencia Ficcion, desea alquilarlo? Digite S, si se arrepintio de la eleccion digite N";
			}
			else
			{
				cout<<"\nHay "<<Prestado<<" libros del genero "<<name<<", desea alquilar alguno? Digite S, si quiere volver al menu digite N";
			}
			cout<<"\nDigite: ";
			cin>>Op2;
			cout<<"\n";
			Op = 0;
			if(Op2 == 'S' || Op2 == 's')
			{
				cout<<"Libro de "<<name<<" alquilado satisfactoriamente.\n";
				Num = C;
			}
			else
			{
				cout<<"Volviendo al menu...";
			}
		}
	}while(Op != 0);
	system("pause");
	return Num;
}

void ConsulPena(string name [], string apelli [], string ced [], int penalizacion [], string Tele[], int Cont, int prestado1[], int prestado2[], int prestado3[], int prestado4[], int prestado5[]){
	system("cls");
	cout<<"CONSULTA DE PENALIZACION"<<endl;
	cout<<"BIENVENIDO"<<endl;
	cout<<"Nombre: "<<name[Cont-1]<<endl;
	cout<<"Apellido: "<<apelli[Cont-1]<<endl;
	cout<<"Cedula: "<<ced[Cont-1]<<endl;
	cout<<"Telefono: "<<Tele[Cont-1]<<endl;
	if(penalizacion[Cont-1] == 0)
	{
		cout<<"ESTADO: Usted no esta penalizado, puede seguir mirando los diferentes generos de libros y seguir alquilando."<<endl;
	}
	else if(penalizacion[Cont-1] == 1)
	{
		cout<<"ESTADO: Usted esta penalizado, debera realizar el tramite de devolucion en la seccion 4 del menu."<<endl;
		cout<<"Usted debe devolver al menos un libro de estos para dejar de estar penalizado: "<<endl<<endl;
		if(prestado1[Cont-1] > 0)
		{
			cout<<"CIENCIA FICCION: "<<prestado1[Cont-1]<<endl;
		}
		if(prestado2[Cont-1] > 0)
		{
			cout<<"FANTASIA: "<<prestado2[Cont-1]<<endl;
		}
		if(prestado3[Cont-1] > 0)
		{
			cout<<"MISTERIO: "<<prestado3[Cont-1]<<endl;
		}
		if(prestado4[Cont-1] > 0)
		{
			cout<<"TERROR: "<<prestado4[Cont-1]<<endl;
		}
		if(prestado5[Cont-1] > 0)
		{
			cout<<"MEDIEVAL: "<<prestado5[Cont-1]<<endl;
		}							
		cout<<"\n";		
	}
	
}

int Devo(string name [], string apelli [], string ced [], string Tele[], int Cont, int prestado1[], int prestado2[], int prestado3[], int prestado4[], int prestado5[]){
	system("cls");
	int Op;
	int Centinela[10], R = 0;
	cout<<"PANEL DE DEVOLUCION DE LIBROS\n"<<endl;
	cout<<"LIBROS QUE TE PRESTARON Y PENDIENTES A DEVOLVER: "<<endl;
	if(prestado1[Cont-1] > 0)
	{
		cout<<"1. CIENCIA FICCION - CANTIDAD: "<<prestado1[Cont-1]<<endl;
		Centinela[1] = 1;
	}
	if(prestado2[Cont-1] > 0)
	{
		cout<<"2. FANTASIA - CANTIDAD: "<<prestado2[Cont-1]<<endl;
		Centinela[2] = 2;
	}
	if(prestado3[Cont-1] > 0)
	{
		cout<<"3. MISTERIO - CANTIDAD: "<<prestado3[Cont-1]<<endl;
		Centinela[3] = 3;
	}
	if(prestado4[Cont-1] > 0)
	{
		cout<<"4. TERROR - CANTIDAD: "<<prestado4[Cont-1]<<endl;
		Centinela[4] = 4;
	}
	if(prestado5[Cont-1] > 0)
	{
		cout<<"5. MEDIEVAL - CANTIDAD: "<<prestado5[Cont-1]<<endl;
		Centinela[5] = 5;
	}
	cout<<"\nDigite el numero que aparece antes del genero, para devolver 1 libro correspondiente a este.";	
	do{
		do{
			cout<<"\nDigite: ";
			cin>>Op;
		}while(Op < 1 || Op > 5);
		if(Centinela[Op] == Op)
		{
			R = 1;
			cout<<"\nLibro devuelto correctamente."<<endl;
		}
	}while(R == 0);
	for(int r = 0; r < 10 ; r++)
	{
		Centinela[r] = 0;
	}
	
	return(Op);
			
}

int Modientre(string name[], string apelli[], string ced[], string Tele[], int Cont, int fechas[]){
	system("cls");
	int plazo;
	cout<<"MODIFICADOR DE FECHAS DE ENTREGA\n\n";
	cout<<"El plazo estandar es de 15 dias de entrega desde el alquiler de cualquier libro. Digite cuanto desea aumentar el plazo segun: \n\n";
	cout << "1. 5 dias\n" << endl;
	cout << "2. 10 dias \n" << endl;
	cout << "3. 15 dias\n" << endl;
	do{
		cout<<"Digite: ";
		cin>>plazo;
	}while(plazo < 1 || plazo > 3);
	cout<<"\n\nPlazo aumentado.";
	return(plazo);
}

void MenuPrincipal(){
		cout << "******************************" << endl;
        cout << "****** Menu de Opciones ******" << endl;
        cout << "******************************" << endl << endl;
        cout << "1. Nuevo Prestamo de Libro " << endl;
        cout << "2. Consultar Penalizaciones" << endl;
        cout << "3. Modificar Tiempo de Entrega" << endl;
        cout << "4. Devolucion de libro" << endl;
        cout << "5. Nuevo Usuario" << endl;
        cout << "6. Historial de la Biblioteca" << endl;
        cout << "7. Salir" << endl;        
}

void infoFinal(string name [], string apelli[], string ced[], string Tele[], int Validar[], int Cont, int ContAux, int devuelto1, int devuelto2, int devuelto3, int devuelto4, int devuelto5, int PrestadoGenero1, int PrestadoGenero2, int PrestadoGenero3, int PrestadoGenero4, int PrestadoGenero5, int fechaentrega[])
{
	system("cls");
	cout<<"ESTADISTICAS GLOBALES DE LA BIBLIOTECA\n";
	cout<<"Datos de los Usuarios: \n\n";
	if(Validar[Cont-1] == 0)
	{
		cout<<"El usuario #"<<Cont<<" no ha registrado sus datos en la primer opcion del menu.\n";
	}
	else
	{
		for(int i = 0 ; i < ContAux ; i++)
		{
			cout<<"Nombre del usuario #"<<i+1<<": "<<name[i]<<endl;
			cout<<"Apellido del usuario #"<<i+1<<": "<<apelli[i]<<endl;
			cout<<"Cedula del usuario #"<<i+1<<": "<<ced[i]<<endl;
			cout<<"Telefono del usuario #"<<i+1<<": "<<Tele[i]<<endl;
			if(fechaentrega[i] == 5){
				cout<<name[i]<<" tiene un plazo estandar de 15 dias para devolver los libros pendientes que tiene prestados a la biblioteca.\n";
			}
			else if(fechaentrega[i] == 4){
				cout<<name[i]<<" ha entregado todos los libros que le han prestado en la biblioteca.\n";
			}
			else if(fechaentrega[i] == 3){
				cout<<name[i]<<" tiene un plazo extendido de 30 dias para devolver los libros pendientes que tiene prestados a la biblioteca.\n";
			}
			else if(fechaentrega[i] == 2){
				cout<<name[i]<<" tiene un plazo extendido de 25 dias para devolver los libros pendientes que tiene prestados a la biblioteca.\n";
			}	
			else if(fechaentrega[i] == 1){
				cout<<name[i]<<" tiene un plazo extendido de 20 dias para devolver los libros pendientes que tiene prestados a la biblioteca.\n";
			}
			cout<<"\n";	
		}
	}
	cout<<"\nEstadistica De la Biblioteca: \n\n";
	cout << "Libros de Ciencia Ficcion prestados: "<<PrestadoGenero1;
	cout << "\nLibros de Fantasia prestados:" <<PrestadoGenero2;
	cout << "\nLibros de Misterio prestados:" <<PrestadoGenero3;
	cout << "\nLibros de Terror prestados:" <<PrestadoGenero4;
	cout << "\nLibros de Medieval prestados:" <<PrestadoGenero5<< endl<<endl;
	cout << "Libros de Ciencia Ficcion devueltos: "<<devuelto1;
	cout << "\nLibros de Fantasia devueltos:" <<devuelto2;
	cout << "\nLibros de Misterio devueltos:" <<devuelto3;
	cout << "\nLibros de Terror devueltos:" <<devuelto4;
	cout << "\nLibros de Medieval devueltos:" <<devuelto5<<endl;
	cout << "\nUsuarios Ingresados el dia de hoy: " <<ContAux<<endl<<endl;
	
}

int login() {
  int intentos = 0, r = 0;
  string user;
  string pass;  
  bool band=false;  
  cout<<"INICIO DE SESION DE LA MAQUINA"<<endl<<endl;
    while(band == false)
	{
		intentos++;
		cout << "Digite usuario: ";
	    getline(cin, user);
	    fflush(stdin);
	    cout << "Digite contrasena: ";
	    getline(cin, pass);
	    fflush(stdin);
	    if (user == "admin" && pass == "123")
	    {
	    	band = true;
	    	r = 1;
		}
	    else if (user != "admin" || pass != "123")
	    {
	    	cout << "\nDatos Incorrectos."<<endl;
	    	if(intentos == 3){
	    		cout << "Tiene un ultimo intento"<<endl;
			}
			else if(intentos == 4){
				cout << "Ya no posee intentos"<<endl;
				band = true;
			}
			else
			{
				cout << "Tiene "<<4-intentos<<" intentos."<<endl;
			}
	    	cout<<"\n";
		}  
	    if(intentos == 4)
	    {
	    	cout << "Ya hizo demasiados intentos, regrese mas tarde."<<endl;
	    	system("pause"); 	
		}
  	}
  	system("cls");
  	return(r); 	
}

