#ifndef __LIBVCT_API_H__
#define __LIBVCT_API_H__

#include <time.h>

#ifdef _WIN32
#    ifdef VCT_DYN_LINK
#        ifdef VCT_SOURCE
#            define VCT_API __declspec(dllexport)
#        else
#            define VCT_API __declspec(dllimport)
#        endif
#    else
#        define VCT_API
#    endif
#else
#    define VCT_API
#endif

#ifdef __cplusplus
extern "C" {
#endif

#ifdef _WIN32
typedef int              vct_BOOL;
typedef unsigned char    vct_U8;
typedef unsigned short   vct_U16;
typedef unsigned int     vct_U32;
typedef unsigned __int64 vct_U64;
typedef char             vct_I8;
typedef short            vct_I16;
typedef int              vct_I32;
typedef __int64          vct_I64;
typedef char             vct_CHAR;
typedef float            vct_F32;
typedef double           vct_F64;
typedef void            *vct_POINTER;
typedef time_t           vct_DATETIME;
typedef int              vct_DATE;
typedef int              vct_TIME;
#else
#    include <stdint.h>
typedef int                vct_BOOL;
typedef unsigned char      vct_U8;
typedef unsigned short     vct_U16;
typedef unsigned int       vct_U32;
typedef unsigned long long vct_U64;
typedef signed char        vct_I8;
typedef short              vct_I16;
typedef int                vct_I32;
typedef long long          vct_I64;
typedef char               vct_CHAR;
typedef float              vct_F32;
typedef double             vct_F64;
typedef void              *vct_POINTER;
typedef time_t             vct_DATETIME;
typedef int                vct_DATE;
typedef int                vct_TIME;
#endif

#if defined(WIN32)
#    define STRCASECMP(a, b)     (_stricmp(a, b))
#    define STRNCASECMP(a, b, n) (_strnicmp(a, b, n))
#    define STRCMP(a, b)         (_strcmp(a, b))
#    define STRNCMP(a, b, b)     (_strncmp(a, b, n))
#else
/** Alias for strcasecmp() */
#    define STRCASECMP(a, b)     (strcasecmp(a, b))
/** Alias for strncasecmp() */
#    define STRNCASECMP(a, b, n) (strncasecmp(a, b, n))
#endif
/** Alias for strncasecmp() == 0 */
#define EQUALN(a, b, n) (STRNCASECMP(a, b, n) == 0)
/** Alias for strcasecmp() == 0 */
#define EQUAL(a, b) (STRCASECMP(a, b) == 0)

/*-----------------------------------------------------------------------------
 * Does a string "a" start with string "b".  Search is case-sensitive or, with
 * CI, it is a case-insensitive comparison.
 *--------------------------------------------------------------------------- */
#ifndef STARTS_WITH_CI
/** Returns whether a starts with b */
#    define STARTS_WITH(a, b) (strncmp(a, b, strlen(b)) == 0)
/** Returns whether a starts with b (case insensitive comparison) */
#    define STARTS_WITH_CI(a, b) EQUALN(a, b, strlen(b))
#endif

/* -------------------------------------------------------------------------- */
/*                    VCT important macros and enumerations                   */
/* -------------------------------------------------------------------------- */

/* ------------------------------- VCT Version ------------------------------ */
#define VCT_VERSION_1 1
#define VCT_VERSION_2 2
#define VCT_VERSION_3 3

/* -------------------------- VCT table field type -------------------------- */
typedef enum vct_TableFieldType {
    VCT_FT_CHAR,     /* Fix length, up to 256 */
    VCT_FT_INT1,     /* Store 1 byte */
    VCT_FT_INT2,     /* Store 2 bytes */
    VCT_FT_INT4,     /* Store 4 bytes */
    VCT_FT_INT8,     /* Store 8 bytes */
    VCT_FT_FLOAT,    /* Single float type */
    VCT_FT_DOUBLE,   /* Double float type */
    VCT_FT_DATE,     /* Date type, store 4 bytes, format YYYYMMDD */
    VCT_FT_TIME,     /* Time type, store 4 bytes, format hh:mm:ss.sss */
    VCT_FT_DATETIME, /* Datetime type, store 8 bytes, format YYYYMMDDhh:mm:ss.s
                      */
    VCT_FT_VARCHAR,  /* Variable length string, up to 65535 bytes stored */
    VCT_FT_VARBIN,   /* Binary data, storing file relative path or address in
                        VARCHAR*/
} vct_TableFieldType;

/* ---------------------------- VCT Geometry Type --------------------------- */
typedef enum vct_GeometryType {
    VCT_GT_Point,       /* Point type */
    VCT_GT_Line,        /* Line type */
    VCT_GT_Polygon,     /* Polygon type */
    VCT_GT_Solid,       /* Solid type */
    VCT_GT_Aggregation, /* Aggregation type */
} vct_GeometryType;

/* ----------------------- VCT Representation keyword ----------------------- */
#define VCT_STRING(x)             #x
#define VCT_REP_LAYERNAME         VCT_STRING(LAYERNAME)
#define VCT_REP_COLOR             VCT_STRING(COLOR)
#define VCT_REP_FONTCOLOR         VCT_STRING(FONTCOLOR)
#define VCT_REP_BACKCOLOR         VCT_STRING(BACKCOLOR)
#define VCT_REP_SYMBOLID          VCT_STRING(SYMBOLID)
#define VCT_REP_SYMBOLLIBPROTOCOL VCT_STRING(SYMBOLLIBPROTOCOL)
#define VCT_REP_SYMBOLLIBLOCATION VCT_STRING(SYMBOLLIBLOCATION)
#define VCT_REP_SYMBOLDESCRIPTION VCT_STRING(SYMBOLDESCRIPTION)
#define VCT_REP_RETRIEVALSTATUS   VCT_STRING(RETRIEVALSTATUS)
#define VCT_REP_POINTSIZE         VCT_STRING(POINTSIZE)
#define VCT_REP_LINEWIDTH         VCT_STRING(LINEWIDTH)
#define VCT_REP_LINESTYLEID       VCT_STRING(LINESTYLEID)
#define VCT_REP_PATTERNID         VCT_STRING(PATTERNID)
#define VCT_REP_FONT              VCT_STRING(FONT)
#define VCT_REP_ANNOWIDTH         VCT_STRING(ANNOWIDTH)
#define VCT_REP_ANNOSPACE         VCT_STRING(ANNOSPACE)
#define VCT_REP_ANNOWEIGHT        VCT_STRING(ANNOWEIGHT)
#define VCT_REP_ANNOSTYLE         VCT_STRING(ANNOSTYLE)
#define VCT_REP_ANNOUNDERLINE     VCT_STRING(ANNOUNDERLINE)
#define VCT_REP_ANNOSTRIKE        VCT_STRING(ANNOSTRIKE)
#define VCT_REP_ANNOSHADOW        VCT_STRING(ANNOSHADOW)
#define VCT_REP_ANNOHOLE          VCT_STRING(ANNOHOLE)
#define VCT_REP_ANNOLIGNMENT      VCT_STRING(ANNOLIGNMENT)
#define VCT_REP_ANNOHORIZONTAL    VCT_STRING(ANNOHORIZONTAL)
#define VCT_REP_ANNOTRANSPARENT   VCT_STRING(ANNOTRANSPARENT)

/* -------------------------------- VCT Color ------------------------------- */
/* RGB values */
typedef vct_U32 vct_RGB;
/* mask RGB values */
#define RGB_MASK 0X00FFFFFF
/* default alpha value*/
#define RGB_ALPHA 0xFFU
/* set RGB value*/
#define VCT_RGB(r, g, b)                                                       \
    (RGB_ALPHA << 24) | ((r & 0xFFU) << 16) | ((g & 0XFFU) << 8) | (b & 0XFFU)
/* set RGBA value*/
#define VCT_RGBA(r, g, b, a)                                                   \
    ((a & 0xFFU) << 24) | ((r & 0xFFU) << 16) | ((g & 0XFFU) << 8) | (b & 0XFFU)
/* get RGB red component */
#define VCT_RED_COMPONENT(rgb) ((rgb >> 16) & 0xFF)
/* get RGB green component */
#define VCT_GREEN_COMPONENT(rgb) ((rgb >> 8) & 0xFF)
/* get RGB blue component */
#define VCT_BLUE_COMPONENT(rgb) (rgb & 0xFF)
/* get RGB alpha component */
#define VCT_ALPHA_COMPONENT(rgb) (rgb >> 24)

#define VCT_Black       VCT_RGB(0x00, 0x00, 0x00)
#define VCT_White       VCT_RGB(0xFF, 0xFF, 0xFF)
#define VCT_DarkGray    VCT_RGB(0x80, 0x80, 0x80)
#define VCT_Gray        VCT_RGB(0xA0, 0xA0, 0xA4)
#define VCT_LightGray   VCT_RGB(0xC0, 0xC0, 0xC0)
#define VCT_Red         VCT_RGB(0xFF, 0x00, 0x00)
#define VCT_Green       VCT_RGB(0x00, 0xFF, 0x00)
#define VCT_Blue        VCT_RGB(0x00, 0x00, 0xFF)
#define VCT_Cyan        VCT_RGB(0x00, 0xFF, 0xFF)
#define VCT_Magenta     VCT_RGB(0xFF, 0x00, 0xFF)
#define VCT_Yellow      VCT_RGB(0xFF, 0xFF, 0x00)
#define VCT_DarkRed     VCT_RGB(0x80, 0x00, 0x00)
#define VCT_DarkGreen   VCT_RGB(0x00, 0x80, 0x00)
#define VCT_DarkBlue    VCT_RGB(0x00, 0x00, 0x80)
#define VCT_DarkCyan    VCT_RGB(0x00, 0x80, 0x80)
#define VCT_DarkMagenta VCT_RGB(0x80, 0x00, 0x80)
#define VCT_DarkYellow  VCT_RGB(0x80, 0x80, 0x00)

/* -------------------------------------------------------------------------- */
/*                  VCT important macros and enumerations end                 */
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                           VCT core data structure                          */
/* -------------------------------------------------------------------------- */

/* ------------------------------- Head Begin ------------------------------- */
typedef struct vct_Head {
    vct_CHAR data_mark[12]; /* CNSDTF-VCT */
    vct_U8   version;
    /* Coordinate system type. 'C' represents the Cartesian coordinate system,
     * 'D' represents the geodetic coordinate system, and 'P' represents the
     * projected coordinate system. Default is 'C'. */
    vct_CHAR coordinate_system_type;
    /* Coordinate dimension, 2 means only two-dimensional coordinates, 3 means
     * three-dimensional coordinates. When dim is 2, there is no <Z> item in the
     * coordinates of the point. When dim is 3, there is a <Z> item in the
     * coordinates of the point. The default is 2. */
    vct_CHAR dim;
    /* X coordinate axis direction, default is E.
     * Y coordinate axis direction, default is N.
     * The X coordinate axis is perpendicular to the Y coordinate axis. E means
     * east, N means north, W means west, and S means south. When the coordinate
     * system type is a geodetic coordinate system, there is no need to specify
     * the coordinate axis direction.*/
    vct_CHAR x_axis_direction;
    vct_CHAR y_axis_direction;
    /* Plane coordinate units, M represents meters, D represents latitude and
     * longitude. When the coordinate type is Cartesian coordinate system or
     * projected coordinate system, the default is M. When the coordinate type
     * is the geodetic coordinate system, the default is D.*/
    vct_CHAR xy_unit;
    /* Z coordinate axis direction, default is M.*/
    vct_CHAR     z_uint;
    vct_CHAR     spheroid[512];
    vct_CHAR     prime_meridian[512];
    vct_CHAR     projection[256];
    vct_CHAR     parameters[512];
    vct_CHAR     vertical_datum[256];
    vct_CHAR     temporal_reference_system[256];
    vct_F64      extent_min[2];
    vct_F64      extent_max[2];
    vct_I32      map_scale;
    vct_F64      offset;
    vct_DATETIME date;
    vct_CHAR    *separator;
} vct_Head;

/* --------------------------- Feature Code Begin --------------------------- */
typedef struct vct_FeatureCode {
    vct_CHAR         feature_code[12];
    vct_CHAR         feature_name[36];
    vct_GeometryType type;
    vct_CHAR         attr_table_name[36];
    vct_U32          user_data_size;
    vct_CHAR       **user_data;
} vct_FeatureCode;

/* -------------------------- Table Structure Begin ------------------------- */
typedef struct vct_TableField {
    vct_CHAR           name[36];
    vct_TableFieldType type;
    vct_U8             length;
    vct_U8             precision;
} vct_TableField;

typedef struct vct_TableStructure {
    vct_CHAR        table_name[36];
    vct_U32         field_size;
    vct_TableField *fields;
} vct_TableStructure;

/* ------------------------------- Point Begin ------------------------------ */
typedef struct vct_Point {
    vct_U64  bsm;
    vct_CHAR feature_code[12];
    vct_CHAR graphical_presentation_code[128];
    vct_U8   eigenvalues;
    vct_U32  point_size;
    vct_F64 *point_coordinates;
} vct_Point;

/* ------------------------------- Line Begin ------------------------------- */

typedef struct vct_SubLine {
    vct_U8 line_type;
} vct_SubLine;

typedef struct vct_Line {
    vct_U64      bsm;
    vct_CHAR     feature_code[12];
    vct_CHAR     graphical_presentation_code[128];
    vct_U8       eigenvalues;
    vct_U32      line_size;
    vct_SubLine *lines;
} vct_Line;

typedef struct vct_PathLine {
    vct_U8   line_type;
    vct_U32  point_size;
    vct_F64 *point_coordinates;
} vct_PathLine;

typedef struct vct_Arc3PLine {
    vct_U8  line_type;
    vct_F64 point_coordinates[9];
} vct_Arc3PLine;

typedef struct vct_ArcCircleLine {
    vct_U8  line_type;
    vct_F64 center[3];
    vct_F64 radius;
    vct_F64 start_angle;
    vct_F64 end_angle;
} vct_ArcCircleLine;

typedef struct vct_EllipseArcLine {
    vct_U8  line_type;
    vct_F64 center[3];
    vct_F64 major_axis[3];
    vct_F64 ratio;
    vct_F64 start_angle;
    vct_F64 end_angle;
} vct_EllipseArcLine;

typedef struct vct_CubicSpline {
    vct_U8   line_type;
    vct_U32  point_size;
    vct_F64 *point_coordinates;
} vct_CubicSpline;

typedef struct vct_BSplineCurve {
    vct_U8   line_type;
    vct_U32  point_size;
    vct_F64 *point_coordinates;
    vct_U32  factor;
    vct_U32  node_size;
    struct node {
        vct_F64 parameter;
        vct_I32 factor;
        vct_F64 weight;
    };
    struct node *nodes;
} vct_BSplineCurve;

typedef struct vct_BezierCurve {
    vct_U8   line_type;
    vct_U32  point_size;
    vct_F64 *point_coordinates;
    vct_U32  factor;
    struct node {
        vct_F64 parameter;
        vct_I32 factor;
        vct_F64 weight;
    };
    struct node nodes[2];
} vct_BezierCurve;

/* --------------------------------------------------------------------------
 */
/*                          VCT core data structure end */
/* --------------------------------------------------------------------------
 */

/* --------------------------------------------------------------------------
 */
/*                             VCT helper function */
/* --------------------------------------------------------------------------
 */

/* --------------------------------------------------------------------------
 */
vct_I32 vct_merge_date_and_time(const vct_DATE date,
                                const vct_TIME time,
                                vct_DATETIME  *dt);

/* -------------------------------------------------------------------------- */
vct_I32
vct_split_date_and_time(const vct_DATETIME dt, vct_DATE *date, vct_TIME *time);

#ifdef __cplusplus
}
#endif

#endif //__LIBVCT_API_H__
