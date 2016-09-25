NAME = protein_synthesizer

FILES = main transcription translation find_attached_amino_acid

SRC_FILES = $(addprefix srcs/,$(addsuffix .c,$(FILES)))

HDR = -I includes/

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(CFLAGS) $(HDR) $(SRC_FILES) -o $(NAME)

clean:
	rm -f *~

fclean: clean
	rm -f $(NAME)

re: fclean all
