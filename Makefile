# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jvarila <jvarila@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/07 09:32:50 by jvarila           #+#    #+#              #
#    Updated: 2025/03/07 09:47:19 by jvarila          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= minitalk
SERVER		:= server
CLIENT		:= client

CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
DEBUGFLAGS	:= -g
#------------------------------------------------------------------------------#
SRCDIR		:= ./
INCDIR		:= ./
OBJDIR		:= ./obj
LIBFTDIR	:= ./libft
#------------------------------------------------------------------------------#
LIBFT		:= $(LIBFTDIR)/libft.a
LIBFTH		:= $(LIBFTDIR)/libft.h
INC		:= -I $(LIBFTDIR) -I $(INCDIR)
MINITALKH	:= $(INCDIR)/minitalk.h
#------------------------------------------------------------------------------#
all: $(NAME)

$(NAME): $(OBJDIR) $(SERVER) $(CLIENT)

$(SERVER): $(OBJDIR)/minitalk_server.o $(LIBFT) $(MINITALKH)
	$(CC) $(CFLAGS) $(OBJDIR)/minitalk_server.o $(LIBFT) $(INC) -o $@

$(CLIENT): $(OBJDIR)/minitalk_client.o $(LIBFT) $(MINITALKH)
	$(CC) $(CFLAGS) $(OBJDIR)/minitalk_client.o $(LIBFT) $(INC) -o $@

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(MINITALKH)
	$(CC) $(CFLAGS) -c $< $(INC) -o $@

$(OBJDIR):
	mkdir -p $(OBJDIR)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(SERVER) $(CLIENT)

re: fclean all
#------------------------------------------------------------------------------#
debug: CFLAGS += $(DEBUGFLAGS)
debug: re
#------------------------------------------------------------------------------#
.PHONY: all clean fclean re debug libftdebug minitalk $(NAME)
#------------------------------------------------------------------------------#
