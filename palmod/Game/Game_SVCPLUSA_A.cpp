#include "StdAfx.h"
#include "..\StdAfx.h"
#include "GameDef.h"
#include "Game_SVCPLUSA_A.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

#define SVCPLUSA_A_DEBUG DEFAULT_GAME_DEBUG_STATE

stExtraDef* CGame_SVCPLUSA_A::SVCPLUSA_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_SVCPLUSA_A::MainDescTree = nullptr;

int CGame_SVCPLUSA_A::rgExtraCountAll[SVCPLUSA_A_NUMUNIT + 1];
int CGame_SVCPLUSA_A::rgExtraLoc[SVCPLUSA_A_NUMUNIT + 1];

UINT32 CGame_SVCPLUSA_A::m_nTotalPaletteCountForSVCPLUSA = 0;
UINT32 CGame_SVCPLUSA_A::m_nGameROMSize = 0x400000;  // 4194304 bytes
UINT32 CGame_SVCPLUSA_A::m_nConfirmedROMSize = -1;

void CGame_SVCPLUSA_A::InitializeStatics()
{
    safe_delete_array(CGame_SVCPLUSA_A::SVCPLUSA_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_SVCPLUSA_A::InitDescTree());
}

CGame_SVCPLUSA_A::CGame_SVCPLUSA_A(UINT32 nConfirmedROMSize)
{
    CString strMessage;
    strMessage.Format(_T("CGame_SVCPLUSA_A::CGame_SVCPLUSA_A: Loading ROM...\n"));
    OutputDebugString(strMessage);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = SVCPLUSA_A_NUMUNIT;
    m_nExtraUnit = SVCPLUSA_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 1000;
    m_pszExtraFilename = EXTRA_FILENAME_SVCPLUSA_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForSVCPLUSA;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0x2d97f0;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    //Set color mode
    SetColMode(COLMODE_NEOGEO);

    //Set palette conversion mode
    BasePalGroup.SetMode(PALTYPE_8);

    //Set game information
    nGameFlag = SVCPLUSA_A;
    nImgGameFlag = IMGDAT_SECTION_KOF;
    nImgUnitAmt = sizeof(SVCPLUSA_A_IMG_UNITS);

    nDisplayW = 8;
    nFileAmt = 1;

    //Set the image out display type
    DisplayType = DISP_DEF;
    // Button labels are used for the Export Image dialog
    pButtonLabel = const_cast<TCHAR*>((TCHAR*)DEF_BUTTONLABEL_SVC);
    m_nNumberOfColorOptions = ARRAYSIZE(DEF_BUTTONLABEL_SVC);

    //Create the redirect buffer
    rgUnitRedir = new UINT16[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(UINT16) * nUnitAmt);

    //Create the file changed flag
    rgFileChanged = new UINT16;

    nRGBIndexAmt = 15;
    nAIndexAmt = 0;

    nRGBIndexMul = 17.0f;
    nAIndexMul = 0.0f;
}

