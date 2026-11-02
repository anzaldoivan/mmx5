#include "types.h"

extern s32 func_80014464(void);
extern void* func_80066D98(void* func);
extern s32 CdControlB(s32, s32, u8*);

extern u16 D_800E5A46;
extern u16 D_800E5A44;
extern u8 D_800E5A3D;
extern u32 D_800E5A2C;
extern u16 D_80070368[][2];
extern u16 D_800D51F8;
extern u16 D_800D51FA;
extern u16 D_800D51FC;
extern u8 D_800E5209;
extern u8* D_800E5A1C;
extern u8 D_800D5208[];
extern u8 D_80091D50;
extern u8 D_8009811C;

extern Rec5A58 D_800E5A58[];

void func_80014DEC(void) {
    u16* p;

    D_800E5A46++;
    if (D_800E5A46 - D_800E5A44 >= 0x20) {
        goto fail; // !FAKE: goto kept for the matching branch layout
    }
    {
        if (D_800E5A3D != 0) {
            D_800E5A3D = 0;
            p = D_80070368[(u8)D_800E5A2C];
            *(volatile u16*)&D_800D51F8 =
                p[0]; // !FAKE: volatile pair orders the store before the reload
            D_800D51FA =
                ((volatile u16*)
                     p)[1]; // !FAKE: volatile keeps the load after the store
            D_800D51FC = D_800D51FA & 0x100;
        }
        D_800E5A1C = D_800D5208 + D_800E5209 * 0x800;
        if (func_80014464() == -1) {
        fail:
            func_80066D98(0);
            CdControlB(9, 0, 0);
            D_8009811C = 0x80;
            return;
        }
        {
            D_80091D50 = 1;
            D_800E5A58[D_800E5209].unk0 = 1;
            D_800E5A58[D_800E5209].unk1 = 1;
            D_800E5A58[D_800E5209].unk4 = (D_800D51F8 << 16) | D_800D51FA;
            D_800E5209++;
            if (D_800E5209 == 0x20) {
                D_800E5209 = 0;
            }
            switch ((D_800E5A2C & 0xFF00) >> 8) {
            case 0:
                if (D_800D51FA == D_800D51FC + 0xF0) {
                    D_800D51F8 += 0x40;
                    D_800D51FA = D_800D51FC;
                } else {
                    D_800D51FA += 0x10;
                }
                break;
            case 1:
                if (D_800D51FA == D_800D51FC + 0xA0) {
                    D_800D51F8 += 0x40;
                    D_800D51FA = D_800D51FC;
                } else {
                    D_800D51FA += 0x10;
                }
                break;
            case 2:
                if (D_800D51FA == 0xF0) {
                    D_800D51FA = 0xB0;
                    D_800D51F8 += 0x40;
                } else {
                    D_800D51FA += 0x10;
                }
                break;
            case 3:
                if (D_800D51FA == 0) {
                    D_800D51FA = 0xA0;
                    D_800D51F8 -= 0x40;
                } else {
                    D_800D51FA -= 0x10;
                }
                break;
            case 4:
                if (D_800D51FA == D_800D51FC + 0xA0) {
                    D_800D51FA = 0x10;
                    D_800D51F8 += 0x40;
                } else {
                    D_800D51FA += 0x10;
                }
                break;
            }
        }
    }
}
