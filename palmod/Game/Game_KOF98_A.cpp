#include "StdAfx.h"
#include "GameDef.h"
#include "Game_KOF98_A.h"
#include "..\PalMod.h"
#include "..\RegProc.h"

#define KOF98_A_DEBUG DEFAULT_GAME_DEBUG_STATE

stExtraDef* CGame_KOF98_A::KOF98_A_EXTRA_CUSTOM = nullptr;

CDescTree CGame_KOF98_A::MainDescTree = nullptr;

int CGame_KOF98_A::rgExtraCountAll[KOF98_A_NUMUNIT + 1];
int CGame_KOF98_A::rgExtraLoc[KOF98_A_NUMUNIT + 1];

UINT32 CGame_KOF98_A::m_nTotalPaletteCountForKOF98 = 0;
UINT32 CGame_KOF98_A::m_nExpectedGameROMSize = 0x400000;  // 4194304 bytes
UINT32 CGame_KOF98_A::m_nConfirmedROMSize = -1;

void CGame_KOF98_A::InitializeStatics()
{
    safe_delete_array(CGame_KOF98_A::KOF98_A_EXTRA_CUSTOM);

    memset(rgExtraCountAll, -1, sizeof(rgExtraCountAll));
    memset(rgExtraLoc, -1, sizeof(rgExtraLoc));

    MainDescTree.SetRootTree(CGame_KOF98_A::InitDescTree());
}

CGame_KOF98_A::CGame_KOF98_A(UINT32 nConfirmedROMSize)
{
    CString strMessage;
    strMessage.Format(_T("CGame_KOF98_A::CGame_KOF98_A: Loading ROM...\n"));
    OutputDebugString(strMessage);

    // We need this set before we initialize so that corrupt Extras truncate correctly.
    // Otherwise the new user inadvertently corrupts their ROM.
    m_nConfirmedROMSize = nConfirmedROMSize;
    InitializeStatics();

    m_nTotalInternalUnits = KOF98_A_NUMUNIT;
    m_nExtraUnit = KOF98_A_EXTRALOC;

    m_nSafeCountForThisRom = GetExtraCt(m_nExtraUnit) + 1909;
    m_pszExtraFilename = EXTRA_FILENAME_KOF98_A;
    m_nTotalPaletteCount = m_nTotalPaletteCountForKOF98;
    // This magic number is used to warn users if their Extra file is trying to write somewhere potentially unusual
    m_nLowestKnownPaletteRomLocation = 0x2d97f0;

    nUnitAmt = m_nTotalInternalUnits + (GetExtraCt(m_nExtraUnit) ? 1 : 0);

    InitDataBuffer();

    createPalOptions = { NO_SPECIAL_OPTIONS, WRITE_16 };
    SetAlphaMode(AlphaMode::GameDoesNotUseAlpha);
    SetColorMode(ColMode::COLMODE_NEOGEO);

    //Set palette conversion mode
    BasePalGroup.SetMode(ePalType::PALTYPE_8);

    //Set game information
    nGameFlag = KOF98_A;
    nImgGameFlag = IMGDAT_SECTION_KOF;
    nImgUnitAmt = KOF98_A_NUM_IMG_UNITS;

    nFileAmt = 1;

    //Set the image out display type
    DisplayType = eImageOutputSpriteDisplay::DISPLAY_SPRITES_LEFTTORIGHT;
    // Button labels are used for the Export Image dialog
    pButtonLabelSet = DEF_BUTTONLABEL_NEOGEO;
    m_nNumberOfColorOptions = ARRAYSIZE(DEF_BUTTONLABEL_NEOGEO);

    //Create the redirect buffer
    rgUnitRedir = new UINT16[nUnitAmt + 1];
    memset(rgUnitRedir, NULL, sizeof(UINT16) * nUnitAmt);

    //Create the file changed flag
    PrepChangeTrackingArray();
}

