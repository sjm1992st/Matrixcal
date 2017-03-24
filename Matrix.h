#pragma once
class CMatrix
{
protected:
	double * m_pArray;
	int m_nRow;
	int m_nCol;
public:
	 CMatrix operator*(CMatrix &A);
	 CMatrix operator+(CMatrix &A);
	CMatrix operator-(CMatrix &A);
	CMatrix operator=(CMatrix &A);
	void GetC(double *m_ptransfer);
	//static int countn;
	//void CMatrixAdd(double **arrayC, double **arrayD, int r, int l);
	//void CMatrixSub(double **arrayC, double **arrayD, int r, int l);
	//void CMatrixMul(double **arrayC, double **arrayD, int r, int l);
public:
	CMatrix(double * pData, int nRow, int nCol);
	CMatrix(const CMatrix&r);
	~CMatrix();
};

