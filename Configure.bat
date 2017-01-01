

mkdir "Engine\External\Lumino\build_LuminoStudio"
cd "Engine\External\Lumino\build_LuminoStudio"
cmake .. -G"Visual Studio 14" -DLN_MSVC_LINK_MULTI_THREAD_STATIC_RUNTIME=OFF -DLN_USE_UNICODE_CHAR_SET=ON

pause

