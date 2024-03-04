gcc -O2 -o play play.c -lmpg123 -lao
./play output.mp3

gcc -O2 -o playurl playurl.c -lmpg123 -lao -lcurl