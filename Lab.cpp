#include <iostream>
#include <ctime>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

void menuFun();
void ejercicio1Resp(int);
int ejercicio1RespIntentos(int,int);
void arrayOrdering(int[],int,int);

int main(int argc, char const *argv[])
{
	int const arrayIntentosSizeMain=10;
	int const arraySTATSSizeMainFILAS=4;
	int const arraySTATSSizeMainCOL=3;
	int const arraySTATSJUGSizeMainFILAS=2;
	int const arraySTATSJUGSizeMainCOL=3;
	int arraySTATSJUG[arraySTATSJUGSizeMainFILAS][arraySTATSJUGSizeMainCOL];
	int arrayScore[arrayIntentosSizeMain]={100,100,100,100,100,100,100,100,100,100};
	int arraySTATS[arraySTATSSizeMainFILAS][arraySTATSSizeMainCOL];
	menuFun();
	int respMEnMain, numeroIntentoMain, numeroResultadoMain,numeroScore=0;
	char respNuevoJuegoEjer1;
	cin>>respMEnMain;
	do
	{
		if (respMEnMain==1){
			//Ejercicio 1
			srand(time(NULL));
			int numeroAzar = rand()%1001-500;
			cout<<numeroAzar<<endl;
			do{	
				cout<<"Ingrese un Número"<<endl;
				cin>>numeroIntentoMain;
				numeroResultadoMain= ejercicio1RespIntentos(numeroIntentoMain,numeroAzar);
				ejercicio1Resp(numeroResultadoMain);
				numeroScore++;
			} while (numeroResultadoMain!=3);
			cout<<"Felicidades, solo te tomo "<<numeroScore<<" intentos "<<endl;
			arrayOrdering(arrayScore,arrayIntentosSizeMain,numeroScore);
			cout<<"Otro Juego? [y/n]: "<<endl;
			for (int i = 0; i < arrayIntentosSizeMain; ++i)
			{
				cout<<"--"<<arrayScore[i]<<"--"<<endl;
			}
			numeroScore=0;
			cin>>respNuevoJuegoEjer1;
			if (respNuevoJuegoEjer1=='n'){
				cout<<"Score No Guardado"<<endl;
				break;
			}
		}else if (respMEnMain ==2){
			srand(time(NULL));
			//Llenar Matriz STATS
			for (int i = 0; i < arraySTATSSizeMainFILAS; ++i){
				for (int j = 0; j <arraySTATSSizeMainCOL; ++j)
				{
					int numeroAzarATK = rand()%30+85;
					int numeroAzarDEF = rand()%25+50;
					int numeroAzarSPE = rand()%50+150;
					if (j==0)
					{
						arraySTATS[i][j]= numeroAzarATK;
					}else if (j==1){
						arraySTATS[i][j]=numeroAzarDEF;
					}else if(j==(arraySTATSSizeMainCOL-1)){
						arraySTATS[i][j]=numeroAzarSPE;
					}
				}
			}
			//Llenar Matriz JUGADORES
			for (int i = 0; i < arraySTATSJUGSizeMainFILAS; ++i){
				for (int j = 0; j < arraySTATSJUGSizeMainCOL; ++j){
					int numeroAzarASIG = rand()%4;
					if (j==0)
					{
						arraySTATSJUG[i][j]=arraySTATS[numeroAzarASIG][0];
					}else if (j==1){
						arraySTATSJUG[i][j]=arraySTATS[numeroAzarASIG][1];
					}else if(j==2){
						arraySTATSJUG[i][j]=arraySTATS[numeroAzarASIG][2];
					}
				}
			}
			int scoreJUG1,scoreJUG2;
			scoreJUG1 = arraySTATSJUG[0][0]-arraySTATSJUG[1][1];
			scoreJUG2 = arraySTATSJUG[1][0]-arraySTATSJUG[0][1];
			if (scoreJUG1>scoreJUG2)
			{
				cout<<"Jugador 1 ganó!!! con "<<(scoreJUG1 - scoreJUG2)<<endl;
			}else if (scoreJUG2>scoreJUG1)
			{
				cout<<"Jugador 2 ganó!!! con "<<(scoreJUG2 - scoreJUG1)<<endl;
			}
		}else{
			cout<<"Numero Inválido!!"<<endl;
		}
	} while (respMEnMain!=3);
	return 0;
}

void menuFun(){
	cout<<"1-Mayor o Menor\n2-Juego2\n3-Salir"<<endl;
}

void ejercicio1Resp(int numeroResultadoMain){
	if (numeroResultadoMain==1)
	{
		cout<<"EL Número es Menor"<<endl;
	}else if (numeroResultadoMain==2){
		cout<<"El Número es Mayor"<<endl;
	}else if (numeroResultadoMain==3){
		cout<<"Correcto"<<endl;
	}
}
int ejercicio1RespIntentos(int numIntento, int numeroAzar){
	if (numIntento>numeroAzar)
	{
		return 1;
	}else if (numIntento<numeroAzar){
		return 2;
	}else if (numIntento==numeroAzar){
		return 3;
	}
}
void arrayOrdering(int arrayScoreFun[],int arrayIntentosSizeFun,int numeroScoreFun){
	int numRempTmp, cambioNum=1;
	for (int i = 0; (i < arrayIntentosSizeFun)&&cambioNum==1; ++i)
	{
		if (numeroScoreFun < arrayScoreFun[i] || numeroScoreFun==arrayScoreFun[i])
		{
			numRempTmp = arrayScoreFun[i];
			arrayScoreFun[i]=numeroScoreFun;
			arrayScoreFun[i+1]=numRempTmp;
			cambioNum=0;
		}
	}
}