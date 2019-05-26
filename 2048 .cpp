#include<iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<iomanip>

using namespace std;
void jugar(int mat[][4], int &puntaje,int &,bool &,int &,int copia[][4]);
void movimientos(int mat[][4], int &puntaje,int &,bool &);
void recorrerArr(int mat[][4], int &puntaje);
void recorrerBaj(int mat[][4], int &puntaje);
void recorrerIzq(int mat[][4], int &puntaje);
void recorrerDer(int mat[][4], int &puntaje);
int compararMatriz(int mat[][4],int copia[][4]);
void copiarMatriz(int mat[][4],int copia[][4]);
void anuncios(int mat[][4],int &);
void bienvenida();
void instrucciones();
void ImprimirTablero(int matriz[][4]);
void limpiarMat(int matriz[][4]);
void InsertarTablero(int matriz[][4], int &puntaje,int &,bool &,int &);
bool Fin(int matriz[][4], int &,int &,int &);
int numeroRandom1();
int numeroRandom2();
int main(){
    srand(time(NULL));
    int matriz[4][4];
    int copia[4][4];
    int puntaje=0;
    int numMax=0;
	int how = 0;
	bool flag=false;
	int partidas=1;
	limpiarMat(matriz);
	string nombre;
	bienvenida();
	cout<<"\n                  Te gustaria conocer las reglas del juego?\n";
	cout<<"\nSi = 1";
	cout<<"\nNo = 2\n\n";
	cin>>how;
	if(how==1){
            system("cls");
            instrucciones();
	}
    cin.ignore();
	cout<<"\nDigite su nombre: ";
	getline(cin, nombre);
    while(partidas==1){         //Ciclo while para validar si el jugador quiere seguir jugando.
        limpiarMat(matriz);         //Funcion que pone todos los valores en 0 del arreglo
        puntaje=0;                  //Se reestablece el puntaje a 0
        jugar(matriz,puntaje,partidas,flag,numMax,copia);     //Funcion donde se ejecuta el juego
    }
	return 0;
}
void InsertarTablero(int matriz[][4], int &puntaje, int &partidas,bool &flag,int &numMax){
    int dato1 = 0;
    int dato2 = 0;
    dato1 = numeroRandom1();
    dato2 = numeroRandom2(); // 1,2,3 = 2 || 4,5 = 4
    if(matriz[0][0]!=0&&matriz[0][1]!=0&&matriz[0][2]!=0&&matriz[0][3]!=0&&matriz[1][0]!=0&&matriz[1][1]!=0&&matriz[1][2]!=0&&matriz[1][3]!=0&&matriz[2][0]!=0&&matriz[2][1]!=0&&matriz[2][2]!=0&&matriz[2][3]!=0&&matriz[3][0]!=0&&matriz[3][1]!=0&&matriz[3][2]!=0&&matriz[3][3]!=0){
        movimientos(matriz,puntaje,partidas,flag);                //If gigante y no se como optimizarlo para que si esta lleno el arreglo y todo sea diferente de cero, intente realizar movimientos para seguir jugando
        Fin(matriz, partidas,puntaje,numMax);                      //En caso de que ya no se pueda seguir de ninguna manera, el juego termina
    }
    if(dato1==1){
        if(matriz[0][0]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if(dato2==1 || dato2==2 || dato2==3){
                matriz[0][0] = 2;
            }else if (dato2==4 || dato2==5){
                matriz[0][0] = 4;
            }
        }
    }
    if(dato1==2){
        if(matriz[0][1]!=0){
            InsertarTablero(matriz,puntaje, partidas,flag,numMax);
        }else{
            if(dato2==1 || dato2==2 || dato2==3){
            matriz[0][1] = 2;
            }else if (dato2==4 || dato2==5){
            matriz[0][1] = 4;
            }
        }
    }
    if(dato1==3){
        if(matriz[0][2]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if(dato2==1 || dato2==2 || dato2==3){
            matriz[0][2] = 2;
            }else if (dato2==4|| dato2==5){
            matriz[0][2] = 4;
            }
        }
    }
    if(dato1==4){
        if(matriz[0][3]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if(dato2==1 || dato2==2|| dato2==3){
            matriz[0][3] = 2;
            }else if (dato2==4 || dato2==5){
            matriz[0][3] = 4;
            }
        }
    }
    if(dato1==5){
        if(matriz[1][0]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if(dato2==1 || dato2==2 || dato2==3){
            matriz[1][0] = 2;
            }else if ( dato2==4 || dato2==5){
            matriz[1][0] = 4;
            }
        }
    }
    if(dato1==6){
        if(matriz[1][1]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if(dato2==1 || dato2==2 || dato2==3){
            matriz[1][1] = 2;
            }else if(dato2==4 || dato2==5){
            matriz[1][1] = 4;
            }
        }
    }
    if(dato1==7){
        if(matriz[1][2]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if(dato2==1 || dato2==2 || dato2==3){
            matriz[1][2] = 2;
            }else if (dato2==4 || dato2==5){
            matriz[1][2] = 4;
            }
        }
    }
    if(dato1==8){
        if(matriz[1][3]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if(dato2==1 || dato2==2 || dato2==3){
            matriz[1][3] = 2;
            }else if ( dato2==4 || dato2==5){
            matriz[1][3] = 4;
            }
        }
    }
    if(dato1==9){
        if(matriz[2][0]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if( dato2==1 || dato2==2 || dato2==3){
            matriz[2][0] = 2;
            }else if ( dato2==4 || dato2==5 ){
            matriz[2][0] = 4;
            }
        }
    }
    if(dato1==10){
        if(matriz[2][1]!=0){
        InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if( dato2==1 || dato2==2|| dato2==3 ){
            matriz[2][1] = 2;
            }else if ( dato2==4|| dato2==5 ){
            matriz[2][1] = 4;
            }
        }
    }
    if(dato1==11){
        if(matriz[2][2]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if( dato2==1 || dato2==2|| dato2==3 ){
            matriz[2][2] = 2;
            }else if ( dato2==4 || dato2==5){
            matriz[2][2] = 4;
            }
        }
    }
    if(dato1==12){
        if(matriz[2][3]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if( dato2==1 || dato2==2 || dato2==3){
            matriz[2][3] = 2;
            }else if ( dato2==4 || dato2==5){
            matriz[2][3] = 4;
            }
        }
    }
    if(dato1==13){
        if(matriz[3][0]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if( dato2==1 || dato2==2 || dato2==3){
            matriz[3][0] = 2;
            }else if ( dato2==4 || dato2==5){
            matriz[3][0] = 4;
            }
        }
    }
    if(dato1==14){
        if(matriz[3][1]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if( dato2==1 || dato2==2 || dato2==3){
            matriz[3][1] = 2;
            }else if ( dato2==4 || dato2==5){
            matriz[3][1] = 4;
            }
        }
    }
    if(dato1==15){
        if(matriz[3][2]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if( dato2==1 || dato2==2 || dato2==3){
            matriz[3][2] = 2;
            }else if ( dato2==4 || dato2==5 ){
            matriz[3][2] = 4;
            }
        }
    }
    if(dato1==16){
        if(matriz[3][3]!=0){
            InsertarTablero(matriz,puntaje,partidas,flag,numMax);
        }else{
            if( dato2==1 || dato2==2 || dato2==3){
            matriz[3][3] = 2;
            }else if ( dato2==4 || dato2==5){
            matriz[3][3] = 4;
            }
        }
    }
}
bool Fin(int matriz[][4],int &partidas,int &puntaje,int &numMax){
    int over = 0;
    if(matriz[0][0] !=0 && matriz[0][0] != matriz[0][1] && matriz[0][0] != matriz[1][0]){
            over++;
    }
    if(matriz[0][1] !=0 && matriz[0][1] !=  matriz[0][2] && matriz[0][1] != matriz[1][1] ){
            over++;
    }
    if(matriz[0][2] !=0 && matriz[0][2] !=  matriz[0][3] && matriz[0][2] != matriz[1][2]){
            over++;
    }
    if(matriz[0][3] !=0 && matriz[0][3] !=  matriz[1][3]){
            over++;
    }
    if(matriz[1][0] !=0 && matriz[1][0] !=  matriz[1][1] && matriz[1][0] != matriz[2][0]){
            over++;
    }
    if(matriz[1][1] !=0 && matriz[1][1] !=  matriz[1][2] && matriz[1][1] != matriz[2][1]){
            over++;
    }
    if(matriz[1][2] !=0 && matriz[1][2] !=  matriz[1][3] && matriz[1][2] != matriz[2][2]){
            over++;
    }
    if(matriz[1][3] !=0 && matriz[1][3] != matriz[2][3]){
            over++;
    }
    if(matriz[2][0] !=0 && matriz[2][0] !=  matriz[2][1] && matriz[2][0] != matriz[3][0]){
            over++;
    }
    if(matriz[2][1] !=0 && matriz[2][1] !=  matriz[2][2] && matriz[2][1] != matriz[3][1]){
            over++;
    }
    if(matriz[2][2] !=0 && matriz[2][2] !=  matriz[2][3] && matriz[2][2] != matriz[3][2]){
            over++;
    }
    if(matriz[0][1] !=0 && matriz[0][1] !=  matriz[0][2] && matriz[0][1] != matriz[1][1]){
            over++;
    }
    if(matriz[2][3] !=0 && matriz[2][3] !=  matriz[3][3]){
            over++;
    }
    if(matriz[3][0] !=0 && matriz[3][0] !=  matriz[3][1] && matriz[3][1] != matriz[3][2] && matriz[3][2] != matriz[3][3]){
            over++;
    }
    if(over==14){
        cout<<"\n\n\t\tGAME OVER\t\t\n";
        cout<<"Tu puntaje maximo fue : "<<puntaje<<endl;
        cout<<"El numero mas alto obtenido fue: "<<numMax<<endl;
        cout<<"\nDesea volver a jugar?\n1.-Intentar de nuevo/Jugar de Nuevo\n2.-Salir\n";
        cin>>partidas;                      //Si el jugador inserta un 1, volvera a jugar, en caso contrario, terminara el programa
        return true;                        //La funcion regresa un bool para terminar el juego adecuadamente
    }
}
void ImprimirTablero(int matriz[][4]){
	for( int i = 0; i < 4; i++ ){
	    cout << "+---+---+---+---+---+---+---+---+" << endl << "| ";
	    for( int j = 0; j < 4; j++ ){
            cout<< setw(3) <<matriz[i][j]<<"  ";
            cout << " | ";
	    }
	    cout << endl;
	}
	cout << "+---+---+---+---+---+---+---+---+" << endl << endl;
}
int numeroRandom1(){
    int dato1;
    dato1 = rand()%16+1;
    return dato1;

}
int numeroRandom2(){
    int dato2;
    dato2 = rand()%5+1;
    return dato2;
}
void movimientos(int mat[][4], int &puntaje,int &partidas,bool &flag){
        cout<<"Para mover, utilice las flechas\n\t^\n<\t\t>\n\tv\nPara abandonar la partida, presione la tecla ESC\n";
        int c=getch();                  //Sirve para captar la tecla que se presiono del teclado
        const int KEY_UP =72;           //KEY UP y sus variantes, toman el valor de la tecla, el valor inicial que es OxCE o algo parecido,
        const int KEY_DOWN =80;         //Los numeros son el verdadero valor ascii para poder usar dichas teclas
        const int KEY_LEFT =75;
        const int KEY_RIGHT =77;
        const int ESC=27;
        switch((c=getch())) {
        case KEY_UP:{
            recorrerArr(mat,puntaje);
            ImprimirTablero(mat);
            break;
        }
        case KEY_DOWN:{
            recorrerBaj(mat,puntaje);
            ImprimirTablero(mat);
            break;
        }
        case KEY_LEFT:{
            recorrerIzq(mat,puntaje);
            ImprimirTablero(mat);
            break;
        }
        case KEY_RIGHT:{
            recorrerDer(mat,puntaje);
            ImprimirTablero(mat);
            break;
        }
        case ESC:{
            cout<<"Saliendo de la partida\n";
            partidas=2;
            flag=true;
            break;
        }
        default:
            cout << endl << "Tecla invalida" << endl;
            break;
        }
}
void limpiarMat(int matriz[][4]){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            matriz[i][j] = 0;
        }
    }
}
void instrucciones(){
        cout<<"################################################################################################################\n";
        cout<<"\nEl objetivo del juego es obtener el numero 2048 usando adiciones del numero dos y sus multiplos.\n";
		cout<<"\nTendras una grilla de 16 fichas. Se daran dos numeros: generalmente dos numeros dos, tal vez el numero cuatro.\n";
		cout<<"\nMover hacia arriba o hacia abajo, hacia la izquierda o hacia la derecha\n";
		cout<<"tratando de unir dos numeros iguales.\n";
		cout<<"\nCuando dos numeros iguales estan en contacto, se sumaran.\n";
		cout<<"\nSi nos quedan numeros iguales en nuestra grilla, o no podemos ponerlos en\n";
		cout<<"contacto, el juego nos proporcionara otros dos, un cuatro o incluso un ocho\n";
		cout<<"para que podamos seguir jugando. Si no hay fichas gratis en nuestra grilla,\n";
		cout<<"el juego termina.\n";
		cout<<"\nAl sumar numeros, obtenemos numeros mas altos y podemos acercarnos a 2048, que es el objetivo del juego\n";
		cout<<"################################################################################################################\n";
}
void recorrerBaj(int mat[][4], int &puntaje){
    for(int i=3;i>=0;i--){                          //Primer for, recorre todos los valores del arreglo una linea abajo, excepto la de hasta abajo y sus variantes, pues si se incluye se desfasa
        for(int j=3;j>=0;j--){
            if(mat[i][j]!=0 && mat[i+1][j]==0){
                mat[i+1][j]=mat[i][j];
                mat[i][j]=0;
            }
        }
    }
    for(int i=3;i>=0;i--){                          //Se recorren todos los valores del arreglo una linea abajo
        for(int j=3;j>=0;j--){
            if(mat[i][j]!=0&& mat[i+1][j]==0){
                mat[i+1][j]=mat[i][j];
                mat[i][j]=0;
            }
            if(mat[i][j] == mat[i+1][j]){                   //Condicional que hace la suma y ademas cuenta puntaje
                mat[i+1][j]+=mat[i][j];
                puntaje+=mat[i+1][j];
                mat[i][j]=0;
            }
            for(int i=3;i>=0;i--){                          //Se recorren todos los valores del arreglo una linea abajo
                for(int j=3;j>=0;j--){
                    if(mat[i][j]!=0&& mat[i+1][j]==0){
                        mat[i+1][j]=mat[i][j];
                        mat[i][j]=0;
                    }
                }
            }
        }
    }
    for(int i=3;i>=0;i--){                              //Se recorren todos los valores del arreglo una linea abajo
        for(int j=3;j>=0;j--){
            if(mat[i][j]!=0&& mat[i+1][j]==0){
                mat[i+1][j]=mat[i][j];
                mat[i][j]=0;
            }
        }
    }
}
void recorrerArr(int mat[][4], int &puntaje){       //Primer for que recorre todos los valores del arreglo una linea arriba
    for(int i=1;i<=3;i++){
        for(int j=0;j<=3;j++){
            if(mat[i][j]!=0 && mat[i-1][j]==0){
                mat[i-1][j]=mat[i][j];
                mat[i][j]=0;
            }
        }
    }
    for(int i=1;i<=3;i++){                          //Segundo for donde se recorren los valores del arreglo excepto la primer linea, para evitar desfasamiento
        for(int j=0;j<=3;j++){
            if(mat[i][j]!=0&& mat[i-1][j]==0){
                mat[i-1][j]=mat[i][j];
                mat[i][j]=0;
            }
        }
    }
    for(int i=1;i<=3;i++){
        for(int j=0;j<=3;j++){
            if(mat[i][j]!=0&& mat[i-1][j]==0){
                mat[i-1][j]=mat[i][j];
                mat[i][j]=0;
            }
            if(mat[i][j] == mat[i-1][j]){               //Condicional donde valida si los valores son iguales para sumarlos
                mat[i-1][j]+=mat[i][j];                 //Valores sumando en puntaje
                puntaje+=mat[i-1][j];
                mat[i][j]=0;
            }
            for(int i=1;i<=3;i++){                          //Segundo for donde se recorren los valores del arreglo excepto la primer linea, para evitar desfasamiento
                for(int j=0;j<=3;j++){
                    if(mat[i][j]!=0&& mat[i-1][j]==0){
                        mat[i-1][j]=mat[i][j];
                        mat[i][j]=0;
                    }
                }
            }
        }
    }
}
void recorrerDer(int mat[][4], int &puntaje){               //Primer for que recorre los elementos del arreglo a la derecha
    for(int i=3;i>=0;i--){
        for(int j=2;j>=0;j--){
            if(mat[i][j]!=0 && mat[i][j+1]==0){
                mat[i][j+1]=mat[i][j];
                mat[i][j]=0;
            }
        }
    }
    for(int i=3;i>=0;i--){
        for(int j=2;j>=0;j--){
            if(mat[i][j]!=0 && mat[i][j+1]==0){
                mat[i][j+1]=mat[i][j];
                mat[i][j]=0;
            }
            if(mat[i][j] == mat[i][j+1]){
                mat[i][j+1]+=mat[i][j];
                puntaje+=mat[i][j+1];
                mat[i][j]=0;
            }
            for(int i=3;i>=0;i--){
                for(int j=2;j>=0;j--){
                    if(mat[i][j]!=0 && mat[i][j+1]==0){
                        mat[i][j+1]=mat[i][j];
                        mat[i][j]=0;
                    }
                }
            }
        }
    }
    for(int i=3;i>=0;i--){
        for(int j=2;j>=0;j--){
            if(mat[i][j]!=0 && mat[i][j+1]==0){
                mat[i][j+1]=mat[i][j];
                mat[i][j]=0;
            }
        }
    }
}
void recorrerIzq(int mat[][4], int &puntaje){           //Recorre los valores a la izquierda
    for(int i=0;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(mat[i][j]!=0 && mat[i][j-1]==0){
                mat[i][j-1]=mat[i][j];
                mat[i][j]=0;
            }
        }
    }
    for(int i=0;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(mat[i][j]!=0 && mat[i][j-1]==0){
                mat[i][j-1]=mat[i][j];
                mat[i][j]=0;
            }
        }
    }
    for(int i=0;i<=3;i++){
        for(int j=1;j<=3;j++){
            if(mat[i][j]!=0 && mat[i][j-1]==0){
                mat[i][j-1]=mat[i][j];
                mat[i][j]=0;
            }
            if(mat[i][j] == mat[i][j-1]){
                mat[i][j-1]+=mat[i][j];
                puntaje+=mat[i][j-1];
                mat[i][j]=0;
            }
            for(int i=0;i<=3;i++){
                for(int j=1;j<=3;j++){
                    if(mat[i][j]!=0 && mat[i][j-1]==0){
                        mat[i][j-1]=mat[i][j];
                        mat[i][j]=0;
                    }
                }
            }
        }
    }
}
void jugar(int mat[][4], int &puntaje,int &partidas,bool &flag,int &numMax,int copia[][4]){
    InsertarTablero(mat,puntaje,partidas,flag,numMax);              //Al principio del juego simepre se insertan dos valores random
    InsertarTablero(mat,puntaje,partidas,flag,numMax);
    ImprimirTablero(mat);
    while(true){
        if(!Fin(mat,partidas,puntaje,numMax)){                        //Despues de eso solo se va insertando uno despues de cada movimiento
            copiarMatriz(mat,copia);
            movimientos(mat,puntaje,partidas,flag);
            if(flag){
                cout<<"#     #    #     #####  #######    #       #       #     # #######  #####  #######\n";
                cout<<"#     #   # #   #     #    #      # #      #       #     # #       #     # #     #\n";
                cout<<"#     #  #   #  #          #     #   #     #       #     # #       #       #     #\n";
                cout<<"####### #     #  #####     #    #     #    #       #     # #####   #  #### #     #\n";
                cout<<"#     # #######       #    #    #######    #       #     # #       #     # #     #\n";
                cout<<"#     # #     # #     #    #    #     #    #       #     # #       #     # #     #\n";
                cout<<"#     # #     #  #####     #    #     #    #######  #####  #######  #####  #######\n";
                break;
            }else{
                if(compararMatriz(mat,copia)==16){
                system("cls");
                ImprimirTablero(mat);
                }else{
                    InsertarTablero(mat,puntaje,partidas,flag,numMax);
                    system("cls");
                    ImprimirTablero(mat);
                    puntaje=puntaje;
                    cout<<"Este es tu puntaje: "<<puntaje<<endl;
                    anuncios(mat,numMax);
                }
            }
        }else{
            break;
        }
    }
}
void anuncios(int mat[][4],int &numMax){
    bool _16=false;
    bool _32=false;
    bool _64=false;
    bool _128=false;
    bool _256=false;
    bool _512=false;
    bool _1024=false;
    bool _2048=false;
    bool _4096=false;
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            if(mat[i][j]==16){
                _16=true;
            }else if(mat[i][j]==32){
                _32=true;
            }else if(mat[i][j]==64){
                _64=true;
            }else if(mat[i][j]==128){
                _128=true;
            }else if(mat[i][j]==256){
                _256=true;
            }else if(mat[i][j]==512){
                _512=true;
            }else if(mat[i][j]==1024 ){
                _1024=true;
            }else if(mat[i][j]==2048){
                _2048=true;
            }else if(mat[i][j]==4096){
                _4096=true;
            }
        }
    }
    if(_16 &&!_32 &&!_64 &&!_128 &&!_256 &&!_512 && !_1024 && !_2048 && !_4096){
            numMax=16;
    }else if(_32 &&!_64 &&!_128 &&!_256 &&!_512 && !_1024 && !_2048 && !_4096){
            numMax=32;
    }else if(_64 &&!_128 &&!_256 &&!_512 && !_1024 && !_2048 && !_4096){
        numMax=64;
    }else if(_128 &&!_256 &&!_512 && !_1024 && !_2048 && !_4096){
            numMax=128;
    }else if(_256 &&!_512 && !_1024 && !_2048 && !_4096){
        numMax=256;
    }else if(_512 && !_1024 && !_2048 && !_4096){
        cout<<"Felicidades, lograste alcanzar 512!!\n";
        numMax=512;
    }else if((_512 && _1024 && !_2048 && !_4096) || (!_512 && _1024 && !_2048 && !_4096) ){
        cout<<"Felicidades, avanzaste y alcanzaste 1024!!\n";
        numMax=1024;
    }else if((_512 && _1024 && _2048 && !_4096) || (!_512 && _1024 && _2048 && !_4096) || (_512 && !_1024 && _2048 && !_4096) || (!_512 && !_1024 && _2048 && !_4096)){
        cout<<"FELICIDADES, HAS CONSEGUIDO GANAR EL JUEGO CONSIGUIENDO UN 2048, CONTINUA SI ES QUE PUEDES!!!\n";
        numMax=2048;
    }else if((_512 && _1024 && _2048 && _4096) || (!_512 && _1024 && _2048 && _4096) || (_512 && !_1024 && _2048 && _4096) ||(_512 && _1024 && !_2048 && _4096) || (!_512 && !_1024 && !_2048 && _4096) || (!_512 && !_1024 && _2048 && _4096) || (_512 && !_1024 && !_2048 && _4096)||(!_512 && _1024 && !_2048 && _4096)){
        cout<<"INCREIBLE, LOGRASTE LLEGAR A 4096, ERES UN DIGNO JUGADOR\n";
        numMax=4096;
    }
}
void bienvenida(){
    cout<<" 222222222222222         000000000            444444444       888888888     \n";
    cout<<"2:::::::::::::::22     00:::::::::00         4::::::::4     88:::::::::88   \n";
    cout<<"2::::::222222:::::2  00:::::::::::::00      4:::::::::4   88:::::::::::::88 \n";
    cout<<"2222222     2:::::2 0:::::::000:::::::0    4::::44::::4  8::::::88888::::::8\n";
    cout<<"            2:::::2 0::::::0   0::::::0   4::::4 4::::4  8:::::8     8:::::8\n";
    cout<<"            2:::::2 0:::::0     0:::::0  4::::4  4::::4  8:::::8     8:::::8\n";
    cout<<"    22222::::::22   0:::::0 000 0:::::04::::444444::::444  8:::::::::::::8  \n";
    cout<<"  22::::::::222     0:::::0 000 0:::::04::::::::::::::::4 8:::::88888:::::8 \n";
    cout<<" 2:::::22222        0:::::0     0:::::04444444444:::::4448:::::8     8:::::8\n";
    cout<<"2:::::2             0:::::0     0:::::0          4::::4  8:::::8     8:::::8\n";
    cout<<"2:::::2             0::::::0   0::::::0          4::::4  8:::::8     8:::::8\n";
    cout<<"2:::::2       2222220:::::::000:::::::0          4::::4  8::::::88888::::::8\n";
    cout<<"2::::::2222222:::::2 00:::::::::::::00         44::::::44 88:::::::::::::88 \n";
    cout<<"2::::::::::::::::::2   00:::::::::00           4::::::::4   88:::::::::88   \n";
    cout<<"22222222222222222222     000000000             4444444444     888888888  \n";
    cout<<"-----------------------------------------------------------------------------";
}
void copiarMatriz(int mat[][4],int copia[][4]){
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            copia[i][j] = mat[i][j];
        }
    }
}
int compararMatriz(int mat[][4],int copia[][4]){
    int cont = 0;
    for(int i = 0; i<4; i++){
        for(int j = 0; j<4; j++){
            if(copia[i][j] == mat[i][j]){
                cont++;
            }
        }
    }
    return cont;
}
