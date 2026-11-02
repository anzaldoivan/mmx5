#include "types.h"

extern s32 func_800182D8(u8* src, u8* dst);
extern RectPtrPair* D_8009A788;
extern u8 D_800CD598[];
extern u8 D_800CE598[];

void func_80017348(u8* obj, s16 x, s16 y) {
    u8* base;
    u32 word;
    s16 n;
    u8* dst;
    RectPtrPair* p;
    s16 h;
    s8 bank;

    if (obj[0x48] != obj[0x47]) {
        obj[0x48] = obj[0x47];
        base = *(u8**)(obj + 0x38);
        bank = obj[0x49];
        word = ((u32*)base)[obj[0x47]];
        n = word >> 20;
        if (bank == 3) {
            dst = D_800CD598;
        } else {
            dst = D_800CE598 + (bank << 12);
        }
        func_800182D8(base + (word & 0xFFFFF), dst);
        p = D_8009A788;
        do {
            p->rect.unk0 = x;
            p->rect.unk2 = y;
            p->ptr = dst;
            if (n < 16) {
                p->rect.unk4 = n * 4;
                n = 0;
                p->rect.unk6 = 16;
            } else {
                p->rect.unk4 = 0x40;
                h = (s16)(n / 16) * 16;
                p->rect.unk6 = h;
                y += h;
                n -= h;
                dst += 0x800;
            }
            p++;
        } while (n != 0);
        p->ptr = 0;
        D_8009A788 = p;
    }
}
