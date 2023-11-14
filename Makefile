SRCS = srcs
SRC = $(SRCS)/philosophers.c \
		$(SRCS)/check_input.c \
		$(SRCS)/actions.c \
		$(SRCS)/time_scheduling.c \
		$(SRCS)/create_philo.c \
		$(SRCS)/threads.c \
		$(SRCS)/mutexes.c
OBJ_DIR = object_files
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:.c=.o)))
HEADER = -Iincludes/
NAME = philo
FLAGS = -Wall -Wextra -Werror -pthread #-g3 -fsanitize=thread

RED = \x1b[31;01m
GREEN = \x1b[32;01m
BLUE = \033[34;1m
BOLD = \033[1m
RESET = \x1b[0m

all: $(NAME)
$(NAME): $(OBJ)
	@gcc $(FLAGS) $(HEADER) -o $(NAME) $(OBJ)
	@printf "$(GREEN) Executable named philo created$(RESET)\n"

$(OBJ_DIR)/%.o: $(SRCS)/%.c
	@mkdir -p $(OBJ_DIR)
	@gcc $(FLAGS) $(HEADER) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(BLUE) deleting object files$(RESET)\n"

fclean: clean
	@rm -rf $(NAME)
	@printf "$(RED) deleting executable name$(RESET)\n"

re: fclean all