CGame_KOF98_A::~CGame_KOF98_A(void)
{
    safe_delete_array(CGame_KOF98_A::KOF98_A_EXTRA_CUSTOM);
    ClearDataBuffer();
    //Get rid of the file changed flag
    FlushChangeTrackingArray();
}

CDescTree* CGame_KOF98_A::GetMainTree()
{
    return &CGame_KOF98_A::MainDescTree;
}

UINT32 CGame_KOF98_A::GetKnownCRC32DatasetsForGame(const sCRC32ValueSet** ppKnownROMSet, bool* pfNeedToValidateCRCs)
{
    static sCRC32ValueSet knownROMs[] =
    {
        // There are three unique ROM sets, but the first two share the same palette file,
        // and the third one we don't care about.
        { _T("KOF '98 (Arcade)"), _T("242-p2.sp2"), 0x980aba4c, 0 },
        { _T("KOF '98 (Arcade)"), _T("kof98_p2.rom"), 0x980aba4c, 0 },
        { _T("KOF '98 (Arcade Alt)"), _T("242-ep.ep2"), 0x6e474841, 0 },
    };

    if (ppKnownROMSet != nullptr)
    {
        *ppKnownROMSet = knownROMs;
    }

    if (pfNeedToValidateCRCs)
    {
        // Each filename is associated with a single CRC
        *pfNeedToValidateCRCs = false;
    }

    return ARRAYSIZE(knownROMs);

#ifdef NOTES
    // These are the MAME values...
    <software name = "kof98">
        <description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends(NGM - 2420) </description>
            <rom loadflag="load16_word_swap" name="242-p2.sp2" offset="0x200000" size="0x400000" crc="980aba4c" sha1="5e735929ec6c3ca5b2efae3c7de47bcbb8ade2c5" />  <!--TC5332205-->

	<software name="kof98k" cloneof="kof98">
		<description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (Korean board, set 1)</description>
			<rom loadflag="load16_word_swap" name="242-p2.sp2" offset="0x200000" size="0x400000" crc="980aba4c" sha1="5e735929ec6c3ca5b2efae3c7de47bcbb8ade2c5" />  <!-- TC5332205 -->

	<software name="kof98ka" cloneof="kof98">
		<description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (Korean board, set 2)</description>
			<rom loadflag="load16_word_swap" name="242-p2.sp2" offset="0x200000" size="0x400000" crc="980aba4c" sha1="5e735929ec6c3ca5b2efae3c7de47bcbb8ade2c5" />  <!-- TC5332205 -->

	<software name="kof98h" cloneof="kof98">
		<description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (NGH-2420)</description>
				<rom loadflag="load16_word_swap" name="242-p2.sp2" offset="0x100000" size="0x400000" crc="980aba4c" sha1="5e735929ec6c3ca5b2efae3c7de47bcbb8ade2c5" />  <!-- TC5332205 -->

	<software name="kof98a" cloneof="kof98">
		<description>The King of Fighters '98 - The Slugfest / King of Fighters '98 - Dream Match Never Ends (NGM-2420, alt board)</description>
				<rom loadflag="load16_word_swap" name="242-ep2.ep2" offset="0x400000" size="0x200000" crc="6e474841" sha1="0ce401277f9c53435ea00b930efe361c8d25a7d9" /> <!-- M27C160 -->
#endif
}

int CGame_KOF98_A::GetExtraCt(UINT16 nUnitId, BOOL bCountVisibleOnly)
{
    if (rgExtraCountAll[0] == -1)
    {
        int nDefCtr = 0;
        memset(rgExtraCountAll, 0, ((KOF98_A_NUMUNIT + 1) * sizeof(int)));

        stExtraDef* pCurrDef = GetExtraDefForKOF98(0);

        while (pCurrDef->uUnitN != INVALID_UNIT_VALUE)
        {
            if (!pCurrDef->isInvisible || !bCountVisibleOnly)
            {
                rgExtraCountAll[pCurrDef->uUnitN]++;
            }

            nDefCtr++;
            pCurrDef = GetExtraDefForKOF98(nDefCtr);
        }
    }

    return rgExtraCountAll[nUnitId];
}

