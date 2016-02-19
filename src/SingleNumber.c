//
// Created by seanr on 2016/2/19.
//

// submit the codes below

int singleNumber(int* nums, int numsSize) {
    int ret = 0;
    for( int i = 0 ; i < numsSize ; i++ ) {
        ret ^= *( nums + i );
    }
    return ret;
}

// submit the codes above

int main() {
    return 0;
}
