NAME = ex00

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -MMD -MP
INCLUDES = -I include

OBJ_DIR = obj

SRCS = main.cpp

OBJS = $(SRCS:%.cpp=$(OBJ_DIR)/%.o)
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re