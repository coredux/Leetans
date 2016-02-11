//
// Created by seanr on 2016/2/11.
//


// submit the codes below

void merge(int* nums1, int m, int* nums2, int n) {

    int offset1 = m - 1;
    int offset2 = n - 1;

    for( int i = m + n - 1 ; i >= 0 ; i-- ) {
        if( offset1 >= 0 && offset2 >= 0 && *(nums1 + offset1 ) > *( nums2 + offset2 ) ) {
            *( nums1 + i ) = *( nums1 + offset1 );
            offset1 -= 1;
        } else if( offset1 >= 0 && offset2 >= 0 && *(nums1 + offset1 ) <= *( nums2 + offset2 ) ) {
            *( nums1 + i ) = *( nums2 + offset2 );
            offset2 -= 1;
        } else {
            if( offset1 < 0 ) {
                *( nums1 + i ) = *( nums2 + offset2 );
                offset2 -= 1;
            } else {
                *( nums1 + i ) = *( nums1 + offset1 );
                offset1 -= 1;
            }
        }
    }

}

// submit the codes above

int main() {
    return 0;
}

