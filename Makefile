NAME = protein_synthesizer

FILES = main transcription translation find_attached_amino_acid

SRC_FILES = $(addprefix srcs/,$(addsuffix .c,$(FILES)))

HDR = -I includes/

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

# You should declare your SRC_FILES as a dependency
# of NAME like:
#
#   $(NAME): $(SRC_FILES)
#   	gcc $(CFLAGS) $(HDR) $(SRC_FILES) -o $(NAME)
#
# this way when you `make` it will check to see
# if your files have changed before compiling.
#
$(NAME):
	gcc $(CFLAGS) $(HDR) $(SRC_FILES) -o $(NAME)

clean:
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
