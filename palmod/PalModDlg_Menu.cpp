
#include "stdafx.h"
#include "PalModDlg.h"
#include "PalMod.h"

void CPalModDlg::OnLoadGameByDirectory(int nGameFlag)
{
    if (VerifyMsg(eVerifyType::VM_FILECHANGE))
    {
        CString szGet;

        if (SetLoadDir(&szGet))
        {
            LoadGameDir(nGameFlag, szGet.GetBuffer());
        }
    }
}

void CPalModDlg::OnInitMenuPopup(CMenu* pPopupMenu, UINT nIndex, BOOL bSysMenu)
{
    CDialog::OnInitMenuPopup(pPopupMenu, nIndex, bSysMenu);

    //Set the menu variables
    CMenu* m_SubFileMenu = GetMenu()->GetSubMenu(0);
    CMenu* m_SubEditMenu = GetMenu()->GetSubMenu(1);
    CMenu* m_SubToolMenu = GetMenu()->GetSubMenu(2);
    CMenu* m_SubSettMenu = GetMenu()->GetSubMenu(3);

    if (pPopupMenu == m_SubFileMenu)
    {
        pPopupMenu->EnableMenuItem(ID_FILE_PATCH, !fFileChanged);
        pPopupMenu->EnableMenuItem(ID_FILE_CLOSEFILEDIR, (GetHost()->GetCurrGame() == nullptr));
        pPopupMenu->EnableMenuItem(ID_FILE_LOADLASTUSEDDIR, !GetLastUsedDirectory(NULL, NULL, NULL, TRUE));
    }
    else if (pPopupMenu == m_SubEditMenu)
    {
        pPopupMenu->EnableMenuItem(ID_EDIT_UNDO, !UndoProc.GetUndoCount());
        pPopupMenu->EnableMenuItem(ID_EDIT_REDO, !UndoProc.GetRedoCount());

        pPopupMenu->EnableMenuItem(ID_EDIT_COPY, !m_PalHost.CurrPalAvail());
        pPopupMenu->EnableMenuItem(ID_EDIT_PASTE, !IsPasteSupported());

        pPopupMenu->EnableMenuItem(ID_EDIT_SELECTALL, !m_PalHost.GetNotifyPal()->GetWorkingAmt());
        pPopupMenu->EnableMenuItem(ID_EDIT_SELECTNONE, !m_PalHost.GetNotifyPal()->GetWorkingAmt());
    }
    else if (pPopupMenu == m_SubToolMenu)
    {
        // Enable everything... but then double-check since some games have no previews available at this time.
        int i = 0, nMenuID;

        while ((nMenuID = pPopupMenu->GetMenuItemID(i)) != -1)
        {
            pPopupMenu->EnableMenuItem(nMenuID, !bEnabled);

            i++;
        }

        // Right now we can only generate patches collecting changes that are for single-binary game sets
        const bool shouldEnable = fFileChanged && GetHost()->GetCurrGame() && !GetHost()->GetCurrGame()->GetIsDir();
        pPopupMenu->EnableMenuItem(ID_TOOLS_GENERATEPATCHFILE, !shouldEnable);
    }
    else if (pPopupMenu == m_SubSettMenu)
    {
        UpdateColorFormatMenu();
    }
}
