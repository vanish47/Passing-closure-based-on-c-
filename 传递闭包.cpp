#include<iostream>
using std::cout;
using std::cin;
using std::endl;
void trans_clo(int* array[], int n);
int main()
{
	cout << "row and column : ";
	int n;
	cin >> n;
	int** martrix = new int* [n];
	for (int i = 0; i < n; i++)
		martrix[i] = new int[n];
	for (int i = 0; i < n; i++)
	{
		cout << "input " << (i + 1) << " row's datas :";
		for (int j = 0; j < n; j++)
			cin >> martrix[i][j];
	}
	trans_clo(martrix, n);




	for (int i = 0; i < n; i++)
		delete[] martrix[i];
	delete[] martrix;
	return 0;
}

void trans_clo(int* array[], int n)
{
	int** A = new int* [n];
	int** B = new int* [n];
	for (int i = 0; i < n; i++)
	{
		A[i] = new int[n];
		B[i] = new int[n];
	}//创建临时动态数组
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			A[i][j] = array[i][j];
			B[i][j] = array[i][j];
		}
	}//赋值
	for (int i = 1; i < n; i++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				for (int k = 0; k < n; k++)
				{
					if (A[i][k] * array[k][j] == 1)
					{
						A[i][j] = 1;
						B[i][j] = 1;//求R*
						break;
					}
					if (k == n)
						A[i][j] = 0;

				}
			}
		}//矩阵布尔运算同时求连通性关系R*
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << B[i][j] << "  ";
		cout << endl;
	}//输入R*
	for (int i = 0; i < n; i++)
	{
		delete[] A[i];
		delete[]B[i];
	}
	delete[] A;
	delete[]B;//释放动态数组
}