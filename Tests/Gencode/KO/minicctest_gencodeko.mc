void main () {
    int i ;
    int masque = 1;
    int mot = 0x46 ;
    int res = 0;
    int temp = 0;
    for ( i = 0; i < 32; i = i + 1) {
        temp = mot & masque ;
        temp = temp >>> i ;
        res = res + temp ;
        masque = masque << 1;
        a = 1; // rajout d'une affectation sans declaration préléalable
    }
    print(res);
}
