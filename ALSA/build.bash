
gcc -lasound listing1.c -o listing1
./listing1

echo "Press any key To continue"
read -n 1
gcc -lasound listing2.c -o listing2
./listing2

echo "Press any key to continue"
read -n 1
gcc -lasound listing3.c -o listing3
./listing3 < /dev/urandom

echo "Press any key to continue"
read -n 1
gcc -lasound listing4.c -o listing4
./listing4 > sound.raw
./listing3 < sound.raw
