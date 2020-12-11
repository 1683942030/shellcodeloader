
// shellcodeLoaderDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"



// CshellcodeLoaderDlg �Ի���
class CshellcodeLoaderDlg : public CDialogEx
{
// ����
public:
	CshellcodeLoaderDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SHELLCODELOADER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString ShellcodePath;
	afx_msg void OnDropFiles(HDROP hDropInfo);
	BOOL bool_x64;
	BOOL bool_autostart;
	BOOL bool_antisandbox;
	CComboBox Method;
	afx_msg void OnBnClickedGenerate();
	afx_msg void OnBnClickedX64();
};

