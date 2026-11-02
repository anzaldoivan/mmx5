#include "types.h"
#include "addr.h"

extern void func_80017348(u8* a0, s32 a1, s32 a2);
extern void func_8002D6FC(u8* obj);

void func_80050D04(u8* obj) {
    s32 big;

    big = 0;
    if (((s8*)obj)[2] == 0) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x8);
    } else if (((s8*)obj)[2] == 1) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0xC);
    } else if (((s8*)obj)[2] == 2) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x14);
    } else if (((s8*)obj)[2] == 3) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x18);
    } else if (((s8*)obj)[2] == 4) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x20);
    } else if (((s8*)obj)[2] == 5) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x24);
    } else if (((s8*)obj)[2] == 6) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x1C);
    } else if (((s8*)obj)[2] == 7) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x2C);
        big = 1;
    } else if (((s8*)obj)[2] == 8) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x30);
    } else if (((s8*)obj)[2] == 9) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x2C);
        big = 1;
    } else if (((s8*)obj)[2] == 10) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x2C);
        big = 1;
    } else if (((s8*)obj)[2] == 11) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x30);
        big = 1;
    } else if (((s8*)obj)[2] == 12) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x34);
        big = 1;
    } else if (((s8*)obj)[2] == 13) {
        *(u8**)(obj + 0x38) = D_1F800014 + *(s32*)(D_1F800014 + 0x38);
        big = 1;
    }
    obj[0x48] = 0xFF;
    obj[0x47] = 0;
    if (big == 0) {
        *(s16*)(obj + 0x40) = 0x520;
        obj[0x49] = 0;
        func_80017348(obj, 0x140, 0x20);
    } else {
        *(s16*)(obj + 0x40) = 0x540;
        obj[0x49] = 1;
        func_80017348(obj, 0x140, 0x40);
    }
    func_8002D6FC(obj);
}
