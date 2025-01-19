# Nom du programme
NAME = program

# Sources et objets
SRCS = test.cpp
OBJS = $(SRCS:.cpp=.o)
DEPS = $(OBJS:.o=.d)

# Compilateur et flags
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -std=c++11 -MMD

# Règle principale
$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

# Nettoyage
clean:
	rm -f $(OBJS) $(DEPS)

fclean: clean
	rm -f $(NAME)

re: fclean all $(NAME)

# Générer les dépendances
-include $(DEPS)

# .PHONY pour éviter des conflits avec des fichiers existants
.PHONY: all clean fclean re