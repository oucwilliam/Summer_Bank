#pragma once


// CLost 对话框

class CLost : public CDialogEx
{
	DECLARE_DYNAMIC(CLost)

public:
	CLost(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~CLost();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_Lost};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};
