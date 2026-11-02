#include "types.h"
#include "addr.h"

extern void func_80017248(u8* obj);
extern u8* func_8002D0E4(void);
extern u8* func_8002D078();
extern void func_8003CEAC(s32 arg0, s32 arg1, s32 arg2, u8* arg3);
extern void func_80016490(s32, s32, void*);
extern void func_8003AA4C(u8* arg0);
extern u8 D_8007B3D8[];

void func_80043678(u8* obj) {
    u8* p;
    u8* q;
    u8* b;
    s32 i;
    s32 off;

    func_80017248(obj);
    if (*(s8*)(obj + 0x45) & 0x80) {
        obj[0x45] = 0;
        p = func_8002D0E4();
        if (p != 0) {
            p[0] = 0x21;
            p[1] = 3;
            p[2] = 0xD;
            p[0x14] = obj[0x14];
            b = D_1F80001C.bytes;
            off = *(s32*)(b + 0x18);
            *(u8**)(p + 0x30) = D_8007B3D8;
            *(s16*)(p + 0x40) = 0;
            *(s16*)(p + 0x42) = 0x7843;
            p[0x16] = 0;
            *(u8**)(p + 0x3C) = b + off;
            *(s32*)(p + 0x8) = *(s32*)(obj + 0x8);
            *(s32*)(p + 0xC) = *(s32*)(obj + 0xC);
            p[0x15] = obj[0x15];
            func_8003CEAC(0x54, 0x13, 1, p);
        }
    }
    if (obj[0x45] & 0x40) {
        obj[0x45] = 0;
        i = 0;
        do {
            q = func_8002D078();
            if (q != 0) {
                q[0] = 0x21;
                q[1] = 0x2A;
                q[2] = i;
                q[0x14] = obj[0x14];
            }
            i++;
        } while ((u32)i < 9);
        func_80016490(1, 0x11, obj);
    }
    if (*(s8*)(obj + 0x46) == 0) {
        obj[0x93] = 0;
        obj[0x8E] = 0;
        if (*(s8*)(obj + 0xD3) == 0 && *(s8*)(obj + 0x14B) != -1) {
            obj[0x7A] = 0;
        }
        func_8003AA4C(obj);
    }
}
