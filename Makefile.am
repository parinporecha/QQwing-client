LD_LIBRARY_PATH="/opt/gnome/lib"
INCLUDE_PATH="/opt/gnome/include"

noinst_PROGRAMS = client

client_SOURCES = \
	client.vala	\
	QQwing_wrapper.cpp	\
	QQwing_client.vapi

client_VALAFLAGS = --pkg glib-2.0

client_CFLAGS = $(shell pkg-config --cflags glib-2.0)

client_CPPFLAGS = \
	-I$(INCLUDE_PATH)	\
	$(shell pkg-config --cflags glib-2.0)

client_LDADD = -lqqwing -L${LD_LIBRARY_PATH} -lglib-2.0

client_LDFLAGS = -Wl,-rpath,${LD_LIBRARY_PATH}
