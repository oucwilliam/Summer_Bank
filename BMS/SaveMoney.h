#pragma once


// SaveMoney 对话框

class SaveMoney : public CDialogEx
{
	DECLARE_DYNAMIC(SaveMoney)

public:
	SaveMoney(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~SaveMoney();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_SaveMoney };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedCancel();
};
