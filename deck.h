#ifndef DECK_H
#define DECK_H
/**
 * enum kind_e - Kind of the card
 *
 * @SPADE: index 0
 * @HEART: index 1
 * @CLUB: index 2
 * @DIAMOND: index 3
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;
void sort_deck(deck_node_t **deck);
int _strcmp(const char *s1, const char *s2);
int compare_card(const char *a, const char *b);
void swap_prev(deck_node_t *node, deck_node_t **list);
int card_swap_check(deck_node_t *curr_card);
#endif
