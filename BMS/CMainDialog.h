#pragma once


// CMainDialog 对话框

class CMainDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDialog)

public:
	CMainDialog(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CMainDialog();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Main_Dialog };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnStnClickedStaticText();
	afx_msg void OnBnClickedOk();

public:
	void SetInfo(CString strInfo);

private:
	CString m_strInfo;
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedBtnadd();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonOutmoney();
	afx_msg void OnBnClickedButtonLost();
	afx_msg void OnBnClickedButtonUserlgn();
};
