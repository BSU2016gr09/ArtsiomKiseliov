#include<iostream>
#include<cmath>
using namespace std;
const int N = 10;
void createMas(int A[], int N)
{
	int i = 0;
	while(i<N)
		{
			A[i] = rand() %9+1;
			i++;
		}
}
void printMas(int A[], int N)
{
	int i = 0;
	while (i<N)
	{
		cout << A[i] << ' ';
		i++;
	}
	cout << endl;
}
void Search(int A[], int N)
{

	int B[10];
	int n = 0, m = 0;
	int i = 0, j = 0;
	for (i = 0; i < N; ++i) 
	{  
		B[j] = A[i];
		++j;
	}
	for (i = 0; i < N; ++i) 
	{   
		for (j = 0; j < N; ++j) 
		{ 
			if (B[j] == A[i])    
				++n;            
		}
		if (n >= 2)
			++m;  
		n = 0; 

	}
	cout << "Kolichestvo povtornih elementov: " << m/2;
}
int main()
{
	const int N = 10;
	int A[N];
	int B[N];
	createMas(A, N);
	printMas(A, N);
	Search(A, N);
	system("pause");
}