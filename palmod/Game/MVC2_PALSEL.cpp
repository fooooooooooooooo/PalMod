#include "StdAfx.h"
//#include "Gamedef.h"
#include "Game_MVC2_D.h"

BOOL CGame_MVC2_D::UpdatePalImg(int Node01, int Node02, int Node03, int Node04)
{
    //Reset palette sources
    ClearSrcPal();

    if (Node01 == -1)
    {
        return FALSE;
    }

    //Reset the extra amount
    nExtraAmt = 6;

    int nSpecOffs;
    BOOL bLoadDefPal = TRUE;
    bool fImgIsFromNewImgDatRange = false;

    sDescNode* NodeGet = MainDescTree.GetDescNode(Node01, Node02, Node03, Node04);

    if (NodeGet == NULL)
    {
        return FALSE;
    }

    UINT16 uUnitId = NodeGet->uUnitId;
    UINT16 uPalId = NodeGet->uPalId;

    //Change the image id if we need to
    nTargetImgId = 0;
    nImgUnitId = uUnitId;

    //Get rid of any palettes if there are any
    BasePalGroup.FlushPalAll();

    switch (uUnitId)
    {
    case 0x01: //Zangief
    {
        if ((uPalId >= (0x11 + EXTRA_OMNI)) && (uPalId <= (0x16 + EXTRA_OMNI)))
        {
            // MechaGief
            SetExtraImg(11, uUnitId, uPalId);
            break;
        }

        if ((uPalId >= (0x17 + EXTRA_OMNI)) && (uPalId <= (0x3A + EXTRA_OMNI)))
        {
            // atomic suplex sprite
            SetExtraImg(12, uUnitId, uPalId);
            break;
        }

        break;
    }
    case 0x03: //Morrigan
    {
        if (CreateExtraPal(uUnitId, uPalId, 0x3A, 3, 11, 0, 2)
            || CreateExtraPal(uUnitId, uPalId, 0x4B, 9, 12, 0, 2)
            || CreateExtraPal(uUnitId, uPalId, 0x4D, 9, 13, 0, 7)
            || CreateExtraPal(uUnitId, uPalId, 0x81, 1, 14))
        {
            break;
        }

        break;
    }

    case 0x06: //Cyclops
    {
        if (CreateExtraPal(uUnitId, uPalId, 0x19, 1, 11))
        {
            break;
        }

        if (uPalId >= (0x29 + EXTRA_OMNI) && uPalId <= (0x58 + EXTRA_OMNI))
        {
            SetExtraImg(12, uUnitId, uPalId);
            break;
        }

        if (
            CreateExtraPal(uUnitId, uPalId, 0x59, 2, 13)
            || CreateExtraPal(uUnitId, uPalId, 0x5A, 2, 13)
            )
        {
            break;
        }


        break;
    }
    case 0x07: //Wolverine
    {
        if (SpecSel(&nSpecOffs, uPalId, 0, 8))
        {
            bLoadDefPal = FALSE;

            //Create the img ticket
            ClearSetImgTicket(
                CreateImgTicket(0x07, 0,
                    CreateImgTicket(0x07, 1, NULL, 20, 4)
                )
            );

            //Set each palette
            sDescNode* NodeGet[2] = {
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 0, -1),
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 1, -1)
            };

            //Set each palette
            CreateDefPal(NodeGet[0], 0);
            CreateDefPal(NodeGet[1], 1);

            SetSourcePal(0, uUnitId, 0, 6, 8);
            SetSourcePal(1, uUnitId, 1, 6, 8);

            break;
        }

        nExtraAmt = 1;
        CreateExtraPal(uUnitId, uPalId, 0x11, 1, 11);

        break;
    }

    case 0x09: //Iceman
    {
        if (SpecSel(&nSpecOffs, uPalId, 1, 8) || SpecSel(&nSpecOffs, uPalId, 2, 8))
        {
            SetExtraImg(0, uUnitId, uPalId);
        }

        nExtraAmt = 4;
        if (CreateExtraPal(uUnitId, uPalId, 0x09, 1, 11))
        {
            break;
        }

        nExtraAmt = 0x4A - 0x21 + 1;
        CreateExtraPal(uUnitId, uPalId, 0x21, 1, 0);

        break;
    }
    case 0x0A: //Rogue
    {
        if ((uPalId >= 0x1D + EXTRA_OMNI) && (uPalId <= 0x22 + EXTRA_OMNI))
        {
            SetExtraImg(11, uUnitId, uPalId);
            break;
        }

        break;
    }

    case 0x0B: //Captain America
    {
        if (SpecSel(&nSpecOffs, uPalId, 0, 8))
        {
            bLoadDefPal = FALSE;

            //Create the img ticket
            ClearSetImgTicket(
                CreateImgTicket(uUnitId, 0,
                    CreateImgTicket(uUnitId, 1, NULL, -22, -17)
                )
            );

            //Set each palette
            sDescNode* NodeGet[2] = {
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 0, -1),
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 1, -1)
            };

            //Set each palette
            CreateDefPal(NodeGet[0], 0);
            CreateDefPal(NodeGet[1], 1);

            SetSourcePal(0, uUnitId, 0, 6, 8);
            SetSourcePal(1, uUnitId, 1, 6, 8);
        }
        break;
    }
    case 0x0C: //Spider-Man
    {
        if (
            CreateExtraPal(uUnitId, uPalId, 0x09, 0x10, 11, 0, 8)
            || CreateExtraPal(uUnitId, uPalId, 0x11, 0x10, 12)
            || CreateExtraPal(uUnitId, uPalId, 0x12, 0x10, 13)
            || CreateExtraPal(uUnitId, uPalId, 0x13, 0x10, 14)
            || CreateExtraPal(uUnitId, uPalId, 0x14, 0x10, 15)
            )
        {
            break;
        }

        break;
    }

    case 0x0D: //Hulk
    {
        nExtraAmt = 1;
        CreateExtraPal(uUnitId, uPalId, 0x0A, 1, 11);
        break;
    }

    case 0x0F: //Dr Doom
    {
        if (
            CreateExtraPal(uUnitId, uPalId, 0x09, 0x1C, 11)
            || CreateExtraPal(uUnitId, uPalId, 0x0A, 0x1C, 12)
            || CreateExtraPal(uUnitId, uPalId, 0x0B, 0x1C, 13)
            || CreateExtraPal(uUnitId, uPalId, 0x0C, 0x1C, 14)
            )
        {
            break;
        }

        break;
    }

    case 0x10: //Tron
    {
        if (SpecSel(&nSpecOffs, uPalId, 0, 8))
        {
            bLoadDefPal = FALSE;

            //Create the img ticket
            ClearSetImgTicket(
                CreateImgTicket(0x10, 0,
                    CreateImgTicket(0x10, 1, NULL, -4, -50)
                )
            );

            //Set each palette
            sDescNode* NodeGet[2] = {
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 0, -1),
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 1, -1)
            };

            //Set each palette
            CreateDefPal(NodeGet[0], 0);
            CreateDefPal(NodeGet[1], 1);

            SetSourcePal(0, uUnitId, 0, 6, 8);
            SetSourcePal(1, uUnitId, 1, 6, 8);

            break;
        }

        nExtraAmt = 1;

        if (
            CreateExtraPal(uUnitId, uPalId, 0x11, 1, 11)
            || CreateExtraPal(uUnitId, uPalId, 0x13, 1, 12)
            || CreateExtraPal(uUnitId, uPalId, 0x14, 1, 13)
            || CreateExtraPal(uUnitId, uPalId, 0x15, 1, 14)
            )
        {
            break;
        }

        break;
    }

    case 0x11: //Jill Valentine
    {
        nExtraAmt = 1;

        if (
            CreateExtraPal(uUnitId, uPalId, 0x09, 1, 11)
            || CreateExtraPal(uUnitId, uPalId, 0x0A, 1, 12)
            || CreateExtraPal(uUnitId, uPalId, 0x0B, 1, 2)
            )
        {
            break;
        }

        break;
    }
    case 0x12: //Hayato
    {
        if (SpecSel(&nSpecOffs, uPalId, 0, 8) && nSpecOffs < 6)
        {
            bLoadDefPal = FALSE;

            //Create the img ticket
            ClearSetImgTicket(
                CreateImgTicket(0x12, 0,
                    CreateImgTicket(0x12, 1, NULL, -63, 32)
                )
            );

            sDescNode* NodeGet[2] = {
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 0, -1),
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 1, -1)
            };

            //Set each palette
            CreateDefPal(NodeGet[0], 0);
            CreateDefPal(NodeGet[1], 1);

            SetSourcePal(0, uUnitId, 0, 6, 8);
            SetSourcePal(1, uUnitId, 1, 6, 8);
        }

        break;
    }
    case 0x13: //Ruby Heart
    {
        nExtraAmt = 1;

        if (
            CreateExtraPal(uUnitId, uPalId, 0x0B, 1, 11)
            || CreateExtraPal(uUnitId, uPalId, 0x0C, 1, 12)
            || CreateExtraPal(uUnitId, uPalId, 0x0D, 1, 13)
            || CreateExtraPal(uUnitId, uPalId, 0x0E, 1, 14)
            || CreateExtraPal(uUnitId, uPalId, 0x10, 1, 15)
            )
        {
            break;
        }

        break;
    }
    case 0x14: //SonSon
    {
        if (
            CreateExtraPal(uUnitId, uPalId, 0x0F, 1, 11)
            || CreateExtraPal(uUnitId, uPalId, 0x17, 1, 11)
            || CreateExtraPal(uUnitId, uPalId, 0x1D, 2, 11, 0, 2)
            )
        {
            break;
        }
        break;
    }

    case 0x1C: // Megaman
    {
        if (((uPalId >= (0x0B + EXTRA_OMNI)) && (uPalId <= (0x13 + EXTRA_OMNI))) || // Megaman intros
            ((uPalId >= (0x2F + EXTRA_OMNI)) && (uPalId <= (0x37 + EXTRA_OMNI))) || // Charging buster

            ((uPalId >= (0x62 + EXTRA_OMNI)) && (uPalId <= (0x6A + EXTRA_OMNI))) || // Megaman intros
            ((uPalId >= (0x86 + EXTRA_OMNI)) && (uPalId <= (0x8E + EXTRA_OMNI))) || // Charging buster

            ((uPalId >= (0xB9 + EXTRA_OMNI)) && (uPalId <= (0xC1 + EXTRA_OMNI))) || // Megaman intros
            ((uPalId >= (0xDD + EXTRA_OMNI)) && (uPalId <= (0xE5 + EXTRA_OMNI))) || // Charging buster

            ((uPalId >= (0x110 + EXTRA_OMNI)) && (uPalId <= (0x118 + EXTRA_OMNI))) || // Megaman intros
            ((uPalId >= (0x134 + EXTRA_OMNI)) && (uPalId <= (0x13c + EXTRA_OMNI))) || // Charging buster

            ((uPalId >= (0x167 + EXTRA_OMNI)) && (uPalId <= (0x16F + EXTRA_OMNI))) || // Megaman intros
            ((uPalId >= (0x18B + EXTRA_OMNI)) && (uPalId <= (0x193 + EXTRA_OMNI))) || // Charging buster

            ((uPalId >= (0x1BE + EXTRA_OMNI)) && (uPalId <= (0x1C6 + EXTRA_OMNI))) || // Megaman intros
            ((uPalId >= (0x1E2 + EXTRA_OMNI)) && (uPalId <= (0x1EA + EXTRA_OMNI))))   // Charging buster
        {
            SetExtraImg(0, uUnitId, uPalId);
            break;
        }
        else if ((uPalId == (0x9 + EXTRA_OMNI)) || // hair
                 (uPalId == (0x60 + EXTRA_OMNI)) ||
                 (uPalId == (0xB7 + EXTRA_OMNI)) ||
                 (uPalId == (0xB7 + EXTRA_OMNI)) ||
                 (uPalId == (0x10E + EXTRA_OMNI)) ||
                 (uPalId == (0x165 + EXTRA_OMNI)))
        {
            fImgIsFromNewImgDatRange = true;
            nTargetImgId = 0x26;
            break;
        }
        else if ((uPalId == (0x0A + EXTRA_OMNI)) || // teleport intro
                 (uPalId == (0x61 + EXTRA_OMNI)) ||
                 (uPalId == (0xB8 + EXTRA_OMNI)) ||
                 (uPalId == (0x10F + EXTRA_OMNI)) ||
                 (uPalId == (0x166 + EXTRA_OMNI)) ||
                 (uPalId == (0x1BD + EXTRA_OMNI)))
        {
            nTargetImgId = 0x0B;
            break;
        }
        else if ((uPalId == (0x42 + EXTRA_OMNI)) || // Dr Light
                 (uPalId == (0x99 + EXTRA_OMNI)) ||
                 (uPalId == (0xEF + EXTRA_OMNI)) ||
                 (uPalId == (0x147 + EXTRA_OMNI)) ||
                 (uPalId == (0x19E + EXTRA_OMNI)) ||
                 (uPalId == (0x1F5 + EXTRA_OMNI)))
        {
            fImgIsFromNewImgDatRange = true;
            nTargetImgId = 0x25;
            break;
        }
        else if ((uPalId == (0x5E + EXTRA_OMNI)) || // Roll
                 (uPalId == (0xB5 + EXTRA_OMNI)) ||
                 (uPalId == (0x10C + EXTRA_OMNI)) ||
                 (uPalId == (0x163 + EXTRA_OMNI)) ||
                 (uPalId == (0x1BA + EXTRA_OMNI)) ||
                 (uPalId == (0x211 + EXTRA_OMNI)))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1d;
            nTargetImgId = 0;

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, 0));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, uPalId, 1, 1);

            break;
        }
        else if (((uPalId >= (0x14 + EXTRA_OMNI)) && (uPalId <= (0x1C + EXTRA_OMNI))) || // Rush
                 ((uPalId >= (0x6B + EXTRA_OMNI)) && (uPalId <= (0x73 + EXTRA_OMNI))) ||
                 ((uPalId >= (0xC2 + EXTRA_OMNI)) && (uPalId <= (0xCA + EXTRA_OMNI))) ||
                 ((uPalId >= (0x119 + EXTRA_OMNI)) && (uPalId <= (0x121 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x170 + EXTRA_OMNI)) && (uPalId <= (0x178 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1C7 + EXTRA_OMNI)) && (uPalId <= (0x1CF + EXTRA_OMNI))))
        {
            nTargetImgId = 1; // Rush
            break;
        }
        else if (((uPalId >= (0x1D + EXTRA_OMNI)) && (uPalId <= (0x25 + EXTRA_OMNI))) || // Beat
                 ((uPalId >= (0x74 + EXTRA_OMNI)) && (uPalId <= (0x7C + EXTRA_OMNI))) ||
                 ((uPalId >= (0xCB + EXTRA_OMNI)) && (uPalId <= (0xD3 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x122 + EXTRA_OMNI)) && (uPalId <= (0x12A + EXTRA_OMNI))) ||
                 ((uPalId >= (0x179 + EXTRA_OMNI)) && (uPalId <= (0x181 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1D0 + EXTRA_OMNI)) && (uPalId <= (0x1D8 + EXTRA_OMNI))))
        {
            nTargetImgId = 2;
            break;
        }
        else if (((uPalId >= (0x26 + EXTRA_OMNI)) && (uPalId <= (0x2E + EXTRA_OMNI))) || // Beat Plane
                 ((uPalId >= (0x7D + EXTRA_OMNI)) && (uPalId <= (0x85 + EXTRA_OMNI))) ||
                 ((uPalId >= (0xD4 + EXTRA_OMNI)) && (uPalId <= (0xDC + EXTRA_OMNI))) ||
                 ((uPalId >= (0x12B + EXTRA_OMNI)) && (uPalId <= (0x133 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x182 + EXTRA_OMNI)) && (uPalId <= (0x18A + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1D9 + EXTRA_OMNI)) && (uPalId <= (0x1E1 + EXTRA_OMNI))))
        {
            fImgIsFromNewImgDatRange = true;
            nTargetImgId = 0x24;
            break;
        }
        else if (((uPalId >= (0x38 + EXTRA_OMNI)) && (uPalId <= (0x3F + EXTRA_OMNI))) || // Rush Drill
                 ((uPalId >= (0x8F + EXTRA_OMNI)) && (uPalId <= (0x96 + EXTRA_OMNI))) ||
                 ((uPalId >= (0xE6 + EXTRA_OMNI)) && (uPalId <= (0xEC + EXTRA_OMNI))) ||
                 ((uPalId >= (0x13D + EXTRA_OMNI)) && (uPalId <= (0x144 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x194 + EXTRA_OMNI)) && (uPalId <= (0x19B + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1EB + EXTRA_OMNI)) && (uPalId <= (0x1F2 + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            int nXOffs = 0;
            int nYOffs = 0;
            int nPeerPaletteDistance = 0x1E;

            //Create the img ticket
            ClearSetImgTicket(
                CreateImgTicket(0x1D, 0xB,
                    CreateImgTicket(0x1D, 0x0C, nullptr, nXOffs, nYOffs)
                )
            );

            //Set each palette
            sDescNode* NodeRushDrill[2] = {
                MainDescTree.GetDescNode(Node01, Node02, Node03, -1),
                MainDescTree.GetDescNode(Node01, Node02, Node03 + nPeerPaletteDistance, -1)
            };

            //Set each palette
            CreateDefPal(NodeRushDrill[0], 0);
            CreateDefPal(NodeRushDrill[1], 1);

            SetSourcePal(0, NodeGet->uUnitId, NodeGet->uPalId, 1, 1);
            SetSourcePal(1, NodeGet->uUnitId, NodeGet->uPalId + nPeerPaletteDistance, 1, 1);

            break;
        }
        else if (((uPalId == (0x40 + EXTRA_OMNI))) || // Rush Drill: all white sprite.  No matching metal.
                 ((uPalId == (0x97 + EXTRA_OMNI))) ||
                 ((uPalId == (0xED + EXTRA_OMNI))) ||
                 ((uPalId == (0x145 + EXTRA_OMNI))) ||
                 ((uPalId == (0x19C + EXTRA_OMNI))) ||
                 ((uPalId == (0x1F3 + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1D;
            nTargetImgId = 0x0B; // rush drill

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, uPalId, 1, 1);
            break;
        }
        else if (((uPalId >= (0x56 + EXTRA_OMNI)) && (uPalId <= (0x5D + EXTRA_OMNI))) || // Rush Drill metal bits
                 ((uPalId >= (0xAD + EXTRA_OMNI)) && (uPalId <= (0xB4 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x104 + EXTRA_OMNI)) && (uPalId <= (0x10B + EXTRA_OMNI))) ||
                 ((uPalId >= (0x15B + EXTRA_OMNI)) && (uPalId <= (0x162 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1B2 + EXTRA_OMNI)) && (uPalId <= (0x1B9 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x209 + EXTRA_OMNI)) && (uPalId <= (0x210 + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1D;
            nTargetImgId = 0x0C; // rush drill metal

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, uPalId, 1, 1);
            break;
        }
        else if (((uPalId >= (0x43 + EXTRA_OMNI)) && (uPalId <= (0x4B + EXTRA_OMNI))) || // Hyper Megaman: Armor
                 ((uPalId >= (0x9A + EXTRA_OMNI)) && (uPalId <= (0xA2 + EXTRA_OMNI))) ||
                 ((uPalId >= (0xF1 + EXTRA_OMNI)) && (uPalId <= (0xF9 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x148 + EXTRA_OMNI)) && (uPalId <= (0x150 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x19F + EXTRA_OMNI)) && (uPalId <= (0x1A7 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1F6 + EXTRA_OMNI)) && (uPalId <= (0x1FE + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            int nXOffs = 31;
            int nYOffs = 12;
            int nPeerPaletteDistance = 9;

            //Create the img ticket
            ClearSetImgTicket(
                CreateImgTicket(uUnitId, 0x27,
                    CreateImgTicket(uUnitId, 0x28, nullptr, nXOffs, nYOffs)
                )
            );

            //Set each palette
            sDescNode* NodeHMMM[2] = {
                MainDescTree.GetDescNode(Node01, Node02, Node03, -1),
                MainDescTree.GetDescNode(Node01, Node02, Node03 + nPeerPaletteDistance, -1)
            };

            //Set each palette
            CreateDefPal(NodeHMMM[0], 0);
            CreateDefPal(NodeHMMM[1], 1);

            SetSourcePal(0, NodeGet->uUnitId, NodeGet->uPalId, 1, 1);
            SetSourcePal(1, NodeGet->uUnitId, NodeGet->uPalId + nPeerPaletteDistance, 1, 1);

            break;
        }
        else if (((uPalId >= (0x4C + EXTRA_OMNI)) && (uPalId <= (0x54 + EXTRA_OMNI))) || // Hyper Megaman: core
                 ((uPalId >= (0xA3 + EXTRA_OMNI)) && (uPalId <= (0xAB + EXTRA_OMNI))) ||
                 ((uPalId >= (0xFA + EXTRA_OMNI)) && (uPalId <= (0x102 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x151 + EXTRA_OMNI)) && (uPalId <= (0x159 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1A8 + EXTRA_OMNI)) && (uPalId <= (0x1B0 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1FF + EXTRA_OMNI)) && (uPalId <= (0x207 + EXTRA_OMNI))))
        {
            fImgIsFromNewImgDatRange = true;
            nTargetImgId = 0x28;
            break;
        }
        else if ((uPalId == (0x55 + EXTRA_OMNI)) || // HMM missiles
                 (uPalId == (0xAC + EXTRA_OMNI)) ||
                 (uPalId == (0x103 + EXTRA_OMNI)) ||
                 (uPalId == (0x15A + EXTRA_OMNI)) ||
                 (uPalId == (0x1B1 + EXTRA_OMNI)) ||
                 (uPalId == (0x208 + EXTRA_OMNI)))
        {
            fImgIsFromNewImgDatRange = true;
            nTargetImgId = 0x29;
            break;
        }

        break;
    }

    case 0x1D: // Roll
    {
        if (((uPalId >= (0x0B + EXTRA_OMNI)) && (uPalId <= (0x13 + EXTRA_OMNI))) || // Roll intros
            ((uPalId >= (0x2F + EXTRA_OMNI)) && (uPalId <= (0x37 + EXTRA_OMNI))) || // Charging buster
            ((uPalId >= (0x4C + EXTRA_OMNI)) && (uPalId <= (0x54 + EXTRA_OMNI))) || // Hyper Roll

            ((uPalId >= (0x62 + EXTRA_OMNI)) && (uPalId <= (0x6A + EXTRA_OMNI))) || // Roll intros
            ((uPalId >= (0x86 + EXTRA_OMNI)) && (uPalId <= (0x8E + EXTRA_OMNI))) || // Charging buster
            ((uPalId >= (0xA3 + EXTRA_OMNI)) && (uPalId <= (0xAB + EXTRA_OMNI))) || // Hyper Roll

            ((uPalId >= (0xB9 + EXTRA_OMNI)) && (uPalId <= (0xC1 + EXTRA_OMNI))) || // Roll intros
            ((uPalId >= (0xDD + EXTRA_OMNI)) && (uPalId <= (0xE5 + EXTRA_OMNI))) || // Charging buster
            ((uPalId >= (0xFA + EXTRA_OMNI)) && (uPalId <= (0x102 + EXTRA_OMNI))) ||  // Hyper Roll

            ((uPalId >= (0x110 + EXTRA_OMNI)) && (uPalId <= (0x118 + EXTRA_OMNI))) || // Roll intros
            ((uPalId >= (0x134 + EXTRA_OMNI)) && (uPalId <= (0x13c + EXTRA_OMNI))) || // Charging buster
            ((uPalId >= (0x151 + EXTRA_OMNI)) && (uPalId <= (0x159 + EXTRA_OMNI))) || // Hyper Roll

            ((uPalId >= (0x167 + EXTRA_OMNI)) && (uPalId <= (0x16F + EXTRA_OMNI))) || // Roll intros
            ((uPalId >= (0x18B + EXTRA_OMNI)) && (uPalId <= (0x193 + EXTRA_OMNI))) || // Charging buster
            ((uPalId >= (0x1A8 + EXTRA_OMNI)) && (uPalId <= (0x1B0 + EXTRA_OMNI))) || // Hyper Roll

            ((uPalId >= (0x1BE + EXTRA_OMNI)) && (uPalId <= (0x1C6 + EXTRA_OMNI))) || // Roll intros
            ((uPalId >= (0x1E2 + EXTRA_OMNI)) && (uPalId <= (0x1EA + EXTRA_OMNI))) || // Charging buster
            ((uPalId >= (0x1FF + EXTRA_OMNI)) && (uPalId <= (0x207 + EXTRA_OMNI))))  // Hyper Roll
        {
            SetExtraImg(0, uUnitId, uPalId);
            break;
        }
        else if ((uPalId == (0x0A + EXTRA_OMNI)) || // teleport intro
                 (uPalId == (0x61 + EXTRA_OMNI)) ||
                 (uPalId == (0xB8 + EXTRA_OMNI)) ||
                 (uPalId == (0x10F + EXTRA_OMNI)) ||
                 (uPalId == (0x166 + EXTRA_OMNI)) ||
                 (uPalId == (0x1BD + EXTRA_OMNI)))
        {
            nImgUnitId = 0x1C;
            nTargetImgId = 0x0B;
            break;
        }
        else if ((uPalId == (0x42 + EXTRA_OMNI)) || // Dr Light
                 (uPalId == (0x99 + EXTRA_OMNI)) ||
                 (uPalId == (0xEF + EXTRA_OMNI)) ||
                 (uPalId == (0x147 + EXTRA_OMNI)) ||
                 (uPalId == (0x19E + EXTRA_OMNI)) ||
                 (uPalId == (0x1F5 + EXTRA_OMNI)))
        {
            fImgIsFromNewImgDatRange = true;
            nImgUnitId = 0x1C;
            nTargetImgId = 0x25;
            break;
        }

        else if ((uPalId == (0x5E + EXTRA_OMNI)) || // Megaman
                 (uPalId == (0xB5 + EXTRA_OMNI)) ||
                 (uPalId == (0x10C + EXTRA_OMNI)) ||
                 (uPalId == (0x163 + EXTRA_OMNI)) ||
                 (uPalId == (0x1BA + EXTRA_OMNI)) ||
                 (uPalId == (0x211 + EXTRA_OMNI)))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1C;
            nTargetImgId = 0;

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, uPalId, 1, 1);

            break;
        }
        else if ((uPalId == (0x9 + EXTRA_OMNI)) || // Megaman's hair
                 (uPalId == (0x60 + EXTRA_OMNI)) ||
                 (uPalId == (0xB7 + EXTRA_OMNI)) ||
                 (uPalId == (0xB7 + EXTRA_OMNI)) ||
                 (uPalId == (0x10E + EXTRA_OMNI)) ||
                 (uPalId == (0x165 + EXTRA_OMNI)))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1C;
            nTargetImgId = 0x26;

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, uPalId, 1, 1);

            break;
        }
        else if ((uPalId == 0x1) || // Button Extra 01: Reuse Megaman's Rush sprite
                 (uPalId == 0x9) ||
                 (uPalId == 0x11) ||
                 (uPalId == 0x19) ||
                 (uPalId == 0x21) ||
                 (uPalId == 0x29) ||
                 ((uPalId >= (0x14 + EXTRA_OMNI)) && (uPalId <= (0x1C + EXTRA_OMNI))) || // Rush extras
                 ((uPalId >= (0x6B + EXTRA_OMNI)) && (uPalId <= (0x73 + EXTRA_OMNI))) ||
                 ((uPalId >= (0xC2 + EXTRA_OMNI)) && (uPalId <= (0xCA + EXTRA_OMNI))) ||
                 ((uPalId >= (0x119 + EXTRA_OMNI)) && (uPalId <= (0x121 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x170 + EXTRA_OMNI)) && (uPalId <= (0x178 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1C7 + EXTRA_OMNI)) && (uPalId <= (0x1CF + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1C;
            nTargetImgId = 1; // Rush

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            const int nBasicOffset = GetBasicOffset(uPalId);
            if (nBasicOffset != -1)
            {
                SetSourcePal(0, uUnitId, nBasicOffset, 6, 8);
            }
            else
            {
                SetSourcePal(0, uUnitId, uPalId, 1, 1);
            }
            break;
        }
        else if ((uPalId == 0x2) || // Pull in Megaman's Beat sprite
                 (uPalId == 0xA) ||
                 (uPalId == 0x12) ||
                 (uPalId == 0x1A) ||
                 (uPalId == 0x22) ||
                 (uPalId == 0x2A) ||
                 ((uPalId >= (0x1D + EXTRA_OMNI)) && (uPalId <= (0x25 + EXTRA_OMNI))) || // Beat
                 ((uPalId >= (0x74 + EXTRA_OMNI)) && (uPalId <= (0x7C + EXTRA_OMNI))) ||
                 ((uPalId >= (0xCB + EXTRA_OMNI)) && (uPalId <= (0xD3 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x122 + EXTRA_OMNI)) && (uPalId <= (0x12A + EXTRA_OMNI))) ||
                 ((uPalId >= (0x179 + EXTRA_OMNI)) && (uPalId <= (0x181 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1D0 + EXTRA_OMNI)) && (uPalId <= (0x1D8 + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1C;
            nTargetImgId = 0x2; // Beat!

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            const int nBasicOffset = GetBasicOffset(uPalId);
            if (nBasicOffset != -1)
            {
                SetSourcePal(0, uUnitId, nBasicOffset, 6, 8);
            }
            else
            {
                SetSourcePal(0, uUnitId, uPalId, 1, 1);
            }
            break;
        }
        else if (((uPalId >= (0x26 + EXTRA_OMNI)) && (uPalId <= (0x2E + EXTRA_OMNI))) || // Beat Plane
                 ((uPalId >= (0x7D + EXTRA_OMNI)) && (uPalId <= (0x85 + EXTRA_OMNI))) ||
                 ((uPalId >= (0xD4 + EXTRA_OMNI)) && (uPalId <= (0xDC + EXTRA_OMNI))) ||
                 ((uPalId >= (0x12B + EXTRA_OMNI)) && (uPalId <= (0x133 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x182 + EXTRA_OMNI)) && (uPalId <= (0x18A + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1D9 + EXTRA_OMNI)) && (uPalId <= (0x1E1 + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1C;
            nTargetImgId = 0x24; // Beat plane

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, uPalId, 1, 1);
            break;
        }
        else if (((uPalId >= (0x38 + EXTRA_OMNI)) && (uPalId <= (0x3F + EXTRA_OMNI))) || // Rush Drill
                 ((uPalId >= (0x8F + EXTRA_OMNI)) && (uPalId <= (0x96 + EXTRA_OMNI))) ||
                 ((uPalId >= (0xE6 + EXTRA_OMNI)) && (uPalId <= (0xEC + EXTRA_OMNI))) ||
                 ((uPalId >= (0x13D + EXTRA_OMNI)) && (uPalId <= (0x144 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x194 + EXTRA_OMNI)) && (uPalId <= (0x19B + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1EB + EXTRA_OMNI)) && (uPalId <= (0x1F2 + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            int nXOffs = 0;
            int nYOffs = 0;
            int nPeerPaletteDistance = 0x1E;

            //Create the img ticket
            ClearSetImgTicket(
                CreateImgTicket(uUnitId, 0xB,
                    CreateImgTicket(uUnitId, 0x0C, nullptr, nXOffs, nYOffs)
                )
            );

            //Set each palette
            sDescNode* NodeRushDrill[2] = {
                MainDescTree.GetDescNode(Node01, Node02, Node03, -1),
                MainDescTree.GetDescNode(Node01, Node02, Node03 + nPeerPaletteDistance, -1)
            };

            //Set each palette
            CreateDefPal(NodeRushDrill[0], 0);
            CreateDefPal(NodeRushDrill[1], 1);

            SetSourcePal(0, NodeGet->uUnitId, NodeGet->uPalId, 1, 1);
            SetSourcePal(1, NodeGet->uUnitId, NodeGet->uPalId + nPeerPaletteDistance, 1, 1);

            break;
        }
        else if (((uPalId == (0x40 + EXTRA_OMNI))) || // Rush Drill: all white sprite.  No matching metal.
                 ((uPalId == (0x97 + EXTRA_OMNI))) ||
                 ((uPalId == (0xED + EXTRA_OMNI))) ||
                 ((uPalId == (0x145 + EXTRA_OMNI))) ||
                 ((uPalId == (0x19C + EXTRA_OMNI))) ||
                 ((uPalId == (0x1F3 + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1D;
            nTargetImgId = 0x0B; // rush drill

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, uPalId, 1, 1);
            break;
        }
        else if (((uPalId >= (0x56 + EXTRA_OMNI)) && (uPalId <= (0x5D + EXTRA_OMNI))) || // Rush Drill metal bits
                 ((uPalId >= (0xAD + EXTRA_OMNI)) && (uPalId <= (0xB4 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x104 + EXTRA_OMNI)) && (uPalId <= (0x10B + EXTRA_OMNI))) ||
                 ((uPalId >= (0x15B + EXTRA_OMNI)) && (uPalId <= (0x162 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x1B2 + EXTRA_OMNI)) && (uPalId <= (0x1B9 + EXTRA_OMNI))) ||
                 ((uPalId >= (0x209 + EXTRA_OMNI)) && (uPalId <= (0x210 + EXTRA_OMNI))))
        {
            bLoadDefPal = FALSE;

            nImgUnitId = 0x1D;
            nTargetImgId = 0x0C; // rush drill metal

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, uPalId, 1, 1);
            break;
        }

        break;
    }
    case 0x15: //Amingo
    {
        nExtraAmt = 1;

        if (
            CreateExtraPal(uUnitId, uPalId, 0x09, 1, 11)
            || CreateExtraPal(uUnitId, uPalId, 0x0B, 1, 11)
            )
        {
            break;
        }

        break;
    }
    case 0x23: //Dan
    {
        if (SpecSel(&nSpecOffs, uPalId, 2, 8))
        {
            SetExtraImg(1, uUnitId, uPalId);
        }

        break;
    }

    case 0x24: //Cammy
    {
        if ((uPalId >= (0x09 + EXTRA_OMNI)) && (uPalId <= (0x3E + EXTRA_OMNI)))
        {
            SetExtraImg(11, uUnitId, uPalId);
        }
        break;
    }
    case 0x25: //Dhalsim
    {
        if ((uPalId >= (0x09 + EXTRA_OMNI)) && (uPalId <= (0x26 + EXTRA_OMNI)))
        {
            SetExtraImg(11, uUnitId, uPalId);
        }
        break;
    }
    case 0x26: //M.Bison
    {
        if (
            CreateExtraPal(uUnitId, uPalId, 0x09, 1, 11)
            || CreateExtraPal(uUnitId, uPalId, 0x0A, 1, 12)
            )
        {
            break;
        }

        break;
    }
    case 0x28: //Gambit
    {
        if ((uPalId >= (0x09 + EXTRA_OMNI)) && (uPalId <= (0x26 + EXTRA_OMNI)))
        {
            SetExtraImg(11, uUnitId, uPalId);
        }
        break;
    }
    case 0x29: //Juggernaut
    {
        if ((uPalId >= (0x09 + EXTRA_OMNI)) && (uPalId <= (0x44 + EXTRA_OMNI)))
        {
            SetExtraImg(11, uUnitId, uPalId);
        }
        break;
    }
    case 0x2A: //Storm
    {
        nExtraAmt = 3;

        if (CreateExtraPal(uUnitId, uPalId, 0x09, 1, 11))
            break;

        nExtraAmt = 4;

        if (CreateExtraPal(uUnitId, uPalId, 0x0F, 1, 12))
            break;

        nExtraAmt = 4;

        if (CreateExtraPal(uUnitId, uPalId, 0x13, 1, 13))
            break;

        nExtraAmt = 1;

        if (CreateExtraPal(uUnitId, uPalId, 0x1B, 1, 14))
            break;

        nExtraAmt = 18;
        if (CreateExtraPal(uUnitId, uPalId, 0x19, 1, 15))
            break;

        break;
    }
    case 0x2C: // Magneto
    {
        if (uPalId == 0x09 + EXTRA_OMNI)
        {
            SetExtraImg(11, uUnitId, uPalId);
        }

        break;
    }

    case 0x2D: // Shuma Gorath
    {
        // Everything he has works great with the default sprite
        // If you want to show the default sprite for just the Extras, uncomment the following line
        //if (uPalId >= (0x11 + EXTRA_OMNI) && uPalId <= (0x130 + EXTRA_OMNI))
        {
            SetExtraImg(0, uUnitId, uPalId);
        }

        break;
    }

    case 0x2F: //Silver Samurai
    {
        if ((uPalId >= (0x09 + EXTRA_OMNI)) && (uPalId <= (0x37 + EXTRA_OMNI)))
        {
            SetExtraImg(0, uUnitId, uPalId);
        }

        break;
    }
    case 0x30: //Omega Red
    {
        if ((uPalId >= (0x09 + EXTRA_OMNI)) && (uPalId <= (0x20 + EXTRA_OMNI)))
        {
            SetExtraImg(11, uUnitId, uPalId);
        }

        break;
    }
    case 0x31: //Spiral
    {
        if ((uPalId >= (0x09 + EXTRA_OMNI)) && (uPalId <= (0x2A + EXTRA_OMNI)))
        {
            // Metamorphosis super
            int nOffs = (uPalId - (0x09 + EXTRA_OMNI)) * 2;

            // Ensure we're loading for the right character that Spiral is copying from.                
            nImgUnitId = MVC2_D_0x31_EXTRAREDIR[nOffs];
            nTargetImgId = 0xFF00 + MVC2_D_0x31_EXTRAREDIR[nOffs + 1];

            SetSourcePal(0, nImgUnitId, uPalId, MVC2_D_0x31_EXTRAREDIR[nOffs + 1], 1);
            break;
        }

        if (
            CreateExtraPal(uUnitId, uPalId, 0x2D, 0x1C, 11, 0, 6) || // power enhance
            CreateExtraPal(uUnitId, uPalId, 0x33, 0x1C, 12, 0, 6) || // speed enhance
            CreateExtraPal(uUnitId, uPalId, 0x3B, 0x1C, 12, 0, 12)   // metamorphosis
            )
        {
            break;
        }

        break;
    }
    case 0x32: //Colossus
    {
        if (uPalId >= (0x09 + EXTRA_OMNI))
        {
            SetExtraImg(0, uUnitId, uPalId);
        }

        break;
    }
    case 0x37: //Jin
    {
        // Power-up glow
        if ((uPalId >= (0x09 + EXTRA_OMNI)) && (uPalId <= (0x2C + EXTRA_OMNI)))
        {
            SetExtraImg(0, uUnitId, uPalId);
            break;
        }

        if (
            CreateExtraPal(uUnitId, uPalId, 0x2D, 6, 11, 0, 6)
            || CreateExtraPal(uUnitId, uPalId, 0x51, 3, 12)
            || CreateExtraPal(uUnitId, uPalId, 0x52, 3, 13)
            || CreateExtraPal(uUnitId, uPalId, 0x53, 3, 14)
            || CreateExtraPal(uUnitId, uPalId, 0x63, 6, 15, 0, 6)
            )
            break;

        break;
    }
    case 0x38: //CapCom
    {
        // Handle the joined ninja sprites
        if (SpecSel(&nSpecOffs, uPalId, 1, 8) || SpecSel(&nSpecOffs, uPalId, 2, 8))
        {
            bLoadDefPal = FALSE;

            //Create the img ticket
            ClearSetImgTicket(
                CreateImgTicket(uUnitId, 1,
                    CreateImgTicket(uUnitId, 2, NULL, 28, 4)
                )
            );

            //Set each palette
            sDescNode* NodeGet[2] = {
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 1, -1),
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 2, -1)
            };

            //Set each palette
            CreateDefPal(NodeGet[0], 0);
            CreateDefPal(NodeGet[1], 1);

            SetSourcePal(0, uUnitId, 1, 6, 8);
            SetSourcePal(1, uUnitId, 2, 6, 8);

            break;
        }

        nExtraAmt = 4;

        if (CreateExtraPal(uUnitId, uPalId, 0x09, 1, 11))
            break;

        nExtraAmt = 1;

        if (CreateExtraPal(uUnitId, uPalId, 0x0D, 1, 12))
            break;

        nExtraAmt = 6;

        if (
            CreateExtraPal(uUnitId, uPalId, 0x0E, 2, 13)
            || CreateExtraPal(uUnitId, uPalId, 0x0F, 2, 14)
            )
            break;

        break;
    }
    case 0x39: //Bonerine
    {
        if (SpecSel(&nSpecOffs, uPalId, 0, 8))
        {
            bLoadDefPal = FALSE;

            //Create the img ticket
            ClearSetImgTicket(
                CreateImgTicket(uUnitId, 0,
                    CreateImgTicket(uUnitId, 1, NULL, 25, 6)
                )
            );

            sDescNode* NodeGet[2] = {
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 0, -1),
                MainDescTree.GetDescNode(uUnitId, nSpecOffs, 1, -1)
            };

            //Set each palette
            CreateDefPal(NodeGet[0], 0);
            CreateDefPal(NodeGet[1], 1);

            SetSourcePal(0, uUnitId, 0, 6, 8);
            SetSourcePal(1, uUnitId, 1, 6, 8);
        }

        break;
    }
    case 0x3A: // Kobun
    {
        if ((uPalId == 0x1) ||
            (uPalId == 0x9) ||
            (uPalId == 0x11) ||
            (uPalId == 0x19) ||
            (uPalId == 0x21) ||
            (uPalId == 0x29))
        {
            // Tron Bonne body
            bLoadDefPal = FALSE;

            nImgUnitId = 0x10;
            nTargetImgId = 1;

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, 0, 6, 8);

            break;
        }
        else if ((uPalId == 0x2) || 
                 (uPalId == 0xA) ||
                 (uPalId == 0x12) ||
                 (uPalId == 0x1A) ||
                 (uPalId == 0x22) ||
                 (uPalId == 0x2A))
        {
            // Tron Bonne has a lunch sprite we can reuse here.
            bLoadDefPal = FALSE;

            nImgUnitId = 0x10;
            nTargetImgId = 0x0C;

            ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId));

            CreateDefPal(NodeGet, 0);

            SetSourcePal(0, uUnitId, 0, 6, 8);

            break;
        }
        else if ((uPalId == 0x6) ||
                 (uPalId == 0xE) ||
                 (uPalId == 0x16) ||
                 (uPalId == 0x1E) ||
                 (uPalId == 0x26) ||
                 (uPalId == 0x2E) ||
                 (uPalId == 0x7) || 
                 (uPalId == 0xF) ||
                 (uPalId == 0x17) ||
                 (uPalId == 0x1F) ||
                 (uPalId == 0x27) ||
                 (uPalId == 0x2F))
        {
            // Kobun assist sprites.
            SetExtraImg(0, uUnitId, 0x0);
            break;
        }
        else if ((uPalId >= (0x09 + EXTRA_OMNI)) && (uPalId <= (0x26 + EXTRA_OMNI)))
        {
            // King Kobun.  Just reuse the Kobun core sprite for now. :(
            SetExtraImg(0, uUnitId, uPalId);
            break;
        }
        break;
    }
    }

    if (bLoadDefPal)
    {
        int nBasicOffset = GetBasicOffset(uPalId);

        // bugbug: 
        if ((nImgUnitId == 0xA) && (nBasicOffset == 5))
        {
            // Rogue's darkened dash sprite is missing a sprite association in img.dat, so just reuse the normal dash sprite
            nBasicOffset = 4;
        }

        // I'm unclear why there's a flag here, but fImgIsFromNewImgDatRange allows us to sidestep compatibility concerns.
        const int nBitFlagToUse = fImgIsFromNewImgDatRange ? 0xFF : 0x0F;

        if (nTargetImgId > nBitFlagToUse)
        {
            OutputDebugString("WARNING: The desired nTargetImgId is out of range and is being modified\n");
        }

        ClearSetImgTicket(CreateImgTicket(nImgUnitId, nTargetImgId ? (nTargetImgId & nBitFlagToUse) : nBasicOffset));

        CreateDefPal(NodeGet, 0);

        if (nBasicOffset != -1)
        {
            SetSourcePal(0, uUnitId, nBasicOffset, 6, 8);
        }
        else
        {
            // Disable multisprite export for now.  Otherwise you would need to do the math.
            SetSourcePal(0, uUnitId, uPalId, 1, 1);
        }
        //else
        //{
        //    //SetSourcePal(0, uUnitId, uPalId, 0, 0);
        //}
    }

    return TRUE;
}
