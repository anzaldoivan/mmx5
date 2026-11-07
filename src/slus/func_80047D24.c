#include "types.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8002DED4(u8* obj);
extern s32 func_8002FB58(u8* obj);
extern u8 D_8007706C[];

void func_80047D24(u8* obj) {
    u8 f;

    func_8002DED4(obj);
    if (obj[0x15] != 0) {
        if (*(s32*)(obj + 0x20) < 0) {
            *(s32*)(obj + 0x28) = 0;
            goto clear; // !FAKE: goto kept for the matching branch layout
        }
    } else if (*(s32*)(obj + 0x20) > 0) {
        *(s32*)(obj + 0x28) = 0;
    clear: // !FAKE: label kept for the matching branch layout
        *(s32*)(obj + 0x20) = 0;
    }
    if (*(s8*)(obj + 0x98) != 0 || obj[0x70] != 0) {
        obj[0x8D] = 0x78;
        obj[0x8E] = 0;
        obj[0x8F] = 0x14;
        obj[0x90] = 0;
        func_800171E8(obj, 1);
        obj[5]++;
        if (*(s8*)(obj + 0x98) == 0 && (f = obj[0x70], (f & 0xF) != 0xF) &&
            !(f & 8)) {
            if (f & 2) {
                obj[0x8C] = 1;
            } else if (f & 1) {
                obj[0x8C] = 2;
            } else {
                goto zero; // !FAKE: goto kept for the matching branch layout
            }
        } else {
        zero: // !FAKE: label kept for the matching branch layout
            obj[0x8C] = 0;
        }
        *(u8**)(obj + 0x50) = D_8007706C;
        *(s32*)(obj + 0x68) = 0;
        obj[0x98] = 0;
    }
    func_8002FB58(obj);
}
