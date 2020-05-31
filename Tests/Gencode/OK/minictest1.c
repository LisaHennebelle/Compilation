void main() {
	int carotte = 15, i, nb = 0;
	int bin1 = 230, bin2 = 12, bin3;
	bool var2 = (true && false), booleen;
	if (var2 == true) {
	  carotte = 1;
	}
	else {
	  carotte = 2;
	}
	while(nb<=5){nb=nb+1;}
	bin1 = bin1 >> 2;
	bin3 = bin1 | bin2;
	bin2 = bin1 ^ bin3;
	booleen = !var2;
	for (i = 1; i < 5; i = i + 1)
	{carotte = carotte+1;}
	print(carotte);
}
