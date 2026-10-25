/* Synthetic fixture (not mmx6 text): mmx6/psyq_api.h. */
#ifndef MMX6_PSYQ_API_H
#define MMX6_PSYQ_API_H
typedef struct {
    short x, y, w, h;
} X4_RECT;
typedef unsigned char X4_u_char;
typedef void (*X4_CdlCB)(X4_u_char, X4_u_char*);
X4_CdlCB CdReadyCallback(X4_CdlCB func);
#endif