CGame_SVCPLUSA_A::~CGame_SVCPLUSA_A(void)
{
    safe_delete_array(CGame_SVCPLUSA_A::SVCPLUSA_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    safe_delete(rgFileChanged);
}

CDescTree* CGame_SVCPLUSA_A::GetMainTree()
{
    return &CGame_SVCPLUSA_A::MainDescTree;
}

int CGame_SVCPLUSA_A::GetExtraCt(UINT16 nUnitId, BOOL bCountVisibleOnly)
{
    if (rgExtraCountAll[0] == -1)
    {
        int nDefCtr = 0;
        memset(rgExtraCountAll, 0, ((SVCPLUSA_A_NUMUNIT + 1) * sizeof(int)));

        stExtraDef* pCurrDef = GetExtraDefForSVCPLUSA(0);

        while (pCurrDef->uUnitN != INVALID_UNIT_VALUE)
        {
            if (!pCurrDef->isInvisible || !bCountVisibleOnly)
            {
                rgExtraCountAll[pCurrDef->uUnitN]++;
            }

            nDefCtr++;
            pCurrDef = GetExtraDefForSVCPLUSA(nDefCtr);
        }
    }

    return rgExtraCountAll[nUnitId];
}

int CGame_SVCPLUSA_A::GetExtraLoc(UINT16 nUnitId)
{
    if (rgExtraLoc[0] == -1)
    {
        int nDefCtr = 0;
        int nCurrUnit = UNIT_START_VALUE;
        memset(rgExtraLoc, 0, (SVCPLUSA_A_NUMUNIT + 1) * sizeof(int));

        stExtraDef* pCurrDef = GetExtraDefForSVCPLUSA(0);

        while (pCurrDef->uUnitN != INVALID_UNIT_VALUE)
        {
            if (pCurrDef->uUnitN != nCurrUnit)
            {
                rgExtraLoc[pCurrDef->uUnitN] = nDefCtr;
                nCurrUnit = pCurrDef->uUnitN;
            }

            nDefCtr++;
            pCurrDef = GetExtraDefForSVCPLUSA(nDefCtr);
        }
    }

    return rgExtraLoc[nUnitId];
}

sDescTreeNode* CGame_SVCPLUSA_A::InitDescTree()
{
    UINT32 nTotalPaletteCount = 0;

    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_SVCPLUSA_A, SVCPLUSA_A_EXTRA, &SVCPLUSA_A_EXTRA_CUSTOM, SVCPLUSA_A_EXTRALOC, m_nConfirmedROMSize);

    UINT16 nUnitCt = SVCPLUSA_A_NUMUNIT + (GetExtraCt(SVCPLUSA_A_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _stprintf(NewDescTree->szDesc, _T("%s"), g_GameFriendlyName[SVCPLUSA_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    CString strMsg;
    bool fHaveExtras = (GetExtraCt(SVCPLUSA_A_EXTRALOC) > 0);
    strMsg.Format(_T("CGame_SVCPLUSA_A::InitDescTree: Building desc tree for SVCPLUSA_A %s extras...\n"), fHaveExtras ? _T("with") : _T("without"));
    OutputDebugString(strMsg);

    //Go through each character
    for (UINT16 iUnitCtr = 0; iUnitCtr < nUnitCt; iUnitCtr++)
    {
        sDescTreeNode* UnitNode = nullptr;
        sDescTreeNode* CollectionNode = nullptr;
        sDescNode* ChildNode = nullptr;

        UINT16 nExtraCt = GetExtraCt(iUnitCtr, TRUE);
        BOOL bUseExtra = (GetExtraLoc(iUnitCtr) ? 1 : 0);

        UINT16 nUnitChildCount = GetCollectionCountForUnit(iUnitCtr);

        UnitNode = &((sDescTreeNode*)NewDescTree->ChildNodes)[iUnitCtr];

        if (iUnitCtr < SVCPLUSA_A_EXTRALOC)
        {
            //Set each description
            _stprintf(UnitNode->szDesc, _T("%s"), SVCPLUSA_A_UNITS[iUnitCtr].szDesc);
            UnitNode->ChildNodes = new sDescTreeNode[nUnitChildCount];
            //All children have collection trees
            UnitNode->uChildType = DESC_NODETYPE_TREE;
            UnitNode->uChildAmt = nUnitChildCount;

#if SVCPLUSA_A_DEBUG
            strMsg.Format(_T("Unit: \"%s\", %u of %u (%s), %u total children\n"), UnitNode->szDesc, iUnitCtr + 1, nUnitCt, bUseExtra ? _T("with extras") : _T("no extras"), nUnitChildCount);
            OutputDebugString(strMsg);
#endif
            
            UINT16 nTotalPalettesUsedInUnit = 0;

            //Set data for each child group ("collection")
            for (UINT16 iCollectionCtr = 0; iCollectionCtr < nUnitChildCount; iCollectionCtr++)
            {
                CollectionNode = &((sDescTreeNode*)UnitNode->ChildNodes)[iCollectionCtr];

                //Set each collection data

                // Default label, since these aren't associated to collections
                _stprintf(CollectionNode->szDesc, GetDescriptionForCollection(iUnitCtr, iCollectionCtr));
                //Collection children have nodes
                UINT16 nListedChildrenCount = GetNodeCountForCollection(iUnitCtr, iCollectionCtr);
                CollectionNode->uChildType = DESC_NODETYPE_NODE;
                CollectionNode->uChildAmt = nListedChildrenCount;
                CollectionNode->ChildNodes = (sDescTreeNode*)new sDescNode[nListedChildrenCount];

#if SVCPLUSA_A_DEBUG
                strMsg.Format(_T("\tCollection: \"%s\", %u of %u, %u children\n"), CollectionNode->szDesc, iCollectionCtr + 1, nUnitChildCount, nListedChildrenCount);
                OutputDebugString(strMsg);
#endif

                const sGame_PaletteDataset* paletteSetToUse = GetPaletteSet(iUnitCtr, iCollectionCtr);

                //Set each collection's extra nodes: convert the sGame_PaletteDataset to sDescTreeNodes
                for (UINT16 nNodeIndex = 0; nNodeIndex < nListedChildrenCount; nNodeIndex++)
                {
                    ChildNode = &((sDescNode*)CollectionNode->ChildNodes)[nNodeIndex];

                    _sntprintf(ChildNode->szDesc, ARRAYSIZE(ChildNode->szDesc), _T("%s"), paletteSetToUse[nNodeIndex].szPaletteName);

                    ChildNode->uUnitId = iUnitCtr;
                    ChildNode->uPalId = nTotalPalettesUsedInUnit++;
                    nTotalPaletteCount++;

#if SVCPLUSA_A_DEBUG
                    strMsg.Format(_T("\t\tPalette: \"%s\", %u of %u"), ChildNode->szDesc, nNodeIndex + 1, nListedChildrenCount);
                    OutputDebugString(strMsg);
                    strMsg.Format(_T(", 0x%06x to 0x%06x (%u colors),"), paletteSetToUse[nNodeIndex].nPaletteOffset, paletteSetToUse[nNodeIndex].nPaletteOffsetEnd, (paletteSetToUse[nNodeIndex].nPaletteOffsetEnd - paletteSetToUse[nNodeIndex].nPaletteOffset) / 2);
                    OutputDebugString(strMsg);

                    if (paletteSetToUse[nNodeIndex].indexImgToUse != INVALID_UNIT_VALUE)
                    {
                        strMsg.Format(_T(" image unit 0x%02x image index 0x%02x.\n"), paletteSetToUse[nNodeIndex].indexImgToUse, paletteSetToUse[nNodeIndex].indexOffsetToUse);
                    }
                    else
                    {
                        strMsg.Format(_T(" no image available.\n"));
                    }
                    OutputDebugString(strMsg);
#endif
                }
            }
        }
        else
        {
            // This handles data loaded from the Extra extension file, which are treated
            // each as their own separate node with one collection with everything under that.
            _stprintf(UnitNode->szDesc, _T("Extra Palettes"));
            UnitNode->ChildNodes = new sDescTreeNode[1];
            UnitNode->uChildType = DESC_NODETYPE_TREE;
            UnitNode->uChildAmt = 1;

#if SVCPLUSA_A_DEBUG
            strMsg.Format(_T("Unit (Extras): %s, %u of %u, %u total children\n"), UnitNode->szDesc, iUnitCtr + 1, nUnitCt, nUnitChildCount);
            OutputDebugString(strMsg);
#endif
        }

        //Set up extra nodes
        if (bUseExtra)
        {
            int nExtraPos = GetExtraLoc(iUnitCtr);
            int nCurrExtra = 0;

            CollectionNode = &((sDescTreeNode*)UnitNode->ChildNodes)[(SVCPLUSA_A_EXTRALOC > iUnitCtr) ? (nUnitChildCount - 1) : 0]; //Extra node

            _stprintf(CollectionNode->szDesc, _T("Extra"));

            CollectionNode->ChildNodes = new sDescTreeNode[nExtraCt];

            CollectionNode->uChildType = DESC_NODETYPE_NODE;
            CollectionNode->uChildAmt = nExtraCt; //EX + Extra

#if SVCPLUSA_A_DEBUG
            strMsg.Format(_T("\tCollection: %s, %u of %u, %u children\n"), CollectionNode->szDesc, 1, nUnitChildCount, nExtraCt);
            OutputDebugString(strMsg);
#endif

            for (UINT16 nExtraCtr = 0; nExtraCtr < nExtraCt; nExtraCtr++)
            {
                ChildNode = &((sDescNode*)CollectionNode->ChildNodes)[nExtraCtr];

                stExtraDef* pCurrDef = GetExtraDefForSVCPLUSA(nExtraPos + nCurrExtra);

                while (pCurrDef->isInvisible)
                {
                    nCurrExtra++;

                    pCurrDef = GetExtraDefForSVCPLUSA(nExtraPos + nCurrExtra);
                }

                _stprintf(ChildNode->szDesc, pCurrDef->szDesc);

                ChildNode->uUnitId = iUnitCtr;
                ChildNode->uPalId = (((SVCPLUSA_A_EXTRALOC > iUnitCtr) ? 1 : 0) * nUnitChildCount * 2) + nCurrExtra;

#if SVCPLUSA_A_DEBUG
                strMsg.Format(_T("\t\tPalette: %s, %u of %u\n"), ChildNode->szDesc, nExtraCtr + 1, nExtraCt);
                OutputDebugString(strMsg);
#endif

                nCurrExtra++;
                nTotalPaletteCount++;
            }
        }
    }

    strMsg.Format(_T("CGame_SVCPLUSA_A::InitDescTree: Loaded %u palettes for SVCPLUSA\n"), nTotalPaletteCount);
    OutputDebugString(strMsg);

    m_nTotalPaletteCountForSVCPLUSA = nTotalPaletteCount;

    // For development use to speed things up
    //DumpPaletteHeaders();

    return NewDescTree;
}

struct sSVCPLUSA_A_PaletteData
{
    LPCTSTR pszCharacterName;
    UINT32 nCoreOffset = 0;
    UINT32 nEffectsOffset = 0;
    UINT32 nWinPortraitOffset = 0;
    UINT32 nIntroPortraitOffset = 0;
    LPCTSTR pszImageSet = _T("");
    //bool rgIsEffectUsed[11];
};

//NORMY 0x364538 + 24000
//FX    0x388538 + 1F400
//INTRO 0x3a7938 + 2000
//WIN   0x3a9938

sSVCPLUSA_A_PaletteData SVCPLUSA_A_CharacterPalettes[] =
{
    { _T("Kyo"),            0x364538, 0x388538, 0x3a9938, 0x3a7938, _T("indexSVCSprites_Kyo") },
    { _T("Iori"),           0x365538, 0x388d38, 0x3a99b8, 0x3a79b8, _T("indexSVCSprites_Iori") },
    { _T("Ryo"),            0x366538, 0x389538, 0x3a9a38, 0x3a7a38, _T("indexSVCSprites_Ryo") },
    { _T("Terry"),          0x367538, 0x389d38, 0x3a9ab8, 0x3a7ab8, _T("indexSVCSprites_Terry") },
    { _T("Mai"),            0x368538, 0x38a538, 0x3a9b38, 0x3a7b38, _T("indexSVCSprites_Mai") },
    { _T("Kasumi"),         0x369538, 0x38ad38, 0x3a9bb8, 0x3a7bb8, _T("indexSVCSprites_Kasumi") },
    { _T("Kim"),            0x36a538,        0, 0x3a9c38, 0x3a7c38, _T("indexSVCSprites_Kim") },
    { _T("Mr. Karate"),     0x36b538, 0x38bd38, 0x3a9cb8, 0x3a7cb8, _T("indexSVCSprites_MrKarate") },
    { _T("Choi"),           0x36c538, 0x38c538, 0x3a9d38, 0x3a7d38, _T("indexSVCSprites_Choi") },
    { _T("Earthquake"),     0x36d538, 0x38cd38, 0x3a9db8, 0x3a7db8, _T("indexSVCSprites_Earthquake") },
    { _T("Genjuro"),        0x36e538, 0x38d538, 0x3a9e38, 0x3a7e38, _T("indexSVCSprites_Genjuro") },
    { _T("Shiki"),          0x36f538, 0x38dd38, 0x3a9eb8, 0x3a7eb8, _T("indexSVCSprites_Shiki") },
    { _T("Geese Howard"),   0x370538, 0x38e538, 0x3a9f38, 0x3a7f38, _T("indexSVCSprites_GeeseHoward") },
    { _T("Mars People"),    0x371538, 0x38ed38, 0x3a9fb8, 0x3a7fb8, _T("indexSVCSprites_MarsPeople") },
    { _T("Goenitz"),        0x372538, 0x38f538, 0x3aa038, 0x3a8038, _T("indexSVCSprites_Goenitz") },
    { _T("Princess Athena"), 0x373538, 0x38fd38, 0x3aa0b8, 0x3a80b8, _T("indexSVCSprites_PrincessAthena") },

    { _T("Ryu"),            0x374538, 0x390538, 0x3aa138, 0x3a8138, _T("indexSVCSprites_Ryu") },
    { _T("Ken"),            0x375538, 0x390d38, 0x3aa1b8, 0x3a81b8, _T("indexSVCSprites_Ken") },
    { _T("Chun-Li"),        0x376538, 0x391538, 0x3aa238, 0x3a8238, _T("indexSVCSprites_ChunLi") },
    { _T("Guile"),          0x377538, 0x391d38, 0x3aa2b8, 0x3a82b8, _T("indexSVCSprites_Guile") },
    { _T("Dhalsim"),        0x378538, 0x392538, 0x3aa338, 0x3a8338, _T("indexSVCSprites_Dhalsim") },
    { _T("Boxer"),          0x379538, 0x392d38, 0x3aa3b8, 0x3a83b8, _T("indexSVCSprites_Boxer") },
    { _T("Claw"),           0x37a538, 0x393538, 0x3aa438, 0x3a8438, _T("indexSVCSprites_Claw") },
    { _T("Sagat"),          0x37b538, 0x393d38, 0x3aa4b8, 0x3a84b8, _T("indexSVCSprites_Sagat") },
    { _T("Dictator"),       0x37c538, 0x394538, 0x3aa538, 0x3a8538, _T("indexSVCSprites_Dictator") },
    { _T("Akuma"),          0x37d538, 0x394d38, 0x3aa5b8, 0x3a85b8, _T("indexSVCSprites_Akuma") },
    { _T("Hugo"),           0x37e538, 0x395538, 0x3aa638, 0x3a8638, _T("indexSVCSprites_Hugo") },
        { _T("Poison"),            0,        0, 0x3aab38, 0x3a8c38, _T("indexSVCSprites_Poison") },
    { _T("Tessa"),          0x37f538, 0x395d38, 0x3aa6b8, 0x3a86b8, _T("indexSVCSprites_Tessa") },
    { _T("Zero"),           0x380538, 0x396538, 0x3aa738, 0x3a8738, _T("indexSVCSprites_Zero") },
        { _T("Ciel"),              0,        0,        0, 0x3a8bb8, _T("indexSVCSprites_Ciel") },
    { _T("Demitri"),        0x381538, 0x396d38, 0x3aa7b8, 0x3a87b8, _T("indexSVCSprites_Demitri") },
    { _T("Dan"),            0x382538, 0x397538, 0x3aa838, 0x3a8838, _T("indexSVCSprites_Dan") },
    { _T("Red Arremer"),    0x383538, 0x397d38, 0x3aa8b8, 0x3a88b8, _T("indexSVCSprites_RedArremer") },

    { _T("Orochi Iori"),    0x384538, 0x398538, 0x3aa938, 0x3a8938, _T("indexSVCSprites_OrochiIori") },
    { _T("Serious Mr. Karate"), 0x385538, 0x398d38, 0x3aa9b8, 0x3a89b8, _T("indexSVCSprites_SeriousMrKarate") },
    { _T("Violent Ken"),    0x386538, 0x399538, 0x3aaa38, 0x3a8a38, _T("indexSVCSprites_ViolentKen") },
    { _T("Shin Akuma"),     0x387538, 0x399d38, 0x3aaab8, 0x3a8ab8, _T("indexSVCSprites_ShinAkuma") },
};

const LPCTSTR SVC_CharacterEffectNames[] =
{
    _T("Fire Effect 1"),
    _T("Fire Effect 2"),
    _T("Electric Shock Effect"),
    _T("Red Arremer Transformation"),
    _T("Athena Transformation"),
    _T("Soul Palette"),
    _T("Midnight Bliss"),
};

void CGame_SVCPLUSA_A::DumpPaletteHeaders()
{
    CString strOutput;
    const UINT16 nColorOptionsPerCharacter = 2;
    constexpr UINT32 SVCPLUSA_PALETTE_LENGTH = 0x20;
    constexpr UINT16 c_nEffectsPerCharacter = 7;
    constexpr UINT32 c_nSVCDistanceBetweenColorss = 0x200;

    for (UINT16 nCharIndex = 0; nCharIndex < ARRAYSIZE(SVCPLUSA_A_CharacterPalettes); nCharIndex++)
    {
        TCHAR szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StrRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), SVCPLUSA_A_CharacterPalettes[nCharIndex].pszCharacterName);
        UINT32 nCurrentOffset = 0;

        nCurrentOffset = SVCPLUSA_A_CharacterPalettes[nCharIndex].nCoreOffset;

        if (nCurrentOffset != 0)
        {
            // First handle the core sprite and moves.
            for (UINT16 iButtonIndex = 0; iButtonIndex < ARRAYSIZE(DEF_BUTTONLABEL_SVC); iButtonIndex++)
            {
                if (iButtonIndex != 0)
                {
                    nCurrentOffset = SVCPLUSA_A_CharacterPalettes[nCharIndex].nCoreOffset + (iButtonIndex * 0x200);
                }

                TCHAR szCodeButtonLabel[MAX_DESCRIPTION_LENGTH];
                StrRemoveNonASCII(szCodeButtonLabel, ARRAYSIZE(szCodeButtonLabel), DEF_BUTTONLABEL_SVC[iButtonIndex]);

                strOutput.Format(_T("const sGame_PaletteDataset SVCPLUSA_A_%s_%s_PALETTES[] = \r\n{\r\n"), szCodeDesc, szCodeButtonLabel);
                OutputDebugString(strOutput);

                strOutput.Format(_T("    { _T(\"%s\"), 0x%x, 0x%x, %s },\r\n"), SVCPLUSA_A_CharacterPalettes[nCharIndex].pszCharacterName, nCurrentOffset, nCurrentOffset + SVCPLUSA_PALETTE_LENGTH, SVCPLUSA_A_CharacterPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);

                nCurrentOffset += SVCPLUSA_PALETTE_LENGTH;

                for (UINT16 nEffectIndex = 0; nEffectIndex < c_nEffectsPerCharacter; nEffectIndex++)
                {
                    strOutput.Format(_T("    { _T(\"%s\"), 0x%x, 0x%x, %s },\r\n"), SVC_CharacterEffectNames[nEffectIndex], nCurrentOffset, nCurrentOffset + SVCPLUSA_PALETTE_LENGTH, SVCPLUSA_A_CharacterPalettes[nCharIndex].pszImageSet);
                    OutputDebugString(strOutput);

                    nCurrentOffset += SVCPLUSA_PALETTE_LENGTH;
                }

                OutputDebugString(_T("};\r\n\r\n"));
            }
        } 

        nCurrentOffset = SVCPLUSA_A_CharacterPalettes[nCharIndex].nEffectsOffset;

        if (nCurrentOffset != 0)
        {
            constexpr UINT16 c_nExtraEffectsPerCharacter = 8;
            strOutput.Format(_T("const sGame_PaletteDataset SVCPLUSA_A_%s_%s_PALETTES[] = \r\n{\r\n"), szCodeDesc, _T("EFFECTS"));
            OutputDebugString(strOutput);

            for (UINT16 nEffectIndex = 0; nEffectIndex < c_nExtraEffectsPerCharacter; nEffectIndex++)
            {
                strOutput.Format(_T("    { _T(\"Effect %u\"), 0x%x, 0x%x },\r\n"), nEffectIndex, nCurrentOffset, nCurrentOffset + SVCPLUSA_PALETTE_LENGTH);
                OutputDebugString(strOutput);

                nCurrentOffset += SVCPLUSA_PALETTE_LENGTH;
            }

            OutputDebugString(_T("};\r\n\r\n"));
        }

        nCurrentOffset = SVCPLUSA_A_CharacterPalettes[nCharIndex].nWinPortraitOffset;

        if (nCurrentOffset != 0)
        {
            constexpr auto c_nWinPortraitPaletteLength = 0x40;
            constexpr auto c_nWinPortraitImageOffset = 0x21;

            strOutput.Format(_T("const sGame_PaletteDataset SVCPLUSA_A_%s_%s_PALETTES[] = \r\n{\r\n"), szCodeDesc, _T("WIN_PORTRAITS"));
            OutputDebugString(strOutput);

            for (UINT16 iButtonIndex = 0; iButtonIndex < ARRAYSIZE(DEF_BUTTONLABEL_SVC); iButtonIndex++)
            {
                strOutput.Format(_T("    { _T(\"%s %s\"), 0x%x, 0x%x, %s, 0x%02x },\r\n"), SVCPLUSA_A_CharacterPalettes[nCharIndex].pszCharacterName, DEF_BUTTONLABEL_SVC[iButtonIndex], nCurrentOffset, nCurrentOffset + c_nWinPortraitPaletteLength,
                                                                                SVCPLUSA_A_CharacterPalettes[nCharIndex].pszImageSet, c_nWinPortraitImageOffset);
                OutputDebugString(strOutput);

                nCurrentOffset += c_nWinPortraitPaletteLength;
            }

            OutputDebugString(_T("};\r\n\r\n"));
        }

        nCurrentOffset = SVCPLUSA_A_CharacterPalettes[nCharIndex].nIntroPortraitOffset;

        if (nCurrentOffset != 0)
        {
            constexpr auto c_nIntroPortraitPaletteLength = 0x40;
            constexpr auto c_nIntroPortraitImageOffset = 0x20;

            strOutput.Format(_T("const sGame_PaletteDataset SVCPLUSA_A_%s_%s_PALETTES[] = \r\n{\r\n"), szCodeDesc, _T("INTRO_PORTRAITS"));
            OutputDebugString(strOutput);

            for (UINT16 iButtonIndex = 0; iButtonIndex < ARRAYSIZE(DEF_BUTTONLABEL_SVC); iButtonIndex++)
            {
                strOutput.Format(_T("    { _T(\"%s %s\"), 0x%x, 0x%x, %s, 0x%02x },\r\n"), SVCPLUSA_A_CharacterPalettes[nCharIndex].pszCharacterName, DEF_BUTTONLABEL_SVC[iButtonIndex], nCurrentOffset, nCurrentOffset + c_nIntroPortraitPaletteLength,
                                                                                SVCPLUSA_A_CharacterPalettes[nCharIndex].pszImageSet, c_nIntroPortraitImageOffset);
                OutputDebugString(strOutput);

                nCurrentOffset += c_nIntroPortraitPaletteLength;
            }

            OutputDebugString(_T("};\r\n\r\n"));
        }
    }

    // All the collections...
    for (UINT16 nCharIndex = 0; nCharIndex < ARRAYSIZE(SVCPLUSA_A_CharacterPalettes); nCharIndex++)
    {
        TCHAR szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StrRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), SVCPLUSA_A_CharacterPalettes[nCharIndex].pszCharacterName);

        strOutput.Format(_T("const sDescTreeNode SVCPLUSA_A_%s_COLLECTION[] = \r\n{\r\n"), szCodeDesc);
        OutputDebugString(strOutput);

        if (SVCPLUSA_A_CharacterPalettes[nCharIndex].nCoreOffset != 0)
        {
            for (UINT16 nColorIndex = 0; nColorIndex < nColorOptionsPerCharacter; nColorIndex++)
            {
                TCHAR szColorOptionCodeDesc[MAX_DESCRIPTION_LENGTH];
                StrRemoveNonASCII(szColorOptionCodeDesc, ARRAYSIZE(szColorOptionCodeDesc), DEF_BUTTONLABEL_SVC[nColorIndex]);

                strOutput.Format(_T("    { _T(\"%s\"), DESC_NODETYPE_TREE, (void*)SVCPLUSA_A_%s_%s_PALETTES, ARRAYSIZE(SVCPLUSA_A_%s_%s_PALETTES) },\r\n"), DEF_BUTTONLABEL_SVC[nColorIndex], szCodeDesc, szColorOptionCodeDesc, szCodeDesc, szColorOptionCodeDesc);
                OutputDebugString(strOutput);
            }
        }

        if (SVCPLUSA_A_CharacterPalettes[nCharIndex].nEffectsOffset != 0)
        {
            strOutput.Format(_T("    { _T(\"Effects\"), DESC_NODETYPE_TREE, (void*)SVCPLUSA_A_%s_%s_PALETTES, ARRAYSIZE(SVCPLUSA_A_%s_%s_PALETTES) },\r\n"), szCodeDesc, _T("EFFECTS"), szCodeDesc, _T("EFFECTS"));
            OutputDebugString(strOutput);
        }

        if (SVCPLUSA_A_CharacterPalettes[nCharIndex].nWinPortraitOffset != 0)
        {
            strOutput.Format(_T("    { _T(\"Win Portraits\"), DESC_NODETYPE_TREE, (void*)SVCPLUSA_A_%s_%s_PALETTES, ARRAYSIZE(SVCPLUSA_A_%s_%s_PALETTES) },\r\n"), szCodeDesc, _T("WIN_PORTRAITS"), szCodeDesc, _T("WIN_PORTRAITS"));
            OutputDebugString(strOutput);
        }

        if (SVCPLUSA_A_CharacterPalettes[nCharIndex].nIntroPortraitOffset != 0)
        {
            strOutput.Format(_T("    { _T(\"Intro Portraits\"), DESC_NODETYPE_TREE, (void*)SVCPLUSA_A_%s_%s_PALETTES, ARRAYSIZE(SVCPLUSA_A_%s_%s_PALETTES) },\r\n"), szCodeDesc, _T("INTRO_PORTRAITS"), szCodeDesc, _T("INTRO_PORTRAITS"));
            OutputDebugString(strOutput);
        }

        OutputDebugString(_T("};\r\n\r\n"));
    }

    // And now the units...
    OutputDebugString(_T("const sDescTreeNode SVCPLUSA_A_UNITS[SVCPLUSA_A_NUMUNIT] =\n{\n"));

    for (UINT16 nCharIndex = 0; nCharIndex < ARRAYSIZE(SVCPLUSA_A_CharacterPalettes); nCharIndex++)
    {
        TCHAR szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StrRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), SVCPLUSA_A_CharacterPalettes[nCharIndex].pszCharacterName);

        strOutput.Format(_T("    { _T(\"%s\"), DESC_NODETYPE_TREE, (void*)SVCPLUSA_A_%s_COLLECTION, ARRAYSIZE(SVCPLUSA_A_%s_COLLECTION) },\r\n"), SVCPLUSA_A_CharacterPalettes[nCharIndex].pszCharacterName, szCodeDesc, szCodeDesc);
        OutputDebugString(strOutput);
    }

    OutputDebugString(_T("};\r\n\r\n"));
}

