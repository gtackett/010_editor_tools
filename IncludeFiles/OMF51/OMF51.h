#error "This file is obsolete!"
#ifndef _OMF51_H
#define _OMF51_H

typedef ushort RECORDLENGTH;
typedef ubyte uhbyte <format=hex>;
typedef ubyte udbyte <format=decimal>;

typedef uhbyte CHECKSUMBYTE;
#ifdef NO_KEIL
#warning ("(Info) Excluding Keil record type definitions")
#endif
 
typedef enum <ubyte> {
    rt_Module_HDR       =   0x02,
    rt_Module_END       =   0x04,
    rt_Content          =   0x06,
#ifndef NO_KEIL
    rt_Content_Keil     =   0x07,
#endif
    rt_Fixup            =   0x08,
    rt_Fixup_Keil       =   0x09,
    rt_Segment_DEF      =   0x0e,
#ifndef NO_KEIL
    rt_Segment_DEF_Keil =   0x0f,
#endif
    rt_Scope_DEF        =   0x10,
    rt_Debug_Item       =   0x12,
    rt_Public_DEF       =   0x16,
#ifndef NO_KEIL
    rt_Public_DEF_keil  =   0x17,
#endif
    rt_External_DEF     =   0x18,
#ifndef NO_KEIL
    rt_External_DEF_keil =   0x19,
#endif
    rt_LIB_ModLocs      =   0x26,
    rt_LIB_ModName      =   0x28,
    rt_LIB_DICTNRY      =   0x2A,
    rt_LIB_Header       =   0x2c
} RECORDTYPE;

typedef enum <ubyte> {
    ASM51   =   0xFD,
    PLM_51, //  0xFE
    RL51    //  0xFF
} TRNID <format=hex>;

typedef enum <int> {
    ft_Empty    =   -1,
    ft_ObjFile  =   rt_Module_HDR,
    ft_LibFile =   rt_LIB_Header
} FILETYPE <format=hex>;

const ubyte maxExpectedNameLength = 40;

#endif