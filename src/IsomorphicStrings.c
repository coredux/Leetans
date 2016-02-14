//
// Created by seanr on 2016/2/14.
//

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


// submit the codes below

bool isIsomorphic(char* s, char* t) {

    int mapSize = 128;
    char* map = calloc( (size_t) mapSize , sizeof(char) );
    char* mapBy = calloc( (size_t) mapSize , sizeof(char) );

    for( int i = 0 ; i < mapSize ; i++ ) {
        *( map + i ) = -1;
        *( mapBy + i ) = -1;
    }

    int len = strlen(s);
    for( int i = 0 ; i < len ; i++ ) {
        char nowS = *( s + i );
        char nowT = *( t + i );
        if( map[ nowS ] < 0 && mapBy[ nowT ] < 0 ) {
            map[ nowS ] = nowT;
            mapBy[ nowT ] = nowS;
        } else if(  map[ nowS ] != nowT || mapBy[ nowT ] != nowS ) {
            return false;
        }
    }
    free( map );
    free( mapBy );
    return true;

}

// submit the codes above

int main() {
    printf("%d\n" , isIsomorphic( "13" , "42") );
    return 0;
}

