
// jzDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "Matrixcal.h"
#include "MatrixcalDlg.h"
#include "afxdialogex.h"
#include "Matrix.h"
#include <fstream>
using namespace std;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CjzDlg 对话框



CjzDlg::CjzDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CjzDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CjzDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT_Matrixresult, m_editcx);
	DDX_Control(pDX, IDC_EDIT_SORTresult, m_editmcx);
	DDX_Control(pDX, IDC_EDIT_MatrixA, m_editMatrixA);
	DDX_Control(pDX, IDC_EDIT_MatrixB, m_editMatrixB);
}

BEGIN_MESSAGE_MAP(CjzDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_ADD, &CjzDlg::OnBnClickedButtonAdd)
	ON_BN_CLICKED(IDC_BUTTON_SUB, &CjzDlg::OnBnClickedButtonSub)
	ON_BN_CLICKED(IDC_BUTTON_MUL, &CjzDlg::OnBnClickedButtonMul)
	ON_EN_CHANGE(IDC_EDIT_MatrixA, &CjzDlg::OnEnChangeEditMatrixa)
	ON_BN_CLICKED(IDC_BUTTON_SORT, &CjzDlg::OnBnClickedButtonSort)
	ON_EN_CHANGE(IDC_EDIT_MatrixB, &CjzDlg::OnEnChangeEditMatrixb)
	ON_EN_CHANGE(IDC_EDIT_SORTresult, &CjzDlg::OnEnChangeEditSortresult)
	ON_BN_CLICKED(IDC_BUTTON_ImportA, &CjzDlg::OnBnClickedButtonImporta)
	ON_BN_CLICKED(IDC_BUTTON_ImportB, &CjzDlg::OnBnClickedButtonImportb)
	ON_BN_CLICKED(IDC_BUTTON_SAVEresult, &CjzDlg::OnBnClickedButtonSaveresult)
	ON_BN_CLICKED(IDC_BUTTON_Modify, &CjzDlg::OnBnClickedButtonModify)
END_MESSAGE_MAP()


// CjzDlg 消息处理程序

