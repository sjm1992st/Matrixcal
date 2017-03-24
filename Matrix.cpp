#include "stdafx.h"
#include "Matrix.h"

CMatrix::CMatrix(double * pData, int nRow, int nCol)
{
	m_nRow = nRow;
	m_nCol = nCol;
	m_pArray = new double[m_nRow*m_nCol];
	if (NULL != pData)
	{
		for (int i = 0; i < m_nRow; i++)
			for (int j = 0; j < m_nCol; j++)
			{
				m_pArray[i*m_nCol + j] = pData[i*m_nCol + j];
			}
	}
}
CMatrix::CMatrix(const CMatrix&r){
	m_nRow = r.m_nRow;
	m_nCol = r.m_nCol;
	m_pArray = new double[m_nRow*m_nCol];
	for (int i = 0; i < m_nRow; i++)
		for (int j = 0; j <m_nCol; j++)
		{
			m_pArray[i*m_nCol + j] = r.m_pArray[i*m_nCol + j];
		}
}
CMatrix  CMatrix::operator+(CMatrix &A)
{
	
	for (int i = 0; i<A.m_nRow; i++)
		for (int j = 0; j < m_nCol; j++)
		{
			this->m_pArray[i*m_nCol+j]=A.m_pArray[i*m_nCol+j]+m_pArray[i*m_nCol+j];
		}
	return *this;
}
CMatrix CMatrix::operator-(CMatrix &B)
{

	for (int i = 0; i < B.m_nRow; i++)
		for (int j = 0; j < m_nCol; j++)
		{
			this->m_pArray[i*m_nCol + j] =m_pArray[i*m_nCol + j] - B.m_pArray[i*m_nCol + j];
		}
	return *this;
}
CMatrix CMatrix::operator*(CMatrix &B)
{
	CMatrix C(NULL,m_nRow,B.m_nCol);
	for (int i = 0; i < m_nRow; i++)
		for (int j = 0; j < B.m_nCol; j++)
		{
	          C.m_pArray[i*B.m_nCol + j] = 0;
			for (int k = 0; k <m_nCol; k++)
			{
				C.m_pArray[i*B.m_nCol + j] += m_pArray[i*m_nCol + k] * B.m_pArray[k*B.m_nCol + j];
			}
		}
	return C;
}
CMatrix CMatrix::operator=(CMatrix &A)
{
	m_nRow = A.m_nRow;
	m_nCol = A.m_nCol;
	for (int i = 0; i < m_nRow; i++)
		for (int j = 0; j < m_nCol; j++)
		{
			this->m_pArray[i*m_nCol + j] = A.m_pArray[i*m_nCol + j];
		}
	return *this;
}
void CMatrix::GetC(double *m_ptransfer)
{
	for (int i = 0; i < m_nRow; i++)
		for (int j = 0; j < m_nCol; j++)
		{
			m_ptransfer[i*m_nCol + j] = m_pArray[i*m_nCol + j];
		}
}

CMatrix::~CMatrix()
{     
	if (NULL != m_pArray)
	{
		delete []m_pArray;
		m_pArray = NULL;
	}
}