int CGame_KOF98_A::GetExtraLoc(UINT16 nUnitId)
{
    if (rgExtraLoc[0] == -1)
    {
        int nDefCtr = 0;
        int nCurrUnit = UNIT_START_VALUE;
        memset(rgExtraLoc, 0, (KOF98_A_NUMUNIT + 1) * sizeof(int));

        stExtraDef* pCurrDef = GetExtraDefForKOF98(0);

        while (pCurrDef->uUnitN != INVALID_UNIT_VALUE)
        {
            if (pCurrDef->uUnitN != nCurrUnit)
            {
                rgExtraLoc[pCurrDef->uUnitN] = nDefCtr;
                nCurrUnit = pCurrDef->uUnitN;
            }

            nDefCtr++;
            pCurrDef = GetExtraDefForKOF98(nDefCtr);
        }
    }

    return rgExtraLoc[nUnitId];
}

sDescTreeNode* CGame_KOF98_A::InitDescTree()
{
    UINT32 nTotalPaletteCount = 0;

    //Load extra file if we're using it
    LoadExtraFileForGame(EXTRA_FILENAME_KOF98_A, KOF98_A_EXTRA, &KOF98_A_EXTRA_CUSTOM, KOF98_A_EXTRALOC, m_nConfirmedROMSize);

    UINT16 nUnitCt = KOF98_A_NUMUNIT + (GetExtraCt(KOF98_A_EXTRALOC) ? 1 : 0);
    
    sDescTreeNode* NewDescTree = new sDescTreeNode;

    //Create the main character tree
    _stprintf(NewDescTree->szDesc, _T("%s"), g_GameFriendlyName[KOF98_A]);
    NewDescTree->ChildNodes = new sDescTreeNode[nUnitCt];
    NewDescTree->uChildAmt = nUnitCt;
    //All units have tree children
    NewDescTree->uChildType = DESC_NODETYPE_TREE;

    CString strMsg;
    bool fHaveExtras = (GetExtraCt(KOF98_A_EXTRALOC) > 0);
    strMsg.Format(_T("CGame_KOF98_A::InitDescTree: Building desc tree for KOF98_A %s extras...\n"), fHaveExtras ? _T("with") : _T("without"));
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

        if (iUnitCtr < KOF98_A_EXTRALOC)
        {
            //Set each description
            _stprintf(UnitNode->szDesc, _T("%s"), KOF98_A_UNITS[iUnitCtr].szDesc);
            UnitNode->ChildNodes = new sDescTreeNode[nUnitChildCount];
            //All children have collection trees
            UnitNode->uChildType = DESC_NODETYPE_TREE;
            UnitNode->uChildAmt = nUnitChildCount;

#if KOF98_A_DEBUG
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

#if KOF98_A_DEBUG
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

#if KOF98_A_DEBUG
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

#if KOF98_A_DEBUG
            strMsg.Format(_T("Unit (Extras): %s, %u of %u, %u total children\n"), UnitNode->szDesc, iUnitCtr + 1, nUnitCt, nUnitChildCount);
            OutputDebugString(strMsg);
#endif
        }

        //Set up extra nodes
        if (bUseExtra)
        {
            int nExtraPos = GetExtraLoc(iUnitCtr);
            int nCurrExtra = 0;

            CollectionNode = &((sDescTreeNode*)UnitNode->ChildNodes)[(KOF98_A_EXTRALOC > iUnitCtr) ? (nUnitChildCount - 1) : 0]; //Extra node

            _stprintf(CollectionNode->szDesc, _T("Extra"));

            CollectionNode->ChildNodes = new sDescTreeNode[nExtraCt];

            CollectionNode->uChildType = DESC_NODETYPE_NODE;
            CollectionNode->uChildAmt = nExtraCt; //EX + Extra

#if KOF98_A_DEBUG
            strMsg.Format(_T("\tCollection: %s, %u of %u, %u children\n"), CollectionNode->szDesc, 1, nUnitChildCount, nExtraCt);
            OutputDebugString(strMsg);
#endif

            for (UINT16 nExtraCtr = 0; nExtraCtr < nExtraCt; nExtraCtr++)
            {
                ChildNode = &((sDescNode*)CollectionNode->ChildNodes)[nExtraCtr];

                stExtraDef* pCurrDef = GetExtraDefForKOF98(nExtraPos + nCurrExtra);

                while (pCurrDef->isInvisible)
                {
                    nCurrExtra++;

                    pCurrDef = GetExtraDefForKOF98(nExtraPos + nCurrExtra);
                }

                _stprintf(ChildNode->szDesc, pCurrDef->szDesc);

                ChildNode->uUnitId = iUnitCtr;
                ChildNode->uPalId = (((KOF98_A_EXTRALOC > iUnitCtr) ? 1 : 0) * nUnitChildCount * 2) + nCurrExtra;

#if KOF98_A_DEBUG
                strMsg.Format(_T("\t\tPalette: %s, %u of %u\n"), ChildNode->szDesc, nExtraCtr + 1, nExtraCt);
                OutputDebugString(strMsg);
#endif

                nCurrExtra++;
                nTotalPaletteCount++;
            }
        }
    }

    strMsg.Format(_T("CGame_KOF98_A::InitDescTree: Loaded %u palettes for KOF98\n"), nTotalPaletteCount);
    OutputDebugString(strMsg);

    m_nTotalPaletteCountForKOF98 = nTotalPaletteCount;

    // For development use to speed things up
    //DumpPaletteHeaders();

    return NewDescTree;
}

