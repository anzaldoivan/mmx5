#include "types.h"
#include "addr.h"

extern s32 GetTPage(s32 tp, s32 abr, s32 x, s32 y);
extern void SetDrawMode(u8* p, s32 dfe, s32 dtd, s32 tpage, void* tw);
extern u8 D_8007029C[];
extern s32 D_8009A420;
extern u8* D_8009E794;

void func_80013C04(u8 a0) {
    u8* poly;
    u8* mode;
    u8* e;
    u8 c;
    u8* ot;
    u32 lo;

    if (a0 != 0 || !(D_8009A420 & 0x10)) {
        poly = D_1F800100;
        mode = D_1F800104;
        e = D_8007029C + a0 * 8;
        SetDrawMode(mode, 0, 0, GetTPage(0, 0, 0x380, 0x100), 0);
        poly[3] = 4;
        poly[7] = 0x64;
        *(u16*)(poly + 0x8) = *(u16*)(e + 0);
        *(u16*)(poly + 0xA) = *(u16*)(e + 2);
        poly[0xC] = e[4] << 4;
        poly[0xD] = e[4] & 0xF0;
        c = e[7];
        poly[7] = 0x65;
        *(u16*)(poly + 0xE) = (c & 0xF) | (((c >> 4) + 0x1E0) << 6);
        *(u16*)(poly + 0x10) = e[5] << 4;
        *(u16*)(poly + 0x12) = e[6] << 4;
        lo = (u32)mode & 0xFFFFFF;
        *(u32*)mode = (*(u32*)mode & 0xFF000000) | ((u32)poly & 0xFFFFFF);
        mode += 0xC;
        ot = D_8009E794;
        *(u32*)poly =
            (*(u32*)poly & 0xFF000000) | (*(u32*)(ot + 0x80) & 0xFFFFFF);
        poly += 0x14;
        *(u32*)(ot + 0x80) = (*(u32*)(ot + 0x80) & 0xFF000000) | lo;
        D_1F800100 = poly;
        D_1F800104 = mode;
    }
}
