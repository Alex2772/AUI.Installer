cmake_minimum_required(VERSION 3.10)

project(installer)


find_package(AUI REQUIRED)

if(WIN32)
    if (NOT CPACK_PACKAGE_NAME)
        set(CPACK_PACKAGE_NAME CPACK_PACKAGE_NAME)
    endif()
    if (TARGET AUI.Views)
        AUI_Executable(installer)
        AUI_Compile_Assets(installer)
        target_link_libraries(installer PRIVATE AUI.Core)
        target_link_libraries(installer PRIVATE AUI.Data)
        target_link_libraries(installer PRIVATE AUI.Views)
        target_link_libraries(installer PRIVATE AUI.Crypt)
        target_compile_definitions(installer PRIVATE PROJECT_NAME=\"${PROJECT_NAME}\")
    endif()
else()
    message("Not building installer because it is WIN32 only.")
endif()