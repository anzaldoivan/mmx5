#include "types.h"

extern s32 SsVabClose(s32);
extern s32 SsVabOpenHeadSticky(u8* addr, s32 vabid, s32 sbaddr);
extern s32 SsVabTransBodyPartly(s32, s32, s32);
extern s32 SsVabTransCompleted(s32);

extern u8 D_800E6B78;
extern u8* D_8009E79C;
extern s32 D_8009E798;
extern s8 D_80093E60[];
extern s32 D_8009A750[];
extern u8* D_8009A730[];
extern u8* D_8009A770[];

s32 func_800169C4(s32 arg0) {
    u8* p;
    u8* q;
    u8* v;
    u8* src;
    s8* slot;
    u8* addr;
    u32 hdr;
    s8 id;
    s32 n;
    s32 r;
    s32 idx;

    idx = arg0 & 0xFF;
    p = &D_800E6B78;
    switch (D_800E6B78) {
    case 0:
        src = D_8009E79C;
        slot = &D_80093E60[idx];
        hdr = *(u32*)src;
        *(s32*)(p + 8) = 0;
        addr = src + (hdr & 0xFFFFFF);
        *(s32*)(p + 4) = ((s32*)src)[1];
        p[1] = hdr >> 24;
        SsVabClose(*slot);
        id = SsVabOpenHeadSticky(addr, p[1], D_8009A750[idx]);
        if (id == -1) {
            return -1;
        }
        *slot = id;
        D_8009A730[idx] = addr;
        D_8009A770[idx] = D_8009E79C + 8;
        D_800E6B78++;
    case 1:
        q = &D_800E6B78;
        n = *(s32*)(q + 4);
        if (n > 0x1000) {
            n = 0x1000;
        }
        r = SsVabTransBodyPartly(D_8009E798 + *(s32*)(q + 8), n, q[1]);
        if (r == -1) {
            return -1;
        }
        SsVabTransCompleted(1);
        *(s32*)(q + 4) -= n;
        *(s32*)(q + 8) += n;
    default:
        v = &D_800E6B78;
        if (r == v[1]) {
            D_800E6B78 = 0;
        }
        return r;
    }
}
