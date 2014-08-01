LD_LIBRARY_PATH="/opt/gnome/lib"
INCLUDE_PATH="/opt/gnome/include"

.PHONY: all
all:
	valac -C --pkg glib-2.0 client.vala QQwing_client.vapi; \
	gcc -o client.o client.c -c `pkg-config --cflags --libs glib-2.0`;	\
	g++ -I${INCLUDE_PATH} -o QQwing_wrapper.o QQwing_wrapper.cpp -c -lqqwing `pkg-config --cflags --libs glib-2.0`;	\
	g++ -o client client.o QQwing_wrapper.o -Wl,-rpath,${LD_LIBRARY_PATH} -L${LD_LIBRARY_PATH} -lqqwing `pkg-config --cflags --libs glib-2.0`
