#pragma once

// To add characters or palette lists:
// * Update the SupportedPaletteListIndex with the new index name.
// * Add an array below along the lines of CVS2_A_KYO_PALETTE_A. 
// * Update every array using CVS2_A_NUMUNIT below
// That should be it.  Good luck.

#define CVS2_A_EXTRALOC CVS2_A_NUMUNIT

struct sCVS2_CharacterDump
{
    LPCSTR pszCharacterName = nullptr;
    LPCSTR pszCodeDesc = nullptr;
    UINT32 romOffset = 0;
    LPCSTR pszImageRefName = nullptr;
};

const sCVS2_CharacterDump CVS2_CharacterOffsetArray[] =
{
    // This is sorted in ROM layout order
    { "Ryu", "RYU", 0x1488e80, "indexCVS2Sprites_Ryu" },
    { "Ken", "KEN", 0x1553500, "indexCVS2Sprites_Ken" },
    { "Chun-Li", "CHUNLI", 0x166f140, "indexCVS2Sprites_ChunLi" },
    { "Guile", "GUILE", 0x1777de0, "indexCVS2Sprites_Guile" },
    { "Zangief", "ZANGIEF", 0x1880800, "indexCVS2Sprites_Zangief" },
    { "Dhalsim", "DHALSIM", 0x19aef60, "indexCVS2Sprites_Dhalsim" },
    { "E.Honda", "EHONDA", 0x1a33500, "indexCVS2Sprites_EHonda" },
    { "Blanka", "BLANKA", 0x1b32560, "indexCVS2Sprites_Blanka" },
    { "Vega", "VEGA", 0x1bfe160, "indexCVS2Sprites_Vega" },
    { "Sagat", "SAGAT", 0x1c9b720, "indexCVS2Sprites_Sagat" },
    { "M.Bison", "BISON", 0x1d71a60, "indexCVS2Sprites_MBison" },
    { "Sakura", "SAKURA", 0x1e961A0, "indexCVS2Sprites_Sakura" },
    { "Cammy", "CAMMY", 0x1f6fc60, "indexCVS2Sprites_Cammy" },
    { "Akuma", "AKUMA", 0x20759C0, "indexCVS2Sprites_Akuma" },
    { "Morrigan", "MORRIGAN", 0x21AD920, "indexCVS2Sprites_Morrigan" },
    { "Evil Ryu", "EVILRYU", 0x22a4800, "indexCVS2Sprites_EvilRyu" },
    { "Kyo", "KYO", 0x23a5180, "indexCVS2Sprites_Kyo" },
    { "Iori", "IORI", 0x248f660, "indexCVS2Sprites_Iori" },
    { "Terry Bogard", "TERRT", 0x257a360, "indexCVS2Sprites_Terry" },
    { "Ryo", "RYO", 0x265c5c0, "indexCVS2Sprites_Ryo" },
    { "Mai", "MAI", 0x2741ce0, "indexCVS2Sprites_Mai" },
    { "Kim", "KIM", 0x27d80a0, "indexCVS2Sprites_Kim" },
    { "Geese", "GEESE", 0x28e8ee0, "indexCVS2Sprites_Geese" },
    { "Yamazaki", "YAMAZAKI", 0x29fcd40, "indexCVS2Sprites_RyujiYamazaki" },
    { "Raiden", "RAIDEN", 0x2af5a20, "indexCVS2Sprites_Raiden" },
    { "Rugal", "RUGAL", 0x2c28660, "indexCVS2Sprites_Rugal" },
    { "Vice", "VICE", 0x2d18200, "indexCVS2Sprites_Vice" },
    { "Benimaru", "BENIMARU", 0x2e38300, "indexCVS2Sprites_Benimaru" },
    { "Yuri", "YURI", 0x2edf8e0, "indexCVS2Sprites_Yuri" },
    { "King", "KING", 0x2f76140, "indexCVS2Sprites_King" },
    { "Nakoruru", "NAKORURU", 0x3069680, "indexCVS2Sprites_Nakoruru" },
    { "Orochi Iori", "OROCHIIORI", 0x314b5a0, "indexCVS2Sprites_OrochiIori" },
    { "Balrog", "BALROG", 0x31d3320, "indexCVS2Sprites_Balrog" },
    { "Dan", "DAN", 0x328c960, "indexCVS2Sprites_Dan" },
    { "Joe", "Joe", 0x3344620, "indexCVS2Sprites_Joe" },
    { "Eagle", "EAGLE", 0x342f920, "indexCVS2Sprites_Eagle" },
    { "Maki", "MAKI", 0x34f71a0, "indexCVS2Sprites_Maki" },
    { "Kyosuke", "KYOSUKE", 0x36134a0, "indexCVS2Sprites_Kyosuke" },
    { "Athena", "ATHENA", 0x36e48a0, "indexCVS2Sprites_Athena" },
    { "Chang and Choi", "CHANG", 0x38111a0, "indexCVS2Sprites_Chang" },
    { "Todoh", "TODOH", 0x38fc140, "indexCVS2Sprites_RyuhakuTodoh" },
    { "Rock Howard", "ROCK", 0x3a34ea0, "indexCVS2Sprites_Rock" },
    { "Hibiki", "HIBIKI", 0x3b16dc0, "indexCVS2Sprites_Hibiki" },
    { "Haohmaru", "HAOHMARU", 0x3c4ed80, "indexCVS2Sprites_Haohmaru" },
    { "Yun", "YUN", 0x3d52a20, "indexCVS2Sprites_Yun" },
    { "Shin Akuma", "SHINAKUMA", 0x3e75a80, "indexCVS2Sprites_ShinAkuma" },
    { "God Rugal", "GODRUGAL", 0x3fab320, "indexCVS2Sprites_GodRugal" },
    { "Rolento", "ROLENTO", 0x40d69a0, "indexCVS2Sprites_Rolento" },

};

// max x600 color range
   // 0xc0 is per sprite

   // ryu -- 
   // 0000 9CF3 10FB 8CF6 08EE 66D1 03B5 00F8 00D8 00C0 FDFF 98F3 F2E6 90D6 0DC2 4288
   // 0000 F39C FB10 F68C EE08 D166 B503 F800
   //{ "Ryu", 0x16ae10, 0x16AFB0 }, <-- 0x600 color range that also starts with ryu, but isn't him

const sGame_PaletteDataset CVS2_A_RYU_PALETTES_LP[] =
{
    { "Main Sprite", 0x1488e80, 0x1488ea0, indexCVS2Sprites_Ryu },
    { "Extra 1", 0x1488ea0, 0x1488ec0 },
    { "Extra 2", 0x1488ec0, 0x1488ee0 },
    { "Extra 3", 0x1488ee0, 0x1488f00 },
    { "Extra 4", 0x1488f00, 0x1488f20 },
    { "Extra 5", 0x1488f20, 0x1488f40 },
};

const sGame_PaletteDataset CVS2_A_RYU_PALETTES_MP[] =
{
    { "Main Sprite", 0x1488f40, 0x1488f60, indexCVS2Sprites_Ryu },
    { "Extra 1", 0x1488f60, 0x1488f80 },
    { "Extra 2", 0x1488f80, 0x1488fa0 },
    { "Extra 3", 0x1488fa0, 0x1488fc0 },
    { "Extra 4", 0x1488fc0, 0x1488fe0 },
    { "Extra 5", 0x1488fe0, 0x1489000 },
};

const sGame_PaletteDataset CVS2_A_RYU_PALETTES_HP[] =
{
    { "Main Sprite", 0x1489000, 0x1489020, indexCVS2Sprites_Ryu },
    { "Extra 1", 0x1489020, 0x1489040 },
    { "Extra 2", 0x1489040, 0x1489060 },
    { "Extra 3", 0x1489060, 0x1489080 },
    { "Extra 4", 0x1489080, 0x14890a0 },
    { "Extra 5", 0x14890a0, 0x14890c0 },
};

const sGame_PaletteDataset CVS2_A_RYU_PALETTES_LK[] =
{
    { "Main Sprite", 0x14890c0, 0x14890e0, indexCVS2Sprites_Ryu },
    { "Extra 1", 0x14890e0, 0x1489100 },
    { "Extra 2", 0x1489100, 0x1489120 },
    { "Extra 3", 0x1489120, 0x1489140 },
    { "Extra 4", 0x1489140, 0x1489160 },
    { "Extra 5", 0x1489160, 0x1489180 },
};

const sGame_PaletteDataset CVS2_A_RYU_PALETTES_MK[] =
{
    { "Main Sprite", 0x1489180, 0x14891a0, indexCVS2Sprites_Ryu },
    { "Extra 1", 0x14891a0, 0x14891c0 },
    { "Extra 2", 0x14891c0, 0x14891e0 },
    { "Extra 3", 0x14891e0, 0x1489200 },
    { "Extra 4", 0x1489200, 0x1489220 },
    { "Extra 5", 0x1489220, 0x1489240 },
};

const sGame_PaletteDataset CVS2_A_RYU_PALETTES_HK[] =
{
    { "Main Sprite", 0x1489240, 0x1489260, indexCVS2Sprites_Ryu },
    { "Extra 1", 0x1489260, 0x1489280 },
    { "Extra 2", 0x1489280, 0x14892a0 },
    { "Extra 3", 0x14892a0, 0x14892c0 },
    { "Extra 4", 0x14892c0, 0x14892e0 },
    { "Extra 5", 0x14892e0, 0x1489300 },
};

const sGame_PaletteDataset CVS2_A_RYU_PALETTES_3P[] =
{
    { "Main Sprite", 0x1489300, 0x1489320, indexCVS2Sprites_Ryu },
    { "Extra 1", 0x1489320, 0x1489340 },
    { "Extra 2", 0x1489340, 0x1489360 },
    { "Extra 3", 0x1489360, 0x1489380 },
    { "Extra 4", 0x1489380, 0x14893a0 },
    { "Extra 5", 0x14893a0, 0x14893c0 },
};

const sGame_PaletteDataset CVS2_A_RYU_PALETTES_3K[] =
{
    { "Main Sprite", 0x14893c0, 0x14893e0, indexCVS2Sprites_Ryu },
    { "Extra 1", 0x14893e0, 0x1489400 },
    { "Extra 2", 0x1489400, 0x1489420 },
    { "Extra 3", 0x1489420, 0x1489440 },
    { "Extra 4", 0x1489440, 0x1489460 },
    { "Extra 5", 0x1489460, 0x1489480 },
};