sFileRule CGame_SVCPLUSA_A::GetRule(UINT16 nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _stprintf_s(NewFileRule.szFileName, MAX_FILENAME_LENGTH, _T("svc-p2pl.bin"));

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nGameROMSize;

    return NewFileRule;
}

UINT16 CGame_SVCPLUSA_A::GetCollectionCountForUnit(UINT16 nUnitId)
{
    if (nUnitId == SVCPLUSA_A_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        return SVCPLUSA_A_UNITS[nUnitId].uChildAmt;
    }
}

UINT16 CGame_SVCPLUSA_A::GetNodeCountForCollection(UINT16 nUnitId, UINT16 nCollectionId)
{
    if (nUnitId == SVCPLUSA_A_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        const sDescTreeNode* pCollectionNode = (const sDescTreeNode*)(SVCPLUSA_A_UNITS[nUnitId].ChildNodes);

        return pCollectionNode[nCollectionId].uChildAmt;
    }
}

LPCTSTR CGame_SVCPLUSA_A::GetDescriptionForCollection(UINT16 nUnitId, UINT16 nCollectionId)
{
    if (nUnitId == SVCPLUSA_A_EXTRALOC)
    {
        return _T("Extra Palettes");
    }
    else
    {
        const sDescTreeNode* pCollection = (const sDescTreeNode*)SVCPLUSA_A_UNITS[nUnitId].ChildNodes;
        return pCollection[nCollectionId].szDesc;
    }
}

