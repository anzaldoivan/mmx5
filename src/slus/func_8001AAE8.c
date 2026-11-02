#include "types.h"

extern int VSync(int mode);
extern s32 StGetNext(u32** addr, StHdr8130** hdr);
extern void DecDCTReset(s32 mode);
extern void DecDCTin(u32* buf, s32 mode);
extern void DecDCTout(u32* buf, s32 size);
extern void DecDCTvlc(u32* bs, u32* buf);
extern void StFreeRing(u32* base);

extern u32 D_800E80F8;
extern u32* D_800E8108[2];
extern u32* D_800E8110;
extern u32 D_800E8114;
extern s32 D_800E8118;
extern s32 D_800E8120;
extern StHdr8130 D_800E8130;
extern s32 D_800E8150;
extern s32 D_800E8154;
extern Ovl50Pos D_800E8158;
extern u32* D_800E8160;
extern s32 D_800E8164;
extern s32 D_800E8168;
extern u32 D_800E816C;
extern u32 D_800E8170;
extern s32 D_800E8178;
extern s32 D_800E817C;

s32 func_8001AAE8(s32 arg0, s32 arg1) {
    u32* addr;
    StHdr8130* hdr;
    u32 cnt;
    s32 ret;
    s32 h;
    s32 h2;
    s32 t;
    s32 t2;

    cnt = 0;
    while (StGetNext(&addr, &hdr) != 0) {
        VSync(0);
        cnt++;
        if (cnt >= 0x259) {
            return 1;
        }
    }
    D_800E8158.unk0 = arg0;
    D_800E8158.unk2 = arg1;
    D_800E8150--;
    D_800E8178 = D_800E8130.unk10;
    D_800E817C = D_800E8130.unk12;
    D_800E80F8 = D_800E8130.unk8;
    ret = D_800E8130.unk8 >= D_800E8114;
    D_800E8158.unk4 = D_800E8118 ? 0x18 : 0x10;
    D_800E816C = 0;
    D_800E8170 = (u32)D_800E8178 >> 4;
    D_800E8158.unk6 = D_800E817C;
    D_800E8160 = D_800E8110;
    h = D_800E8130.unk12;
    D_800E8168 = D_800E8118 ? (t = h << 2, (h << 3) + t) : h << 3;
    if (D_800E8154 == 0) {
        D_800E8164 = 0;
    } else {
        h2 = D_800E817C;
        D_800E8164 = D_800E8118 ? (t2 = h2 << 2, (h2 << 3) + t2) : h2 << 3;
    }
    DecDCTReset(1);
    DecDCTin(D_800E8108[D_800E8120], D_800E8118);
    DecDCTout(D_800E8110, D_800E8168);
    D_800E8120 = D_800E8120 == 0;
    D_800E8130 = *hdr;
    D_800E8130.unk10 = (D_800E8130.unk10 + 8) / 16 * 16;
    D_800E8130.unk12 = (D_800E8130.unk12 + 8) / 16 * 16;
    DecDCTvlc(addr, D_800E8108[D_800E8120]);
    StFreeRing(addr);
    return ret;
}
