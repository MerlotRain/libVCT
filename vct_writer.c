#include "libvct_api.h"
#include <sys/syslimits.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vct_Writer {
    vct_CHAR filepath[PATH_MAX];
    FILE    *fp;
    FILE    *fp_head;
    FILE    *fp_feature_code;
    FILE    *fp_table_structure;
    FILE    *fp_point;
    FILE    *fp_line;
    FILE    *fp_polygon;
    FILE    *fp_annotation;
    FILE    *fp_attribute;
    FILE    *fp_graphical_presentation;
};

vct_I32 vct_create_writer(vct_Writer **w, const char *filepath) {
    assert(filepath && strlen(filepath) < PATH_MAX);
    *w = (vct_Writer *)malloc(sizeof(vct_Writer));
    if (*w == NULL) {
        return -1;
    }
    memset(*w, 0, sizeof(vct_Writer));
    strcpy((*w)->filepath, filepath);
    (*w)->fp = fopen(filepath, "w+");
    if ((*w)->fp == NULL) {
        vct_destroy_writer(*w);
        free(*w);
        return -1;
    }
#define VCT_CREATE_TEMP_FILE(x)                                                \
    {                                                                          \
        (*w)->fp_##x = NULL;                                                   \
        vct_CHAR tmp[512];                                                     \
        strcpy(tmp, filepath);                                                 \
        strcat(tmp, #x);                                                       \
        (*w)->fp_##x = fopen(tmp, "w+");                                       \
        if ((*w)->fp_##x == NULL) {                                            \
            vct_destroy_writer(*w);                                            \
            free(*w);                                                          \
            return -1;                                                         \
        }                                                                      \
    }

    VCT_CREATE_TEMP_FILE(head)
    VCT_CREATE_TEMP_FILE(feature_code)
    VCT_CREATE_TEMP_FILE(table_structure)
    VCT_CREATE_TEMP_FILE(point)
    VCT_CREATE_TEMP_FILE(line)
    VCT_CREATE_TEMP_FILE(polygon)
    VCT_CREATE_TEMP_FILE(annotation)
    VCT_CREATE_TEMP_FILE(attribute)
    VCT_CREATE_TEMP_FILE(graphical_presentation)

#undef VCT_CREATE_TEMP_FILE
    return VCT_SUCCESS;
}

vct_I32 vct_destroy_writer(vct_Writer *w) {
    assert(w);
#define VCT_DESTROY_TEMP_FILE(x)                                               \
    if (w->fp_##x) {                                                           \
        fclose(w->fp_##x);                                                     \
        w->fp_##x = NULL;                                                      \
    }

    VCT_DESTROY_TEMP_FILE(head)
    VCT_DESTROY_TEMP_FILE(feature_code)
    VCT_DESTROY_TEMP_FILE(table_structure)
    VCT_DESTROY_TEMP_FILE(point)
    VCT_DESTROY_TEMP_FILE(line)
    VCT_DESTROY_TEMP_FILE(polygon)
    VCT_DESTROY_TEMP_FILE(annotation)
    VCT_DESTROY_TEMP_FILE(attribute)
    VCT_DESTROY_TEMP_FILE(graphical_presentation)

    free(w);
    w = NULL;

#undef VCT_DESTROY_TEMP_FILE

    return VCT_SUCCESS;
}

vct_I32 vct_write_head(const vct_Writer *w, const vct_Head *head) { return 0; }

vct_I32
vct_write_tables(const vct_Writer *w, vct_U32 size, vct_TableStructure *table) {
    return 0;
}

vct_I32 vct_begin_write_point(const vct_Writer *w) { return 0; }

vct_I32 vct_end_write_point(const vct_Writer *w) { return 0; }

vct_I32 vct_write_point(const vct_Writer *w, const vct_Point *point) {
    return 0;
}

vct_I32 vct_begin_write_line(const vct_Writer *w) { return 0; }

vct_I32 vct_end_write_line(const vct_Writer *w) { return 0; }

vct_I32 vct_write_line(const vct_Writer *w, const vct_Line *line) { return 0; }

vct_I32 vct_begin_write_polygon(const vct_Writer *w) { return 0; }

vct_I32 vct_end_write_polygon(const vct_Writer *w) { return 0; }

vct_I32 vct_write_polygon(const vct_Writer *w, const vct_Polygon *polygon) {
    return 0;
}

vct_I32 vct_begin_write_annotation(const vct_Writer *w) { return 0; }

vct_I32 vct_end_write_annotation(const vct_Writer *w) { return 0; }

vct_I32 vct_write_annotation(const vct_Writer     *w,
                             const vct_Annotation *annotation) {
    return 0;
}

vct_I32 vct_begin_write_attribute(const vct_Writer *w) { return 0; }

vct_I32 vct_end_write_attribute(const vct_Writer *w) { return 0; }