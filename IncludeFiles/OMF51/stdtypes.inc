//
// Definitions referring to KEIL or Keil are not defined by Intel's OMF51 document.
// ARM Keil's 8051 C toolchain uses these values but does not document them.
//
#ifndef _OMF51_STDTYPES_INC_
#define _OMF51_STDTYPES_INC_

typedef enum <ubyte>
{
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
} OMF51_RECORDTYPE
    <
        format=hex
        //, name="Record type byte"
        //, comment=
        //    (isOMFrecordType(this)
        //       ? ( ""
//#define NO_KEIL
//#ifndef NO_KEIL
//              +
//                   (isKeilOMF51recordType(this)
//                        ? "Keil-specific"
//                        : "")
//#endif
//#undef NO_KEIL
//             : "Invalid value"
//            )  
    >;

int isOMF51recordType(OMF51_RECORDTYPE n)
{
    return EnumToString(n) != "";
}

int isKeilOMF51recordType(OMF51_RECORDTYPE n)
{
#ifndef NO_KEIL
    return (n & 1 == 1) && (EnumToString(n) != "");
#else
#warning "NO_KEIL is #defined. Compiling isKeilOMF51recordType() as equivalent to isOMF51recordType()."
    return EnumToString(n) != "";
#endif
}

OMF51_RECORDTYPE KeilOMF51baseRecordType(OMF51_RECORDTYPE n)
{
#ifdef NO_KEIL
#warning "NO_KEIL is #defined. Replacing calls to KeilOMF51baseRecordType() with calls to a \"pass-through-or-FALSE\" function."
    return  EnumToString(n) != "" ? n : 0;
#else
    return EnumToString(n) != "" ? n & 0xfe : 0;
#endif
}
//
// Strictly speaking, the following isn't defined by Intel's OMF51 document.
//typedef enum <int> {
//    ft_Empty    =   -1,
//    ft_ObjFile  =   rt_Module_HDR,
//    ft_LibFile =   rt_LIB_Header
//} OMF51_FILETYPE;

typedef enum <ubyte> {
    ASM51   =   0xFD,
    PLM_51, //  0xFE
    RL51    //  0xFF
} TRNID;


//The relocation type field of a segment can specify an absolute segment and four types of relocatable segments://0//-//ABS.//Specifies an absolute segment (non-relocatable).//1//-//UNIT.//The segment can be relocated on a unit boundary (a bit boundary for BIT type segments and a byte boundary for all other segments). Thus no restrictions are placed on its relocation.//2//-//BITADDRESSABLE.//The segment must be located within the bit-addressable portion of the internal data space. Allowed only for DATA type segments.//3//-//INPAGE.//The segment will be located within a 256 byte page.//4//-//INBLOCK.//The segment will be located within a 2048 byte block.//5//-//PAGE.//The base address of this segment will be on a 256 byte page boundary.
typedef enum <ubyte> {
    SegType_CODE = 0,
    SegType_XDATA,
    SegType_DATA,
    SegType_IDATA,
    SegType_BIT
} SEGTYPE;


#endif // _OMF51_STDTYPES_INC_