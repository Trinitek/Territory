@mkdir out 2>NUL
@cd src
gcc ^
main.c render.c event.c map.c ^
-o ../out/territory.exe ^
-std=c11 ^
-I . ^
-L ../lib ^
-l csfml-audio -l csfml-graphics -l csfml-network -l csfml-system -l csfml-window
@cd ..
@mkdir out\res 2>NUL
@copy /y res\* out\res\* >NUL
