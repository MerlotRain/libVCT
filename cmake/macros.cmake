######################################################################
macro(DISSECT_VERSION)
    # Find version components
    string(REGEX REPLACE "^([0-9]+).*" "\\1"
        LIBVCT_API_VERSION_MAJOR "${LIBVCT_API_VERSION_STRING}")
    string(REGEX REPLACE "^[0-9]+\\.([0-9]+).*" "\\1"
        LIBVCT_API_VERSION_MINOR "${LIBVCT_API_VERSION_STRING}")
    string(REGEX REPLACE "^[0-9]+\\.[0-9]+\\.([0-9]+).*" "\\1"
        LIBVCT_API_VERSION_PATCH "${LIBVCT_API_VERSION_STRING}")
    if(NOT LIBVCT_API_VERSION_MINOR)
        set(LIBVCT_API_VERSION_MINOR "0")
    endif()
    if(NOT LIBVCT_API_VERSION_PATCH)
        set(LIBVCT_API_VERSION_PATCH "0")
    endif()
endmacro(DISSECT_VERSION)
