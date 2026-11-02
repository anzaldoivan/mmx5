#include "types.h"

extern s32 SsVabOpenHeadSticky(u8* addr, s32 vabid, s32 sbaddr);
extern void SpuSetTransferMode(s32 mode);
extern s8 func_80014464(void);
extern void* func_80066D98(void* func);
extern s32 CdControlB(s32, s32, u8*);

extern u16 D_800E5A46;
extern u16 D_800E5A44;
extern u32 D_800E5A2C;

extern Rec5A58 D_800E5A58[];
extern u8 D_800E5209;
extern u8 D_800E5A3D;
extern s32 D_8009A750[];
extern s32 D_800E5BE4;
extern u32* D_8009A748;
extern u8* D_8009A770[];
extern u8* D_8009A730[];
extern s8 D_80093E60[];
extern s32 D_800E5A18;
extern s32 D_800E5A38;
extern u8* D_800E5A1C;
extern u8 D_800D5208[];
extern u8 D_80091D50;
extern u8 D_8009811C;

void func_80015068(void) {
    s32 slot;
    u8* vab;
    s32 size;
    s32 vabid;
    u32* hdr;

    D_800E5A46++;
    if (D_800E5A46 - D_800E5A44 >= 0x20) {
        func_80066D98(0);
        CdControlB(9, 0, 0);
        D_8009811C = 0x80;
        return;
    }
    slot = (D_800E5A2C >> 8) & 0xFF;
    D_800E5A58[D_800E5209].unk8 = 0;
    vabid = (u8)D_800E5A2C;
    if (D_800E5A3D != 0) {
        hdr = D_8009A748;
        D_8009A750[slot] = D_800E5BE4;
        D_8009A770[slot] = (u8*)(hdr + 2);
        vab = (u8*)hdr + (*hdr & 0xFFFFFF);
        D_8009A730[slot] = vab;
        D_80093E60[slot] = SsVabOpenHeadSticky(vab, vabid, D_800E5BE4);
        if (D_80093E60[slot] == -1) {
            func_80066D98(0);
            CdControlB(9, 0, 0);
            D_8009811C = 0x80;
            return;
        }
        SpuSetTransferMode(0);
        size = D_800E5A18;
        D_800E5A3D = 0;
        D_800E5A58[D_800E5209].unk8 = 0xFFFF;
        D_800E5A38 = size;
        D_800E5BE4 += size;
    }
    D_800E5A1C = D_800D5208 + (D_800E5209 << 11);
    if (func_80014464() == -1) {
        func_80066D98(0);
        CdControlB(9, 0, 0);
        D_8009811C = 0x80;
    } else {
        D_80091D50 = 1;
        D_800E5A58[D_800E5209].unk0 = 1;
        D_800E5A58[D_800E5209].unk1 = 2;
        D_800E5A58[D_800E5209].unk4 = slot;
        if (++D_800E5209 == 0x20) {
            D_800E5209 = 0;
        }
    }
}
