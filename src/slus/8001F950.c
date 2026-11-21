#include "types.h"
#include "mmx5/globals.h"
#include "addr.h"

extern void LoadImage(void*, void*);
extern void func_80013288(int);
extern u8 D_80070C54;
extern u8 D_8009A427;
extern u8 D_80070FB8;
extern u8 D_8009A1F8[];
extern u8 D_80071040;
extern u8 D_80070FD0;

static inline u8* func_8001F950_spawn(u8* p) {
    u8* obj;
    u8 i;
    s32 one;

    i = 0;
    one = 1;
    if (*p != 0) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = one;
            obj[1] = 0x20;
            *(u8**)(obj + 0x50) = p;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    } else {
        p++;
    }
    while (*p != 0xFF) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x1F;
            obj[2] = *p++;
            obj[7] = i++;
            *(u16*)(obj + 0xE) = *p++;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    }
    return p;
}

void func_8001F950(u8* arg0) {
    u8* p;
    u8* addr;

    func_8002C50C();
    D_8009A427 = 0;
    if (D_80070C54 != 0xFF) {
        p = func_8001F950_spawn(&D_80070FB8);
        *(u16*)(arg0 + 8) = p[1];
        arg0[1] = arg0[1] + 1;
    } else {
        p = func_8001F950_spawn(&D_80070FD0);
        *(u16*)(arg0 + 8) = p[1];
        arg0[1] = arg0[1] + 3;
    }
    addr = D_801F3000 + D_801F3004;
    D_8009A1F8[3] = 0;
    D_8009A1F8[0x57] = 0;
    D_8009A1F8[0xAB] = 0;
    LoadImage(&D_80071040, addr);
    func_80013288(8);
}

extern void create_task(s32, void (*)(void));
extern void func_80012EAC(void);
extern void func_8001CC34(u8*, u8*);
extern u8 D_80070C54;
extern u8 D_8009A1F8[];
extern u8 D_800C9310;
extern u8 D_800D1C00[];
extern void func_80020904(void);

void func_8001FBCC(u8* arg0) {
    u8* p;

    if ((s8)D_8009A420[4] == 0) {
        if (D_8009A420[7] != 1) {
            D_800C9310 |= 1;
        }
        switch (*(s16*)(arg0 + 0xA)) {
        case 0:
            func_8001CC34(&D_80070C54, arg0);
            if (D_800D1C00[0x194] == 0xFF) {
                D_800D1C00[0] = 3;
                D_800D1C00[1] = 0;
                D_800D1C00[2] = 0;
                D_800D1C00[3] = 0;
            } else {
                D_800D1C00[0] = 0x13;
                D_800D1C00[1] = 0;
                D_800D1C00[2] = 0;
                D_800D1C00[3] = 0;
                D_800D1C00[0x1D] = D_800D1C00[0x194];
            }
            create_task(1, func_80020904);
            func_80012EAC();
            return;
        case 1:
            arg0[0] = 9;
            D_800D1C00[1] = 0;
            D_800D1C00[2] = 0;
            D_800D1C00[3] = 0;
            return;
        case 2: // !FAKE: rebalances the case tree
        default:
            p = D_8009A1F8;
            *(s16*)(p + 0xA) = 0;
            *(s16*)(p + 0xE) = 0;
            p[0x4C] = 1;
            p[3] = 1;
            arg0[0] = 6;
            arg0[1] = 0;
            arg0[2] = 0;
            arg0[3] = 0;
            break;
        }
    }
}

extern u8 D_80070C54;
extern u8 D_8009A427;
extern u8 D_80070FB8;
extern u8 D_80070FD0;

static inline u8* func_8001FCF8_spawn(u8* p) {
    u8* obj;
    u8 i;
    s32 one;

    i = 0;
    one = 1;
    if (*p != 0) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = one;
            obj[1] = 0x20;
            *(u8**)(obj + 0x50) = p;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    } else {
        p++;
    }
    while (*p != 0xFF) {
        obj = func_8002D27C();
        if (obj != 0) {
            obj[0] = 1;
            obj[1] = 0x1F;
            obj[2] = *p++;
            obj[7] = i++;
            *(u16*)(obj + 0xE) = *p++;
            *(u16*)(obj + 0xA) = *p++;
            obj[0x55] = one;
        }
    }
    return p;
}

void func_8001FCF8(u8* arg0) {
    u8* p;

    func_8002C50C();
    D_8009A427 = 0;
    if (D_80070C54 != 0xFF) {
        p = func_8001FCF8_spawn(&D_80070FB8);
        *(u16*)(arg0 + 8) = p[1];
        arg0[1] = 1;
    } else {
        p = func_8001FCF8_spawn(&D_80070FD0);
        *(u16*)(arg0 + 8) = p[1];
        arg0[1] = 3;
    }
}