BOOL CjzDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CString   str= "1 2\r\n3 4";
	GetDlgItem(IDC_EDIT_MatrixA)->SetWindowText(str);
	GetDlgItem(IDC_EDIT_MatrixB)->SetWindowText(str);
	CString   strB = "2,0,1,3,4";
	GetDlgItem(IDC_EDIT_SORTresult)->SetWindowText(strB);
	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CjzDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CjzDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CjzDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CjzDlg::RowCol(CString sInput,int *rowcol)
{
	int nALength = sInput.GetLength();
	int i = 0,countnum=0;
	while (i != nALength){
		if (sInput.GetAt(i) == '\n')
		{
			rowcol[0]++;
		}
		if (sInput.GetAt(i) == ' ')
		{
			countnum = 0;
		}
		if (sInput.GetAt(i) != ' '
			&&sInput.GetAt(i) != '\r'
			&&sInput.GetAt(i) != '\n'
			&&rowcol[0]<2
			&&countnum==0)
		{
			countnum++;
			rowcol[1]++;
		}
		//if (i == nALength - 1 && sInput.GetAt(i) == '\n')
		//{
		//	rowcol[0]--;
		//}
		i = i + 1;
	}
}
void CjzDlg::RowColB(CString sInput, int *length)
{
	int nALength = sInput.GetLength();
	int i = 0, countnum = 0;
	while (i != nALength){
		if (sInput.GetAt(i) == ',')
		{
			countnum = 0;
		}
		if (sInput.GetAt(i) != ','&& countnum == 0)
		{
			countnum++;
			length[0]++;
		}
		i = i + 1;
	}
}
void CjzDlg::Convert(CString sInput, double *ArrayX, int *rowcol)
{   
	int nALength = sInput.GetLength();
	int i = 0, j = 0, k = 0,count=0;
	CString tmpA,tmpB;
	double a;
	while (i != nALength){
		if (sInput.GetAt(i) != '\r'
			&&sInput.GetAt(i) != '\n'
			&&sInput.GetAt(i) != ' ')
		{
			tmpA = sInput.GetAt(i);
			tmpB += tmpA;
			count++;
		}
		if (sInput.GetAt(i) == '\n')
		{
			a = _tstof(tmpB);
			ArrayX[j*rowcol[1] + k] = a;
			tmpB = "";
			j++;
			k = 0;
		}
		if (sInput.GetAt(i) == ' '&&count != 0)
		{
			a = _tstof(tmpB);
			ArrayX[j*rowcol[1]+k] =a;
			tmpB = "";
			k++;
			count = 0;
		}
		if (i == nALength - 1 && sInput.GetAt(i) != ' '&&count != 0)
		{
			a = _tstof(tmpB);
			ArrayX[j*rowcol[1] + k] = a;
			tmpB = "";
			k++;
			count = 0;
		}
		i = i + 1;
	}
}
void CjzDlg::Convertc(CString sInput, double *ArrayX)
{
	int nALength = sInput.GetLength();
	int i = 0, k = 0;
	CString tmpA, tmpB;
	double a;
	while (i != nALength)
	{
		if (sInput.GetAt(i) != ',')
		{
			tmpA = sInput.GetAt(i);
			tmpB += tmpA;
		}
		if (sInput.GetAt(i) == ',' || i == nALength - 1)
		{
			a = _tstof(tmpB);
			ArrayX[k++] = a;
			tmpB = "";
		}
		i = i + 1;
	}
}
CString CjzDlg::outputs(double *m_array)
{
	CString tmpB, tmpA;
     tmpB = tmpA = "";
	for (int i = 0; i <m_prowcolA[0]; i++)
	{
		for (int j = 0; j <m_prowcolB[1]; j++)
		{   if (j==0)
		    tmpB.Format("%g", m_array[i*m_prowcolB[1] + j]);
		else
		    tmpB.Format(" %g", m_array[i*m_prowcolB[1]+j]);
		tmpA += tmpB;
		}
		if (i!=m_prowcolA[0]-1)
		tmpA += "\r\n";
	}
	return tmpA;
}
CString CjzDlg::sortandoutput(double *m_arrays)
{
	double temp = 0;
	for (int i = 0; i < m_plength[0]; i++)
		for (int j = 0; j<m_plength[0] - i - 1; j++)
			if (m_arrayS[j]>m_arrayS[j + 1])
			{
				temp = m_arrayS[j];
				m_arrayS[j] = m_arrayS[j + 1];
				m_arrayS[j + 1] = temp;
			}
	CString tmpA, tmpB;
	tmpB = tmpA = "";
	tmpB.Format("%g", m_arrayS[0]);
	tmpA += tmpB;
	for (int i = 1; i < m_plength[0]; i++)
	{
		tmpB.Format(",%g", m_arrayS[i]);
		tmpA += tmpB;
	}
	return tmpA;
}
void CjzDlg::OnBnClickedCancel()
{
	// TODO:  在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}

void CjzDlg::deletepointer(double *m_ptransfer )
{
	delete []m_prowcolA;
	delete []m_prowcolB;
	delete []m_pDataB;
	delete []m_ptransfer;
	delete []m_arrayA;
	delete []m_arrayB;
}
void CjzDlg::commonmy()
{
	CString sInputA;
	CString sInputB;
	GetDlgItemText(IDC_EDIT_MatrixA, sInputA);
	GetDlgItemText(IDC_EDIT_MatrixB, sInputB);
	m_prowcolA = new int[2];
	m_prowcolA[0] = 1; m_prowcolA[1] = 0;
	m_prowcolB = new int[2];
	m_prowcolB[0] = 1; m_prowcolB[1] = 0;
	RowCol(sInputA, m_prowcolA);
	RowCol(sInputB, m_prowcolB);
	m_arrayA = new double[m_prowcolA[0] * m_prowcolA[1]];
	m_arrayB = new double[m_prowcolB[0] * m_prowcolB[1]];
	Convert(sInputA, m_arrayA, m_prowcolA);
	Convert(sInputB, m_arrayB, m_prowcolB);
}
void CjzDlg::OnBnClickedButtonAdd()
{
	UpdateData(TRUE);
		commonmy();
		CMatrix A(m_arrayA, m_prowcolA[0], m_prowcolA[1]);
		CMatrix B(m_arrayB, m_prowcolB[0], m_prowcolB[1]);
		CMatrix C(NULL, m_prowcolA[0], m_prowcolB[1]);
		C = A + B;
		double *m_ptransfer = new double[m_prowcolA[0] * m_prowcolB[1]];
		C.GetC(m_ptransfer);
		CString tmpA = outputs(m_ptransfer);
		deletepointer(m_ptransfer);
		m_editcx.SetWindowText(tmpA);
}


void CjzDlg::OnBnClickedButtonSub()
{
	UpdateData(TRUE);
	commonmy();
	CMatrix A(m_arrayA, m_prowcolA[0], m_prowcolA[1]);
	CMatrix B(m_arrayB, m_prowcolB[0], m_prowcolB[1]);
	CMatrix C(NULL, m_prowcolA[0], m_prowcolB[1]);
	C = A - B;
	double *m_ptransfer = new double[m_prowcolA[0] * m_prowcolB[1]];
	C.GetC(m_ptransfer);
	CString tmpA = outputs(m_ptransfer);
	deletepointer(m_ptransfer);
	m_editcx.SetWindowText(tmpA);// TODO:  在此添加控件通知处理程序代码
}


void CjzDlg::OnBnClickedButtonMul()
{
	UpdateData(TRUE);
	commonmy();
	if (m_prowcolA[1] == m_prowcolB[0]){
		CMatrix A(m_arrayA, m_prowcolA[0], m_prowcolA[1]);
		CMatrix B(m_arrayB, m_prowcolB[0], m_prowcolB[1]);
		CMatrix C(NULL, m_prowcolA[0], m_prowcolB[1]);
		C = A * B;
		double *m_ptransfer = new double[m_prowcolA[0] * m_prowcolB[1]];
		C.GetC(m_ptransfer);
		CString tmpA = outputs(m_ptransfer);
		deletepointer(m_ptransfer);
		m_editcx.SetWindowText(tmpA);
}
	else{
		CString str = "不能做乘法";
		m_editcx.SetWindowText(str);
	}// TODO:  在此添加控件通知处理程序代码
}


void CjzDlg::OnEnChangeEditMatrixa()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}

