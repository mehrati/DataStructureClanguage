#define _XOPEN_SOURCE 500 /* Enable certain library functions (strdup) on linux.  See feature_test_macros(7) */
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <string.h>

struct data_item_s {
	char *key;
	char *value;
	struct data_item_s *next;
};

typedef struct data_item_s data_item_t;

struct hash_table_s {
	int size;
	struct data_item_s **table;	
};

typedef struct hash_table_s hash_table_t;

hash_table_t *create_hash_table( int size );
int hash_code( hash_table_t *hashtable, char *key );
data_item_t *creat_new_pair( char *key, char *value );
void insert( hash_table_t *hashtable, char *key, char *value );	
char *search( hash_table_t *hashtable, char *key );	

int main( int argc, char **argv ) {

	hash_table_t *hashtable = create_hash_table( 65536 );

	insert( hashtable, "key1", "inky" );
	insert( hashtable, "key2", "pinky" );
	insert( hashtable, "key3", "blinky" );
	insert( hashtable, "key4", "floyd" );

	printf( "%s\n", search( hashtable, "key1" ) );
	printf( "%s\n", search( hashtable, "key2" ) );
	printf( "%s\n", search( hashtable, "key3" ) );
	printf( "%s\n", search( hashtable, "key4" ) );

	return 0;
}
//********************************************************************************************

hash_table_t *create_hash_table( int size ) {

	hash_table_t *hashtable = NULL;
	
	int i;

	hashtable = malloc( sizeof( hash_table_t ) ) );
	
	hashtable->table = malloc( sizeof( data_item_t * ) * size ) );
	
	for( i = 0; i < size; i++ ) {
		hashtable->table[i] = NULL;
	}

	hashtable->size = size;

	return hashtable;	
}
//********************************************************************************************
/* Hash a string for a particular hash table. */
int hash_code( hash_table_t *hashtable, char *key ) {

	unsigned long int hash_val;
	int i = 0;

	/* Convert our string to an integer */
	while( hash_val < ULONG_MAX && i < strlen( key ) ) {
		hash_val = hash_val << 8;
		hash_val += key[ i ];
		i++;
	}

	return hash_val % hashtable->size;
}
//********************************************************************************************

data_item_t *creat_new_pair( char *key, char *value ) {
	data_item_t *newpair;

	if( ( newpair = malloc( sizeof( data_item_t ) ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->key = strdup( key ) ) == NULL ) {
		return NULL;
	}

	if( ( newpair->value = strdup( value ) ) == NULL ) {
		return NULL;
	}

	newpair->next = NULL;

	return newpair;
}
//********************************************************************************************
/* Insert a key-value pair into a hash table. */
void insert( hash_table_t *hashtable, char *key, char *value ) {
	int bin = 0;
	data_item_t *newpair = NULL;
	data_item_t *next = NULL;
	data_item_t *last = NULL;

	bin = hash_code( hashtable, key );

	next = hashtable->table[ bin ];

	while( next != NULL && next->key != NULL && strcmp( key, next->key ) > 0 ) {
		last = next;
		next = next->next;
	}

	/* There's already a pair.  Let's replace that string. */
	if( next != NULL && next->key != NULL && strcmp( key, next->key ) == 0 ) {

		free( next->value );
		next->value = strdup( value );

	/* Nope, could't find it.  Time to grow a pair. */
	} else {
		newpair = creat_new_pair( key, value );

		/* We're at the start of the linked list in this bin. */
		if( next == hashtable->table[ bin ] ) {
			newpair->next = next;
			hashtable->table[ bin ] = newpair;
	
		/* We're at the end of the linked list in this bin. */
		} else if ( next == NULL ) {
			last->next = newpair;
	
		/* We're in the middle of the list. */
		} else  {
			newpair->next = next;
			last->next = newpair;
		}
	}
}
//********************************************************************************************
/* Retrieve a key-value pair from a hash table. */
char *search( hash_table_t *hashtable, char *key ) {
	int bin = 0;
	data_item_t *pair;

	bin = hash_code( hashtable, key );

	/* Step through the bin, looking for our value. */
	pair = hashtable->table[ bin ];
	while( pair != NULL && pair->key != NULL && strcmp( key, pair->key ) > 0 ) {
		pair = pair->next;
	}

	/* Did we actually find anything? */
	if( pair == NULL || pair->key == NULL || strcmp( key, pair->key ) != 0 ) {
		return NULL;

	} else {
		return pair->value;
	}
	
}
//********************************************************************************************