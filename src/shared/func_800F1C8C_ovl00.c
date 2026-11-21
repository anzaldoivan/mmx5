#include "types.h"
#include "mmx5/title.h"
#include "mmx5/globals.h"
#include "addr.h"
#include "mmx5/system.h"

extern void func_80054440(u8* a0, s32 a1);
extern void func_8004D4F4(s32 a0, void* a1, u8* a2);
extern u8 D_8009A197;
extern void* D_800FAD10_ovl00[];
extern u8 D_80074EE0[];
extern u8 D_800FAA1C_ovl00[];
extern u8 D_800FAA20_ovl00[];
extern u8 D_80075200[];
extern u8 D_800FAC8C_ovl00[];

void func_800F1C8C_ovl00(u8* arg0) {
    u8* s;
    s32 r;
    u8 m;
    u8* t;

    if (D_8009A197 == 0) {
        *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
        *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
        animate_object(arg0);
        ((void (*)(u8*))D_800FAD10_ovl00[(s8)arg0[5]])(arg0);
    }
    s = D_1F80004C.bytes;
    if (s[0x89] != 0) {
        *(u8**)(arg0 + 0x54) = s + 0x80;
        t = D_1F80004C.bytes + 0x80;
        *(u8**)(arg0 + 0x58) = D_80074EE0;
        *(u8**)(arg0 + 0x50) = t;
        r = func_80031DD0(arg0);
        func_800317B8(arg0);
        if (r != 0) {
            goto test; // !FAKE: goto kept for the matching branch layout
        }
    }
    *(u8**)(arg0 + 0x54) = D_800FAA1C_ovl00;
    *(u8**)(arg0 + 0x50) = D_800FAA20_ovl00;
    *(u8**)(arg0 + 0x58) = D_80075200;
    r = func_80031DD0(arg0);
    func_800317B8(arg0);
    if (r < 0) {
        func_80054440(arg0, 0x12);
        goto fail; // !FAKE: goto kept for the matching branch layout
    }
test:
    if (is_off_screen(arg0, 0x200, 0x200) != 0) {
        *(s16*)(arg0 + 0x7C) = 4;
        D_1F80004C.bytes[0x87] = 0;
        D_1F80004C.bytes[0x86] = 1;
        arg0[4] = 4;
        return;
    }
    func_8002D9EC(arg0, 0x70, 0x30);
    m = arg0[0x70];
    if ((m & 0xC) == 0xC || (m & 3) == 3) {
    fail:
        func_8004D4F4(4, D_800FAC8C_ovl00, arg0);
        arg0[3] = 0;
        *(s16*)(arg0 + 0x7C) = 0x19;
        *(s16*)(arg0 + 0x7E) = 5;
        D_1F80004C.bytes[0x87] = 0;
        arg0[4] = 6;
        return;
    }
    func_8002FB58(arg0);
}

extern void func_800F2F40_ovl00(u8* a0);
extern u8 D_8009A197;
extern void (*D_800FAD34_ovl00[])(u8*);

void func_800F1E5C_ovl00(u8* arg0) {
    s32 r;
    u8* p;

    if (D_8009A197 == 0) {
        *(s32*)(arg0 + 0x18) = *(s32*)(arg0 + 0x8);
        *(s32*)(arg0 + 0x1C) = *(s32*)(arg0 + 0xC);
        D_800FAD34_ovl00[*(s8*)(arg0 + 5)](arg0);
        animate_object(arg0);
    }
    *(u16*)(arg0 + 0xA) = *(u16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xA);
    *(u16*)(arg0 + 0xE) = *(u16*)(*(u8**)(D_1F80004C.bytes + 0x80) + 0xE);
    func_800F2F40_ovl00(arg0);
    r = func_80031DD0(arg0);
    func_800317B8(arg0);
    if (r < 0) {
        if (*(s8*)(arg0 + 2) == 0x10) {
            if (arg0[0x15] == 0) {
                *(u16*)(arg0 + 0xA) += 0x1B;
            } else {
                *(u16*)(arg0 + 0xA) -= 0x1B;
            }
            *(u16*)(arg0 + 0xE) -= 8;
        } else {
            if (arg0[0x15] == 0) {
                *(u16*)(arg0 + 0xA) += 0x1F;
            } else {
                *(u16*)(arg0 + 0xA) -= 0x1F;
            }
            *(u16*)(arg0 + 0xE) -= 0x10;
        }
        func_8004FD24(arg0);
        arg0[3] = 0;
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x88] = 1;
        (*(u8**)(D_1F80004C.bytes + 0x80))[0x8A] = 0;
        arg0[4] = 5;
        return;
    }
    func_8002D9EC(arg0, 0x30, 0x30);
    p = D_1F80004C.bytes;
    if (p[0x85] != 0) {
        *(u16*)(arg0 + 0x42) |= *(u16*)(*(u8**)(p + 0x80) + 0x42) & 0x8000;
    }
}

extern u8 D_800FAC90_ovl00[][5][5];

void func_800F2038_ovl00(u8* arg0) {
    u8 v;

    D_1F80004C.bytes[0x85]++;
    v = D_800FAC90_ovl00[((s8*)arg0)[2]][D_1F80004C.bytes[0x84]]
                        [D_1F80004C.bytes[0x85]];
    if (v == 0x80) {
        D_1F80004C.bytes[0x84] = random_byte() & 3;
        D_1F80004C.bytes[0x85] = 0;
        arg0[5] = D_800FAC90_ovl00[((s8*)arg0)[2]][D_1F80004C.bytes[0x84]]
                                  [D_1F80004C.bytes[0x85]];
    } else {
        arg0[5] = v;
    }
    arg0[6] = 0;
}
