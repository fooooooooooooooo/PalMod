#include "StdAfx.h"
#include "GameDef.h"
#include "Game_Garou_S.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

#define Garou_S_DEBUG DEFAULT_GAME_DEBUG_STATE

stExtraDef* CGame_Garou_S::Garou_S_EXTRA_CUSTOM = nullptr;

CDescTree CGame_Garou_S::MainDescTree = nullptr;

int CGame_Garou_S::rgExtraCountAll[Garou_S_NUMUNIT + 1];
int CGame_Garou_S::rgExtraLoc[Garou_S_NUMUNIT + 1];

UINT32 CGame_Garou_S::m_nTotalPaletteCountForGarou = 0;
UINT32 CGame_Garou_S::m_nExpectedGameROMSize = 0x900000; // 9,437,184 bytes
UINT32 CGame_Garou_S::m_nConfirmedROMSize = -1;

void CGame_Garou_S::InitializeStatics()
{
    safe_delete_array(CGame_Garou_S::Garou_S_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_Garou_S::InitDescTree());
}

CGame_Garou_S::CGame_Garou_S(UINT32 nConfirmedROMSize)
{
    CString strMessage;
    strMessage.Format(_T("CGame_Garou_S::CGame_Garou_S: Loading ROM...\n"));
    OutputDebugString(strMessage);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = Garou_S_NUMUNIT;
    m_nExtraUnit = Garou_S_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 1195;
    m_pszExtraFilename = EXTRA_FILENAME_Garou_S;
    m_nTotalPaletteCount = m_nTotalPaletteCountForGarou;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0xce040;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    createPalOptions = { NO_SPECIAL_OPTIONS, WRITE_16 };
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_NEOGEO);

    //Set palette conversion mode
    BasePalGroup.SetMode(ePalType::PALTYPE_8);

    //Set game information
    nGameFlag = Garou_S;
    nImgGameFlag = IMGDAT_SECTION_GAROU;
    nImgUnitAmt = GAROU_A_NUM_IMG_UNITS;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    // The MOTW options are A B C D (Boss)
    pButtonLabelSet = DEF_BUTTONLABEL_NEOGEO_FIVE;
    m_nNumberOfColorOptions = ARRAYSIZE(DEF_BUTTONLABEL_NEOGEO_FIVE);

    //Create the redirect buffer
    rgUnitRedir = new UINT16[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(UINT16) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_Garou_S::~CGame_Garou_S(void)
{
    safe_delete_array(CGame_Garou_S::Garou_S_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

CDescTree* CGame_Garou_S::GetMainTree()
{
    return &CGame_Garou_S::MainDescTree;
}

int CGame_Garou_S::GetExtraCt(UINT16 nUnitId, BOOL bCountVisibleOnly)
{
    if (rgExtraCountAll[0] == -1)
    {
        int nDefCtr = 0;
        memset(rgExtraCountAll, 0, ((Garou_S_NUMUNIT + 1) * sizeof(int)));

        stExtraDef* pCurrDef = GetExtraDefForGarou_S(0);

        while (pCurrDef->uUnitN != INVALID_UNIT_VALUE)
        {
            if (!pCurrDef->isInvisible || !bCountVisibleOnly)
            {
                rgExtraCountAll[pCurrDef->uUnitN]++;
            }

            nDefCtr++;
            pCurrDef = GetExtraDefForGarou_S(nDefCtr);
        }
    }

    return rgExtraCountAll[nUnitId];
}

int CGame_Garou_S::GetExtraLoc(UINT16 nUnitId)
{
    if (rgExtraLoc[0] == -1)
    {
        int nDefCtr = 0;
        int nCurrUnit = UNIT_START_VALUE;
        memset(rgExtraLoc, 0, (Garou_S_NUMUNIT + 1) * sizeof(int));

        stExtraDef* pCurrDef = GetExtraDefForGarou_S(0);

        while (pCurrDef->uUnitN != INVALID_UNIT_VALUE)
        {
            if (pCurrDef->uUnitN != nCurrUnit)
            {
                rgExtraLoc[pCurrDef->uUnitN] = nDefCtr;
                nCurrUnit = pCurrDef->uUnitN;
            }

            nDefCtr++;
            pCurrDef = GetExtraDefForGarou_S(nDefCtr);
        }
    }

    return rgExtraLoc[nUnitId];
}

sDescTreeNode* CGame_Garou_S::InitDescTree()
{
    UINT32 nTotalPaletteCount = 0;

    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_Garou_S, Garou_S_EXTRA, &Garou_S_EXTRA_CUSTOM, Garou_S_EXTRALOC, m_nConfirmedROMSize);

    UINT16 nUnitCt = Garou_S_NUMUNIT + (GetExtraCt(Garou_S_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _stprintf(NewDescTree->szDesc, _T("%s"), g_GameFriendlyName[Garou_S]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    CString strMsg;
    bool fHaveExtras = (GetExtraCt(Garou_S_EXTRALOC) > 0);
    strMsg.Format(_T("CGame_Garou_S::InitDescTree: Building desc tree for Garou_S %s extras...\n"), fHaveExtras ? _T("with") : _T("without"));
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

        if (iUnitCtr < Garou_S_EXTRALOC)
        {
            //Set each description
            _stprintf(UnitNode->szDesc, _T("%s"), Garou_S_UNITS[iUnitCtr].szDesc);
            UnitNode->ChildNodes = new sDescTreeNode[nUnitChildCount];
            //All children have collection trees
            UnitNode->uChildType = DESC_NODETYPE_TREE;
            UnitNode->uChildAmt = nUnitChildCount;

#if Garou_S_DEBUG
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

#if Garou_S_DEBUG
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

#if Garou_S_DEBUG
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

#if Garou_S_DEBUG
            strMsg.Format(_T("Unit (Extras): %s, %u of %u, %u total children\n"), UnitNode->szDesc, iUnitCtr + 1, nUnitCt, nUnitChildCount);
            OutputDebugString(strMsg);
#endif
        }

        //Set up extra nodes
        if (bUseExtra)
        {
            int nExtraPos = GetExtraLoc(iUnitCtr);
            int nCurrExtra = 0;

            CollectionNode = &((sDescTreeNode*)UnitNode->ChildNodes)[(Garou_S_EXTRALOC > iUnitCtr) ? (nUnitChildCount - 1) : 0]; //Extra node

            _stprintf(CollectionNode->szDesc, _T("Extra"));

            CollectionNode->ChildNodes = new sDescTreeNode[nExtraCt];

            CollectionNode->uChildType = DESC_NODETYPE_NODE;
            CollectionNode->uChildAmt = nExtraCt; //EX + Extra

#if Garou_S_DEBUG
            strMsg.Format(_T("\tCollection: %s, %u of %u, %u children\n"), CollectionNode->szDesc, 1, nUnitChildCount, nExtraCt);
            OutputDebugString(strMsg);
#endif

            for (UINT16 nExtraCtr = 0; nExtraCtr < nExtraCt; nExtraCtr++)
            {
                ChildNode = &((sDescNode*)CollectionNode->ChildNodes)[nExtraCtr];

                stExtraDef* pCurrDef = GetExtraDefForGarou_S(nExtraPos + nCurrExtra);

                while (pCurrDef->isInvisible)
                {
                    nCurrExtra++;

                    pCurrDef = GetExtraDefForGarou_S(nExtraPos + nCurrExtra);
                }

                _stprintf(ChildNode->szDesc, pCurrDef->szDesc);

                ChildNode->uUnitId = iUnitCtr;
                ChildNode->uPalId = (((Garou_S_EXTRALOC > iUnitCtr) ? 1 : 0) * nUnitChildCount * 2) + nCurrExtra;

#if Garou_S_DEBUG
                strMsg.Format(_T("\t\tPalette: %s, %u of %u\n"), ChildNode->szDesc, nExtraCtr + 1, nExtraCt);
                OutputDebugString(strMsg);
#endif

                nCurrExtra++;
                nTotalPaletteCount++;
            }
        }
    }

    strMsg.Format(_T("CGame_Garou_S::InitDescTree: Loaded %u palettes for Garou\n"), nTotalPaletteCount);
    OutputDebugString(strMsg);

    m_nTotalPaletteCountForGarou = nTotalPaletteCount;

    return NewDescTree;
}

sFileRule CGame_Garou_S::GetRule(UINT16 nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _stprintf_s(NewFileRule.szFileName, MAX_FILENAME_LENGTH, _T("p1.bin"));

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

UINT16 CGame_Garou_S::GetCollectionCountForUnit(UINT16 nUnitId)
{
    if (nUnitId == Garou_S_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        return Garou_S_UNITS[nUnitId].uChildAmt;
    }
}

UINT16 CGame_Garou_S::GetNodeCountForCollection(UINT16 nUnitId, UINT16 nCollectionId)
{
    if (nUnitId == Garou_S_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        const sDescTreeNode* pCollectionNode = (const sDescTreeNode*)(Garou_S_UNITS[nUnitId].ChildNodes);

        return pCollectionNode[nCollectionId].uChildAmt;
    }
}

LPCTSTR CGame_Garou_S::GetDescriptionForCollection(UINT16 nUnitId, UINT16 nCollectionId)
{
    if (nUnitId == Garou_S_EXTRALOC)
    {
        return _T("Extra Palettes");
    }
    else
    {
        const sDescTreeNode* pCollection = (const sDescTreeNode*)Garou_S_UNITS[nUnitId].ChildNodes;
        return pCollection[nCollectionId].szDesc;
    }
}

UINT16 CGame_Garou_S::GetPaletteCountForUnit(UINT16 nUnitId)
{
    if (nUnitId == Garou_S_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        UINT16 nCompleteCount = 0;
        const sDescTreeNode* pCompleteROMTree = Garou_S_UNITS;
        UINT16 nCollectionCount = pCompleteROMTree[nUnitId].uChildAmt;

        const sDescTreeNode* pCurrentCollection = (const sDescTreeNode*)(pCompleteROMTree[nUnitId].ChildNodes);

        for (UINT16 nCollectionIndex = 0; nCollectionIndex < nCollectionCount; nCollectionIndex++)
        {
            nCompleteCount += pCurrentCollection[nCollectionIndex].uChildAmt;
        }

#if Garou_S_DEBUG
        CString strMsg;
        strMsg.Format(_T("CGame_Garou_S::GetPaletteCountForUnit: %u for unit %u which has %u collections.\n"), nCompleteCount, nUnitId, nCollectionCount);
        OutputDebugString(strMsg);
#endif

        return nCompleteCount;
    }
}

const sGame_PaletteDataset* CGame_Garou_S::GetPaletteSet(UINT16 nUnitId, UINT16 nCollectionId)
{
    // Don't use this for Extra palettes.
    const sDescTreeNode* pCurrentSet = (const sDescTreeNode*)Garou_S_UNITS[nUnitId].ChildNodes;
    return ((sGame_PaletteDataset*)(pCurrentSet[nCollectionId].ChildNodes));
}

const sDescTreeNode* CGame_Garou_S::GetNodeFromPaletteId(UINT16 nUnitId, UINT16 nPaletteId, bool fReturnBasicNodesOnly)
{
    // Don't use this for Extra palettes.
    const sDescTreeNode* pCollectionNode = nullptr;
    UINT16 nTotalCollections = GetCollectionCountForUnit(nUnitId);
    const sGame_PaletteDataset* paletteSetToUse = nullptr;
    int nDistanceFromZero = nPaletteId;

    for (UINT16 nCollectionIndex = 0; nCollectionIndex < nTotalCollections; nCollectionIndex++)
    {
        const sGame_PaletteDataset* paletteSetToCheck = GetPaletteSet(nUnitId, nCollectionIndex);
        UINT16 nNodeCount;

        if (nUnitId == Garou_S_EXTRALOC)
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
            const sDescTreeNode* pCollectionNodeToCheck = (const sDescTreeNode*)(Garou_S_UNITS[nUnitId].ChildNodes);
            
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

const sGame_PaletteDataset* CGame_Garou_S::GetSpecificPalette(UINT16 nUnitId, UINT16 nPaletteId)
{
    // Don't use this for Extra palettes.
    UINT16 nTotalCollections = GetCollectionCountForUnit(nUnitId);
    const sGame_PaletteDataset* paletteToUse = nullptr;
    int nDistanceFromZero = nPaletteId;

    for (UINT16 nCollectionIndex = 0; nCollectionIndex < nTotalCollections; nCollectionIndex++)
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

void CGame_Garou_S::LoadSpecificPaletteData(UINT16 nUnitId, UINT16 nPalId)
{
     if (nUnitId != Garou_S_EXTRALOC)
    {
        int cbPaletteSizeOnDisc = 0;
        const sGame_PaletteDataset* paletteData = GetSpecificPalette(nUnitId, nPalId);

        if (paletteData)
        {
            cbPaletteSizeOnDisc = (int)max(0, (paletteData->nPaletteOffsetEnd - paletteData->nPaletteOffset));

            m_nCurrentPaletteROMLocation = paletteData->nPaletteOffset;
            m_nCurrentPaletteSize = cbPaletteSizeOnDisc / 2;
            m_pszCurrentPaletteName = paletteData->szPaletteName;
        }
        else
        {
            // A bogus palette was requested: this is unrecoverable.
            DebugBreak();
        }
    }
    else // Garou_S_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForGarou_S(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSize = (pCurrDef->cbPaletteSize / 2);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_Garou_S::LoadFile(CFile* LoadedFile, UINT16 nUnitId)
{
    for (UINT16 nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
    {
        UINT16 nPalAmt = GetPaletteCountForUnit(nUnitCtr);

        m_pppDataBuffer[nUnitCtr] = new UINT16 * [nPalAmt];

        // Use a sorted layout
        rgUnitRedir[nUnitCtr] = Garou_S_UNITSORT[nUnitCtr];

        for (UINT16 nPalCtr = 0; nPalCtr < nPalAmt; nPalCtr++)
        {
            LoadSpecificPaletteData(nUnitCtr, nPalCtr);

            m_pppDataBuffer[nUnitCtr][nPalCtr] = new UINT16[m_nCurrentPaletteSize];

            LoadedFile->Seek(m_nCurrentPaletteROMLocation, CFile::begin);

            LoadedFile->Read(m_pppDataBuffer[nUnitCtr][nPalCtr], m_nCurrentPaletteSize * 2);
        }
    }

    rgUnitRedir[nUnitAmt] = INVALID_UNIT_VALUE;
    
    CheckForErrorsInTables();

    return TRUE;
}

void CGame_Garou_S::CreateDefPal(sDescNode* srcNode, UINT16 nSepId)
{
    UINT16 nUnitId = srcNode->uUnitId;
    UINT16 nPalId = srcNode->uPalId;
    static UINT16 s_nColorsPerPage = CRegProc::GetMaxPalettePageSize();

    LoadSpecificPaletteData(nUnitId, nPalId);

    const UINT8 nTotalPagesNeeded = (UINT8)ceil((double)m_nCurrentPaletteSize / (double)s_nColorsPerPage);
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
        INT16 nColorsRemaining = m_nCurrentPaletteSize;

        for (UINT16 nCurrentPage = 0; (nCurrentPage * s_nColorsPerPage) < m_nCurrentPaletteSize; nCurrentPage++)
        {
            strPageDescription.Format(_T("%s (%u/%u)"), srcNode->szDesc, nCurrentPage + 1, nTotalPagesNeeded);
            BasePalGroup.AddSep(nSepId, strPageDescription, nCurrentPage * s_nColorsPerPage, min(s_nColorsPerPage, (DWORD)nColorsRemaining));
            nColorsRemaining -= s_nColorsPerPage;
        }
    }
    else
    {
        BasePalGroup.AddSep(nSepId, srcNode->szDesc, 0, m_nCurrentPaletteSize);
    }
}

BOOL CGame_Garou_S::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    //Reset palette sources
    ClearSrcPal();

    if (Node01 == -1)
    {
        return FALSE;
    }

    sDescNode* NodeGet = GetMainTree()->GetDescNode(Node01, Node02, Node03, Node04);

    if (NodeGet == nullptr)
    {
        return FALSE;
    }

    // Default values for multisprite image display for Export
    UINT16 nSrcStart = NodeGet->uPalId;
    UINT16 nSrcAmt = 1;
    UINT16 nNodeIncrement = 1;

    //Get rid of any palettes if there are any
    BasePalGroup.FlushPalAll();

    // Make sure to reset the image id
    nTargetImgId = 0;
    UINT16 nImgUnitId = INVALID_UNIT_VALUE;

    bool fShouldUseAlternateLoadLogic = false;

    // Only load images for internal units, since we don't currently have a methodology for associating
    // external loads to internal sprites.
    if (NodeGet->uUnitId != Garou_S_EXTRALOC)
    {
        const sGame_PaletteDataset* paletteDataSet = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId);

        if (paletteDataSet)
        {
            nImgUnitId = paletteDataSet->indexImgToUse;
            nTargetImgId = paletteDataSet->indexOffsetToUse;

            const sDescTreeNode* pCurrentNode = GetNodeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId, false);

            if (pCurrentNode)
            {
                if (Garou_S_UNITSORT[NodeGet->uUnitId] == indexGarouAPortraits)
                {
                    nSrcAmt = 4;
                    nSrcStart = NodeGet->uPalId - (NodeGet->uPalId % 4);
                    nNodeIncrement = 1;
                }
                else
                {
                    nSrcAmt = 5;
                    nNodeIncrement = pCurrentNode->uChildAmt;

                    while (nSrcStart >= nNodeIncrement)
                    {
                        // The starting point is the absolute first palette for the sprite in question which is found in P1
                        nSrcStart -= nNodeIncrement;
                    }
                }

                if (nSrcAmt == 5)
                {
                    pButtonLabelSet = DEF_BUTTONLABEL_NEOGEO_FIVE;
                }
                else
                {
                    pButtonLabelSet = DEF_BUTTONLABEL_NEOGEO;
                }
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
