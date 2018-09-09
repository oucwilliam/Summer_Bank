#pragma once
class CStaff
{
public:
	CStaff(void);
	CStaff(char aAccount[21], char aPassword[7], char aName[15], char aBankName[41], int nPermission);
	~CStaff(void);
public:
	char* GetAccount();
	void SetAccount(char aAccount[21]);
	char* GetPassword();
	void SetPassword(char aPassword[7]);
	char* GetName();
	void SetName(char aName[15]);
	char* GetBankName();
	void SetBankName(char aBankName[41]);
	int GetPermission();
	void SetPermission(int nPermission);
private:
	char m_aAccount[21];
	char m_aPassword[7];
	char m_aName[15];
	char m_aBankName[41];
	int m_nPermission;
};


