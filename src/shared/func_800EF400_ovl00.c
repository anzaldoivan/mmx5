/* Shared body (DK-5), from the banked draft of func_800EF400_ovl00 by tools/wave/gate.py rescan. */
#include "types.h"
#include "addr.h"

extern void func_800171E8(u8* obj, s32 state);
extern void func_8001296C(s32);
extern s32 func_80016490(s32, s32, void*);
extern void func_8002A600(s32, s32, s32);
extern void func_800EF91C_ovl00(s32, s16, s16, s16, s16, s32);
extern s16 D_8009A1F8[];

void DEDUP_NAME(u8* obj) {
    u8* q;
    u8* p;
    s8 st;

    if (D_1F80004C.bytes[0x90] == 0) {
        q = *(u8**)(D_1F80004C.bytes + 0x80);
        if (((s8*)q)[2] == 0) {
            st = ((s8*)q)[5];
            if (st == 3) {
                func_800171E8(obj, 1);
                obj[5] = st;
                obj[6] = 0;
                return;
            }
        }
        if (obj[0x70] & 8) {
            p = *(u8**)(D_1F80004C.bytes + 0x80);
            p[0x87] = 1;
            func_8001296C(8);
            func_80016490(5, 5, 0);
            if (D_8009A1F8[0x10] == D_8009A1F8[7]) {
                func_8002A600(8, 4, 2);
            }
            func_800EF91C_ovl00(
                0x11, *(s16*)(obj + 0xA), *(s16*)(obj + 0xE) + 0x10,
                *(s16*)(obj + 0xA) + 0x1C, *(s16*)(obj + 0xE) + 0x20, 3);
            func_800EF91C_ovl00(0x12, *(s16*)(obj + 0xA) - 0x1C,
                                *(s16*)(obj + 0xE) + 0x10, *(s16*)(obj + 0xA),
                                *(s16*)(obj + 0xE) + 0x20, 3);
            obj[6] = 2;
            *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x8A) =
                *(s16*)(obj + 0xE) -
                *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xE);
        }
        *(s16*)(obj + 0xA) = *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xA);
        *(s16*)(obj + 0xE) = *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xE) +
                             *(s16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0x8A);
    }
}