UINT16 CGame_SVCPLUSA_A::GetPaletteCountForUnit(UINT16 nUnitId)
{
    if (nUnitId == SVCPLUSA_A_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        UINT16 nCompleteCount = 0;
        const sDescTreeNode* pCompleteROMTree = SVCPLUSA_A_UNITS;
        UINT16 nCollectionCount = pCompleteROMTree[nUnitId].uChildAmt;

        const sDescTreeNode* pCurrentCollection = (const sDescTreeNode*)(pCompleteROMTree[nUnitId].ChildNodes);

        for (UINT16 nCollectionIndex = 0; nCollectionIndex < nCollectionCount; nCollectionIndex++)
        {
            nCompleteCount += pCurrentCollection[nCollectionIndex].uChildAmt;
        }

#if SVCPLUSA_A_DEBUG
        CString strMsg;
        strMsg.Format(_T("CGame_SVCPLUSA_A::GetPaletteCountForUnit: %u for unit %u which has %u collections.\n"), nCompleteCount, nUnitId, nCollectionCount);
        OutputDebugString(strMsg);
#endif

        return nCompleteCount;
    }
}

const sGame_PaletteDataset* CGame_SVCPLUSA_A::GetPaletteSet(UINT16 nUnitId, UINT16 nCollectionId)
{
    // Don't use this for Extra palettes.
    const sDescTreeNode* pCurrentSet = (const sDescTreeNode*)SVCPLUSA_A_UNITS[nUnitId].ChildNodes;
    return ((sGame_PaletteDataset*)(pCurrentSet[nCollectionId].ChildNodes));
}

