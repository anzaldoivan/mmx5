#include "types.h"
#include "mmx5/globals.h"
#include "mmx5/sound.h"

extern void func_80013288(s32);
extern s32 func_8002002C(s32);
extern u8* func_8002D2DC(void);
extern u8 D_8006FADB;
extern u8 D_80073040[];
extern u8 D_80073064[];
extern u8 D_80073088[];
extern u8 D_800D1D10;

void func_8002B6C0(void) {
    u8* o;
    u8* p;

    o = func_8002D2DC();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0;
        o[2] = 0x20;
        o[0x47] = 0;
        *(s16*)(o + 0xE) = 0x18;
    }
    o = func_8002D2DC();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0;
        ((s8*)o)[2] = -1;
        *(s16*)(o + 0xA) = 0x20;
        *(u8**)(o + 0x50) = D_80073088;
    }
    if (D_8009A420[8] != 0) {
        p = D_80073040;
    } else {
        p = D_80073064;
    }
    while (*p != 0xFF) {
        o = func_8002D2DC();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0;
            o[2] = 0x10;
            o[0x47] = p[0];
            *(s16*)(o + 0xE) = p[1];
            o[7] = p[2];
        }
        p += 3;
    }
    for (p = D_80073088; *p != 0xFF; p += 2) {
        o = func_8002D2DC();
        if (o != 0) {
            o[0] = 1;
            o[1] = 0;
            o[2] = p[1];
            *(s16*)(o + 0xE) = p[0] + 8;
        }
        if (p[1] == 9) {
            break;
        }
    }
    o = func_8002D2DC();
    if (o != 0) {
        o[0] = 1;
        o[1] = 0;
        ((s8*)o)[2] = -2;
    }
    if (D_8009A420[8] == 0) {
        func_8002002C(0);
        if (D_8009A420[8] == 0) {
            D_8006FADB = D_800D1D10;
        }
    }
    D_8009A420[7] = 0;
    func_80013288(8);
    D_800E9300.u++;
}

#define D_8009A420_as_Sel800218E0 (*(Sel800218E0*)&D_8009A420)
#define D_800C931C_as_Pad800218E0 (*(Pad800218E0*)&g_pad1_buttons)

extern u16 D_80073020[];
extern u16 g_button_map[];
extern u16 D_80073030[];
extern u8 D_8006FADB;
extern u8 D_8007301C[];
extern void func_800132F8(s8 arg);

void func_8002B8F0(void) {
    u8 i;
    u8 j;
    u8 slot;
    u16 tmp;
    u16 btn;
    u16 val;

    if (D_8009A420_as_Sel800218E0.unk4 != 0) {
        return;
    }
    if ((D_800C931C_as_Pad800218E0.unk4 & 0x800) ||
        ((D_800C931C_as_Pad800218E0.unk4 & 0x40) &&
         D_8009A420_as_Sel800218E0.unk7.u == 10)) {
        play_sound(0, 0x22, 0);
        func_800132F8(8);
        D_800E9300.u++;
        return;
    }
    if (D_800C931C_as_Pad800218E0.unk4 & 0x1000) {
        play_sound(0, 0xC, 0);
        if (D_8009A420_as_Sel800218E0.unk7.u == 0) {
            D_8009A420_as_Sel800218E0.unk7.u = 10;
        } else {
            D_8009A420_as_Sel800218E0.unk7.u--;
        }
    }
    if (D_800C931C_as_Pad800218E0.unk4 & 0x4000) {
        play_sound(0, 0xC, 0);
        if (D_8009A420_as_Sel800218E0.unk7.u == 10) {
            D_8009A420_as_Sel800218E0.unk7.u = 0;
        } else {
            D_8009A420_as_Sel800218E0.unk7.u++;
        }
    }
    if (D_8009A420_as_Sel800218E0.unk7.u < 7) {
        slot = 0xFF;
        for (i = 4; i < 16; i++) {
            if ((1 << i) == D_80073020[D_8009A420_as_Sel800218E0.unk7.u]) {
                slot = i;
                break;
            }
        }
        if (slot != 0xFF) {
            btn = D_800C931C_as_Pad800218E0.unk4;
            for (i = 0; i < 8; i++) {
                if (btn == D_80073030[i]) {
                    play_sound(0, 0x22, 0);
                    val = D_80073030[i];
                    tmp = g_button_map[slot];
                    g_button_map[slot] = val;
                    if (g_button_map[0] != 0) {
                        j = 0;
                        do {
                            if (j != slot && g_button_map[j] == D_80073030[i]) {
                                g_button_map[j] = tmp;
                            }
                        } while (g_button_map[++j] != 0);
                    }
                    return;
                }
            }
        }
    } else if (D_8009A420_as_Sel800218E0.unk7.u < 10) {
        if (D_800C931C_as_Pad800218E0.unk4 & 0x40) {
            play_sound(0, 0x22, 0);
            D_8006FADB ^= D_8007301C[D_8009A420_as_Sel800218E0.unk7.u - 7];
        }
    }
}