void CjzDlg::OnBnClickedButtonSort()
{
	CString sInputA, tmp;
	GetDlgItemText(IDC_EDIT_SORTresult, sInputA);
	m_plength = new int[1];
	m_plength[0] = 0;
	RowColB(sInputA, m_plength);
	m_arrayS = new double[m_plength[0]];
	Convertc(sInputA, m_arrayS);
	CString tmpA=sortandoutput(m_arrayS);
	delete []m_plength;
	delete []m_arrayS;
	m_editmcx.SetWindowText(tmpA);
	// TODO:  在此添加控件通知处理程序代码
}


void CjzDlg::OnEnChangeEditMatrixb()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。
	// TODO:  在此添加控件通知处理程序代码
}


void CjzDlg::OnEnChangeEditSortresult()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CjzDlg::OnBnClickedButtonImporta()
{
	char Filter[] = ("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, ("txt"), NULL, 0, Filter, this);
	CString strPath; 
	if (IDOK == fileDlg.DoModal())
	{   
		strPath = fileDlg.GetPathName();
		fstream file;
		file.open(strPath, ios::in | ios::out | ios::binary);
		char *pBufA;
		file.seekg(0, ios::end);
		int Len = file.tellg();
		file.seekg(0, ios::beg);
		pBufA = new char[Len + 1];
		file.read(pBufA, Len);
		pBufA[Len] = 0;
		file.close();
		m_editMatrixA.SetWindowText(pBufA);
		delete[]pBufA;
	}// TODO:  在此添加控件通知处理程序代码
}


void CjzDlg::OnBnClickedButtonImportb()
{

	char Filter[] = ("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||"); 
	CFileDialog fileDlg(TRUE, ("txt"), NULL, 0, Filter, this);
	CString strPath;
	if (IDOK == fileDlg.DoModal())
	{  
		strPath = fileDlg.GetPathName();
		fstream file;
		file.open(strPath, ios::in | ios::out | ios::binary);
		char *pBufA;
		file.seekg(0, ios::end);
		int Len = file.tellg();
		file.seekg(0, ios::beg);
		pBufA = new char[Len + 1];
		file.read(pBufA, Len);
		pBufA[Len] = 0;
		file.close();
		m_editMatrixB.SetWindowText(pBufA);
		delete[]pBufA;
	}// TODO:  在此添加控件通知处理程序代码
}


void CjzDlg::OnBnClickedButtonSaveresult()
{
	char Filter[] = ("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(FALSE, ("txt"), NULL, 0, Filter, this);
	CString sInputC, strPath;
	if (IDOK == fileDlg.DoModal())
	{
		strPath = fileDlg.GetPathName();
		fstream file;
		file.open(strPath, ios::in | ios::out | ios::binary | ios::trunc);
		GetDlgItemText(IDC_EDIT_Matrixresult, sInputC);
		file.write(sInputC, sInputC.GetLength());
		file.close();
	}
}


void CjzDlg::OnBnClickedButtonModify()
{
	char Filter[] = ("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	CFileDialog fileDlg(FALSE, ("txt"), NULL, 0, Filter, this);
	CString strPath;  
	if (IDOK == fileDlg.DoModal())
	{
		strPath = fileDlg.GetPathName();
		SetDlgItemText(IDC_EDIT_Modify, strPath);
		ShellExecute(NULL, "open", strPath, NULL, NULL, SW_SHOWNORMAL);
	}// TODO:  在此添加控件通知处理程序代码
}
