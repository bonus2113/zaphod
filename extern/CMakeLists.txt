OPTION(EMBREE_STATIC_LIB "Build Embree as a static library." ON)
OPTION(EMBREE_ISPC_SUPPORT "Build Embree with support for ISPC applications." OFF)
OPTION(EMBREE_TUTORIALS    "Enable to build Embree tutorials" OFF)


set(TASKING_INTERNAL ON FORCE)
set(TASKING_TBB OFF FORCE)
set(EMBREE_TASKING_SYSTEM "INTERNAL" CACHE STRING "Selects tasking system" FORCE)
  
add_subdirectory(embree)
set(INC_DIRS ${INC_DIRS} "${CMAKE_CURRENT_LIST_DIR}/embree/include")
set(LIBS ${LIBS} "embree" "embree_sse42")

if(NOT HEADLESS)
  set(BUILD_SHARED_LIBS OFF CACHE STRING "" FORCE)
  option(SFML_USE_STATIC_STD_LIBS "" OFF)
  add_subdirectory(SFML)
  set(INC_DIRS ${INC_DIRS} "${CMAKE_CURRENT_LIST_DIR}/SFML/include")
  set(LIBS ${LIBS} "sfml-graphics" "sfml-window" "sfml-system" "sfml-main")
endif()

# add_subdirectory(USD)

OPTION (BUILD_SHARED_LIBS "Build Shared Libraries" OFF)
OPTION (NAMESPACE_VERSIONING "Namespace Versioning" OFF)

add_subdirectory(openexr/IlmBase)

set(ILMBASE_ROOT "${CMAKE_CURRENT_LIST_DIR}/openexr/IlmBase")
set(ILMBASE_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/include/openexr")
set(ALEMBIC_ILMBASE_HALF_LIB "${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}/Half.lib")
set(ALEMBIC_ILMBASE_IEXMATH_LIB "${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}/IexMath.lib")
set(ALEMBIC_ILMBASE_IEX_LIB "${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}/Iex.lib")
set(ALEMBIC_ILMBASE_ILMTHREAD_LIB "${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}/IlmThread.lib")
set(ALEMBIC_ILMBASE_IMATH_LIB "${LIBRARY_OUTPUT_PATH}/${CMAKE_CFG_INTDIR}/Imath.lib")

set(LIBS ${LIBS} "Half" "IexMath" "Iex" "IlmThread" "Imath")

option(ALEMBIC_SHARED_LIBS "" OFF)
option(USE_HDF5 "" OFF)
option(USE_MAYA "" OFF)
option(ALEMBIC_LIB_USES_BOOST "" OFF)
option(ALEMBIC_LIB_USES_TR1 "" OFF)
option(ALEMBIC_ILMBASE_LINK_STATIC "" ON)
option(USE_TESTS "" OFF)
option(USE_BINARIES "" OFF)

include_directories("${CMAKE_CURRENT_LIST_DIR}/alembic/lib")

add_subdirectory(alembic)

set(INC_DIRS ${INC_DIRS} "${CMAKE_CURRENT_LIST_DIR}/alembic/lib")
set(LIBS ${LIBS} "Alembic")

add_subdirectory(pugixml-1.7)


set(INC_DIRS ${INC_DIRS} "${CMAKE_CURRENT_LIST_DIR}/pugixml-1.7/src" PARENT_SCOPE)
set(LIBS ${LIBS} "PugiXML" PARENT_SCOPE)
