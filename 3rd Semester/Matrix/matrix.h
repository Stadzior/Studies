#pragma once
class matrix
{
private:
	int width;
	int height;
	double **content;
	void MemoryFree();
	void MemoryAlloc();
	void MemoryRealloc(int, int);
	void setWidth(int);
	void setHeight(int);
public:
	int getWidth() const;
	int getHeight() const;
	char* Display() const;
	void RandomInitialize();
	void RandomInitialize(int, int);
	void InitializeZero();
	void InitializeZero(int, int);
	void InitializeFromFile(int,int,char*);
	matrix &operator=(const matrix&);
	friend matrix operator+(const matrix &, const matrix &);
	friend matrix operator-(const matrix &, const matrix &);
	friend matrix operator*(const matrix &, const matrix &);
	friend matrix operator/(const matrix &, const matrix &);
	matrix &operator+=(const matrix&);
	matrix &operator-=(const matrix&);
	matrix &operator*=(const matrix&);
	matrix &operator/=(const matrix&);
	double operator()(int,int);
	void operator()(int, int, double);
	int operator==(const matrix&);
	friend std::ostream& operator<< (std::ostream&,const matrix&);
	matrix(matrix& matrix);
	matrix();
	virtual ~matrix();
};

class InvalidMatrixSizeException: std::exception
{
};

class FileOpenErrorException : std::exception
{
};
