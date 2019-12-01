.PHONY : compile clean dist doc

CFLAGS = -g -Wall
OPATH = obj
BPATH = bin
SPATH = src
LPATH = lib
MODE=CAIROGUI
CPPFLAGS += -Iinclude -I/usr/include/cairo
LDFLAGS += -lcairo -lm -lX11

vpath %.h include
vpath %.c src
vpath %.o obj

compile : main.o libjeu.a
ifeq (MODE$(MODE),MODECAIROGUI)
		gcc -DMODE$(MODE) $(CFLAGS) -o main $(OPATH)/*.o -o $(BPATH)/main -lm $(CPPFLAGS) $(LDFLAGS) -ljeu -L $(LPATH)/
else
		gcc -DMODE$(MODE) $(CFLAGS) -o main $(OPATH)/*.o -o $(BPATH)/main -ljeu -L $(LPATH)/
endif 
 
libjeu.a : grille.o jeu.o io.o
	@mkdir lib
	@mkdir bin
	ar -crv $(LPATH)/$@ $(OPATH)/*
	ranlib $(LPATH)/$@
	
%.o : %.c
ifeq (MODE$(MODE),MODECAIROGUI)
		gcc -DMODE$(MODE) $(CFLAGS) -c $< -I include -o $(OPATH)/$@ $(CPPFLAGS) $(LDFLAGS)
else
		gcc -DMODE$(MODE) $(CFLAGS) -c $< -I include -o $(OPATH)/$@
endif

doc :
	doxygen

clean :
	rm -rf $(OPATH)/* $(BPATH) html $(LPATH)

dist :
	tar -zcvf DiabyIbrahim-GoL-5.1.1.tar.xz src include grilles obj bin Makefile Doxyfile README
