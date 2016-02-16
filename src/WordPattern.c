//
// Created by seanr on 2016/2/16.
//

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// submit the codes below

bool wordPattern(char* pattern, char* str) {
    int listSize = 100;
    int sizeLoad =1;
    char **words = calloc( (size_t) ( listSize * sizeLoad ) , sizeof(char*) );

    int totalLen = strlen( str );
    int wordBeginIndex = 0;
    int wordEndIndex = 0;
    while( wordEndIndex < totalLen && *( str + wordEndIndex ) == ' ' ) {
        wordEndIndex++;
    }
    wordBeginIndex = wordEndIndex;
    int wordCnt = 0;
    // get words in str
    while( wordEndIndex < totalLen ) {
        while( wordEndIndex < totalLen && *( str + wordEndIndex ) != ' ' ) {
            wordEndIndex++;
        }
        int wordSize = wordEndIndex - wordBeginIndex;
        char *nowWord = calloc( (size_t)( wordSize + 1 ) , sizeof(char) );
        memcpy( nowWord , str + wordBeginIndex , ( size_t )wordSize );
        *( words + wordCnt ) = nowWord;
        wordCnt++;
        if( wordCnt == listSize * sizeLoad ) {
            char** tmp = calloc( ( size_t )( listSize * ( sizeLoad + 1 ) ) , sizeof(char*) );
            memcpy( tmp , words , sizeof( words ) );
            free( words );
            words = tmp;
            sizeLoad++;
        }
        while( wordEndIndex < totalLen && *( str + wordEndIndex ) == ' ' ) {
            wordEndIndex++;
        }
        wordBeginIndex = wordEndIndex;
    }

    int patternCnt = strlen( pattern );

    if( patternCnt != wordCnt ) {
        return false;
    }

    int letterNum = 26;
    char** wordPattern = calloc( (size_t)letterNum , sizeof(char*) );

    for( int i = 0 ; i < wordCnt ; i++ ) {
        int nowPatternPos = *( pattern + i ) - 'a';
        char* nowWord = *( words + i );
        if( *( wordPattern + nowPatternPos ) == NULL ) {
            *( wordPattern + nowPatternPos ) = nowWord;
        } else if( nowWord != NULL && strcmp( nowWord , *( wordPattern + nowPatternPos ) ) ) {
            return false;
        }
    }

    for( int i = 0 ; i < letterNum ; i++ ) {
        for( int j = i + 1 ; j < letterNum ; j++ ) {
            if( *( wordPattern + i ) != NULL && *( wordPattern + j ) != NULL && strcmp( *( wordPattern + i ) , *( wordPattern + j ) ) == 0 ) {
                return false;
            }
        }
    }
    free(words);
    free( wordPattern );
    return true;
}

// submit the codes above

int main() {
    return 0;
}

