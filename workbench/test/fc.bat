:loop
data.exe > input.in
Code.exe < input.in > Code.out
std.exe < input.in > std.out
fc Code.out std.out
if not errorlevel 1 goto loop
pause
