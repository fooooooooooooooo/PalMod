// SettDlg.cpp : implementation file
//
#include "stdafx.h"
#include "PalMod.h"
#include "SettDlg.h"

// CSettDlg dialog

IMPLEMENT_DYNAMIC(CSettDlg, CDialog)

CSettDlg::CSettDlg(CWnd* pParent /*=NULL*/)
    : CDialog(CSettDlg::IDD, pParent)
    , m_fAllowAlphaChanges(FALSE) // these values are ignored: the defaults in regproc.cpp are used
    , m_bUpdSupp(TRUE)
{

}

CSettDlg::~CSettDlg()
{
}

void CSettDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Check(pDX, IDC_CALPHATRANS, m_fAllowAlphaChanges);
    DDX_Check(pDX, IDC_CUPDSUPP, m_bUpdSupp);
}

BEGIN_MESSAGE_MAP(CSettDlg, CDialog)
END_MESSAGE_MAP()

// CSettDlg message handlers
