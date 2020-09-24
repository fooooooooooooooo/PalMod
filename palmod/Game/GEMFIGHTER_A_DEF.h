#pragma once

// To add characters or palette lists:
// * Update the SupportedPaletteListIndex with the new index name.
// * Add an array below along the lines of GEMFIGHTER_A_RYU_PALETTE_A. 
// * Update every array using GEMFIGHTER_A_NUMUNITS below
// That should be it.  Good luck.

constexpr auto GEMFIGHTER_A_NUMUNITS = indexGemFighterChars_Last;

#define GEMFIGHTER_A_EXTRALOC GEMFIGHTER_A_NUMUNITS

const sGame_PaletteDataset GEMFIGHTER_A_RYU_PALETTES_A[] =
{
    { _T("Ryu A"), 0x0099e6, 0x009A86 },
    { _T("Ryu Portrait A"), 0xc226, 0xc286 },
};

const sGame_PaletteDataset GEMFIGHTER_A_RYU_PALETTES_B[] =
{
    { _T("Ryu B"), 0x009a86, 0x009b26 },
    { _T("Ryu Portrait B"), 0xc286, 0xc2e6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_RYU_PALETTES_C[] =
{
    { _T("Ryu C"), 0x009b26, 0x009bc6 },
    { _T("Ryu Portrait C"), 0xc2e6, 0xc346 },
};

const sGame_PaletteDataset GEMFIGHTER_A_RYU_PALETTES_X3[] =
{
    { _T("Ryu x3"), 0x009bc6, 0x009c66 },
    { _T("Ryu Portrait x3"), 0xc346, 0xc3a6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_KEN_PALETTES_A[] =
{
    { _T("Ken A"), 0x009c66, 0x009d06 },
};

const sGame_PaletteDataset GEMFIGHTER_A_KEN_PALETTES_B[] =
{
    { _T("Ken B"), 0x009d06, 0x009da6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_KEN_PALETTES_C[] =
{
    { _T("Ken C"), 0x009da6, 0x009e46 },
};

const sGame_PaletteDataset GEMFIGHTER_A_KEN_PALETTES_X3[] =
{
    { _T("Ken x3"), 0x009e46, 0x009ee6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_CHUNLI_PALETTES_A[] =
{
    { _T("Chun-Li A"), 0x009ee6, 0x009f86 },
};

const sGame_PaletteDataset GEMFIGHTER_A_CHUNLI_PALETTES_B[] =
{
    { _T("Chun-Li B"), 0x009f86, 0x00a026 },
};

const sGame_PaletteDataset GEMFIGHTER_A_CHUNLI_PALETTES_C[] =
{
    { _T("Chun-Li C"), 0x00a026, 0x00a0c6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_CHUNLI_PALETTES_X3[] =
{
    { _T("Chun-Li x3"), 0x00a0c6, 0x00a166 },
};

const sGame_PaletteDataset GEMFIGHTER_A_SAKURA_PALETTES_A[] =
{
    { _T("Sakura A"), 0x00a166, 0x00a206 },
};

const sGame_PaletteDataset GEMFIGHTER_A_SAKURA_PALETTES_B[] =
{
    { _T("Sakura B"), 0x00a206, 0x00a2a6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_SAKURA_PALETTES_C[] =
{
    { _T("Sakura C"), 0x00a2a6, 0x00a346 },
};

const sGame_PaletteDataset GEMFIGHTER_A_SAKURA_PALETTES_X3[] =
{
    { _T("Sakura x3"), 0x00a346, 0x00a3e6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_MORRIGAN_PALETTES_A[] =
{
    { _T("Morrigan A "), 0x00a3e6, 0x00a486 },
};

const sGame_PaletteDataset GEMFIGHTER_A_MORRIGAN_PALETTES_B[] =
{
    { _T("Morrigan B"), 0x00a486, 0x00a526 },
};

const sGame_PaletteDataset GEMFIGHTER_A_MORRIGAN_PALETTES_C[] =
{
    { _T("Morrigan C "), 0x00a526, 0x00a5c6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_MORRIGAN_PALETTES_X3[] =
{
    { _T("Morrigan x3"), 0x00a5c6, 0x00a666 },
};

const sGame_PaletteDataset GEMFIGHTER_A_HSIENKO_PALETTES_A[] =
{
    { _T("Hsien-Ko A"), 0x00a666, 0x00a706 },
};

const sGame_PaletteDataset GEMFIGHTER_A_HSIENKO_PALETTES_B[] =
{
    { _T("Hsien-Ko B"), 0x00a706, 0x00a7a6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_HSIENKO_PALETTES_C[] =
{
    { _T("Hsien-Ko C"), 0x00a7a6, 0x00a846 },
};

const sGame_PaletteDataset GEMFIGHTER_A_HSIENKO_PALETTES_X3[] =
{
    { _T("Hsien-Ko x3"), 0x00a846, 0x00a8e6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_FELICIA_PALETTES_A[] =
{
    { _T("Felicia A"), 0x00a8e6, 0x00a986 },
};

const sGame_PaletteDataset GEMFIGHTER_A_FELICIA_PALETTES_B[] =
{
    { _T("Felicia B"), 0x00a986, 0x00aa26 },
};

const sGame_PaletteDataset GEMFIGHTER_A_FELICIA_PALETTES_C[] =
{
    { _T("Felicia C "), 0x00aa26, 0x00aac6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_FELICIA_PALETTES_X3[] =
{
    { _T("Felicia x3"), 0x00aac6, 0x00ab66 },
};

const sGame_PaletteDataset GEMFIGHTER_A_TESSA_PALETTES_A[] =
{
    { _T("Tessa A"), 0x00ab66, 0x00ac06 },
};

const sGame_PaletteDataset GEMFIGHTER_A_TESSA_PALETTES_B[] =
{
    { _T("Tessa B"), 0x00ac06, 0x00aca6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_TESSA_PALETTES_C[] =
{
    { _T("Tessa C "), 0x00aca6, 0x00ad46 },
};

const sGame_PaletteDataset GEMFIGHTER_A_TESSA_PALETTES_X3[] =
{
    { _T("Tessa x3"), 0x00ad46, 0x00ade6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_IBUKI_PALETTES_A[] =
{
    { _T("Ibuki A"), 0x00ade6, 0x00ae86 },
};

const sGame_PaletteDataset GEMFIGHTER_A_IBUKI_PALETTES_B[] =
{
    { _T("Ibuki B"), 0x00ae86, 0x00af26 },
};

const sGame_PaletteDataset GEMFIGHTER_A_IBUKI_PALETTES_C[] =
{
    { _T("Ibuki C "), 0x00af26, 0x00afc6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_IBUKI_PALETTES_X3[] =
{
    { _T("Ibuki x3"), 0x00afc6, 0x00b066 },
};

const sGame_PaletteDataset GEMFIGHTER_A_ZANGIEF_PALETTES_A[] =
{
    { _T("Zangief A"), 0x00b066, 0x00b106 },
};

const sGame_PaletteDataset GEMFIGHTER_A_ZANGIEF_PALETTES_B[] =
{
    { _T("Zangief B"), 0x00b106, 0x00b1a6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_ZANGIEF_PALETTES_C[] =
{
    { _T("Zangief C"), 0x00b1a6, 0x00b246 },
};

const sGame_PaletteDataset GEMFIGHTER_A_ZANGIEF_PALETTES_X3[] =
{
    { _T("Zangief x3"), 0x00b246, 0x00b2e6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_DAN_PALETTES_A[] =
{
    { _T("Dan A"), 0x00b2e6, 0x00b386 },
};

const sGame_PaletteDataset GEMFIGHTER_A_DAN_PALETTES_B[] =
{
    { _T("Dan B"), 0x00b386, 0x00b426 },
};

const sGame_PaletteDataset GEMFIGHTER_A_DAN_PALETTES_C[] =
{
    { _T("Dan C"), 0x00b426, 0x00b4c6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_DAN_PALETTES_X3[] =
{
    { _T("Dan x3"), 0x00b4c6, 0x00b566 },
};

const sGame_PaletteDataset GEMFIGHTER_A_AKUMA_PALETTES_A[] =
{
    { _T("Akuma A"), 0x00b566, 0x00b606 },
};

const sGame_PaletteDataset GEMFIGHTER_A_AKUMA_PALETTES_B[] =
{
    { _T("Akuma B"), 0x00b606, 0x00b6a6 },
};

const sGame_PaletteDataset GEMFIGHTER_A_AKUMA_PALETTES_C[] =
{
    { _T("Akuma C"), 0x00b6a6, 0x00b746 },
};

const sGame_PaletteDataset GEMFIGHTER_A_AKUMA_PALETTES_X3[] =
{
    { _T("Akuma x3"), 0x00b746, 0x00b7e6 },
};

const sDescTreeNode GEMFIGHTER_A_RYU_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_RYU_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_RYU_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_RYU_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_RYU_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_RYU_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_RYU_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_RYU_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_RYU_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_KEN_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_KEN_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_KEN_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_KEN_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_KEN_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_KEN_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_KEN_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_KEN_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_KEN_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_CHUNLI_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_CHUNLI_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_CHUNLI_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_CHUNLI_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_CHUNLI_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_CHUNLI_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_CHUNLI_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_CHUNLI_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_CHUNLI_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_SAKURA_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_SAKURA_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_SAKURA_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_SAKURA_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_SAKURA_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_SAKURA_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_SAKURA_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_SAKURA_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_SAKURA_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_MORRIGAN_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_MORRIGAN_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_MORRIGAN_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_MORRIGAN_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_MORRIGAN_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_MORRIGAN_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_MORRIGAN_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_MORRIGAN_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_MORRIGAN_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_HSIENKO_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_HSIENKO_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_HSIENKO_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_HSIENKO_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_HSIENKO_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_HSIENKO_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_HSIENKO_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_HSIENKO_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_HSIENKO_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_FELICIA_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_FELICIA_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_FELICIA_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_FELICIA_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_FELICIA_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_FELICIA_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_FELICIA_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_FELICIA_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_FELICIA_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_TESSA_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_TESSA_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_TESSA_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_TESSA_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_TESSA_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_TESSA_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_TESSA_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_TESSA_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_TESSA_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_IBUKI_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_IBUKI_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_IBUKI_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_IBUKI_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_IBUKI_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_IBUKI_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_IBUKI_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_IBUKI_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_IBUKI_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_ZANGIEF_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_ZANGIEF_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_ZANGIEF_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_ZANGIEF_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_ZANGIEF_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_ZANGIEF_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_ZANGIEF_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_ZANGIEF_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_ZANGIEF_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_DAN_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_DAN_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_DAN_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_DAN_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_DAN_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_DAN_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_DAN_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_DAN_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_DAN_PALETTES_X3) },
};

const sDescTreeNode GEMFIGHTER_A_AKUMA_COLLECTION[] =
{
    { _T("A"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_AKUMA_PALETTES_A, ARRAYSIZE(GEMFIGHTER_A_AKUMA_PALETTES_A) },
    { _T("B"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_AKUMA_PALETTES_B, ARRAYSIZE(GEMFIGHTER_A_AKUMA_PALETTES_B) },
    { _T("C"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_AKUMA_PALETTES_C, ARRAYSIZE(GEMFIGHTER_A_AKUMA_PALETTES_C) },
    { _T("X3"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_AKUMA_PALETTES_X3, ARRAYSIZE(GEMFIGHTER_A_AKUMA_PALETTES_X3) },
};

const sGame_PaletteDataset GEMFIGHTER_A_BONUS_PALETTES[] =
{
    { _T("Insert Coin / Char Names / After Battle Text / Timer Numbers"), 0xbde6, 0xbe06 },
    { _T("HUD"), 0xbe66, 0xbe86 },
    { _T("Intro Cascade Gems"), 0xbf26, 0xbf66 },
};

const sDescTreeNode GEMFIGHTER_A_BONUS_COLLECTION[] =
{
    { _T("Palettes"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_BONUS_PALETTES, ARRAYSIZE(GEMFIGHTER_A_BONUS_PALETTES) },
};

const UINT8 GEMFIGHTER_A_UNITSORT[GEMFIGHTER_A_NUMUNITS + 1] // Plus 1 for extras
{
    indexGemFighterChars_Akuma,
    indexGemFighterChars_ChunLi,
    indexGemFighterChars_Dan,
    indexGemFighterChars_Felicia,
    indexGemFighterChars_HsienKo,
    indexGemFighterChars_Ibuki,
    indexGemFighterChars_Ken,
    indexGemFighterChars_Morrigan,
    indexGemFighterChars_Ryu,
    indexGemFighterChars_Sakura,
    indexGemFighterChars_Tessa,
    indexGemFighterChars_Zangief,
    indexGemFighterChars_Bonus,
    
    GEMFIGHTER_A_EXTRALOC
};

const sDescTreeNode GEMFIGHTER_A_UNITS[GEMFIGHTER_A_NUMUNITS] =
{
    { _T("Ryu"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_RYU_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_RYU_COLLECTION) },
    { _T("Ken"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_KEN_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_KEN_COLLECTION) },
    { _T("Chun-Li"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_CHUNLI_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_CHUNLI_COLLECTION) },
    { _T("Sakura"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_SAKURA_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_SAKURA_COLLECTION) },
    { _T("Morrigan"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_MORRIGAN_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_MORRIGAN_COLLECTION) },
    { _T("Hsien-Ko"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_HSIENKO_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_HSIENKO_COLLECTION) },
    { _T("Felicia"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_FELICIA_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_FELICIA_COLLECTION) },
    { _T("Tessa"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_TESSA_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_TESSA_COLLECTION) },
    { _T("Ibuki"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_IBUKI_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_IBUKI_COLLECTION) },
    { _T("Zangief"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_ZANGIEF_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_ZANGIEF_COLLECTION) },
    { _T("Dan"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_DAN_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_DAN_COLLECTION) },
    { _T("Akuma"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_AKUMA_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_AKUMA_COLLECTION) },
    { _T("Bonus Stuff"), DESC_NODETYPE_TREE, (void*)GEMFIGHTER_A_BONUS_COLLECTION, ARRAYSIZE(GEMFIGHTER_A_BONUS_COLLECTION) },
};

// We extend this array with data groveled from the GarouE.txt extensible extras file, if any.
const stExtraDef GEMFIGHTER_A_EXTRA[] =
{
    // Start
    { UNIT_START_VALUE },

    { INVALID_UNIT_VALUE }
};