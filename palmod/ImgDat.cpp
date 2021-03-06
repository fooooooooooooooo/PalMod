#include "StdAfx.h"
#include "ImgDat.h"
#include "Game\GameDef.h"

#define IMGDAT_DEBUG 0

void OutputDebugString_ImgDat(LPCTSTR pszString)
{
#if IMGDAT_DEBUG
    OutputDebugString(pszString);
#else
#endif
}

typedef std::map<UINT8, ImgInfoList*>::iterator imgMapIter;

CImgDat::CImgDat(void)
{
}

CImgDat::~CImgDat(void)
{
    if (!imageBufferFlushed)
    {
        FlushImageBuffer();
    }
    CloseImgFile();
}

bool CImgDat::FlushImageBuffer()
{
    if (imageBufferFlushed)
    {
        return imageBufferFlushed;
    }

    if (nImgMap)
    {
        for (imgMapIter it = nImgMap->begin(); it != nImgMap->end(); ++it)
        {
            if (it->second)
            {
                delete it->second;
            }
        }

        if (!nImgMap->empty())
        {
            nImgMap->clear();
        }
    }

    safe_delete(nImgMap);

    imageBufferPrepped = false;
    imageBufferFlushed = true;

    return true;
}

bool CImgDat::PrepImageBuffer(const UINT16 nGameImageUnitAmt, const UINT8 uGameFlag)
{
    if (!imageBufferFlushed)
    {
        imageBufferFlushed = FlushImageBuffer();
    }

    nImgMap = new  std::map<UINT8, ImgInfoList*>;

#if IMGDAT_DEBUG
    CString strDebugInfo;
    strDebugInfo.Format(_T("CImgDat::PrepImageBuffer : Prepping Image Buffer \n"));
    OutputDebugString(strDebugInfo);
#endif

    // We have an individual entry here for every game so we can optimize image loads
    for (UINT16 nUnitCtr = 0; nUnitCtr < nGameImageUnitAmt; nUnitCtr++)
    {
        UINT8 nImageUnitCounterToUse = 0;

        switch (uGameFlag)
        {
        case BREAKERS_A:
        {
            nImageUnitCounterToUse = BREAKERS_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case COTA_A:
        {
            nImageUnitCounterToUse = COTA_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case CVS2_A:
        {
            nImageUnitCounterToUse = CVS2_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case Garou_A:
        case Garou_S:
        {
            nImageUnitCounterToUse = GAROU_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case GEMFIGHTER_A:
        {
            nImageUnitCounterToUse = GEMFIGHTER_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case JOJOS_A:
        case JOJOS_A_DIR_50:
        case JOJOS_A_DIR_51:
        {
            nImageUnitCounterToUse = JOJOS_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case KarnovsR_A:
        {
            nImageUnitCounterToUse = KARNOVSR_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case KOF98_A:
        {
            nImageUnitCounterToUse = KOF98_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case KOF02_A:
        {
            nImageUnitCounterToUse = KOF02_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case KOFXI_A:
        {
            nImageUnitCounterToUse = KOFXI_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case KOF02UM_S:
        {
            nImageUnitCounterToUse = KOF02UM_S_IMG_UNITS[nUnitCtr];
            break;
        }
        case MATRIMELEE_A:
        {
            nImageUnitCounterToUse = MATRIM_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case MSH_A:
        {
            nImageUnitCounterToUse = MSH_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case MSHVSF_A:
        {
            nImageUnitCounterToUse = MSHVSF_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case MVC_A:
        {
            nImageUnitCounterToUse = MVC_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case MVC2_A:
        case MVC2_D:
        case MVC2_A_DIR:
        {
            nImageUnitCounterToUse = MVC2_IMG_UNITS[nUnitCtr];
            break;
        }
        case MVC2_P:
        {
            nImageUnitCounterToUse = MVC2_IMG_UNITS[nUnitCtr];
            break;
        }
        case NGBC_A:
        {
            nImageUnitCounterToUse = NGBC_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case RBFFS_A:
        {
            nImageUnitCounterToUse = RBFFS_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case REDEARTH_A:
        {
            nImageUnitCounterToUse = REDEARTH_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SAMSHO3_A:
        {
            nImageUnitCounterToUse = SAMSHO3_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SAMSHO5SP_A:
        {
            nImageUnitCounterToUse = SAMSHO5SP_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SFA1_A:
        {
            nImageUnitCounterToUse = SFA1_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SFA2_A:
        {
            nImageUnitCounterToUse = SFA2_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SFA3_A:
        {
            nImageUnitCounterToUse = SFA3_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SFIII1_A:
        {
            nImageUnitCounterToUse = SFIII1_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SFIII2_A:
        {
            nImageUnitCounterToUse = SFIII2_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SFIII3_A:
        case SFIII3_A_DIR_10:
        case SFIII3_A_DIR_4:
        case SFIII3_A_DIR_51:
        {
            nImageUnitCounterToUse = SFIII3_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SFIII3_D:
        {
            nImageUnitCounterToUse = SFIII3_D_IMG_UNITS[nUnitCtr];
            break;
        }
        case SF2CE_A: // these two are the same currently
        case SF2HF_A:
        {
            nImageUnitCounterToUse = SF2HF_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SSF2T_A:
        {
            nImageUnitCounterToUse = SSF2T_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case SSF2T_GBA:
        {
            nImageUnitCounterToUse = SSF2T_GBA_IMG_UNITS[nUnitCtr];
            break;
        }
        case SVCPLUSA_A:
        {
            nImageUnitCounterToUse = SVCPLUSA_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case VHUNT2_A:
        {
            nImageUnitCounterToUse = VHUNT2_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case VSAV_A:
        {
            nImageUnitCounterToUse = VSAV_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case VSAV2_A:
        {
            nImageUnitCounterToUse = VSAV2_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case WINDJAMMERS_A:
        {
            nImageUnitCounterToUse = WINDJAMMERS_A_IMG_UNITS[nUnitCtr];
            break;
        }
        case XMVSF_A:
        {
            nImageUnitCounterToUse = XMVSF_A_IMG_UNITS[nUnitCtr];
            break;
        }
        default:
            OutputDebugString(_T("CImgDat::PrepImageBuffer : WARNING: Unhandled game id.  You won't get images for this game.\n"));
            return NULL;
            break;
        }

#if IMGDAT_DEBUG
        strDebugInfo.Format(_T("CImgDat::PrepImageBuffer : Trying to insert unitID: 0x%02X into nImgMap\n"), nImageUnitCounterToUse);
        OutputDebugString(strDebugInfo);
#endif
        nImgMap->insert({ nImageUnitCounterToUse, new ImgInfoList });
    }

    imageBufferFlushed = false;
    return true;
}

sImgDef* CImgDat::GetImageDef(UINT16 uUnitId, UINT16 uImgId)
{
#if IMGDAT_DEBUG
    CString strDebugInfo;
    strDebugInfo.Format(_T("CImgDat::GetImageDef : Attempting to get ImageDef for unit 0x%02x img 0x%x.\n"), uUnitId, uImgId);
    OutputDebugString(strDebugInfo);
#endif

    //if ((uUnitId >= uCurrUnitAmt) || (uImgId > uCurrImgAmt))

    if (nImgMap)
    {
#if IMGDAT_DEBUG
        strDebugInfo.Format(_T("CImgDat::GetImageDef : nImgMap exists \n"));
        OutputDebugString(strDebugInfo);
#endif

        imgMapIter it = nImgMap->find((UINT8)uUnitId);
        if (it != nImgMap->cend())
        {
            // it->second->listAllImgIDs();
#if IMGDAT_DEBUG
            strDebugInfo.Format(_T("CImgDat::GetImageDef : ppImgData[0x%02X] exists \n"), uUnitId);
            OutputDebugString(strDebugInfo);
#endif
            if (it->second->valueExists(uImgId))
            {
#if IMGDAT_DEBUG
                strDebugInfo.Format(_T("CImgDat::GetImageDef : Found imgID 0x%02X in list for unitID 0x%02X \n"), uImgId, uUnitId);
                OutputDebugString(strDebugInfo);
#endif
                return it->second->getImgDef(uImgId);
            }
#if IMGDAT_DEBUG
            strDebugInfo.Format(_T("CImgDat::GetImageDef : Could not find imgID:0x%02X in list for unitID:0x%02X\n"), uImgId, uUnitId);
            OutputDebugString(strDebugInfo);
#endif
        }
        else
        {
            if (uUnitId != INVALID_UNIT_VALUE)
            {
                CString strWarning;
                strWarning.Format(_T("\n    **************\nCImgDat::GetImageDef : WARNING: UnitId 0x%02x was not found in the image map for this game.  Did you forget to update gamedef.h or CImgDat::PrepImageBuffer?\n    **************\n"), uUnitId);
                OutputDebugString(strWarning);
            }
        }
    }

#if IMGDAT_DEBUG
    strDebugInfo.Format(_T("CImgDat::GetImageDef : No image found\n"));
    OutputDebugString(strDebugInfo);
#endif
    return nullptr;
}

UINT8* CImgDat::GetImgData(sImgDef* pCurrImg, UINT8 uGameFlag, int nCurrentUnitId, int nCurrentImgId)
{
#if IMGDAT_DEBUG
    CString strDebugInfo;
#endif
    if (pCurrImg->pImgData)
    {
#if IMGDAT_DEBUG
        strDebugInfo.Format(_T("CImgDat::GetImgData : Image at position '0x%x' for unit 0x%02x img 0x%x is already loaded.\n"), pCurrImg->uThisImgLoc, nCurrentUnitId, nCurrentImgId);
        OutputDebugString(strDebugInfo);

        strDebugInfo.Format(_T(" W: 0x%x (%u), H: 0x%x (%u), compressed: %u, size 0x%x, offset 0x%x (%lu) to offset 0x%x\n\n"), pCurrImg->uImgWidth, pCurrImg->uImgWidth, pCurrImg->uImgHeight, pCurrImg->uImgHeight, pCurrImg->nCompressionType, pCurrImg->uDataSize, pCurrImg->uThisImgLoc, pCurrImg->uThisImgLoc, pCurrImg->uThisImgLoc + pCurrImg->uDataSize);
        OutputDebugString(strDebugInfo);
#endif
        return pCurrImg->pImgData;
    }

    //Read the data

    UINT8* pNewImgData = new UINT8[pCurrImg->uDataSize];

#if IMGDAT_DEBUG
    strDebugInfo.Format(_T("CImgDat::GetImgData : Making pNewImgData for unitID:0x%X, imgID:0x%X .\n"), nCurrentUnitId, nCurrentImgId);
    OutputDebugString_ImgDat(strDebugInfo);
    strDebugInfo.Format(_T(" W: 0x%x (%u), H: 0x%x (%u), compressed: %u, size 0x%x, offset 0x%x (%lu) to offset 0x%x\n\n"), pCurrImg->uImgWidth, pCurrImg->uImgWidth, pCurrImg->uImgHeight, pCurrImg->uImgHeight, pCurrImg->nCompressionType, pCurrImg->uDataSize, pCurrImg->uThisImgLoc, pCurrImg->uThisImgLoc, pCurrImg->uThisImgLoc + pCurrImg->uDataSize);
    OutputDebugString_ImgDat(strDebugInfo);
#endif

    ImgDatFile.Seek(pCurrImg->uThisImgLoc, CFile::begin);
    ImgDatFile.Read(pNewImgData, pCurrImg->uDataSize);

    switch (pCurrImg->nCompressionType)
    {
    case 0: // No compression
        break;
    case 1: // RLE
    {
        UINT8 * pTmpData = pNewImgData;

        pNewImgData = RLEDecodeImg(
            pTmpData,
            pCurrImg->uDataSize,
            pCurrImg->uImgWidth,
            pCurrImg->uImgHeight
        );

        safe_delete_array(pTmpData);
        break;
    }
    case 2: // BitmaskRLE
    {
        OutputDebugString(_T("Using new BitMaskRLE logic...\n"));
        UINT8* pTmpData = pNewImgData;

        pNewImgData = BitMaskRLEDecodeImg(
            pTmpData,
            pCurrImg->uDataSize,
            pCurrImg->uImgWidth,
            pCurrImg->uImgHeight
        );

        safe_delete_array(pTmpData);
        break;
    }
    default:
        OutputDebugString(_T("CImgDat::GetImgData : WARNING: Unhandled compression type.  Skipping loading this image\n"));
        return nullptr;
    }

#ifdef EXPORT_IMG_DAT_TO_DISK
    static bool shouldExportItAll = true;
    if (shouldExportItAll)
    {
        int uLengthToWrite = (pCurrImg->nCompressionType) ? (pCurrImg->uImgHeight * pCurrImg->uImgWidth) : pCurrImg->uDataSize;

        CString strThisGameName;
        strThisGameName = g_GameFriendlyName[uGameFlag];

        // We could use known CurrentUnitId offsets to get back to the friendly character name...
        // We previously included the offset ( pCurrImg->uThisImgLoc ) in the filename, but that's probably not useful overall.
        CString strFilePath;
        strFilePath.Format(_T(".\\Assets\\%s-unit-0x%02x-imgid-0x%02x-W-%i-H-%i.raw"), strThisGameName, nCurrentUnitId, nCurrentImgId, pCurrImg->uImgWidth, pCurrImg->uImgHeight);

        CString strDebugInfo;
        strDebugInfo.Format(_T("Special Export: Image '0x%x', H %u W %u for LEN %u to %s\n"), pCurrImg->uThisImgLoc, pCurrImg->uImgHeight, pCurrImg->uImgWidth, uLengthToWrite, strFilePath);
        OutputDebugString(strDebugInfo);

        HANDLE hFile = CreateFile(
            strFilePath,
            GENERIC_WRITE,
            0,
            NULL,
            CREATE_ALWAYS,
            FILE_ATTRIBUTE_NORMAL,
            NULL);

        if (hFile != INVALID_HANDLE_VALUE)
        {
            DWORD cbWritten = 0;

            // write the file to disk
            for (int nIndexMe = 0; nIndexMe < uLengthToWrite; nIndexMe++)
            {
                cbWritten = 0;
                WriteFile(hFile, &(pNewImgData[nIndexMe]), 1, &cbWritten, nullptr);
            }

            CloseHandle(hFile);
        }
        else
        {
            OutputDebugString(_T("Error exporting image file\n"));
        }
    }
#endif

    pCurrImg->pImgData = pNewImgData;

    return pNewImgData;
}

void CImgDat::CloseImgFile()
{
    if (bOnTheFly)
    {
        ImgDatFile.Abort();
    }
}

bool CImgDat::sameGameAlreadyLoaded(UINT8 uGameFlag, UINT8 uImgGameFlag)
{
    return (uImgGameFlag == nCurImgGameFlag) && (uGameFlag == nCurGameFlag);
}

BOOL CImgDat::LoadImage(TCHAR* lpszLoadFile, UINT8 uGameFlag, UINT8 uImgGameFlag, UINT16 uGameUnitAmt, UINT16 uImgUnitAmt, UINT16 uImgAmt, BOOL bLoadAll)
{
    UINT8 uNumGames = 0xFF;

    CString strDebugInfo;
    strDebugInfo.Format(_T("CImgDat::LoadImage : Opening image file '%s'\n"), lpszLoadFile);
    OutputDebugString(strDebugInfo);
    strDebugInfo.Format(_T("CImgDat::LoadImage : gameFlag is '%u' (\"%s\") and gameImageFlag is '%u'.  For 0x%02x game units we have 0x%02x image units.\n"), uGameFlag, g_GameFriendlyName[uGameFlag], uImgGameFlag, uGameUnitAmt, uImgUnitAmt);
    OutputDebugString(strDebugInfo);

    if (sameGameAlreadyLoaded(uGameFlag, uImgGameFlag))
    {
        return TRUE;
    }
    else
    {

#if IMGDAT_DEBUG
        strDebugInfo.Format(_T("CImgDat::LoadImage : New game being loaded gameFlag:0x%02X with imgGameFlag:0x%02X, flushing image buffer.'\n"), uGameFlag, uImgGameFlag);
        OutputDebugString(strDebugInfo);
#endif

        imageBufferFlushed = false;
        imageBufferFlushed = FlushImageBuffer();
#if IMGDAT_DEBUG
        strDebugInfo.Format(_T("CImgDat::LoadImage : Image buffer has been flushed. imageBuffer: %u '\n"), imageBufferPrepped);
        OutputDebugString(strDebugInfo);
#endif
        CloseImgFile();
    }

    if (!ImgDatFile.Open(lpszLoadFile, CFile::modeRead | CFile::typeBinary))
    {
        ImgDatFile.Abort(); //Error loading
        return FALSE;
    }

    bOnTheFly = !bLoadAll;

    //Skip image verification
    ImgDatFile.Seek(0x04, CFile::current);
    ImgDatFile.Read(&uNumGames, 0x01);
    ImgDatFile.Seek(0x01, CFile::current);

    if (uNumGames)
    {
        for (int nGameCtr = 0; nGameCtr < uNumGames; nGameCtr++)
        {
            ImgDatFile.Read(&uReadGameFlag, 0x01);
            ImgDatFile.Read(&uReadBPP, 0x01);
            ImgDatFile.Read(&uReadNumImgs, 0x02);
            ImgDatFile.Read(&uReadNextImgLoc, 0x04);

#if IMGDAT_DEBUG
            strDebugInfo.Format(_T("CImgDat::LoadImage : Detected gameID 0x%X ; game has %u images; first imgLoc is 0x%X .\n"), uReadGameFlag, uReadNumImgs, uReadNextImgLoc);
            OutputDebugString(strDebugInfo);
#endif

            if (uReadGameFlag == uImgGameFlag)
            {
                nCurGameImgAmt = uReadNumImgs;

#if IMGDAT_DEBUG
                strDebugInfo.Format(_T("CImgDat::LoadImage : Read matching uImgGameFlag: 0x%X for current uGameFlag: 0x%X \n"), uImgGameFlag, uGameFlag);
                OutputDebugString(strDebugInfo);
#endif

                if (!imageBufferFlushed)
                {
                    imageBufferFlushed = FlushImageBuffer();
                }

                imageBufferPrepped = PrepImageBuffer(uImgUnitAmt, uGameFlag);

                while (uReadNextImgLoc != 0)
                {
                    ImgDatFile.Seek(uReadNextImgLoc, CFile::begin);
                    UINT8 uCurrUnitId, uCurrImgId;
                    ImgDatFile.Read(&uCurrUnitId, 0x01);
                    ImgDatFile.Read(&uCurrImgId, 0x01);
#if IMGDAT_DEBUG
                    strDebugInfo.Format(_T("CImgDat::LoadImage : Seeing UnitID:0x%02X imgID:0x%02X \n"), uCurrUnitId, uCurrImgId);
                    OutputDebugString_ImgDat(strDebugInfo);
#endif

                    std::map<UINT8, ImgInfoList*>::iterator it = nImgMap->find(uCurrUnitId);
                    if (nImgMap->find(uCurrUnitId) != nImgMap->cend())
                    {
                        it->second->insertNode(uCurrImgId);

#if IMGDAT_DEBUG
                        strDebugInfo.Format(_T("CImgDat::LoadImage : node[0x%X][0x%X] Inserted\n"), uCurrUnitId, uCurrImgId);
                        OutputDebugString_ImgDat(strDebugInfo);
#endif

                        sImgDef* pCurrImg = it->second->getImgDef(uCurrImgId);
                        pCurrImg->pImgData = nullptr;
                        ImgDatFile.Read(&pCurrImg->uImgWidth, 0x02);
                        ImgDatFile.Read(&pCurrImg->uImgHeight, 0x02);
                        ImgDatFile.Read(&pCurrImg->nCompressionType, 0x01);
                        ImgDatFile.Read(&pCurrImg->uDataSize, 0x04);
                        ImgDatFile.Read(&uReadNextImgLoc, 0x04);
                        pCurrImg->uThisImgLoc = (0xFFFFFFFF & ImgDatFile.GetPosition());

                        if (pCurrImg->uDataSize == 0)
                        {
                            CString strError;
                            strError.Format(_T("WARNING: Probable imgdat corruption at gameflag 0x%02x unit 0x%02x imgid 0x%02x: data size is 0x%x.\n\tNext location is 0x%x\n."), uImgGameFlag, uCurrUnitId, uCurrImgId, pCurrImg->uDataSize, uReadNextImgLoc);
                            OutputDebugString(strError);
                        }

#if IMGDAT_DEBUG
                        strDebugInfo.Format(_T("CImgDat::LoadImage : Image info for unit 0x%02X img 0x%02X has been loaded.\n"), uCurrUnitId, uCurrImgId);
                        OutputDebugString_ImgDat(strDebugInfo);
                        strDebugInfo.Format(_T(" W: 0x%x (%u), H: 0x%x (%u), compressed: %u, size 0x%x, offset 0x%x (%lu) to offset 0x%x\n\n"), pCurrImg->uImgWidth, pCurrImg->uImgWidth, pCurrImg->uImgHeight, pCurrImg->uImgHeight, pCurrImg->nCompressionType, pCurrImg->uDataSize, pCurrImg->uThisImgLoc, pCurrImg->uThisImgLoc, pCurrImg->uThisImgLoc + pCurrImg->uDataSize);
                        OutputDebugString_ImgDat(strDebugInfo);
#endif
                        if (bLoadAll)
                        {
                            GetImgData(pCurrImg, uReadGameFlag, uCurrUnitId, uCurrImgId);
                        }
                    }
                    else
                    {
                        UINT8 tCompressed;
                        UINT16 tImgWidth, tImgHeight;
                        UINT32 tDataSize;

                        ImgDatFile.Read(&tImgWidth, 0x02);
                        ImgDatFile.Read(&tImgHeight, 0x02);
                        ImgDatFile.Read(&tCompressed, 0x01);
                        ImgDatFile.Read(&tDataSize, 0x04);
                        ImgDatFile.Read(&uReadNextImgLoc, 0x04);
                    }
                }

                break;
            }
        }

        nCurGameFlag = uGameFlag;
        nCurImgGameFlag = uImgGameFlag;

        if (bLoadAll)
        {
            ImgDatFile.Abort();
        }

        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

UINT8* CImgDat::RLEDecodeImg(UINT8* pSrcImgData, UINT32 uiDataSz, UINT16 uiImgWidth, UINT16 uiImgHeight)
{
    UINT8* output_data = new UINT8[uiImgWidth * uiImgHeight];
    memset(output_data, NULL, sizeof(UINT8) * uiImgWidth * uiImgHeight);

    UINT8 count = 0;
    bool isDigit = true;
    UINT32 byte_ctr = 0;
    int data_ctr = 0;
    while (byte_ctr < uiDataSz)
    {
        if (isDigit) // The character is numerical...
        {
            // get the count
            count = pSrcImgData[byte_ctr];
            byte_ctr++;
            isDigit = !isDigit;
        }
        else
        {
            // expand the next character by count times
            // the decoding
            for (UINT16 i = 0; i < count; i++)
            {
                output_data[data_ctr + i] = pSrcImgData[byte_ctr];
            }

            byte_ctr++;
            data_ctr += count;
            isDigit = !isDigit;
        }
    }
    return output_data;
}

UINT8* CImgDat::BitMaskRLEDecodeImg(UINT8* pSrcImgData, UINT32 uiDataSz, UINT16 uiImgWidth, UINT16 uiImgHeight)
{
    UINT8* output_data = new UINT8[uiImgWidth * uiImgHeight];
    memset(output_data, NULL, sizeof(UINT8) * uiImgWidth * uiImgHeight);

    UINT32 i_byteCtr = 0;
    UINT32 o_dataCtr = 0;
    UINT32 byteGroups = 0;
    UINT8 extraChunks = 0;

    memcpy(&byteGroups, pSrcImgData, 4);
    i_byteCtr += 4;
    extraChunks = *(pSrcImgData + i_byteCtr++);

    // printf("byteGroups: 0x%08X\n  extraChunks: 0x%02X\n", byteGroups, extraChunks);

    for (UINT32 group = 0; group < byteGroups; group++)
    {
        getBMRLEData(8, pSrcImgData, output_data, i_byteCtr, o_dataCtr);
    }

    if (extraChunks != 0)
    {
        getBMRLEData(extraChunks + 1, pSrcImgData, output_data, i_byteCtr, o_dataCtr);
    }

    return output_data;
}

void CImgDat::getBMRLEData(UINT8 chunkSize, UINT8* inputData, UINT8* output_data, UINT32& i_byteCtr, UINT32& o_dataCtr)
{
    UINT8 data = 0;
    UINT8 bitMask = 0;
    UINT32 count = 0;
    UINT8 tempCount = 0;
    UINT16 multiplier = 0;

    bitMask = *(inputData + i_byteCtr++);
    // printf("New Group - \n  BitMask: 0x%02X\n", bitMask);

    for (UINT8 chunk = 0; chunk < chunkSize; chunk++)
    {
        count = 0;
        tempCount = 0;
        if ((bitMask & (0x80 >> chunk)) != 0)
        {
            count = inputData[i_byteCtr++];
            if (count == 0xFF)
            {
                multiplier = 0;
                tempCount = inputData[i_byteCtr++];
                while (tempCount == 0xFF)
                {
                    multiplier += tempCount;
                    tempCount = inputData[i_byteCtr++];
                }
                multiplier += tempCount;
                count *= multiplier;
                tempCount = inputData[i_byteCtr++];
                count += tempCount;
            }
        }

        data = inputData[i_byteCtr++];
        // printf("    Payload - Count: 0x%08X, Data: 0x%02X\n", count, data);
        if (count != 0)
        {
            for (UINT32 writing = 0; writing < (count - 1); writing++)
            {
                output_data[o_dataCtr++] = data;
            }
        }

        output_data[o_dataCtr++] = data;
    }
}

UINT8* CImgDat::DecodeImg(UINT8* pSrcImgData, UINT32 uiDataSz, UINT16 uiImgWidth, UINT16 uiImgHeight, UINT8 uiBPP)
{

    UINT8* output_data = new UINT8[uiImgWidth * uiImgHeight];
    memset(output_data, NULL, sizeof(UINT8) * uiImgWidth * uiImgHeight);

    UINT32 bit_ctr = 0;
    int data_ctr = 0;
    int k = 0;

    UINT8 uZeroPos;
    UINT8 uExtraAmt;
    UINT8 uGetAmt;
    UINT8 curr_data;
    UINT16 zero_data;
    int get_from_extra;
    int zero_get_amt = 16 - uiBPP;

    while (bit_ctr < (uiDataSz * 8))
    {
        if (((8 - bit_ctr % 8) < uiBPP) && ((bit_ctr / 8) != (uiDataSz - 1)))
        {
            get_from_extra = uiBPP - (8 - bit_ctr % 8);
        }
        else
        {
            get_from_extra = 0;
        }

        curr_data = (pSrcImgData[bit_ctr / 8] >> bit_ctr % 8);

        if (get_from_extra)
        {
            curr_data |= (pSrcImgData[(bit_ctr / 8) + 1] & (0xFF >> (8 - get_from_extra))) << (8 - bit_ctr % 8);
        }

        bit_ctr += uiBPP;
        curr_data = curr_data & (0xFF >> (8 - uiBPP));

        if (curr_data != 0)
        {
            output_data[data_ctr] = curr_data;
            data_ctr++;
        }
        else if (bit_ctr < (uiDataSz * 8))
        {
            zero_data = 0;
            uZeroPos = 0;

            while (uZeroPos < zero_get_amt)
            {
                uExtraAmt = bit_ctr % 8;
                if (zero_get_amt - uZeroPos > 8)
                {
                    uGetAmt = 8 - uExtraAmt;
                }
                else
                {
                    uGetAmt = zero_get_amt - uZeroPos;
                }

                zero_data |= (((UINT16)(pSrcImgData[bit_ctr / 8] >> uExtraAmt) & (0xFF >> (8 - uGetAmt))) << (uZeroPos));

                uZeroPos += uGetAmt;
                bit_ctr += uGetAmt;
            }

            for (k = 0; k < zero_data; k++)
            {
                output_data[data_ctr + k] = 0;
            }
            data_ctr += zero_data;
        }
    }
    return output_data;
}
