LD_LIBRARY_PATH="/opt/gnome/lib"
INCLUDE_PATH="/opt/gnome/include"

.PHONY: all
all:
	valac -C --pkg glib-2.0 QQwing_client.vala;	\
	gcc -o QQwing_client.o QQwing_client.c -c `pkg-config --cflags --libs glib-2.0`;	\
	g++ -I${INCLUDE_PATH} -o QQwing_client.cpp.o QQwing_client.cpp -c -lqqwing `pkg-config --cflags --libs glib-2.0`;	\
	g++ -o client QQwing_client.o QQwing_client.cpp.o -Wl,-rpath,${LD_LIBRARY_PATH} -L${LD_LIBRARY_PATH} -lqqwing `pkg-config --cflags --libs glib-2.0`
