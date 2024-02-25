#
# To reduce typing.
#
set(CDIR "${CMAKE_CURRENT_LIST_DIR}")

#
# This must come before macros, but I don't understand why the policies
# apply to the macros rather than the invocation of the macros.

include(${CDIR}/macros.cmake)