const sDescTreeNode* CGame_SVCPLUSA_A::GetNodeFromPaletteId(UINT16 nUnitId, UINT16 nPaletteId, bool fReturnBasicNodesOnly)
{
    // Don't use this for Extra palettes.
    const sDescTreeNode* pCollectionNode = nullptr;
    UINT16 nTotalCollections = GetCollectionCountForUnit(nUnitId);
    const sGame_PaletteDataset* paletteSetToUse = nullptr;
    int nDistanceFromZero = nPaletteId;

    for (int nCollectionIndex = 0; nCollectionIndex < nTotalCollections; nCollectionIndex++)
    {
        const sGame_PaletteDataset* paletteSetToCheck = GetPaletteSet(nUnitId, nCollectionIndex);
        UINT16 nNodeCount;

        if (nUnitId == SVCPLUSA_A_EXTRALOC)
        {
            nNodeCount = GetExtraCt(nUnitId);

            if (nDistanceFromZero < nNodeCount)
            {
                pCollectionNode = nullptr;
                break;
            }
        }
        else
        {
            const sDescTreeNode* pCollectionNodeToCheck = (const sDescTreeNode*)(SVCPLUSA_A_UNITS[nUnitId].ChildNodes);
            
            nNodeCount = pCollectionNodeToCheck[nCollectionIndex].uChildAmt;

            if (nDistanceFromZero < nNodeCount)
            {
                // We know it's within this group.  Now: is it basic?
                if (!fReturnBasicNodesOnly || (nCollectionIndex < m_nNumberOfColorOptions))
                {
                    pCollectionNode = &(pCollectionNodeToCheck[nCollectionIndex]);
                }
                else
                {
                    pCollectionNode = nullptr;
                }

                break;
            }
        }

        nDistanceFromZero -= nNodeCount;
    }

    return pCollectionNode;
}

