
// jzDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "Matrix.h"


// CjzDlg 对话框
class CjzDlg : public CDialogEx
{
// 构造
public:
	CjzDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_Matrixcal_DIALOG };
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

protected:
	void Convert(CString str, double *ArrayX, int *rowcol);
	void Convertc(CString str, double *ArrayX);
	CString outputs(double *arrayS);
	void creatarray(double *arrayA, int *rowcol);
	//void deletearray(double **arrayA, int *rowcol);
	void getmyvalue(double **arrayA, double *pData, int *rowcol);
	void RowCol(CString sInput,int *rowcol);
	void deletepointer(double *m_ptransfer);
	void commonmy();
	void RowColB(CString sInput, int *length);
	CString sortandoutput(double *arrays);
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButtonAdd();
	afx_msg void OnBnClickedButtonSub();
	afx_msg void OnBnClickedButtonMul();
	afx_msg void OnEnChangeEditMatrixa();
//	int m_Col1;
//	CString l2;
//	int l2;
//	int r1;
//	int r2;
	CEdit m_editcx;
	CEdit m_editmcx;
	afx_msg void OnBnClickedButtonSort();
	//int nRow;
	//int nCol;
	int *m_prowcolA,*m_prowcolB,*m_plength;
	double *m_pDataB,*m_arrayA,*m_arrayB,*m_arrayS;
	afx_msg void OnEnChangeEditMatrixb();
	afx_msg void OnEnChangeEditSortresult();
	afx_msg void OnBnClickedButtonImporta();
	CEdit m_editMatrixA;
	CEdit m_editMatrixB;
	afx_msg void OnBnClickedButtonImportb();
	afx_msg void OnBnClickedButtonSaveresult();
	afx_msg void OnBnClickedButtonModify();
};
