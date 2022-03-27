#include <iostream>
#include <iomanip>
#include <cmath>
#include<windows.h>
#include<fstream>

using namespace std;

const double eps = 1e-12;
double **AB, *X;
int n, i, j;
int option;

int wczytaj(char *nplik)
{
	ifstream plik(nplik);
	plik >> n;
	AB = new double * [n];
	X  = new double [n];
		
	for( i = 0; i < n; i++ ) AB[i] = new double[n+1];
		
	for( i = 0; i < n; i++ )
		for( j = 0; j <= n; j++ ) plik >> AB [ i ][ j ];
	plik.close(); 
	return 0; 
}

void pokaz(){
	for(int a=0;i<n;a++){
		for(int b=0;b<=n;b++){
			cout<<AB[i][j];
			if(b==n) cout<<endl;
			else if(b<n) cout<<" ";
		}
	}
}

bool gauss ( int n, double **AB, double *X)
{
  	int i, j, k;
  	double m, s;

  	for( i = 0; i < n - 1; i++ ) {
    	for( j = i + 1; j < n; j++ ) {
      	if( fabs ( AB [ i ][ i ] ) < eps ) return false;
      	m = -AB [ j ][ i ] / AB [ i ][ i ];
      	for( k = i + 1; k <= n; k++ )
        	AB [ j ][ k ] += m * AB [ i ][ k ];
    	}
  	}

  	for(i = n-1; i>=0; i--) {
    	s = AB [ i ][ n ];
    	for( j = n - 1; j >= i + 1; j-- )
      		s -= AB [ i ][ j ] * X [ j ];
    	if( fabs ( AB [ i ][ i ] ) < eps ) return false;
    	X [ i ] = s / AB [ i ][ i ];
	}
	return true;
}

int main( )
{
	SetConsoleTitleA("Gaussian elimination method");
  
	cout<<"Load data from Mother.txt [0]NO / [1]YES? ";
	cin>>option;
	
	if(option==0){
		cout<<"Enter n: ";
		cin>>n;
		
		AB = new double * [n];
		X  = new double [n];
		
		for( i = 0; i < n; i++ ) AB [ i ] = new double [ n + 1 ];
		
		for( i = 0; i < n; i++ )
			for( j = 0; j <= n; j++ ) cin >> AB [ i ][ j ];		
	}else{
		wczytaj("Mother.txt");
	}

	pokaz();
	
	if(gauss(n,AB,X)){
		for( i = 0; i < n; i++ )
			cout<<"x"<<i+1<<" = "<<setw(9)<<X[i]<<endl;
	}
	else cout<<"The divisor of zero!\r\n";
	
	for( i = 0; i < n; i++ ) delete [ ] AB [ i ];
	delete [ ] AB;
	delete [ ] X;

	system("pause");
	return 0;
} 
