# executable
EXEC_NAME = fillit

MAIN = main

# library name
LIBFT = libft
LIBFI = libfi

# compiler
CC = clang

# compilation flags
CF = -Wall -Wextra -Werror

# directories
SRCS = ./srcs
INCLUDES = ./includes
OBJ = ./obj
STATIC = ./static

# header
LIBFT_HEADER = $(patsubst %, $(INCLUDES)/%.h, $(LIBFT))
LIBFI_HEADER = $(patsubst %, $(INCLUDES)/%.h, $(LIBFI))

# function names
LIBFT_FUNCS = ft_memset ft_memdel ft_strnew ft_strdel ft_strclr ft_striter \
			  ft_striteri ft_memalloc ft_bzero ft_memcpy ft_memccpy ft_memmove \
			  ft_memchr ft_strlen  ft_strdup ft_strcpy ft_strmap ft_strmapi \
			  ft_strequ ft_strnequ ft_strsub ft_strjoin ft_strtrim ft_strncpy \
			  ft_strcat ft_strncat ft_strlcat ft_strchr ft_strrchr ft_strstr \
			  ft_strnstr ft_strcmp ft_strncmp ft_atoi ft_isalpha ft_isdigit \
			  ft_isalnum ft_isascii ft_isprint ft_islower ft_isupper \
			  ft_toupper ft_tolower ft_itoa ft_strsplit ft_putchar ft_putstr \
			  ft_putendl ft_putnbr ft_abs ft_putchar_fd ft_putstr_fd \
			  ft_putendl_fd ft_putnbr_fd ft_lstnew ft_lstdelone ft_lstdel \
			  ft_memcmp ft_lstadd ft_lstiter ft_lstmap ft_getc
LIBFI_FUNCS = gettetr deltetr gettetrlst puttetr puttetrlst

# object files
LIBFT_O_FILES =  $(patsubst %, $(OBJ)/$(LIBFT)/%.o, $(LIBFT_FUNCS))
LIBFI_O_FILES = $(patsubst %, $(OBJ)/$(LIBFI)/%.o, $(LIBFI_FUNCS))
MAIN_O_FILE = $(patsubst %, $(OBJ)/$(MAIN)/%.o, $(MAIN))

.PHONY: re all clean fclean clean_libft fclean_libft clean_libfi fclean_libfi

all: $(EXEC_NAME)

$(EXEC_NAME): $(STATIC)/$(LIBFT).a $(LIBFI_O_FILES) $(MAIN_O_FILE)
	clang -o $(EXEC_NAME) $(MAIN_O_FILE) $(LIBFI_O_FILES) -I $(INCLUDES) -L $(STATIC) -lft

$(OBJ)/$(MAIN)/%.o: $(SRCS)/$(MAIN)/%.c $(LIBFI_HEADER) $(LIBFT_HEADER) 
	@mkdir -p $(OBJ)
	@mkdir -p $(OBJ)/$(MAIN)
	$(CC) $(CF) -c $< -o $@ -I $(INCLUDES)

$(STATIC)/$(LIBFT).a: $(LIBFT_O_FILES)
	@mkdir -p $(STATIC)
	ar rc $(STATIC)/$(LIBFT).a $(LIBFT_O_FILES)
	ranlib $(STATIC)/$(LIBFT).a

$(OBJ)/$(LIBFT)/%.o: $(SRCS)/$(LIBFT)/%.c $(LIBFT_HEADER)
	@mkdir -p $(OBJ)
	@mkdir -p $(OBJ)/$(LIBFT)
	$(CC) $(CF) -c $< -o $@ -I $(INCLUDES)

$(OBJ)/$(LIBFI)/%.o: $(SRCS)/$(LIBFI)/%.c $(LIBFI_HEADER) $(LIBFT_HEADER)
	@mkdir -p $(OBJ)
	@mkdir -p $(OBJ)/$(LIBFI)
	$(CC) $(CF) -c $< -o $@ -I $(INCLUDES)

clean:
	rm -rf $(OBJ)
	rm -rf $(STATIC)
	
fclean: clean
	rm -f $(EXEC_NAME)

re: clean all