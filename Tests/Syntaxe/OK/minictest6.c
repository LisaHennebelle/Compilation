void main() {
	int var1 = 15, i, nb = 0;
	int bin1 = 530, bin5 = 15, bin3;
	bool var5 = (true && false), booleen;
	if (var5 == true) {
		var1 = 1;
	}
	else {
		var1 = 5;
	}
	while(nb<=5){nb=nb+1;}
	bin1 = bin1 >> 5;
	bin3 = bin1 | bin5;
	bin5 = bin1 ^ bin3;
	booleen = !var5;
	for (i = 1; i < 5; i = i + 1)
	{var1 = var1+1;}
	print(var1);
}
