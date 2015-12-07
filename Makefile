##
## Makefile for my printf in /home/boulat_m/rendu/Projets/CPE_2014_my_printf
## 
## Made by Mickael BOULAT
## Login   <boulat_m@epitech.net>
## 
## Started on  Mon Nov 10 09:49:01 2014 Mickael BOULAT
## Last update Tue Nov 11 14:43:45 2014 Mickael BOULAT
##

NAME	=	minitalk
NAMELIB	=	libmy.a

SRCSLIBS=	./srv/lib/my/my_putchar.c		\
		./srv/lib/my/my_getnbr.c		\
		./srv/lib/my/my_putstr.c		\
		./srv/lib/my/my_put_nbr.c		\
		./srv/lib/my/my_put_nbrn.c		\
		./srv/lib/my/my_power_rec.c		\
		./srv/lib/my/my_strlen.c		\
		./srv/lib/my/my_str_isnum.c		\
		./srv/lib/my/my_putstrn.c

SRCSLIBC	=./clt/lib/my/my_putchar.c		\
		./clt/lib/my/my_getnbr.c		\
		./clt/lib/my/my_putstr.c		\
		./clt/lib/my/my_putstrn.c

SRCS	=	./srv/server.c
SRCC	=	./clt/client.c

OBJS	=	$(SRCS:.c=.o)
OBJC	=	$(SRCC:.c=.o)

OBJLIBS	=	$(SRCSLIBS:.c=.o)
OBJLIBC	=	$(SRCSLIBC:.c=.o)

INCLUDES=	-I ./srv/include/
INCLUDEC=	-I ./clt/include/

LIBS	=	-L ./srv/lib/ -lmy
LIBC	=	-L ./clt/lib/ -lmy

CFLAGSS	+=	-W -Wall -pedantic
CFLAGSS	+=	$(INCLUDES) $(LIBS)

CFLAGSC	+=	-W -Wall -pedantic
CFLAGSC	+=	$(INCLUDEC) $(LIBC)

RM	=	rm -f
CC	=	gcc


all	:	$(NAME)

libs	:	$(OBJLIBS)
		ar rc $(NAMELIB) $(OBJLIBS)
		ranlib $(NAMELIB)
		mv $(NAMELIB) ./srv/lib/

libc	:	$(OBJLIBC)
		ar rc $(NAMELIB) $(OBJLIBC)
		ranlib $(NAMELIB)
		mv $(NAMELIB) ./clt/lib/

$(NAME)	:	server client libs libc

server	:	$(OBJS) libs
		$(CC) -o srv/server $(OBJS) $(CFLAGSS)

client	:	$(OBJC) libc
		$(CC) -o clt/client $(OBJC) $(CFLAGSC)

clean	:	
		$(RM) $(OBJS)
		$(RM) $(OBJC)
		$(RM) $(OBJLIBS)
		$(RM) $(OBJLIBC)

fclean	:	clean
		$(RM) ./srv/server
		$(RM) ./clt/client
		$(RM) ./srv/lib/$(NAMELIB)
		$(RM) ./clt/lib/$(NAMELIB)

re	:	fclean all