const sGame_PaletteDataset* CGame_SVCPLUSA_A::GetSpecificPalette(UINT16 nUnitId, UINT16 nPaletteId)
{
    // Don't use this for Extra palettes.
    UINT16 nTotalCollections = GetCollectionCountForUnit(nUnitId);
    const sGame_PaletteDataset* paletteToUse = nullptr;
    int nDistanceFromZero = nPaletteId;

    for (int nCollectionIndex = 0; nCollectionIndex < nTotalCollections; nCollectionIndex++)
    {
        const sGame_PaletteDataset* paletteSetToUse = GetPaletteSet(nUnitId, nCollectionIndex);
        UINT16 nNodeCount = GetNodeCountForCollection(nUnitId, nCollectionIndex);

        if (nDistanceFromZero < nNodeCount)
        {
            paletteToUse = &paletteSetToUse[nDistanceFromZero];
            break;
        }

        nDistanceFromZero -= nNodeCount;
    }

    return paletteToUse;
}

void CGame_SVCPLUSA_A::InitDataBuffer()
{
    pppDataBuffer = new UINT16 * *[nUnitAmt];
    memset(pppDataBuffer, NULL, sizeof(UINT16**) * nUnitAmt);
}

void CGame_SVCPLUSA_A::ClearDataBuffer()
{
    if (pppDataBuffer)
    {
        for (UINT16 nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
        {
            if (pppDataBuffer[nUnitCtr])
            {
                UINT16 nPalAmt = GetPaletteCountForUnit(nUnitCtr);

                for (UINT16 nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
                {
                    safe_delete_array(pppDataBuffer[nUnitCtr][nPalCtr]);
                }

                safe_delete_array(pppDataBuffer[nUnitCtr]);
            }
        }

        safe_delete_array(pppDataBuffer);
    }
}

void CGame_SVCPLUSA_A::LoadSpecificPaletteData(UINT16 nUnitId, UINT16 nPalId)
{
     if (nUnitId != SVCPLUSA_A_EXTRALOC)
    {
        int cbPaletteSizeOnDisc = 0;
        const sGame_PaletteDataset* paletteData = GetSpecificPalette(nUnitId, nPalId);

        if (paletteData)
        {
            cbPaletteSizeOnDisc = (int)max(0, (paletteData->nPaletteOffsetEnd - paletteData->nPaletteOffset));

            nCurrPalOffs = paletteData->nPaletteOffset;
            m_nCurrentPaletteSize = cbPaletteSizeOnDisc / 2;
            m_pszCurrentPaletteName = paletteData->szPaletteName;
        }
        else
        {
            // A bogus palette was requested: this is unrecoverable.
            DebugBreak();
        }
    }
    else // SVCPLUSA_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForSVCPLUSA(GetExtraLoc(nUnitId) + nPalId);

        nCurrPalOffs = pCurrDef->uOffset;
        m_nCurrentPaletteSize = (pCurrDef->cbPaletteSize / 2);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }

    m_nCurrentPaletteROMLocation = nCurrPalOffs;
}

BOOL CGame_SVCPLUSA_A::LoadFile(CFile* LoadedFile, UINT16 nUnitId)
{
    for (UINT16 nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
    {
        int nPalAmt = GetPaletteCountForUnit(nUnitCtr);

        pppDataBuffer[nUnitCtr] = new UINT16 * [nPalAmt];

        // Use a sorted layout
        rgUnitRedir[nUnitCtr] = SVCPLUSA_A_UNITSORT[nUnitCtr];

        for (UINT16 nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
        {
            LoadSpecificPaletteData(nUnitCtr, nPalCtr);

            pppDataBuffer[nUnitCtr][nPalCtr] = new UINT16[m_nCurrentPaletteSize];

            LoadedFile->Seek(nCurrPalOffs, CFile::begin);

            LoadedFile->Read(pppDataBuffer[nUnitCtr][nPalCtr], m_nCurrentPaletteSize * 2);
        }
    }

    rgUnitRedir[nUnitAmt] = INVALID_UNIT_VALUE;
    
    CheckForErrorsInTables();

    return TRUE;
}

BOOL CGame_SVCPLUSA_A::SaveFile(CFile* SaveFile, UINT16 nUnitId)
{
    UINT32 nTotalPalettesSaved = 0;
    bool fShownOnce = false;

    for (UINT16 nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
    {
        UINT16 nPalAmt = GetPaletteCountForUnit(nUnitCtr);

        for (UINT16 nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
        {
            LoadSpecificPaletteData(nUnitCtr, nPalCtr);

            if (!fShownOnce && (nCurrPalOffs < m_nLowestKnownPaletteRomLocation)) // This magic number is the lowest known ROM location.
            {
                CString strMsg;
                strMsg.Format(_T("Warning: Unit %u palette %u is trying to write to ROM location 0x%06x which is lower than we usually write to."), nUnitCtr, nPalCtr, nCurrPalOffs);
                MessageBox(g_appHWnd, strMsg, GetHost()->GetAppName(), MB_ICONERROR);
                fShownOnce = true;
            }

            SaveFile->Seek(nCurrPalOffs, CFile::begin);
            SaveFile->Write(pppDataBuffer[nUnitCtr][nPalCtr], m_nCurrentPaletteSize * 2);
            nTotalPalettesSaved++;
        }
    }

    CString strMsg;
    strMsg.Format(_T("CGame_SVCPLUSA_A::SaveFile: Saved 0x%x palettes to disk for %u units\n"), nTotalPalettesSaved, nUnitAmt);
    OutputDebugString(strMsg);

    return TRUE;
}

void CGame_SVCPLUSA_A::CreateDefPal(sDescNode* srcNode, UINT16 nSepId)
{
    UINT16 nUnitId = srcNode->uUnitId;
    UINT16 nPalId = srcNode->uPalId;
    static DWORD s_nColorsPerPage = CRegProc::GetMaxPalettePageSize();

    LoadSpecificPaletteData(nUnitId, nPalId);

    const UINT8 nTotalPagesNeeded = (UINT8)ceil(m_nCurrentPaletteSize / s_nColorsPerPage);
    const bool fCanFitWithinCurrentPageLayout = (nTotalPagesNeeded <= MAX_PALETTE_PAGES);

    if (!fCanFitWithinCurrentPageLayout)
    {
        CString strWarning;
        strWarning.Format(_T("ERROR: The UI currently only supports %u pages. \"%s\" is trying to use %u pages which will not work.\n"), MAX_PALETTE_PAGES, srcNode->szDesc, nTotalPagesNeeded);
        OutputDebugString(strWarning);
    }

    BasePalGroup.AddPal(CreatePal(nUnitId, nPalId), m_nCurrentPaletteSize, nUnitId, nPalId);

    if (fCanFitWithinCurrentPageLayout && (m_nCurrentPaletteSize > s_nColorsPerPage))
    {
        CString strPageDescription;
        int nColorsRemaining = m_nCurrentPaletteSize;

        for (UINT16 nCurrentPage = 0; (nCurrentPage * s_nColorsPerPage) < m_nCurrentPaletteSize; nCurrentPage++)
        {
            strPageDescription.Format(_T("%s (%u/%u)"), srcNode->szDesc, nCurrentPage + 1, nTotalPagesNeeded);
            BasePalGroup.AddSep(0, strPageDescription, nCurrentPage * s_nColorsPerPage, min(s_nColorsPerPage, (DWORD)nColorsRemaining));
            nColorsRemaining -= s_nColorsPerPage;
        }
    }
    else
    {
        BasePalGroup.AddSep(nSepId, srcNode->szDesc, 0, m_nCurrentPaletteSize);
    }
}

BOOL CGame_SVCPLUSA_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    //Reset palette sources
    ClearSrcPal();

    if (Node01 == -1)
    {
        return FALSE;
    }

    sDescNode* NodeGet = MainDescTree.GetDescNode(Node01, Node02, Node03, Node04);

    if (NodeGet == nullptr)
    {
        return FALSE;
    }

    // Default values for multisprite image display for Export
    int nSrcStart = 0;
    int nSrcAmt = 0;
    UINT16 nNodeIncrement = 1;

    //Get rid of any palettes if there are any
    BasePalGroup.FlushPalAll();

    // Make sure to reset the image id
    nTargetImgId = 0;
    UINT16 nImgUnitId = INVALID_UNIT_VALUE;

    bool fShouldUseAlternateLoadLogic = false;

    // Only load images for internal units, since we don't currently have a methodology for associating
    // external loads to internal sprites.
    if (NodeGet->uUnitId != SVCPLUSA_A_EXTRALOC)
    {
        const sGame_PaletteDataset* paletteDataSet = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId);

        nSrcStart = NodeGet->uPalId;
        nSrcAmt = 1;

        if (paletteDataSet)
        {
            nImgUnitId = paletteDataSet->indexImgToUse;
            nTargetImgId = paletteDataSet->indexOffsetToUse;

            const sDescTreeNode* pCurrentNode = GetNodeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId, false);

            if (pCurrentNode)
            {
                if ((_tcsicmp(pCurrentNode->szDesc, _T("Punch")) == 0) || (_tcsicmp(pCurrentNode->szDesc, _T("Kick")) == 0))
                {
                    nSrcAmt = 2;
                    nNodeIncrement = pCurrentNode->uChildAmt;

                    while (nSrcStart >= nNodeIncrement)
                    {
                        // The starting point is the absolute first palette for the sprite in question which is found in P1
                        nSrcStart -= nNodeIncrement;
                    }
                }
            }

            if (paletteDataSet->pPalettePairingInfo)
            {
                // Right now this just needs to handle the weird Athena palette.
                fShouldUseAlternateLoadLogic = true;

                int nPaletteTwoDelta = 1;
                int nPaletteThreeDelta = 2;
                int nPaletteFourDelta = 5;

                const sGame_PaletteDataset* paletteDataSetOne = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId);
                const sGame_PaletteDataset* paletteDataSetTwo = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + nPaletteTwoDelta);
                const sGame_PaletteDataset* paletteDataSetThree = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + nPaletteThreeDelta);
                const sGame_PaletteDataset* paletteDataSetFour = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + nPaletteFourDelta);

                ClearSetImgTicket(
                    CreateImgTicket(paletteDataSetOne->indexImgToUse, paletteDataSetOne->indexOffsetToUse,
                        CreateImgTicket(paletteDataSetTwo->indexImgToUse, paletteDataSetTwo->indexOffsetToUse,
                            CreateImgTicket(paletteDataSetThree->indexImgToUse, paletteDataSetThree->indexOffsetToUse,
                                CreateImgTicket(paletteDataSetFour->indexImgToUse, paletteDataSetFour->indexOffsetToUse
                                    )))));


                //Set each palette
                sDescNode* JoinedNode[4] = {
                    MainDescTree.GetDescNode(Node01, Node02, Node03, -1),
                    MainDescTree.GetDescNode(Node01, Node02, Node03 + nPaletteTwoDelta, -1),
                    MainDescTree.GetDescNode(Node01, Node02, Node03 + nPaletteThreeDelta, -1),
                    MainDescTree.GetDescNode(Node01, Node02, Node03 + nPaletteFourDelta, -1)
                };

                //Set each palette
                CreateDefPal(JoinedNode[0], 0);
                CreateDefPal(JoinedNode[1], 1);
                CreateDefPal(JoinedNode[2], 2);
                CreateDefPal(JoinedNode[3], 3);

                SetSourcePal(0, NodeGet->uUnitId, nSrcStart, nSrcAmt, nNodeIncrement);
                SetSourcePal(1, NodeGet->uUnitId, nSrcStart + nPaletteTwoDelta, nSrcAmt, nNodeIncrement);
                SetSourcePal(2, NodeGet->uUnitId, nSrcStart + nPaletteThreeDelta, nSrcAmt, nNodeIncrement);
                SetSourcePal(3, NodeGet->uUnitId, nSrcStart + nPaletteFourDelta, nSrcAmt, nNodeIncrement);
            }
        }
    }

    if (!fShouldUseAlternateLoadLogic)
    {
        //Create the default palette
        ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

        CreateDefPal(NodeGet, 0);

        SetSourcePal(0, NodeGet->uUnitId, nSrcStart, nSrcAmt, nNodeIncrement);
    }

    return TRUE;
}

