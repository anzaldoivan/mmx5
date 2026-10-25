#include "types.h"

extern s16 D_8009A0AA;
extern s32 func_80016490(s32, s32, void*);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DED4(u8* obj);

void func_800F9B74_ovl28(u8* obj) {
    s16 d;

    if (++*(s16*)(obj + 0x7C) >= 11) {
        d = D_8009A0AA - *(s16*)(obj + 0xA);
        if (*(s32*)(obj + 0x20) < 0) {
            if (d < -0x40) {
                goto end; // !FAKE: goto kept for the matching branch layout
            }
        } else if (d > 0x40) {
            goto end; // !FAKE: goto kept for the matching branch layout
        }
        func_80016490(2, 0x86, obj);
        obj[6]++;
        *(s32*)(obj + 0x20) = 0;
    }
end:
    func_8002D9EC(obj, 0x30, 0x30);
    func_8002DED4(obj);
}