struct sKOF98_A_PaletteData
{
    LPCTSTR pszCharacterName;
    UINT32 nROMOffset = 0;
    LPCTSTR pszImageSet = _T("indexKOF98_A_Kyo");
    bool rgIsEffectUsed[11];
};

sKOF98_A_PaletteData KOF98_A_CharacterEffectPalettes[] =
{
    // These effects use a random number of palettes per character.  The rgIsEffectUsed array keeps track of this for us.
    // Note that the Orochi characters share the same effects as the normal character.
    //                                                                            1  2  3  4  5  6  7  8  9  a  b
    { _T("Kyo"),        0x2ee7f0 + (0x200 *  0), _T("indexKOF98_A_Kyo"),        { 1, 1, 1, 0, 1, 1, 1, 0, 0, 0, 0 } },
    { _T("Benimaru"),   0x2ee7f0 + (0x200 *  1), _T("indexKOF98_A_Benimaru"),   { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Daimon"),     0x2ee7f0 + (0x200 *  2), _T("indexKOF98_A_Daimon"),     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Terry"),      0x2ee7f0 + (0x200 *  3), _T("indexKOF98_A_Terry"),      { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { _T("Andy"),       0x2ee7f0 + (0x200 *  4), _T("indexKOF98_A_Andy"),       { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0 } },
    { _T("Joe"),        0x2ee7f0 + (0x200 *  5), _T("indexKOF98_A_Joe"),        { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { _T("Ryo"),        0x2ee7f0 + (0x200 *  6), _T("indexKOF98_A_Ryo"),        { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } },
    { _T("Robert"),     0x2ee7f0 + (0x200 *  7), _T("indexKOF98_A_Robert"),     { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { _T("Yuri"),       0x2ee7f0 + (0x200 *  8), _T("indexKOF98_A_Yuri"),       { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 } },
    { _T("Leona"),      0x2ee7f0 + (0x200 *  9), _T("indexKOF98_A_Leona"),      { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } },
    { _T("Ralf"),       0x2ee7f0 + (0x200 * 10), _T("indexKOF98_A_Ralf"),       { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Clark"),      0x2ee7f0 + (0x200 * 11), _T("indexKOF98_A_Clark"),      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Athena"),     0x2ee7f0 + (0x200 * 12), _T("indexKOF98_A_Athena"),     { 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0 } },
    { _T("Kensou"),     0x2ee7f0 + (0x200 * 13), _T("indexKOF98_A_Kensou"),     { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Chin"),       0x2ee7f0 + (0x200 * 14), _T("indexKOF98_A_Chin"),       { 1, 0, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { _T("Chizuru"),    0x2ee7f0 + (0x200 * 15), _T("indexKOF98_A_Chizuru"),    { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Mai"),        0x2ee7f0 + (0x200 * 16), _T("indexKOF98_A_Mai"),        { 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 0 } },
    { _T("King"),       0x2ee7f0 + (0x200 * 17), _T("indexKOF98_A_King"),       { 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Kim"),        0x2ee7f0 + (0x200 * 18), _T("indexKOF98_A_Kim"),        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Chang"),      0x2ee7f0 + (0x200 * 19), _T("indexKOF98_A_Chang"),      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Choi"),       0x2ee7f0 + (0x200 * 20), _T("indexKOF98_A_Choi"),       { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Yashiro"),    0x2ee7f0 + (0x200 * 21), _T("indexKOF98_A_Yashiro"),    { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 } },
    { _T("Shermie"),    0x2ee7f0 + (0x200 * 22), _T("indexKOF98_A_Shermie"),    { 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1 } },
    { _T("Chris"),      0x2ee7f0 + (0x200 * 23), _T("indexKOF98_A_Chris"),      { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } },
    { _T("Yamazaki"),   0x2ee7f0 + (0x200 * 24), _T("indexKOF98_A_Yamazaki"),   { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Blue Mary"),  0x2ee7f0 + (0x200 * 25), _T("indexKOF98_A_BlueMary"),   { 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Billy"),      0x2ee7f0 + (0x200 * 26), _T("indexKOF98_A_Billy"),      { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 1 } },
    { _T("Iori"),       0x2ee7f0 + (0x200 * 27), _T("indexKOF98_A_Iori"),       { 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0 } },
    { _T("Mature"),     0x2ee7f0 + (0x200 * 28), _T("indexKOF98_A_Mature"),     { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { _T("Vice"),       0x2ee7f0 + (0x200 * 29), _T("indexKOF98_A_Vice"),       { 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 1 } },
    { _T("Heidern"),    0x2ee7f0 + (0x200 * 30), _T("indexKOF98_A_Heidern"),    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 } },
    { _T("Takuma"),     0x2ee7f0 + (0x200 * 31), _T("indexKOF98_A_Takuma"),     { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } },
    { _T("Saisyu"),     0x2ee7f0 + (0x200 * 32), _T("indexKOF98_A_Saisyu"),     { 1, 1, 1, 0, 1, 1, 1, 1, 0, 0, 0 } },
    { _T("Heavy D!"),   0x2ee7f0 + (0x200 * 33), _T("indexKOF98_A_HeavyD"),     { 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0 } },
    { _T("Lucky"),      0x2ee7f0 + (0x200 * 34), _T("indexKOF98_A_Lucky"),      { 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0 } },
    { _T("Brian"),      0x2ee7f0 + (0x200 * 35), _T("indexKOF98_A_Brian"),      { 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0 } },
    { _T("Rugal"),      0x2ee7f0 + (0x200 * 36), _T("indexKOF98_A_Rugal"),      { 1, 1, 1, 1, 0, 1, 0, 1, 0, 1, 0 } },
    { _T("Shingo"),     0x2ee7f0 + (0x200 * 37), _T("indexKOF98_A_Shingo"),     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } },
    { _T("Omega Rugal"), 0x2ee7f0 + (0x200* 38), _T("indexKOF98_A_OmegaRugal"), { 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 1 } },
    //                                                                            1  2  3  4  5  6  7  8  9  a  b
};

void CGame_KOF98_A::DumpPaletteHeaders()
{
    CString strOutput;
    const UINT16 nColorOptionsPerCharacter = 4;
    constexpr UINT32 KOF98_PALETTE_LENGTH = 0x20;
    const UINT16 nCountStatusEffects = 16;

    for (UINT16 nCharIndex = 0; nCharIndex < ARRAYSIZE(KOF98_A_CharacterEffectPalettes); nCharIndex++)
    {
        TCHAR szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StrRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), KOF98_A_CharacterEffectPalettes[nCharIndex].pszCharacterName);

        strOutput.Format(_T("const sGame_PaletteDataset KOF98_A_%s_EFFECT_PALETTES[] = \r\n{\r\n"), szCodeDesc);
        OutputDebugString(strOutput);

        // Status effects
        for (UINT16 nStatusIndex = 0; nStatusIndex < nCountStatusEffects; nStatusIndex++)
        {
            UINT32 nCurrentOffset = KOF98_A_CharacterEffectPalettes[nCharIndex].nROMOffset + (nStatusIndex * KOF98_PALETTE_LENGTH);
            switch (nStatusIndex)
            {
            default:
                if (KOF98_A_CharacterEffectPalettes[nCharIndex].rgIsEffectUsed[nStatusIndex])
                {
                    strOutput.Format(_T("    { _T(\"Effect %u\"), 0x%x, 0x%x },\r\n"), nStatusIndex, nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH);
                        OutputDebugString(strOutput);
                }
                break;
            case 11:
                strOutput.Format(_T("    { _T(\"Zap Effect 1\"), 0x%x, 0x%x, %s },\r\n"), nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            case 12:
                strOutput.Format(_T("    { _T(\"Zap Effect 2\"), 0x%x, 0x%x, %s },\r\n"), nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            case 13:
                strOutput.Format(_T("    { _T(\"Super Trail 1\"), 0x%x, 0x%x, %s },\r\n"), nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            case 14:
                strOutput.Format(_T("    { _T(\"Super Trail 2\"), 0x%x, 0x%x, %s },\r\n"), nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            case 15:
                strOutput.Format(_T("    { _T(\"Super Trail 3\"), 0x%x, 0x%x, %s },\r\n"), nCurrentOffset, nCurrentOffset + KOF98_PALETTE_LENGTH,
                    KOF98_A_CharacterEffectPalettes[nCharIndex].pszImageSet);
                OutputDebugString(strOutput);
                break;
            };
        }

        OutputDebugString(_T("};\r\n\r\n"));
    }

    for (UINT16 nCharIndex = 0; nCharIndex < ARRAYSIZE(KOF98_A_CharacterEffectPalettes); nCharIndex++)
    {
        TCHAR szCodeDesc[MAX_DESCRIPTION_LENGTH];
        StrRemoveNonASCII(szCodeDesc, ARRAYSIZE(szCodeDesc), KOF98_A_CharacterEffectPalettes[nCharIndex].pszCharacterName);

        strOutput.Format(_T("const sDescTreeNode KOF98_A_%s_COLLECTION[] = \r\n{\r\n"), szCodeDesc);
        OutputDebugString(strOutput);

        for (UINT16 nColorIndex = 0; nColorIndex < nColorOptionsPerCharacter; nColorIndex++)
        {
            TCHAR szColorOptionCodeDesc[MAX_DESCRIPTION_LENGTH];
            StrRemoveNonASCII(szColorOptionCodeDesc, ARRAYSIZE(szColorOptionCodeDesc), DEF_BUTTONLABEL_NEOGEO[nColorIndex]);

            strOutput.Format(_T("    { _T(\"%s\"), DESC_NODETYPE_TREE, (void*)KOF98_A_%s_%s_PALETTES, ARRAYSIZE(KOF98_A_%s_%s_PALETTES) },\r\n"), DEF_BUTTONLABEL_NEOGEO[nColorIndex], szCodeDesc, szColorOptionCodeDesc, szCodeDesc, szColorOptionCodeDesc);
            OutputDebugString(strOutput);
        }

        strOutput.Format(_T("    { _T(\"Effects\"), DESC_NODETYPE_TREE, (void*)KOF98_A_%s_EFFECT_PALETTES, ARRAYSIZE(KOF98_A_%s_EFFECT_PALETTES) },\r\n"), szCodeDesc, szCodeDesc);
        OutputDebugString(strOutput);
        OutputDebugString(_T("};\r\n\r\n"));
    }
}

sFileRule CGame_KOF98_A::GetRule(UINT16 nUnitId)
{
    sFileRule NewFileRule;

    // This value is only used for directory-based games
    _stprintf_s(NewFileRule.szFileName, MAX_FILENAME_LENGTH, _T("242-p2.sp2"));

    NewFileRule.uUnitId = 0;
    NewFileRule.uVerifyVar = m_nExpectedGameROMSize;

    return NewFileRule;
}

UINT16 CGame_KOF98_A::GetCollectionCountForUnit(UINT16 nUnitId)
{
    if (nUnitId == KOF98_A_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        return KOF98_A_UNITS[nUnitId].uChildAmt;
    }
}

UINT16 CGame_KOF98_A::GetNodeCountForCollection(UINT16 nUnitId, UINT16 nCollectionId)
{
    if (nUnitId == KOF98_A_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        const sDescTreeNode* pCollectionNode = (const sDescTreeNode*)(KOF98_A_UNITS[nUnitId].ChildNodes);

        return pCollectionNode[nCollectionId].uChildAmt;
    }
}

LPCTSTR CGame_KOF98_A::GetDescriptionForCollection(UINT16 nUnitId, UINT16 nCollectionId)
{
    if (nUnitId == KOF98_A_EXTRALOC)
    {
        return _T("Extra Palettes");
    }
    else
    {
        const sDescTreeNode* pCollection = (const sDescTreeNode*)KOF98_A_UNITS[nUnitId].ChildNodes;
        return pCollection[nCollectionId].szDesc;
    }
}

UINT16 CGame_KOF98_A::GetPaletteCountForUnit(UINT16 nUnitId)
{
    if (nUnitId == KOF98_A_EXTRALOC)
    {
        return GetExtraCt(nUnitId);
    }
    else
    {
        UINT16 nCompleteCount = 0;
        const sDescTreeNode* pCompleteROMTree = KOF98_A_UNITS;
        UINT16 nCollectionCount = pCompleteROMTree[nUnitId].uChildAmt;

        const sDescTreeNode* pCurrentCollection = (const sDescTreeNode*)(pCompleteROMTree[nUnitId].ChildNodes);

        for (UINT16 nCollectionIndex = 0; nCollectionIndex < nCollectionCount; nCollectionIndex++)
        {
            nCompleteCount += pCurrentCollection[nCollectionIndex].uChildAmt;
        }

#if KOF98_A_DEBUG
        CString strMsg;
        strMsg.Format(_T("CGame_KOF98_A::GetPaletteCountForUnit: %u for unit %u which has %u collections.\n"), nCompleteCount, nUnitId, nCollectionCount);
        OutputDebugString(strMsg);
#endif

        return nCompleteCount;
    }
}

const sGame_PaletteDataset* CGame_KOF98_A::GetPaletteSet(UINT16 nUnitId, UINT16 nCollectionId)
{
    // Don't use this for Extra palettes.
    const sDescTreeNode* pCurrentSet = (const sDescTreeNode*)KOF98_A_UNITS[nUnitId].ChildNodes;
    return ((sGame_PaletteDataset*)(pCurrentSet[nCollectionId].ChildNodes));
}

const sDescTreeNode* CGame_KOF98_A::GetNodeFromPaletteId(UINT16 nUnitId, UINT16 nPaletteId, bool fReturnBasicNodesOnly)
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

        if (nUnitId == KOF98_A_EXTRALOC)
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
            const sDescTreeNode* pCollectionNodeToCheck = (const sDescTreeNode*)(KOF98_A_UNITS[nUnitId].ChildNodes);
            
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

const sGame_PaletteDataset* CGame_KOF98_A::GetSpecificPalette(UINT16 nUnitId, UINT16 nPaletteId)
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

void CGame_KOF98_A::LoadSpecificPaletteData(UINT16 nUnitId, UINT16 nPalId)
{
     if (nUnitId != KOF98_A_EXTRALOC)
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
    else // KOF98_A_EXTRALOC
    {
        // This is where we handle all the palettes added in via Extra.
        stExtraDef* pCurrDef = GetExtraDefForKOF98(GetExtraLoc(nUnitId) + nPalId);

        m_nCurrentPaletteROMLocation = pCurrDef->uOffset;
        m_nCurrentPaletteSize = (pCurrDef->cbPaletteSize / 2);
        m_pszCurrentPaletteName = pCurrDef->szDesc;
    }
}

BOOL CGame_KOF98_A::LoadFile(CFile* LoadedFile, UINT16 nUnitId)
{
    for (UINT16 nUnitCtr = 0; nUnitCtr < nUnitAmt; nUnitCtr++)
    {
        UINT16 nPalAmt = GetPaletteCountForUnit(nUnitCtr);

        m_pppDataBuffer[nUnitCtr] = new UINT16 * [nPalAmt];

        // Use a sorted layout
        rgUnitRedir[nUnitCtr] = KOF98_A_UNITSORT[nUnitCtr];

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

void CGame_KOF98_A::CreateDefPal(sDescNode* srcNode, UINT16 nSepId)
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

BOOL CGame_KOF98_A::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
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
    if (NodeGet->uUnitId != KOF98_A_EXTRALOC)
    {
        const sGame_PaletteDataset* paletteDataSet = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId);

        if (paletteDataSet)
        {
            nImgUnitId = paletteDataSet->indexImgToUse;
            nTargetImgId = paletteDataSet->indexOffsetToUse;

            const sDescTreeNode* pCurrentNode = GetNodeFromPaletteId(NodeGet->uUnitId, NodeGet->uPalId, false);

            if (pCurrentNode)
            {
                if ((_tcsicmp(pCurrentNode->szDesc, _T("A")) == 0) || (_tcsicmp(pCurrentNode->szDesc, _T("B")) == 0) ||
                    (_tcsicmp(pCurrentNode->szDesc, _T("C")) == 0) || (_tcsicmp(pCurrentNode->szDesc, _T("D")) == 0))
                {
                    nSrcAmt = 4;
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
                int nXOffs = paletteDataSet->pPalettePairingInfo->nXOffs;
                int nYOffs = paletteDataSet->pPalettePairingInfo->nYOffs;
                INT8 nPeerPaletteDistance = paletteDataSet->pPalettePairingInfo->nNodeIncrementToPartner;

                const sGame_PaletteDataset* paletteDataSetToJoin = GetSpecificPalette(NodeGet->uUnitId, NodeGet->uPalId + nPeerPaletteDistance);

                if (paletteDataSetToJoin)
                {
                    fShouldUseAlternateLoadLogic = true;

                    ClearSetImgTicket(
                        CreateImgTicket(paletteDataSet->indexImgToUse, paletteDataSet->indexOffsetToUse,
                            CreateImgTicket(paletteDataSetToJoin->indexImgToUse, paletteDataSetToJoin->indexOffsetToUse, nullptr, nXOffs, nYOffs)
                        )
                    );

                    //Set each palette
                    sDescNode* JoinedNode[2] = {
                        GetMainTree()->GetDescNode(Node01, Node02, Node03, -1),
                        GetMainTree()->GetDescNode(Node01, Node02, Node03 + nPeerPaletteDistance, -1)
                    };

                    //Set each palette
                    CreateDefPal(JoinedNode[0], 0);
                    CreateDefPal(JoinedNode[1], 1);

                    SetSourcePal(0, NodeGet->uUnitId, nSrcStart, nSrcAmt, nNodeIncrement);
                    SetSourcePal(1, NodeGet->uUnitId, nSrcStart + nPeerPaletteDistance, nSrcAmt, nNodeIncrement);
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
