#include "libvct_api.h"
#include <sys/syslimits.h>

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vct_Reader {
    vct_CHAR  filepath[PATH_MAX];
    FILE     *fp;
    vct_Head *head;
    vct_U32   table_size;
    vct_U32  *table_offset;
};