#include "types.h"
#include "mmx5/globals.h"

extern void func_8003763C(u8* arg0);
extern void func_8003CEDC(u8* arg0, s32 arg1);
extern void func_8003C5D8(u8* obj);
extern void func_8003AA4C(u8* arg0);
extern void func_8003CFA8(u8* arg0);

void func_80037330(u8* arg0) {
    func_8003763C(arg0);
    if (((s8*)arg0)[2] == 0) {
        if (arg0[0x47] == 0xEC) {
            func_8003CEDC(arg0, 0x52);
        } else {
            func_8003C5D8(arg0);
        }
    }
    if (((s8*)arg0)[0x61] == 0x3C) {
        func_8003AA4C(arg0);
        if (((s8*)arg0)[0xD3] != 0) {
            arg0[0xA4] = 0;
            arg0[0x61] = 0;
        } else {
            func_8003CFA8(arg0);
            ((s8*)arg0)[0xA4] = -1;
        }
    }
}

extern void func_8003763C(u8* arg0);
extern void func_8003D344(void* arg0);
extern void func_8003A670(u8* arg0);
extern void func_8003A94C(u8* obj);
extern void func_8003CFA8(u8* arg0);

void func_800373D0(u8* obj) {
    func_8003763C(obj);
    func_8003D344(obj);
    if (*(s8*)(obj + 6) == 0) {
        obj[6] = obj[6] + 1;
        return;
    }
    if (*(s8*)(obj + 0x67) != 0 && (obj[0x89] & 8)) {
        obj[0x67] = 0;
        if (obj[0x15] != 0) {
            *(s32*)(obj + 0x20) = -0x8000;
        } else {
            *(s32*)(obj + 0x20) = 0x8000;
        }
        *(s32*)(obj + 0x24) = 0;
        *(s32*)(obj + 0x2C) = 0;
    }
    if (*(s8*)(obj + 0x61) == 0x3C) {
        if (obj[0x89] & 8) {
            obj[0x67] = 0;
            func_8003A670(obj);
        } else if (*(s32*)(obj + 0x2C) != 0) {
            func_8003B33C(obj, 0xB);
            *(s8*)(obj + 0x67) = -1;
            obj[5] = 7;
            obj[6] = 0;
        } else {
            func_8003A94C(obj);
        }
        if (*(s8*)(obj + 0xD3) != 0) {
            obj[0xA4] = 0;
            obj[0x61] = 0;
            return;
        }
        func_8003CFA8(obj);
        *(s8*)(obj + 0xA4) = -1;
    }
}

extern void func_800376EC(u8* arg0);
extern void func_8003D344(void* arg0);
extern void func_8003A94C(u8* obj);
extern void func_8003CFA8(u8* arg0);

void func_800374FC(u8* arg0) {
    func_800376EC(arg0);
    func_8003D344(arg0);
    if (((s8*)arg0)[6] == 0) {
        arg0[6]++;
    } else if (((s8*)arg0)[0x61] == 0x3C) {
        func_8003A94C(arg0);
        if (((s8*)arg0)[0xD3] != 0) {
            arg0[0xA4] = 0;
            arg0[0x61] = 0;
        } else {
            func_8003CFA8(arg0);
            ((s8*)arg0)[0xA4] = -1;
        }
    }
}

extern void func_8003AA4C(u8* arg0);

void func_80037588(u8* arg0) {
    s8 state;

    if (*(u16*)(arg0 + 0x7C) & 2) {
        arg0[0x15] = 0;
    }
    if (*(u16*)(arg0 + 0x7C) & 1) {
        arg0[0x15] = 0x40;
    }
    state = arg0[0xCA];
    if (state > 0) {
        return;
    }
    if (state == 0) {
        arg0[0xA4] = 0;
        func_8003AA4C(arg0);
    } else if (state == -1) {
        func_8003B33C(arg0, 0x25);
        ((s8*)arg0)[0xCA] = -2;
    } else if (((s8*)arg0)[0x46] < 0) {
        func_8003B33C(arg0, 0x24);
        arg0[0xCA] = 1;
    }
}
