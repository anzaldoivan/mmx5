#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_80017248(u8* obj);
extern void func_80017348(u8* a0, s32 a1, s32 a2);
extern void func_8002D6FC(u8* obj);
extern s32 func_8002D938(u8* a0, s32 a1, s32 a2, u8* a3);
extern void func_8002D9EC(u8* a0, s32 a1, s32 a2);
extern void func_8002DF54(u8* a0);
extern s32 func_8002F8FC(u8* a0);
extern u8 D_80077258[];
extern u8 D_8007725C[];
extern u8 D_8007B3D8[];
extern u8 D_8009A0A0[];

void func_8004BB18(u8* obj) {
    u8* d = D_8009A0A0;
    u8* p;
    u8* p2;
    s32 q;
    s32 one;

    if (*(s8*)(obj + 4) == 0) {
        one = 1;
        obj[3] = one;
        *(u8**)(obj + 0x68) = D_80077258;
        *(u8**)(obj + 0x50) = D_8007725C;
        p = D_1F80001C.bytes;
        *(u8**)(obj + 0x3C) = p + *(s32*)(p + 0x20);
        p2 = D_1F800014;
        q = *(s32*)(p2 + 0xC);
        *(u8**)(obj + 0x30) = D_8007B3D8;
        *(s16*)(obj + 0x40) = 0x520;
        *(s16*)(obj + 0x42) = 0x7802;
        obj[0x16] = one;
        *(u8**)(obj + 0x38) = p2 + q;
        if (obj[0x15] == 0) {
            *(s16*)(obj + 0xA) = *(u16*)(d + 0xA) - 0x18;
        } else {
            *(s16*)(obj + 0xA) = *(u16*)(d + 0xA) + 0x18;
        }
        *(s16*)(obj + 0xE) = *(u16*)(d + 0xE) + 6;
        *(s32*)(obj + 0x24) = 0xFFF80000;
        *(s32*)(obj + 0x20) = 0;
        func_800171E8(obj, 3);
        obj[0x48] = 0xFF;
        obj[0x49] = 0;
        func_80017348(obj, 0x140, 0x20);
        obj[4]++;
        goto tail; // !FAKE: goto kept for the matching branch layout
    }
    if (func_8002D938(obj, 0x10, 0x20, d) == 0 && *(s8*)(obj + 0x98) == 0 &&
        obj[0x70] == 0) {
        func_8002F8FC(obj);
        if (obj[0x70] == 0) {
            func_80017248(obj);
            func_8002DF54(obj);
            goto tail; // !FAKE: goto kept for the matching branch layout
        }
    }
    func_8002D6FC(obj);
    return;
tail: // !FAKE: shared tail placed last, as the target lays it out
    func_8002D9EC(obj, 0x10, 0x20);
}
