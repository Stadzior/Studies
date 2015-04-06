#pragma once
#include <fstream>
#include <iostream>
#include <cstdlib>
#include "matrix.h"

	int matrix::getWidth() const
	{
		return this->width;
	}

	int matrix::getHeight() const
	{
		return this->height;
	}

	void matrix::setWidth(int value)
	{
		this->width = value;
	}

	void matrix::setHeight(int value)
	{
		this->height = value;
	}

	void matrix::MemoryAlloc()
	{
		this->content = new double*[this->height];
		for (int i = 0; i < this->height; i++)
		{
			this->content[i] = new double[this->width];
		}
	}
	void matrix::MemoryFree()
	{
		for (int i = 0; i < this->height; i++)
		{
			delete[]this->content[i];
		}
		delete[]this->content;
	}

	void matrix::MemoryRealloc(int height, int width)
	{
		this->MemoryFree();
		this->height = height;
		this->width = width;
		this->MemoryAlloc();
	}
	void matrix::RandomInitialize()
	{
		for (int i = 0; i < this->height; i++)
		{
			for (int j = 0; j < this->width; j++)
			{
				this->content[i][j] =rand() % 10;
			}
		}
	}
	void matrix::RandomInitialize(int height,int width)
	{
		this->MemoryRealloc(height, width);
		for (int i = 0; i < this->height; i++)
		{
			for (int j = 0; j < this->width; j++)
			{
				this->content[i][j] = rand() % 10;
			}
		}
	}
	void matrix::InitializeZero()
	{
		for (int i = 0; i < this->height; i++)
		{
			for (int j = 0; j < this->width; j++)
			{
				this->content[i][j] = 0;
			}
		}
	}

	void matrix::InitializeZero(int height, int width)
	{
		this->MemoryRealloc(height, width);
		for (int i = 0; i < this->height; i++)
		{
			for (int j = 0; j < this->width; j++)
			{
				this->content[i][j] = 0;
			}
		}
	}

	void matrix::InitializeFromFile(int height,int width,char* FileName)
	{
		this->MemoryRealloc(height, width);
		std::ifstream pFile;
		pFile.open(FileName, std::ios::in);
		try
		{
			if (!pFile.is_open()) throw FileOpenErrorException();
		}
		catch (FileOpenErrorException)
		{
			system("cls");
			std::cout<<"Nie mozna otworzyc pliku!";
			getchar();
			exit(EXIT_FAILURE);
		}
		char inputText[100],temp[20];
		unsigned int CurrentPosition, posY, posX, i,j,k;
		for (posY = 0; posY < height; posY++)
		{
			pFile.getline(inputText, 100);
			CurrentPosition = 0;
			posX = 0;
			for (i = 0; i < strlen(inputText); i++)
			{
				if (inputText[i] == ' ')
				{
					for (j = CurrentPosition, k = 0; j < i; j++, k++)
					{
						temp[k] = inputText[j];
					}
					temp[k + 1] = '\0';
					this->content[posY][posX] = atof(temp);
					posX++;
					CurrentPosition = i + 1;
				}
				if (i == (strlen(inputText))-1)
				{
					for (j = CurrentPosition, k = 0; j < strlen(inputText); j++, k++)
					{
						temp[k] = inputText[j];
					}
					temp[k + 1] = '\0';
					this->content[posY][posX] = atof(temp);
				}
			}
		}
		pFile.close();
	}

	char* matrix::Display() const
	{
		char* output;
		char* temp;
		output = new char[10000];
		temp = new char[100];
		strcpy_s(output,10000,"");
		for (int i = 0; i < this->height; i++)
		{
			for (int j = 0; j < this->width; j++)
			{
				_itoa_s(this->content[i][j], temp,100, 10);
				strcat_s(output, 10000, temp);
				strcat_s(output, 10000, " ");
			}
			strcat_s(output, 10000, "\n");
		}
		delete[]temp;
		return output;
		delete[]output;
	}

	std::ostream& operator<<(std::ostream & stream,const matrix &matrix)
	{
		return stream << matrix.Display();
	}

	matrix &matrix::operator=(const matrix &matrix)
	{
		if (this != &matrix)
		{
			this->MemoryRealloc(matrix.height, matrix.width);
			///////////////////////////////////////////////////////////
			for (int i = 0; i < this->height; i++)
			{
				for (int j = 0; j < this->width; j++)
				{
					this->content[i][j] = matrix.content[i][j];
				}
			}
		}
		return *this;
	}

	matrix operator+(const matrix &object1, const matrix &object2)
	{
		matrix resultObject;
		resultObject = object1;
		int height=object1.height, width=object1.width;
		if (object1.height>object2.height)
		{
			height = object2.height;
		}
		if (object1.width>object2.width)
		{
			width = object2.width;
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				resultObject.content[i][j] += object2.content[i][j];
			}
		}
		return resultObject;
	}

	matrix operator-(const matrix &object1, const matrix &object2)
	{
		matrix resultObject;
		resultObject = object1;
		int height = object1.height, width = object1.width;
		if (object1.height>object2.height)
		{
			height = object2.height;
		}
		if (object1.width>object2.width)
		{
			width = object2.width;
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				resultObject.content[i][j] -= object2.content[i][j];
			}
		}
		return resultObject;
	}
	matrix operator*(const matrix &object1, const matrix &object2)
	{
		try
		{
			if (object1.width != object2.height)
			{
				throw InvalidMatrixSizeException();
			}
		}
		catch (InvalidMatrixSizeException)
		{
			system("cls");
			std::cout<<"Nie da sie pomnozyc powyzszych macierzy.\n";
			getchar();
			exit(EXIT_FAILURE);
		}
		matrix resultObject;
		resultObject.InitializeZero(object1.height,object2.width);
		for (int i = 0; i < resultObject.height; i++)
		{
			for (int j = 0; j < resultObject.width; j++)
			{
				int k;
					for (k = 0; k < object1.width; k++)
					{
						resultObject.content[i][j] += object1.content[i][k] * object2.content[k][j];
					}
			}
		}
		return resultObject;
	}

	matrix &matrix::operator+=(const matrix &matrix)
	{
		int height=this->height, width=this->width;
	if (this->height>matrix.height)
	{
	height = matrix.height;
	}
	if (this->width>matrix.width)
	{
	width = matrix.width;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			this->content[i][j] += matrix.content[i][j];
		}
	}
		return *this;
	}
	
	matrix &matrix::operator-=(const matrix &matrix)
	{
		int height = this->height, width = this->width;
		if (this->height>matrix.height)
		{
			height = matrix.height;
		}
		if (this->width>matrix.width)
		{
			width = matrix.width;
		}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				this->content[i][j] -= matrix.content[i][j];
			}
		}
		return *this;
	}

	matrix &matrix::operator*=(const matrix &object2)
	{
		try
		{
			if (this->width != object2.height)
			{
				throw InvalidMatrixSizeException();
			}
		}
		catch (InvalidMatrixSizeException)
		{
			system("cls");
			std::cout<<"Nie da sie pomnozyc powyzszych macierzy.\n";
			getchar();
			exit(EXIT_FAILURE);
		}
		int height = this->height, width = object2.width,i,j;
		matrix temp;
		temp = *this;
		this->MemoryRealloc(height, width);
		this->InitializeZero();
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				int k;
					for (k = 0; k < object2.height; k++)
					{
						this->content[i][j] += temp.content[i][k] * object2.content[k][j];
					}
			}
		}
		return *this;
	}

	double matrix::operator()(int posY, int posX)
	{
		return this->content[posY][posX];
	}
	void matrix::operator()(int posY, int posX, double value)
	{
		this->content[posY][posX] = value;
	}
	int matrix::operator==(const matrix &matrix)
	{
		bool flag = true;
		if ((this->height != matrix.height) || (this->width != matrix.width))
		{
			flag = false;
		}
		if (flag != false)
		{
			for (int i = 0; i < this->height; i++)
			{
				for (int j = 0; j < this->width; j++)
				{
					if (this->content[i][j]!=matrix.content[i][j])
					{
						flag = false;
					}
				}
			}
		}
		return flag;
	}

	matrix::matrix(matrix &matrix)
	{
		if (this != &matrix)
		{
			this->height = matrix.height;
			this->width = matrix.width;
			///////////////////////////////////////////////////////////
			this->MemoryAlloc();
			///////////////////////////////////////////////////////////
			for (int i = 0; i < this->height; i++)
			{
				for (int j = 0; j < this->width; j++)
				{
					this->content[i][j] = matrix.content[i][j];
				}
			}
		}
	}

	matrix::matrix()
	{
		this->height = (rand() % 5) + 1;
		this->width = (rand() % 5) + 1;
		this->MemoryAlloc();
	}

	matrix::~matrix()
	{
		this->MemoryFree();
	}