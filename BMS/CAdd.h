#pragma once


// CAdd 对话框

class CAdd : public CDialogEx
{
	DECLARE_DYNAMIC(CAdd)

public:
	CAdd(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CAdd();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Add };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedBack();
};
