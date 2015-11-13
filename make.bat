@mkdir out 2>NUL
gcc main.c -o out/territory.exe -I . -L lib -l csfml-audio -l csfml-graphics -l csfml-network -l csfml-system -l csfml-window
@mkdir out\res 2>NUL
@copy /y res\* out\res\* >NUL