const sDescTreeNode CVS2_A_RYU_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_RYU_PALETTES_LP, ARRAYSIZE(CVS2_A_RYU_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_RYU_PALETTES_MP, ARRAYSIZE(CVS2_A_RYU_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_RYU_PALETTES_HP, ARRAYSIZE(CVS2_A_RYU_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_RYU_PALETTES_LK, ARRAYSIZE(CVS2_A_RYU_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_RYU_PALETTES_MK, ARRAYSIZE(CVS2_A_RYU_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_RYU_PALETTES_HK, ARRAYSIZE(CVS2_A_RYU_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_RYU_PALETTES_3P, ARRAYSIZE(CVS2_A_RYU_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_RYU_PALETTES_3K, ARRAYSIZE(CVS2_A_RYU_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_KEN_PALETTES_LP[] =
{
    { "Main Sprite", 0x1553500, 0x1553520, indexCVS2Sprites_Ken },
    { "Extra 1", 0x1553520, 0x1553540 },
    { "Extra 2", 0x1553540, 0x1553560 },
    { "Extra 3", 0x1553560, 0x1553580 },
    { "Extra 4", 0x1553580, 0x15535a0 },
    { "Extra 5", 0x15535a0, 0x15535c0 },
};

const sGame_PaletteDataset CVS2_A_KEN_PALETTES_MP[] =
{
    { "Main Sprite", 0x15535c0, 0x15535e0, indexCVS2Sprites_Ken },
    { "Extra 1", 0x15535e0, 0x1553600 },
    { "Extra 2", 0x1553600, 0x1553620 },
    { "Extra 3", 0x1553620, 0x1553640 },
    { "Extra 4", 0x1553640, 0x1553660 },
    { "Extra 5", 0x1553660, 0x1553680 },
};

const sGame_PaletteDataset CVS2_A_KEN_PALETTES_HP[] =
{
    { "Main Sprite", 0x1553680, 0x15536a0, indexCVS2Sprites_Ken },
    { "Extra 1", 0x15536a0, 0x15536c0 },
    { "Extra 2", 0x15536c0, 0x15536e0 },
    { "Extra 3", 0x15536e0, 0x1553700 },
    { "Extra 4", 0x1553700, 0x1553720 },
    { "Extra 5", 0x1553720, 0x1553740 },
};

const sGame_PaletteDataset CVS2_A_KEN_PALETTES_LK[] =
{
    { "Main Sprite", 0x1553740, 0x1553760, indexCVS2Sprites_Ken },
    { "Extra 1", 0x1553760, 0x1553780 },
    { "Extra 2", 0x1553780, 0x15537a0 },
    { "Extra 3", 0x15537a0, 0x15537c0 },
    { "Extra 4", 0x15537c0, 0x15537e0 },
    { "Extra 5", 0x15537e0, 0x1553800 },
};

const sGame_PaletteDataset CVS2_A_KEN_PALETTES_MK[] =
{
    { "Main Sprite", 0x1553800, 0x1553820, indexCVS2Sprites_Ken },
    { "Extra 1", 0x1553820, 0x1553840 },
    { "Extra 2", 0x1553840, 0x1553860 },
    { "Extra 3", 0x1553860, 0x1553880 },
    { "Extra 4", 0x1553880, 0x15538a0 },
    { "Extra 5", 0x15538a0, 0x15538c0 },
};

const sGame_PaletteDataset CVS2_A_KEN_PALETTES_HK[] =
{
    { "Main Sprite", 0x15538c0, 0x15538e0, indexCVS2Sprites_Ken },
    { "Extra 1", 0x15538e0, 0x1553900 },
    { "Extra 2", 0x1553900, 0x1553920 },
    { "Extra 3", 0x1553920, 0x1553940 },
    { "Extra 4", 0x1553940, 0x1553960 },
    { "Extra 5", 0x1553960, 0x1553980 },
};

const sGame_PaletteDataset CVS2_A_KEN_PALETTES_3P[] =
{
    { "Main Sprite", 0x1553980, 0x15539a0, indexCVS2Sprites_Ken },
    { "Extra 1", 0x15539a0, 0x15539c0 },
    { "Extra 2", 0x15539c0, 0x15539e0 },
    { "Extra 3", 0x15539e0, 0x1553a00 },
    { "Extra 4", 0x1553a00, 0x1553a20 },
    { "Extra 5", 0x1553a20, 0x1553a40 },
};

const sGame_PaletteDataset CVS2_A_KEN_PALETTES_3K[] =
{
    { "Main Sprite", 0x1553a40, 0x1553a60, indexCVS2Sprites_Ken },
    { "Extra 1", 0x1553a60, 0x1553a80 },
    { "Extra 2", 0x1553a80, 0x1553aa0 },
    { "Extra 3", 0x1553aa0, 0x1553ac0 },
    { "Extra 4", 0x1553ac0, 0x1553ae0 },
    { "Extra 5", 0x1553ae0, 0x1553b00 },
};

const sDescTreeNode CVS2_A_KEN_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_KEN_PALETTES_LP, ARRAYSIZE(CVS2_A_KEN_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_KEN_PALETTES_MP, ARRAYSIZE(CVS2_A_KEN_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_KEN_PALETTES_HP, ARRAYSIZE(CVS2_A_KEN_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_KEN_PALETTES_LK, ARRAYSIZE(CVS2_A_KEN_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_KEN_PALETTES_MK, ARRAYSIZE(CVS2_A_KEN_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_KEN_PALETTES_HK, ARRAYSIZE(CVS2_A_KEN_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_KEN_PALETTES_3P, ARRAYSIZE(CVS2_A_KEN_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_KEN_PALETTES_3K, ARRAYSIZE(CVS2_A_KEN_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_CHUNLI_PALETTES_LP[] =
{
    { "Main Sprite", 0x166f140, 0x166f160, indexCVS2Sprites_ChunLi },
    { "Extra 1", 0x166f160, 0x166f180 },
    { "Extra 2", 0x166f180, 0x166f1a0 },
    { "Extra 3", 0x166f1a0, 0x166f1c0 },
    { "Extra 4", 0x166f1c0, 0x166f1e0 },
    { "Extra 5", 0x166f1e0, 0x166f200 },
};

const sGame_PaletteDataset CVS2_A_CHUNLI_PALETTES_MP[] =
{
    { "Main Sprite", 0x166f200, 0x166f220, indexCVS2Sprites_ChunLi },
    { "Extra 1", 0x166f220, 0x166f240 },
    { "Extra 2", 0x166f240, 0x166f260 },
    { "Extra 3", 0x166f260, 0x166f280 },
    { "Extra 4", 0x166f280, 0x166f2a0 },
    { "Extra 5", 0x166f2a0, 0x166f2c0 },
};

const sGame_PaletteDataset CVS2_A_CHUNLI_PALETTES_HP[] =
{
    { "Main Sprite", 0x166f2c0, 0x166f2e0, indexCVS2Sprites_ChunLi },
    { "Extra 1", 0x166f2e0, 0x166f300 },
    { "Extra 2", 0x166f300, 0x166f320 },
    { "Extra 3", 0x166f320, 0x166f340 },
    { "Extra 4", 0x166f340, 0x166f360 },
    { "Extra 5", 0x166f360, 0x166f380 },
};

const sGame_PaletteDataset CVS2_A_CHUNLI_PALETTES_LK[] =
{
    { "Main Sprite", 0x166f380, 0x166f3a0, indexCVS2Sprites_ChunLi },
    { "Extra 1", 0x166f3a0, 0x166f3c0 },
    { "Extra 2", 0x166f3c0, 0x166f3e0 },
    { "Extra 3", 0x166f3e0, 0x166f400 },
    { "Extra 4", 0x166f400, 0x166f420 },
    { "Extra 5", 0x166f420, 0x166f440 },
};

const sGame_PaletteDataset CVS2_A_CHUNLI_PALETTES_MK[] =
{
    { "Main Sprite", 0x166f440, 0x166f460, indexCVS2Sprites_ChunLi },
    { "Extra 1", 0x166f460, 0x166f480 },
    { "Extra 2", 0x166f480, 0x166f4a0 },
    { "Extra 3", 0x166f4a0, 0x166f4c0 },
    { "Extra 4", 0x166f4c0, 0x166f4e0 },
    { "Extra 5", 0x166f4e0, 0x166f500 },
};

const sGame_PaletteDataset CVS2_A_CHUNLI_PALETTES_HK[] =
{
    { "Main Sprite", 0x166f500, 0x166f520, indexCVS2Sprites_ChunLi },
    { "Extra 1", 0x166f520, 0x166f540 },
    { "Extra 2", 0x166f540, 0x166f560 },
    { "Extra 3", 0x166f560, 0x166f580 },
    { "Extra 4", 0x166f580, 0x166f5a0 },
    { "Extra 5", 0x166f5a0, 0x166f5c0 },
};

const sGame_PaletteDataset CVS2_A_CHUNLI_PALETTES_3P[] =
{
    { "Main Sprite", 0x166f5c0, 0x166f5e0, indexCVS2Sprites_ChunLi },
    { "Extra 1", 0x166f5e0, 0x166f600 },
    { "Extra 2", 0x166f600, 0x166f620 },
    { "Extra 3", 0x166f620, 0x166f640 },
    { "Extra 4", 0x166f640, 0x166f660 },
    { "Extra 5", 0x166f660, 0x166f680 },
};

const sGame_PaletteDataset CVS2_A_CHUNLI_PALETTES_3K[] =
{
    { "Main Sprite", 0x166f680, 0x166f6a0, indexCVS2Sprites_ChunLi },
    { "Extra 1", 0x166f6a0, 0x166f6c0 },
    { "Extra 2", 0x166f6c0, 0x166f6e0 },
    { "Extra 3", 0x166f6e0, 0x166f700 },
    { "Extra 4", 0x166f700, 0x166f720 },
    { "Extra 5", 0x166f720, 0x166f740 },
};

const sDescTreeNode CVS2_A_CHUNLI_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_CHUNLI_PALETTES_LP, ARRAYSIZE(CVS2_A_CHUNLI_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_CHUNLI_PALETTES_MP, ARRAYSIZE(CVS2_A_CHUNLI_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_CHUNLI_PALETTES_HP, ARRAYSIZE(CVS2_A_CHUNLI_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_CHUNLI_PALETTES_LK, ARRAYSIZE(CVS2_A_CHUNLI_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_CHUNLI_PALETTES_MK, ARRAYSIZE(CVS2_A_CHUNLI_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_CHUNLI_PALETTES_HK, ARRAYSIZE(CVS2_A_CHUNLI_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_CHUNLI_PALETTES_3P, ARRAYSIZE(CVS2_A_CHUNLI_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_CHUNLI_PALETTES_3K, ARRAYSIZE(CVS2_A_CHUNLI_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_GUILE_PALETTES_LP[] =
{
    { "Main Sprite", 0x1777de0, 0x1777e00, indexCVS2Sprites_Guile },
    { "Extra 1", 0x1777e00, 0x1777e20 },
    { "Extra 2", 0x1777e20, 0x1777e40 },
    { "Extra 3", 0x1777e40, 0x1777e60 },
    { "Extra 4", 0x1777e60, 0x1777e80 },
    { "Extra 5", 0x1777e80, 0x1777ea0 },
};

const sGame_PaletteDataset CVS2_A_GUILE_PALETTES_MP[] =
{
    { "Main Sprite", 0x1777ea0, 0x1777ec0, indexCVS2Sprites_Guile },
    { "Extra 1", 0x1777ec0, 0x1777ee0 },
    { "Extra 2", 0x1777ee0, 0x1777f00 },
    { "Extra 3", 0x1777f00, 0x1777f20 },
    { "Extra 4", 0x1777f20, 0x1777f40 },
    { "Extra 5", 0x1777f40, 0x1777f60 },
};

const sGame_PaletteDataset CVS2_A_GUILE_PALETTES_HP[] =
{
    { "Main Sprite", 0x1777f60, 0x1777f80, indexCVS2Sprites_Guile },
    { "Extra 1", 0x1777f80, 0x1777fa0 },
    { "Extra 2", 0x1777fa0, 0x1777fc0 },
    { "Extra 3", 0x1777fc0, 0x1777fe0 },
    { "Extra 4", 0x1777fe0, 0x1778000 },
    { "Extra 5", 0x1778000, 0x1778020 },
};

const sGame_PaletteDataset CVS2_A_GUILE_PALETTES_LK[] =
{
    { "Main Sprite", 0x1778020, 0x1778040, indexCVS2Sprites_Guile },
    { "Extra 1", 0x1778040, 0x1778060 },
    { "Extra 2", 0x1778060, 0x1778080 },
    { "Extra 3", 0x1778080, 0x17780a0 },
    { "Extra 4", 0x17780a0, 0x17780c0 },
    { "Extra 5", 0x17780c0, 0x17780e0 },
};

const sGame_PaletteDataset CVS2_A_GUILE_PALETTES_MK[] =
{
    { "Main Sprite", 0x17780e0, 0x1778100, indexCVS2Sprites_Guile },
    { "Extra 1", 0x1778100, 0x1778120 },
    { "Extra 2", 0x1778120, 0x1778140 },
    { "Extra 3", 0x1778140, 0x1778160 },
    { "Extra 4", 0x1778160, 0x1778180 },
    { "Extra 5", 0x1778180, 0x17781a0 },
};

const sGame_PaletteDataset CVS2_A_GUILE_PALETTES_HK[] =
{
    { "Main Sprite", 0x17781a0, 0x17781c0, indexCVS2Sprites_Guile },
    { "Extra 1", 0x17781c0, 0x17781e0 },
    { "Extra 2", 0x17781e0, 0x1778200 },
    { "Extra 3", 0x1778200, 0x1778220 },
    { "Extra 4", 0x1778220, 0x1778240 },
    { "Extra 5", 0x1778240, 0x1778260 },
};

const sGame_PaletteDataset CVS2_A_GUILE_PALETTES_3P[] =
{
    { "Main Sprite", 0x1778260, 0x1778280, indexCVS2Sprites_Guile },
    { "Extra 1", 0x1778280, 0x17782a0 },
    { "Extra 2", 0x17782a0, 0x17782c0 },
    { "Extra 3", 0x17782c0, 0x17782e0 },
    { "Extra 4", 0x17782e0, 0x1778300 },
    { "Extra 5", 0x1778300, 0x1778320 },
};

const sGame_PaletteDataset CVS2_A_GUILE_PALETTES_3K[] =
{
    { "Main Sprite", 0x1778320, 0x1778340, indexCVS2Sprites_Guile },
    { "Extra 1", 0x1778340, 0x1778360 },
    { "Extra 2", 0x1778360, 0x1778380 },
    { "Extra 3", 0x1778380, 0x17783a0 },
    { "Extra 4", 0x17783a0, 0x17783c0 },
    { "Extra 5", 0x17783c0, 0x17783e0 },
};

const sDescTreeNode CVS2_A_GUILE_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_GUILE_PALETTES_LP, ARRAYSIZE(CVS2_A_GUILE_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_GUILE_PALETTES_MP, ARRAYSIZE(CVS2_A_GUILE_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_GUILE_PALETTES_HP, ARRAYSIZE(CVS2_A_GUILE_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_GUILE_PALETTES_LK, ARRAYSIZE(CVS2_A_GUILE_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_GUILE_PALETTES_MK, ARRAYSIZE(CVS2_A_GUILE_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_GUILE_PALETTES_HK, ARRAYSIZE(CVS2_A_GUILE_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_GUILE_PALETTES_3P, ARRAYSIZE(CVS2_A_GUILE_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_GUILE_PALETTES_3K, ARRAYSIZE(CVS2_A_GUILE_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_ZANGIEF_PALETTES_LP[] =
{
    { "Main Sprite", 0x1880800, 0x1880820, indexCVS2Sprites_Zangief },
    { "Extra 1", 0x1880820, 0x1880840 },
    { "Extra 2", 0x1880840, 0x1880860 },
    { "Extra 3", 0x1880860, 0x1880880 },
    { "Extra 4", 0x1880880, 0x18808a0 },
    { "Extra 5", 0x18808a0, 0x18808c0 },
};

const sGame_PaletteDataset CVS2_A_ZANGIEF_PALETTES_MP[] =
{
    { "Main Sprite", 0x18808c0, 0x18808e0, indexCVS2Sprites_Zangief },
    { "Extra 1", 0x18808e0, 0x1880900 },
    { "Extra 2", 0x1880900, 0x1880920 },
    { "Extra 3", 0x1880920, 0x1880940 },
    { "Extra 4", 0x1880940, 0x1880960 },
    { "Extra 5", 0x1880960, 0x1880980 },
};

const sGame_PaletteDataset CVS2_A_ZANGIEF_PALETTES_HP[] =
{
    { "Main Sprite", 0x1880980, 0x18809a0, indexCVS2Sprites_Zangief },
    { "Extra 1", 0x18809a0, 0x18809c0 },
    { "Extra 2", 0x18809c0, 0x18809e0 },
    { "Extra 3", 0x18809e0, 0x1880a00 },
    { "Extra 4", 0x1880a00, 0x1880a20 },
    { "Extra 5", 0x1880a20, 0x1880a40 },
};

const sGame_PaletteDataset CVS2_A_ZANGIEF_PALETTES_LK[] =
{
    { "Main Sprite", 0x1880a40, 0x1880a60, indexCVS2Sprites_Zangief },
    { "Extra 1", 0x1880a60, 0x1880a80 },
    { "Extra 2", 0x1880a80, 0x1880aa0 },
    { "Extra 3", 0x1880aa0, 0x1880ac0 },
    { "Extra 4", 0x1880ac0, 0x1880ae0 },
    { "Extra 5", 0x1880ae0, 0x1880b00 },
};

const sGame_PaletteDataset CVS2_A_ZANGIEF_PALETTES_MK[] =
{
    { "Main Sprite", 0x1880b00, 0x1880b20, indexCVS2Sprites_Zangief },
    { "Extra 1", 0x1880b20, 0x1880b40 },
    { "Extra 2", 0x1880b40, 0x1880b60 },
    { "Extra 3", 0x1880b60, 0x1880b80 },
    { "Extra 4", 0x1880b80, 0x1880ba0 },
    { "Extra 5", 0x1880ba0, 0x1880bc0 },
};

const sGame_PaletteDataset CVS2_A_ZANGIEF_PALETTES_HK[] =
{
    { "Main Sprite", 0x1880bc0, 0x1880be0, indexCVS2Sprites_Zangief },
    { "Extra 1", 0x1880be0, 0x1880c00 },
    { "Extra 2", 0x1880c00, 0x1880c20 },
    { "Extra 3", 0x1880c20, 0x1880c40 },
    { "Extra 4", 0x1880c40, 0x1880c60 },
    { "Extra 5", 0x1880c60, 0x1880c80 },
};

const sGame_PaletteDataset CVS2_A_ZANGIEF_PALETTES_3P[] =
{
    { "Main Sprite", 0x1880c80, 0x1880ca0, indexCVS2Sprites_Zangief },
    { "Extra 1", 0x1880ca0, 0x1880cc0 },
    { "Extra 2", 0x1880cc0, 0x1880ce0 },
    { "Extra 3", 0x1880ce0, 0x1880d00 },
    { "Extra 4", 0x1880d00, 0x1880d20 },
    { "Extra 5", 0x1880d20, 0x1880d40 },
};

const sGame_PaletteDataset CVS2_A_ZANGIEF_PALETTES_3K[] =
{
    { "Main Sprite", 0x1880d40, 0x1880d60, indexCVS2Sprites_Zangief },
    { "Extra 1", 0x1880d60, 0x1880d80 },
    { "Extra 2", 0x1880d80, 0x1880da0 },
    { "Extra 3", 0x1880da0, 0x1880dc0 },
    { "Extra 4", 0x1880dc0, 0x1880de0 },
    { "Extra 5", 0x1880de0, 0x1880e00 },
};

const sDescTreeNode CVS2_A_ZANGIEF_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_ZANGIEF_PALETTES_LP, ARRAYSIZE(CVS2_A_ZANGIEF_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_ZANGIEF_PALETTES_MP, ARRAYSIZE(CVS2_A_ZANGIEF_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_ZANGIEF_PALETTES_HP, ARRAYSIZE(CVS2_A_ZANGIEF_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_ZANGIEF_PALETTES_LK, ARRAYSIZE(CVS2_A_ZANGIEF_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_ZANGIEF_PALETTES_MK, ARRAYSIZE(CVS2_A_ZANGIEF_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_ZANGIEF_PALETTES_HK, ARRAYSIZE(CVS2_A_ZANGIEF_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_ZANGIEF_PALETTES_3P, ARRAYSIZE(CVS2_A_ZANGIEF_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_ZANGIEF_PALETTES_3K, ARRAYSIZE(CVS2_A_ZANGIEF_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_DHALSIM_PALETTES_LP[] =
{
    { "Main Sprite", 0x19aef60, 0x19aef80, indexCVS2Sprites_Dhalsim },
    { "Extra 1", 0x19aef80, 0x19aefa0 },
    { "Extra 2", 0x19aefa0, 0x19aefc0 },
    { "Extra 3", 0x19aefc0, 0x19aefe0 },
    { "Extra 4", 0x19aefe0, 0x19af000 },
    { "Extra 5", 0x19af000, 0x19af020 },
};

const sGame_PaletteDataset CVS2_A_DHALSIM_PALETTES_MP[] =
{
    { "Main Sprite", 0x19af020, 0x19af040, indexCVS2Sprites_Dhalsim },
    { "Extra 1", 0x19af040, 0x19af060 },
    { "Extra 2", 0x19af060, 0x19af080 },
    { "Extra 3", 0x19af080, 0x19af0a0 },
    { "Extra 4", 0x19af0a0, 0x19af0c0 },
    { "Extra 5", 0x19af0c0, 0x19af0e0 },
};

const sGame_PaletteDataset CVS2_A_DHALSIM_PALETTES_HP[] =
{
    { "Main Sprite", 0x19af0e0, 0x19af100, indexCVS2Sprites_Dhalsim },
    { "Extra 1", 0x19af100, 0x19af120 },
    { "Extra 2", 0x19af120, 0x19af140 },
    { "Extra 3", 0x19af140, 0x19af160 },
    { "Extra 4", 0x19af160, 0x19af180 },
    { "Extra 5", 0x19af180, 0x19af1a0 },
};

const sGame_PaletteDataset CVS2_A_DHALSIM_PALETTES_LK[] =
{
    { "Main Sprite", 0x19af1a0, 0x19af1c0, indexCVS2Sprites_Dhalsim },
    { "Extra 1", 0x19af1c0, 0x19af1e0 },
    { "Extra 2", 0x19af1e0, 0x19af200 },
    { "Extra 3", 0x19af200, 0x19af220 },
    { "Extra 4", 0x19af220, 0x19af240 },
    { "Extra 5", 0x19af240, 0x19af260 },
};

const sGame_PaletteDataset CVS2_A_DHALSIM_PALETTES_MK[] =
{
    { "Main Sprite", 0x19af260, 0x19af280, indexCVS2Sprites_Dhalsim },
    { "Extra 1", 0x19af280, 0x19af2a0 },
    { "Extra 2", 0x19af2a0, 0x19af2c0 },
    { "Extra 3", 0x19af2c0, 0x19af2e0 },
    { "Extra 4", 0x19af2e0, 0x19af300 },
    { "Extra 5", 0x19af300, 0x19af320 },
};

const sGame_PaletteDataset CVS2_A_DHALSIM_PALETTES_HK[] =
{
    { "Main Sprite", 0x19af320, 0x19af340, indexCVS2Sprites_Dhalsim },
    { "Extra 1", 0x19af340, 0x19af360 },
    { "Extra 2", 0x19af360, 0x19af380 },
    { "Extra 3", 0x19af380, 0x19af3a0 },
    { "Extra 4", 0x19af3a0, 0x19af3c0 },
    { "Extra 5", 0x19af3c0, 0x19af3e0 },
};

const sGame_PaletteDataset CVS2_A_DHALSIM_PALETTES_3P[] =
{
    { "Main Sprite", 0x19af3e0, 0x19af400, indexCVS2Sprites_Dhalsim },
    { "Extra 1", 0x19af400, 0x19af420 },
    { "Extra 2", 0x19af420, 0x19af440 },
    { "Extra 3", 0x19af440, 0x19af460 },
    { "Extra 4", 0x19af460, 0x19af480 },
    { "Extra 5", 0x19af480, 0x19af4a0 },
};

const sGame_PaletteDataset CVS2_A_DHALSIM_PALETTES_3K[] =
{
    { "Main Sprite", 0x19af4a0, 0x19af4c0, indexCVS2Sprites_Dhalsim },
    { "Extra 1", 0x19af4c0, 0x19af4e0 },
    { "Extra 2", 0x19af4e0, 0x19af500 },
    { "Extra 3", 0x19af500, 0x19af520 },
    { "Extra 4", 0x19af520, 0x19af540 },
    { "Extra 5", 0x19af540, 0x19af560 },
};

const sDescTreeNode CVS2_A_DHALSIM_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_DHALSIM_PALETTES_LP, ARRAYSIZE(CVS2_A_DHALSIM_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_DHALSIM_PALETTES_MP, ARRAYSIZE(CVS2_A_DHALSIM_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_DHALSIM_PALETTES_HP, ARRAYSIZE(CVS2_A_DHALSIM_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_DHALSIM_PALETTES_LK, ARRAYSIZE(CVS2_A_DHALSIM_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_DHALSIM_PALETTES_MK, ARRAYSIZE(CVS2_A_DHALSIM_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_DHALSIM_PALETTES_HK, ARRAYSIZE(CVS2_A_DHALSIM_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_DHALSIM_PALETTES_3P, ARRAYSIZE(CVS2_A_DHALSIM_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_DHALSIM_PALETTES_3K, ARRAYSIZE(CVS2_A_DHALSIM_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_EHONDA_PALETTES_LP[] =
{
    { "Main Sprite", 0x1a33500, 0x1a33520, indexCVS2Sprites_EHonda },
    { "Extra 1", 0x1a33520, 0x1a33540 },
    { "Extra 2", 0x1a33540, 0x1a33560 },
    { "Extra 3", 0x1a33560, 0x1a33580 },
    { "Extra 4", 0x1a33580, 0x1a335a0 },
    { "Extra 5", 0x1a335a0, 0x1a335c0 },
};

const sGame_PaletteDataset CVS2_A_EHONDA_PALETTES_MP[] =
{
    { "Main Sprite", 0x1a335c0, 0x1a335e0, indexCVS2Sprites_EHonda },
    { "Extra 1", 0x1a335e0, 0x1a33600 },
    { "Extra 2", 0x1a33600, 0x1a33620 },
    { "Extra 3", 0x1a33620, 0x1a33640 },
    { "Extra 4", 0x1a33640, 0x1a33660 },
    { "Extra 5", 0x1a33660, 0x1a33680 },
};

const sGame_PaletteDataset CVS2_A_EHONDA_PALETTES_HP[] =
{
    { "Main Sprite", 0x1a33680, 0x1a336a0, indexCVS2Sprites_EHonda },
    { "Extra 1", 0x1a336a0, 0x1a336c0 },
    { "Extra 2", 0x1a336c0, 0x1a336e0 },
    { "Extra 3", 0x1a336e0, 0x1a33700 },
    { "Extra 4", 0x1a33700, 0x1a33720 },
    { "Extra 5", 0x1a33720, 0x1a33740 },
};

const sGame_PaletteDataset CVS2_A_EHONDA_PALETTES_LK[] =
{
    { "Main Sprite", 0x1a33740, 0x1a33760, indexCVS2Sprites_EHonda },
    { "Extra 1", 0x1a33760, 0x1a33780 },
    { "Extra 2", 0x1a33780, 0x1a337a0 },
    { "Extra 3", 0x1a337a0, 0x1a337c0 },
    { "Extra 4", 0x1a337c0, 0x1a337e0 },
    { "Extra 5", 0x1a337e0, 0x1a33800 },
};

const sGame_PaletteDataset CVS2_A_EHONDA_PALETTES_MK[] =
{
    { "Main Sprite", 0x1a33800, 0x1a33820, indexCVS2Sprites_EHonda },
    { "Extra 1", 0x1a33820, 0x1a33840 },
    { "Extra 2", 0x1a33840, 0x1a33860 },
    { "Extra 3", 0x1a33860, 0x1a33880 },
    { "Extra 4", 0x1a33880, 0x1a338a0 },
    { "Extra 5", 0x1a338a0, 0x1a338c0 },
};

const sGame_PaletteDataset CVS2_A_EHONDA_PALETTES_HK[] =
{
    { "Main Sprite", 0x1a338c0, 0x1a338e0, indexCVS2Sprites_EHonda },
    { "Extra 1", 0x1a338e0, 0x1a33900 },
    { "Extra 2", 0x1a33900, 0x1a33920 },
    { "Extra 3", 0x1a33920, 0x1a33940 },
    { "Extra 4", 0x1a33940, 0x1a33960 },
    { "Extra 5", 0x1a33960, 0x1a33980 },
};

const sGame_PaletteDataset CVS2_A_EHONDA_PALETTES_3P[] =
{
    { "Main Sprite", 0x1a33980, 0x1a339a0, indexCVS2Sprites_EHonda },
    { "Extra 1", 0x1a339a0, 0x1a339c0 },
    { "Extra 2", 0x1a339c0, 0x1a339e0 },
    { "Extra 3", 0x1a339e0, 0x1a33a00 },
    { "Extra 4", 0x1a33a00, 0x1a33a20 },
    { "Extra 5", 0x1a33a20, 0x1a33a40 },
};

const sGame_PaletteDataset CVS2_A_EHONDA_PALETTES_3K[] =
{
    { "Main Sprite", 0x1a33a40, 0x1a33a60, indexCVS2Sprites_EHonda },
    { "Extra 1", 0x1a33a60, 0x1a33a80 },
    { "Extra 2", 0x1a33a80, 0x1a33aa0 },
    { "Extra 3", 0x1a33aa0, 0x1a33ac0 },
    { "Extra 4", 0x1a33ac0, 0x1a33ae0 },
    { "Extra 5", 0x1a33ae0, 0x1a33b00 },
};

const sDescTreeNode CVS2_A_EHONDA_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_EHONDA_PALETTES_LP, ARRAYSIZE(CVS2_A_EHONDA_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_EHONDA_PALETTES_MP, ARRAYSIZE(CVS2_A_EHONDA_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_EHONDA_PALETTES_HP, ARRAYSIZE(CVS2_A_EHONDA_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_EHONDA_PALETTES_LK, ARRAYSIZE(CVS2_A_EHONDA_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_EHONDA_PALETTES_MK, ARRAYSIZE(CVS2_A_EHONDA_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_EHONDA_PALETTES_HK, ARRAYSIZE(CVS2_A_EHONDA_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_EHONDA_PALETTES_3P, ARRAYSIZE(CVS2_A_EHONDA_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_EHONDA_PALETTES_3K, ARRAYSIZE(CVS2_A_EHONDA_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_BLANKA_PALETTES_LP[] =
{
    { "Main Sprite", 0x1b32560, 0x1b32580, indexCVS2Sprites_Blanka },
    { "Extra 1", 0x1b32580, 0x1b325a0 },
    { "Extra 2", 0x1b325a0, 0x1b325c0 },
    { "Extra 3", 0x1b325c0, 0x1b325e0 },
    { "Extra 4", 0x1b325e0, 0x1b32600 },
    { "Extra 5", 0x1b32600, 0x1b32620 },
};

const sGame_PaletteDataset CVS2_A_BLANKA_PALETTES_MP[] =
{
    { "Main Sprite", 0x1b32620, 0x1b32640, indexCVS2Sprites_Blanka },
    { "Extra 1", 0x1b32640, 0x1b32660 },
    { "Extra 2", 0x1b32660, 0x1b32680 },
    { "Extra 3", 0x1b32680, 0x1b326a0 },
    { "Extra 4", 0x1b326a0, 0x1b326c0 },
    { "Extra 5", 0x1b326c0, 0x1b326e0 },
};

const sGame_PaletteDataset CVS2_A_BLANKA_PALETTES_HP[] =
{
    { "Main Sprite", 0x1b326e0, 0x1b32700, indexCVS2Sprites_Blanka },
    { "Extra 1", 0x1b32700, 0x1b32720 },
    { "Extra 2", 0x1b32720, 0x1b32740 },
    { "Extra 3", 0x1b32740, 0x1b32760 },
    { "Extra 4", 0x1b32760, 0x1b32780 },
    { "Extra 5", 0x1b32780, 0x1b327a0 },
};

const sGame_PaletteDataset CVS2_A_BLANKA_PALETTES_LK[] =
{
    { "Main Sprite", 0x1b327a0, 0x1b327c0, indexCVS2Sprites_Blanka },
    { "Extra 1", 0x1b327c0, 0x1b327e0 },
    { "Extra 2", 0x1b327e0, 0x1b32800 },
    { "Extra 3", 0x1b32800, 0x1b32820 },
    { "Extra 4", 0x1b32820, 0x1b32840 },
    { "Extra 5", 0x1b32840, 0x1b32860 },
};

const sGame_PaletteDataset CVS2_A_BLANKA_PALETTES_MK[] =
{
    { "Main Sprite", 0x1b32860, 0x1b32880, indexCVS2Sprites_Blanka },
    { "Extra 1", 0x1b32880, 0x1b328a0 },
    { "Extra 2", 0x1b328a0, 0x1b328c0 },
    { "Extra 3", 0x1b328c0, 0x1b328e0 },
    { "Extra 4", 0x1b328e0, 0x1b32900 },
    { "Extra 5", 0x1b32900, 0x1b32920 },
};

const sGame_PaletteDataset CVS2_A_BLANKA_PALETTES_HK[] =
{
    { "Main Sprite", 0x1b32920, 0x1b32940, indexCVS2Sprites_Blanka },
    { "Extra 1", 0x1b32940, 0x1b32960 },
    { "Extra 2", 0x1b32960, 0x1b32980 },
    { "Extra 3", 0x1b32980, 0x1b329a0 },
    { "Extra 4", 0x1b329a0, 0x1b329c0 },
    { "Extra 5", 0x1b329c0, 0x1b329e0 },
};

const sGame_PaletteDataset CVS2_A_BLANKA_PALETTES_3P[] =
{
    { "Main Sprite", 0x1b329e0, 0x1b32a00, indexCVS2Sprites_Blanka },
    { "Extra 1", 0x1b32a00, 0x1b32a20 },
    { "Extra 2", 0x1b32a20, 0x1b32a40 },
    { "Extra 3", 0x1b32a40, 0x1b32a60 },
    { "Extra 4", 0x1b32a60, 0x1b32a80 },
    { "Extra 5", 0x1b32a80, 0x1b32aa0 },
};

const sGame_PaletteDataset CVS2_A_BLANKA_PALETTES_3K[] =
{
    { "Main Sprite", 0x1b32aa0, 0x1b32ac0, indexCVS2Sprites_Blanka },
    { "Extra 1", 0x1b32ac0, 0x1b32ae0 },
    { "Extra 2", 0x1b32ae0, 0x1b32b00 },
    { "Extra 3", 0x1b32b00, 0x1b32b20 },
    { "Extra 4", 0x1b32b20, 0x1b32b40 },
    { "Extra 5", 0x1b32b40, 0x1b32b60 },
};

const sDescTreeNode CVS2_A_BLANKA_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_BLANKA_PALETTES_LP, ARRAYSIZE(CVS2_A_BLANKA_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_BLANKA_PALETTES_MP, ARRAYSIZE(CVS2_A_BLANKA_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_BLANKA_PALETTES_HP, ARRAYSIZE(CVS2_A_BLANKA_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_BLANKA_PALETTES_LK, ARRAYSIZE(CVS2_A_BLANKA_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_BLANKA_PALETTES_MK, ARRAYSIZE(CVS2_A_BLANKA_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_BLANKA_PALETTES_HK, ARRAYSIZE(CVS2_A_BLANKA_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_BLANKA_PALETTES_3P, ARRAYSIZE(CVS2_A_BLANKA_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_BLANKA_PALETTES_3K, ARRAYSIZE(CVS2_A_BLANKA_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_VEGA_PALETTES_LP[] =
{
    { "Main Sprite", 0x1bfe160, 0x1bfe180, indexCVS2Sprites_Vega },
    { "Extra 1", 0x1bfe180, 0x1bfe1a0 },
    { "Extra 2", 0x1bfe1a0, 0x1bfe1c0 },
    { "Extra 3", 0x1bfe1c0, 0x1bfe1e0 },
    { "Extra 4", 0x1bfe1e0, 0x1bfe200 },
    { "Extra 5", 0x1bfe200, 0x1bfe220 },
};

const sGame_PaletteDataset CVS2_A_VEGA_PALETTES_MP[] =
{
    { "Main Sprite", 0x1bfe220, 0x1bfe240, indexCVS2Sprites_Vega },
    { "Extra 1", 0x1bfe240, 0x1bfe260 },
    { "Extra 2", 0x1bfe260, 0x1bfe280 },
    { "Extra 3", 0x1bfe280, 0x1bfe2a0 },
    { "Extra 4", 0x1bfe2a0, 0x1bfe2c0 },
    { "Extra 5", 0x1bfe2c0, 0x1bfe2e0 },
};

const sGame_PaletteDataset CVS2_A_VEGA_PALETTES_HP[] =
{
    { "Main Sprite", 0x1bfe2e0, 0x1bfe300, indexCVS2Sprites_Vega },
    { "Extra 1", 0x1bfe300, 0x1bfe320 },
    { "Extra 2", 0x1bfe320, 0x1bfe340 },
    { "Extra 3", 0x1bfe340, 0x1bfe360 },
    { "Extra 4", 0x1bfe360, 0x1bfe380 },
    { "Extra 5", 0x1bfe380, 0x1bfe3a0 },
};

const sGame_PaletteDataset CVS2_A_VEGA_PALETTES_LK[] =
{
    { "Main Sprite", 0x1bfe3a0, 0x1bfe3c0, indexCVS2Sprites_Vega },
    { "Extra 1", 0x1bfe3c0, 0x1bfe3e0 },
    { "Extra 2", 0x1bfe3e0, 0x1bfe400 },
    { "Extra 3", 0x1bfe400, 0x1bfe420 },
    { "Extra 4", 0x1bfe420, 0x1bfe440 },
    { "Extra 5", 0x1bfe440, 0x1bfe460 },
};

const sGame_PaletteDataset CVS2_A_VEGA_PALETTES_MK[] =
{
    { "Main Sprite", 0x1bfe460, 0x1bfe480, indexCVS2Sprites_Vega },
    { "Extra 1", 0x1bfe480, 0x1bfe4a0 },
    { "Extra 2", 0x1bfe4a0, 0x1bfe4c0 },
    { "Extra 3", 0x1bfe4c0, 0x1bfe4e0 },
    { "Extra 4", 0x1bfe4e0, 0x1bfe500 },
    { "Extra 5", 0x1bfe500, 0x1bfe520 },
};

const sGame_PaletteDataset CVS2_A_VEGA_PALETTES_HK[] =
{
    { "Main Sprite", 0x1bfe520, 0x1bfe540, indexCVS2Sprites_Vega },
    { "Extra 1", 0x1bfe540, 0x1bfe560 },
    { "Extra 2", 0x1bfe560, 0x1bfe580 },
    { "Extra 3", 0x1bfe580, 0x1bfe5a0 },
    { "Extra 4", 0x1bfe5a0, 0x1bfe5c0 },
    { "Extra 5", 0x1bfe5c0, 0x1bfe5e0 },
};

const sGame_PaletteDataset CVS2_A_VEGA_PALETTES_3P[] =
{
    { "Main Sprite", 0x1bfe5e0, 0x1bfe600, indexCVS2Sprites_Vega },
    { "Extra 1", 0x1bfe600, 0x1bfe620 },
    { "Extra 2", 0x1bfe620, 0x1bfe640 },
    { "Extra 3", 0x1bfe640, 0x1bfe660 },
    { "Extra 4", 0x1bfe660, 0x1bfe680 },
    { "Extra 5", 0x1bfe680, 0x1bfe6a0 },
};

const sGame_PaletteDataset CVS2_A_VEGA_PALETTES_3K[] =
{
    { "Main Sprite", 0x1bfe6a0, 0x1bfe6c0, indexCVS2Sprites_Vega },
    { "Extra 1", 0x1bfe6c0, 0x1bfe6e0 },
    { "Extra 2", 0x1bfe6e0, 0x1bfe700 },
    { "Extra 3", 0x1bfe700, 0x1bfe720 },
    { "Extra 4", 0x1bfe720, 0x1bfe740 },
    { "Extra 5", 0x1bfe740, 0x1bfe760 },
};

const sDescTreeNode CVS2_A_VEGA_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_VEGA_PALETTES_LP, ARRAYSIZE(CVS2_A_VEGA_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_VEGA_PALETTES_MP, ARRAYSIZE(CVS2_A_VEGA_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_VEGA_PALETTES_HP, ARRAYSIZE(CVS2_A_VEGA_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_VEGA_PALETTES_LK, ARRAYSIZE(CVS2_A_VEGA_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_VEGA_PALETTES_MK, ARRAYSIZE(CVS2_A_VEGA_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_VEGA_PALETTES_HK, ARRAYSIZE(CVS2_A_VEGA_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_VEGA_PALETTES_3P, ARRAYSIZE(CVS2_A_VEGA_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_VEGA_PALETTES_3K, ARRAYSIZE(CVS2_A_VEGA_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_SAGAT_PALETTES_LP[] =
{
    { "Main Sprite", 0x1c9b720, 0x1c9b740, indexCVS2Sprites_Sagat },
    { "Extra 1", 0x1c9b740, 0x1c9b760 },
    { "Extra 2", 0x1c9b760, 0x1c9b780 },
    { "Extra 3", 0x1c9b780, 0x1c9b7a0 },
    { "Extra 4", 0x1c9b7a0, 0x1c9b7c0 },
    { "Extra 5", 0x1c9b7c0, 0x1c9b7e0 },
};

const sGame_PaletteDataset CVS2_A_SAGAT_PALETTES_MP[] =
{
    { "Main Sprite", 0x1c9b7e0, 0x1c9b800, indexCVS2Sprites_Sagat },
    { "Extra 1", 0x1c9b800, 0x1c9b820 },
    { "Extra 2", 0x1c9b820, 0x1c9b840 },
    { "Extra 3", 0x1c9b840, 0x1c9b860 },
    { "Extra 4", 0x1c9b860, 0x1c9b880 },
    { "Extra 5", 0x1c9b880, 0x1c9b8a0 },
};

const sGame_PaletteDataset CVS2_A_SAGAT_PALETTES_HP[] =
{
    { "Main Sprite", 0x1c9b8a0, 0x1c9b8c0, indexCVS2Sprites_Sagat },
    { "Extra 1", 0x1c9b8c0, 0x1c9b8e0 },
    { "Extra 2", 0x1c9b8e0, 0x1c9b900 },
    { "Extra 3", 0x1c9b900, 0x1c9b920 },
    { "Extra 4", 0x1c9b920, 0x1c9b940 },
    { "Extra 5", 0x1c9b940, 0x1c9b960 },
};

const sGame_PaletteDataset CVS2_A_SAGAT_PALETTES_LK[] =
{
    { "Main Sprite", 0x1c9b960, 0x1c9b980, indexCVS2Sprites_Sagat },
    { "Extra 1", 0x1c9b980, 0x1c9b9a0 },
    { "Extra 2", 0x1c9b9a0, 0x1c9b9c0 },
    { "Extra 3", 0x1c9b9c0, 0x1c9b9e0 },
    { "Extra 4", 0x1c9b9e0, 0x1c9ba00 },
    { "Extra 5", 0x1c9ba00, 0x1c9ba20 },
};

const sGame_PaletteDataset CVS2_A_SAGAT_PALETTES_MK[] =
{
    { "Main Sprite", 0x1c9ba20, 0x1c9ba40, indexCVS2Sprites_Sagat },
    { "Extra 1", 0x1c9ba40, 0x1c9ba60 },
    { "Extra 2", 0x1c9ba60, 0x1c9ba80 },
    { "Extra 3", 0x1c9ba80, 0x1c9baa0 },
    { "Extra 4", 0x1c9baa0, 0x1c9bac0 },
    { "Extra 5", 0x1c9bac0, 0x1c9bae0 },
};

const sGame_PaletteDataset CVS2_A_SAGAT_PALETTES_HK[] =
{
    { "Main Sprite", 0x1c9bae0, 0x1c9bb00, indexCVS2Sprites_Sagat },
    { "Extra 1", 0x1c9bb00, 0x1c9bb20 },
    { "Extra 2", 0x1c9bb20, 0x1c9bb40 },
    { "Extra 3", 0x1c9bb40, 0x1c9bb60 },
    { "Extra 4", 0x1c9bb60, 0x1c9bb80 },
    { "Extra 5", 0x1c9bb80, 0x1c9bba0 },
};

const sGame_PaletteDataset CVS2_A_SAGAT_PALETTES_3P[] =
{
    { "Main Sprite", 0x1c9bba0, 0x1c9bbc0, indexCVS2Sprites_Sagat },
    { "Extra 1", 0x1c9bbc0, 0x1c9bbe0 },
    { "Extra 2", 0x1c9bbe0, 0x1c9bc00 },
    { "Extra 3", 0x1c9bc00, 0x1c9bc20 },
    { "Extra 4", 0x1c9bc20, 0x1c9bc40 },
    { "Extra 5", 0x1c9bc40, 0x1c9bc60 },
};

const sGame_PaletteDataset CVS2_A_SAGAT_PALETTES_3K[] =
{
    { "Main Sprite", 0x1c9bc60, 0x1c9bc80, indexCVS2Sprites_Sagat },
    { "Extra 1", 0x1c9bc80, 0x1c9bca0 },
    { "Extra 2", 0x1c9bca0, 0x1c9bcc0 },
    { "Extra 3", 0x1c9bcc0, 0x1c9bce0 },
    { "Extra 4", 0x1c9bce0, 0x1c9bd00 },
    { "Extra 5", 0x1c9bd00, 0x1c9bd20 },
};

const sDescTreeNode CVS2_A_SAGAT_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_SAGAT_PALETTES_LP, ARRAYSIZE(CVS2_A_SAGAT_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_SAGAT_PALETTES_MP, ARRAYSIZE(CVS2_A_SAGAT_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_SAGAT_PALETTES_HP, ARRAYSIZE(CVS2_A_SAGAT_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_SAGAT_PALETTES_LK, ARRAYSIZE(CVS2_A_SAGAT_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_SAGAT_PALETTES_MK, ARRAYSIZE(CVS2_A_SAGAT_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_SAGAT_PALETTES_HK, ARRAYSIZE(CVS2_A_SAGAT_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_SAGAT_PALETTES_3P, ARRAYSIZE(CVS2_A_SAGAT_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_SAGAT_PALETTES_3K, ARRAYSIZE(CVS2_A_SAGAT_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_BISON_PALETTES_LP[] =
{
    { "Main Sprite", 0x1d71a60, 0x1d71a80, indexCVS2Sprites_MBison },
    { "Extra 1", 0x1d71a80, 0x1d71aa0 },
    { "Extra 2", 0x1d71aa0, 0x1d71ac0 },
    { "Extra 3", 0x1d71ac0, 0x1d71ae0 },
    { "Extra 4", 0x1d71ae0, 0x1d71b00 },
    { "Extra 5", 0x1d71b00, 0x1d71b20 },
};

const sGame_PaletteDataset CVS2_A_BISON_PALETTES_MP[] =
{
    { "Main Sprite", 0x1d71b20, 0x1d71b40, indexCVS2Sprites_MBison },
    { "Extra 1", 0x1d71b40, 0x1d71b60 },
    { "Extra 2", 0x1d71b60, 0x1d71b80 },
    { "Extra 3", 0x1d71b80, 0x1d71ba0 },
    { "Extra 4", 0x1d71ba0, 0x1d71bc0 },
    { "Extra 5", 0x1d71bc0, 0x1d71be0 },
};

const sGame_PaletteDataset CVS2_A_BISON_PALETTES_HP[] =
{
    { "Main Sprite", 0x1d71be0, 0x1d71c00, indexCVS2Sprites_MBison },
    { "Extra 1", 0x1d71c00, 0x1d71c20 },
    { "Extra 2", 0x1d71c20, 0x1d71c40 },
    { "Extra 3", 0x1d71c40, 0x1d71c60 },
    { "Extra 4", 0x1d71c60, 0x1d71c80 },
    { "Extra 5", 0x1d71c80, 0x1d71ca0 },
};

const sGame_PaletteDataset CVS2_A_BISON_PALETTES_LK[] =
{
    { "Main Sprite", 0x1d71ca0, 0x1d71cc0, indexCVS2Sprites_MBison },
    { "Extra 1", 0x1d71cc0, 0x1d71ce0 },
    { "Extra 2", 0x1d71ce0, 0x1d71d00 },
    { "Extra 3", 0x1d71d00, 0x1d71d20 },
    { "Extra 4", 0x1d71d20, 0x1d71d40 },
    { "Extra 5", 0x1d71d40, 0x1d71d60 },
};

const sGame_PaletteDataset CVS2_A_BISON_PALETTES_MK[] =
{
    { "Main Sprite", 0x1d71d60, 0x1d71d80, indexCVS2Sprites_MBison },
    { "Extra 1", 0x1d71d80, 0x1d71da0 },
    { "Extra 2", 0x1d71da0, 0x1d71dc0 },
    { "Extra 3", 0x1d71dc0, 0x1d71de0 },
    { "Extra 4", 0x1d71de0, 0x1d71e00 },
    { "Extra 5", 0x1d71e00, 0x1d71e20 },
};

const sGame_PaletteDataset CVS2_A_BISON_PALETTES_HK[] =
{
    { "Main Sprite", 0x1d71e20, 0x1d71e40, indexCVS2Sprites_MBison },
    { "Extra 1", 0x1d71e40, 0x1d71e60 },
    { "Extra 2", 0x1d71e60, 0x1d71e80 },
    { "Extra 3", 0x1d71e80, 0x1d71ea0 },
    { "Extra 4", 0x1d71ea0, 0x1d71ec0 },
    { "Extra 5", 0x1d71ec0, 0x1d71ee0 },
};

const sGame_PaletteDataset CVS2_A_BISON_PALETTES_3P[] =
{
    { "Main Sprite", 0x1d71ee0, 0x1d71f00, indexCVS2Sprites_MBison },
    { "Extra 1", 0x1d71f00, 0x1d71f20 },
    { "Extra 2", 0x1d71f20, 0x1d71f40 },
    { "Extra 3", 0x1d71f40, 0x1d71f60 },
    { "Extra 4", 0x1d71f60, 0x1d71f80 },
    { "Extra 5", 0x1d71f80, 0x1d71fa0 },
};

const sGame_PaletteDataset CVS2_A_BISON_PALETTES_3K[] =
{
    { "Main Sprite", 0x1d71fa0, 0x1d71fc0, indexCVS2Sprites_MBison },
    { "Extra 1", 0x1d71fc0, 0x1d71fe0 },
    { "Extra 2", 0x1d71fe0, 0x1d72000 },
    { "Extra 3", 0x1d72000, 0x1d72020 },
    { "Extra 4", 0x1d72020, 0x1d72040 },
    { "Extra 5", 0x1d72040, 0x1d72060 },
};

const sDescTreeNode CVS2_A_BISON_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_BISON_PALETTES_LP, ARRAYSIZE(CVS2_A_BISON_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_BISON_PALETTES_MP, ARRAYSIZE(CVS2_A_BISON_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_BISON_PALETTES_HP, ARRAYSIZE(CVS2_A_BISON_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_BISON_PALETTES_LK, ARRAYSIZE(CVS2_A_BISON_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_BISON_PALETTES_MK, ARRAYSIZE(CVS2_A_BISON_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_BISON_PALETTES_HK, ARRAYSIZE(CVS2_A_BISON_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_BISON_PALETTES_3P, ARRAYSIZE(CVS2_A_BISON_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_BISON_PALETTES_3K, ARRAYSIZE(CVS2_A_BISON_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_SAKURA_PALETTES_LP[] =
{
    { "Main Sprite", 0x1e961a0, 0x1e961c0, indexCVS2Sprites_Sakura },
    { "Extra 1", 0x1e961c0, 0x1e961e0 },
    { "Extra 2", 0x1e961e0, 0x1e96200 },
    { "Extra 3", 0x1e96200, 0x1e96220 },
    { "Extra 4", 0x1e96220, 0x1e96240 },
    { "Extra 5", 0x1e96240, 0x1e96260 },
};

const sGame_PaletteDataset CVS2_A_SAKURA_PALETTES_MP[] =
{
    { "Main Sprite", 0x1e96260, 0x1e96280, indexCVS2Sprites_Sakura },
    { "Extra 1", 0x1e96280, 0x1e962a0 },
    { "Extra 2", 0x1e962a0, 0x1e962c0 },
    { "Extra 3", 0x1e962c0, 0x1e962e0 },
    { "Extra 4", 0x1e962e0, 0x1e96300 },
    { "Extra 5", 0x1e96300, 0x1e96320 },
};

const sGame_PaletteDataset CVS2_A_SAKURA_PALETTES_HP[] =
{
    { "Main Sprite", 0x1e96320, 0x1e96340, indexCVS2Sprites_Sakura },
    { "Extra 1", 0x1e96340, 0x1e96360 },
    { "Extra 2", 0x1e96360, 0x1e96380 },
    { "Extra 3", 0x1e96380, 0x1e963a0 },
    { "Extra 4", 0x1e963a0, 0x1e963c0 },
    { "Extra 5", 0x1e963c0, 0x1e963e0 },
};

const sGame_PaletteDataset CVS2_A_SAKURA_PALETTES_LK[] =
{
    { "Main Sprite", 0x1e963e0, 0x1e96400, indexCVS2Sprites_Sakura },
    { "Extra 1", 0x1e96400, 0x1e96420 },
    { "Extra 2", 0x1e96420, 0x1e96440 },
    { "Extra 3", 0x1e96440, 0x1e96460 },
    { "Extra 4", 0x1e96460, 0x1e96480 },
    { "Extra 5", 0x1e96480, 0x1e964a0 },
};

const sGame_PaletteDataset CVS2_A_SAKURA_PALETTES_MK[] =
{
    { "Main Sprite", 0x1e964a0, 0x1e964c0, indexCVS2Sprites_Sakura },
    { "Extra 1", 0x1e964c0, 0x1e964e0 },
    { "Extra 2", 0x1e964e0, 0x1e96500 },
    { "Extra 3", 0x1e96500, 0x1e96520 },
    { "Extra 4", 0x1e96520, 0x1e96540 },
    { "Extra 5", 0x1e96540, 0x1e96560 },
};

const sGame_PaletteDataset CVS2_A_SAKURA_PALETTES_HK[] =
{
    { "Main Sprite", 0x1e96560, 0x1e96580, indexCVS2Sprites_Sakura },
    { "Extra 1", 0x1e96580, 0x1e965a0 },
    { "Extra 2", 0x1e965a0, 0x1e965c0 },
    { "Extra 3", 0x1e965c0, 0x1e965e0 },
    { "Extra 4", 0x1e965e0, 0x1e96600 },
    { "Extra 5", 0x1e96600, 0x1e96620 },
};

const sGame_PaletteDataset CVS2_A_SAKURA_PALETTES_3P[] =
{
    { "Main Sprite", 0x1e96620, 0x1e96640, indexCVS2Sprites_Sakura },
    { "Extra 1", 0x1e96640, 0x1e96660 },
    { "Extra 2", 0x1e96660, 0x1e96680 },
    { "Extra 3", 0x1e96680, 0x1e966a0 },
    { "Extra 4", 0x1e966a0, 0x1e966c0 },
    { "Extra 5", 0x1e966c0, 0x1e966e0 },
};

const sGame_PaletteDataset CVS2_A_SAKURA_PALETTES_3K[] =
{
    { "Main Sprite", 0x1e966e0, 0x1e96700, indexCVS2Sprites_Sakura },
    { "Extra 1", 0x1e96700, 0x1e96720 },
    { "Extra 2", 0x1e96720, 0x1e96740 },
    { "Extra 3", 0x1e96740, 0x1e96760 },
    { "Extra 4", 0x1e96760, 0x1e96780 },
    { "Extra 5", 0x1e96780, 0x1e967a0 },
};

const sDescTreeNode CVS2_A_SAKURA_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_SAKURA_PALETTES_LP, ARRAYSIZE(CVS2_A_SAKURA_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_SAKURA_PALETTES_MP, ARRAYSIZE(CVS2_A_SAKURA_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_SAKURA_PALETTES_HP, ARRAYSIZE(CVS2_A_SAKURA_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_SAKURA_PALETTES_LK, ARRAYSIZE(CVS2_A_SAKURA_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_SAKURA_PALETTES_MK, ARRAYSIZE(CVS2_A_SAKURA_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_SAKURA_PALETTES_HK, ARRAYSIZE(CVS2_A_SAKURA_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_SAKURA_PALETTES_3P, ARRAYSIZE(CVS2_A_SAKURA_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_SAKURA_PALETTES_3K, ARRAYSIZE(CVS2_A_SAKURA_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_CAMMY_PALETTES_LP[] =
{
    { "Main Sprite", 0x1f6fc60, 0x1f6fc80, indexCVS2Sprites_Cammy },
    { "Extra 1", 0x1f6fc80, 0x1f6fca0 },
    { "Extra 2", 0x1f6fca0, 0x1f6fcc0 },
    { "Extra 3", 0x1f6fcc0, 0x1f6fce0 },
    { "Extra 4", 0x1f6fce0, 0x1f6fd00 },
    { "Extra 5", 0x1f6fd00, 0x1f6fd20 },
};

const sGame_PaletteDataset CVS2_A_CAMMY_PALETTES_MP[] =
{
    { "Main Sprite", 0x1f6fd20, 0x1f6fd40, indexCVS2Sprites_Cammy },
    { "Extra 1", 0x1f6fd40, 0x1f6fd60 },
    { "Extra 2", 0x1f6fd60, 0x1f6fd80 },
    { "Extra 3", 0x1f6fd80, 0x1f6fda0 },
    { "Extra 4", 0x1f6fda0, 0x1f6fdc0 },
    { "Extra 5", 0x1f6fdc0, 0x1f6fde0 },
};

const sGame_PaletteDataset CVS2_A_CAMMY_PALETTES_HP[] =
{
    { "Main Sprite", 0x1f6fde0, 0x1f6fe00, indexCVS2Sprites_Cammy },
    { "Extra 1", 0x1f6fe00, 0x1f6fe20 },
    { "Extra 2", 0x1f6fe20, 0x1f6fe40 },
    { "Extra 3", 0x1f6fe40, 0x1f6fe60 },
    { "Extra 4", 0x1f6fe60, 0x1f6fe80 },
    { "Extra 5", 0x1f6fe80, 0x1f6fea0 },
};

const sGame_PaletteDataset CVS2_A_CAMMY_PALETTES_LK[] =
{
    { "Main Sprite", 0x1f6fea0, 0x1f6fec0, indexCVS2Sprites_Cammy },
    { "Extra 1", 0x1f6fec0, 0x1f6fee0 },
    { "Extra 2", 0x1f6fee0, 0x1f6ff00 },
    { "Extra 3", 0x1f6ff00, 0x1f6ff20 },
    { "Extra 4", 0x1f6ff20, 0x1f6ff40 },
    { "Extra 5", 0x1f6ff40, 0x1f6ff60 },
};

const sGame_PaletteDataset CVS2_A_CAMMY_PALETTES_MK[] =
{
    { "Main Sprite", 0x1f6ff60, 0x1f6ff80, indexCVS2Sprites_Cammy },
    { "Extra 1", 0x1f6ff80, 0x1f6ffa0 },
    { "Extra 2", 0x1f6ffa0, 0x1f6ffc0 },
    { "Extra 3", 0x1f6ffc0, 0x1f6ffe0 },
    { "Extra 4", 0x1f6ffe0, 0x1f70000 },
    { "Extra 5", 0x1f70000, 0x1f70020 },
};

const sGame_PaletteDataset CVS2_A_CAMMY_PALETTES_HK[] =
{
    { "Main Sprite", 0x1f70020, 0x1f70040, indexCVS2Sprites_Cammy },
    { "Extra 1", 0x1f70040, 0x1f70060 },
    { "Extra 2", 0x1f70060, 0x1f70080 },
    { "Extra 3", 0x1f70080, 0x1f700a0 },
    { "Extra 4", 0x1f700a0, 0x1f700c0 },
    { "Extra 5", 0x1f700c0, 0x1f700e0 },
};

const sGame_PaletteDataset CVS2_A_CAMMY_PALETTES_3P[] =
{
    { "Main Sprite", 0x1f700e0, 0x1f70100, indexCVS2Sprites_Cammy },
    { "Extra 1", 0x1f70100, 0x1f70120 },
    { "Extra 2", 0x1f70120, 0x1f70140 },
    { "Extra 3", 0x1f70140, 0x1f70160 },
    { "Extra 4", 0x1f70160, 0x1f70180 },
    { "Extra 5", 0x1f70180, 0x1f701a0 },
};

const sGame_PaletteDataset CVS2_A_CAMMY_PALETTES_3K[] =
{
    { "Main Sprite", 0x1f701a0, 0x1f701c0, indexCVS2Sprites_Cammy },
    { "Extra 1", 0x1f701c0, 0x1f701e0 },
    { "Extra 2", 0x1f701e0, 0x1f70200 },
    { "Extra 3", 0x1f70200, 0x1f70220 },
    { "Extra 4", 0x1f70220, 0x1f70240 },
    { "Extra 5", 0x1f70240, 0x1f70260 },
};

const sDescTreeNode CVS2_A_CAMMY_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_CAMMY_PALETTES_LP, ARRAYSIZE(CVS2_A_CAMMY_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_CAMMY_PALETTES_MP, ARRAYSIZE(CVS2_A_CAMMY_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_CAMMY_PALETTES_HP, ARRAYSIZE(CVS2_A_CAMMY_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_CAMMY_PALETTES_LK, ARRAYSIZE(CVS2_A_CAMMY_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_CAMMY_PALETTES_MK, ARRAYSIZE(CVS2_A_CAMMY_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_CAMMY_PALETTES_HK, ARRAYSIZE(CVS2_A_CAMMY_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_CAMMY_PALETTES_3P, ARRAYSIZE(CVS2_A_CAMMY_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_CAMMY_PALETTES_3K, ARRAYSIZE(CVS2_A_CAMMY_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_AKUMA_PALETTES_LP[] =
{
    { "Main Sprite", 0x20759c0, 0x20759e0, indexCVS2Sprites_Akuma },
    { "Extra 1", 0x20759e0, 0x2075a00 },
    { "Extra 2", 0x2075a00, 0x2075a20 },
    { "Extra 3", 0x2075a20, 0x2075a40 },
    { "Extra 4", 0x2075a40, 0x2075a60 },
    { "Extra 5", 0x2075a60, 0x2075a80 },
};

const sGame_PaletteDataset CVS2_A_AKUMA_PALETTES_MP[] =
{
    { "Main Sprite", 0x2075a80, 0x2075aa0, indexCVS2Sprites_Akuma },
    { "Extra 1", 0x2075aa0, 0x2075ac0 },
    { "Extra 2", 0x2075ac0, 0x2075ae0 },
    { "Extra 3", 0x2075ae0, 0x2075b00 },
    { "Extra 4", 0x2075b00, 0x2075b20 },
    { "Extra 5", 0x2075b20, 0x2075b40 },
};

const sGame_PaletteDataset CVS2_A_AKUMA_PALETTES_HP[] =
{
    { "Main Sprite", 0x2075b40, 0x2075b60, indexCVS2Sprites_Akuma },
    { "Extra 1", 0x2075b60, 0x2075b80 },
    { "Extra 2", 0x2075b80, 0x2075ba0 },
    { "Extra 3", 0x2075ba0, 0x2075bc0 },
    { "Extra 4", 0x2075bc0, 0x2075be0 },
    { "Extra 5", 0x2075be0, 0x2075c00 },
};

const sGame_PaletteDataset CVS2_A_AKUMA_PALETTES_LK[] =
{
    { "Main Sprite", 0x2075c00, 0x2075c20, indexCVS2Sprites_Akuma },
    { "Extra 1", 0x2075c20, 0x2075c40 },
    { "Extra 2", 0x2075c40, 0x2075c60 },
    { "Extra 3", 0x2075c60, 0x2075c80 },
    { "Extra 4", 0x2075c80, 0x2075ca0 },
    { "Extra 5", 0x2075ca0, 0x2075cc0 },
};

const sGame_PaletteDataset CVS2_A_AKUMA_PALETTES_MK[] =
{
    { "Main Sprite", 0x2075cc0, 0x2075ce0, indexCVS2Sprites_Akuma },
    { "Extra 1", 0x2075ce0, 0x2075d00 },
    { "Extra 2", 0x2075d00, 0x2075d20 },
    { "Extra 3", 0x2075d20, 0x2075d40 },
    { "Extra 4", 0x2075d40, 0x2075d60 },
    { "Extra 5", 0x2075d60, 0x2075d80 },
};

const sGame_PaletteDataset CVS2_A_AKUMA_PALETTES_HK[] =
{
    { "Main Sprite", 0x2075d80, 0x2075da0, indexCVS2Sprites_Akuma },
    { "Extra 1", 0x2075da0, 0x2075dc0 },
    { "Extra 2", 0x2075dc0, 0x2075de0 },
    { "Extra 3", 0x2075de0, 0x2075e00 },
    { "Extra 4", 0x2075e00, 0x2075e20 },
    { "Extra 5", 0x2075e20, 0x2075e40 },
};

const sGame_PaletteDataset CVS2_A_AKUMA_PALETTES_3P[] =
{
    { "Main Sprite", 0x2075e40, 0x2075e60, indexCVS2Sprites_Akuma },
    { "Extra 1", 0x2075e60, 0x2075e80 },
    { "Extra 2", 0x2075e80, 0x2075ea0 },
    { "Extra 3", 0x2075ea0, 0x2075ec0 },
    { "Extra 4", 0x2075ec0, 0x2075ee0 },
    { "Extra 5", 0x2075ee0, 0x2075f00 },
};

const sGame_PaletteDataset CVS2_A_AKUMA_PALETTES_3K[] =
{
    { "Main Sprite", 0x2075f00, 0x2075f20, indexCVS2Sprites_Akuma },
    { "Extra 1", 0x2075f20, 0x2075f40 },
    { "Extra 2", 0x2075f40, 0x2075f60 },
    { "Extra 3", 0x2075f60, 0x2075f80 },
    { "Extra 4", 0x2075f80, 0x2075fa0 },
    { "Extra 5", 0x2075fa0, 0x2075fc0 },
};

const sDescTreeNode CVS2_A_AKUMA_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_AKUMA_PALETTES_LP, ARRAYSIZE(CVS2_A_AKUMA_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_AKUMA_PALETTES_MP, ARRAYSIZE(CVS2_A_AKUMA_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_AKUMA_PALETTES_HP, ARRAYSIZE(CVS2_A_AKUMA_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_AKUMA_PALETTES_LK, ARRAYSIZE(CVS2_A_AKUMA_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_AKUMA_PALETTES_MK, ARRAYSIZE(CVS2_A_AKUMA_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_AKUMA_PALETTES_HK, ARRAYSIZE(CVS2_A_AKUMA_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_AKUMA_PALETTES_3P, ARRAYSIZE(CVS2_A_AKUMA_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_AKUMA_PALETTES_3K, ARRAYSIZE(CVS2_A_AKUMA_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_MORRIGAN_PALETTES_LP[] =
{
    { "Main Sprite", 0x21ad920, 0x21ad940, indexCVS2Sprites_Morrigan },
    { "Extra 1", 0x21ad940, 0x21ad960 },
    { "Extra 2", 0x21ad960, 0x21ad980 },
    { "Extra 3", 0x21ad980, 0x21ad9a0 },
    { "Extra 4", 0x21ad9a0, 0x21ad9c0 },
    { "Extra 5", 0x21ad9c0, 0x21ad9e0 },
};

const sGame_PaletteDataset CVS2_A_MORRIGAN_PALETTES_MP[] =
{
    { "Main Sprite", 0x21ad9e0, 0x21ada00, indexCVS2Sprites_Morrigan },
    { "Extra 1", 0x21ada00, 0x21ada20 },
    { "Extra 2", 0x21ada20, 0x21ada40 },
    { "Extra 3", 0x21ada40, 0x21ada60 },
    { "Extra 4", 0x21ada60, 0x21ada80 },
    { "Extra 5", 0x21ada80, 0x21adaa0 },
};

const sGame_PaletteDataset CVS2_A_MORRIGAN_PALETTES_HP[] =
{
    { "Main Sprite", 0x21adaa0, 0x21adac0, indexCVS2Sprites_Morrigan },
    { "Extra 1", 0x21adac0, 0x21adae0 },
    { "Extra 2", 0x21adae0, 0x21adb00 },
    { "Extra 3", 0x21adb00, 0x21adb20 },
    { "Extra 4", 0x21adb20, 0x21adb40 },
    { "Extra 5", 0x21adb40, 0x21adb60 },
};

const sGame_PaletteDataset CVS2_A_MORRIGAN_PALETTES_LK[] =
{
    { "Main Sprite", 0x21adb60, 0x21adb80, indexCVS2Sprites_Morrigan },
    { "Extra 1", 0x21adb80, 0x21adba0 },
    { "Extra 2", 0x21adba0, 0x21adbc0 },
    { "Extra 3", 0x21adbc0, 0x21adbe0 },
    { "Extra 4", 0x21adbe0, 0x21adc00 },
    { "Extra 5", 0x21adc00, 0x21adc20 },
};

const sGame_PaletteDataset CVS2_A_MORRIGAN_PALETTES_MK[] =
{
    { "Main Sprite", 0x21adc20, 0x21adc40, indexCVS2Sprites_Morrigan },
    { "Extra 1", 0x21adc40, 0x21adc60 },
    { "Extra 2", 0x21adc60, 0x21adc80 },
    { "Extra 3", 0x21adc80, 0x21adca0 },
    { "Extra 4", 0x21adca0, 0x21adcc0 },
    { "Extra 5", 0x21adcc0, 0x21adce0 },
};

const sGame_PaletteDataset CVS2_A_MORRIGAN_PALETTES_HK[] =
{
    { "Main Sprite", 0x21adce0, 0x21add00, indexCVS2Sprites_Morrigan },
    { "Extra 1", 0x21add00, 0x21add20 },
    { "Extra 2", 0x21add20, 0x21add40 },
    { "Extra 3", 0x21add40, 0x21add60 },
    { "Extra 4", 0x21add60, 0x21add80 },
    { "Extra 5", 0x21add80, 0x21adda0 },
};

const sGame_PaletteDataset CVS2_A_MORRIGAN_PALETTES_3P[] =
{
    { "Main Sprite", 0x21adda0, 0x21addc0, indexCVS2Sprites_Morrigan },
    { "Extra 1", 0x21addc0, 0x21adde0 },
    { "Extra 2", 0x21adde0, 0x21ade00 },
    { "Extra 3", 0x21ade00, 0x21ade20 },
    { "Extra 4", 0x21ade20, 0x21ade40 },
    { "Extra 5", 0x21ade40, 0x21ade60 },
};

const sGame_PaletteDataset CVS2_A_MORRIGAN_PALETTES_3K[] =
{
    { "Main Sprite", 0x21ade60, 0x21ade80, indexCVS2Sprites_Morrigan },
    { "Extra 1", 0x21ade80, 0x21adea0 },
    { "Extra 2", 0x21adea0, 0x21adec0 },
    { "Extra 3", 0x21adec0, 0x21adee0 },
    { "Extra 4", 0x21adee0, 0x21adf00 },
    { "Extra 5", 0x21adf00, 0x21adf20 },
};

const sDescTreeNode CVS2_A_MORRIGAN_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_MORRIGAN_PALETTES_LP, ARRAYSIZE(CVS2_A_MORRIGAN_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_MORRIGAN_PALETTES_MP, ARRAYSIZE(CVS2_A_MORRIGAN_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_MORRIGAN_PALETTES_HP, ARRAYSIZE(CVS2_A_MORRIGAN_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_MORRIGAN_PALETTES_LK, ARRAYSIZE(CVS2_A_MORRIGAN_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_MORRIGAN_PALETTES_MK, ARRAYSIZE(CVS2_A_MORRIGAN_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_MORRIGAN_PALETTES_HK, ARRAYSIZE(CVS2_A_MORRIGAN_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_MORRIGAN_PALETTES_3P, ARRAYSIZE(CVS2_A_MORRIGAN_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_MORRIGAN_PALETTES_3K, ARRAYSIZE(CVS2_A_MORRIGAN_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_EVILRYU_PALETTES_LP[] =
{
    { "Main Sprite", 0x22a4800, 0x22a4820, indexCVS2Sprites_EvilRyu },
    { "Extra 1", 0x22a4820, 0x22a4840 },
    { "Extra 2", 0x22a4840, 0x22a4860 },
    { "Extra 3", 0x22a4860, 0x22a4880 },
    { "Extra 4", 0x22a4880, 0x22a48a0 },
    { "Extra 5", 0x22a48a0, 0x22a48c0 },
};

const sGame_PaletteDataset CVS2_A_EVILRYU_PALETTES_MP[] =
{
    { "Main Sprite", 0x22a48c0, 0x22a48e0, indexCVS2Sprites_EvilRyu },
    { "Extra 1", 0x22a48e0, 0x22a4900 },
    { "Extra 2", 0x22a4900, 0x22a4920 },
    { "Extra 3", 0x22a4920, 0x22a4940 },
    { "Extra 4", 0x22a4940, 0x22a4960 },
    { "Extra 5", 0x22a4960, 0x22a4980 },
};

const sGame_PaletteDataset CVS2_A_EVILRYU_PALETTES_HP[] =
{
    { "Main Sprite", 0x22a4980, 0x22a49a0, indexCVS2Sprites_EvilRyu },
    { "Extra 1", 0x22a49a0, 0x22a49c0 },
    { "Extra 2", 0x22a49c0, 0x22a49e0 },
    { "Extra 3", 0x22a49e0, 0x22a4a00 },
    { "Extra 4", 0x22a4a00, 0x22a4a20 },
    { "Extra 5", 0x22a4a20, 0x22a4a40 },
};

const sGame_PaletteDataset CVS2_A_EVILRYU_PALETTES_LK[] =
{
    { "Main Sprite", 0x22a4a40, 0x22a4a60, indexCVS2Sprites_EvilRyu },
    { "Extra 1", 0x22a4a60, 0x22a4a80 },
    { "Extra 2", 0x22a4a80, 0x22a4aa0 },
    { "Extra 3", 0x22a4aa0, 0x22a4ac0 },
    { "Extra 4", 0x22a4ac0, 0x22a4ae0 },
    { "Extra 5", 0x22a4ae0, 0x22a4b00 },
};

const sGame_PaletteDataset CVS2_A_EVILRYU_PALETTES_MK[] =
{
    { "Main Sprite", 0x22a4b00, 0x22a4b20, indexCVS2Sprites_EvilRyu },
    { "Extra 1", 0x22a4b20, 0x22a4b40 },
    { "Extra 2", 0x22a4b40, 0x22a4b60 },
    { "Extra 3", 0x22a4b60, 0x22a4b80 },
    { "Extra 4", 0x22a4b80, 0x22a4ba0 },
    { "Extra 5", 0x22a4ba0, 0x22a4bc0 },
};

const sGame_PaletteDataset CVS2_A_EVILRYU_PALETTES_HK[] =
{
    { "Main Sprite", 0x22a4bc0, 0x22a4be0, indexCVS2Sprites_EvilRyu },
    { "Extra 1", 0x22a4be0, 0x22a4c00 },
    { "Extra 2", 0x22a4c00, 0x22a4c20 },
    { "Extra 3", 0x22a4c20, 0x22a4c40 },
    { "Extra 4", 0x22a4c40, 0x22a4c60 },
    { "Extra 5", 0x22a4c60, 0x22a4c80 },
};

const sGame_PaletteDataset CVS2_A_EVILRYU_PALETTES_3P[] =
{
    { "Main Sprite", 0x22a4c80, 0x22a4ca0, indexCVS2Sprites_EvilRyu },
    { "Extra 1", 0x22a4ca0, 0x22a4cc0 },
    { "Extra 2", 0x22a4cc0, 0x22a4ce0 },
    { "Extra 3", 0x22a4ce0, 0x22a4d00 },
    { "Extra 4", 0x22a4d00, 0x22a4d20 },
    { "Extra 5", 0x22a4d20, 0x22a4d40 },
};

const sGame_PaletteDataset CVS2_A_EVILRYU_PALETTES_3K[] =
{
    { "Main Sprite", 0x22a4d40, 0x22a4d60, indexCVS2Sprites_EvilRyu },
    { "Extra 1", 0x22a4d60, 0x22a4d80 },
    { "Extra 2", 0x22a4d80, 0x22a4da0 },
    { "Extra 3", 0x22a4da0, 0x22a4dc0 },
    { "Extra 4", 0x22a4dc0, 0x22a4de0 },
    { "Extra 5", 0x22a4de0, 0x22a4e00 },
};

const sDescTreeNode CVS2_A_EVILRYU_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_EVILRYU_PALETTES_LP, ARRAYSIZE(CVS2_A_EVILRYU_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_EVILRYU_PALETTES_MP, ARRAYSIZE(CVS2_A_EVILRYU_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_EVILRYU_PALETTES_HP, ARRAYSIZE(CVS2_A_EVILRYU_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_EVILRYU_PALETTES_LK, ARRAYSIZE(CVS2_A_EVILRYU_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_EVILRYU_PALETTES_MK, ARRAYSIZE(CVS2_A_EVILRYU_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_EVILRYU_PALETTES_HK, ARRAYSIZE(CVS2_A_EVILRYU_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_EVILRYU_PALETTES_3P, ARRAYSIZE(CVS2_A_EVILRYU_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_EVILRYU_PALETTES_3K, ARRAYSIZE(CVS2_A_EVILRYU_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_KYO_PALETTES_LP[] =
{
    { "Main Sprite", 0x23a5180, 0x23a51a0, indexCVS2Sprites_Kyo },
    { "Extra 1", 0x23a51a0, 0x23a51c0 },
    { "Extra 2", 0x23a51c0, 0x23a51e0 },
    { "Extra 3", 0x23a51e0, 0x23a5200 },
    { "Extra 4", 0x23a5200, 0x23a5220 },
    { "Extra 5", 0x23a5220, 0x23a5240 },
};

const sGame_PaletteDataset CVS2_A_KYO_PALETTES_MP[] =
{
    { "Main Sprite", 0x23a5240, 0x23a5260, indexCVS2Sprites_Kyo },
    { "Extra 1", 0x23a5260, 0x23a5280 },
    { "Extra 2", 0x23a5280, 0x23a52a0 },
    { "Extra 3", 0x23a52a0, 0x23a52c0 },
    { "Extra 4", 0x23a52c0, 0x23a52e0 },
    { "Extra 5", 0x23a52e0, 0x23a5300 },
};

const sGame_PaletteDataset CVS2_A_KYO_PALETTES_HP[] =
{
    { "Main Sprite", 0x23a5300, 0x23a5320, indexCVS2Sprites_Kyo },
    { "Extra 1", 0x23a5320, 0x23a5340 },
    { "Extra 2", 0x23a5340, 0x23a5360 },
    { "Extra 3", 0x23a5360, 0x23a5380 },
    { "Extra 4", 0x23a5380, 0x23a53a0 },
    { "Extra 5", 0x23a53a0, 0x23a53c0 },
};

const sGame_PaletteDataset CVS2_A_KYO_PALETTES_LK[] =
{
    { "Main Sprite", 0x23a53c0, 0x23a53e0, indexCVS2Sprites_Kyo },
    { "Extra 1", 0x23a53e0, 0x23a5400 },
    { "Extra 2", 0x23a5400, 0x23a5420 },
    { "Extra 3", 0x23a5420, 0x23a5440 },
    { "Extra 4", 0x23a5440, 0x23a5460 },
    { "Extra 5", 0x23a5460, 0x23a5480 },
};

const sGame_PaletteDataset CVS2_A_KYO_PALETTES_MK[] =
{
    { "Main Sprite", 0x23a5480, 0x23a54a0, indexCVS2Sprites_Kyo },
    { "Extra 1", 0x23a54a0, 0x23a54c0 },
    { "Extra 2", 0x23a54c0, 0x23a54e0 },
    { "Extra 3", 0x23a54e0, 0x23a5500 },
    { "Extra 4", 0x23a5500, 0x23a5520 },
    { "Extra 5", 0x23a5520, 0x23a5540 },
};

const sGame_PaletteDataset CVS2_A_KYO_PALETTES_HK[] =
{
    { "Main Sprite", 0x23a5540, 0x23a5560, indexCVS2Sprites_Kyo },
    { "Extra 1", 0x23a5560, 0x23a5580 },
    { "Extra 2", 0x23a5580, 0x23a55a0 },
    { "Extra 3", 0x23a55a0, 0x23a55c0 },
    { "Extra 4", 0x23a55c0, 0x23a55e0 },
    { "Extra 5", 0x23a55e0, 0x23a5600 },
};

const sGame_PaletteDataset CVS2_A_KYO_PALETTES_3P[] =
{
    { "Main Sprite", 0x23a5600, 0x23a5620, indexCVS2Sprites_Kyo },
    { "Extra 1", 0x23a5620, 0x23a5640 },
    { "Extra 2", 0x23a5640, 0x23a5660 },
    { "Extra 3", 0x23a5660, 0x23a5680 },
    { "Extra 4", 0x23a5680, 0x23a56a0 },
    { "Extra 5", 0x23a56a0, 0x23a56c0 },
};

const sGame_PaletteDataset CVS2_A_KYO_PALETTES_3K[] =
{
    { "Main Sprite", 0x23a56c0, 0x23a56e0, indexCVS2Sprites_Kyo },
    { "Extra 1", 0x23a56e0, 0x23a5700 },
    { "Extra 2", 0x23a5700, 0x23a5720 },
    { "Extra 3", 0x23a5720, 0x23a5740 },
    { "Extra 4", 0x23a5740, 0x23a5760 },
    { "Extra 5", 0x23a5760, 0x23a5780 },
};

const sDescTreeNode CVS2_A_KYO_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_KYO_PALETTES_LP, ARRAYSIZE(CVS2_A_KYO_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_KYO_PALETTES_MP, ARRAYSIZE(CVS2_A_KYO_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_KYO_PALETTES_HP, ARRAYSIZE(CVS2_A_KYO_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_KYO_PALETTES_LK, ARRAYSIZE(CVS2_A_KYO_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_KYO_PALETTES_MK, ARRAYSIZE(CVS2_A_KYO_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_KYO_PALETTES_HK, ARRAYSIZE(CVS2_A_KYO_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_KYO_PALETTES_3P, ARRAYSIZE(CVS2_A_KYO_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_KYO_PALETTES_3K, ARRAYSIZE(CVS2_A_KYO_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_IORI_PALETTES_LP[] =
{
    { "Main Sprite", 0x248f660, 0x248f680, indexCVS2Sprites_Iori },
    { "Extra 1", 0x248f680, 0x248f6a0 },
    { "Extra 2", 0x248f6a0, 0x248f6c0 },
    { "Extra 3", 0x248f6c0, 0x248f6e0 },
    { "Extra 4", 0x248f6e0, 0x248f700 },
    { "Extra 5", 0x248f700, 0x248f720 },
};

const sGame_PaletteDataset CVS2_A_IORI_PALETTES_MP[] =
{
    { "Main Sprite", 0x248f720, 0x248f740, indexCVS2Sprites_Iori },
    { "Extra 1", 0x248f740, 0x248f760 },
    { "Extra 2", 0x248f760, 0x248f780 },
    { "Extra 3", 0x248f780, 0x248f7a0 },
    { "Extra 4", 0x248f7a0, 0x248f7c0 },
    { "Extra 5", 0x248f7c0, 0x248f7e0 },
};

const sGame_PaletteDataset CVS2_A_IORI_PALETTES_HP[] =
{
    { "Main Sprite", 0x248f7e0, 0x248f800, indexCVS2Sprites_Iori },
    { "Extra 1", 0x248f800, 0x248f820 },
    { "Extra 2", 0x248f820, 0x248f840 },
    { "Extra 3", 0x248f840, 0x248f860 },
    { "Extra 4", 0x248f860, 0x248f880 },
    { "Extra 5", 0x248f880, 0x248f8a0 },
};

const sGame_PaletteDataset CVS2_A_IORI_PALETTES_LK[] =
{
    { "Main Sprite", 0x248f8a0, 0x248f8c0, indexCVS2Sprites_Iori },
    { "Extra 1", 0x248f8c0, 0x248f8e0 },
    { "Extra 2", 0x248f8e0, 0x248f900 },
    { "Extra 3", 0x248f900, 0x248f920 },
    { "Extra 4", 0x248f920, 0x248f940 },
    { "Extra 5", 0x248f940, 0x248f960 },
};

const sGame_PaletteDataset CVS2_A_IORI_PALETTES_MK[] =
{
    { "Main Sprite", 0x248f960, 0x248f980, indexCVS2Sprites_Iori },
    { "Extra 1", 0x248f980, 0x248f9a0 },
    { "Extra 2", 0x248f9a0, 0x248f9c0 },
    { "Extra 3", 0x248f9c0, 0x248f9e0 },
    { "Extra 4", 0x248f9e0, 0x248fa00 },
    { "Extra 5", 0x248fa00, 0x248fa20 },
};

const sGame_PaletteDataset CVS2_A_IORI_PALETTES_HK[] =
{
    { "Main Sprite", 0x248fa20, 0x248fa40, indexCVS2Sprites_Iori },
    { "Extra 1", 0x248fa40, 0x248fa60 },
    { "Extra 2", 0x248fa60, 0x248fa80 },
    { "Extra 3", 0x248fa80, 0x248faa0 },
    { "Extra 4", 0x248faa0, 0x248fac0 },
    { "Extra 5", 0x248fac0, 0x248fae0 },
};

const sGame_PaletteDataset CVS2_A_IORI_PALETTES_3P[] =
{
    { "Main Sprite", 0x248fae0, 0x248fb00, indexCVS2Sprites_Iori },
    { "Extra 1", 0x248fb00, 0x248fb20 },
    { "Extra 2", 0x248fb20, 0x248fb40 },
    { "Extra 3", 0x248fb40, 0x248fb60 },
    { "Extra 4", 0x248fb60, 0x248fb80 },
    { "Extra 5", 0x248fb80, 0x248fba0 },
};

const sGame_PaletteDataset CVS2_A_IORI_PALETTES_3K[] =
{
    { "Main Sprite", 0x248fba0, 0x248fbc0, indexCVS2Sprites_Iori },
    { "Extra 1", 0x248fbc0, 0x248fbe0 },
    { "Extra 2", 0x248fbe0, 0x248fc00 },
    { "Extra 3", 0x248fc00, 0x248fc20 },
    { "Extra 4", 0x248fc20, 0x248fc40 },
    { "Extra 5", 0x248fc40, 0x248fc60 },
};

const sDescTreeNode CVS2_A_IORI_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_IORI_PALETTES_LP, ARRAYSIZE(CVS2_A_IORI_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_IORI_PALETTES_MP, ARRAYSIZE(CVS2_A_IORI_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_IORI_PALETTES_HP, ARRAYSIZE(CVS2_A_IORI_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_IORI_PALETTES_LK, ARRAYSIZE(CVS2_A_IORI_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_IORI_PALETTES_MK, ARRAYSIZE(CVS2_A_IORI_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_IORI_PALETTES_HK, ARRAYSIZE(CVS2_A_IORI_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_IORI_PALETTES_3P, ARRAYSIZE(CVS2_A_IORI_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_IORI_PALETTES_3K, ARRAYSIZE(CVS2_A_IORI_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_TERRT_PALETTES_LP[] =
{
    { "Main Sprite", 0x257a360, 0x257a380, indexCVS2Sprites_Terry },
    { "Extra 1", 0x257a380, 0x257a3a0 },
    { "Extra 2", 0x257a3a0, 0x257a3c0 },
    { "Extra 3", 0x257a3c0, 0x257a3e0 },
    { "Extra 4", 0x257a3e0, 0x257a400 },
    { "Extra 5", 0x257a400, 0x257a420 },
};

const sGame_PaletteDataset CVS2_A_TERRT_PALETTES_MP[] =
{
    { "Main Sprite", 0x257a420, 0x257a440, indexCVS2Sprites_Terry },
    { "Extra 1", 0x257a440, 0x257a460 },
    { "Extra 2", 0x257a460, 0x257a480 },
    { "Extra 3", 0x257a480, 0x257a4a0 },
    { "Extra 4", 0x257a4a0, 0x257a4c0 },
    { "Extra 5", 0x257a4c0, 0x257a4e0 },
};

const sGame_PaletteDataset CVS2_A_TERRT_PALETTES_HP[] =
{
    { "Main Sprite", 0x257a4e0, 0x257a500, indexCVS2Sprites_Terry },
    { "Extra 1", 0x257a500, 0x257a520 },
    { "Extra 2", 0x257a520, 0x257a540 },
    { "Extra 3", 0x257a540, 0x257a560 },
    { "Extra 4", 0x257a560, 0x257a580 },
    { "Extra 5", 0x257a580, 0x257a5a0 },
};

const sGame_PaletteDataset CVS2_A_TERRT_PALETTES_LK[] =
{
    { "Main Sprite", 0x257a5a0, 0x257a5c0, indexCVS2Sprites_Terry },
    { "Extra 1", 0x257a5c0, 0x257a5e0 },
    { "Extra 2", 0x257a5e0, 0x257a600 },
    { "Extra 3", 0x257a600, 0x257a620 },
    { "Extra 4", 0x257a620, 0x257a640 },
    { "Extra 5", 0x257a640, 0x257a660 },
};

const sGame_PaletteDataset CVS2_A_TERRT_PALETTES_MK[] =
{
    { "Main Sprite", 0x257a660, 0x257a680, indexCVS2Sprites_Terry },
    { "Extra 1", 0x257a680, 0x257a6a0 },
    { "Extra 2", 0x257a6a0, 0x257a6c0 },
    { "Extra 3", 0x257a6c0, 0x257a6e0 },
    { "Extra 4", 0x257a6e0, 0x257a700 },
    { "Extra 5", 0x257a700, 0x257a720 },
};

const sGame_PaletteDataset CVS2_A_TERRT_PALETTES_HK[] =
{
    { "Main Sprite", 0x257a720, 0x257a740, indexCVS2Sprites_Terry },
    { "Extra 1", 0x257a740, 0x257a760 },
    { "Extra 2", 0x257a760, 0x257a780 },
    { "Extra 3", 0x257a780, 0x257a7a0 },
    { "Extra 4", 0x257a7a0, 0x257a7c0 },
    { "Extra 5", 0x257a7c0, 0x257a7e0 },
};

const sGame_PaletteDataset CVS2_A_TERRT_PALETTES_3P[] =
{
    { "Main Sprite", 0x257a7e0, 0x257a800, indexCVS2Sprites_Terry },
    { "Extra 1", 0x257a800, 0x257a820 },
    { "Extra 2", 0x257a820, 0x257a840 },
    { "Extra 3", 0x257a840, 0x257a860 },
    { "Extra 4", 0x257a860, 0x257a880 },
    { "Extra 5", 0x257a880, 0x257a8a0 },
};

const sGame_PaletteDataset CVS2_A_TERRT_PALETTES_3K[] =
{
    { "Main Sprite", 0x257a8a0, 0x257a8c0, indexCVS2Sprites_Terry },
    { "Extra 1", 0x257a8c0, 0x257a8e0 },
    { "Extra 2", 0x257a8e0, 0x257a900 },
    { "Extra 3", 0x257a900, 0x257a920 },
    { "Extra 4", 0x257a920, 0x257a940 },
    { "Extra 5", 0x257a940, 0x257a960 },
};

const sDescTreeNode CVS2_A_TERRT_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_TERRT_PALETTES_LP, ARRAYSIZE(CVS2_A_TERRT_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_TERRT_PALETTES_MP, ARRAYSIZE(CVS2_A_TERRT_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_TERRT_PALETTES_HP, ARRAYSIZE(CVS2_A_TERRT_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_TERRT_PALETTES_LK, ARRAYSIZE(CVS2_A_TERRT_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_TERRT_PALETTES_MK, ARRAYSIZE(CVS2_A_TERRT_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_TERRT_PALETTES_HK, ARRAYSIZE(CVS2_A_TERRT_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_TERRT_PALETTES_3P, ARRAYSIZE(CVS2_A_TERRT_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_TERRT_PALETTES_3K, ARRAYSIZE(CVS2_A_TERRT_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_RYO_PALETTES_LP[] =
{
    { "Main Sprite", 0x265c5c0, 0x265c5e0, indexCVS2Sprites_Ryo },
    { "Extra 1", 0x265c5e0, 0x265c600 },
    { "Extra 2", 0x265c600, 0x265c620 },
    { "Extra 3", 0x265c620, 0x265c640 },
    { "Extra 4", 0x265c640, 0x265c660 },
    { "Extra 5", 0x265c660, 0x265c680 },
};

const sGame_PaletteDataset CVS2_A_RYO_PALETTES_MP[] =
{
    { "Main Sprite", 0x265c680, 0x265c6a0, indexCVS2Sprites_Ryo },
    { "Extra 1", 0x265c6a0, 0x265c6c0 },
    { "Extra 2", 0x265c6c0, 0x265c6e0 },
    { "Extra 3", 0x265c6e0, 0x265c700 },
    { "Extra 4", 0x265c700, 0x265c720 },
    { "Extra 5", 0x265c720, 0x265c740 },
};

const sGame_PaletteDataset CVS2_A_RYO_PALETTES_HP[] =
{
    { "Main Sprite", 0x265c740, 0x265c760, indexCVS2Sprites_Ryo },
    { "Extra 1", 0x265c760, 0x265c780 },
    { "Extra 2", 0x265c780, 0x265c7a0 },
    { "Extra 3", 0x265c7a0, 0x265c7c0 },
    { "Extra 4", 0x265c7c0, 0x265c7e0 },
    { "Extra 5", 0x265c7e0, 0x265c800 },
};

const sGame_PaletteDataset CVS2_A_RYO_PALETTES_LK[] =
{
    { "Main Sprite", 0x265c800, 0x265c820, indexCVS2Sprites_Ryo },
    { "Extra 1", 0x265c820, 0x265c840 },
    { "Extra 2", 0x265c840, 0x265c860 },
    { "Extra 3", 0x265c860, 0x265c880 },
    { "Extra 4", 0x265c880, 0x265c8a0 },
    { "Extra 5", 0x265c8a0, 0x265c8c0 },
};

const sGame_PaletteDataset CVS2_A_RYO_PALETTES_MK[] =
{
    { "Main Sprite", 0x265c8c0, 0x265c8e0, indexCVS2Sprites_Ryo },
    { "Extra 1", 0x265c8e0, 0x265c900 },
    { "Extra 2", 0x265c900, 0x265c920 },
    { "Extra 3", 0x265c920, 0x265c940 },
    { "Extra 4", 0x265c940, 0x265c960 },
    { "Extra 5", 0x265c960, 0x265c980 },
};

const sGame_PaletteDataset CVS2_A_RYO_PALETTES_HK[] =
{
    { "Main Sprite", 0x265c980, 0x265c9a0, indexCVS2Sprites_Ryo },
    { "Extra 1", 0x265c9a0, 0x265c9c0 },
    { "Extra 2", 0x265c9c0, 0x265c9e0 },
    { "Extra 3", 0x265c9e0, 0x265ca00 },
    { "Extra 4", 0x265ca00, 0x265ca20 },
    { "Extra 5", 0x265ca20, 0x265ca40 },
};

const sGame_PaletteDataset CVS2_A_RYO_PALETTES_3P[] =
{
    { "Main Sprite", 0x265ca40, 0x265ca60, indexCVS2Sprites_Ryo },
    { "Extra 1", 0x265ca60, 0x265ca80 },
    { "Extra 2", 0x265ca80, 0x265caa0 },
    { "Extra 3", 0x265caa0, 0x265cac0 },
    { "Extra 4", 0x265cac0, 0x265cae0 },
    { "Extra 5", 0x265cae0, 0x265cb00 },
};

const sGame_PaletteDataset CVS2_A_RYO_PALETTES_3K[] =
{
    { "Main Sprite", 0x265cb00, 0x265cb20, indexCVS2Sprites_Ryo },
    { "Extra 1", 0x265cb20, 0x265cb40 },
    { "Extra 2", 0x265cb40, 0x265cb60 },
    { "Extra 3", 0x265cb60, 0x265cb80 },
    { "Extra 4", 0x265cb80, 0x265cba0 },
    { "Extra 5", 0x265cba0, 0x265cbc0 },
};

const sDescTreeNode CVS2_A_RYO_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_RYO_PALETTES_LP, ARRAYSIZE(CVS2_A_RYO_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_RYO_PALETTES_MP, ARRAYSIZE(CVS2_A_RYO_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_RYO_PALETTES_HP, ARRAYSIZE(CVS2_A_RYO_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_RYO_PALETTES_LK, ARRAYSIZE(CVS2_A_RYO_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_RYO_PALETTES_MK, ARRAYSIZE(CVS2_A_RYO_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_RYO_PALETTES_HK, ARRAYSIZE(CVS2_A_RYO_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_RYO_PALETTES_3P, ARRAYSIZE(CVS2_A_RYO_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_RYO_PALETTES_3K, ARRAYSIZE(CVS2_A_RYO_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_MAI_PALETTES_LP[] =
{
    { "Main Sprite", 0x2741ce0, 0x2741d00, indexCVS2Sprites_Mai },
    { "Extra 1", 0x2741d00, 0x2741d20 },
    { "Extra 2", 0x2741d20, 0x2741d40 },
    { "Extra 3", 0x2741d40, 0x2741d60 },
    { "Extra 4", 0x2741d60, 0x2741d80 },
    { "Extra 5", 0x2741d80, 0x2741da0 },
};

const sGame_PaletteDataset CVS2_A_MAI_PALETTES_MP[] =
{
    { "Main Sprite", 0x2741da0, 0x2741dc0, indexCVS2Sprites_Mai },
    { "Extra 1", 0x2741dc0, 0x2741de0 },
    { "Extra 2", 0x2741de0, 0x2741e00 },
    { "Extra 3", 0x2741e00, 0x2741e20 },
    { "Extra 4", 0x2741e20, 0x2741e40 },
    { "Extra 5", 0x2741e40, 0x2741e60 },
};

const sGame_PaletteDataset CVS2_A_MAI_PALETTES_HP[] =
{
    { "Main Sprite", 0x2741e60, 0x2741e80, indexCVS2Sprites_Mai },
    { "Extra 1", 0x2741e80, 0x2741ea0 },
    { "Extra 2", 0x2741ea0, 0x2741ec0 },
    { "Extra 3", 0x2741ec0, 0x2741ee0 },
    { "Extra 4", 0x2741ee0, 0x2741f00 },
    { "Extra 5", 0x2741f00, 0x2741f20 },
};

const sGame_PaletteDataset CVS2_A_MAI_PALETTES_LK[] =
{
    { "Main Sprite", 0x2741f20, 0x2741f40, indexCVS2Sprites_Mai },
    { "Extra 1", 0x2741f40, 0x2741f60 },
    { "Extra 2", 0x2741f60, 0x2741f80 },
    { "Extra 3", 0x2741f80, 0x2741fa0 },
    { "Extra 4", 0x2741fa0, 0x2741fc0 },
    { "Extra 5", 0x2741fc0, 0x2741fe0 },
};

const sGame_PaletteDataset CVS2_A_MAI_PALETTES_MK[] =
{
    { "Main Sprite", 0x2741fe0, 0x2742000, indexCVS2Sprites_Mai },
    { "Extra 1", 0x2742000, 0x2742020 },
    { "Extra 2", 0x2742020, 0x2742040 },
    { "Extra 3", 0x2742040, 0x2742060 },
    { "Extra 4", 0x2742060, 0x2742080 },
    { "Extra 5", 0x2742080, 0x27420a0 },
};

const sGame_PaletteDataset CVS2_A_MAI_PALETTES_HK[] =
{
    { "Main Sprite", 0x27420a0, 0x27420c0, indexCVS2Sprites_Mai },
    { "Extra 1", 0x27420c0, 0x27420e0 },
    { "Extra 2", 0x27420e0, 0x2742100 },
    { "Extra 3", 0x2742100, 0x2742120 },
    { "Extra 4", 0x2742120, 0x2742140 },
    { "Extra 5", 0x2742140, 0x2742160 },
};

const sGame_PaletteDataset CVS2_A_MAI_PALETTES_3P[] =
{
    { "Main Sprite", 0x2742160, 0x2742180, indexCVS2Sprites_Mai },
    { "Extra 1", 0x2742180, 0x27421a0 },
    { "Extra 2", 0x27421a0, 0x27421c0 },
    { "Extra 3", 0x27421c0, 0x27421e0 },
    { "Extra 4", 0x27421e0, 0x2742200 },
    { "Extra 5", 0x2742200, 0x2742220 },
};

const sGame_PaletteDataset CVS2_A_MAI_PALETTES_3K[] =
{
    { "Main Sprite", 0x2742220, 0x2742240, indexCVS2Sprites_Mai },
    { "Extra 1", 0x2742240, 0x2742260 },
    { "Extra 2", 0x2742260, 0x2742280 },
    { "Extra 3", 0x2742280, 0x27422a0 },
    { "Extra 4", 0x27422a0, 0x27422c0 },
    { "Extra 5", 0x27422c0, 0x27422e0 },
};

const sDescTreeNode CVS2_A_MAI_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_MAI_PALETTES_LP, ARRAYSIZE(CVS2_A_MAI_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_MAI_PALETTES_MP, ARRAYSIZE(CVS2_A_MAI_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_MAI_PALETTES_HP, ARRAYSIZE(CVS2_A_MAI_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_MAI_PALETTES_LK, ARRAYSIZE(CVS2_A_MAI_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_MAI_PALETTES_MK, ARRAYSIZE(CVS2_A_MAI_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_MAI_PALETTES_HK, ARRAYSIZE(CVS2_A_MAI_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_MAI_PALETTES_3P, ARRAYSIZE(CVS2_A_MAI_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_MAI_PALETTES_3K, ARRAYSIZE(CVS2_A_MAI_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_KIM_PALETTES_LP[] =
{
    { "Main Sprite", 0x27d80a0, 0x27d80c0, indexCVS2Sprites_Kim },
    { "Extra 1", 0x27d80c0, 0x27d80e0 },
    { "Extra 2", 0x27d80e0, 0x27d8100 },
    { "Extra 3", 0x27d8100, 0x27d8120 },
    { "Extra 4", 0x27d8120, 0x27d8140 },
    { "Extra 5", 0x27d8140, 0x27d8160 },
};

const sGame_PaletteDataset CVS2_A_KIM_PALETTES_MP[] =
{
    { "Main Sprite", 0x27d8160, 0x27d8180, indexCVS2Sprites_Kim },
    { "Extra 1", 0x27d8180, 0x27d81a0 },
    { "Extra 2", 0x27d81a0, 0x27d81c0 },
    { "Extra 3", 0x27d81c0, 0x27d81e0 },
    { "Extra 4", 0x27d81e0, 0x27d8200 },
    { "Extra 5", 0x27d8200, 0x27d8220 },
};

const sGame_PaletteDataset CVS2_A_KIM_PALETTES_HP[] =
{
    { "Main Sprite", 0x27d8220, 0x27d8240, indexCVS2Sprites_Kim },
    { "Extra 1", 0x27d8240, 0x27d8260 },
    { "Extra 2", 0x27d8260, 0x27d8280 },
    { "Extra 3", 0x27d8280, 0x27d82a0 },
    { "Extra 4", 0x27d82a0, 0x27d82c0 },
    { "Extra 5", 0x27d82c0, 0x27d82e0 },
};

const sGame_PaletteDataset CVS2_A_KIM_PALETTES_LK[] =
{
    { "Main Sprite", 0x27d82e0, 0x27d8300, indexCVS2Sprites_Kim },
    { "Extra 1", 0x27d8300, 0x27d8320 },
    { "Extra 2", 0x27d8320, 0x27d8340 },
    { "Extra 3", 0x27d8340, 0x27d8360 },
    { "Extra 4", 0x27d8360, 0x27d8380 },
    { "Extra 5", 0x27d8380, 0x27d83a0 },
};

const sGame_PaletteDataset CVS2_A_KIM_PALETTES_MK[] =
{
    { "Main Sprite", 0x27d83a0, 0x27d83c0, indexCVS2Sprites_Kim },
    { "Extra 1", 0x27d83c0, 0x27d83e0 },
    { "Extra 2", 0x27d83e0, 0x27d8400 },
    { "Extra 3", 0x27d8400, 0x27d8420 },
    { "Extra 4", 0x27d8420, 0x27d8440 },
    { "Extra 5", 0x27d8440, 0x27d8460 },
};

const sGame_PaletteDataset CVS2_A_KIM_PALETTES_HK[] =
{
    { "Main Sprite", 0x27d8460, 0x27d8480, indexCVS2Sprites_Kim },
    { "Extra 1", 0x27d8480, 0x27d84a0 },
    { "Extra 2", 0x27d84a0, 0x27d84c0 },
    { "Extra 3", 0x27d84c0, 0x27d84e0 },
    { "Extra 4", 0x27d84e0, 0x27d8500 },
    { "Extra 5", 0x27d8500, 0x27d8520 },
};

const sGame_PaletteDataset CVS2_A_KIM_PALETTES_3P[] =
{
    { "Main Sprite", 0x27d8520, 0x27d8540, indexCVS2Sprites_Kim },
    { "Extra 1", 0x27d8540, 0x27d8560 },
    { "Extra 2", 0x27d8560, 0x27d8580 },
    { "Extra 3", 0x27d8580, 0x27d85a0 },
    { "Extra 4", 0x27d85a0, 0x27d85c0 },
    { "Extra 5", 0x27d85c0, 0x27d85e0 },
};

const sGame_PaletteDataset CVS2_A_KIM_PALETTES_3K[] =
{
    { "Main Sprite", 0x27d85e0, 0x27d8600, indexCVS2Sprites_Kim },
    { "Extra 1", 0x27d8600, 0x27d8620 },
    { "Extra 2", 0x27d8620, 0x27d8640 },
    { "Extra 3", 0x27d8640, 0x27d8660 },
    { "Extra 4", 0x27d8660, 0x27d8680 },
    { "Extra 5", 0x27d8680, 0x27d86a0 },
};

const sDescTreeNode CVS2_A_KIM_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_KIM_PALETTES_LP, ARRAYSIZE(CVS2_A_KIM_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_KIM_PALETTES_MP, ARRAYSIZE(CVS2_A_KIM_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_KIM_PALETTES_HP, ARRAYSIZE(CVS2_A_KIM_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_KIM_PALETTES_LK, ARRAYSIZE(CVS2_A_KIM_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_KIM_PALETTES_MK, ARRAYSIZE(CVS2_A_KIM_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_KIM_PALETTES_HK, ARRAYSIZE(CVS2_A_KIM_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_KIM_PALETTES_3P, ARRAYSIZE(CVS2_A_KIM_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_KIM_PALETTES_3K, ARRAYSIZE(CVS2_A_KIM_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_GEESE_PALETTES_LP[] =
{
    { "Main Sprite", 0x28e8ee0, 0x28e8f00, indexCVS2Sprites_Geese },
    { "Extra 1", 0x28e8f00, 0x28e8f20 },
    { "Extra 2", 0x28e8f20, 0x28e8f40 },
    { "Extra 3", 0x28e8f40, 0x28e8f60 },
    { "Extra 4", 0x28e8f60, 0x28e8f80 },
    { "Extra 5", 0x28e8f80, 0x28e8fa0 },
};

const sGame_PaletteDataset CVS2_A_GEESE_PALETTES_MP[] =
{
    { "Main Sprite", 0x28e8fa0, 0x28e8fc0, indexCVS2Sprites_Geese },
    { "Extra 1", 0x28e8fc0, 0x28e8fe0 },
    { "Extra 2", 0x28e8fe0, 0x28e9000 },
    { "Extra 3", 0x28e9000, 0x28e9020 },
    { "Extra 4", 0x28e9020, 0x28e9040 },
    { "Extra 5", 0x28e9040, 0x28e9060 },
};

const sGame_PaletteDataset CVS2_A_GEESE_PALETTES_HP[] =
{
    { "Main Sprite", 0x28e9060, 0x28e9080, indexCVS2Sprites_Geese },
    { "Extra 1", 0x28e9080, 0x28e90a0 },
    { "Extra 2", 0x28e90a0, 0x28e90c0 },
    { "Extra 3", 0x28e90c0, 0x28e90e0 },
    { "Extra 4", 0x28e90e0, 0x28e9100 },
    { "Extra 5", 0x28e9100, 0x28e9120 },
};

const sGame_PaletteDataset CVS2_A_GEESE_PALETTES_LK[] =
{
    { "Main Sprite", 0x28e9120, 0x28e9140, indexCVS2Sprites_Geese },
    { "Extra 1", 0x28e9140, 0x28e9160 },
    { "Extra 2", 0x28e9160, 0x28e9180 },
    { "Extra 3", 0x28e9180, 0x28e91a0 },
    { "Extra 4", 0x28e91a0, 0x28e91c0 },
    { "Extra 5", 0x28e91c0, 0x28e91e0 },
};

const sGame_PaletteDataset CVS2_A_GEESE_PALETTES_MK[] =
{
    { "Main Sprite", 0x28e91e0, 0x28e9200, indexCVS2Sprites_Geese },
    { "Extra 1", 0x28e9200, 0x28e9220 },
    { "Extra 2", 0x28e9220, 0x28e9240 },
    { "Extra 3", 0x28e9240, 0x28e9260 },
    { "Extra 4", 0x28e9260, 0x28e9280 },
    { "Extra 5", 0x28e9280, 0x28e92a0 },
};

const sGame_PaletteDataset CVS2_A_GEESE_PALETTES_HK[] =
{
    { "Main Sprite", 0x28e92a0, 0x28e92c0, indexCVS2Sprites_Geese },
    { "Extra 1", 0x28e92c0, 0x28e92e0 },
    { "Extra 2", 0x28e92e0, 0x28e9300 },
    { "Extra 3", 0x28e9300, 0x28e9320 },
    { "Extra 4", 0x28e9320, 0x28e9340 },
    { "Extra 5", 0x28e9340, 0x28e9360 },
};

const sGame_PaletteDataset CVS2_A_GEESE_PALETTES_3P[] =
{
    { "Main Sprite", 0x28e9360, 0x28e9380, indexCVS2Sprites_Geese },
    { "Extra 1", 0x28e9380, 0x28e93a0 },
    { "Extra 2", 0x28e93a0, 0x28e93c0 },
    { "Extra 3", 0x28e93c0, 0x28e93e0 },
    { "Extra 4", 0x28e93e0, 0x28e9400 },
    { "Extra 5", 0x28e9400, 0x28e9420 },
};

const sGame_PaletteDataset CVS2_A_GEESE_PALETTES_3K[] =
{
    { "Main Sprite", 0x28e9420, 0x28e9440, indexCVS2Sprites_Geese },
    { "Extra 1", 0x28e9440, 0x28e9460 },
    { "Extra 2", 0x28e9460, 0x28e9480 },
    { "Extra 3", 0x28e9480, 0x28e94a0 },
    { "Extra 4", 0x28e94a0, 0x28e94c0 },
    { "Extra 5", 0x28e94c0, 0x28e94e0 },
};

const sDescTreeNode CVS2_A_GEESE_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_GEESE_PALETTES_LP, ARRAYSIZE(CVS2_A_GEESE_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_GEESE_PALETTES_MP, ARRAYSIZE(CVS2_A_GEESE_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_GEESE_PALETTES_HP, ARRAYSIZE(CVS2_A_GEESE_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_GEESE_PALETTES_LK, ARRAYSIZE(CVS2_A_GEESE_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_GEESE_PALETTES_MK, ARRAYSIZE(CVS2_A_GEESE_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_GEESE_PALETTES_HK, ARRAYSIZE(CVS2_A_GEESE_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_GEESE_PALETTES_3P, ARRAYSIZE(CVS2_A_GEESE_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_GEESE_PALETTES_3K, ARRAYSIZE(CVS2_A_GEESE_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_YAMAZAKI_PALETTES_LP[] =
{
    { "Main Sprite", 0x29fcd40, 0x29fcd60, indexCVS2Sprites_RyujiYamazaki },
    { "Extra 1", 0x29fcd60, 0x29fcd80 },
    { "Extra 2", 0x29fcd80, 0x29fcda0 },
    { "Extra 3", 0x29fcda0, 0x29fcdc0 },
    { "Extra 4", 0x29fcdc0, 0x29fcde0 },
    { "Extra 5", 0x29fcde0, 0x29fce00 },
};

const sGame_PaletteDataset CVS2_A_YAMAZAKI_PALETTES_MP[] =
{
    { "Main Sprite", 0x29fce00, 0x29fce20, indexCVS2Sprites_RyujiYamazaki },
    { "Extra 1", 0x29fce20, 0x29fce40 },
    { "Extra 2", 0x29fce40, 0x29fce60 },
    { "Extra 3", 0x29fce60, 0x29fce80 },
    { "Extra 4", 0x29fce80, 0x29fcea0 },
    { "Extra 5", 0x29fcea0, 0x29fcec0 },
};

const sGame_PaletteDataset CVS2_A_YAMAZAKI_PALETTES_HP[] =
{
    { "Main Sprite", 0x29fcec0, 0x29fcee0, indexCVS2Sprites_RyujiYamazaki },
    { "Extra 1", 0x29fcee0, 0x29fcf00 },
    { "Extra 2", 0x29fcf00, 0x29fcf20 },
    { "Extra 3", 0x29fcf20, 0x29fcf40 },
    { "Extra 4", 0x29fcf40, 0x29fcf60 },
    { "Extra 5", 0x29fcf60, 0x29fcf80 },
};

const sGame_PaletteDataset CVS2_A_YAMAZAKI_PALETTES_LK[] =
{
    { "Main Sprite", 0x29fcf80, 0x29fcfa0, indexCVS2Sprites_RyujiYamazaki },
    { "Extra 1", 0x29fcfa0, 0x29fcfc0 },
    { "Extra 2", 0x29fcfc0, 0x29fcfe0 },
    { "Extra 3", 0x29fcfe0, 0x29fd000 },
    { "Extra 4", 0x29fd000, 0x29fd020 },
    { "Extra 5", 0x29fd020, 0x29fd040 },
};

const sGame_PaletteDataset CVS2_A_YAMAZAKI_PALETTES_MK[] =
{
    { "Main Sprite", 0x29fd040, 0x29fd060, indexCVS2Sprites_RyujiYamazaki },
    { "Extra 1", 0x29fd060, 0x29fd080 },
    { "Extra 2", 0x29fd080, 0x29fd0a0 },
    { "Extra 3", 0x29fd0a0, 0x29fd0c0 },
    { "Extra 4", 0x29fd0c0, 0x29fd0e0 },
    { "Extra 5", 0x29fd0e0, 0x29fd100 },
};

const sGame_PaletteDataset CVS2_A_YAMAZAKI_PALETTES_HK[] =
{
    { "Main Sprite", 0x29fd100, 0x29fd120, indexCVS2Sprites_RyujiYamazaki },
    { "Extra 1", 0x29fd120, 0x29fd140 },
    { "Extra 2", 0x29fd140, 0x29fd160 },
    { "Extra 3", 0x29fd160, 0x29fd180 },
    { "Extra 4", 0x29fd180, 0x29fd1a0 },
    { "Extra 5", 0x29fd1a0, 0x29fd1c0 },
};

const sGame_PaletteDataset CVS2_A_YAMAZAKI_PALETTES_3P[] =
{
    { "Main Sprite", 0x29fd1c0, 0x29fd1e0, indexCVS2Sprites_RyujiYamazaki },
    { "Extra 1", 0x29fd1e0, 0x29fd200 },
    { "Extra 2", 0x29fd200, 0x29fd220 },
    { "Extra 3", 0x29fd220, 0x29fd240 },
    { "Extra 4", 0x29fd240, 0x29fd260 },
    { "Extra 5", 0x29fd260, 0x29fd280 },
};

const sGame_PaletteDataset CVS2_A_YAMAZAKI_PALETTES_3K[] =
{
    { "Main Sprite", 0x29fd280, 0x29fd2a0, indexCVS2Sprites_RyujiYamazaki },
    { "Extra 1", 0x29fd2a0, 0x29fd2c0 },
    { "Extra 2", 0x29fd2c0, 0x29fd2e0 },
    { "Extra 3", 0x29fd2e0, 0x29fd300 },
    { "Extra 4", 0x29fd300, 0x29fd320 },
    { "Extra 5", 0x29fd320, 0x29fd340 },
};

const sDescTreeNode CVS2_A_YAMAZAKI_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_YAMAZAKI_PALETTES_LP, ARRAYSIZE(CVS2_A_YAMAZAKI_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_YAMAZAKI_PALETTES_MP, ARRAYSIZE(CVS2_A_YAMAZAKI_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_YAMAZAKI_PALETTES_HP, ARRAYSIZE(CVS2_A_YAMAZAKI_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_YAMAZAKI_PALETTES_LK, ARRAYSIZE(CVS2_A_YAMAZAKI_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_YAMAZAKI_PALETTES_MK, ARRAYSIZE(CVS2_A_YAMAZAKI_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_YAMAZAKI_PALETTES_HK, ARRAYSIZE(CVS2_A_YAMAZAKI_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_YAMAZAKI_PALETTES_3P, ARRAYSIZE(CVS2_A_YAMAZAKI_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_YAMAZAKI_PALETTES_3K, ARRAYSIZE(CVS2_A_YAMAZAKI_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_RAIDEN_PALETTES_LP[] =
{
    { "Main Sprite", 0x2af5a20, 0x2af5a40, indexCVS2Sprites_Raiden },
    { "Extra 1", 0x2af5a40, 0x2af5a60 },
    { "Extra 2", 0x2af5a60, 0x2af5a80 },
    { "Extra 3", 0x2af5a80, 0x2af5aa0 },
    { "Extra 4", 0x2af5aa0, 0x2af5ac0 },
    { "Extra 5", 0x2af5ac0, 0x2af5ae0 },
};

const sGame_PaletteDataset CVS2_A_RAIDEN_PALETTES_MP[] =
{
    { "Main Sprite", 0x2af5ae0, 0x2af5b00, indexCVS2Sprites_Raiden },
    { "Extra 1", 0x2af5b00, 0x2af5b20 },
    { "Extra 2", 0x2af5b20, 0x2af5b40 },
    { "Extra 3", 0x2af5b40, 0x2af5b60 },
    { "Extra 4", 0x2af5b60, 0x2af5b80 },
    { "Extra 5", 0x2af5b80, 0x2af5ba0 },
};

const sGame_PaletteDataset CVS2_A_RAIDEN_PALETTES_HP[] =
{
    { "Main Sprite", 0x2af5ba0, 0x2af5bc0, indexCVS2Sprites_Raiden },
    { "Extra 1", 0x2af5bc0, 0x2af5be0 },
    { "Extra 2", 0x2af5be0, 0x2af5c00 },
    { "Extra 3", 0x2af5c00, 0x2af5c20 },
    { "Extra 4", 0x2af5c20, 0x2af5c40 },
    { "Extra 5", 0x2af5c40, 0x2af5c60 },
};

const sGame_PaletteDataset CVS2_A_RAIDEN_PALETTES_LK[] =
{
    { "Main Sprite", 0x2af5c60, 0x2af5c80, indexCVS2Sprites_Raiden },
    { "Extra 1", 0x2af5c80, 0x2af5ca0 },
    { "Extra 2", 0x2af5ca0, 0x2af5cc0 },
    { "Extra 3", 0x2af5cc0, 0x2af5ce0 },
    { "Extra 4", 0x2af5ce0, 0x2af5d00 },
    { "Extra 5", 0x2af5d00, 0x2af5d20 },
};

const sGame_PaletteDataset CVS2_A_RAIDEN_PALETTES_MK[] =
{
    { "Main Sprite", 0x2af5d20, 0x2af5d40, indexCVS2Sprites_Raiden },
    { "Extra 1", 0x2af5d40, 0x2af5d60 },
    { "Extra 2", 0x2af5d60, 0x2af5d80 },
    { "Extra 3", 0x2af5d80, 0x2af5da0 },
    { "Extra 4", 0x2af5da0, 0x2af5dc0 },
    { "Extra 5", 0x2af5dc0, 0x2af5de0 },
};

const sGame_PaletteDataset CVS2_A_RAIDEN_PALETTES_HK[] =
{
    { "Main Sprite", 0x2af5de0, 0x2af5e00, indexCVS2Sprites_Raiden },
    { "Extra 1", 0x2af5e00, 0x2af5e20 },
    { "Extra 2", 0x2af5e20, 0x2af5e40 },
    { "Extra 3", 0x2af5e40, 0x2af5e60 },
    { "Extra 4", 0x2af5e60, 0x2af5e80 },
    { "Extra 5", 0x2af5e80, 0x2af5ea0 },
};

const sGame_PaletteDataset CVS2_A_RAIDEN_PALETTES_3P[] =
{
    { "Main Sprite", 0x2af5ea0, 0x2af5ec0, indexCVS2Sprites_Raiden },
    { "Extra 1", 0x2af5ec0, 0x2af5ee0 },
    { "Extra 2", 0x2af5ee0, 0x2af5f00 },
    { "Extra 3", 0x2af5f00, 0x2af5f20 },
    { "Extra 4", 0x2af5f20, 0x2af5f40 },
    { "Extra 5", 0x2af5f40, 0x2af5f60 },
};

const sGame_PaletteDataset CVS2_A_RAIDEN_PALETTES_3K[] =
{
    { "Main Sprite", 0x2af5f60, 0x2af5f80, indexCVS2Sprites_Raiden },
    { "Extra 1", 0x2af5f80, 0x2af5fa0 },
    { "Extra 2", 0x2af5fa0, 0x2af5fc0 },
    { "Extra 3", 0x2af5fc0, 0x2af5fe0 },
    { "Extra 4", 0x2af5fe0, 0x2af6000 },
    { "Extra 5", 0x2af6000, 0x2af6020 },
};

const sDescTreeNode CVS2_A_RAIDEN_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_RAIDEN_PALETTES_LP, ARRAYSIZE(CVS2_A_RAIDEN_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_RAIDEN_PALETTES_MP, ARRAYSIZE(CVS2_A_RAIDEN_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_RAIDEN_PALETTES_HP, ARRAYSIZE(CVS2_A_RAIDEN_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_RAIDEN_PALETTES_LK, ARRAYSIZE(CVS2_A_RAIDEN_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_RAIDEN_PALETTES_MK, ARRAYSIZE(CVS2_A_RAIDEN_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_RAIDEN_PALETTES_HK, ARRAYSIZE(CVS2_A_RAIDEN_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_RAIDEN_PALETTES_3P, ARRAYSIZE(CVS2_A_RAIDEN_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_RAIDEN_PALETTES_3K, ARRAYSIZE(CVS2_A_RAIDEN_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_RUGAL_PALETTES_LP[] =
{
    { "Main Sprite", 0x2c28660, 0x2c28680, indexCVS2Sprites_Rugal },
    { "Extra 1", 0x2c28680, 0x2c286a0 },
    { "Extra 2", 0x2c286a0, 0x2c286c0 },
    { "Extra 3", 0x2c286c0, 0x2c286e0 },
    { "Extra 4", 0x2c286e0, 0x2c28700 },
    { "Extra 5", 0x2c28700, 0x2c28720 },
};

const sGame_PaletteDataset CVS2_A_RUGAL_PALETTES_MP[] =
{
    { "Main Sprite", 0x2c28720, 0x2c28740, indexCVS2Sprites_Rugal },
    { "Extra 1", 0x2c28740, 0x2c28760 },
    { "Extra 2", 0x2c28760, 0x2c28780 },
    { "Extra 3", 0x2c28780, 0x2c287a0 },
    { "Extra 4", 0x2c287a0, 0x2c287c0 },
    { "Extra 5", 0x2c287c0, 0x2c287e0 },
};

const sGame_PaletteDataset CVS2_A_RUGAL_PALETTES_HP[] =
{
    { "Main Sprite", 0x2c287e0, 0x2c28800, indexCVS2Sprites_Rugal },
    { "Extra 1", 0x2c28800, 0x2c28820 },
    { "Extra 2", 0x2c28820, 0x2c28840 },
    { "Extra 3", 0x2c28840, 0x2c28860 },
    { "Extra 4", 0x2c28860, 0x2c28880 },
    { "Extra 5", 0x2c28880, 0x2c288a0 },
};

const sGame_PaletteDataset CVS2_A_RUGAL_PALETTES_LK[] =
{
    { "Main Sprite", 0x2c288a0, 0x2c288c0, indexCVS2Sprites_Rugal },
    { "Extra 1", 0x2c288c0, 0x2c288e0 },
    { "Extra 2", 0x2c288e0, 0x2c28900 },
    { "Extra 3", 0x2c28900, 0x2c28920 },
    { "Extra 4", 0x2c28920, 0x2c28940 },
    { "Extra 5", 0x2c28940, 0x2c28960 },
};

const sGame_PaletteDataset CVS2_A_RUGAL_PALETTES_MK[] =
{
    { "Main Sprite", 0x2c28960, 0x2c28980, indexCVS2Sprites_Rugal },
    { "Extra 1", 0x2c28980, 0x2c289a0 },
    { "Extra 2", 0x2c289a0, 0x2c289c0 },
    { "Extra 3", 0x2c289c0, 0x2c289e0 },
    { "Extra 4", 0x2c289e0, 0x2c28a00 },
    { "Extra 5", 0x2c28a00, 0x2c28a20 },
};

const sGame_PaletteDataset CVS2_A_RUGAL_PALETTES_HK[] =
{
    { "Main Sprite", 0x2c28a20, 0x2c28a40, indexCVS2Sprites_Rugal },
    { "Extra 1", 0x2c28a40, 0x2c28a60 },
    { "Extra 2", 0x2c28a60, 0x2c28a80 },
    { "Extra 3", 0x2c28a80, 0x2c28aa0 },
    { "Extra 4", 0x2c28aa0, 0x2c28ac0 },
    { "Extra 5", 0x2c28ac0, 0x2c28ae0 },
};

const sGame_PaletteDataset CVS2_A_RUGAL_PALETTES_3P[] =
{
    { "Main Sprite", 0x2c28ae0, 0x2c28b00, indexCVS2Sprites_Rugal },
    { "Extra 1", 0x2c28b00, 0x2c28b20 },
    { "Extra 2", 0x2c28b20, 0x2c28b40 },
    { "Extra 3", 0x2c28b40, 0x2c28b60 },
    { "Extra 4", 0x2c28b60, 0x2c28b80 },
    { "Extra 5", 0x2c28b80, 0x2c28ba0 },
};

const sGame_PaletteDataset CVS2_A_RUGAL_PALETTES_3K[] =
{
    { "Main Sprite", 0x2c28ba0, 0x2c28bc0, indexCVS2Sprites_Rugal },
    { "Extra 1", 0x2c28bc0, 0x2c28be0 },
    { "Extra 2", 0x2c28be0, 0x2c28c00 },
    { "Extra 3", 0x2c28c00, 0x2c28c20 },
    { "Extra 4", 0x2c28c20, 0x2c28c40 },
    { "Extra 5", 0x2c28c40, 0x2c28c60 },
};

const sDescTreeNode CVS2_A_RUGAL_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_RUGAL_PALETTES_LP, ARRAYSIZE(CVS2_A_RUGAL_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_RUGAL_PALETTES_MP, ARRAYSIZE(CVS2_A_RUGAL_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_RUGAL_PALETTES_HP, ARRAYSIZE(CVS2_A_RUGAL_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_RUGAL_PALETTES_LK, ARRAYSIZE(CVS2_A_RUGAL_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_RUGAL_PALETTES_MK, ARRAYSIZE(CVS2_A_RUGAL_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_RUGAL_PALETTES_HK, ARRAYSIZE(CVS2_A_RUGAL_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_RUGAL_PALETTES_3P, ARRAYSIZE(CVS2_A_RUGAL_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_RUGAL_PALETTES_3K, ARRAYSIZE(CVS2_A_RUGAL_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_VICE_PALETTES_LP[] =
{
    { "Main Sprite", 0x2d18200, 0x2d18220, indexCVS2Sprites_Vice },
    { "Extra 1", 0x2d18220, 0x2d18240 },
    { "Extra 2", 0x2d18240, 0x2d18260 },
    { "Extra 3", 0x2d18260, 0x2d18280 },
    { "Extra 4", 0x2d18280, 0x2d182a0 },
    { "Extra 5", 0x2d182a0, 0x2d182c0 },
};

const sGame_PaletteDataset CVS2_A_VICE_PALETTES_MP[] =
{
    { "Main Sprite", 0x2d182c0, 0x2d182e0, indexCVS2Sprites_Vice },
    { "Extra 1", 0x2d182e0, 0x2d18300 },
    { "Extra 2", 0x2d18300, 0x2d18320 },
    { "Extra 3", 0x2d18320, 0x2d18340 },
    { "Extra 4", 0x2d18340, 0x2d18360 },
    { "Extra 5", 0x2d18360, 0x2d18380 },
};

const sGame_PaletteDataset CVS2_A_VICE_PALETTES_HP[] =
{
    { "Main Sprite", 0x2d18380, 0x2d183a0, indexCVS2Sprites_Vice },
    { "Extra 1", 0x2d183a0, 0x2d183c0 },
    { "Extra 2", 0x2d183c0, 0x2d183e0 },
    { "Extra 3", 0x2d183e0, 0x2d18400 },
    { "Extra 4", 0x2d18400, 0x2d18420 },
    { "Extra 5", 0x2d18420, 0x2d18440 },
};

const sGame_PaletteDataset CVS2_A_VICE_PALETTES_LK[] =
{
    { "Main Sprite", 0x2d18440, 0x2d18460, indexCVS2Sprites_Vice },
    { "Extra 1", 0x2d18460, 0x2d18480 },
    { "Extra 2", 0x2d18480, 0x2d184a0 },
    { "Extra 3", 0x2d184a0, 0x2d184c0 },
    { "Extra 4", 0x2d184c0, 0x2d184e0 },
    { "Extra 5", 0x2d184e0, 0x2d18500 },
};

const sGame_PaletteDataset CVS2_A_VICE_PALETTES_MK[] =
{
    { "Main Sprite", 0x2d18500, 0x2d18520, indexCVS2Sprites_Vice },
    { "Extra 1", 0x2d18520, 0x2d18540 },
    { "Extra 2", 0x2d18540, 0x2d18560 },
    { "Extra 3", 0x2d18560, 0x2d18580 },
    { "Extra 4", 0x2d18580, 0x2d185a0 },
    { "Extra 5", 0x2d185a0, 0x2d185c0 },
};

const sGame_PaletteDataset CVS2_A_VICE_PALETTES_HK[] =
{
    { "Main Sprite", 0x2d185c0, 0x2d185e0, indexCVS2Sprites_Vice },
    { "Extra 1", 0x2d185e0, 0x2d18600 },
    { "Extra 2", 0x2d18600, 0x2d18620 },
    { "Extra 3", 0x2d18620, 0x2d18640 },
    { "Extra 4", 0x2d18640, 0x2d18660 },
    { "Extra 5", 0x2d18660, 0x2d18680 },
};

const sGame_PaletteDataset CVS2_A_VICE_PALETTES_3P[] =
{
    { "Main Sprite", 0x2d18680, 0x2d186a0, indexCVS2Sprites_Vice },
    { "Extra 1", 0x2d186a0, 0x2d186c0 },
    { "Extra 2", 0x2d186c0, 0x2d186e0 },
    { "Extra 3", 0x2d186e0, 0x2d18700 },
    { "Extra 4", 0x2d18700, 0x2d18720 },
    { "Extra 5", 0x2d18720, 0x2d18740 },
};

const sGame_PaletteDataset CVS2_A_VICE_PALETTES_3K[] =
{
    { "Main Sprite", 0x2d18740, 0x2d18760, indexCVS2Sprites_Vice },
    { "Extra 1", 0x2d18760, 0x2d18780 },
    { "Extra 2", 0x2d18780, 0x2d187a0 },
    { "Extra 3", 0x2d187a0, 0x2d187c0 },
    { "Extra 4", 0x2d187c0, 0x2d187e0 },
    { "Extra 5", 0x2d187e0, 0x2d18800 },
};

const sDescTreeNode CVS2_A_VICE_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_VICE_PALETTES_LP, ARRAYSIZE(CVS2_A_VICE_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_VICE_PALETTES_MP, ARRAYSIZE(CVS2_A_VICE_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_VICE_PALETTES_HP, ARRAYSIZE(CVS2_A_VICE_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_VICE_PALETTES_LK, ARRAYSIZE(CVS2_A_VICE_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_VICE_PALETTES_MK, ARRAYSIZE(CVS2_A_VICE_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_VICE_PALETTES_HK, ARRAYSIZE(CVS2_A_VICE_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_VICE_PALETTES_3P, ARRAYSIZE(CVS2_A_VICE_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_VICE_PALETTES_3K, ARRAYSIZE(CVS2_A_VICE_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_BENIMARU_PALETTES_LP[] =
{
    { "Main Sprite", 0x2e38300, 0x2e38320, indexCVS2Sprites_Benimaru },
    { "Extra 1", 0x2e38320, 0x2e38340 },
    { "Extra 2", 0x2e38340, 0x2e38360 },
    { "Extra 3", 0x2e38360, 0x2e38380 },
    { "Extra 4", 0x2e38380, 0x2e383a0 },
    { "Extra 5", 0x2e383a0, 0x2e383c0 },
};

const sGame_PaletteDataset CVS2_A_BENIMARU_PALETTES_MP[] =
{
    { "Main Sprite", 0x2e383c0, 0x2e383e0, indexCVS2Sprites_Benimaru },
    { "Extra 1", 0x2e383e0, 0x2e38400 },
    { "Extra 2", 0x2e38400, 0x2e38420 },
    { "Extra 3", 0x2e38420, 0x2e38440 },
    { "Extra 4", 0x2e38440, 0x2e38460 },
    { "Extra 5", 0x2e38460, 0x2e38480 },
};

const sGame_PaletteDataset CVS2_A_BENIMARU_PALETTES_HP[] =
{
    { "Main Sprite", 0x2e38480, 0x2e384a0, indexCVS2Sprites_Benimaru },
    { "Extra 1", 0x2e384a0, 0x2e384c0 },
    { "Extra 2", 0x2e384c0, 0x2e384e0 },
    { "Extra 3", 0x2e384e0, 0x2e38500 },
    { "Extra 4", 0x2e38500, 0x2e38520 },
    { "Extra 5", 0x2e38520, 0x2e38540 },
};

const sGame_PaletteDataset CVS2_A_BENIMARU_PALETTES_LK[] =
{
    { "Main Sprite", 0x2e38540, 0x2e38560, indexCVS2Sprites_Benimaru },
    { "Extra 1", 0x2e38560, 0x2e38580 },
    { "Extra 2", 0x2e38580, 0x2e385a0 },
    { "Extra 3", 0x2e385a0, 0x2e385c0 },
    { "Extra 4", 0x2e385c0, 0x2e385e0 },
    { "Extra 5", 0x2e385e0, 0x2e38600 },
};

const sGame_PaletteDataset CVS2_A_BENIMARU_PALETTES_MK[] =
{
    { "Main Sprite", 0x2e38600, 0x2e38620, indexCVS2Sprites_Benimaru },
    { "Extra 1", 0x2e38620, 0x2e38640 },
    { "Extra 2", 0x2e38640, 0x2e38660 },
    { "Extra 3", 0x2e38660, 0x2e38680 },
    { "Extra 4", 0x2e38680, 0x2e386a0 },
    { "Extra 5", 0x2e386a0, 0x2e386c0 },
};

const sGame_PaletteDataset CVS2_A_BENIMARU_PALETTES_HK[] =
{
    { "Main Sprite", 0x2e386c0, 0x2e386e0, indexCVS2Sprites_Benimaru },
    { "Extra 1", 0x2e386e0, 0x2e38700 },
    { "Extra 2", 0x2e38700, 0x2e38720 },
    { "Extra 3", 0x2e38720, 0x2e38740 },
    { "Extra 4", 0x2e38740, 0x2e38760 },
    { "Extra 5", 0x2e38760, 0x2e38780 },
};

const sGame_PaletteDataset CVS2_A_BENIMARU_PALETTES_3P[] =
{
    { "Main Sprite", 0x2e38780, 0x2e387a0, indexCVS2Sprites_Benimaru },
    { "Extra 1", 0x2e387a0, 0x2e387c0 },
    { "Extra 2", 0x2e387c0, 0x2e387e0 },
    { "Extra 3", 0x2e387e0, 0x2e38800 },
    { "Extra 4", 0x2e38800, 0x2e38820 },
    { "Extra 5", 0x2e38820, 0x2e38840 },
};

const sGame_PaletteDataset CVS2_A_BENIMARU_PALETTES_3K[] =
{
    { "Main Sprite", 0x2e38840, 0x2e38860, indexCVS2Sprites_Benimaru },
    { "Extra 1", 0x2e38860, 0x2e38880 },
    { "Extra 2", 0x2e38880, 0x2e388a0 },
    { "Extra 3", 0x2e388a0, 0x2e388c0 },
    { "Extra 4", 0x2e388c0, 0x2e388e0 },
    { "Extra 5", 0x2e388e0, 0x2e38900 },
};

const sDescTreeNode CVS2_A_BENIMARU_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_BENIMARU_PALETTES_LP, ARRAYSIZE(CVS2_A_BENIMARU_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_BENIMARU_PALETTES_MP, ARRAYSIZE(CVS2_A_BENIMARU_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_BENIMARU_PALETTES_HP, ARRAYSIZE(CVS2_A_BENIMARU_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_BENIMARU_PALETTES_LK, ARRAYSIZE(CVS2_A_BENIMARU_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_BENIMARU_PALETTES_MK, ARRAYSIZE(CVS2_A_BENIMARU_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_BENIMARU_PALETTES_HK, ARRAYSIZE(CVS2_A_BENIMARU_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_BENIMARU_PALETTES_3P, ARRAYSIZE(CVS2_A_BENIMARU_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_BENIMARU_PALETTES_3K, ARRAYSIZE(CVS2_A_BENIMARU_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_YURI_PALETTES_LP[] =
{
    { "Main Sprite", 0x2edf8e0, 0x2edf900, indexCVS2Sprites_Yuri },
    { "Extra 1", 0x2edf900, 0x2edf920 },
    { "Extra 2", 0x2edf920, 0x2edf940 },
    { "Extra 3", 0x2edf940, 0x2edf960 },
    { "Extra 4", 0x2edf960, 0x2edf980 },
    { "Extra 5", 0x2edf980, 0x2edf9a0 },
};

const sGame_PaletteDataset CVS2_A_YURI_PALETTES_MP[] =
{
    { "Main Sprite", 0x2edf9a0, 0x2edf9c0, indexCVS2Sprites_Yuri },
    { "Extra 1", 0x2edf9c0, 0x2edf9e0 },
    { "Extra 2", 0x2edf9e0, 0x2edfa00 },
    { "Extra 3", 0x2edfa00, 0x2edfa20 },
    { "Extra 4", 0x2edfa20, 0x2edfa40 },
    { "Extra 5", 0x2edfa40, 0x2edfa60 },
};

const sGame_PaletteDataset CVS2_A_YURI_PALETTES_HP[] =
{
    { "Main Sprite", 0x2edfa60, 0x2edfa80, indexCVS2Sprites_Yuri },
    { "Extra 1", 0x2edfa80, 0x2edfaa0 },
    { "Extra 2", 0x2edfaa0, 0x2edfac0 },
    { "Extra 3", 0x2edfac0, 0x2edfae0 },
    { "Extra 4", 0x2edfae0, 0x2edfb00 },
    { "Extra 5", 0x2edfb00, 0x2edfb20 },
};

const sGame_PaletteDataset CVS2_A_YURI_PALETTES_LK[] =
{
    { "Main Sprite", 0x2edfb20, 0x2edfb40, indexCVS2Sprites_Yuri },
    { "Extra 1", 0x2edfb40, 0x2edfb60 },
    { "Extra 2", 0x2edfb60, 0x2edfb80 },
    { "Extra 3", 0x2edfb80, 0x2edfba0 },
    { "Extra 4", 0x2edfba0, 0x2edfbc0 },
    { "Extra 5", 0x2edfbc0, 0x2edfbe0 },
};

const sGame_PaletteDataset CVS2_A_YURI_PALETTES_MK[] =
{
    { "Main Sprite", 0x2edfbe0, 0x2edfc00, indexCVS2Sprites_Yuri },
    { "Extra 1", 0x2edfc00, 0x2edfc20 },
    { "Extra 2", 0x2edfc20, 0x2edfc40 },
    { "Extra 3", 0x2edfc40, 0x2edfc60 },
    { "Extra 4", 0x2edfc60, 0x2edfc80 },
    { "Extra 5", 0x2edfc80, 0x2edfca0 },
};

const sGame_PaletteDataset CVS2_A_YURI_PALETTES_HK[] =
{
    { "Main Sprite", 0x2edfca0, 0x2edfcc0, indexCVS2Sprites_Yuri },
    { "Extra 1", 0x2edfcc0, 0x2edfce0 },
    { "Extra 2", 0x2edfce0, 0x2edfd00 },
    { "Extra 3", 0x2edfd00, 0x2edfd20 },
    { "Extra 4", 0x2edfd20, 0x2edfd40 },
    { "Extra 5", 0x2edfd40, 0x2edfd60 },
};

const sGame_PaletteDataset CVS2_A_YURI_PALETTES_3P[] =
{
    { "Main Sprite", 0x2edfd60, 0x2edfd80, indexCVS2Sprites_Yuri },
    { "Extra 1", 0x2edfd80, 0x2edfda0 },
    { "Extra 2", 0x2edfda0, 0x2edfdc0 },
    { "Extra 3", 0x2edfdc0, 0x2edfde0 },
    { "Extra 4", 0x2edfde0, 0x2edfe00 },
    { "Extra 5", 0x2edfe00, 0x2edfe20 },
};

const sGame_PaletteDataset CVS2_A_YURI_PALETTES_3K[] =
{
    { "Main Sprite", 0x2edfe20, 0x2edfe40, indexCVS2Sprites_Yuri },
    { "Extra 1", 0x2edfe40, 0x2edfe60 },
    { "Extra 2", 0x2edfe60, 0x2edfe80 },
    { "Extra 3", 0x2edfe80, 0x2edfea0 },
    { "Extra 4", 0x2edfea0, 0x2edfec0 },
    { "Extra 5", 0x2edfec0, 0x2edfee0 },
};

const sDescTreeNode CVS2_A_YURI_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_YURI_PALETTES_LP, ARRAYSIZE(CVS2_A_YURI_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_YURI_PALETTES_MP, ARRAYSIZE(CVS2_A_YURI_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_YURI_PALETTES_HP, ARRAYSIZE(CVS2_A_YURI_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_YURI_PALETTES_LK, ARRAYSIZE(CVS2_A_YURI_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_YURI_PALETTES_MK, ARRAYSIZE(CVS2_A_YURI_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_YURI_PALETTES_HK, ARRAYSIZE(CVS2_A_YURI_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_YURI_PALETTES_3P, ARRAYSIZE(CVS2_A_YURI_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_YURI_PALETTES_3K, ARRAYSIZE(CVS2_A_YURI_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_KING_PALETTES_LP[] =
{
    { "Main Sprite", 0x2f76140, 0x2f76160, indexCVS2Sprites_King },
    { "Extra 1", 0x2f76160, 0x2f76180 },
    { "Extra 2", 0x2f76180, 0x2f761a0 },
    { "Extra 3", 0x2f761a0, 0x2f761c0 },
    { "Extra 4", 0x2f761c0, 0x2f761e0 },
    { "Extra 5", 0x2f761e0, 0x2f76200 },
};

const sGame_PaletteDataset CVS2_A_KING_PALETTES_MP[] =
{
    { "Main Sprite", 0x2f76200, 0x2f76220, indexCVS2Sprites_King },
    { "Extra 1", 0x2f76220, 0x2f76240 },
    { "Extra 2", 0x2f76240, 0x2f76260 },
    { "Extra 3", 0x2f76260, 0x2f76280 },
    { "Extra 4", 0x2f76280, 0x2f762a0 },
    { "Extra 5", 0x2f762a0, 0x2f762c0 },
};

const sGame_PaletteDataset CVS2_A_KING_PALETTES_HP[] =
{
    { "Main Sprite", 0x2f762c0, 0x2f762e0, indexCVS2Sprites_King },
    { "Extra 1", 0x2f762e0, 0x2f76300 },
    { "Extra 2", 0x2f76300, 0x2f76320 },
    { "Extra 3", 0x2f76320, 0x2f76340 },
    { "Extra 4", 0x2f76340, 0x2f76360 },
    { "Extra 5", 0x2f76360, 0x2f76380 },
};

const sGame_PaletteDataset CVS2_A_KING_PALETTES_LK[] =
{
    { "Main Sprite", 0x2f76380, 0x2f763a0, indexCVS2Sprites_King },
    { "Extra 1", 0x2f763a0, 0x2f763c0 },
    { "Extra 2", 0x2f763c0, 0x2f763e0 },
    { "Extra 3", 0x2f763e0, 0x2f76400 },
    { "Extra 4", 0x2f76400, 0x2f76420 },
    { "Extra 5", 0x2f76420, 0x2f76440 },
};

const sGame_PaletteDataset CVS2_A_KING_PALETTES_MK[] =
{
    { "Main Sprite", 0x2f76440, 0x2f76460, indexCVS2Sprites_King },
    { "Extra 1", 0x2f76460, 0x2f76480 },
    { "Extra 2", 0x2f76480, 0x2f764a0 },
    { "Extra 3", 0x2f764a0, 0x2f764c0 },
    { "Extra 4", 0x2f764c0, 0x2f764e0 },
    { "Extra 5", 0x2f764e0, 0x2f76500 },
};

const sGame_PaletteDataset CVS2_A_KING_PALETTES_HK[] =
{
    { "Main Sprite", 0x2f76500, 0x2f76520, indexCVS2Sprites_King },
    { "Extra 1", 0x2f76520, 0x2f76540 },
    { "Extra 2", 0x2f76540, 0x2f76560 },
    { "Extra 3", 0x2f76560, 0x2f76580 },
    { "Extra 4", 0x2f76580, 0x2f765a0 },
    { "Extra 5", 0x2f765a0, 0x2f765c0 },
};

const sGame_PaletteDataset CVS2_A_KING_PALETTES_3P[] =
{
    { "Main Sprite", 0x2f765c0, 0x2f765e0, indexCVS2Sprites_King },
    { "Extra 1", 0x2f765e0, 0x2f76600 },
    { "Extra 2", 0x2f76600, 0x2f76620 },
    { "Extra 3", 0x2f76620, 0x2f76640 },
    { "Extra 4", 0x2f76640, 0x2f76660 },
    { "Extra 5", 0x2f76660, 0x2f76680 },
};

const sGame_PaletteDataset CVS2_A_KING_PALETTES_3K[] =
{
    { "Main Sprite", 0x2f76680, 0x2f766a0, indexCVS2Sprites_King },
    { "Extra 1", 0x2f766a0, 0x2f766c0 },
    { "Extra 2", 0x2f766c0, 0x2f766e0 },
    { "Extra 3", 0x2f766e0, 0x2f76700 },
    { "Extra 4", 0x2f76700, 0x2f76720 },
    { "Extra 5", 0x2f76720, 0x2f76740 },
};

const sDescTreeNode CVS2_A_KING_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_KING_PALETTES_LP, ARRAYSIZE(CVS2_A_KING_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_KING_PALETTES_MP, ARRAYSIZE(CVS2_A_KING_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_KING_PALETTES_HP, ARRAYSIZE(CVS2_A_KING_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_KING_PALETTES_LK, ARRAYSIZE(CVS2_A_KING_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_KING_PALETTES_MK, ARRAYSIZE(CVS2_A_KING_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_KING_PALETTES_HK, ARRAYSIZE(CVS2_A_KING_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_KING_PALETTES_3P, ARRAYSIZE(CVS2_A_KING_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_KING_PALETTES_3K, ARRAYSIZE(CVS2_A_KING_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_NAKORURU_PALETTES_LP[] =
{
    { "Main Sprite", 0x3069680, 0x30696a0, indexCVS2Sprites_Nakoruru },
    { "Extra 1", 0x30696a0, 0x30696c0 },
    { "Extra 2", 0x30696c0, 0x30696e0 },
    { "Extra 3", 0x30696e0, 0x3069700 },
    { "Extra 4", 0x3069700, 0x3069720 },
    { "Extra 5", 0x3069720, 0x3069740 },
};

const sGame_PaletteDataset CVS2_A_NAKORURU_PALETTES_MP[] =
{
    { "Main Sprite", 0x3069740, 0x3069760, indexCVS2Sprites_Nakoruru },
    { "Extra 1", 0x3069760, 0x3069780 },
    { "Extra 2", 0x3069780, 0x30697a0 },
    { "Extra 3", 0x30697a0, 0x30697c0 },
    { "Extra 4", 0x30697c0, 0x30697e0 },
    { "Extra 5", 0x30697e0, 0x3069800 },
};

const sGame_PaletteDataset CVS2_A_NAKORURU_PALETTES_HP[] =
{
    { "Main Sprite", 0x3069800, 0x3069820, indexCVS2Sprites_Nakoruru },
    { "Extra 1", 0x3069820, 0x3069840 },
    { "Extra 2", 0x3069840, 0x3069860 },
    { "Extra 3", 0x3069860, 0x3069880 },
    { "Extra 4", 0x3069880, 0x30698a0 },
    { "Extra 5", 0x30698a0, 0x30698c0 },
};

const sGame_PaletteDataset CVS2_A_NAKORURU_PALETTES_LK[] =
{
    { "Main Sprite", 0x30698c0, 0x30698e0, indexCVS2Sprites_Nakoruru },
    { "Extra 1", 0x30698e0, 0x3069900 },
    { "Extra 2", 0x3069900, 0x3069920 },
    { "Extra 3", 0x3069920, 0x3069940 },
    { "Extra 4", 0x3069940, 0x3069960 },
    { "Extra 5", 0x3069960, 0x3069980 },
};

const sGame_PaletteDataset CVS2_A_NAKORURU_PALETTES_MK[] =
{
    { "Main Sprite", 0x3069980, 0x30699a0, indexCVS2Sprites_Nakoruru },
    { "Extra 1", 0x30699a0, 0x30699c0 },
    { "Extra 2", 0x30699c0, 0x30699e0 },
    { "Extra 3", 0x30699e0, 0x3069a00 },
    { "Extra 4", 0x3069a00, 0x3069a20 },
    { "Extra 5", 0x3069a20, 0x3069a40 },
};

const sGame_PaletteDataset CVS2_A_NAKORURU_PALETTES_HK[] =
{
    { "Main Sprite", 0x3069a40, 0x3069a60, indexCVS2Sprites_Nakoruru },
    { "Extra 1", 0x3069a60, 0x3069a80 },
    { "Extra 2", 0x3069a80, 0x3069aa0 },
    { "Extra 3", 0x3069aa0, 0x3069ac0 },
    { "Extra 4", 0x3069ac0, 0x3069ae0 },
    { "Extra 5", 0x3069ae0, 0x3069b00 },
};

const sGame_PaletteDataset CVS2_A_NAKORURU_PALETTES_3P[] =
{
    { "Main Sprite", 0x3069b00, 0x3069b20, indexCVS2Sprites_Nakoruru },
    { "Extra 1", 0x3069b20, 0x3069b40 },
    { "Extra 2", 0x3069b40, 0x3069b60 },
    { "Extra 3", 0x3069b60, 0x3069b80 },
    { "Extra 4", 0x3069b80, 0x3069ba0 },
    { "Extra 5", 0x3069ba0, 0x3069bc0 },
};

const sGame_PaletteDataset CVS2_A_NAKORURU_PALETTES_3K[] =
{
    { "Main Sprite", 0x3069bc0, 0x3069be0, indexCVS2Sprites_Nakoruru },
    { "Extra 1", 0x3069be0, 0x3069c00 },
    { "Extra 2", 0x3069c00, 0x3069c20 },
    { "Extra 3", 0x3069c20, 0x3069c40 },
    { "Extra 4", 0x3069c40, 0x3069c60 },
    { "Extra 5", 0x3069c60, 0x3069c80 },
};

const sDescTreeNode CVS2_A_NAKORURU_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_NAKORURU_PALETTES_LP, ARRAYSIZE(CVS2_A_NAKORURU_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_NAKORURU_PALETTES_MP, ARRAYSIZE(CVS2_A_NAKORURU_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_NAKORURU_PALETTES_HP, ARRAYSIZE(CVS2_A_NAKORURU_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_NAKORURU_PALETTES_LK, ARRAYSIZE(CVS2_A_NAKORURU_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_NAKORURU_PALETTES_MK, ARRAYSIZE(CVS2_A_NAKORURU_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_NAKORURU_PALETTES_HK, ARRAYSIZE(CVS2_A_NAKORURU_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_NAKORURU_PALETTES_3P, ARRAYSIZE(CVS2_A_NAKORURU_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_NAKORURU_PALETTES_3K, ARRAYSIZE(CVS2_A_NAKORURU_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_OROCHIIORI_PALETTES_LP[] =
{
    { "Main Sprite", 0x314b5a0, 0x314b5c0, indexCVS2Sprites_OrochiIori },
    { "Extra 1", 0x314b5c0, 0x314b5e0 },
    { "Extra 2", 0x314b5e0, 0x314b600 },
    { "Extra 3", 0x314b600, 0x314b620 },
    { "Extra 4", 0x314b620, 0x314b640 },
    { "Extra 5", 0x314b640, 0x314b660 },
};

const sGame_PaletteDataset CVS2_A_OROCHIIORI_PALETTES_MP[] =
{
    { "Main Sprite", 0x314b660, 0x314b680, indexCVS2Sprites_OrochiIori },
    { "Extra 1", 0x314b680, 0x314b6a0 },
    { "Extra 2", 0x314b6a0, 0x314b6c0 },
    { "Extra 3", 0x314b6c0, 0x314b6e0 },
    { "Extra 4", 0x314b6e0, 0x314b700 },
    { "Extra 5", 0x314b700, 0x314b720 },
};

const sGame_PaletteDataset CVS2_A_OROCHIIORI_PALETTES_HP[] =
{
    { "Main Sprite", 0x314b720, 0x314b740, indexCVS2Sprites_OrochiIori },
    { "Extra 1", 0x314b740, 0x314b760 },
    { "Extra 2", 0x314b760, 0x314b780 },
    { "Extra 3", 0x314b780, 0x314b7a0 },
    { "Extra 4", 0x314b7a0, 0x314b7c0 },
    { "Extra 5", 0x314b7c0, 0x314b7e0 },
};

const sGame_PaletteDataset CVS2_A_OROCHIIORI_PALETTES_LK[] =
{
    { "Main Sprite", 0x314b7e0, 0x314b800, indexCVS2Sprites_OrochiIori },
    { "Extra 1", 0x314b800, 0x314b820 },
    { "Extra 2", 0x314b820, 0x314b840 },
    { "Extra 3", 0x314b840, 0x314b860 },
    { "Extra 4", 0x314b860, 0x314b880 },
    { "Extra 5", 0x314b880, 0x314b8a0 },
};

const sGame_PaletteDataset CVS2_A_OROCHIIORI_PALETTES_MK[] =
{
    { "Main Sprite", 0x314b8a0, 0x314b8c0, indexCVS2Sprites_OrochiIori },
    { "Extra 1", 0x314b8c0, 0x314b8e0 },
    { "Extra 2", 0x314b8e0, 0x314b900 },
    { "Extra 3", 0x314b900, 0x314b920 },
    { "Extra 4", 0x314b920, 0x314b940 },
    { "Extra 5", 0x314b940, 0x314b960 },
};

const sGame_PaletteDataset CVS2_A_OROCHIIORI_PALETTES_HK[] =
{
    { "Main Sprite", 0x314b960, 0x314b980, indexCVS2Sprites_OrochiIori },
    { "Extra 1", 0x314b980, 0x314b9a0 },
    { "Extra 2", 0x314b9a0, 0x314b9c0 },
    { "Extra 3", 0x314b9c0, 0x314b9e0 },
    { "Extra 4", 0x314b9e0, 0x314ba00 },
    { "Extra 5", 0x314ba00, 0x314ba20 },
};

const sGame_PaletteDataset CVS2_A_OROCHIIORI_PALETTES_3P[] =
{
    { "Main Sprite", 0x314ba20, 0x314ba40, indexCVS2Sprites_OrochiIori },
    { "Extra 1", 0x314ba40, 0x314ba60 },
    { "Extra 2", 0x314ba60, 0x314ba80 },
    { "Extra 3", 0x314ba80, 0x314baa0 },
    { "Extra 4", 0x314baa0, 0x314bac0 },
    { "Extra 5", 0x314bac0, 0x314bae0 },
};

const sGame_PaletteDataset CVS2_A_OROCHIIORI_PALETTES_3K[] =
{
    { "Main Sprite", 0x314bae0, 0x314bb00, indexCVS2Sprites_OrochiIori },
    { "Extra 1", 0x314bb00, 0x314bb20 },
    { "Extra 2", 0x314bb20, 0x314bb40 },
    { "Extra 3", 0x314bb40, 0x314bb60 },
    { "Extra 4", 0x314bb60, 0x314bb80 },
    { "Extra 5", 0x314bb80, 0x314bba0 },
};

const sDescTreeNode CVS2_A_OROCHIIORI_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_OROCHIIORI_PALETTES_LP, ARRAYSIZE(CVS2_A_OROCHIIORI_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_OROCHIIORI_PALETTES_MP, ARRAYSIZE(CVS2_A_OROCHIIORI_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_OROCHIIORI_PALETTES_HP, ARRAYSIZE(CVS2_A_OROCHIIORI_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_OROCHIIORI_PALETTES_LK, ARRAYSIZE(CVS2_A_OROCHIIORI_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_OROCHIIORI_PALETTES_MK, ARRAYSIZE(CVS2_A_OROCHIIORI_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_OROCHIIORI_PALETTES_HK, ARRAYSIZE(CVS2_A_OROCHIIORI_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_OROCHIIORI_PALETTES_3P, ARRAYSIZE(CVS2_A_OROCHIIORI_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_OROCHIIORI_PALETTES_3K, ARRAYSIZE(CVS2_A_OROCHIIORI_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_BALROG_PALETTES_LP[] =
{
    { "Main Sprite", 0x31d3320, 0x31d3340, indexCVS2Sprites_Balrog },
    { "Extra 1", 0x31d3340, 0x31d3360 },
    { "Extra 2", 0x31d3360, 0x31d3380 },
    { "Extra 3", 0x31d3380, 0x31d33a0 },
    { "Extra 4", 0x31d33a0, 0x31d33c0 },
    { "Extra 5", 0x31d33c0, 0x31d33e0 },
};

const sGame_PaletteDataset CVS2_A_BALROG_PALETTES_MP[] =
{
    { "Main Sprite", 0x31d33e0, 0x31d3400, indexCVS2Sprites_Balrog },
    { "Extra 1", 0x31d3400, 0x31d3420 },
    { "Extra 2", 0x31d3420, 0x31d3440 },
    { "Extra 3", 0x31d3440, 0x31d3460 },
    { "Extra 4", 0x31d3460, 0x31d3480 },
    { "Extra 5", 0x31d3480, 0x31d34a0 },
};

const sGame_PaletteDataset CVS2_A_BALROG_PALETTES_HP[] =
{
    { "Main Sprite", 0x31d34a0, 0x31d34c0, indexCVS2Sprites_Balrog },
    { "Extra 1", 0x31d34c0, 0x31d34e0 },
    { "Extra 2", 0x31d34e0, 0x31d3500 },
    { "Extra 3", 0x31d3500, 0x31d3520 },
    { "Extra 4", 0x31d3520, 0x31d3540 },
    { "Extra 5", 0x31d3540, 0x31d3560 },
};

const sGame_PaletteDataset CVS2_A_BALROG_PALETTES_LK[] =
{
    { "Main Sprite", 0x31d3560, 0x31d3580, indexCVS2Sprites_Balrog },
    { "Extra 1", 0x31d3580, 0x31d35a0 },
    { "Extra 2", 0x31d35a0, 0x31d35c0 },
    { "Extra 3", 0x31d35c0, 0x31d35e0 },
    { "Extra 4", 0x31d35e0, 0x31d3600 },
    { "Extra 5", 0x31d3600, 0x31d3620 },
};

const sGame_PaletteDataset CVS2_A_BALROG_PALETTES_MK[] =
{
    { "Main Sprite", 0x31d3620, 0x31d3640, indexCVS2Sprites_Balrog },
    { "Extra 1", 0x31d3640, 0x31d3660 },
    { "Extra 2", 0x31d3660, 0x31d3680 },
    { "Extra 3", 0x31d3680, 0x31d36a0 },
    { "Extra 4", 0x31d36a0, 0x31d36c0 },
    { "Extra 5", 0x31d36c0, 0x31d36e0 },
};

const sGame_PaletteDataset CVS2_A_BALROG_PALETTES_HK[] =
{
    { "Main Sprite", 0x31d36e0, 0x31d3700, indexCVS2Sprites_Balrog },
    { "Extra 1", 0x31d3700, 0x31d3720 },
    { "Extra 2", 0x31d3720, 0x31d3740 },
    { "Extra 3", 0x31d3740, 0x31d3760 },
    { "Extra 4", 0x31d3760, 0x31d3780 },
    { "Extra 5", 0x31d3780, 0x31d37a0 },
};

const sGame_PaletteDataset CVS2_A_BALROG_PALETTES_3P[] =
{
    { "Main Sprite", 0x31d37a0, 0x31d37c0, indexCVS2Sprites_Balrog },
    { "Extra 1", 0x31d37c0, 0x31d37e0 },
    { "Extra 2", 0x31d37e0, 0x31d3800 },
    { "Extra 3", 0x31d3800, 0x31d3820 },
    { "Extra 4", 0x31d3820, 0x31d3840 },
    { "Extra 5", 0x31d3840, 0x31d3860 },
};

const sGame_PaletteDataset CVS2_A_BALROG_PALETTES_3K[] =
{
    { "Main Sprite", 0x31d3860, 0x31d3880, indexCVS2Sprites_Balrog },
    { "Extra 1", 0x31d3880, 0x31d38a0 },
    { "Extra 2", 0x31d38a0, 0x31d38c0 },
    { "Extra 3", 0x31d38c0, 0x31d38e0 },
    { "Extra 4", 0x31d38e0, 0x31d3900 },
    { "Extra 5", 0x31d3900, 0x31d3920 },
};

const sDescTreeNode CVS2_A_BALROG_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_BALROG_PALETTES_LP, ARRAYSIZE(CVS2_A_BALROG_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_BALROG_PALETTES_MP, ARRAYSIZE(CVS2_A_BALROG_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_BALROG_PALETTES_HP, ARRAYSIZE(CVS2_A_BALROG_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_BALROG_PALETTES_LK, ARRAYSIZE(CVS2_A_BALROG_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_BALROG_PALETTES_MK, ARRAYSIZE(CVS2_A_BALROG_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_BALROG_PALETTES_HK, ARRAYSIZE(CVS2_A_BALROG_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_BALROG_PALETTES_3P, ARRAYSIZE(CVS2_A_BALROG_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_BALROG_PALETTES_3K, ARRAYSIZE(CVS2_A_BALROG_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_DAN_PALETTES_LP[] =
{
    { "Main Sprite", 0x328c960, 0x328c980, indexCVS2Sprites_Dan },
    { "Extra 1", 0x328c980, 0x328c9a0 },
    { "Extra 2", 0x328c9a0, 0x328c9c0 },
    { "Extra 3", 0x328c9c0, 0x328c9e0 },
    { "Extra 4", 0x328c9e0, 0x328ca00 },
    { "Extra 5", 0x328ca00, 0x328ca20 },
};

const sGame_PaletteDataset CVS2_A_DAN_PALETTES_MP[] =
{
    { "Main Sprite", 0x328ca20, 0x328ca40, indexCVS2Sprites_Dan },
    { "Extra 1", 0x328ca40, 0x328ca60 },
    { "Extra 2", 0x328ca60, 0x328ca80 },
    { "Extra 3", 0x328ca80, 0x328caa0 },
    { "Extra 4", 0x328caa0, 0x328cac0 },
    { "Extra 5", 0x328cac0, 0x328cae0 },
};

const sGame_PaletteDataset CVS2_A_DAN_PALETTES_HP[] =
{
    { "Main Sprite", 0x328cae0, 0x328cb00, indexCVS2Sprites_Dan },
    { "Extra 1", 0x328cb00, 0x328cb20 },
    { "Extra 2", 0x328cb20, 0x328cb40 },
    { "Extra 3", 0x328cb40, 0x328cb60 },
    { "Extra 4", 0x328cb60, 0x328cb80 },
    { "Extra 5", 0x328cb80, 0x328cba0 },
};

const sGame_PaletteDataset CVS2_A_DAN_PALETTES_LK[] =
{
    { "Main Sprite", 0x328cba0, 0x328cbc0, indexCVS2Sprites_Dan },
    { "Extra 1", 0x328cbc0, 0x328cbe0 },
    { "Extra 2", 0x328cbe0, 0x328cc00 },
    { "Extra 3", 0x328cc00, 0x328cc20 },
    { "Extra 4", 0x328cc20, 0x328cc40 },
    { "Extra 5", 0x328cc40, 0x328cc60 },
};

const sGame_PaletteDataset CVS2_A_DAN_PALETTES_MK[] =
{
    { "Main Sprite", 0x328cc60, 0x328cc80, indexCVS2Sprites_Dan },
    { "Extra 1", 0x328cc80, 0x328cca0 },
    { "Extra 2", 0x328cca0, 0x328ccc0 },
    { "Extra 3", 0x328ccc0, 0x328cce0 },
    { "Extra 4", 0x328cce0, 0x328cd00 },
    { "Extra 5", 0x328cd00, 0x328cd20 },
};

const sGame_PaletteDataset CVS2_A_DAN_PALETTES_HK[] =
{
    { "Main Sprite", 0x328cd20, 0x328cd40, indexCVS2Sprites_Dan },
    { "Extra 1", 0x328cd40, 0x328cd60 },
    { "Extra 2", 0x328cd60, 0x328cd80 },
    { "Extra 3", 0x328cd80, 0x328cda0 },
    { "Extra 4", 0x328cda0, 0x328cdc0 },
    { "Extra 5", 0x328cdc0, 0x328cde0 },
};

const sGame_PaletteDataset CVS2_A_DAN_PALETTES_3P[] =
{
    { "Main Sprite", 0x328cde0, 0x328ce00, indexCVS2Sprites_Dan },
    { "Extra 1", 0x328ce00, 0x328ce20 },
    { "Extra 2", 0x328ce20, 0x328ce40 },
    { "Extra 3", 0x328ce40, 0x328ce60 },
    { "Extra 4", 0x328ce60, 0x328ce80 },
    { "Extra 5", 0x328ce80, 0x328cea0 },
};

const sGame_PaletteDataset CVS2_A_DAN_PALETTES_3K[] =
{
    { "Main Sprite", 0x328cea0, 0x328cec0, indexCVS2Sprites_Dan },
    { "Extra 1", 0x328cec0, 0x328cee0 },
    { "Extra 2", 0x328cee0, 0x328cf00 },
    { "Extra 3", 0x328cf00, 0x328cf20 },
    { "Extra 4", 0x328cf20, 0x328cf40 },
    { "Extra 5", 0x328cf40, 0x328cf60 },
};

const sDescTreeNode CVS2_A_DAN_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_DAN_PALETTES_LP, ARRAYSIZE(CVS2_A_DAN_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_DAN_PALETTES_MP, ARRAYSIZE(CVS2_A_DAN_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_DAN_PALETTES_HP, ARRAYSIZE(CVS2_A_DAN_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_DAN_PALETTES_LK, ARRAYSIZE(CVS2_A_DAN_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_DAN_PALETTES_MK, ARRAYSIZE(CVS2_A_DAN_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_DAN_PALETTES_HK, ARRAYSIZE(CVS2_A_DAN_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_DAN_PALETTES_3P, ARRAYSIZE(CVS2_A_DAN_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_DAN_PALETTES_3K, ARRAYSIZE(CVS2_A_DAN_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_Joe_PALETTES_LP[] =
{
    { "Main Sprite", 0x3344620, 0x3344640, indexCVS2Sprites_Joe },
    { "Extra 1", 0x3344640, 0x3344660 },
    { "Extra 2", 0x3344660, 0x3344680 },
    { "Extra 3", 0x3344680, 0x33446a0 },
    { "Extra 4", 0x33446a0, 0x33446c0 },
    { "Extra 5", 0x33446c0, 0x33446e0 },
};

const sGame_PaletteDataset CVS2_A_Joe_PALETTES_MP[] =
{
    { "Main Sprite", 0x33446e0, 0x3344700, indexCVS2Sprites_Joe },
    { "Extra 1", 0x3344700, 0x3344720 },
    { "Extra 2", 0x3344720, 0x3344740 },
    { "Extra 3", 0x3344740, 0x3344760 },
    { "Extra 4", 0x3344760, 0x3344780 },
    { "Extra 5", 0x3344780, 0x33447a0 },
};

const sGame_PaletteDataset CVS2_A_Joe_PALETTES_HP[] =
{
    { "Main Sprite", 0x33447a0, 0x33447c0, indexCVS2Sprites_Joe },
    { "Extra 1", 0x33447c0, 0x33447e0 },
    { "Extra 2", 0x33447e0, 0x3344800 },
    { "Extra 3", 0x3344800, 0x3344820 },
    { "Extra 4", 0x3344820, 0x3344840 },
    { "Extra 5", 0x3344840, 0x3344860 },
};

const sGame_PaletteDataset CVS2_A_Joe_PALETTES_LK[] =
{
    { "Main Sprite", 0x3344860, 0x3344880, indexCVS2Sprites_Joe },
    { "Extra 1", 0x3344880, 0x33448a0 },
    { "Extra 2", 0x33448a0, 0x33448c0 },
    { "Extra 3", 0x33448c0, 0x33448e0 },
    { "Extra 4", 0x33448e0, 0x3344900 },
    { "Extra 5", 0x3344900, 0x3344920 },
};

const sGame_PaletteDataset CVS2_A_Joe_PALETTES_MK[] =
{
    { "Main Sprite", 0x3344920, 0x3344940, indexCVS2Sprites_Joe },
    { "Extra 1", 0x3344940, 0x3344960 },
    { "Extra 2", 0x3344960, 0x3344980 },
    { "Extra 3", 0x3344980, 0x33449a0 },
    { "Extra 4", 0x33449a0, 0x33449c0 },
    { "Extra 5", 0x33449c0, 0x33449e0 },
};

const sGame_PaletteDataset CVS2_A_Joe_PALETTES_HK[] =
{
    { "Main Sprite", 0x33449e0, 0x3344a00, indexCVS2Sprites_Joe },
    { "Extra 1", 0x3344a00, 0x3344a20 },
    { "Extra 2", 0x3344a20, 0x3344a40 },
    { "Extra 3", 0x3344a40, 0x3344a60 },
    { "Extra 4", 0x3344a60, 0x3344a80 },
    { "Extra 5", 0x3344a80, 0x3344aa0 },
};

const sGame_PaletteDataset CVS2_A_Joe_PALETTES_3P[] =
{
    { "Main Sprite", 0x3344aa0, 0x3344ac0, indexCVS2Sprites_Joe },
    { "Extra 1", 0x3344ac0, 0x3344ae0 },
    { "Extra 2", 0x3344ae0, 0x3344b00 },
    { "Extra 3", 0x3344b00, 0x3344b20 },
    { "Extra 4", 0x3344b20, 0x3344b40 },
    { "Extra 5", 0x3344b40, 0x3344b60 },
};

const sGame_PaletteDataset CVS2_A_Joe_PALETTES_3K[] =
{
    { "Main Sprite", 0x3344b60, 0x3344b80, indexCVS2Sprites_Joe },
    { "Extra 1", 0x3344b80, 0x3344ba0 },
    { "Extra 2", 0x3344ba0, 0x3344bc0 },
    { "Extra 3", 0x3344bc0, 0x3344be0 },
    { "Extra 4", 0x3344be0, 0x3344c00 },
    { "Extra 5", 0x3344c00, 0x3344c20 },
};

const sDescTreeNode CVS2_A_Joe_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_Joe_PALETTES_LP, ARRAYSIZE(CVS2_A_Joe_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_Joe_PALETTES_MP, ARRAYSIZE(CVS2_A_Joe_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_Joe_PALETTES_HP, ARRAYSIZE(CVS2_A_Joe_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_Joe_PALETTES_LK, ARRAYSIZE(CVS2_A_Joe_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_Joe_PALETTES_MK, ARRAYSIZE(CVS2_A_Joe_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_Joe_PALETTES_HK, ARRAYSIZE(CVS2_A_Joe_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_Joe_PALETTES_3P, ARRAYSIZE(CVS2_A_Joe_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_Joe_PALETTES_3K, ARRAYSIZE(CVS2_A_Joe_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_EAGLE_PALETTES_LP[] =
{
    { "Main Sprite", 0x342f920, 0x342f940, indexCVS2Sprites_Eagle },
    { "Extra 1", 0x342f940, 0x342f960 },
    { "Extra 2", 0x342f960, 0x342f980 },
    { "Extra 3", 0x342f980, 0x342f9a0 },
    { "Extra 4", 0x342f9a0, 0x342f9c0 },
    { "Extra 5", 0x342f9c0, 0x342f9e0 },
};

const sGame_PaletteDataset CVS2_A_EAGLE_PALETTES_MP[] =
{
    { "Main Sprite", 0x342f9e0, 0x342fa00, indexCVS2Sprites_Eagle },
    { "Extra 1", 0x342fa00, 0x342fa20 },
    { "Extra 2", 0x342fa20, 0x342fa40 },
    { "Extra 3", 0x342fa40, 0x342fa60 },
    { "Extra 4", 0x342fa60, 0x342fa80 },
    { "Extra 5", 0x342fa80, 0x342faa0 },
};

const sGame_PaletteDataset CVS2_A_EAGLE_PALETTES_HP[] =
{
    { "Main Sprite", 0x342faa0, 0x342fac0, indexCVS2Sprites_Eagle },
    { "Extra 1", 0x342fac0, 0x342fae0 },
    { "Extra 2", 0x342fae0, 0x342fb00 },
    { "Extra 3", 0x342fb00, 0x342fb20 },
    { "Extra 4", 0x342fb20, 0x342fb40 },
    { "Extra 5", 0x342fb40, 0x342fb60 },
};

const sGame_PaletteDataset CVS2_A_EAGLE_PALETTES_LK[] =
{
    { "Main Sprite", 0x342fb60, 0x342fb80, indexCVS2Sprites_Eagle },
    { "Extra 1", 0x342fb80, 0x342fba0 },
    { "Extra 2", 0x342fba0, 0x342fbc0 },
    { "Extra 3", 0x342fbc0, 0x342fbe0 },
    { "Extra 4", 0x342fbe0, 0x342fc00 },
    { "Extra 5", 0x342fc00, 0x342fc20 },
};

const sGame_PaletteDataset CVS2_A_EAGLE_PALETTES_MK[] =
{
    { "Main Sprite", 0x342fc20, 0x342fc40, indexCVS2Sprites_Eagle },
    { "Extra 1", 0x342fc40, 0x342fc60 },
    { "Extra 2", 0x342fc60, 0x342fc80 },
    { "Extra 3", 0x342fc80, 0x342fca0 },
    { "Extra 4", 0x342fca0, 0x342fcc0 },
    { "Extra 5", 0x342fcc0, 0x342fce0 },
};

const sGame_PaletteDataset CVS2_A_EAGLE_PALETTES_HK[] =
{
    { "Main Sprite", 0x342fce0, 0x342fd00, indexCVS2Sprites_Eagle },
    { "Extra 1", 0x342fd00, 0x342fd20 },
    { "Extra 2", 0x342fd20, 0x342fd40 },
    { "Extra 3", 0x342fd40, 0x342fd60 },
    { "Extra 4", 0x342fd60, 0x342fd80 },
    { "Extra 5", 0x342fd80, 0x342fda0 },
};

const sGame_PaletteDataset CVS2_A_EAGLE_PALETTES_3P[] =
{
    { "Main Sprite", 0x342fda0, 0x342fdc0, indexCVS2Sprites_Eagle },
    { "Extra 1", 0x342fdc0, 0x342fde0 },
    { "Extra 2", 0x342fde0, 0x342fe00 },
    { "Extra 3", 0x342fe00, 0x342fe20 },
    { "Extra 4", 0x342fe20, 0x342fe40 },
    { "Extra 5", 0x342fe40, 0x342fe60 },
};

const sGame_PaletteDataset CVS2_A_EAGLE_PALETTES_3K[] =
{
    { "Main Sprite", 0x342fe60, 0x342fe80, indexCVS2Sprites_Eagle },
    { "Extra 1", 0x342fe80, 0x342fea0 },
    { "Extra 2", 0x342fea0, 0x342fec0 },
    { "Extra 3", 0x342fec0, 0x342fee0 },
    { "Extra 4", 0x342fee0, 0x342ff00 },
    { "Extra 5", 0x342ff00, 0x342ff20 },
};

const sDescTreeNode CVS2_A_EAGLE_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_EAGLE_PALETTES_LP, ARRAYSIZE(CVS2_A_EAGLE_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_EAGLE_PALETTES_MP, ARRAYSIZE(CVS2_A_EAGLE_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_EAGLE_PALETTES_HP, ARRAYSIZE(CVS2_A_EAGLE_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_EAGLE_PALETTES_LK, ARRAYSIZE(CVS2_A_EAGLE_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_EAGLE_PALETTES_MK, ARRAYSIZE(CVS2_A_EAGLE_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_EAGLE_PALETTES_HK, ARRAYSIZE(CVS2_A_EAGLE_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_EAGLE_PALETTES_3P, ARRAYSIZE(CVS2_A_EAGLE_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_EAGLE_PALETTES_3K, ARRAYSIZE(CVS2_A_EAGLE_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_MAKI_PALETTES_LP[] =
{
    { "Main Sprite", 0x34f71a0, 0x34f71c0, indexCVS2Sprites_Maki },
    { "Extra 1", 0x34f71c0, 0x34f71e0 },
    { "Extra 2", 0x34f71e0, 0x34f7200 },
    { "Extra 3", 0x34f7200, 0x34f7220 },
    { "Extra 4", 0x34f7220, 0x34f7240 },
    { "Extra 5", 0x34f7240, 0x34f7260 },
};

const sGame_PaletteDataset CVS2_A_MAKI_PALETTES_MP[] =
{
    { "Main Sprite", 0x34f7260, 0x34f7280, indexCVS2Sprites_Maki },
    { "Extra 1", 0x34f7280, 0x34f72a0 },
    { "Extra 2", 0x34f72a0, 0x34f72c0 },
    { "Extra 3", 0x34f72c0, 0x34f72e0 },
    { "Extra 4", 0x34f72e0, 0x34f7300 },
    { "Extra 5", 0x34f7300, 0x34f7320 },
};

const sGame_PaletteDataset CVS2_A_MAKI_PALETTES_HP[] =
{
    { "Main Sprite", 0x34f7320, 0x34f7340, indexCVS2Sprites_Maki },
    { "Extra 1", 0x34f7340, 0x34f7360 },
    { "Extra 2", 0x34f7360, 0x34f7380 },
    { "Extra 3", 0x34f7380, 0x34f73a0 },
    { "Extra 4", 0x34f73a0, 0x34f73c0 },
    { "Extra 5", 0x34f73c0, 0x34f73e0 },
};

const sGame_PaletteDataset CVS2_A_MAKI_PALETTES_LK[] =
{
    { "Main Sprite", 0x34f73e0, 0x34f7400, indexCVS2Sprites_Maki },
    { "Extra 1", 0x34f7400, 0x34f7420 },
    { "Extra 2", 0x34f7420, 0x34f7440 },
    { "Extra 3", 0x34f7440, 0x34f7460 },
    { "Extra 4", 0x34f7460, 0x34f7480 },
    { "Extra 5", 0x34f7480, 0x34f74a0 },
};

const sGame_PaletteDataset CVS2_A_MAKI_PALETTES_MK[] =
{
    { "Main Sprite", 0x34f74a0, 0x34f74c0, indexCVS2Sprites_Maki },
    { "Extra 1", 0x34f74c0, 0x34f74e0 },
    { "Extra 2", 0x34f74e0, 0x34f7500 },
    { "Extra 3", 0x34f7500, 0x34f7520 },
    { "Extra 4", 0x34f7520, 0x34f7540 },
    { "Extra 5", 0x34f7540, 0x34f7560 },
};

const sGame_PaletteDataset CVS2_A_MAKI_PALETTES_HK[] =
{
    { "Main Sprite", 0x34f7560, 0x34f7580, indexCVS2Sprites_Maki },
    { "Extra 1", 0x34f7580, 0x34f75a0 },
    { "Extra 2", 0x34f75a0, 0x34f75c0 },
    { "Extra 3", 0x34f75c0, 0x34f75e0 },
    { "Extra 4", 0x34f75e0, 0x34f7600 },
    { "Extra 5", 0x34f7600, 0x34f7620 },
};

const sGame_PaletteDataset CVS2_A_MAKI_PALETTES_3P[] =
{
    { "Main Sprite", 0x34f7620, 0x34f7640, indexCVS2Sprites_Maki },
    { "Extra 1", 0x34f7640, 0x34f7660 },
    { "Extra 2", 0x34f7660, 0x34f7680 },
    { "Extra 3", 0x34f7680, 0x34f76a0 },
    { "Extra 4", 0x34f76a0, 0x34f76c0 },
    { "Extra 5", 0x34f76c0, 0x34f76e0 },
};

const sGame_PaletteDataset CVS2_A_MAKI_PALETTES_3K[] =
{
    { "Main Sprite", 0x34f76e0, 0x34f7700, indexCVS2Sprites_Maki },
    { "Extra 1", 0x34f7700, 0x34f7720 },
    { "Extra 2", 0x34f7720, 0x34f7740 },
    { "Extra 3", 0x34f7740, 0x34f7760 },
    { "Extra 4", 0x34f7760, 0x34f7780 },
    { "Extra 5", 0x34f7780, 0x34f77a0 },
};

const sDescTreeNode CVS2_A_MAKI_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_MAKI_PALETTES_LP, ARRAYSIZE(CVS2_A_MAKI_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_MAKI_PALETTES_MP, ARRAYSIZE(CVS2_A_MAKI_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_MAKI_PALETTES_HP, ARRAYSIZE(CVS2_A_MAKI_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_MAKI_PALETTES_LK, ARRAYSIZE(CVS2_A_MAKI_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_MAKI_PALETTES_MK, ARRAYSIZE(CVS2_A_MAKI_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_MAKI_PALETTES_HK, ARRAYSIZE(CVS2_A_MAKI_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_MAKI_PALETTES_3P, ARRAYSIZE(CVS2_A_MAKI_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_MAKI_PALETTES_3K, ARRAYSIZE(CVS2_A_MAKI_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_KYOSUKE_PALETTES_LP[] =
{
    { "Main Sprite", 0x36134a0, 0x36134c0, indexCVS2Sprites_Kyosuke },
    { "Extra 1", 0x36134c0, 0x36134e0 },
    { "Extra 2", 0x36134e0, 0x3613500 },
    { "Extra 3", 0x3613500, 0x3613520 },
    { "Extra 4", 0x3613520, 0x3613540 },
    { "Extra 5", 0x3613540, 0x3613560 },
};

const sGame_PaletteDataset CVS2_A_KYOSUKE_PALETTES_MP[] =
{
    { "Main Sprite", 0x3613560, 0x3613580, indexCVS2Sprites_Kyosuke },
    { "Extra 1", 0x3613580, 0x36135a0 },
    { "Extra 2", 0x36135a0, 0x36135c0 },
    { "Extra 3", 0x36135c0, 0x36135e0 },
    { "Extra 4", 0x36135e0, 0x3613600 },
    { "Extra 5", 0x3613600, 0x3613620 },
};

const sGame_PaletteDataset CVS2_A_KYOSUKE_PALETTES_HP[] =
{
    { "Main Sprite", 0x3613620, 0x3613640, indexCVS2Sprites_Kyosuke },
    { "Extra 1", 0x3613640, 0x3613660 },
    { "Extra 2", 0x3613660, 0x3613680 },
    { "Extra 3", 0x3613680, 0x36136a0 },
    { "Extra 4", 0x36136a0, 0x36136c0 },
    { "Extra 5", 0x36136c0, 0x36136e0 },
};

const sGame_PaletteDataset CVS2_A_KYOSUKE_PALETTES_LK[] =
{
    { "Main Sprite", 0x36136e0, 0x3613700, indexCVS2Sprites_Kyosuke },
    { "Extra 1", 0x3613700, 0x3613720 },
    { "Extra 2", 0x3613720, 0x3613740 },
    { "Extra 3", 0x3613740, 0x3613760 },
    { "Extra 4", 0x3613760, 0x3613780 },
    { "Extra 5", 0x3613780, 0x36137a0 },
};

const sGame_PaletteDataset CVS2_A_KYOSUKE_PALETTES_MK[] =
{
    { "Main Sprite", 0x36137a0, 0x36137c0, indexCVS2Sprites_Kyosuke },
    { "Extra 1", 0x36137c0, 0x36137e0 },
    { "Extra 2", 0x36137e0, 0x3613800 },
    { "Extra 3", 0x3613800, 0x3613820 },
    { "Extra 4", 0x3613820, 0x3613840 },
    { "Extra 5", 0x3613840, 0x3613860 },
};

const sGame_PaletteDataset CVS2_A_KYOSUKE_PALETTES_HK[] =
{
    { "Main Sprite", 0x3613860, 0x3613880, indexCVS2Sprites_Kyosuke },
    { "Extra 1", 0x3613880, 0x36138a0 },
    { "Extra 2", 0x36138a0, 0x36138c0 },
    { "Extra 3", 0x36138c0, 0x36138e0 },
    { "Extra 4", 0x36138e0, 0x3613900 },
    { "Extra 5", 0x3613900, 0x3613920 },
};

const sGame_PaletteDataset CVS2_A_KYOSUKE_PALETTES_3P[] =
{
    { "Main Sprite", 0x3613920, 0x3613940, indexCVS2Sprites_Kyosuke },
    { "Extra 1", 0x3613940, 0x3613960 },
    { "Extra 2", 0x3613960, 0x3613980 },
    { "Extra 3", 0x3613980, 0x36139a0 },
    { "Extra 4", 0x36139a0, 0x36139c0 },
    { "Extra 5", 0x36139c0, 0x36139e0 },
};

const sGame_PaletteDataset CVS2_A_KYOSUKE_PALETTES_3K[] =
{
    { "Main Sprite", 0x36139e0, 0x3613a00, indexCVS2Sprites_Kyosuke },
    { "Extra 1", 0x3613a00, 0x3613a20 },
    { "Extra 2", 0x3613a20, 0x3613a40 },
    { "Extra 3", 0x3613a40, 0x3613a60 },
    { "Extra 4", 0x3613a60, 0x3613a80 },
    { "Extra 5", 0x3613a80, 0x3613aa0 },
};

const sDescTreeNode CVS2_A_KYOSUKE_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_KYOSUKE_PALETTES_LP, ARRAYSIZE(CVS2_A_KYOSUKE_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_KYOSUKE_PALETTES_MP, ARRAYSIZE(CVS2_A_KYOSUKE_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_KYOSUKE_PALETTES_HP, ARRAYSIZE(CVS2_A_KYOSUKE_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_KYOSUKE_PALETTES_LK, ARRAYSIZE(CVS2_A_KYOSUKE_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_KYOSUKE_PALETTES_MK, ARRAYSIZE(CVS2_A_KYOSUKE_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_KYOSUKE_PALETTES_HK, ARRAYSIZE(CVS2_A_KYOSUKE_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_KYOSUKE_PALETTES_3P, ARRAYSIZE(CVS2_A_KYOSUKE_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_KYOSUKE_PALETTES_3K, ARRAYSIZE(CVS2_A_KYOSUKE_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_ATHENA_PALETTES_LP[] =
{
    { "Main Sprite", 0x36e48a0, 0x36e48c0, indexCVS2Sprites_Athena },
    { "Extra 1", 0x36e48c0, 0x36e48e0 },
    { "Extra 2", 0x36e48e0, 0x36e4900 },
    { "Extra 3", 0x36e4900, 0x36e4920 },
    { "Extra 4", 0x36e4920, 0x36e4940 },
    { "Extra 5", 0x36e4940, 0x36e4960 },
};

const sGame_PaletteDataset CVS2_A_ATHENA_PALETTES_MP[] =
{
    { "Main Sprite", 0x36e4960, 0x36e4980, indexCVS2Sprites_Athena },
    { "Extra 1", 0x36e4980, 0x36e49a0 },
    { "Extra 2", 0x36e49a0, 0x36e49c0 },
    { "Extra 3", 0x36e49c0, 0x36e49e0 },
    { "Extra 4", 0x36e49e0, 0x36e4a00 },
    { "Extra 5", 0x36e4a00, 0x36e4a20 },
};

const sGame_PaletteDataset CVS2_A_ATHENA_PALETTES_HP[] =
{
    { "Main Sprite", 0x36e4a20, 0x36e4a40, indexCVS2Sprites_Athena },
    { "Extra 1", 0x36e4a40, 0x36e4a60 },
    { "Extra 2", 0x36e4a60, 0x36e4a80 },
    { "Extra 3", 0x36e4a80, 0x36e4aa0 },
    { "Extra 4", 0x36e4aa0, 0x36e4ac0 },
    { "Extra 5", 0x36e4ac0, 0x36e4ae0 },
};

const sGame_PaletteDataset CVS2_A_ATHENA_PALETTES_LK[] =
{
    { "Main Sprite", 0x36e4ae0, 0x36e4b00, indexCVS2Sprites_Athena },
    { "Extra 1", 0x36e4b00, 0x36e4b20 },
    { "Extra 2", 0x36e4b20, 0x36e4b40 },
    { "Extra 3", 0x36e4b40, 0x36e4b60 },
    { "Extra 4", 0x36e4b60, 0x36e4b80 },
    { "Extra 5", 0x36e4b80, 0x36e4ba0 },
};

const sGame_PaletteDataset CVS2_A_ATHENA_PALETTES_MK[] =
{
    { "Main Sprite", 0x36e4ba0, 0x36e4bc0, indexCVS2Sprites_Athena },
    { "Extra 1", 0x36e4bc0, 0x36e4be0 },
    { "Extra 2", 0x36e4be0, 0x36e4c00 },
    { "Extra 3", 0x36e4c00, 0x36e4c20 },
    { "Extra 4", 0x36e4c20, 0x36e4c40 },
    { "Extra 5", 0x36e4c40, 0x36e4c60 },
};

const sGame_PaletteDataset CVS2_A_ATHENA_PALETTES_HK[] =
{
    { "Main Sprite", 0x36e4c60, 0x36e4c80, indexCVS2Sprites_Athena },
    { "Extra 1", 0x36e4c80, 0x36e4ca0 },
    { "Extra 2", 0x36e4ca0, 0x36e4cc0 },
    { "Extra 3", 0x36e4cc0, 0x36e4ce0 },
    { "Extra 4", 0x36e4ce0, 0x36e4d00 },
    { "Extra 5", 0x36e4d00, 0x36e4d20 },
};

const sGame_PaletteDataset CVS2_A_ATHENA_PALETTES_3P[] =
{
    { "Main Sprite", 0x36e4d20, 0x36e4d40, indexCVS2Sprites_Athena },
    { "Extra 1", 0x36e4d40, 0x36e4d60 },
    { "Extra 2", 0x36e4d60, 0x36e4d80 },
    { "Extra 3", 0x36e4d80, 0x36e4da0 },
    { "Extra 4", 0x36e4da0, 0x36e4dc0 },
    { "Extra 5", 0x36e4dc0, 0x36e4de0 },
};

const sGame_PaletteDataset CVS2_A_ATHENA_PALETTES_3K[] =
{
    { "Main Sprite", 0x36e4de0, 0x36e4e00, indexCVS2Sprites_Athena },
    { "Extra 1", 0x36e4e00, 0x36e4e20 },
    { "Extra 2", 0x36e4e20, 0x36e4e40 },
    { "Extra 3", 0x36e4e40, 0x36e4e60 },
    { "Extra 4", 0x36e4e60, 0x36e4e80 },
    { "Extra 5", 0x36e4e80, 0x36e4ea0 },
};

const sDescTreeNode CVS2_A_ATHENA_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_ATHENA_PALETTES_LP, ARRAYSIZE(CVS2_A_ATHENA_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_ATHENA_PALETTES_MP, ARRAYSIZE(CVS2_A_ATHENA_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_ATHENA_PALETTES_HP, ARRAYSIZE(CVS2_A_ATHENA_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_ATHENA_PALETTES_LK, ARRAYSIZE(CVS2_A_ATHENA_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_ATHENA_PALETTES_MK, ARRAYSIZE(CVS2_A_ATHENA_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_ATHENA_PALETTES_HK, ARRAYSIZE(CVS2_A_ATHENA_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_ATHENA_PALETTES_3P, ARRAYSIZE(CVS2_A_ATHENA_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_ATHENA_PALETTES_3K, ARRAYSIZE(CVS2_A_ATHENA_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_CHANG_PALETTES_LP[] =
{
    { "Main Sprite", 0x38111a0, 0x38111c0, indexCVS2Sprites_Chang },
    { "Extra 1", 0x38111c0, 0x38111e0 },
    { "Extra 2", 0x38111e0, 0x3811200 },
    { "Extra 3", 0x3811200, 0x3811220 },
    { "Extra 4", 0x3811220, 0x3811240 },
    { "Extra 5", 0x3811240, 0x3811260 },
};

const sGame_PaletteDataset CVS2_A_CHANG_PALETTES_MP[] =
{
    { "Main Sprite", 0x3811260, 0x3811280, indexCVS2Sprites_Chang },
    { "Extra 1", 0x3811280, 0x38112a0 },
    { "Extra 2", 0x38112a0, 0x38112c0 },
    { "Extra 3", 0x38112c0, 0x38112e0 },
    { "Extra 4", 0x38112e0, 0x3811300 },
    { "Extra 5", 0x3811300, 0x3811320 },
};

const sGame_PaletteDataset CVS2_A_CHANG_PALETTES_HP[] =
{
    { "Main Sprite", 0x3811320, 0x3811340, indexCVS2Sprites_Chang },
    { "Extra 1", 0x3811340, 0x3811360 },
    { "Extra 2", 0x3811360, 0x3811380 },
    { "Extra 3", 0x3811380, 0x38113a0 },
    { "Extra 4", 0x38113a0, 0x38113c0 },
    { "Extra 5", 0x38113c0, 0x38113e0 },
};

const sGame_PaletteDataset CVS2_A_CHANG_PALETTES_LK[] =
{
    { "Main Sprite", 0x38113e0, 0x3811400, indexCVS2Sprites_Chang },
    { "Extra 1", 0x3811400, 0x3811420 },
    { "Extra 2", 0x3811420, 0x3811440 },
    { "Extra 3", 0x3811440, 0x3811460 },
    { "Extra 4", 0x3811460, 0x3811480 },
    { "Extra 5", 0x3811480, 0x38114a0 },
};

const sGame_PaletteDataset CVS2_A_CHANG_PALETTES_MK[] =
{
    { "Main Sprite", 0x38114a0, 0x38114c0, indexCVS2Sprites_Chang },
    { "Extra 1", 0x38114c0, 0x38114e0 },
    { "Extra 2", 0x38114e0, 0x3811500 },
    { "Extra 3", 0x3811500, 0x3811520 },
    { "Extra 4", 0x3811520, 0x3811540 },
    { "Extra 5", 0x3811540, 0x3811560 },
};

const sGame_PaletteDataset CVS2_A_CHANG_PALETTES_HK[] =
{
    { "Main Sprite", 0x3811560, 0x3811580, indexCVS2Sprites_Chang },
    { "Extra 1", 0x3811580, 0x38115a0 },
    { "Extra 2", 0x38115a0, 0x38115c0 },
    { "Extra 3", 0x38115c0, 0x38115e0 },
    { "Extra 4", 0x38115e0, 0x3811600 },
    { "Extra 5", 0x3811600, 0x3811620 },
};

const sGame_PaletteDataset CVS2_A_CHANG_PALETTES_3P[] =
{
    { "Main Sprite", 0x3811620, 0x3811640, indexCVS2Sprites_Chang },
    { "Extra 1", 0x3811640, 0x3811660 },
    { "Extra 2", 0x3811660, 0x3811680 },
    { "Extra 3", 0x3811680, 0x38116a0 },
    { "Extra 4", 0x38116a0, 0x38116c0 },
    { "Extra 5", 0x38116c0, 0x38116e0 },
};

const sGame_PaletteDataset CVS2_A_CHANG_PALETTES_3K[] =
{
    { "Main Sprite", 0x38116e0, 0x3811700, indexCVS2Sprites_Chang },
    { "Extra 1", 0x3811700, 0x3811720 },
    { "Extra 2", 0x3811720, 0x3811740 },
    { "Extra 3", 0x3811740, 0x3811760 },
    { "Extra 4", 0x3811760, 0x3811780 },
    { "Extra 5", 0x3811780, 0x38117a0 },
};

const sDescTreeNode CVS2_A_CHANG_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_CHANG_PALETTES_LP, ARRAYSIZE(CVS2_A_CHANG_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_CHANG_PALETTES_MP, ARRAYSIZE(CVS2_A_CHANG_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_CHANG_PALETTES_HP, ARRAYSIZE(CVS2_A_CHANG_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_CHANG_PALETTES_LK, ARRAYSIZE(CVS2_A_CHANG_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_CHANG_PALETTES_MK, ARRAYSIZE(CVS2_A_CHANG_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_CHANG_PALETTES_HK, ARRAYSIZE(CVS2_A_CHANG_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_CHANG_PALETTES_3P, ARRAYSIZE(CVS2_A_CHANG_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_CHANG_PALETTES_3K, ARRAYSIZE(CVS2_A_CHANG_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_TODOH_PALETTES_LP[] =
{
    { "Main Sprite", 0x38fc140, 0x38fc160, indexCVS2Sprites_RyuhakuTodoh },
    { "Extra 1", 0x38fc160, 0x38fc180 },
    { "Extra 2", 0x38fc180, 0x38fc1a0 },
    { "Extra 3", 0x38fc1a0, 0x38fc1c0 },
    { "Extra 4", 0x38fc1c0, 0x38fc1e0 },
    { "Extra 5", 0x38fc1e0, 0x38fc200 },
};

const sGame_PaletteDataset CVS2_A_TODOH_PALETTES_MP[] =
{
    { "Main Sprite", 0x38fc200, 0x38fc220, indexCVS2Sprites_RyuhakuTodoh },
    { "Extra 1", 0x38fc220, 0x38fc240 },
    { "Extra 2", 0x38fc240, 0x38fc260 },
    { "Extra 3", 0x38fc260, 0x38fc280 },
    { "Extra 4", 0x38fc280, 0x38fc2a0 },
    { "Extra 5", 0x38fc2a0, 0x38fc2c0 },
};

const sGame_PaletteDataset CVS2_A_TODOH_PALETTES_HP[] =
{
    { "Main Sprite", 0x38fc2c0, 0x38fc2e0, indexCVS2Sprites_RyuhakuTodoh },
    { "Extra 1", 0x38fc2e0, 0x38fc300 },
    { "Extra 2", 0x38fc300, 0x38fc320 },
    { "Extra 3", 0x38fc320, 0x38fc340 },
    { "Extra 4", 0x38fc340, 0x38fc360 },
    { "Extra 5", 0x38fc360, 0x38fc380 },
};

const sGame_PaletteDataset CVS2_A_TODOH_PALETTES_LK[] =
{
    { "Main Sprite", 0x38fc380, 0x38fc3a0, indexCVS2Sprites_RyuhakuTodoh },
    { "Extra 1", 0x38fc3a0, 0x38fc3c0 },
    { "Extra 2", 0x38fc3c0, 0x38fc3e0 },
    { "Extra 3", 0x38fc3e0, 0x38fc400 },
    { "Extra 4", 0x38fc400, 0x38fc420 },
    { "Extra 5", 0x38fc420, 0x38fc440 },
};

const sGame_PaletteDataset CVS2_A_TODOH_PALETTES_MK[] =
{
    { "Main Sprite", 0x38fc440, 0x38fc460, indexCVS2Sprites_RyuhakuTodoh },
    { "Extra 1", 0x38fc460, 0x38fc480 },
    { "Extra 2", 0x38fc480, 0x38fc4a0 },
    { "Extra 3", 0x38fc4a0, 0x38fc4c0 },
    { "Extra 4", 0x38fc4c0, 0x38fc4e0 },
    { "Extra 5", 0x38fc4e0, 0x38fc500 },
};

const sGame_PaletteDataset CVS2_A_TODOH_PALETTES_HK[] =
{
    { "Main Sprite", 0x38fc500, 0x38fc520, indexCVS2Sprites_RyuhakuTodoh },
    { "Extra 1", 0x38fc520, 0x38fc540 },
    { "Extra 2", 0x38fc540, 0x38fc560 },
    { "Extra 3", 0x38fc560, 0x38fc580 },
    { "Extra 4", 0x38fc580, 0x38fc5a0 },
    { "Extra 5", 0x38fc5a0, 0x38fc5c0 },
};

const sGame_PaletteDataset CVS2_A_TODOH_PALETTES_3P[] =
{
    { "Main Sprite", 0x38fc5c0, 0x38fc5e0, indexCVS2Sprites_RyuhakuTodoh },
    { "Extra 1", 0x38fc5e0, 0x38fc600 },
    { "Extra 2", 0x38fc600, 0x38fc620 },
    { "Extra 3", 0x38fc620, 0x38fc640 },
    { "Extra 4", 0x38fc640, 0x38fc660 },
    { "Extra 5", 0x38fc660, 0x38fc680 },
};

const sGame_PaletteDataset CVS2_A_TODOH_PALETTES_3K[] =
{
    { "Main Sprite", 0x38fc680, 0x38fc6a0, indexCVS2Sprites_RyuhakuTodoh },
    { "Extra 1", 0x38fc6a0, 0x38fc6c0 },
    { "Extra 2", 0x38fc6c0, 0x38fc6e0 },
    { "Extra 3", 0x38fc6e0, 0x38fc700 },
    { "Extra 4", 0x38fc700, 0x38fc720 },
    { "Extra 5", 0x38fc720, 0x38fc740 },
};

const sDescTreeNode CVS2_A_TODOH_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_TODOH_PALETTES_LP, ARRAYSIZE(CVS2_A_TODOH_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_TODOH_PALETTES_MP, ARRAYSIZE(CVS2_A_TODOH_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_TODOH_PALETTES_HP, ARRAYSIZE(CVS2_A_TODOH_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_TODOH_PALETTES_LK, ARRAYSIZE(CVS2_A_TODOH_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_TODOH_PALETTES_MK, ARRAYSIZE(CVS2_A_TODOH_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_TODOH_PALETTES_HK, ARRAYSIZE(CVS2_A_TODOH_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_TODOH_PALETTES_3P, ARRAYSIZE(CVS2_A_TODOH_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_TODOH_PALETTES_3K, ARRAYSIZE(CVS2_A_TODOH_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_ROCK_PALETTES_LP[] =
{
    { "Main Sprite", 0x3a34ea0, 0x3a34ec0, indexCVS2Sprites_Rock },
    { "Extra 1", 0x3a34ec0, 0x3a34ee0 },
    { "Extra 2", 0x3a34ee0, 0x3a34f00 },
    { "Extra 3", 0x3a34f00, 0x3a34f20 },
    { "Extra 4", 0x3a34f20, 0x3a34f40 },
    { "Extra 5", 0x3a34f40, 0x3a34f60 },
};

const sGame_PaletteDataset CVS2_A_ROCK_PALETTES_MP[] =
{
    { "Main Sprite", 0x3a34f60, 0x3a34f80, indexCVS2Sprites_Rock },
    { "Extra 1", 0x3a34f80, 0x3a34fa0 },
    { "Extra 2", 0x3a34fa0, 0x3a34fc0 },
    { "Extra 3", 0x3a34fc0, 0x3a34fe0 },
    { "Extra 4", 0x3a34fe0, 0x3a35000 },
    { "Extra 5", 0x3a35000, 0x3a35020 },
};

const sGame_PaletteDataset CVS2_A_ROCK_PALETTES_HP[] =
{
    { "Main Sprite", 0x3a35020, 0x3a35040, indexCVS2Sprites_Rock },
    { "Extra 1", 0x3a35040, 0x3a35060 },
    { "Extra 2", 0x3a35060, 0x3a35080 },
    { "Extra 3", 0x3a35080, 0x3a350a0 },
    { "Extra 4", 0x3a350a0, 0x3a350c0 },
    { "Extra 5", 0x3a350c0, 0x3a350e0 },
};

const sGame_PaletteDataset CVS2_A_ROCK_PALETTES_LK[] =
{
    { "Main Sprite", 0x3a350e0, 0x3a35100, indexCVS2Sprites_Rock },
    { "Extra 1", 0x3a35100, 0x3a35120 },
    { "Extra 2", 0x3a35120, 0x3a35140 },
    { "Extra 3", 0x3a35140, 0x3a35160 },
    { "Extra 4", 0x3a35160, 0x3a35180 },
    { "Extra 5", 0x3a35180, 0x3a351a0 },
};

const sGame_PaletteDataset CVS2_A_ROCK_PALETTES_MK[] =
{
    { "Main Sprite", 0x3a351a0, 0x3a351c0, indexCVS2Sprites_Rock },
    { "Extra 1", 0x3a351c0, 0x3a351e0 },
    { "Extra 2", 0x3a351e0, 0x3a35200 },
    { "Extra 3", 0x3a35200, 0x3a35220 },
    { "Extra 4", 0x3a35220, 0x3a35240 },
    { "Extra 5", 0x3a35240, 0x3a35260 },
};

const sGame_PaletteDataset CVS2_A_ROCK_PALETTES_HK[] =
{
    { "Main Sprite", 0x3a35260, 0x3a35280, indexCVS2Sprites_Rock },
    { "Extra 1", 0x3a35280, 0x3a352a0 },
    { "Extra 2", 0x3a352a0, 0x3a352c0 },
    { "Extra 3", 0x3a352c0, 0x3a352e0 },
    { "Extra 4", 0x3a352e0, 0x3a35300 },
    { "Extra 5", 0x3a35300, 0x3a35320 },
};

const sGame_PaletteDataset CVS2_A_ROCK_PALETTES_3P[] =
{
    { "Main Sprite", 0x3a35320, 0x3a35340, indexCVS2Sprites_Rock },
    { "Extra 1", 0x3a35340, 0x3a35360 },
    { "Extra 2", 0x3a35360, 0x3a35380 },
    { "Extra 3", 0x3a35380, 0x3a353a0 },
    { "Extra 4", 0x3a353a0, 0x3a353c0 },
    { "Extra 5", 0x3a353c0, 0x3a353e0 },
};

const sGame_PaletteDataset CVS2_A_ROCK_PALETTES_3K[] =
{
    { "Main Sprite", 0x3a353e0, 0x3a35400, indexCVS2Sprites_Rock },
    { "Extra 1", 0x3a35400, 0x3a35420 },
    { "Extra 2", 0x3a35420, 0x3a35440 },
    { "Extra 3", 0x3a35440, 0x3a35460 },
    { "Extra 4", 0x3a35460, 0x3a35480 },
    { "Extra 5", 0x3a35480, 0x3a354a0 },
};

const sDescTreeNode CVS2_A_ROCK_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_ROCK_PALETTES_LP, ARRAYSIZE(CVS2_A_ROCK_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_ROCK_PALETTES_MP, ARRAYSIZE(CVS2_A_ROCK_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_ROCK_PALETTES_HP, ARRAYSIZE(CVS2_A_ROCK_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_ROCK_PALETTES_LK, ARRAYSIZE(CVS2_A_ROCK_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_ROCK_PALETTES_MK, ARRAYSIZE(CVS2_A_ROCK_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_ROCK_PALETTES_HK, ARRAYSIZE(CVS2_A_ROCK_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_ROCK_PALETTES_3P, ARRAYSIZE(CVS2_A_ROCK_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_ROCK_PALETTES_3K, ARRAYSIZE(CVS2_A_ROCK_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_HIBIKI_PALETTES_LP[] =
{
    { "Main Sprite", 0x3b16dc0, 0x3b16de0, indexCVS2Sprites_Hibiki },
    { "Extra 1", 0x3b16de0, 0x3b16e00 },
    { "Extra 2", 0x3b16e00, 0x3b16e20 },
    { "Extra 3", 0x3b16e20, 0x3b16e40 },
    { "Extra 4", 0x3b16e40, 0x3b16e60 },
    { "Extra 5", 0x3b16e60, 0x3b16e80 },
};

const sGame_PaletteDataset CVS2_A_HIBIKI_PALETTES_MP[] =
{
    { "Main Sprite", 0x3b16e80, 0x3b16ea0, indexCVS2Sprites_Hibiki },
    { "Extra 1", 0x3b16ea0, 0x3b16ec0 },
    { "Extra 2", 0x3b16ec0, 0x3b16ee0 },
    { "Extra 3", 0x3b16ee0, 0x3b16f00 },
    { "Extra 4", 0x3b16f00, 0x3b16f20 },
    { "Extra 5", 0x3b16f20, 0x3b16f40 },
};

const sGame_PaletteDataset CVS2_A_HIBIKI_PALETTES_HP[] =
{
    { "Main Sprite", 0x3b16f40, 0x3b16f60, indexCVS2Sprites_Hibiki },
    { "Extra 1", 0x3b16f60, 0x3b16f80 },
    { "Extra 2", 0x3b16f80, 0x3b16fa0 },
    { "Extra 3", 0x3b16fa0, 0x3b16fc0 },
    { "Extra 4", 0x3b16fc0, 0x3b16fe0 },
    { "Extra 5", 0x3b16fe0, 0x3b17000 },
};

const sGame_PaletteDataset CVS2_A_HIBIKI_PALETTES_LK[] =
{
    { "Main Sprite", 0x3b17000, 0x3b17020, indexCVS2Sprites_Hibiki },
    { "Extra 1", 0x3b17020, 0x3b17040 },
    { "Extra 2", 0x3b17040, 0x3b17060 },
    { "Extra 3", 0x3b17060, 0x3b17080 },
    { "Extra 4", 0x3b17080, 0x3b170a0 },
    { "Extra 5", 0x3b170a0, 0x3b170c0 },
};

const sGame_PaletteDataset CVS2_A_HIBIKI_PALETTES_MK[] =
{
    { "Main Sprite", 0x3b170c0, 0x3b170e0, indexCVS2Sprites_Hibiki },
    { "Extra 1", 0x3b170e0, 0x3b17100 },
    { "Extra 2", 0x3b17100, 0x3b17120 },
    { "Extra 3", 0x3b17120, 0x3b17140 },
    { "Extra 4", 0x3b17140, 0x3b17160 },
    { "Extra 5", 0x3b17160, 0x3b17180 },
};

const sGame_PaletteDataset CVS2_A_HIBIKI_PALETTES_HK[] =
{
    { "Main Sprite", 0x3b17180, 0x3b171a0, indexCVS2Sprites_Hibiki },
    { "Extra 1", 0x3b171a0, 0x3b171c0 },
    { "Extra 2", 0x3b171c0, 0x3b171e0 },
    { "Extra 3", 0x3b171e0, 0x3b17200 },
    { "Extra 4", 0x3b17200, 0x3b17220 },
    { "Extra 5", 0x3b17220, 0x3b17240 },
};

const sGame_PaletteDataset CVS2_A_HIBIKI_PALETTES_3P[] =
{
    { "Main Sprite", 0x3b17240, 0x3b17260, indexCVS2Sprites_Hibiki },
    { "Extra 1", 0x3b17260, 0x3b17280 },
    { "Extra 2", 0x3b17280, 0x3b172a0 },
    { "Extra 3", 0x3b172a0, 0x3b172c0 },
    { "Extra 4", 0x3b172c0, 0x3b172e0 },
    { "Extra 5", 0x3b172e0, 0x3b17300 },
};

const sGame_PaletteDataset CVS2_A_HIBIKI_PALETTES_3K[] =
{
    { "Main Sprite", 0x3b17300, 0x3b17320, indexCVS2Sprites_Hibiki },
    { "Extra 1", 0x3b17320, 0x3b17340 },
    { "Extra 2", 0x3b17340, 0x3b17360 },
    { "Extra 3", 0x3b17360, 0x3b17380 },
    { "Extra 4", 0x3b17380, 0x3b173a0 },
    { "Extra 5", 0x3b173a0, 0x3b173c0 },
};

const sDescTreeNode CVS2_A_HIBIKI_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_HIBIKI_PALETTES_LP, ARRAYSIZE(CVS2_A_HIBIKI_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_HIBIKI_PALETTES_MP, ARRAYSIZE(CVS2_A_HIBIKI_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_HIBIKI_PALETTES_HP, ARRAYSIZE(CVS2_A_HIBIKI_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_HIBIKI_PALETTES_LK, ARRAYSIZE(CVS2_A_HIBIKI_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_HIBIKI_PALETTES_MK, ARRAYSIZE(CVS2_A_HIBIKI_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_HIBIKI_PALETTES_HK, ARRAYSIZE(CVS2_A_HIBIKI_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_HIBIKI_PALETTES_3P, ARRAYSIZE(CVS2_A_HIBIKI_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_HIBIKI_PALETTES_3K, ARRAYSIZE(CVS2_A_HIBIKI_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_HAOHMARU_PALETTES_LP[] =
{
    { "Main Sprite", 0x3c4ed80, 0x3c4eda0, indexCVS2Sprites_Haohmaru },
    { "Extra 1", 0x3c4eda0, 0x3c4edc0 },
    { "Extra 2", 0x3c4edc0, 0x3c4ede0 },
    { "Extra 3", 0x3c4ede0, 0x3c4ee00 },
    { "Extra 4", 0x3c4ee00, 0x3c4ee20 },
    { "Extra 5", 0x3c4ee20, 0x3c4ee40 },
};

const sGame_PaletteDataset CVS2_A_HAOHMARU_PALETTES_MP[] =
{
    { "Main Sprite", 0x3c4ee40, 0x3c4ee60, indexCVS2Sprites_Haohmaru },
    { "Extra 1", 0x3c4ee60, 0x3c4ee80 },
    { "Extra 2", 0x3c4ee80, 0x3c4eea0 },
    { "Extra 3", 0x3c4eea0, 0x3c4eec0 },
    { "Extra 4", 0x3c4eec0, 0x3c4eee0 },
    { "Extra 5", 0x3c4eee0, 0x3c4ef00 },
};

const sGame_PaletteDataset CVS2_A_HAOHMARU_PALETTES_HP[] =
{
    { "Main Sprite", 0x3c4ef00, 0x3c4ef20, indexCVS2Sprites_Haohmaru },
    { "Extra 1", 0x3c4ef20, 0x3c4ef40 },
    { "Extra 2", 0x3c4ef40, 0x3c4ef60 },
    { "Extra 3", 0x3c4ef60, 0x3c4ef80 },
    { "Extra 4", 0x3c4ef80, 0x3c4efa0 },
    { "Extra 5", 0x3c4efa0, 0x3c4efc0 },
};

const sGame_PaletteDataset CVS2_A_HAOHMARU_PALETTES_LK[] =
{
    { "Main Sprite", 0x3c4efc0, 0x3c4efe0, indexCVS2Sprites_Haohmaru },
    { "Extra 1", 0x3c4efe0, 0x3c4f000 },
    { "Extra 2", 0x3c4f000, 0x3c4f020 },
    { "Extra 3", 0x3c4f020, 0x3c4f040 },
    { "Extra 4", 0x3c4f040, 0x3c4f060 },
    { "Extra 5", 0x3c4f060, 0x3c4f080 },
};

const sGame_PaletteDataset CVS2_A_HAOHMARU_PALETTES_MK[] =
{
    { "Main Sprite", 0x3c4f080, 0x3c4f0a0, indexCVS2Sprites_Haohmaru },
    { "Extra 1", 0x3c4f0a0, 0x3c4f0c0 },
    { "Extra 2", 0x3c4f0c0, 0x3c4f0e0 },
    { "Extra 3", 0x3c4f0e0, 0x3c4f100 },
    { "Extra 4", 0x3c4f100, 0x3c4f120 },
    { "Extra 5", 0x3c4f120, 0x3c4f140 },
};

const sGame_PaletteDataset CVS2_A_HAOHMARU_PALETTES_HK[] =
{
    { "Main Sprite", 0x3c4f140, 0x3c4f160, indexCVS2Sprites_Haohmaru },
    { "Extra 1", 0x3c4f160, 0x3c4f180 },
    { "Extra 2", 0x3c4f180, 0x3c4f1a0 },
    { "Extra 3", 0x3c4f1a0, 0x3c4f1c0 },
    { "Extra 4", 0x3c4f1c0, 0x3c4f1e0 },
    { "Extra 5", 0x3c4f1e0, 0x3c4f200 },
};

const sGame_PaletteDataset CVS2_A_HAOHMARU_PALETTES_3P[] =
{
    { "Main Sprite", 0x3c4f200, 0x3c4f220, indexCVS2Sprites_Haohmaru },
    { "Extra 1", 0x3c4f220, 0x3c4f240 },
    { "Extra 2", 0x3c4f240, 0x3c4f260 },
    { "Extra 3", 0x3c4f260, 0x3c4f280 },
    { "Extra 4", 0x3c4f280, 0x3c4f2a0 },
    { "Extra 5", 0x3c4f2a0, 0x3c4f2c0 },
};

const sGame_PaletteDataset CVS2_A_HAOHMARU_PALETTES_3K[] =
{
    { "Main Sprite", 0x3c4f2c0, 0x3c4f2e0, indexCVS2Sprites_Haohmaru },
    { "Extra 1", 0x3c4f2e0, 0x3c4f300 },
    { "Extra 2", 0x3c4f300, 0x3c4f320 },
    { "Extra 3", 0x3c4f320, 0x3c4f340 },
    { "Extra 4", 0x3c4f340, 0x3c4f360 },
    { "Extra 5", 0x3c4f360, 0x3c4f380 },
};

const sDescTreeNode CVS2_A_HAOHMARU_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_HAOHMARU_PALETTES_LP, ARRAYSIZE(CVS2_A_HAOHMARU_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_HAOHMARU_PALETTES_MP, ARRAYSIZE(CVS2_A_HAOHMARU_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_HAOHMARU_PALETTES_HP, ARRAYSIZE(CVS2_A_HAOHMARU_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_HAOHMARU_PALETTES_LK, ARRAYSIZE(CVS2_A_HAOHMARU_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_HAOHMARU_PALETTES_MK, ARRAYSIZE(CVS2_A_HAOHMARU_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_HAOHMARU_PALETTES_HK, ARRAYSIZE(CVS2_A_HAOHMARU_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_HAOHMARU_PALETTES_3P, ARRAYSIZE(CVS2_A_HAOHMARU_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_HAOHMARU_PALETTES_3K, ARRAYSIZE(CVS2_A_HAOHMARU_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_YUN_PALETTES_LP[] =
{
    { "Main Sprite", 0x3d52a20, 0x3d52a40, indexCVS2Sprites_Yun },
    { "Extra 1", 0x3d52a40, 0x3d52a60 },
    { "Extra 2", 0x3d52a60, 0x3d52a80 },
    { "Extra 3", 0x3d52a80, 0x3d52aa0 },
    { "Extra 4", 0x3d52aa0, 0x3d52ac0 },
    { "Extra 5", 0x3d52ac0, 0x3d52ae0 },
};

const sGame_PaletteDataset CVS2_A_YUN_PALETTES_MP[] =
{
    { "Main Sprite", 0x3d52ae0, 0x3d52b00, indexCVS2Sprites_Yun },
    { "Extra 1", 0x3d52b00, 0x3d52b20 },
    { "Extra 2", 0x3d52b20, 0x3d52b40 },
    { "Extra 3", 0x3d52b40, 0x3d52b60 },
    { "Extra 4", 0x3d52b60, 0x3d52b80 },
    { "Extra 5", 0x3d52b80, 0x3d52ba0 },
};

const sGame_PaletteDataset CVS2_A_YUN_PALETTES_HP[] =
{
    { "Main Sprite", 0x3d52ba0, 0x3d52bc0, indexCVS2Sprites_Yun },
    { "Extra 1", 0x3d52bc0, 0x3d52be0 },
    { "Extra 2", 0x3d52be0, 0x3d52c00 },
    { "Extra 3", 0x3d52c00, 0x3d52c20 },
    { "Extra 4", 0x3d52c20, 0x3d52c40 },
    { "Extra 5", 0x3d52c40, 0x3d52c60 },
};

const sGame_PaletteDataset CVS2_A_YUN_PALETTES_LK[] =
{
    { "Main Sprite", 0x3d52c60, 0x3d52c80, indexCVS2Sprites_Yun },
    { "Extra 1", 0x3d52c80, 0x3d52ca0 },
    { "Extra 2", 0x3d52ca0, 0x3d52cc0 },
    { "Extra 3", 0x3d52cc0, 0x3d52ce0 },
    { "Extra 4", 0x3d52ce0, 0x3d52d00 },
    { "Extra 5", 0x3d52d00, 0x3d52d20 },
};

const sGame_PaletteDataset CVS2_A_YUN_PALETTES_MK[] =
{
    { "Main Sprite", 0x3d52d20, 0x3d52d40, indexCVS2Sprites_Yun },
    { "Extra 1", 0x3d52d40, 0x3d52d60 },
    { "Extra 2", 0x3d52d60, 0x3d52d80 },
    { "Extra 3", 0x3d52d80, 0x3d52da0 },
    { "Extra 4", 0x3d52da0, 0x3d52dc0 },
    { "Extra 5", 0x3d52dc0, 0x3d52de0 },
};

const sGame_PaletteDataset CVS2_A_YUN_PALETTES_HK[] =
{
    { "Main Sprite", 0x3d52de0, 0x3d52e00, indexCVS2Sprites_Yun },
    { "Extra 1", 0x3d52e00, 0x3d52e20 },
    { "Extra 2", 0x3d52e20, 0x3d52e40 },
    { "Extra 3", 0x3d52e40, 0x3d52e60 },
    { "Extra 4", 0x3d52e60, 0x3d52e80 },
    { "Extra 5", 0x3d52e80, 0x3d52ea0 },
};

const sGame_PaletteDataset CVS2_A_YUN_PALETTES_3P[] =
{
    { "Main Sprite", 0x3d52ea0, 0x3d52ec0, indexCVS2Sprites_Yun },
    { "Extra 1", 0x3d52ec0, 0x3d52ee0 },
    { "Extra 2", 0x3d52ee0, 0x3d52f00 },
    { "Extra 3", 0x3d52f00, 0x3d52f20 },
    { "Extra 4", 0x3d52f20, 0x3d52f40 },
    { "Extra 5", 0x3d52f40, 0x3d52f60 },
};

const sGame_PaletteDataset CVS2_A_YUN_PALETTES_3K[] =
{
    { "Main Sprite", 0x3d52f60, 0x3d52f80, indexCVS2Sprites_Yun },
    { "Extra 1", 0x3d52f80, 0x3d52fa0 },
    { "Extra 2", 0x3d52fa0, 0x3d52fc0 },
    { "Extra 3", 0x3d52fc0, 0x3d52fe0 },
    { "Extra 4", 0x3d52fe0, 0x3d53000 },
    { "Extra 5", 0x3d53000, 0x3d53020 },
};

const sDescTreeNode CVS2_A_YUN_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_YUN_PALETTES_LP, ARRAYSIZE(CVS2_A_YUN_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_YUN_PALETTES_MP, ARRAYSIZE(CVS2_A_YUN_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_YUN_PALETTES_HP, ARRAYSIZE(CVS2_A_YUN_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_YUN_PALETTES_LK, ARRAYSIZE(CVS2_A_YUN_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_YUN_PALETTES_MK, ARRAYSIZE(CVS2_A_YUN_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_YUN_PALETTES_HK, ARRAYSIZE(CVS2_A_YUN_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_YUN_PALETTES_3P, ARRAYSIZE(CVS2_A_YUN_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_YUN_PALETTES_3K, ARRAYSIZE(CVS2_A_YUN_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_SHINAKUMA_PALETTES_LP[] =
{
    { "Main Sprite", 0x3e75a80, 0x3e75aa0, indexCVS2Sprites_ShinAkuma },
    { "Extra 1", 0x3e75aa0, 0x3e75ac0 },
    { "Extra 2", 0x3e75ac0, 0x3e75ae0 },
    { "Extra 3", 0x3e75ae0, 0x3e75b00 },
    { "Extra 4", 0x3e75b00, 0x3e75b20 },
    { "Extra 5", 0x3e75b20, 0x3e75b40 },
};

const sGame_PaletteDataset CVS2_A_SHINAKUMA_PALETTES_MP[] =
{
    { "Main Sprite", 0x3e75b40, 0x3e75b60, indexCVS2Sprites_ShinAkuma },
    { "Extra 1", 0x3e75b60, 0x3e75b80 },
    { "Extra 2", 0x3e75b80, 0x3e75ba0 },
    { "Extra 3", 0x3e75ba0, 0x3e75bc0 },
    { "Extra 4", 0x3e75bc0, 0x3e75be0 },
    { "Extra 5", 0x3e75be0, 0x3e75c00 },
};

const sGame_PaletteDataset CVS2_A_SHINAKUMA_PALETTES_HP[] =
{
    { "Main Sprite", 0x3e75c00, 0x3e75c20, indexCVS2Sprites_ShinAkuma },
    { "Extra 1", 0x3e75c20, 0x3e75c40 },
    { "Extra 2", 0x3e75c40, 0x3e75c60 },
    { "Extra 3", 0x3e75c60, 0x3e75c80 },
    { "Extra 4", 0x3e75c80, 0x3e75ca0 },
    { "Extra 5", 0x3e75ca0, 0x3e75cc0 },
};

const sGame_PaletteDataset CVS2_A_SHINAKUMA_PALETTES_LK[] =
{
    { "Main Sprite", 0x3e75cc0, 0x3e75ce0, indexCVS2Sprites_ShinAkuma },
    { "Extra 1", 0x3e75ce0, 0x3e75d00 },
    { "Extra 2", 0x3e75d00, 0x3e75d20 },
    { "Extra 3", 0x3e75d20, 0x3e75d40 },
    { "Extra 4", 0x3e75d40, 0x3e75d60 },
    { "Extra 5", 0x3e75d60, 0x3e75d80 },
};

const sGame_PaletteDataset CVS2_A_SHINAKUMA_PALETTES_MK[] =
{
    { "Main Sprite", 0x3e75d80, 0x3e75da0, indexCVS2Sprites_ShinAkuma },
    { "Extra 1", 0x3e75da0, 0x3e75dc0 },
    { "Extra 2", 0x3e75dc0, 0x3e75de0 },
    { "Extra 3", 0x3e75de0, 0x3e75e00 },
    { "Extra 4", 0x3e75e00, 0x3e75e20 },
    { "Extra 5", 0x3e75e20, 0x3e75e40 },
};

const sGame_PaletteDataset CVS2_A_SHINAKUMA_PALETTES_HK[] =
{
    { "Main Sprite", 0x3e75e40, 0x3e75e60, indexCVS2Sprites_ShinAkuma },
    { "Extra 1", 0x3e75e60, 0x3e75e80 },
    { "Extra 2", 0x3e75e80, 0x3e75ea0 },
    { "Extra 3", 0x3e75ea0, 0x3e75ec0 },
    { "Extra 4", 0x3e75ec0, 0x3e75ee0 },
    { "Extra 5", 0x3e75ee0, 0x3e75f00 },
};

const sGame_PaletteDataset CVS2_A_SHINAKUMA_PALETTES_3P[] =
{
    { "Main Sprite", 0x3e75f00, 0x3e75f20, indexCVS2Sprites_ShinAkuma },
    { "Extra 1", 0x3e75f20, 0x3e75f40 },
    { "Extra 2", 0x3e75f40, 0x3e75f60 },
    { "Extra 3", 0x3e75f60, 0x3e75f80 },
    { "Extra 4", 0x3e75f80, 0x3e75fa0 },
    { "Extra 5", 0x3e75fa0, 0x3e75fc0 },
};

const sGame_PaletteDataset CVS2_A_SHINAKUMA_PALETTES_3K[] =
{
    { "Main Sprite", 0x3e75fc0, 0x3e75fe0, indexCVS2Sprites_ShinAkuma },
    { "Extra 1", 0x3e75fe0, 0x3e76000 },
    { "Extra 2", 0x3e76000, 0x3e76020 },
    { "Extra 3", 0x3e76020, 0x3e76040 },
    { "Extra 4", 0x3e76040, 0x3e76060 },
    { "Extra 5", 0x3e76060, 0x3e76080 },
};

const sDescTreeNode CVS2_A_SHINAKUMA_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_SHINAKUMA_PALETTES_LP, ARRAYSIZE(CVS2_A_SHINAKUMA_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_SHINAKUMA_PALETTES_MP, ARRAYSIZE(CVS2_A_SHINAKUMA_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_SHINAKUMA_PALETTES_HP, ARRAYSIZE(CVS2_A_SHINAKUMA_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_SHINAKUMA_PALETTES_LK, ARRAYSIZE(CVS2_A_SHINAKUMA_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_SHINAKUMA_PALETTES_MK, ARRAYSIZE(CVS2_A_SHINAKUMA_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_SHINAKUMA_PALETTES_HK, ARRAYSIZE(CVS2_A_SHINAKUMA_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_SHINAKUMA_PALETTES_3P, ARRAYSIZE(CVS2_A_SHINAKUMA_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_SHINAKUMA_PALETTES_3K, ARRAYSIZE(CVS2_A_SHINAKUMA_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_GODRUGAL_PALETTES_LP[] =
{
    { "Main Sprite", 0x3fab320, 0x3fab340, indexCVS2Sprites_GodRugal },
    { "Extra 1", 0x3fab340, 0x3fab360 },
    { "Extra 2", 0x3fab360, 0x3fab380 },
    { "Extra 3", 0x3fab380, 0x3fab3a0 },
    { "Extra 4", 0x3fab3a0, 0x3fab3c0 },
    { "Extra 5", 0x3fab3c0, 0x3fab3e0 },
};

const sGame_PaletteDataset CVS2_A_GODRUGAL_PALETTES_MP[] =
{
    { "Main Sprite", 0x3fab3e0, 0x3fab400, indexCVS2Sprites_GodRugal },
    { "Extra 1", 0x3fab400, 0x3fab420 },
    { "Extra 2", 0x3fab420, 0x3fab440 },
    { "Extra 3", 0x3fab440, 0x3fab460 },
    { "Extra 4", 0x3fab460, 0x3fab480 },
    { "Extra 5", 0x3fab480, 0x3fab4a0 },
};

const sGame_PaletteDataset CVS2_A_GODRUGAL_PALETTES_HP[] =
{
    { "Main Sprite", 0x3fab4a0, 0x3fab4c0, indexCVS2Sprites_GodRugal },
    { "Extra 1", 0x3fab4c0, 0x3fab4e0 },
    { "Extra 2", 0x3fab4e0, 0x3fab500 },
    { "Extra 3", 0x3fab500, 0x3fab520 },
    { "Extra 4", 0x3fab520, 0x3fab540 },
    { "Extra 5", 0x3fab540, 0x3fab560 },
};

const sGame_PaletteDataset CVS2_A_GODRUGAL_PALETTES_LK[] =
{
    { "Main Sprite", 0x3fab560, 0x3fab580, indexCVS2Sprites_GodRugal },
    { "Extra 1", 0x3fab580, 0x3fab5a0 },
    { "Extra 2", 0x3fab5a0, 0x3fab5c0 },
    { "Extra 3", 0x3fab5c0, 0x3fab5e0 },
    { "Extra 4", 0x3fab5e0, 0x3fab600 },
    { "Extra 5", 0x3fab600, 0x3fab620 },
};

const sGame_PaletteDataset CVS2_A_GODRUGAL_PALETTES_MK[] =
{
    { "Main Sprite", 0x3fab620, 0x3fab640, indexCVS2Sprites_GodRugal },
    { "Extra 1", 0x3fab640, 0x3fab660 },
    { "Extra 2", 0x3fab660, 0x3fab680 },
    { "Extra 3", 0x3fab680, 0x3fab6a0 },
    { "Extra 4", 0x3fab6a0, 0x3fab6c0 },
    { "Extra 5", 0x3fab6c0, 0x3fab6e0 },
};

const sGame_PaletteDataset CVS2_A_GODRUGAL_PALETTES_HK[] =
{
    { "Main Sprite", 0x3fab6e0, 0x3fab700, indexCVS2Sprites_GodRugal },
    { "Extra 1", 0x3fab700, 0x3fab720 },
    { "Extra 2", 0x3fab720, 0x3fab740 },
    { "Extra 3", 0x3fab740, 0x3fab760 },
    { "Extra 4", 0x3fab760, 0x3fab780 },
    { "Extra 5", 0x3fab780, 0x3fab7a0 },
};

const sGame_PaletteDataset CVS2_A_GODRUGAL_PALETTES_3P[] =
{
    { "Main Sprite", 0x3fab7a0, 0x3fab7c0, indexCVS2Sprites_GodRugal },
    { "Extra 1", 0x3fab7c0, 0x3fab7e0 },
    { "Extra 2", 0x3fab7e0, 0x3fab800 },
    { "Extra 3", 0x3fab800, 0x3fab820 },
    { "Extra 4", 0x3fab820, 0x3fab840 },
    { "Extra 5", 0x3fab840, 0x3fab860 },
};

const sGame_PaletteDataset CVS2_A_GODRUGAL_PALETTES_3K[] =
{
    { "Main Sprite", 0x3fab860, 0x3fab880, indexCVS2Sprites_GodRugal },
    { "Extra 1", 0x3fab880, 0x3fab8a0 },
    { "Extra 2", 0x3fab8a0, 0x3fab8c0 },
    { "Extra 3", 0x3fab8c0, 0x3fab8e0 },
    { "Extra 4", 0x3fab8e0, 0x3fab900 },
    { "Extra 5", 0x3fab900, 0x3fab920 },
};

const sDescTreeNode CVS2_A_GODRUGAL_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_GODRUGAL_PALETTES_LP, ARRAYSIZE(CVS2_A_GODRUGAL_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_GODRUGAL_PALETTES_MP, ARRAYSIZE(CVS2_A_GODRUGAL_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_GODRUGAL_PALETTES_HP, ARRAYSIZE(CVS2_A_GODRUGAL_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_GODRUGAL_PALETTES_LK, ARRAYSIZE(CVS2_A_GODRUGAL_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_GODRUGAL_PALETTES_MK, ARRAYSIZE(CVS2_A_GODRUGAL_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_GODRUGAL_PALETTES_HK, ARRAYSIZE(CVS2_A_GODRUGAL_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_GODRUGAL_PALETTES_3P, ARRAYSIZE(CVS2_A_GODRUGAL_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_GODRUGAL_PALETTES_3K, ARRAYSIZE(CVS2_A_GODRUGAL_PALETTES_3K) },
};

const sGame_PaletteDataset CVS2_A_ROLENTO_PALETTES_LP[] =
{
    { "Main Sprite", 0x40d69a0, 0x40d69c0, indexCVS2Sprites_Rolento },
    { "Extra 1", 0x40d69c0, 0x40d69e0 },
    { "Extra 2", 0x40d69e0, 0x40d6a00 },
    { "Extra 3", 0x40d6a00, 0x40d6a20 },
    { "Extra 4", 0x40d6a20, 0x40d6a40 },
    { "Extra 5", 0x40d6a40, 0x40d6a60 },
};

const sGame_PaletteDataset CVS2_A_ROLENTO_PALETTES_MP[] =
{
    { "Main Sprite", 0x40d6a60, 0x40d6a80, indexCVS2Sprites_Rolento },
    { "Extra 1", 0x40d6a80, 0x40d6aa0 },
    { "Extra 2", 0x40d6aa0, 0x40d6ac0 },
    { "Extra 3", 0x40d6ac0, 0x40d6ae0 },
    { "Extra 4", 0x40d6ae0, 0x40d6b00 },
    { "Extra 5", 0x40d6b00, 0x40d6b20 },
};

const sGame_PaletteDataset CVS2_A_ROLENTO_PALETTES_HP[] =
{
    { "Main Sprite", 0x40d6b20, 0x40d6b40, indexCVS2Sprites_Rolento },
    { "Extra 1", 0x40d6b40, 0x40d6b60 },
    { "Extra 2", 0x40d6b60, 0x40d6b80 },
    { "Extra 3", 0x40d6b80, 0x40d6ba0 },
    { "Extra 4", 0x40d6ba0, 0x40d6bc0 },
    { "Extra 5", 0x40d6bc0, 0x40d6be0 },
};

const sGame_PaletteDataset CVS2_A_ROLENTO_PALETTES_LK[] =
{
    { "Main Sprite", 0x40d6be0, 0x40d6c00, indexCVS2Sprites_Rolento },
    { "Extra 1", 0x40d6c00, 0x40d6c20 },
    { "Extra 2", 0x40d6c20, 0x40d6c40 },
    { "Extra 3", 0x40d6c40, 0x40d6c60 },
    { "Extra 4", 0x40d6c60, 0x40d6c80 },
    { "Extra 5", 0x40d6c80, 0x40d6ca0 },
};

const sGame_PaletteDataset CVS2_A_ROLENTO_PALETTES_MK[] =
{
    { "Main Sprite", 0x40d6ca0, 0x40d6cc0, indexCVS2Sprites_Rolento },
    { "Extra 1", 0x40d6cc0, 0x40d6ce0 },
    { "Extra 2", 0x40d6ce0, 0x40d6d00 },
    { "Extra 3", 0x40d6d00, 0x40d6d20 },
    { "Extra 4", 0x40d6d20, 0x40d6d40 },
    { "Extra 5", 0x40d6d40, 0x40d6d60 },
};

const sGame_PaletteDataset CVS2_A_ROLENTO_PALETTES_HK[] =
{
    { "Main Sprite", 0x40d6d60, 0x40d6d80, indexCVS2Sprites_Rolento },
    { "Extra 1", 0x40d6d80, 0x40d6da0 },
    { "Extra 2", 0x40d6da0, 0x40d6dc0 },
    { "Extra 3", 0x40d6dc0, 0x40d6de0 },
    { "Extra 4", 0x40d6de0, 0x40d6e00 },
    { "Extra 5", 0x40d6e00, 0x40d6e20 },
};

const sGame_PaletteDataset CVS2_A_ROLENTO_PALETTES_3P[] =
{
    { "Main Sprite", 0x40d6e20, 0x40d6e40, indexCVS2Sprites_Rolento },
    { "Extra 1", 0x40d6e40, 0x40d6e60 },
    { "Extra 2", 0x40d6e60, 0x40d6e80 },
    { "Extra 3", 0x40d6e80, 0x40d6ea0 },
    { "Extra 4", 0x40d6ea0, 0x40d6ec0 },
    { "Extra 5", 0x40d6ec0, 0x40d6ee0 },
};

const sGame_PaletteDataset CVS2_A_ROLENTO_PALETTES_3K[] =
{
    { "Main Sprite", 0x40d6ee0, 0x40d6f00, indexCVS2Sprites_Rolento },
    { "Extra 1", 0x40d6f00, 0x40d6f20 },
    { "Extra 2", 0x40d6f20, 0x40d6f40 },
    { "Extra 3", 0x40d6f40, 0x40d6f60 },
    { "Extra 4", 0x40d6f60, 0x40d6f80 },
    { "Extra 5", 0x40d6f80, 0x40d6fa0 },
};

const sDescTreeNode CVS2_A_ROLENTO_COLLECTION[] =
{
    { "LP", DESC_NODETYPE_TREE, (void*)CVS2_A_ROLENTO_PALETTES_LP, ARRAYSIZE(CVS2_A_ROLENTO_PALETTES_LP) },
    { "MP", DESC_NODETYPE_TREE, (void*)CVS2_A_ROLENTO_PALETTES_MP, ARRAYSIZE(CVS2_A_ROLENTO_PALETTES_MP) },
    { "HP", DESC_NODETYPE_TREE, (void*)CVS2_A_ROLENTO_PALETTES_HP, ARRAYSIZE(CVS2_A_ROLENTO_PALETTES_HP) },
    { "LK", DESC_NODETYPE_TREE, (void*)CVS2_A_ROLENTO_PALETTES_LK, ARRAYSIZE(CVS2_A_ROLENTO_PALETTES_LK) },
    { "MK", DESC_NODETYPE_TREE, (void*)CVS2_A_ROLENTO_PALETTES_MK, ARRAYSIZE(CVS2_A_ROLENTO_PALETTES_MK) },
    { "HK", DESC_NODETYPE_TREE, (void*)CVS2_A_ROLENTO_PALETTES_HK, ARRAYSIZE(CVS2_A_ROLENTO_PALETTES_HK) },
    { "3P", DESC_NODETYPE_TREE, (void*)CVS2_A_ROLENTO_PALETTES_3P, ARRAYSIZE(CVS2_A_ROLENTO_PALETTES_3P) },
    { "3K", DESC_NODETYPE_TREE, (void*)CVS2_A_ROLENTO_PALETTES_3K, ARRAYSIZE(CVS2_A_ROLENTO_PALETTES_3K) },
};

const UINT8 CVS2_A_UNITSORT[CVS2_A_NUMUNIT + 1] // Plus 1 for extras
{
    indexCVS2_A_Akuma,
    indexCVS2_A_Athena,
    indexCVS2_A_Balrog,
    indexCVS2_A_Benimaru,
    indexCVS2_A_Blanka,
    indexCVS2_A_Cammy,
    indexCVS2_A_Chang,
    indexCVS2_A_ChunLi,
    indexCVS2_A_Dan,
    indexCVS2_A_Dhalsim,
    indexCVS2_A_EHonda,
    indexCVS2_A_Eagle,
    indexCVS2_A_Geese,
    indexCVS2_A_Guile,
    indexCVS2_A_Haohmaru,
    indexCVS2_A_Hibiki,
    indexCVS2_A_Iori,
    indexCVS2_A_Joe,
    indexCVS2_A_Ken,
    indexCVS2_A_Kim,
    indexCVS2_A_King,
    indexCVS2_A_Kyo,
    indexCVS2_A_Kyosuke,
    indexCVS2_A_MBison,
    indexCVS2_A_Mai,
    indexCVS2_A_Maki,
    indexCVS2_A_Morrigan,
    indexCVS2_A_Nakoruru,
    indexCVS2_A_Raiden,
    indexCVS2_A_Rock,
    indexCVS2_A_Rolento,
    indexCVS2_A_Rugal,
    indexCVS2_A_Ryo,
    indexCVS2_A_Ryu,
    indexCVS2_A_Sagat,
    indexCVS2_A_Sakura,
    indexCVS2_A_Terry,
    indexCVS2_A_RyuhakuTodoh,
    indexCVS2_A_Vega,
    indexCVS2_A_Vice,
    indexCVS2_A_RyujiYamazaki,
    indexCVS2_A_Yun,
    indexCVS2_A_Yuri,
    indexCVS2_A_Zangief,

    indexCVS2_A_EvilRyu,
    indexCVS2_A_OrochiIori,
    indexCVS2_A_GodRugal,
    indexCVS2_A_ShinAkuma,

    CVS2_A_EXTRALOC
};

const sDescTreeNode CVS2_A_UNITS[CVS2_A_NUMUNIT] =
{
    { "Akuma", DESC_NODETYPE_TREE, (void*)CVS2_A_AKUMA_COLLECTION, ARRAYSIZE(CVS2_A_AKUMA_COLLECTION) },
    { "Athena", DESC_NODETYPE_TREE, (void*)CVS2_A_ATHENA_COLLECTION, ARRAYSIZE(CVS2_A_ATHENA_COLLECTION) },
    { "Balrog", DESC_NODETYPE_TREE, (void*)CVS2_A_BALROG_COLLECTION, ARRAYSIZE(CVS2_A_BALROG_COLLECTION) },
    { "Benimaru", DESC_NODETYPE_TREE, (void*)CVS2_A_BENIMARU_COLLECTION, ARRAYSIZE(CVS2_A_BENIMARU_COLLECTION) },
    { "Blanka", DESC_NODETYPE_TREE, (void*)CVS2_A_BLANKA_COLLECTION, ARRAYSIZE(CVS2_A_BLANKA_COLLECTION) },
    { "Cammy", DESC_NODETYPE_TREE, (void*)CVS2_A_CAMMY_COLLECTION, ARRAYSIZE(CVS2_A_CAMMY_COLLECTION) },
    { "Chang and Choi", DESC_NODETYPE_TREE, (void*)CVS2_A_CHANG_COLLECTION, ARRAYSIZE(CVS2_A_CHANG_COLLECTION) },
    { "Chun-Li", DESC_NODETYPE_TREE, (void*)CVS2_A_CHUNLI_COLLECTION, ARRAYSIZE(CVS2_A_CHUNLI_COLLECTION) },
    { "Dan", DESC_NODETYPE_TREE, (void*)CVS2_A_DAN_COLLECTION, ARRAYSIZE(CVS2_A_DAN_COLLECTION) },
    { "Dhalsim", DESC_NODETYPE_TREE, (void*)CVS2_A_DHALSIM_COLLECTION, ARRAYSIZE(CVS2_A_DHALSIM_COLLECTION) },
    { "E.Honda", DESC_NODETYPE_TREE, (void*)CVS2_A_EHONDA_COLLECTION, ARRAYSIZE(CVS2_A_EHONDA_COLLECTION) },
    { "Eagle", DESC_NODETYPE_TREE, (void*)CVS2_A_EAGLE_COLLECTION, ARRAYSIZE(CVS2_A_EAGLE_COLLECTION) },
    { "Geese", DESC_NODETYPE_TREE, (void*)CVS2_A_GEESE_COLLECTION, ARRAYSIZE(CVS2_A_GEESE_COLLECTION) },
    { "Guile", DESC_NODETYPE_TREE, (void*)CVS2_A_GUILE_COLLECTION, ARRAYSIZE(CVS2_A_GUILE_COLLECTION) },
    { "Haohmaru", DESC_NODETYPE_TREE, (void*)CVS2_A_HAOHMARU_COLLECTION, ARRAYSIZE(CVS2_A_HAOHMARU_COLLECTION) },
    { "Hibiki", DESC_NODETYPE_TREE, (void*)CVS2_A_HIBIKI_COLLECTION, ARRAYSIZE(CVS2_A_HIBIKI_COLLECTION) },
    { "Iori", DESC_NODETYPE_TREE, (void*)CVS2_A_IORI_COLLECTION, ARRAYSIZE(CVS2_A_IORI_COLLECTION) },
    { "Joe", DESC_NODETYPE_TREE, (void*)CVS2_A_Joe_COLLECTION, ARRAYSIZE(CVS2_A_Joe_COLLECTION) },
    { "Ken", DESC_NODETYPE_TREE, (void*)CVS2_A_KEN_COLLECTION, ARRAYSIZE(CVS2_A_KEN_COLLECTION) },
    { "Kim", DESC_NODETYPE_TREE, (void*)CVS2_A_KIM_COLLECTION, ARRAYSIZE(CVS2_A_KIM_COLLECTION) },
    { "King", DESC_NODETYPE_TREE, (void*)CVS2_A_KING_COLLECTION, ARRAYSIZE(CVS2_A_KING_COLLECTION) },
    { "Kyo", DESC_NODETYPE_TREE, (void*)CVS2_A_KYO_COLLECTION, ARRAYSIZE(CVS2_A_KYO_COLLECTION) },
    { "Kyosuke", DESC_NODETYPE_TREE, (void*)CVS2_A_KYOSUKE_COLLECTION, ARRAYSIZE(CVS2_A_KYOSUKE_COLLECTION) },
    { "M.Bison", DESC_NODETYPE_TREE, (void*)CVS2_A_BISON_COLLECTION, ARRAYSIZE(CVS2_A_BISON_COLLECTION) },
    { "Mai", DESC_NODETYPE_TREE, (void*)CVS2_A_MAI_COLLECTION, ARRAYSIZE(CVS2_A_MAI_COLLECTION) },
    { "Maki", DESC_NODETYPE_TREE, (void*)CVS2_A_MAKI_COLLECTION, ARRAYSIZE(CVS2_A_MAKI_COLLECTION) },
    { "Morrigan", DESC_NODETYPE_TREE, (void*)CVS2_A_MORRIGAN_COLLECTION, ARRAYSIZE(CVS2_A_MORRIGAN_COLLECTION) },
    { "Nakoruru", DESC_NODETYPE_TREE, (void*)CVS2_A_NAKORURU_COLLECTION, ARRAYSIZE(CVS2_A_NAKORURU_COLLECTION) },
    { "Raiden", DESC_NODETYPE_TREE, (void*)CVS2_A_RAIDEN_COLLECTION, ARRAYSIZE(CVS2_A_RAIDEN_COLLECTION) },
    { "Rock Howard", DESC_NODETYPE_TREE, (void*)CVS2_A_ROCK_COLLECTION, ARRAYSIZE(CVS2_A_ROCK_COLLECTION) },
    { "Rolento", DESC_NODETYPE_TREE, (void*)CVS2_A_ROLENTO_COLLECTION, ARRAYSIZE(CVS2_A_ROLENTO_COLLECTION) },
    { "Rugal", DESC_NODETYPE_TREE, (void*)CVS2_A_RUGAL_COLLECTION, ARRAYSIZE(CVS2_A_RUGAL_COLLECTION) },
    { "Ryo", DESC_NODETYPE_TREE, (void*)CVS2_A_RYO_COLLECTION, ARRAYSIZE(CVS2_A_RYO_COLLECTION) },
    { "Ryu", DESC_NODETYPE_TREE, (void*)CVS2_A_RYU_COLLECTION, ARRAYSIZE(CVS2_A_RYU_COLLECTION) },
    { "Sagat", DESC_NODETYPE_TREE, (void*)CVS2_A_SAGAT_COLLECTION, ARRAYSIZE(CVS2_A_SAGAT_COLLECTION) },
    { "Sakura", DESC_NODETYPE_TREE, (void*)CVS2_A_SAKURA_COLLECTION, ARRAYSIZE(CVS2_A_SAKURA_COLLECTION) },
    { "Terry Bogard", DESC_NODETYPE_TREE, (void*)CVS2_A_TERRT_COLLECTION, ARRAYSIZE(CVS2_A_TERRT_COLLECTION) },
    { "Todoh", DESC_NODETYPE_TREE, (void*)CVS2_A_TODOH_COLLECTION, ARRAYSIZE(CVS2_A_TODOH_COLLECTION) },
    { "Vega", DESC_NODETYPE_TREE, (void*)CVS2_A_VEGA_COLLECTION, ARRAYSIZE(CVS2_A_VEGA_COLLECTION) },
    { "Vice", DESC_NODETYPE_TREE, (void*)CVS2_A_VICE_COLLECTION, ARRAYSIZE(CVS2_A_VICE_COLLECTION) },
    { "Yamazaki", DESC_NODETYPE_TREE, (void*)CVS2_A_YAMAZAKI_COLLECTION, ARRAYSIZE(CVS2_A_YAMAZAKI_COLLECTION) },
    { "Yun", DESC_NODETYPE_TREE, (void*)CVS2_A_YUN_COLLECTION, ARRAYSIZE(CVS2_A_YUN_COLLECTION) },
    { "Yuri", DESC_NODETYPE_TREE, (void*)CVS2_A_YURI_COLLECTION, ARRAYSIZE(CVS2_A_YURI_COLLECTION) },
    { "Zangief", DESC_NODETYPE_TREE, (void*)CVS2_A_ZANGIEF_COLLECTION, ARRAYSIZE(CVS2_A_ZANGIEF_COLLECTION) },

    { "Evil Ryu", DESC_NODETYPE_TREE, (void*)CVS2_A_EVILRYU_COLLECTION, ARRAYSIZE(CVS2_A_EVILRYU_COLLECTION) },
    { "Orochi Iori", DESC_NODETYPE_TREE, (void*)CVS2_A_OROCHIIORI_COLLECTION, ARRAYSIZE(CVS2_A_OROCHIIORI_COLLECTION) },
    { "God Rugal", DESC_NODETYPE_TREE, (void*)CVS2_A_GODRUGAL_COLLECTION, ARRAYSIZE(CVS2_A_GODRUGAL_COLLECTION) },
    { "Shin Akuma", DESC_NODETYPE_TREE, (void*)CVS2_A_SHINAKUMA_COLLECTION, ARRAYSIZE(CVS2_A_SHINAKUMA_COLLECTION) },
};

// We extend this array with data groveled from the CVS2E.txt extensible extras file, if any.
const stExtraDef CVS2_A_EXTRA[] =
{
    // Start
    { UNIT_START_VALUE },

    { INVALID_UNIT_VALUE }
};
