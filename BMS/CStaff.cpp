#include "stdafx.h"
#include "CStaff.h"


CStaff::CStaff(void)
{
	m_aAccount[21];
	m_aPassword[7];
	m_aName[15];
	m_aBankName[41];
	strcpy_s(m_aAccount, "");
	strcpy_s(m_aPassword, "");
	strcpy_s(m_aName, "");
	strcpy_s(m_aBankName, "");
	m_nPermission = 0;
}

CStaff::CStaff(char aAccount[21], char aPassword[7], char aName[15], char aBankName[41], int nPermission)
{
	strcpy_s(m_aAccount, aAccount);
	strcpy_s(m_aPassword, aPassword);
	strcpy_s(m_aName, aName);
	strcpy_s(m_aBankName, aBankName);
	m_nPermission = nPermission;
}
CStaff::~CStaff()
{
}

void CStaff::SetAccount(char aAccount[21])
{
	strcpy_s(m_aAccount, aAccount);
}

char* CStaff::GetAccount()
{
	return m_aAccount;
}

void CStaff::SetPassword(char aPassword[7])
{
	strcpy_s(m_aPassword, aPassword);
}

char* CStaff::GetPassword()
{
	return m_aPassword;
}

void CStaff::SetName(char aName[15])
{
	strcpy_s(m_aName, aName);
}

char* CStaff::GetName()
{
	return m_aName;
}

void CStaff::SetBankName(char aBankName[41])
{
	strcpy_s(m_aBankName, aBankName);
}

char* CStaff::GetBankName()
{
	return m_aBankName;
}

void CStaff::SetPermission(int nPermission)
{
	m_nPermission = nPermission;
}

int CStaff::GetPermission()
{
	return m_nPermission;
}

