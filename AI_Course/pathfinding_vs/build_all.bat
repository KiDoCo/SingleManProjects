@echo off
echo Setting compiler environment...
call "C:\Program Files (x86)\Microsoft Visual Studio 14.0\VC\bin\vcvars32.bat"
echo Generating build files...
call cmake -Bbuild/win32 -H.
echo Compiling debug...
call msbuild build/win32/pathfinding.sln /t:build /property:Configuration=Debug /property:Platform=win32
echo Compiling release...
call msbuild build/win32/pathfinding.sln /t:build /property:Configuration=Release /property:Platform=win32
echo Copying files...
call copy /Y input.bmp build\win32\input.bmp
call copy /Y glut\glut32.dll build\win32\glut32.dll
call copy /Y glut\glut32.dll glut32.dll
call copy /Y build\win32\Debug\pathfinding.exe pathfindingd.exe
call copy /Y build\win32\Release\pathfinding.exe pathfinding.exe
echo Build done!!!

pause