COLORREF* CGame_SVCPLUSA_A::CreatePal(UINT16 nUnitId, UINT16 nPalId)
{
    LoadSpecificPaletteData(nUnitId, nPalId);

    COLORREF* NewPal = new COLORREF[m_nCurrentPaletteSize];

    for (int i = 0; i < m_nCurrentPaletteSize; i++)
    {
        NewPal[i] = ConvPal(pppDataBuffer[nUnitId][nPalId][i]);
    }

    return NewPal;
}

void CGame_SVCPLUSA_A::UpdatePalData()
{
    for (int nPalCtr = 0; nPalCtr < MAX_PAL; nPalCtr++)
    {
        sPalDef* srcDef = BasePalGroup.GetPalDef(nPalCtr);

        if (srcDef->bAvail)
        {
            COLORREF* crSrc = srcDef->pPal;

            int nTotalColorsRemaining = srcDef->uPalSz;
            UINT16 nCurrentTotalWrites = 0;
            const UINT16 nMaxSafeColorsToWrite = 16;
            // First color is the transparency color
            const UINT16 iFixedCounterPosition = 0;

            while (nTotalColorsRemaining > 0)
            {
                UINT16 nCurrentColorCountToWrite = min(nMaxSafeColorsToWrite, nTotalColorsRemaining);

                for (int nPICtr = 0; nPICtr < nCurrentColorCountToWrite; nPICtr++)
                {
                    if (nPICtr == iFixedCounterPosition)
                    {
                        continue;
                    }

                    UINT16 iCurrentArrayOffset = nPICtr + nCurrentTotalWrites;
                    pppDataBuffer[srcDef->uUnitId][srcDef->uPalId][iCurrentArrayOffset] = ConvCol(crSrc[iCurrentArrayOffset]);
                }

                nCurrentTotalWrites += nMaxSafeColorsToWrite;
                nTotalColorsRemaining -= nMaxSafeColorsToWrite;
            }

            srcDef->bChanged = FALSE;
            rgFileChanged[0] = TRUE;
        }
    }
}