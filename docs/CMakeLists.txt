find_package(Doxygen)
if(Doxygen_FOUND)
    set(DOXYGEN_EXTRACT_ALL YES)
    set(DOXYGEN_BUILTIN_STL_SUPPORT YES)

    doxygen_add_docs(docs
        "${PROJECT_SOURCE_DIR}/src"
        "${PROJECT_SOURCE_DIR}/include"
        ALL
        COM MENT "Generate HTML documentation")
endif()
