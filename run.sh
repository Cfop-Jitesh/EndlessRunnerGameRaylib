gcc -g -o game src/main.c src/animations.c src/gameMechanics.c -lraylib -lm -ldl -lpthread -lGL -lrt -lX11
./game
rm -rf game
